/***** 					Diagnose 						 *****/
/***** speziell fuer FW-R-0112/K-CHO *****/

#include "struct.h"
#include "defins.h"
#include "sramext.h"
#include "uramext.h"
#include "standdef.h"


/* Task "Diagnose" laeuft all 10 Sekunden */
/* es gibt 6 Programm-Zweige, die minuetlich aufgerufen werden */

void Diagnose ( void )
{
#if DIAG == 1
	char i, n;
	char j;													//*** AnFre 03.09.2009 KWZ-Volstrom-Bereiche
	static char part = 5;
	static char neustart = 1;
	static char leistgBereich_min[4];
	static char flowBereich_min[4];
	static UINT flowBereichKWZ_sek[4];	//*** AnFre 03.09.2009 KWZ-Volstrom-Bereiche in 10sek
	static UINT gesZeit_sek = 1;				//*** AnFre 03.09.2009 GesamtZeit in 10sek
	static char wwlad = 0;
	static UINT wwlad_min;
	static char wwvor = 0;
	static UINT wwvor_min;
	static char geloescht = 0;

// ***AnFre 06.06.2012 Gemittelte Rücklauftemp. HK1
	static char m = 0;	// ***AnFre 06.06.2012 MinutenZähler
	char k;	// ***AnFre 06.06.2012 Monatszähler TH2
	
		
	if ( neustart )
	{																																			// aktuelle Ergebnisse zurückholen
		xicbus ( XEEPADR,	(char *)( &did ), DIAG_ADR, sizeof(did), BICRD );	
		
		if ( did.tvpMax.tag.tag == 0 || did.tvpMax.tag.monat == 0 )					// Tag oder Monat darf nicht 0 sein (Leittechnik-Problem)
		{
			did.tvpMax.tag.tag = 1; did.tvpMax.tag.monat = 1; did.tvpMax.tag.jahr = 0;
			xicbus ( XEEPADR,	(char *)( &did.tvpMax), TVPMAXDIAG_ADR, sizeof( did.tvpMax ), BICWR );	
		}						
		if ( did.tvpMin.tag.tag == 0 || did.tvpMin.tag.monat == 0 )					// Tag oder Monat darf nicht 0 sein (Leittechnik-Problem)
		{
			did.tvpMin.tag.tag = 1; did.tvpMin.tag.monat = 1; did.tvpMin.tag.jahr = 0;
			xicbus ( XEEPADR,	(char *)( &did.tvpMin), TVPMINDIAG_ADR, sizeof( did.tvpMin ), BICWR );	
		}							
	// ***AnFre 03.09.2009 KWZ-Volstrom-Bereiche plus Gesamtzeit in h
		xicbus ( XEEPADR,	(char *)( &kwd ), FLOWDIAG_KWZ_ADR, sizeof(kwd), BICRD );	 // 5*2 Byte !!!!!!!!!!!!!!
		xicbus ( XEEPADR,	(char *)( &did.leistgBereich_h), LEISTDIAG_ADR, 8, BICRD );// 4*2 Byte 								

// ***AnFre 06.06.2012 Gemittelte Rücklauftemp. HK1
		bicbus ( EEPADR,	(char *)( &TH2Mittel ), TH2_MON_ADR, 24, BICRD );					// 12 Monate 
		bicbus ( EEPADR,	(char *)( &TH2MittelVJ ), TH2_VJMON_ADR, 24, BICRD ); 
		bicbus ( EEPADR,	(char *)( &TH2MittelSumme ), TH2_SUMME_ADR, sizeof(TH2MittelSumme), BICRD ); 
		bicbus ( EEPADR,	(char *)( &TH2MittelZaehler ), TH2_ZAEHLER_ADR, sizeof(TH2MittelZaehler), BICRD ); 
		TH2MittelMonAlt = Mon;
		TH2MittelJahrAlt = Jahr;
			
		neustart = 0;
		return;		
	}

// ***AnFre 03.09.2009 KWZ-Volumenstrom-Bereiche checken !!! alle 10 Sekunden !!!
// kws.ZeitLoesch == 1 löscht die Zeit-Bereiche
	if ( ZeitLoesch == 1 )		// KWZ-Volstrom-Diagnose löschen
	{
		kwd.flowBereich_h[0] = 0;
		flowBereichKWZ_sek[0]	= 0;
		kwd.flowBereich_h[1] = 0;
		flowBereichKWZ_sek[1]	= 0;
		kwd.flowBereich_h[2] = 0;
		flowBereichKWZ_sek[2]	= 0;
		kwd.flowBereich_h[3] = 0;
		flowBereichKWZ_sek[3]	= 0;
		kwd.gesZeit_h = 0;
		gesZeit_sek	= 0;
		ZeitLoesch = 0; 
		xicbus ( XEEPADR,	(char *)( &kwd), FLOWDIAG_KWZ_ADR, sizeof(kwd) , BICWR );								
	}

	for ( j = 0; j < 4; j++ )
	{
		if ( (volstrCtr.flow ) < kws.FlowBereich[j] )
		{
			if ( ++flowBereichKWZ_sek[j]	>= 360 )
			{
				flowBereichKWZ_sek[j] = 0;
				++kwd.flowBereich_h[j];
				xicbus ( XEEPADR,	(char *)( &kwd.flowBereich_h[j]), FLOWDIAG_KWZ_ADR + 2*j, 2, BICWR );								
			}
			break;		
		}
	}

	if ( ++gesZeit_sek	>= 360 )
		{
			gesZeit_sek = 0;
			++kwd.gesZeit_h;
			xicbus ( XEEPADR,	(char *)( &kwd.gesZeit_h), FLOWDIAG_KWZ_ADR + 8, 2, BICWR );	// Achtung feste Bytezahlen							
		}

// ----------- Mittlere monatliche RL-Temp. HK1 ( TH2	) und Netz TN2 -------------------------------------------
// alle Minuten
	if ( ++m > 5 )
	{
		m = 0;
		// Daten TH2 sichern im Eprom
		bicbus ( EEPADR,	(char *)( &TH2Mittel ), TH2_MON_ADR, 24, BICWR );	 
		bicbus ( EEPADR,	(char *)( &TH2MittelVJ ), TH2_VJMON_ADR, 24, BICWR ); 
		bicbus ( EEPADR,	(char *)( &TH2MittelSumme ), TH2_SUMME_ADR, sizeof(TH2MittelSumme), BICWR ); 
		bicbus ( EEPADR,	(char *)( &TH2MittelZaehler ), TH2_ZAEHLER_ADR, sizeof(TH2MittelZaehler), BICWR ); 

		if ( TH2MittelMonAlt == Mon )
		{
//			if ( hkdSoL[HK1].solLadung > 0 || hkd[HK1].extAnfAktiv > 0 )
//			{
			if ( TRS[HK1]->stat == 0 )
			{
				TH2MittelSumme += (ULONG)TRS[HK1]->messw;
				TH2MittelZaehler ++;
				TH2Mittel[Mon-1] = (int)(TH2MittelSumme / TH2MittelZaehler);
			}
//			}
		}
		else
		{
			TH2MittelMonAlt = Mon;
			TH2MittelSumme = 0;
			TH2MittelZaehler = 0;
		
			if ( TH2MittelJahrAlt != Jahr )
			{
				TH2MittelJahrAlt = Jahr;
				for ( k = 0; k < 12; k++ )
				{
					TH2MittelVJ[k] = TH2Mittel[k];
					TH2Mittel[k] = 0;
				}
			}
		}
	} // Ende Mittlere RL-Temp. HK1 ---------------------------------------------
	
	
	if ( ++part > 5 )
		part = 0;
	
	// Testen, ob Diagnose-Beginn und -Ende plausible Datums-Angaben sind
	// und der aktuelle Tag im Bereich
	// begin.jahr = 0 wird zum Löschen benutzt		
	if ( 		dis.begin.jahr > 0 && dis.begin.jahr < 99 && dis.end.jahr > 0 && dis.end.jahr < 99	
			&&  dis.begin.tag > 0 && dis.begin.tag <= 31 && dis.end.tag > 0 && dis.end.tag <= 31 
			&&	dis.begin.monat > 0 && dis.begin.monat <= 12 && dis.end.monat > 0 && dis.end.monat <= 12 
			&& ( ( (ULONG)dis.begin.jahr * 10000 + dis.begin.monat * 100 + dis.begin.tag ) <=
					 ( (ULONG)Jahr * 10000 + Mon * 100 + Tag ) )
			&& ( ( (ULONG)dis.end.jahr * 10000 + dis.end.monat * 100 + dis.end.tag ) >=
					 ( (ULONG)Jahr * 10000 + Mon * 100 + Tag ) ) )					 
	{
		geloescht = 0;
		switch ( part )
		{
			case 0 :
			// Maximaler Volumenstrom
				if ( (wmengCtr[1].flow + wmengCtr[3].flow) > did.flow_max )
				{
					did.flow_max = (wmengCtr[1].flow + wmengCtr[3].flow);		
					xicbus ( XEEPADR,	(char *)( &did.flow_max ), FLOWMAXDIAG_ADR, sizeof(did.flow_max), BICWR );
				}		
				
				// Maximale Leistung
				if ( (wmengCtr[1].wmLeistg + wmengCtr[3].wmLeistg) > did.wmLeistg_max)
				{
					did.wmLeistg_max = (wmengCtr[1].wmLeistg + wmengCtr[3].wmLeistg);		
					xicbus ( XEEPADR,	(char *)( &did.wmLeistg_max ), LEISTMAXDIAG_ADR, sizeof(did.wmLeistg_max), BICWR );
				}
				return;

			case 1 :		
			// Leistungs-Bereiche checken
				for ( i = 0; i < 4; i++ )
				{
					if ( (wmengCtr[1].wmLeistg + wmengCtr[3].wmLeistg) < dis.leistgBereich[i] )
					{
						if ( ++leistgBereich_min[i]	>= 60 )
						{
							leistgBereich_min[i] = 0;
							++did.leistgBereich_h[i];
							xicbus ( XEEPADR,	(char *)( &did.leistgBereich_h[i]), LEISTDIAG_ADR + 2*i, 2, BICWR );								
						}
						break;		
					}
				}
	
			// Volumenstrom-Bereiche checken
				for ( i = 0; i < 4; i++ )
				{
					if ( (wmengCtr[1].flow + wmengCtr[3].flow) < dis.flowBereich[i] )
					{
						if ( ++flowBereich_min[i]	>= 60 )
						{
							flowBereich_min[i] = 0;
							++did.flowBereich_h[i];
							xicbus ( XEEPADR,	(char *)( &did.flowBereich_h[i]), FLOWDIAG_ADR + 2*i, 2, BICWR );								
						}
						break;		
					}
				}
	
				return;	

			case 2:		
			// Speicher-Ladung
				if ( wwlad ) 
				{
					if ( ++wwlad_min > did.wwlad_time )
					{
						did.wwlad_time = wwlad_min;				// max. Dauer einer Speicherladung
						xicbus ( XEEPADR,	(char *)( &wwlad_min), LADZEITDIAG_ADR, 2, BICWR );
					}
				}	
				else
					wwlad_min = 0;					
				
				if ( wwlad != wwd[WW1].wwlad )			// Zustand hat gewechselt
				{
					wwlad = wwd[WW1].wwlad;
					if ( wwlad )											// Ladung hat gerade begonnen, Anzahl inkrementiern
					{
						++did.wwlad_anz;
						xicbus ( XEEPADR,	(char *)( &did.wwlad_anz), LADANZDIAG_ADR, 2, BICWR );
					}
				}	
				return;

			case 3 :
			// WW-Vorrang
				if ( wwvor )
				{
					if ( ++wwvor_min > did.wwvor_time )
					{
						did.wwvor_time = wwvor_min;				// max. Dauer einer Speicherladung
						xicbus ( XEEPADR,	(char *)( &wwvor_min), WWVORZEITDIAG_ADR, 2, BICWR );
					}
				}	
				else
					wwvor_min = 0;					
				
				if ( wwvor != wwd[WW1].wwvor )			// Zustand hat gewechselt
				{
					wwvor = wwd[WW1].wwvor;
					if ( wwvor )											// Ladung hat gerade begonnen, Anzahl inkrementiern
					{
						++did.wwvor_anz;
						xicbus ( XEEPADR,	(char *)( &did.wwvor_anz), WWVORANZDIAG_ADR, 2, BICWR );
					}
				}	
				return;	

//#####ulsch: 27.08.04  case 4 und 5 geändert: Messwert-Status muss auch ok sein, wenn noch nichts gespeichert ( .jahr = 0 )
			case 4 :
			// max. Kessel-Vorlauf	
				if ( TVKE[KE1]->stat == 0 && ( TVKE[KE1]->messw > did.tvpMax.temp || did.tvpMax.tag.jahr == 0 ) )	
				{																													// auch wenn Speicher noch geloescht !
					did.tvpMax.temp = TVKE[KE1]->messw;
					did.tvpMax.tag.tag = Tag;	did.tvpMax.tag.monat = Mon;	did.tvpMax.tag.jahr = Jahr;	
					did.tvpMax.ta.stat = ta1m.stat; did.tvpMax.ta.messw = ta1m.messw;	
					xicbus ( XEEPADR,	(char *)( &did.tvpMax), TVPMAXDIAG_ADR, sizeof( did.tvpMax ), BICWR );							
				}
				return;
				
			case 5 :
			// min. Kessel-Vorlauf
				if ( TVKE[KE1]->stat == 0 && ( TVKE[KE1]->messw < did.tvpMin.temp || did.tvpMin.tag.jahr == 0 ) )
				{																													// auch wenn Speicher noch geloescht !
					did.tvpMin.temp = TVKE[KE1]->messw;
					did.tvpMin.tag.tag = Tag;	did.tvpMin.tag.monat = Mon;	did.tvpMin.tag.jahr = Jahr;	
					did.tvpMin.ta.stat = ta1m.stat; did.tvpMin.ta.messw = ta1m.messw;
					xicbus ( XEEPADR,	(char *)( &did.tvpMin), TVPMINDIAG_ADR, sizeof( did.tvpMin ), BICWR );									
				}
				return;

		}				
	}
	
	else if ( geloescht == 0 && dis.begin.jahr == 0 )
	{																			// alles loeschen
		for ( i = 0, n = sizeof( did ); i < n; i++ )
			*( (char *)(&did) + i ) = 0;
		did.tvpMax.tag.tag = 1; did.tvpMax.tag.monat = 1; did.tvpMax.tag.jahr = 0;
		did.tvpMin.tag.tag = 1; did.tvpMin.tag.monat = 1; did.tvpMin.tag.jahr = 0;
			
		xicbus ( XEEPADR,	(char *)( &did ), DIAG_ADR, sizeof(did), BICWR );	
		wwlad = 0; wwvor = 0;								// damit eine nach Loeschen bereits aktive Ladung auch gezaehlt wird

		for ( i= 0; i<24; i++ )
		{
			TH2Mittel[i] 		= 0;
			TH2MittelVJ[i]	= 0;
		}
		TH2MittelSumme		= 0;
		TH2MittelZaehler	= 0;
		TH2MittelMonAlt = Mon;
		
		bicbus ( EEPADR,	(char *)( &TH2Mittel ), TH2_MON_ADR, 24, BICWR );	 
		bicbus ( EEPADR,	(char *)( &TH2MittelVJ ), TH2_VJMON_ADR, 24, BICWR ); 
		bicbus ( EEPADR,	(char *)( &TH2MittelSumme ), TH2_SUMME_ADR, sizeof(TH2MittelSumme), BICWR ); 
		bicbus ( EEPADR,	(char *)( &TH2MittelZaehler ), TH2_ZAEHLER_ADR, sizeof(TH2MittelZaehler), BICWR ); 

		geloescht = 1;
	}			
#endif
}