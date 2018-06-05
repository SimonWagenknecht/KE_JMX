/*	Task:					SteuerWw			*/
/*	Warmwassersteuerung						*/

#include "struct.h"
#include "ustruct.h"
#include "defins.h"
#include "sramext.h"
#include "uramext.h"
#include "standdef.h"

void puwlcnt(char ww);													
void puwllaufz(char ww);
//void puwl_ein(char ww);
void Check_Vorrang( char ww, int wwIst, char wwIstStat); // ***AnFre
void puwBm(char ww);
void puwz_einaus(char ww);
void wwlad_ein(char ww);		// ***AnFre
void wwladlaufz(char ww);		// ***AnFre
void puwtlaufz(char ww);		// ***AnFre 30.05.2013
void puwzlaufz(char ww);		// ***AnFre 30.05.2013
void Pumpenbus_WW ( char ww );


/*-------------------------------- Task SteuerWw -----------------------------------*/
// Takt: 30 sek

void SteuerWw(void)
{
	char flag;
	int twwlbeg, twwlend;
	int temp1, temp2, toben, tmin, tmax;
	char stat1, stat2;
	signed char i;
	
// ***AnFre Zuweisung der Temperaturen auf bereits verwendete Namen 
	TWWC[WW1] = TW1_[0];		// Regeltemp.
	TWWV[WW1] = TW2_[0];		// Vorrangtemp.
	TWW1L[WW1] = TW3_[0];		// Speicher Mitte (oben)
	TWW2L[WW1] = TW4_[0];		// Speicher	unten

	// oberen Speicherfühler bestimmen (bei Ein-Fühlerbetrieb bzw. ein Fühler defekt)
	stat1 = TWW1L[WW1]->stat;					// Status   Speichertemp. 1 Oben
	stat2 = TWW2L[WW1]->stat;					// Status   Speichertemp. 2 Unten
	temp1 = TWW1L[WW1]->messw;				// Messwert Speichertemp. 1 Oben
	temp2 = TWW2L[WW1]->messw;				// Messwert Speichertemp. 2 Unten
		
	toben = 1000;	// 100,0°C vorbelegen
	if(stat1 == 0)
		toben = temp1;
	else
	{	if(stat2 == 0)
			toben = temp2;
	}				
	
	puwtlaufz(WW1);		// ***AnFre 30.05.2013
	puwzlaufz(WW1);		// ***AnFre 30.05.2013
		
	//----------------------- Ladepumpen ---------------------------------
	// ---- Abfrage Handbetrieb -------------------------
	// auch WILO ModBus
	BusPuPara[PU_BUS_TPU_WW1-1].Hand 	= wws[WW1].Haut;

	if(wws[WW1].Haut == TRUE)
	{
		MVWLEA[WW1]->wert = wws[WW1].Lpea;
		wwd[WW1].tauschPu = wws[WW1].Tpea;

		if ( BusPuPara[PU_BUS_TPU_WW1-1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
		{
			PUWTEA[WW1]->wert = wws[WW1].Tpea;
		}
		else
		{
			PUWTEA[WW1]->wert = 1;
			BusPuPara[PU_BUS_TPU_WW1-1].BetriebHand = wws[WW1].Tpea;
			// RegelartHand wird direkt in parli eingetragen
			// SollHand Tauscherpumpe  wird direkt in parli eingetragen
		}
		
		wwd[WW1].puwlBm 	= 0;												// kein Soft-Alarm
	}		
	else
	{
		// --------------- Automatik ------------------------------------
		// Betriebsmeldung Ladepumpe und Zirkpumpe überwachen
		puwBm(WW1);
		
		// Konventionelle LadeBetrieblaufzeiten
		wwladlaufz(WW1);
		
		// Ladepumpe ein/aus	
		if ( wwd[WW1].solWwLad > 0 )// im Solar-Ladebetrieb ?
		{
			MVWLEA[WW1]->wert = 1;									// LadeVentil einschalten
		}
		else
		{
			if ( (wwd[WW1].wwlad > 0) && (TVKE[KE1]->stat != 0 || TVKE[KE1]->messw > prd[PR1].aktTwwlad - 50) )			
			{
				MVWLEA[WW1]->wert = 1;									// LadeVentil einschalten
			}
			else	//-------------------------------------- nicht im Ladebetrieb
			{	
				if ( wwd[WW1].konvLegio == 0 )		// ***AnFre 19.08.2009
				{
					//#####josch	
					wwd[WW1].zpuwlna ? ( wwd[WW1].zpuwlna-- ) : ( MVWLEA[WW1]->wert = 0 );	// Ladepumpe nach Nachlauf abschalten
				}
			}
		}
		
		// Tauscherpumpe schalten
		if ( wwd[WW1].twwBed == 1 )	//Ventil längere Zeit AUF
		{
			PUWTEA[WW1]->wert = 1;
			wwd[WW1].tauschPu = 1;
			wwd[WW1].zpuwtna	= wws[WW1].Puwtna *2;	// Zähler f. Tauscherpu Nachlaufzeit setzen (x min * 2 * 30s-Task)
		}
		else
		{
//-			wwd[WW1].zpuwtna ? ( wwd[WW1].zpuwtna-- ) : ( PUWTEA[WW1]->wert = 0 );	// Tauscherpumpe nach Nachlauf abschalten
			if ( wwd[WW1].zpuwtna > 0 )
			{
				wwd[WW1].zpuwtna--;
			}
			if ( wwd[WW1].zpuwtna == 0 )
			{
				if ( BusPuPara[PU_BUS_TPU_WW1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
					PUWTEA[WW1]->wert = 0;	// Tauscherpumpe nach Nachlauf abschalten
				wwd[WW1].tauschPu = 0;				
			}			
		}
	}

	#if ( BUS_PU_MAX > 0 )
	Pumpenbus_WW ( WW1 );
	#endif


	// Ladebetrieb ermitteln mit 2 Speicherfühlern:
	// Der Ladebetrieb beginnt, wenn beide Speichertemp. die LadeBeginntemp. unterschreiten.
	// Der Ladebetrieb endet,   wenn beide Speichertemp. die LadeEndetemper. überschreiten.
	// Der Ausfall eines Fühlers wird durch den zweiten Fühler kompensiert.
	// Beim Ausfall beider Fühler gibt es keinen Ladebetrieb.
	
	tmax  = 1000;											// Vorbelegung 100,0 °C
	tmin  = 1000;											// Vorbelegung 100,0 °C
	
	// Ermitteln der LadeBeginntemp u. LadeEndetemp
	twwlbeg = prd[PR1].aktTwwlbeg;									// akt. LadeBeginntemp
	twwlend = prd[PR1].aktTwwlend;									// akt. LadeEndetemp
	if(wwd[WW1].konvLegio == TRUE)			// wenn Legionellenschaltung
	{	twwlend = wws[WW1].Twwleg;								// Endtemp. = Legiotemp.
		twwlbeg = twwlend - 20;										// Beginntemp - 2,0 °C
	}	
	
	// Ermitteln der momentanen max. und min. Temperatur über 2 Speicherfühler
	if((stat1 | stat2) == 0)										// beide Fühler ok
	{	if(temp1 >= temp2)
		{	tmax = temp1;														// tmax: Überwachung Ladebeginn
			tmin = temp2;														// tmin: Überwachung Ladeende
		}
		else
		{	tmax = temp2;
			tmin = temp1;
		}
	}
	else																				// mindestens 1 Fühler defekt
	{	if(stat1 == 0)
			tmax = tmin = temp1;
		else		 
		{ if(stat2 == 0)
				tmax = tmin = temp2;
		}
	}

// ------------ WW-Temperatur-Sollwerte nach vorgegebenen Tages-Profil oder Absenk-Tagen---------------

	//in den Programmen benutzte aktuelle Soll-Werte vorbelegen
		prd[PR1].aktTwwsol		= wws[WW1].Twwsol;
		prd[PR1].aktTwwlad		= wws[WW1].Twwsol + wws[WW1].DTTwwlad;	//	25.04.2013
		prd[PR1].aktTwwVor		= wws[WW1].Twwsol + wws[WW1].DTTwwVor;	//	25.04.2013
		prd[PR1].aktTwwUnter	= wws[WW1].Twwsol + wws[WW1].DTTwwUnter;//	25.04.2013
		prd[PR1].aktTwwlbeg		= wws[WW1].Twwsol + wws[WW1].DTTwwlbeg;
		prd[PR1].aktTwwlbegS	= wws[WW1].Twwsol + wws[WW1].DTTwwlbegS;
		prd[PR1].aktTwwlend		= wws[WW1].Twwsol + wws[WW1].DTTwwlend;

		for(i = 3; i >= 0; i--)
		{
			if ( (prs[PR1].profil[i].Zeit != 0 || prs[PR1].profil[i].ZeitStd != 0)
						&& (prs[PR1].profil[i].Zeit == Min && prs[PR1].profil[i].ZeitStd == Std) )
				prd[PR1].zProfEin[i] = (prs[PR1].profil[i].Dauer * 120);
		} //Ende for i
	
		for(i = 3; i >= 0; i--)
		{
			if ( prd[PR1].zProfEin[i] > 0 )
			{
				prd[PR1].zProfEin[i] --;
				prd[PR1].profEin[i] = 1;
				prd[PR1].aktTwwsol 	= prs[PR1].profil[i].Twwsol;
				if ( prd[PR1].aktTwwsol < 100 )
					prd[PR1].aktTwwsol = 100;																			// Begrenzung auf 10,0°C
				if ( prd[PR1].aktTwwsol > 900 )
					prd[PR1].aktTwwsol = 900;																			// Begrenzung auf 90,0°C

				prd[PR1].deltaTwwsol = prd[PR1].aktTwwsol - wws[WW1].Twwsol;
				prd[PR1].aktTwwlad 	= prd[PR1].aktTwwsol + wws[WW1].DTTwwlad;		// + prd[PR1].deltaTwwsol;	25.04.2013
				if ( prd[PR1].aktTwwlad < 200 )
					prd[PR1].aktTwwlad = 200;																			// Begrenzung auf 20,0°C
				if ( prd[PR1].aktTwwlad > 900 )
					prd[PR1].aktTwwlad = 900;																			// Begrenzung auf 90,0°C
				prd[PR1].aktTwwVor	= prd[PR1].aktTwwsol + wws[WW1].DTTwwVor;		// + prd[PR1].deltaTwwsol;	25.04.2013
				prd[PR1].aktTwwUnter= prd[PR1].aktTwwsol + wws[WW1].DTTwwUnter;	// + prd[PR1].deltaTwwsol;
				prd[PR1].aktTwwlbeg	= prd[PR1].aktTwwsol + wws[WW1].DTTwwlbeg;	// + prd[PR1].deltaTwwsol;
				if ( prd[PR1].aktTwwlbeg < 100 )
					prd[PR1].aktTwwlbeg = 100;																		// Begrenzung auf 10,0°C
				prd[PR1].aktTwwlbegS= prd[PR1].aktTwwsol + wws[WW1].DTTwwlbegS;	// + prd[PR1].deltaTwwsol;
				prd[PR1].aktTwwlend	= prd[PR1].aktTwwsol + wws[WW1].DTTwwlend;	// + prd[PR1].deltaTwwsol;
				if ( prd[PR1].aktTwwlend < 200 )
					prd[PR1].aktTwwlend = 200;																		// Begrenzung auf 20,0°C

			}
			else
				prd[PR1].profEin[i] = 0;
		} //Ende for i

// 07.01.2010 Absenk-Tage für TWW (hat Vorrang vor 'Profilen')
		if(wws[WW1].AbsTag & wotbit())						// gültigen Wochentag abfragen
		{
			prd[PR1].aktTwwsol = wws[WW1].TwwAbs;
			prd[PR1].deltaTwwAbs	=	prd[PR1].aktTwwsol - wws[WW1].Twwsol;
			
			prd[PR1].aktTwwlad 	= prd[PR1].aktTwwsol + wws[WW1].DTTwwlad;		// + prd[PR1].deltaTwwAbs;
			if ( prd[PR1].aktTwwlad < 200 )
				prd[PR1].aktTwwlad = 200;																			// Begrenzung auf 20,0°C
			if ( prd[PR1].aktTwwlad > 800 )
				prd[PR1].aktTwwlad = 800;																			// Begrenzung auf 80,0°C
			prd[PR1].aktTwwVor	= prd[PR1].aktTwwsol + wws[WW1].DTTwwVor;		// + prd[PR1].deltaTwwAbs;	25.04.2013
			prd[PR1].aktTwwUnter= prd[PR1].aktTwwsol + wws[WW1].DTTwwUnter;	// + prd[PR1].deltaTwwAbs;
			prd[PR1].aktTwwlbeg	= prd[PR1].aktTwwsol + wws[WW1].DTTwwlbeg;	// + prd[PR1].deltaTwwAbs;
			if ( prd[PR1].aktTwwlbeg < 100 )
				prd[PR1].aktTwwlbeg = 100;																		// Begrenzung auf 10,0°C
			prd[PR1].aktTwwlbegS= prd[PR1].aktTwwsol + wws[WW1].DTTwwlbegS;	// + prd[PR1].deltaTwwAbs;
			prd[PR1].aktTwwlend	= prd[PR1].aktTwwsol + wws[WW1].DTTwwlend;	// + prd[PR1].deltaTwwAbs;
			if ( prd[PR1].aktTwwlend < 200 )
				prd[PR1].aktTwwlend = 200;																		// Begrenzung auf 20,0°C
			}
			else
			{
				prd[PR1].deltaTwwAbs	=	0;
			}		
			
// Klimaschutz ***AnFre 10.10.2007
		if(Klima > 0)
		{
			prd[PR1].aktTwwsol -= DTKlima;
		}					
			
// ------ Ladebetrieb ermitteln --------------------------
		if(tmin > twwlend)									// größer als LadeEndetemp. ? oder beide Fühler defekt
		{	wwd[WW1].wwlad = FALSE;						// Ladebetrieb löschen	
			if(wwd[WW1].konvLegio == 0)	
				wwd[WW1].wwLadS = FALSE;				// wenn keine Legionellenschaltung
		}	
		else
		{	if(tmax < twwlbeg)														// kleiner als LadeBeginntemp. ?	
			{	// Ladebetrieb setzen
//	***AnFre	if(wwd[WW1].wwlad	 == FALSE)								// Anfangsinit.
				wwlad_ein(WW1);									// Ladebetrieb setzen
				wwd[WW1].zpuwlna	= wws[WW1].Puwlna * 2;	// Zähler f. Ladepu Nachlaufzeit setzen (x min * 2 * 30s-Task)
// ***AnFre		wwd[WW1].zpuwtna	= wws[WW1].Puwtna << 1;	// Zähler f. Tauscherpu Nachlaufzeit setzen (x min * 2 * 30s-Task)
			}
			if (tmax < prd[PR1].aktTwwlbegS)			// Solarer Ladebeginn ***AnFre
			{	wwd[WW1].wwLadS = TRUE;
			}
		}

// ***AnFre	Vorrangbetrieb setzen
		// Vorrang-Betrieb Ein/Aus		
		Check_Vorrang( WW1, TWWV[WW1]->messw, TWWV[WW1]->stat ); // ***AnFre

	// --------------------- Zirkulationspumpe --------------------------
	#if ( ZPU_WW1 == 1 || PU_BUS_ZPU_WW1 > 0 )							// wenn vorhanden

	// ------------ Abfrage Handbetrieb --------------------------
	// auch WILO ModBus
	BusPuPara[PU_BUS_ZPU_WW1-1].Hand 	= wws[WW1].Haut;

	if(wws[WW1].Haut == TRUE)
	{	
		wwd[WW1].zirkPu = wws[WW1].Zpea;

		if ( BusPuPara[PU_BUS_ZPU_WW1-1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
		{
			PUWZEA[WW1]->wert = wws[WW1].Zpea;
		}
		else
		{
			PUWZEA[WW1]->wert = 1;
			BusPuPara[PU_BUS_ZPU_WW1-1].BetriebHand = wws[WW1].Zpea;
			// RegelartHand wird direkt in parli eingetragen
			// SollHand Tauscherpumpe  wird direkt in parli eingetragen
		}
		
		wwd[WW1].puwzBm = 0;													// kein Soft-Alarm
	}	
	else	// Automatik
	{
		if( WWAUS[WW1]->bstat == NICHTV || WWAUS[WW1]->bwert == 0) // Anlagenschalter 'Nichtnutzung WWB' ist nicht aktiv
		{

			if(wws[WW1].Puwzdau == 0)										// Abschaltdauer 0 h
			{	wwd[WW1].zpuwz = 0;												// Zähler für ZirkPu Abschaltdauer
				puwz_einaus(WW1);
			}
			else
			{	if(wwd[WW1].zpuwz == 0)										// wenn Zähler nicht gesetzt
				{	if(wws[WW1].Puwzab[1] == Std && 				// Abschaltzeit abfragen
						 wws[WW1].Puwzab[0] == Min    )
					{	
						wwd[WW1].zpuwz = wws[WW1].Puwzdau * 120;	// Zähler setzen (1h bei 30s-Task)
					}
					else	// zur Unzeit
					{	puwz_einaus(WW1);
					}
				}
				else	// Abschaltung läuft
				{	wwd[WW1].zpuwz--;
					if(wwd[WW1].legio == TRUE)							// wenn Legionellenschaltung	
					{	PUWZEA[WW1]->wert = 1;								// ZirkPu einschalten
						wwd[WW1].zirkPu = 1;
					}
					else
					{	
						if ( BusPuPara[PU_BUS_ZPU_WW1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
							PUWZEA[WW1]->wert = 0;								// ZirkPu ausschalten
						wwd[WW1].zirkPu = 0;
					}
				}	
			}
		}
		else			// Anlagenschalter 'Nichtnutzung WWB' ist aktiv
		{
			if ( BusPuPara[PU_BUS_ZPU_WW1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
				PUWZEA[WW1]->wert = 0;								// ZirkPu ausschalten
			wwd[WW1].zirkPu = 0;
		}	
	}
	#endif
	
	if(wws[WW1].Haut != TRUE)
		wws[WW1].Haut = 0;													// Korrektur, falls Fehleigabe
		
	// --------------- Legionellenschaltung --------------------------
	flag = 1;
	if(wws[WW1].Legjn == TRUE)
	{	if ( sod[SO1].zLegSperr == 0 )	// ***AnFre sperren nach Solar-Legio
		{	if(wws[WW1].Legtag & wotbit())							// gültigen Wochentag abfragen
			{	if(wwd[WW1].zleg == 0)										// Zähler läuft nicht
				{	if(wws[WW1].Legzeit[1] == Std && 				// Einschaltzeit abfragen
								wws[WW1].Legzeit[0] == Min    )
					{	
						wwd[WW1].zleg  = wws[WW1].Legdau * 2;		// Zähler setzen (1min bei 30s-Task)
						wwd[WW1].konvLegio = 1;									// konventionelle Temperaturerhöhung ein
// 19.08.2009
//						wwd[WW1].wwLadS = 1;										// Solarladung ein
						MVWLEA[WW1]->wert = 1;				// Ladeventil[17] AUF
						wwd[WW1].zpuwlna	= wws[WW1].Puwlna * 2;	// Zähler f. Ladepu Nachlaufzeit setzen (x min * 2 * 30s-Task)
					}
					else
					 flag = 0;
				}	 
				else																		// Zähler läuft
				{	if(--wwd[WW1].zleg == 0)							// wenn abgelaufen
						flag = 0;
				}		
			}
			else	
				flag = 0;
		}
		else	
			flag = 0;
	}
	else
		flag = 0;
	
	if(flag == 0)
	{	wwd[WW1].konvLegio = 0;
		wwd[WW1].zleg  = 0;
	}
		
}
/*-------------------------------- Ende Task SteuerWw -----------------------------------*/



//---------------- Unterprogramme -------------------------------------

// ***AnFre wwlad einschalten zählen
//-----------------------
void wwlad_ein(char ww)
{
		if(wwd[WW1].wwlad == 0)						// LadeBetrieb aus ?
		{	wwd[WW1].wwlad = 1;							// LadeBetrieb einsch.
			wwd[ww].puwlsta++;
			bicbus(EEPADR, (char*)&wwd[ww].puwlsta, PUWLSTA1_ADR+(ww*2), 2, BICWR);
		}	
}	

// ***AnFre wwlad-Laufzeit erhöhen
//-----------------------
void wwladlaufz(char ww)
{
	static char puwl_sec;
	
	if(wwd[ww].wwlad == 1)				// Abfrage Relais: LadeBetrieb ein ?
	{	if(++puwl_sec > 120)					// 30-Sekunden Zähler hochzählen
		{	puwl_sec = 0;
			wwd[ww].puwlh++;						// Laufzeit h erhöhen
			bicbus(EEPADR, (char*)&wwd[ww].puwlh, PUWLH1_ADR+(ww*2), 2, BICWR);
		}
	}
}	

// ***AnFre Tauscher-Pumpe-Laufzeit erhöhen		30.05.2013
//-----------------------
void puwtlaufz(char ww)
{
	static char puwt_sec;
	
	if(wwd[ww].puwtEinAnz == 1)				// Abfrage T-Pu ein ?
	{	if(++puwt_sec > 120)					// 30-Sekunden Zähler hochzählen
		{	puwt_sec = 0;
			wwd[ww].puwth++;						// Laufzeit h erhöhen
			bicbus(EEPADR, (char*)&wwd[ww].puwth, PUWTH1_ADR+(ww*2), 2, BICWR);
		}
	}
}	

// ***AnFre Zirk.Pumpe-Laufzeit erhöhen		30.05.2013
//-----------------------
void puwzlaufz(char ww)
{
	static char puwz_sec;
	
	if(wwd[ww].puwzEinAnz == 1)				// Abfrage Z-Pu  ein ?
	{	if(++puwz_sec > 120)					// 30-Sekunden Zähler hochzählen
		{	puwz_sec = 0;
			wwd[ww].puwzh++;						// Laufzeit h erhöhen
			bicbus(EEPADR, (char*)&wwd[ww].puwzh, PUWZH1_ADR+(ww*2), 2, BICWR);
		}
	}
}	

// PUWL Einschalten zählen
//------------------------
void puwlcnt(char ww)													
{
	wwd[ww].puwlsta++;
	bicbus(EEPADR, (char*)&wwd[ww].puwlsta, PUWLSTA1_ADR+(ww*2), 2, BICWR);
}

// PUWL Laufzeit erhöhen
//-----------------------
void puwllaufz(char ww)
{
	static char puwl_sec;
	
	if(MVWLEA[ww]->func != NICHTV)
	{	if(MVWLEA[ww]->wert > 0)				// Abfrage Relais: Ladepumpe ein ?
		{	if(++puwl_sec > 120)					// 30-Sekunden Zähler hochzählen
			{	puwl_sec = 0;
				wwd[ww].puwlh++;						// Laufzeit h erhöhen
				bicbus(EEPADR, (char*)&wwd[ww].puwlh, PUWLH1_ADR+(ww*2), 2, BICWR);
			}
		}
	}			
}	

// Vorrang untersuchen
//---------------------------------------------------------------------------------

void Check_Vorrang( char ww, int wwIst, char wwIstStat) // ***AnFre
{
	if ( wwIstStat == 0 )
	{ // Vorrang-Fühler ist o.k.
		if ( wwd[ww].wwvor == 0 )
		{
			if ( (wwIst < prd[PR1].aktTwwUnter) && (wwd[ww].zvorrad < wws[ww].Vorrad *2) )
			{ // Vorrang ein
				wwd[ww].wwvor = TRUE;
			}
			else
			{
				if ( wwIst > prd[PR1].aktTwwUnter + 20 )
				{ // Vorrang-Dauer max. löschen
					wwd[ww].zvorrad = 0;
				}
			}
		}
		else
		{
			if ( wwd[ww].zvorrad < wws[ww].Vorrad *2 )
			{
				wwd[ww].zvorrad++;
			}
			else
			{
				wwd[ww].wwvor = FALSE;
			}				
			if ( wwIst > prd[PR1].aktTwwUnter + 20 )
			{ // Vorrang aus
				wwd[ww].wwvor = FALSE;
				wwd[ww].zvorrad = 0;
			}
		}
	}
	else
	{ // Vorrang-Fühler defekt
		wwd[ww].wwvor = FALSE;
		wwd[ww].zvorrad = 0;
	}
}

					 
// Betriebsmeldung Ladepumpe und Zirkpumpe überwachen
//#####090119: BM Tauscherpumpe überwachen
void puwBm(char ww)
{
	#if LPUBM_WW1 == 1							// Betriebsmeldung Ladepumpe vorhanden
		if(MVWLEA[ww]->wert == 1)			// Ladepumpe EIN ?
		{
			if(BMPUWL[ww]->bwert == 1)	// Betriebsmeldung auch EIN ?
				wwd[WW1].puwlBm = 0;			// kein Alarm
			else
				wwd[WW1].puwlBm = 1;			// Soft-Alarm: 'kein Betriebsmeldungs-Signal'
		}
		else
			wwd[WW1].puwlBm = 0;				// kein Alarm
	#endif
	
	#if ZPUBM_WW1 == 1 							// Betriebsmeldung Zirkpu. vorhanden		
		if(PUWZEA[ww]->wert == 1)			// Zirk.pumpe EIN ?
		{
			if(BMPUWZ[ww]->bwert == 1)	// Betriebsmeldung auch EIN ?
				wwd[WW1].puwzBm = 0;			// kein Alarm
			else
				if ( BusPuPara[PU_BUS_ZPU_WW1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
					wwd[WW1].puwzBm = 1;			// Soft-Alarm: 'kein Betriebsmeldungs-Signal'
		}
		else
			wwd[WW1].puwzBm = 0;				// kein Alarm
	#endif
	
	#if TPUBM_WW1 == 1 							// Betriebsmeldung Tauscherpumpe vorhanden		
		if(PUWTEA[ww]->wert == 1)			// Tauscherpumpe EIN ?
		{
			if(BMPUWT[ww]->bwert == 1)	// Betriebsmeldung auch EIN ?
				wwd[WW1].puwtBm = 0;			// kein Alarm
			else
				if ( BusPuPara[PU_BUS_TPU_WW1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
					wwd[WW1].puwtBm = 1;			// Soft-Alarm: 'kein Betriebsmeldungs-Signal'
		}
		else
			wwd[WW1].puwtBm = 0;				// kein Alarm
	#endif
				
}

// Zirkulationspumpe Ein-/Ausschalten
void puwz_einaus(char ww)
{			
	//#####ulsch ( Siefke	) 28.05.03 : ZirkPu soll im Ladebetrieb abgeschaltet werden
	// bei Legionellenbetrieb muss sie aber laufen !!!

	//#####ulsch			
	//			if ( wwd[WW1].wwlad && wwd[WW1].legio == FALSE )
	//#####ulsch: 24.10.03 neuer Parameter steuert Ausschalten der ZirkPu bei Speicherladung
	if ( wwd[ww].wwlad && wwd[ww].legio == FALSE && wws[ww].ZpuAusLad )			
	{	
		if ( BusPuPara[PU_BUS_ZPU_WW1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
			PUWZEA[ww]->wert = 0;
		wwd[WW1].zirkPu = 0;
	}
	else			
	{	PUWZEA[ww]->wert = 1;									// ZirkPu einschalten
		wwd[WW1].zirkPu = 1;
	}
}



void Pumpenbus_WW ( char ww )
{
#if BUS_PU_MAX > 0
	char pu = 0;
	
	if ( ww == WW1 )
	{
		pu = PU_BUS_TPU_WW1;
		
		if ( pu > 0 && pu <= BUS_PU_MAX )
		{
			pu -= 1;
		
			if ( BusPuPara[pu].Funktion == 1 )
			{
				if ( wwd[ww].tauschPu == 1 )
				{
					BusPuPara[pu].Betrieb = 1;
					BusPuPara[pu].Sollwert = wws[WW1].BusTauPuSoll;		// Sollwert bei WILO Pumpenbus
				}
				else
				{
					BusPuPara[pu].Betrieb = 0;
					BusPuPara[pu].Sollwert = 0;
				}				
			}

			#if GENI > 0	
			wwd[ww].busTPuEin = pu_control[pu].pu_operation;	
			#endif
	
			#if WILO_MODBUS > 0	
			wwd[ww].busTPuEin = modWiloPu[pu].output_value1_temp;	
			#endif
		}

		pu = PU_BUS_LPU_WW1;		// ***AnFre nicht vorh., da Ladeventil
		
		if ( pu > 0 && pu <= BUS_PU_MAX )
		{
			pu -= 1;
		
			if ( BusPuPara[pu].Funktion == 1 )
			{
				if ( wwd[ww].zpuwlna )
				{
					BusPuPara[pu].Betrieb = 1;
//-				BusPuPara[pu].Sollwert = ??? ;		Sollwert variabel / geregelt ?
				}
				else
				{
					BusPuPara[pu].Betrieb = 0;
//-				BusPuPara[pu].Sollwert = 0;
				}				
			}

			#if GENI > 0	
			wwd[ww].busLPuEin = pu_control[pu].pu_operation;	
			#endif
	
			#if WILO_MODBUS > 0	
			wwd[ww].busLPuEin = modWiloPu[pu].output_value1_temp;	
			#endif
		}
		
		pu = PU_BUS_ZPU_WW1;
		
		if ( pu > 0 && pu <= BUS_PU_MAX )
		{
			pu -= 1;
		
			if ( BusPuPara[pu].Funktion == 1 )
			{
				if ( wwd[WW1].zirkPu == 1 )
				{
					BusPuPara[pu].Betrieb = 1;
					if ( MVWLEA[SO1]->wert == 1 )	// WW-Ladeventil offen
						BusPuPara[pu].Sollwert = wws[WW1].BusZirPuSollLad;	//	Sollwert bei WILO Pumpenbus
					else
						BusPuPara[pu].Sollwert = wws[WW1].BusZirPuSoll;			// Sollwert bei WILO Pumpenbus

				}
				else
				{
					BusPuPara[pu].Betrieb = 0;
					BusPuPara[pu].Sollwert = 0;
				}	
			}

			#if GENI > 0	
			wwd[ww].busZPuEin = pu_control[pu].pu_operation;	
			#endif
	
			#if WILO_MODBUS > 0	
			wwd[ww].busZPuEin = modWiloPu[pu].output_value1_temp;	
			#endif
		}
	}
#endif
}

