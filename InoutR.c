/*	Task: InoutR																	*/
/*	Ein/Ausgabe über Erweiterungsmodule R37, R38	*/
/*	07.07.2003 erweitert mit R39									*/


#include "struct.h"
#include "ustruct.h"
#include "defins.h"
#include "sramext.h"
#include "uconstext.h"
#include "uramext.h"
#include "kommando.h"
#include <string.h>

char loadiov(char iocnt);
void check_zaehler(char num);
void load_verbr(char num, char znum, char monat);

/*---------------------- Task InoutR -----------------------------------*/
//	Aktualisierung für jedes Gerät:	im 1s Abstand
//	Anzahl der Geräte:							max. 4
//	Taskaufruf:											alle 50 ms
//	Auftragsstart 1.Modul:					50ms nach Task: Output
 
void InoutR(void)
{
	char  i, dev, num, rc, rc1, diginp, mask, znum, zaufnum;
	ULONG neuwert, altwert, ul_mess;
	UINT  diffwert, incwert, ae_zahl, faktor;

	incwert = 0;
	
	if(iocnt >= R3MAX)														// maximal 4 Module
		iocnt = 0;
	
	// Auftragsabfrage
	if(proc_IO ==	TRUE)																					// Auftrag ausgelöst
	{	if(vec[VEC_IO].request ==	0)															// Auftrag beendet ?
		{	proc_IO = FALSE;																				// ja, Auftrag löschen
			dev = Projekte[proj_typ].iobl[iocnt].iodev;							// Gerätekennzeichen
			num = (char)(Projekte[proj_typ].iobl[iocnt].ionum - 1);	// Gerätenummer
			rc	= vec[VEC_IO].rcode;																// Returncode	des	Handlers
			rc1 = vec[VEC_IO].buffer[2];														// Returncode des Teilnehmers

			switch(dev)
			{	
				case R37:
					if((rc == RC_OK) && (rc1 == RC_OK))
					{
						// Erstes Datenbyte: Diginp		
						diginp = vec[VEC_IO].buffer[3];
						mod37[num].Diginp = diginp;
						mask = 0x01;
						// Diginp aufteilen auf di_mewe[]
						for(i = 0; i < 6; i++)
						{	if(diginp & mask)
								mod37[num].di_mewe[i].bwert = 1;
							else
								mod37[num].di_mewe[i].bwert = 0;
							
							mod37[num].di_mewe[i].bstat = 0;				// Status ok setzen

							mask <<= 1;
						}		
								
						// 3 Datenbytes: swstat		(Status der Handschalter)				
						memcpy(&mod37[num].sw_stat[0], &vec[VEC_IO].buffer[4], 3);
						
						
						znum		= mod37[num].znum;									// aktuelle Zählernummer
						zaufnum	= mod37[num].zaufnum;								// aktuelle Auftragsnummer
						
						if(zaufnum > 0)															// es gab einen Auftrag
						{
							// 4 Bytes Hauptzählerstand
							//memcpy(&mod37[num].zaehler[znum].zwert, &vec[VEC_IO].buffer[7], 4);
							
							memcpy(&neuwert, &vec[VEC_IO].buffer[7], 4);		// Hauptzähler merken
							
							altwert = mod37[num].zaehler[znum].oldwert;
							if(altwert == 0 || neuwert < altwert)						// nach Reset  oder Überlauf ?
								mod37[num].zaehler[znum].oldwert = neuwert;		// ablegen
							else
							{
								diffwert = neuwert - altwert;
								faktor   = mod37[num].zaehler[znum].zdim.faktor;
								if(faktor > 1)
								{	// Zwischen-Zählerstand	erhöhen
									ae_zahl  = mod37[num].zaehler[znum].ae_zahl + diffwert;
									incwert  = ae_zahl / faktor;									// Anzahl der Hauptzähler Incremente
									ae_zahl  = ae_zahl % faktor;									// Vorteiler Rest
									mod37[num].zaehler[znum].ae_zahl = ae_zahl;		// zurückspeichern
								}
								else
									incwert = diffwert;														// kein Zwischenzähler
							
								if(incwert > 0)
								{
									// ul_mess = 10 ^exponent
									ul_mess = 1;
									for(i = mod37[num].zaehler[znum].zdim.exponent; i > 0; i--) {
										ul_mess = ul_mess * 10;	// Berechnung für den normierten Speicher zur Basis 1 !!!
									}
									
									//Zähler erhöhen
									mod37[num].zaehler[znum].zwert += ul_mess * incwert;		// Hauptzähler
									mod37[num].zaehler[znum].vwert += ul_mess * incwert;		// monatl. Verbrauchszähler		
								
									mod37[num].zaehler[znum].ucZstatus |= (char)(LO_HI_FLANKE | HI_LO_FLANKE);
								}		
								mod37[num].zaehler[znum].oldwert = neuwert;

							}
							
//							// 2 Bytes Aktueller Verbrauch (Monat)
//							memcpy(&mod37[num].zaehler[znum].vwert, &vec[VEC_IO].buffer[11], 2);
//							
//							// n Bytes entsprechend Auftragsnummer
//							switch(zaufnum)
//							{
//								case 1:																	// Zählername
//									memcpy(&mod37[num].zaehler[znum].zdim.zname, &vec[VEC_IO].buffer[13], 16);
//									break;
//	
//								case 2:																	// Kommastelle
//									memcpy(&mod37[num].zaehler[znum].zdim.komma, &vec[VEC_IO].buffer[13], 1);
//									break;
//									
//								case 3:																	// Dimensionsnummer
//									memcpy(&mod37[num].zaehler[znum].zdim.dim_idx, &vec[VEC_IO].buffer[13], 1);
//									break;
//									
//								case 4:																	// Teilerfaktor
//									memcpy(&mod37[num].zaehler[znum].zdim.faktor, &vec[VEC_IO].buffer[13], 2);
//									break;
//									
//								case 5:																	// Verbrauch Jan
//								case 6:																	// Verbrauch Feb
//								case 7:																	// Verbrauch März
//								case 8:																	// Verbrauch April
//								case 9:																	// Verbrauch Mai
//								case 10:																// Verbrauch Juni
//								case 11:																// Verbrauch Juli
//								case 12:																// Verbrauch Aug
//								case 13:																// Verbrauch Sept
//								case 14:																// Verbrauch Okt
//								case 15:																// Verbrauch Nov
//								case 16:																// Verbrauch Dez
//								case 17:																// Verbrauch Vorjahr Jan
//								case 18:																// Verbrauch Vorjahr Feb
//								case 19:																// Verbrauch Vorjahr März
//								case 20:																// Verbrauch Vorjahr April
//								case 21:																// Verbrauch Vorjahr Mai
//								case 22:																// Verbrauch Vorjahr Juni
//								case 23:																// Verbrauch Vorjahr Juli
//								case 24:																// Verbrauch Vorjahr Aug
//								case 25:																// Verbrauch Vorjahr Sept
//								case 26:																// Verbrauch Vorjahr Okt
//								case 27:																// Verbrauch Vorjahr Nov
//								case 28:																// Verbrauch Vorjahr Dez
//									load_verbr(num, znum, (char)(zaufnum - 5));
//									break;
//									
//							} // End switch(zaufnum)
						}		// End if(zaufnum > 0)	// es gab einen Auftrag	

						// Datuefehler löschen
						mod37[num].errcnt = 0;
						mod37[num].error  = 0;
					}
					else
					{	if(mod37[num].errcnt > 10)
						{	mod37[num].error = 1;			// Datenübertagungsfehler anzeigen
							if(de_simul == 0)					// wenn keine DE-Simulation
							{	mod37[num].Diginp = 0;
								for(i = 0; i < 6; i++)
								{	mod37[num].di_mewe[i].bwert = 0;
									mod37[num].di_mewe[i].bstat = DATERR;
								}
							}	
						}	
						else
							mod37[num].errcnt++;	
					}		
					break;
					
				//-------------------------------------------------------------------------
				case R38:
					if((rc == RC_OK) && (rc1 == RC_OK))
					{	// 14 * 3 Datenbytes: pt_mewe
						memcpy(&mod38[num].pt_mewe[0], &vec[VEC_IO].buffer[3], 42);
						mod38[num].errcnt = 0;
						mod38[num].error  = 0;
					}
					else	// Fehler
					{	if(mod38[num].errcnt > 10)
						{	mod38[num].error  = 1;

							for(i = 0; i < 14; i++)
								mod38[num].pt_mewe[i].stat = DATERR;
						}
						else
							mod38[num].errcnt++;			 
					}
					break;

				//-------------------------------------------------------------------------
				case R39:
					if((rc == RC_OK) && (rc1 == RC_OK))						// Datenübertragung ok
					{
						// 3. Datenbyte: Status der Kontaktspannung UK24
						mod39[num].Derror = vec[VEC_IO].buffer[5];
						if(mod39[num].Derror == 0)									// Kein Fehler der Kontaktspannung
						{
							// Die ersten 2 Datenbytes -> Diginp2 		
							// dig1 = vec[VEC_IO].buffer[3];							// DE1...DE8
							// dig2 = vec[VEC_IO].buffer[4];							// DE9...DE12
							mod39[num].Diginp2 = *(unsigned int *)&vec[VEC_IO].buffer[3];	// für parli

							// Diginp2 aufteilen auf di_mewe[]
							for(i = 0, faktor = 1; i < 12; i++, faktor <<= 1)	// faktor wird als Maske benutzt
							{
								if(mod39[num].Diginp2 & faktor)
									mod39[num].di_mewe[i].bwert = 1;
								else
									mod39[num].di_mewe[i].bwert = 0;

								mod39[num].di_mewe[i].bstat = 0;				// Status ok
							}

							// Datuefehler löschen
							mod39[num].errcnt = 0;
							mod39[num].error  = 0;
						}
						else																				// Fehler der Kontaktspannung
						{
							for(i = 0; i < 12; i++)
							{	mod39[num].di_mewe[i].bwert = 0;
								mod39[num].di_mewe[i].bstat = DATERR;
							}
							mod39[num].Diginp2 = 0;			
						}
					}	
					else	// Fehler bei der Datenübertragung
					{	if(mod39[num].errcnt > 10)
						{	mod39[num].error 	 = 1;									// Datenübertagungsfehler anzeigen
							if(de_simul == 0)												// wenn keine DE-Simulation
							{	mod39[num].Diginp2 = 0;								// Anzeige löschen
								for(i = 0; i < 12; i++)
								{	mod39[num].di_mewe[i].bwert = 0;
									mod39[num].di_mewe[i].bstat = DATERR;
								}
							}	
						}	
						else
							mod39[num].errcnt++;	
					}		
					break;			

				case R33:
					if((rc == RC_OK) && (rc1 == RC_OK))
					{
						// 6 Datenbytes: swstat		(Status der Handschalter)				
						memcpy(&mod33[num].sw_stat[0], &vec[VEC_IO].buffer[3], 6);
							// Datuefehler löschen
						mod33[num].errcnt = 0;
						mod33[num].error  = 0;
					}	
					else
					{	if(mod33[num].errcnt > 10)
							mod33[num].error = 1;			// Datenübertagungsfehler anzeigen
						else
							mod33[num].errcnt++;	
					}
						
			}					
			iocnt++;
		}
		else
		{	// prüfen ob master noch aktiv
			if(vec[VEC_IO].master == MASTER_S1 && Mode_S1 == SLAVE)
				proc_IO = FALSE;
			if(vec[VEC_IO].master == MASTER_S2 && Mode_S2 == SLAVE)
				proc_IO = FALSE;
			if(vec[VEC_IO].master == MASTER_S3 && (Mode_S3 == SLAVE || spl_kennung != SPL_RS485) )
				proc_IO = FALSE;
		}		
		
	}
	//------------------------------------------------------------------------
	else	// Auftragsauslösung
	{	switch(iocnt)
		{	case 0:														// 1.Modul
				if(oready == TRUE)							// wenn Output-Task abgelaufen
				{	oready = FALSE;
					if(loadiov(iocnt) == FALSE)
						iocnt++;
				}
				break;
			
			case 1:														// 2.- 4. Modul
			case 2:
			case 3:
				if(loadiov(iocnt) == FALSE)
					iocnt++;
				break;
		}
	}				
			
}						

/*---------------------- Task InoutR   Ende  -----------------------------------*/


//	Auftragsvektor laden
char loadiov(char iocnt)
{
		char request = 0;
		char master  = 0;
		char flag = 0;
		char bus = 0;
		char adr = 0;
		char dev = 0;
		char num = 0;
		
		dev = Projekte[proj_typ].iobl[iocnt].iodev;							// Gerätekennzeichen
		num = (char)(Projekte[proj_typ].iobl[iocnt].ionum - 1);	// Gerätenummer
		
		switch(dev)
		{	
			case 0:
				return(FALSE);
				
			case R37:
				bus = mod37[num].bus;
				adr = mod37[num].adr;
				vec[VEC_IO].buffer[1] =	9;										// Leng: Kommando + Daten
				vec[VEC_IO].buffer[2] = R35_KOM;							// Kommando (Primärkommando)
				vec[VEC_IO].buffer[3] = R37_IODAT;						// Daten 		(SubKommando)
				vec[VEC_IO].buffer[4] = mod37[num].anout[0];	// Daten 		(Erstellt in Output.c)
				vec[VEC_IO].buffer[5] = mod37[num].anout[1];	//	"
				vec[VEC_IO].buffer[6] = mod37[num].anout[2];	//	"
				vec[VEC_IO].buffer[7] = mod37[num].anout[3];	//	"
				vec[VEC_IO].buffer[8] = mod37[num].Digout;		//	"
				check_zaehler(num);
				vec[VEC_IO].buffer[9] = mod37[num].znum;			//	"				Zählernummer
				vec[VEC_IO].buffer[10]= mod37[num].zaufnum;		//	"				Auftragsnummer
				break;

			case R38:
				bus = mod38[num].bus;
				adr = mod38[num].adr;
				vec[VEC_IO].buffer[1] =	4;										// Leng: Kommando + Daten
				vec[VEC_IO].buffer[2] = R35_KOM;							// Kommando (Primärkommando)
				vec[VEC_IO].buffer[3] = R38_IODAT;						// Daten 		(SubKommando)
				*((unsigned int *)(&vec[VEC_IO].buffer[4])) = mod38[num].inpUsed;		// Maske aller verwendeten Pt1000-Eingänge
				break;
			
			case R39:
				bus = mod39[num].bus;
				adr = mod39[num].adr;
				vec[VEC_IO].buffer[1] =	4;										// Leng: Kommando + Daten
				vec[VEC_IO].buffer[2] = R35_KOM;							// Kommando (Primärkommando)
				vec[VEC_IO].buffer[3] = R39_IODAT;						// Daten 		(SubKommando)
				*((unsigned int *)(&vec[VEC_IO].buffer[4])) = mod39[num].Digart;		// Maske für Digitalart 
				break;

			case R33:
				bus = mod33[num].bus;
				adr = mod33[num].adr;
				vec[VEC_IO].buffer[1] =	3;										// Leng: Kommando + Daten
				vec[VEC_IO].buffer[2] = R35_KOM;							// Kommando (Primärkommando)
				vec[VEC_IO].buffer[3] = R33_IODAT;						// Daten 		(SubKommando)
				vec[VEC_IO].buffer[4] = mod33[num].Digout;		//	"				(Erstellt in Output.c)
				break;
				
			default:
				return(FALSE);
			
		}		
				 
		
		if(bus 	 == FB_XBUS)									// BUS-Kennung XBUS
		{	flag 		= TRUE;
			request = 0x21;											// Kennung:IFU-Gerät + 1 Versuche
			master	= MASTER_IFU;												// 3=HandlerIFU
		}	
		else																	// BUS-Kennung GBUS
		{	//	gibt es	einen	GBUS-Master ?
			if(Mode_S1	== MASTER	|| Mode_S2 ==	MASTER || (Mode_S3 ==	MASTER && spl_kennung == SPL_RS485) )
			{	flag = TRUE;
				request = 0x02;										// 2 Versuche
				if(Mode_S1 == MASTER)
					master = MASTER_S1;
				else if(Mode_S2 == MASTER)
					master = MASTER_S2;
				else
					master = MASTER_S3;	
			}			
		}

		
		if(flag == TRUE)
		{	vec[VEC_IO].buffer[0] = adr; 				// Device-Adresse des XBUS-Teilnehmers oder
																					// Modul-Adresse  des GBUS-Teilnehmers
			vec[VEC_IO].request = request;
			vec[VEC_IO].master 	= master;
			proc_IO				 			= 1;						// Auftrag merken
		}
		else // Fehler
		{
			switch(dev)
			{
				case R37:
					mod37[num].error = 1;
					break;
				case R38:
					mod38[num].error = 1;
					break;
				case R39:
					mod39[num].error = 1;
					break;
				case R33:
					mod33[num].error = 1;
					break;
			}		
			return(FALSE);
		}	
			
	return(TRUE);
}


// Zaehlerparameter einstellen
void check_zaehler(char num)
{
	char zbeleg, znum, zaufnum, mask;
	zbeleg = znum = zaufnum = 0;
	
	// Zaehlerbelegung entsprechend Gerätenummer(num) ermitteln
	switch(num)
	{
		case 0:
			#ifdef ZEX1BELEG
			zbeleg	= ZEX1BELEG;
			znum 		= mod37[num].znum;
			zaufnum	=	mod37[num].zaufnum;
			#endif
			break;
			
		case 1:
			#ifdef ZEX2BELEG
			zbeleg =  ZEX2BELEG;
			znum 		= mod37[num].znum;
			zaufnum	=	mod37[num].zaufnum;
			#endif
			break;
			
		case 2:
			#ifdef ZEX3BELEG
			zbeleg =  ZEX3BELEG;
			znum 		= mod37[num].znum;
			zaufnum	=	mod37[num].zaufnum;
			#endif
			break;
			
		case 3:
			#ifdef ZEX4BELEG
			zbeleg =  ZEX4BELEG;
			znum 		= mod37[num].znum;
			zaufnum	=	mod37[num].zaufnum;
			#endif
			break;
	}
	
	if(zbeleg == 0)												// kein Zähleingang projektiert
	{	znum 		= 0;
		zaufnum = 0;
	}
	else																	// es ist mindestens 1 Zähleingang projektiert
	{
		if(zaufnum == 0)										// noch nie gelaufen
		{	zaufnum = 1;											// Erster Auftrag
			znum		= 255;										// Erster Zähler - 1
		}
		
		do
		{	znum++;														// nächster möglicher Zählereingang
			if(znum > 5)											// nach maximal 6 Zähleingängen pro Modul,
			{	znum = 0;
				zaufnum++;											// Auftragsnummer erhöhen
				if(zaufnum > ZAUFMAX)
					zaufnum = 1;
			}
			mask = (char)(1 << znum);
		}
		while((zbeleg & mask) == 0);
	}
		
	mod37[num].znum    = znum;
	mod37[num].zaufnum = zaufnum;								
}			


// Kopieren der Verbräuche aus dem Empfangspuffer in die Zählerstruktur 
void load_verbr(char num, char znum, char monat)
{
	if(znum < 12)			// aktuelle Werte
		memcpy(&mod37[num].zaehler[znum].verbr_akt[monat], &vec[VEC_IO].buffer[13], 2);	// R37 liefert nur 2-Byte Werte
	else
	{
		znum -= 12;			// Vorjahreswerte
		memcpy(&mod37[num].zaehler[znum].verbr_vor[monat], &vec[VEC_IO].buffer[13], 2);
	}	
}
						