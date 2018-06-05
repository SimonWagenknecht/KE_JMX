/*		Task:	Steuer			*/

//#####ulsch: 25.02.05 bei Bedarfsabsenkung Pumpe aus nur wenn Ta >= 3 °C ( -> keine Regelung )
// bei Ta < 3 °C (Frostgefahr) regeln auf Absenkwert ( tvsb-Beabs )

#include <string.h>
#include "struct.h"
#include "ustruct.h"
#include "defins.h"
#include "sramext.h"
#include "uramext.h"
#include "standdef.h"
#include "unoinitext.h"
#include "uconstext.h"


// Unterprogramme
void mitteln(void);
void copy_ta1m(int ta);
void pu_aus(char hk);
void pu_Bm(char hk);
#if NTANZ > 0		// ***AnFre
void punt_Bm(char nt);
#endif
void PumpenLaufzeit ( void );
void LaufzeitHk ( char hk );
void Pu_Ein ( char hk );

void Pumpenbus_HZ ( char hk );
void PumpenbusSM ( void );				// für ALLE Pumpenbus-Pumpen (Genibus, Wilo)
void PumpenbusParli ( void );			// ***AnFre 12.12.2012 Parameter für ALLE WILO-Pumpen regenerieren 



/*---------------------- Task Steuer -----------------------------------*/
/* 					Aufruf erfolgt im 30 Sekundenrhythmus												*/

void Steuer(void)
{
	char i, j, aus;
	int zk_sec, taa;
	float fl_wert = 0;
	int maxAnf = 0;

	int tvsbww;			//Sollwert aus TWE

	int aktDatum;	// Sommerzeit ***AnFre 11.12.2008
	static char flipflop;
	
	flipflop ^= 1;
	
	// ***AnFre 30.05.2013 ext. SSM-Bezeichnung in den RAM eintragen
	if ( flipflop == 1 )
	{
		bicbus ( EEPADR,	(char *)( &extAlarmText ), EXTALARMTEXT_ADR, 15, BICRD );		// 16 Zeichen
	} 

	/*+++++++++++++++ maximale Anforderung +++++++++++++++++++++++*/
	#if HKANZ > 0		
	for ( i = HK1; i < HKANZ; i++ )
		if ( hkd[i].tvsb > 0 && ( hkd[i].tvsb + hks[i].TvpAnh > maxAnf ) )
			maxAnf = hkd[i].tvsb + hks[i].TvpAnh;
	#endif

	#if ANF_EXT > 0			
	for ( i = 0; i < ANF_EXT; i++ )
		if ( anfExt[i].stat == 0 && anfExt[i].messw > maxAnf )	
			maxAnf = anfExt[i].messw;						
	#endif
// ***AnFre				
//	#if WWANZ > 0	
//	if ( wwd[WW1].wwlad )
//	{
//		if ( ( wws[WW1].Twwlad + wws[WW1].TvpAnh ) > maxAnf )
//			maxAnf = wws[WW1].Twwlad + wws[WW1].TvpAnh;
//		if ( wwd[WW1].legio && ( ( wws[WW1].TwwladLegio + wws[WW1].TvpAnh ) > maxAnf ) )
//			maxAnf = wws[WW1].TwwladLegio + wws[WW1].TvpAnh;
//	}
//		#if REGEL_WW1 == 1
//		if ( wwd[WW1].tsol > 0 && ( wwd[WW1].tsol + wws[WW1].TvpAnh > maxAnf ) )
//			maxAnf = wwd[WW1].tsol + wws[WW1].TvpAnh;			
//		#endif	
//	#endif
	
	maxAnford = maxAnf;
	
	#if ANFORD == 1
	if ( maxAnford < TmanfSkalMin )
		TMANF[0]->awert = 0;
	else if ( maxAnford > TmanfSkalMax )	
		TMANF[0]->awert = TmanfSkalMaxSpg;
	else
		TMANF[0]->awert = Gerade_YvonX ( maxAnford, TmanfSkalMin, TmanfSkalMinSpg, TmanfSkalMax, TmanfSkalMaxSpg );					
	#endif
	
//-------***AnFre 06.06.2012 Externe Anforderung -------------------------------------------------
//-- für Heizkreis HK1: (in RegelHk.c) und Kessel KES (in Steuer1Ke.c) ---

// ---- erste externe Anforderung UST (HAST1.1): DatenManager oder analog 0...10Volt 
	if ( DM_ANF_Ext1.stat == 0 )
	{ 
		ExtAnf1.messw = DM_ANF_Ext1.messw;							// Anforderung von DatenManager
		ExtAnf1.stat 	= DM_ANF_Ext1.stat;
	}
	else
	{
		ExtAnf1.messw = anaInp[U2].mwSkal.messw;		// Anforderung von Analog-Eingang IN6
		ExtAnf1.stat 	= anaInp[U2].mwSkal.stat;
	}
// ---- zweite externe Anforderung (HAST1.2):  NUR DatenManager 30.05.2013
	ExtAnf2.stat 	= DM_ANF_Ext2.stat;
	if ( DM_ANF_Ext2.stat == 0 )
	{ 
		ExtAnf2.messw = DM_ANF_Ext2.messw;							// Anforderung von DatenManager
	}
	else
	{
		ExtAnf2.messw = 0;
	}
	
	/*+++++++++++++++ gedämpfte Außenlufttemperatur +++++++++++++++++++++++*/
	// Auswahl: gemessene TA oder Broadcast TA auf Zwischenspeicher ta kopieren
	if(bc_vorra == 1)															// Vorrang BC
	{	ta.stat  = bcta.stat;
		ta.messw = bcta.messw;
		bc_flag	 = TRUE;														// Flag für: BC wird benutzt
		if(ta.stat != 0) 
		{	if(TA[ANL]->stat == 0)										// dann TA untersuchen
			{	ta.stat  = TA[ANL]->stat;
				ta.messw = TA[ANL]->messw;
				bc_flag  = FALSE;												// Flag für: BC wird nicht benutzt
			}
		} 
	}
	else																					// Vorrang TA
	{	ta.stat  = TA[ANL]->stat;
		ta.messw = TA[ANL]->messw;
		bc_flag  = FALSE;
		if(ta.stat != 0) 
		{	if(bcta.stat == 0)												// dann BC untersuchen
			{	ta.stat  	= bcta.stat;
				ta.messw 	= bcta.messw;
				bc_flag	  = TRUE;
			} 
		} 
	}
	
	// ***** josch: Datenmanager
	// Die Außentemperatur der Slaves wird zyklisch empfangen. Organisation im Task: DTimer()
	#if DM_MODE == 1														// Gerät im DM_Modus (Data Master)
	if(ta.stat != 0)														// nur wenn kein Pt1000 und keine Broadcast-Temperatur				
	{
		// Untersuchung auf Gültigkeit
		for(i = 0; i < DM_SLAVES; i++)
		{
			if(DM[i].rdta_flag == 1)								// Flag für erfolgte Datenübertragung
			{
				if(DM[i].rdta_bc == 0)								// keine Broadcast-Ta vom Slave
				{
					if(DM[i].rdta.stat == 0)						// Status ok
					{
						ta.stat = 0;											// Ta wird übernommen
						ta.messw = DM[i].rdta.messw;
						break;
					}
				}	
			}
		}	
	}			
	#endif
	
	
	// Außentemperatur über Analogeingang 0..10V
	#if TAE_ANZ == 1															
		ta_ae.stat = TAE[0]->stat;
		ta_ae.messw = Gerade_YvonX ( TAE[0]->messw, 0, TaeSkalMin, 1000, TaeSkalMax );
		
		if ( ta.stat != 0 )														// nur wenn kein Pt1000, keine Broadcast-Temperatur				
		{														
			if ( ta_ae.stat == 0 )											// ist der Eingang  ungestört ? 
			{
				ta.stat = 0;
				ta.messw = ta_ae.messw;										// dann wird er benutzt
			}
		}
	#endif

	// Außentemperatur auf Analogausgang ausgeben ( 0..10V -> [-20,0]..[+40,0] ) 
	#if TAA_ANZ > 0
		taa = ta.messw;
		if(taa < TaaSkalMin )
			taa = 0;
		else if(taa > TaaSkalMax)
			taa = 1000;	
		
		for(i = 0; i < TAA_ANZ; i++)
			TAA[i]->awert = Gerade_YvonX ( taa, TaaSkalMin, 0, TaaSkalMax, 1000 );					
	#endif	

	// gedämpfte Außentemperatur
	ta1m.stat  = ta.stat;													// Status kopieren
	if(ta1m.stat == 0)														// Messwert ok ?
	{																							// ja
		if( (steustart == 0) || (Ta1mzk == 0) )			// nach Reset oder Zk = 0 
		{	ta1m.messw		= ta.messw;									// keine Filterung
			fl_ta1m				= (float)ta1m.messw / 10;
		}
		else	
		{	zk_sec = Ta1mzk * 600;		// Zeitkonstante Umrechnung Minuten in 1/10 sek
			// Ausgangswert(A), Eingangswert(E), Tastzeit(t), Zeitkonstante(T)
			fl_ta1m = g_filter(fl_ta1m, ta.messw, 300, zk_sec);
			ta1m.messw = (int)(fl_ta1m * 10);			// für Anzeige und Weiterverarbeitung
		}	
		TaErsatzCtr = 0;
	}
	else			// Messwert nicht ok
	{
		if(steustart == 0)											// nach Reset
		{	if(ramex1 == RAMEX1)									// i.o., Test auf zerstörten Ram (Noinit-Bereich)
				ta1m.messw = (int)(fl_ta1m * 10);		// gespeicherten Wert holen
			else
			{	
//-				fl_ta1m = 0;
//-				ta1m.messw = 0;
				if ( Mon > 0 && Mon <= 12 )
					ta1m.messw = TaErsatz[Mon-1];
				else
					ta1m.messw = 0;
				fl_ta1m	= (float)ta1m.messw / 10;	
			}	
		}
		else
		{
			if ( TaErsatzCtr < 0xFFFF )
				++TaErsatzCtr;
			if ( TaErsatzCtr >= (UINT)TaErsatzVerz * 120 && Mon > 0 && Mon <= 12 )	
				ta1m.messw = TaErsatz[Mon-1];
			fl_ta1m	= (float)ta1m.messw / 10;			// Handeingabe synchronisieren
		}
	}		
	
	
	/*++++++++++++ gemittelte Außenlufttemperatur über Stunden ++++++++++++*/
	ta1mh.stat  = ta.stat;							// Status kopieren
	if(ramex1 == RAMEX1)								// i.o., Test auf zerstörten Ram (Noinit-Bereich)
		mitteln();							
	else		// Ram ist zerstört
	{	// EEPROM lesen
		bicbus(EEPADR,	(char *)&fl_wert,	FL_TA1MH_ADR,	4, BICRD);
		// Sinnfälligkeitstest
		if((fl_wert > -20) && (fl_wert < 40))
		{	fl_ta1mh	= fl_wert;					// Wert übernehmen
			ramex1		= RAMEX1;						// Kennzeichen im Noinit-Rambereich
			mitteln();
		}	
		else														// Wert im EEPROM nicht sinnfällig,
			copy_ta1m(ta1m.messw);				// gedämpfte ta1m übernehmen
	}			

	// Parameter zum Einstellen (init) einer gewünschten ta1mh
	if(ta1mh_temp != 0)								// Einstellwert muss ungleich 0,0 sein
	{	copy_ta1m(ta1mh_temp);
		ta1mh_temp = 0;
	}	
	
	steustart				= 1;
	
	/*++++++++++ Sommer-/Winterumschaltung ++++++++++++++++++++++++++++++++++*/
	/*---------- mit Sommerzeit ( Datum ) ***AnFre 11.12.2008 ---------------*/

	aktDatum = Mon * 100 + Tag;	
	if ( ( aktDatum >= SomBegin[0] * 100 + SomBegin[1] ) &&
			 ( aktDatum <= SomEnd[0] * 100 + SomEnd[1] ) )
	{
		sowi = 1;							// Sommerbetrieb nach Datum
	}
	else
	{
		if(ta1mh.messw <= Tae) 							// ta1mh <= Winter-Ein-Temp. ?
			sowi = 0;													// Winterbetrieb
		else if(ta1mh.messw >= Taa)					// ta1mh >= Sommer-Ein-Temp. ?
			sowi = 1;													// Sommerbetrieb
	}

	PumpenLaufzeit ( );									// Laufzeit der Heizungspumpen und der Hauptpumpe
	
#if ( BUS_PU_MAX > 0 )
	Pumpenbus_HZ ( HK1 );	
	PumpenbusSM ( );				// Überwachung der Rückmeldungen Betriebsart / Regelart für ALLE Pumpen
	PumpenbusParli ( );			// Pumpen-Parameter für Anzeige in den Gruppen der Parli erzeugen
#endif
	
	/*++++++++++ Pumpen ein/aus ++++++++++++++++++++++++++++++++++++++*/
	for(i = 0; i < HKMAX; i++)				// Nur 1 Heizkreis !!!
	{	
		aus = FALSE;

// ----- Handbetrieb --------------------------------------------------------------
// auch WILO ModBus
		BusPuPara[PU_BUS_HK1-1].Hand = hks[HK1].Haut;
		
		if(hks[HK1].Haut == TRUE)								// bei Handbetrieb,
		{
			if ( hks[HK1].Puea > 3 )
				hks[HK1].Puea = 0;
			if ( BusPuPara[PU_BUS_HK1-1].Funktion == 0 )	// ***AnFre Kein Wilo-PumpenBus
			{
				if ( hks[HK1].Puea > 0 )					// Pumpenrelais Handwert eintragen
					PU[HK1]->wert			= 1;
				else
					PU[HK1]->wert			= 0;
				BusPuPara[PU_BUS_HK1-1].BetriebHand		= 0;
				BusPuPara[PU_BUS_HK1-1].SollHand			= 0;
			}
			else
			{
				PU[HK1]->wert			= 1;	// Pumpenrelais immer Ein eintragen
				BusPuPara[PU_BUS_HK1-1].BetriebHand		= hks[HK1].Puea;	// Pumpen-Handwert Ein / Aus, Min.-, Max.-Drehzahl eintragen
				// SollHand Pufferpumpe  wird direkt in parli eingetragen
				// RegelartHand wird direkt in parli eingetragen
			}	
			hkd[HK1].puBm  		= 0;									// kein Soft-Alarm für fehlende Betriebsmeldung
			hkd[HK1].puBmVerz	= 0;									// Verzögerung Soft-Alarm für fehlende Betriebsmeldung

		}
		else
		{	// ----- Automatikbetrieb	----------------------------------------------
			pu_Bm(i);			// Betriebsmeldung der Heizungspumpe überwachen
					
//#####ulsch: 28.02.07 Pumpen schalten entsprechend tvsb !
			if ( hkd[i].tvsb > 0 || ssfEinAnl == TRUE )
			{	// Pumpe einschalten
				Pu_Ein ( i );
				
//#####090119
//-				if(hkd[i].vorra_bed == FALSE)					// kein Vorrang Bedarfsabsenkung vor Zeitabsenkung
//-					PUMIN[i]->wert = abs_ram[i].absen;	// Minimaldrehzahl in der Absenkphase
				PUMIN[i]->wert = ( hkd[i].absen && hkd[i].aufhe == 0 ) ? 1 : 0;	// auch bei Bedarfsabsenkung: Minimaldrehzahl in der Absenkphase, nicht bei Aufheizphase

				hkd[i].zpu 			= hks[i].Puna * 2;		// Zähler für Pumpennachlaufzeit laden (* 30 Sek-Task)
			}
			else
				pu_aus(i);									// Prozedur: Pumpe ausschalten

		}		

		hkd[i].ucCool = 0;

//-		hkd[i].ucHeat = ( hkd[i].somme	== FALSE ) ? ( 1 << i ) : 0;
// 110916: Forderung Dr.Riedel/Diele: Heizen trotz Sommer setzen, wenn Vorlauf nicht wirklich kalt 
// - der R50 soll dann die Heizkörperventile nicht öffnen (stromlos machen)
		if ( hkd[i].somme	== FALSE )
			hkd[i].ucHeat = TRUE;
		else
		{
			if ( TVS[i]->stat == 0 )	
			{
				if ( TVS[i]->messw <= hks[i].VorlaufMaxSommer )
					hkd[i].ucHeat = FALSE;				
				else if ( TVS[i]->messw >= hks[i].VorlaufMaxSommer + 5 )		// Hysterese 0,5 K
					hkd[i].ucHeat = TRUE;				
			}
			else
				hkd[i].ucHeat = FALSE;					
		}

	}	//	Ende for (i)

// ***** josch: Datenmanager
#if DM_MODE == 1		// Gerät im DM_Modus (Data Master),	Datenbearbeitung in der Funktion: DManager(), Organisation der Datenübertragung im Task: DTimer() 
	DManager();
#endif

}	
/*---------------------- Task Steuer Ende ---------------------------------*/



/*-------------------------Unterprogramme----------------------------------*/

/* Prozedur zur Mittelung der Außenlufttemperatur über Stunden	*/
void mitteln(void)
{
	int zk_minute;
	
	if(Ta1mhzk == 0)									// wenn Zeitkonstante [h] = 0
		fl_ta1mh = fl_ta1m;							// gedämpfte Ta übernehmen
	
	if(++zzta1mh < 20)											// Filtertastzeit 10 Minuten (20*30s)
	{	if(steustart == 0 || Ta1mhzk == 0)		// nach Reset oder Zeitkonstante [h] = 0
			ta1mh.messw = (int)(fl_ta1mh * 10);	// für Anzeige und Weiterverarbeitung
	}
	else	
	{	zzta1mh = 0;
		zk_minute 	= Ta1mhzk * 60;					// Zeitkonstante Umrechnung Stunden in min
		if(zk_minute > 0)
		{	// Ausgangswert(A), Eingangswert(E), Tastzeit(t), Zeitkonstante(T)
			fl_ta1mh = g_filter(fl_ta1mh, ta1m.messw, 10, zk_minute);
			ta1mh.messw = (int)(fl_ta1mh * 10);	// für Anzeige und Weiterverarbeitung
		}
		if(++zzsave < 6);			// 6*10Min = 1 Std, Zeitzähler für Ablage im EEPROM
		else
		{	zzsave = 0;
			bicbus(EEPADR,	(char *)&fl_ta1mh,	FL_TA1MH_ADR,	4, BICWR);
		}
	}	
}

/* Kopieren von ta1m nach ta1mh	*/
void copy_ta1m(int ta)
{
	//ta1mh.messw	= ta1m.messw;
	ta1mh.messw			= ta;
	fl_ta1m					= (float)ta / 10;
	fl_ta1mh				= fl_ta1m;					// fl_ta1mh im Noinit-Rambereich
	ramex1					= RAMEX1;						// Kennzeichen im 		"
	bicbus(EEPADR,	(char *)&fl_ta1mh,	FL_TA1MH_ADR,	4, BICWR);
}	

/* Prozedur Pumpe ausschalten	*/
// IN:	hk...Heizkreis
void pu_aus(char hk)
{
	if(hkd[hk].zpu > 0)
		hkd[hk].zpu--;
	else
	{	
		if ( hk == HK1 )
		{
			BusPuPara[PU_BUS_HK1-1].Betrieb		= 0;
			BusPuPara[PU_BUS_HK1-1].Sollwert	= 0;
			if ( BusPuPara[PU_BUS_HK1-1].Funktion == 0 )	// ***AnFre Kein Wilo-PumpenBus
				PU[hk]->wert	= 0;						// Pumpe ausschalten
			else
			{
				PU[hk]->wert	= 1;						// Pumpenrelais immer einschalten
			}
		}	
		// Blockierschutz bei Sommerbetrieb
		if(hkd[hk].sowi > 0)
		{	if((Wotag == 1) && (Std == 0) && (Min == hk))
			{	PU[HK1]->wert	= 1;						// Pumpenrelais einschalten
				BusPuPara[PU_BUS_HK1-1].Betrieb	= 1;
				BusPuPara[PU_BUS_HK1-1].Sollwert	= 600;	//hks[HK1].PuDzMin;
				hkd[HK1].zpu		= 5;						// ca. 2 Minuten
			}
		}
	}
}				

// Betriebsmeldung der Heizungspumpe überwachen ***AnFre 06.06.2012
void pu_Bm(char hk)
{
	if(BMPU[hk]->bwert == 1)			// Betriebsmelde-Kontakt Ein ?
	{
		hkd[hk].puBm = 0;				// kein Alarm
		hkd[hk].puBmVerz = 0;		// Verzögerung Alarm =0
	}
	else
	{
		if ( BusPuPara[PU_BUS_HK1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus
		{
			if(PU[HK1]->wert == 1)				// Pumpe EIN ?
			{
				if (hkd[hk].puBmVerz < 3)	// Verzögerung Soft-Alarm: 'kein Betriebsmeldungs-Signal' ***AnFre 06.06.12
					hkd[hk].puBmVerz ++;
				else
						hkd[hk].puBm = 1;				// Soft-Alarm: 'kein Betriebsmeldungs-Signal'
			}
		}
	}		
}

// Laufzeit der Heizungspumpen
// Laufzeit der Hauptpumpe/Netztrennungspumpe
// wird ebenfalls hier berechnet, weil diese Pumpe auch in Kesselanlagen benutzt werden kann
 
void PumpenLaufzeit ( void )
{
	static char i = 0;						// alle 5 Minuten ein HK- bzw. NT-Zähler
#if PULZ_NT1 == 1
	static char ctrnt;
#endif

	switch ( i )
	{
		case HK1 :
			#if PULZ_HK1 == 1	
			if ( BusPuPara[PU_BUS_HK1 - 1].Funktion == 0 ) // ***AnFre wenn kein PumpenBus 
				LaufzeitHk ( i );		
			#endif
			break;
		case HK2 :
			#if PULZ_HK2 == 1	
			LaufzeitHk ( i );		
			#endif
			break;
		case HK3 :
			#if PULZ_HK3 == 1	
			LaufzeitHk ( i );		
			#endif
			break;
		case HK4 :
			#if PULZ_HK4 == 1	
			LaufzeitHk ( i );		
			#endif
			break;
		case 4 :
			#if PULZ_NT1 == 1
			if ( PUNTEA[NT1]->func != NICHTV && PUNTEA[NT1]->wert && (++ctrnt >= 12 ) )
			{
				ctrnt = 0;
				++ntd[NT1].puLz;
				bicbus ( EEPADR,	(char *)&ntd[NT1].puLz,	PU_NT_H_ADR, 2, BICWR);
			}
			#endif
			break;
		default :
			break;																												
	}
	if ( ++i >= 10 )
		i = 0;											// damit alle 5 Minuten eine Berechnung		

}

// Pumpen-Laufzeit-Berechnung alle 5 Minuten
void LaufzeitHk ( char hk )
{
#if ( PULZ_HK1 == 1 || PULZ_HK2 == 1 || PULZ_HK3 == 1 || PULZ_HK4 == 1 )

	if ( PU[hk]->func != NICHTV && PU[hk]->wert && (++hkd[hk].pu1min >= 12 ) )
	{
		hkd[hk].pu1min = 0;
		++hkd[hk].puLz;
		bicbus ( EEPADR,	(char *)&hkd[hk].puLz,	PU_HK_H_ADR + 2 * hk, 2, BICWR);
	}

	#if PUDO == 1
	if ( PUD[hk]->func != NICHTV && PUD[hk]->wert && (++hkd[hk].pu2min >= 12 ) )
	{																									// Pumpe ist eingeschaltet
		hkd[hk].pu2min = 0;															// Minutenzähler
		++hkd[hk].pudLz;																// Stundenzähler
		bicbus ( EEPADR, (char*)&hkd[hk].pudLz, PUD_HK_H_ADR + 2 * hk, 2, BICWR);
	}	

	// Vorsicht : Überlauf
	// falls nicht verhindert, ist diese Laufzeit immer kleiner als die der anderen Pumpe -> Umschalten funktioniert nicht mehr
	// beide Zähler korrigieren und sichern !
	if ( hkd[hk].puLz	== 0xFFFF )
	{
		hkd[hk].puLz = hkd[hk].puLz - hkd[hk].pudLz;
		hkd[hk].pudLz = 0;
		bicbus ( EEPADR,	(char *)&hkd[hk].puLz,	PU_HK_H_ADR + 2 * hk, 2, BICWR);
		bicbus ( EEPADR, (char*)&hkd[hk].pudLz, PUD_HK_H_ADR + 2 * hk, 2, BICWR);
	}
	else if ( hkd[hk].pudLz	== 0xFFFF )
	{
		hkd[hk].pudLz = hkd[hk].pudLz - hkd[hk].puLz;
		hkd[hk].puLz = 0;
		bicbus ( EEPADR,	(char *)&hkd[hk].puLz,	PU_HK_H_ADR + 2 * hk, 2, BICWR);
		bicbus ( EEPADR, (char*)&hkd[hk].pudLz, PUD_HK_H_ADR + 2 * hk, 2, BICWR);
	}									
	#endif
		
#endif	
}

void Pu_Ein ( char hk )
{
	char fuehrPu;

#if PUDO == 1	
	
	fuehrPu = hks[hk].FuehrPu;
	if ( fuehrPu == 0 || fuehrPu > 2 )
		fuehrPu = 1; 
	
// muss die Führungs-Pumpe gewechselt werden ?	
	if ( hks[hk].FuehrPuFest > 3 )
		hks[hk].FuehrPuFest = 3;												// Eingabefehler korrigieren
		
	if ( hks[hk].FuehrPuFest != 1 && hks[hk].FuehrPuFest != 2 )
	{																									// laufzeitabh.Wechsel parametriert
		if ( fuehrPu == 1 )
		{
			if ( hkd[hk].puLz > hkd[hk].pudLz && ( hkd[hk].puLz - hkd[hk].pudLz >= hks[hk].PuWechseln ) )
				fuehrPu = 2;
		}
		else if ( fuehrPu == 2 )
		{
			if ( hkd[hk].pudLz > hkd[hk].puLz && ( hkd[hk].pudLz - hkd[hk].puLz >= hks[hk].PuWechseln ) )
				fuehrPu = 1;
		}
	}
	else
		fuehrPu = hks[hk].FuehrPuFest; 

// Führungspumpe gestört ?
	if ( fuehrPu == 1 )
	{
		if ( PUAL[hk]->bstat != NICHTV && PUAL[hk]->bwert )
			fuehrPu = 2;
	}						
	else if ( fuehrPu == 2 )
	{
		if ( PUDAL[hk]->bstat != NICHTV && PUDAL[hk]->bwert )
			fuehrPu = 1;
	}	
	
	hks[hk].FuehrPu = fuehrPu;
	
	if ( hks[hk].FuehrPuFest == 3 )
	{																			// immer beide Pumpen gleichzeitig einschalten
		PU[hk]->wert = 1;
		PUD[hk]->wert = 1;
	}	
	else if ( fuehrPu == 2 )
	{
		PUD[hk]->wert = 1;
		PU[hk]->wert = 0;	
	}
	else
	{
		PU[hk]->wert = 1;
		PUD[hk]->wert = 0;	
	}		

#else

		PU[hk]->wert = 1;	

#endif			

}					

void Pumpenbus_HZ ( char hk )
{
#if BUS_PU_MAX > 0
	char pu = 0;
	
	if ( hk == HK1 )
		pu = PU_BUS_HK1;
	else if ( hk == HK2 )
		pu = PU_BUS_HK2;
	else if ( hk == HK3 )
		pu = PU_BUS_HK3;
	else if ( hk == HK4 )
		pu = PU_BUS_HK4;

	if ( pu > 0 && pu <= BUS_PU_MAX )
	{
		pu -= 1;
		
		if ( BusPuPara[pu].Funktion == 1 )
		{
			if ( ssfEinAnl == TRUE )
			{
				BusPuPara[pu].Betrieb = 1;																// Pumpe EIN
				BusPuPara[pu].Sollwert = hks[hk].BusPuSollwert;
			}
			else if ( hkd[hk].tvsb > 0 || hkd[hk].zpu )
			{
				BusPuPara[pu].Betrieb = 1;																// Pumpe EIN
				BusPuPara[pu].Sollwert = ( hkd[hk].absen == TRUE ) ? hks[hk].BusPuSollwertAbsenk : hks[hk].BusPuSollwert;
			}
			else
			{
				BusPuPara[pu].Betrieb = 0;																// Pumpe AUS
				BusPuPara[pu].Sollwert = 0;
			}
		}
		else
		{
			BusPuPara[pu].Betrieb = 0;																	// Pumpe AUS
			BusPuPara[pu].Sollwert = 0;
		}		

		#if GENI == 1
		hkd[hk].busPuEin = BusPuData[pu].uc_betriebsart;	
		#endif

		#if WILO_MODBUS == 1
		hkd[hk].busPuEin = modWiloPu[pu].output_value1_temp;
		#endif
	
		#if GRUNDFOS_MODBUS == 1
		
		#endif

	}	
#endif
}


// Vergleich der ausgegebenen und rückgelesenen Parameter 
// von Betriebsart (EIN, AUS, MIN, MAX) und Regelart (Konstantdruck etc.)
void PumpenbusSM ( void )
{
#if BUS_PU_MAX > 0 && (GENI == 1 || WILO_MODBUS == 1 || GRUNDFOS_MODBUS == 1)
	char sm;
	char pu;
	char ssm;
	
	for ( pu = 0; pu < BUS_PU_MAX; pu++ )
	{
		sm = FALSE;
		if ( BusPuPara[pu].Funktion == 1 && BusPuPara[pu].Hand == 0 )		// nur im Remote Mode und bei Automatik-Betrieb testen
		{
#if GENI == 1
			if ( ( BusPuData[pu].uc_betriebsart == Geni_Values[pu].uc_operation_reply )	&&		// Betriebsart (Bits in act_mode1 siehe Seite 4 UPE)
				 	 ( BusPuData[pu].uc_regelart == Geni_Values[pu].uc_control_reply ) )				// Regelart
#elif WILO_MODBUS == 1
			if ( modWiloPu[pu].output_value1_temp == modWiloPu[pu].Operation_Input			// Betriebsart
				&& modWiloPu[pu].output_value2_temp == modWiloPu[pu].Control_Input )			// Regelart
#elif GRUNDFOS_MODBUS == 1


#endif
			{
				BusPuData[pu].betriebRmCtr	= 0;
			}
			else
			{
				if ( BusPuData[pu].betriebRmCtr < 0xFFFF )
					++BusPuData[pu].betriebRmCtr;
				if ( BusPuData[pu].betriebRmCtr >= ( BusPuPara[pu].RMverz * 2 )
						&& ( BusPuPara[pu].RMverz > 0 ) ) 
					sm = TRUE;				
			}			
		}
		else
			BusPuData[pu].betriebRmCtr	= 0;	
		
		BusPuData[pu].betriebSm = sm;
	}

// Sammelalarm, verzögert um 3 Minuten
	ssm = FALSE;
	for ( pu = 0; pu < BUS_PU_MAX; pu++ )
		if ( BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm )
			ssm = TRUE;

	if ( ssm == TRUE )
	{
		if ( ssmPuCtr < 0xFF )
			++ssmPuCtr;
	}
	else
		ssmPuCtr = 0;
			
	ssmBusPu = ( ssmPuCtr > 5 ) ? TRUE : FALSE;

		

// Pumpenstörung in den Parametergruppen (HKn, WW1, KE1, ...)
#if PU_BUS_HK1 > 0 
	pu = PU_BUS_HK1 - 1;
	hkd[HK1].busPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_HK2 > 0 
	pu = PU_BUS_HK2 - 1;
	hkd[HK2].busPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_HK3 > 0 
	pu = PU_BUS_HK3 - 1;
	hkd[HK3].busPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_HK4 > 0 
	pu = PU_BUS_HK4 - 1;
	hkd[HK4].busPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_KE1 > 0
	pu = PU_BUS_KE1 - 1;
	ked[KE1].busPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_KE2 > 0
	pu = PU_BUS_KE2 - 1;
	ked[KE2].busPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_ZPU_WW1 > 0
	pu = PU_BUS_ZPU_WW1 - 1;
	wwd[WW1].busZPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_TPU_WW1 > 0
	pu = PU_BUS_TPU_WW1 - 1;
	wwd[WW1].busTPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_LPU_WW1 > 0
	pu = PU_BUS_LPU_WW1 - 1;
	wwd[WW1].busLPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_NT1 > 0
	pu = PU_BUS_NT1 - 1;
	ntd[NT1].busPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_SOL > 0	// Solar-Pumpe
	pu = PU_BUS_SOL - 1;
	sod[SO1].busSolPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#if PU_BUS_PUF > 0	// Puffer-Pumpe
	pu = PU_BUS_PUF - 1;
	sod[SO1].busPufPuSm = BusPuData[pu].puAlarm || BusPuData[pu].busSm || BusPuData[pu].betriebSm;
#endif 

#endif	
}	

// ***AnFre 12.12.2012 zusätzliche Parameter in Parli-Gruppen SOL: HK1: TWE:  für ALLE WILO-Pumpen 
void PumpenbusParli ( void )
{

	// SOL: Solar-Pumpe
	if ( BusPuPara[PU_BUS_SOL - 1].Funktion == 1 )
	{	
		wilo1 = SICHTSERV1;																											// Pumpen-Bus-Parameter hid1
		sod[SO1].solPuEinAnz = modWiloPu[PU_BUS_SOL - 1].output_value1_temp;		// Betriebsart Ein/Aus Befehl nach Pumpe
		if ( modWiloPu[PU_BUS_SOL - 1].Operation_Input < 4 )										// Operation_Input = 4: Keine Bus-Pumpe 
			sod[SO1].solPuBmAnz	 = modWiloPu[PU_BUS_SOL - 1].Operation_Input;			// Betriebsart Ein/Aus Meldung von Pumpe
		else
			sod[SO1].solPuBmAnz	 = 0;
		sod[SO1].solPuSmAnz	 = sod[SO1].busSolPuSm;															// Störungs-Meldung von Pumpe
		sod[SO1].solPuLzAnz	 = modWiloPu[PU_BUS_SOL - 1].op_hours;							// Pumpen-Betriebszeit
	}
	else
	{
		wilo1 = SICHTSERV4;																				// Pumpen-Bus-Parameter hid4
		sod[SO1].solPuEinAnz	= sod[SO1].solarPu;									// Solar-Pumpe Ein/Aus (wie Relais-Ausgabe)
		sod[SO1].solPuBmAnz		= BMPUSOL[SO1]->bwert;							// RM-Pumpe R37_2;IN3
		sod[SO1].solPuSmAnz		= sod[SO1].pusoBm;									// Störungs-Meldung von Pumpe
		sod[SO1].solPuLzAnz		=	(ULONG)sod[SO1].lzKolPuH;					// Pumpen-Laufzeit
	}
	
	// SOL: Puffer-Pumpe
	if ( BusPuPara[PU_BUS_PUF - 1].Funktion == 1 )
	{	
		wilo2 = SICHTSERV1;																											// Pumpen-Bus-Parameter hid1
		sod[SO1].pufPuEinAnz = modWiloPu[PU_BUS_PUF - 1].output_value1_temp;		// Betriebsart Ein/Aus Befehl nach Pumpe
		if ( modWiloPu[PU_BUS_PUF - 1].Operation_Input < 4 )										// Operation_Input = 4: Keine Bus-Pumpe 
			sod[SO1].pufPuBmAnz	 = modWiloPu[PU_BUS_PUF - 1].Operation_Input;			// Betriebsart Ein/Aus Meldung von Pumpe
		else
			sod[SO1].pufPuBmAnz	 = 0;
		sod[SO1].pufPuSmAnz	 = sod[SO1].busPufPuSm;															// Störungs-Meldung von Pumpe
		sod[SO1].pufPuLzAnz	 = modWiloPu[PU_BUS_PUF - 1].op_hours;							// Pumpen-Betriebszeit
	}
	else
	{
		wilo2 = SICHTSERV4;																				// Pumpen-Bus-Parameter hid4
		sod[SO1].pufPuEinAnz = sod[SO1].pufferPu;									// Puffer-Pumpe Ein/Aus (Relais-Ausgabe)
		sod[SO1].pufPuBmAnz	 = BMPUPUF[SO1]->bwert;								// RM-Pumpe R37_2;IN2
		sod[SO1].pufPuSmAnz	 = sod[SO1].pupuBm;										// Störungs-Meldung von Pumpe
		sod[SO1].pufPuLzAnz	 = (ULONG)sod[SO1].lzPufPuH;					// Pumpen-Laufzeit
	}

	// HK1: Pumpe
	if ( BusPuPara[PU_BUS_HK1 - 1].Funktion == 1 )
	{	
		wilo3 = SICHTSERV1;																											// Pumpen-Bus-Parameter hid1
		hkd[HK1].puEinAnz = modWiloPu[PU_BUS_HK1 - 1].output_value1_temp;				// Betriebsart Ein/Aus Befehl nach Pumpe
		if ( modWiloPu[PU_BUS_HK1 - 1].Operation_Input < 4 )										// Operation_Input = 4: Keine Bus-Pumpe 
			hkd[HK1].puBmAnz	 = modWiloPu[PU_BUS_HK1 - 1].Operation_Input;				// Betriebsart Ein/Aus Meldung von Pumpe
		else
			hkd[HK1].puBmAnz	 = 0;
		hkd[HK1].puSmAnz	 = hkd[HK1].busPuSm;																	// Störungs-Meldung von Pumpe
		hkd[HK1].puLzAnz	 = modWiloPu[PU_BUS_HK1 - 1].op_hours;								// Pumpen-Betriebszeit
	}
	else
	{
		wilo3 = SICHTSERV4;																				// Pumpen-Bus-Parameter hid4
		hkd[HK1].puEinAnz = PU[HK1]->wert;												// Relais-Ausgabe
		hkd[HK1].puBmAnz	= BMPU[HK1]->bwert;											// RM-Pumpe R37_2;IN3
		hkd[HK1].puSmAnz	= hkd[HK1].puBm;												// Störungs-Meldung von Pumpe
		hkd[HK1].puLzAnz	=	(ULONG)hkd[HK1].puLz;									// Pumpen-Laufzeit
	}

	// TWE: Tauscher-Pumpe	30.05.2013
	if ( BusPuPara[PU_BUS_TPU_WW1 - 1].Funktion == 1 )
	{	
		wilo4 = SICHTSERV1;																											// Pumpen-Bus-Parameter vis
		wwd[WW1].puwtEinAnz = modWiloPu[PU_BUS_TPU_WW1 - 1].output_value1_temp;	// Betriebsart Ein/Aus Befehl nach Pumpe
		if ( modWiloPu[PU_BUS_TPU_WW1 - 1].Operation_Input < 4 )								// Operation_Input = 4: Keine Bus-Pumpe 
			wwd[WW1].puwtBmAnz	 = modWiloPu[PU_BUS_TPU_WW1 - 1].Operation_Input;	// Betriebsart Ein/Aus Meldung von Pumpe
		else
			wwd[WW1].puwtEinAnz	 = 0;
		wwd[WW1].puwtSmAnz	 = wwd[WW1].busTPuSm;																// Störungs-Meldung von Pumpe
		wwd[WW1].puwtLzAnz	 = modWiloPu[PU_BUS_TPU_WW1 - 1].op_hours;					// Pumpen-Betriebszeit
	}
	else
	{
		wilo4 = SICHTSERV4;																				// Pumpen-Bus-Parameter hid4
		wwd[WW1].puwtEinAnz	= wwd[WW1].tauschPu;									// Ausgabe Tauscherpumpe ein/aus
		wwd[WW1].puwtBmAnz	= BMPUWT[WW1]->bwert;									// RM-Pumpe R37_2;IN5
		wwd[WW1].puwtSmAnz	= wwd[WW1].puwtBm;										// Störungs-Meldung von Pumpe
		wwd[WW1].puwtLzAnz	= (ULONG)wwd[WW1].puwth;							// Pumpen-Laufzeit
	}

	// TWE: Zirk.-Pumpe	30.05.2013
	if ( BusPuPara[PU_BUS_ZPU_WW1 - 1].Funktion == 1 )
	{	
		wilo5 = SICHTSERV1;																											// Pumpen-Bus-Parameter vis
		wwd[WW1].puwzEinAnz = modWiloPu[PU_BUS_ZPU_WW1 - 1].output_value1_temp;	// Betriebsart Ein/Aus Befehl nach Pumpe
		if ( modWiloPu[PU_BUS_ZPU_WW1 - 1].Operation_Input < 4 )								// Operation_Input = 4: Keine Bus-Pumpe 
			wwd[WW1].puwzBmAnz	 = modWiloPu[PU_BUS_ZPU_WW1 - 1].Operation_Input;	// Betriebsart Ein/Aus Meldung von Pumpe
		else
			wwd[WW1].puwzEinAnz	 = 0;
		wwd[WW1].puwzSmAnz	 = wwd[WW1].busZPuSm;																// Störungs-Meldung von Pumpe
		wwd[WW1].puwzLzAnz	 = modWiloPu[PU_BUS_ZPU_WW1 - 1].op_hours;					// Pumpen-Betriebszeit
	}
	else
	{
		wilo5 = SICHTSERV4;																				// Pumpen-Bus-Parameter hid4
		wwd[WW1].puwzEinAnz	= PUWZEA[WW1]->wert;									// Relais-Ausgabe
		wwd[WW1].puwzBmAnz	= BMPUWZ[WW1]->bwert;									// RM-Pumpe R37_2;IN4
		wwd[WW1].puwzSmAnz	= wwd[WW1].puwzBm;										// Störungs-Meldung von Pumpe
		wwd[WW1].puwzLzAnz	= (ULONG)wwd[WW1].puwzh;							// Pumpen-Laufzeit
	}

}

