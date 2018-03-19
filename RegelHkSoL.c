/*		Task:	Solar-RegelHk			*/

#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "ustruct.h"
#include "defins.h"
#include "sramext.h"
#include "uramext.h"
#include "uconstext.h"
#include "unoinitext.h"

/*---------------------- Task RegelHkSoL -----------------------------------*/
// !!!! gilt nur für EINEN Solar-Regelkreis !!!!!!!!!!!
// Zeitbasis für einen Regelkreis : 1,0 Sekunden
// Zeitbasis für den Taskaufruf:		1,0 Sekunden / HKMAX

void RegelHkSoL(void)
{
	
	float fl_ei = 0;
	float fl_dy_rel = 0;	
	float fl_Y_rel_beg = 0;
	float fl_Y_rel_min = 0;
//	char  hkAbschalten = 0;
//	char	tvret;
	
	// Lokale Pointer auf HkSoL-Strukturen
	HkSoLDynam    *pHkd;	
	HkSoLStandard *pHks;

	// Projektabfrage, ob Regelkreis aktiv
	if(Projekte[proj_typ].hkSoLcode[HK1] == 0)
		return;													// Heizkreis nicht aktiv
	
	// Strukturpointer zuweisen
	pHkd = &hkdSoL[HK1];	
	pHks = &hksSoL[HK1];

/* ---- ***AnFre	Heiz-Bedarf melden für Kessel -------------------------- */
// wenn RV-Stellung für KONVENTIONELLEN HK1 länger als 5 min unter Minimal-Stellung
	if ( hkd[HK1].y_rel <= hks[HK1].Y_rel_min + 10 )
	{
		pHkd->zRVauf = 0;
		if ( pHkd->zRVzu < pHks->RVzu * 60 )
			pHkd->zRVzu += 1;
		else
			pHkd->heizBed = 0;	//Ventil längere Zeit ZU, kein Kesselbetrieb
	}
	else
	{
		pHkd->zRVzu = 0;
		if ( pHkd->zRVauf < pHks->RVauf * 60 )
			pHkd->zRVauf += 1;
		else
			pHkd->heizBed = 1;	//Ventil längere Zeit AUF, Kesselbetrieb EIN
	}

//-------------- Solare Heizunterstützung ein/aus-schalten------------------------------
// Unabhängig von der WW-SolarSteuerung, nur nach Möglichkeit (TS3>TRS1)
	if(hkd[HK1].puEinAnz > 0 && sod[SO1].solPuEinAnz > 0)		// Heizkreis-und Solar-Pumpe EIN ?
	{	
		if ( TS3_[SO1]->messw > (TRS[HK1]->messw + pHks->DTSoHk) )
		{	
			if ( pHkd->hkSolJa == 0 )
			{	
				if(pHks->Haut == FALSE)			// Abfrage Handbetrieb
				{	pHkd->y_rel	=  (int) (pHks->RVSoMax / 10);
					pHkd->fl_y_rel  = (float) (pHkd->y_rel);
				}
			}
			pHkd->hkSolJa = 1;
			pHkd->zHkSolJa = 300; // 5 min vorbelegt
		}
		else
		{	
			if ( TS3_[SO1]->messw < TRS[HK1]->messw + 10 )
			{
				if ( pHkd->zHkSolJa > 0 )	// 300 Sekunden warten
					pHkd->zHkSolJa -= 1;
				else
					pHkd->hkSolJa = 0;
			}
		}
	}
	else
	{
		pHkd->hkSolJa = 0;
		pHkd->zHkSolJa = 0; // Abschalt-Cnt löschen

	}

	//--------------------------------------------------------------------------
	// Abfrage Handbetrieb
	//--------------------------------------------------------------------------
	if(pHks->Haut == TRUE)			
	{	
		RVENTSO[HK1]->awert = pHks->Vstell;								// Analogventil 0-100,0% 
		pHkd->fl_y_rel = (float)pHks->Vstell / 10;
		pHkd->tvsb =					0;
		pHkd->tsol =					0;
		pHkd->fl_tsol =				0;
		pHkd->ei =						0;
		pHkd->fl_ei1 =				0;
		pHkd->y_rel =					0;
		return;
	}                                 					
	else																				// Automatikbetrieb
	{	pHks->Haut = 0;														// evtl. Fehleingaben löschen
		pHkd->vzu	= 0;														// Handwerte löschen
		pHkd->vauf	= 0;
	}

//----------------------------------------------------------------------
	
	// Regler-Tastzeit
	if(++pHkd->zts < pHks->Ts/10)
		 return;																	// Tastzeit noch nicht erreicht
	pHkd->zts = 0;	 

	// Solare Heiz-Unterstutzung Aus ? 
	if(pHkd->hkSolJa == 0)
	{
		pHkd->tvsb =					0;
		pHkd->tsol =					0;
		pHkd->fl_tsol =				0;
		pHkd->ei =						0;
		pHkd->fl_ei1 =				0;
		pHkd->y_rel =					0;
		pHkd->fl_y_rel = 			0;
		RVENTSO[HK1]->awert =	0;
		return;
	}

//---------------- Sollwert aus konv. HK1 -------------------------------

	pHkd->tvsb = hkd[HK1].tvsb;
	pHkd->tsol = pHkd->tvsb;
	pHkd->fl_tsol = (float)pHkd->tsol / 10;

//	----------------------------------------------------------------------
//	Reglertyp: P- / PID-Regler
//	----------------------------------------------------------------------
	// Test Vorlauffühler vom konv. HK1
	if(TVS[HK1]->stat == 0)	// Status: 0...Ok, 41H...Überlauf,  21H...Unterlauf
	{	
		// Regelabweichung Soll - Ist
		fl_ei	= pHkd->fl_tsol - (float)TVS[HK1]->messw / 10;
		
		// -------------- PID-Regelalgorithmus ---------------------------------
		// Berechnung der relativen Stellgrößen
		fl_dy_rel = Dy_rel ( pHks->Kp, pHks->Kd, pHks->Ts, pHks->Tn, 
														fl_ei, pHkd->fl_ei1, pHkd->fl_ei2 );
		
		pHkd->fl_y_rel += fl_dy_rel;
		
		pHkd->dy_rel	= (int)(fl_dy_rel * 1000);					// für debug

		//---------------------------------------------------------------------
		// Regelabweichungen merken
		pHkd->fl_ei2 = pHkd->fl_ei1;
		pHkd->fl_ei1 = fl_ei;						
		// Parameterumwandlung float to int
		pHkd->ei = (int)(fl_ei * 10);											// [0,1%] zur Anzeige
		
		//--------------------------------------------------------------------------
		// Abfrage Handbetrieb
		//--------------------------------------------------------------------------
		if(pHks->Haut == TRUE)			
			pHkd->fl_y_rel = (float)pHks->Vstell / 10;		// PID-Wert durch Handwert überschreiben
		else
		{
			// Berechnung und Ausgabe der absoluten Stellgrößen
			// --------------------------------------------------------------------
			// Ausgabe an 3-Punkt Ventil
			if ( pHks->Vst > 0 )
			{	
				pHkd->stellzeit = (int)( fl_dy_rel * (float)pHks->Hub * 60 / (float)pHks->Vst ); // [0.01 s]			
				pHkd->stellsum += pHkd->stellzeit;			
				if(abs(pHkd->stellsum) >= 100)								// ab 1 Sekunde ausgeben
				{
					pHkd->fahren		= pHkd->stellsum / 100;			// nur ganze Sekunden fahren
					pHkd->stellsum	= pHkd->stellsum % 100; 		// Rest merken
				}
			}	
			
			// Ausgabe an 0-10V Ventil
			fl_Y_rel_beg = (float)pHks->Y_rel_beg / 10;			// Beginn der Ventilöffnung
			fl_Y_rel_min = (float)pHks->Y_rel_min / 10;			// Minimalbegrenzung
			
			if(pHkd->fl_y_rel  > 100)												// Begrenzung max 100 %
				 pHkd->fl_y_rel  = 100;
			
			if(fl_dy_rel > 1)																// nur bei positiver Änderung
			{	if(pHkd->fl_y_rel < fl_Y_rel_beg)							// und Wert kleiner als Ventilöffnungsbeginn,
					 pHkd->fl_y_rel = fl_Y_rel_beg;							// dann Setzen auf Ventilöffnungsbeginn
			}
			
			if(pHkd->fl_y_rel  < fl_Y_rel_min)								
				 pHkd->fl_y_rel  = fl_Y_rel_min;							// Minimalbegrenzung

	// Solar-Ventil Begrenzung Max 
			if( (pHkd->fl_y_rel  > (hksSoL[HK1].RVSoMax / 10))		// Begrenzung max 
				|| (hkd[HK1].y_rel > hks[HK1].Y_rel_min + 10) )	// Regel-Beginn erst wenn RVENT[HK1] ZU	***AnFre 23.04.2008
			{
				pHkd->fl_y_rel  = hksSoL[HK1].RVSoMax / 10;
 			}
				
			pHkd->y_rel = (int)(pHkd->fl_y_rel * 10);				// Zur Anzeige und Weiterverarbeitung
			RVENTSO[HK1]->awert = pHkd->y_rel;									// Ausgabe an Stellventil
		}

// -------- ***AnFre 09.07.2009 STW-Abschaltung -----------
		if ( STWHK[HK1]->bwert == TRUE )
			RVENTSO[HK1]->awert = 0;					// Ausgabe 0 Volt an Stellventil

	}	
		
}
/*---------------------- Ende Task RegelHk -----------------------------------*/

