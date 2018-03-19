/*	Task:					RegelWw			*/
/*	Warmwasserregelung						*/

#include <stdlib.h>
#include "struct.h"
#include "ustruct.h"
#include "defins.h"
#include "sramext.h"
#include "uramext.h"

#include <float.h>
#include <math.h>


/*-------------------------------- Task RegelWw -----------------------------------*/
// Takt: 1 sek
void RegelWw(void)
{
	float fl_ei = 0;
	float fl_dy_rel = 0;	
	char regel = FALSE;

	// Abfrage Handbetrieb
	if(wws[WW1].Haut == TRUE)			
	{	RWWZU[WW1]->wert = wwd[WW1].vzu;	// Handwert[s] für Zufahren ausgeben
		if(wwd[WW1].vzu > 0)							// Ausgabe aktiv ?
		{	 wwd[WW1].vzu -= 1;							// Zeit decrementieren
			 wwd[WW1].vauf = 0;							// Vorrang vor Auffahren 
		}
		else															// Ausgabe für Zufahren nicht aktiv
		{	RWWAUF[WW1]->wert = wwd[WW1].vauf;// Handwert[s] für Auffahren ausgeben
			if(wwd[WW1].vauf > 0)						// Ausgabe aktiv ?
				 wwd[WW1].vauf -= 1;					// Zeit decrementieren
		}
		RVENTWW[WW1]->awert = wws[WW1].Vstell;	// Analogventil 0-100,0% 
		AA_UNI[U4]->awert = wws[WW1].Vstell;		// Ausgabe an Fremdregler z.B. Wärmepumpe

	// ***AnFre
		wwd[WW1].fl_y_rel = (float)wws[WW1].Vstell/10;	// Ventil bei AUTO ab dieser Stellung
	// AnFre***
		return;		
	}
	else																// Automatikbetrieb
	{	wws[WW1].Haut = 0;								// evtl. Fehleingaben löschen
		wwd[WW1].vzu	= 0;								// Handwerte löschen
		wwd[WW1].vauf	= 0;
	}

/* ---------- ***AnFre	26.03.2008 WW-Bedarf melden für Kessel -------------------------- */
// Kessel AUS wenn RV-Stellung länger als 5 min unter 0,5%-Stellung und TW2 > akt. Sollwert -10 K
	if ( RVENTWW[WW1]->awert <= 5 )
	{
		wwd[WW1].zRVauf = 0;
		if ( wwd[WW1].zRVzu < wws[WW1].RVzu * 60 )
			wwd[WW1].zRVzu += 1;
		else
			if ( TW2_[0]->messw > (prd[PR1].aktTwwsol - 100) )
				wwd[WW1].twwBed = 0;	//Ventil längere Zeit ZU, kein Kesselbetrieb
	}
	else
	{ // Kessel EIN wenn RV-Stellung länger als 1 min über 0,5%-Stellung und TW2 < akt. Sollwert
		wwd[WW1].zRVzu = 0;
		if ( wwd[WW1].zRVauf < wws[WW1].RVauf * 60 )
			wwd[WW1].zRVauf += 1;
		else
			if ( TW2_[0]->messw < (prd[PR1].aktTwwsol) )
				wwd[WW1].twwBed = 1;	//Ventil längere Zeit AUF, Kesselbetrieb EIN
	}

	
//--- Regler-Tastzeit ----------------------------------------------------------
	if ( ( wwd[WW1].zts += 10 ) < wws[WW1].Ts )
		 return;													// Tastzeit noch nicht erreicht
	wwd[WW1].zts = 0;
	
	// ------ Gültigen RegelSollwert berechnen ----------------------------------

		wwd[WW1].twwsb = prd[PR1].aktTwwsol; //WW-Temp.-Profil

//	Wenn Solarbetrieb um 2,0 K absenken
		if ( (wwd[WW1].solWwLad == 1 ||wwd[WW1].solWwLdg == 1 || wwd[WW1].solWwVW == 1 || wwd[WW1].solWwZir == 1) )
		{
			wwd[WW1].twwsb -= wws[WW1].DTRegSol;
		}


		if ( wwd[WW1].konvLegio && ( wws[WW1].Twwleg > wwd[WW1].twwsb ) )	// ***AnFre
				wwd[WW1].twwsb = wws[WW1].Twwleg;				// Legionellentemp. als Sollwert

		if ( wwd[WW1].wwvor && ( prd[PR1].aktTwwVor > wwd[WW1].twwsb ) )	// ***AnFre
				wwd[WW1].twwsb = prd[PR1].aktTwwVor;				// Regel-Vorrang-temp. als Sollwert

		if ( wwd[WW1].wwlad && ( prd[PR1].aktTwwlad > wwd[WW1].twwsb ) )	// ***AnFre
				wwd[WW1].twwsb = prd[PR1].aktTwwlad;				// Regel-Ladetemp. als Sollwert

// bei Wartung erforderlich  ( NotBetrieb )
		if ( NotBetr == 1 )
			wwd[WW1].twwsb = sos[SO1].NotTemp;

		if ( wwd[WW1].regstart == 0 )									// ohne Dämpfung nach Reset
		{
			wwd[WW1].fl_tsol	= (float)wwd[WW1].twwsb / 10;
			wwd[WW1].regstart = 1;		
		}
		else
		{	// Dämpfung des berechneten Sollwertes: twwsb --> gedämpfte tsol		
			wwd[WW1].fl_tsol = g_filter(wwd[WW1].fl_tsol, wwd[WW1].twwsb, wws[WW1].Ts, wws[WW1].Fzk);
		}
		wwd[WW1].tsol 	  = (int)( wwd[WW1].fl_tsol * 10 );	// für Anzeige
		regel = TRUE;

	//---------------------------------------------------------------------------------------------
	
	if(regel == TRUE)
	{	
		//	----------------------------------------------------------------------
		//	Reglertyp: P- / PID-Regler
		//	----------------------------------------------------------------------
		// Test Regelfühler
		if(TWWC[WW1]->stat == 0)	// Status: 0...Ok, 41H...Überlauf,  21H...Unterlauf
		{	
			// Regelabweichung Soll - Ist
			fl_ei	= wwd[WW1].fl_tsol - (float)TWWC[WW1]->messw / 10;
			
			// -------------- PID-Regelalgorithmus ---------------------------------
			// Berechnung der relativen Stellgrößen
			fl_dy_rel = Dy_rel ( wws[WW1].Kp, wws[WW1].Kd, wws[WW1].Ts, wws[WW1].Tn, 
															fl_ei, wwd[WW1].fl_ei1, wwd[WW1].fl_ei2 );
			
			wwd[WW1].fl_y_rel += fl_dy_rel;

			wwd[WW1].dy_rel	= (int)(fl_dy_rel * 1000);					// für debug
			
			//---------------------------------------------------------------------
			// Regelabweichungen merken
			wwd[WW1].fl_ei2 = wwd[WW1].fl_ei1;
			wwd[WW1].fl_ei1 = fl_ei;																		
			
			// Berechnung und Ausgabe der absoluten Stellgrößen
			// --------------------------------------------------------------------
			// Ausgabe an 3-Punkt Ventil
			if( wws[WW1].Vst > 0 )
			{	
				wwd[WW1].stellzeit = (int)( fl_dy_rel * (float)wws[WW1].Hub * 60 / (float)wws[WW1].Vst ); // [0.01 s]
				wwd[WW1].stellsum += wwd[WW1].stellzeit;
				if(abs(wwd[WW1].stellsum) >= 100)									// ab 1 Sekunde ausgeben
				{
					wwd[WW1].fahren		= wwd[WW1].stellsum / 100;		// nur ganze Sekunden fahren
					wwd[WW1].stellsum	= wwd[WW1].stellsum % 100; 		// Rest merken
					if(wwd[WW1].fahren > 0)		
						RWWAUF[WW1]->wert = (char)wwd[WW1].fahren;
					else
						RWWZU[WW1]->wert  = (char)abs(wwd[WW1].fahren);	
				}
			}	

			// Ausgabe an 0-10V Ventil
			if(wwd[WW1].fl_y_rel  > 100)							// Begrenzung max 100 %
				 wwd[WW1].fl_y_rel  = 100;
			if(wwd[WW1].fl_y_rel  < 0)								// Begrenzung min 0%
				 wwd[WW1].fl_y_rel  = 0;
				
			wwd[WW1].y_rel = (int)(wwd[WW1].fl_y_rel * 10);	// Zur Anzeige und Weiterverarbeitung
			RVENTWW[WW1]->awert = wwd[WW1].y_rel;									// Ausgabe an Stellventil
			AA_UNI[U4]->awert = wwd[WW1].y_rel;		// Ausgabe an Fremdregler z.B. Wärmepumpe
			
			// Parameterumwandlung float to int
			wwd[WW1].ei = (int)(fl_ei * 10);					// [0,1%] zur Anzeige
		}
	}
	else	// 	if(wwd[WW1].wwlad > 0)
	{	// nicht im Ladebetrieb
		wwd[WW1].fl_ei1	  = 0;
		wwd[WW1].ei				= 0;
		RWWAUF[WW1]->wert	= 0;
		RWWZU[WW1]->wert	= 255;				// Regelventil ständig zufahren
		wwd[WW1].y_rel		= 0;
		RVENTWW[WW1]->awert	= 0;					// Ausgabe an Stellventil
		AA_UNI[U4]->awert = 0;		// Ausgabe an Fremdregler z.B. Wärmepumpe
		wwd[WW1].fl_ei2		= 0;
		wwd[WW1].fl_y_rel = 0;
		wwd[WW1].twwsb		= 0;
		wwd[WW1].regstart = 0;					//RESTART, keine Dämpfung
	}	

/* ----------- ***AnFre -------------------------------------------------------- */
// Wenn TVKES < Regel-Sollwert (wwd[WW1].tsol-8,0K)
//  und TVKES < Zirkulation-2,0K: 	RV auf minimale Stellung

	if ( TVKE[KE1]->stat == 0 )
	{
		if ( wwd[WW1].kesMinEin == TRUE )
		{
			if ( RVENTWW[WW1]->awert > wws[WW1].VentGrenz )
			{
				wwd[WW1].fl_ei1	  = 0;
				wwd[WW1].fl_ei2	  = 0;
				wwd[WW1].ei				= 0;
				wwd[WW1].fl_y_rel = (float)wws[WW1].VentGrenz / 10;		// Ventil-Begrenzung auf 50,0 %
				RVENTWW[WW1]->awert = wws[WW1].VentGrenz;							// Ausgabe an Stellventil
				AA_UNI[U4]->awert = wws[WW1].VentGrenz;		// Ausgabe an Fremdregler z.B. Wärmepumpe
			}
			if ( TVKE[KE1]->messw >= wwd[WW1].tsol )
			{
				wwd[WW1].kesMinEin = 0;
			}
		}
		else
		{
			if ( wwd[WW1].twwBed == TRUE )
			{
				if ( TVKE[KE1]->messw < wwd[WW1].tsol - 80 )
				{
					if ( TWWZ[WW1]->stat != 0 )
						wwd[WW1].kesMinEin = 1;
					else if ( TVKE[KE1]->messw < TWWZ[WW1]->messw + 10 )					
						wwd[WW1].kesMinEin = 1;
				}
			}
		}
	}
	else
	{
		wwd[WW1].kesMinEin = 0;
	}				
// Wenn kein Ladebetrieb,keine Konv.Legio und kein WW-Vorrang:
// 		WW-Regelventil ZU, wenn:  TW2 > aktuell-Twwsol + RegHyst
// 		WW-Regelventil wieder AUF, wenn:  TW2 < aktuell-Twwsol - RegHyst

	if ( wwd[WW1].regHystEin > 0 )
	{
		RVENTWW[WW1]->awert = 0;															// Ausgabe an Stellventil auf Null
		AA_UNI[U4]->awert = 0;		// Ausgabe an Fremdregler z.B. Wärmepumpe
		wwd[WW1].fl_y_rel = (float)wws[WW1].VentStell / 10;		//Bei Wiederanlauf Ventil beginnt bei 20,0 %
		if ( TW2_[0]->messw < wwd[WW1].twwsb ) 
		{
			wwd[WW1].regHystEin = 0;
		}
	}
	else
	{
		if( wwd[WW1].wwlad == 0 && wwd[WW1].wwvor == 0 && wwd[WW1].konvLegio == 0 )
		{
			if ( TW2_[0]->messw > (wwd[WW1].twwsb + wws[WW1].RegHyst ) ) 
			{
				wwd[WW1].regHystEin = 1;
			}		
		}
	}

// -------- ***AnFre 09.07.2009 STW-Abschaltung -----------
	if ( STWWW[WW1]->bwert == TRUE )
	{
		RVENTWW[WW1]->awert = 0;					// Ausgabe 0 Volt an Stellventil
		AA_UNI[U4]->awert = 0;		// Ausgabe an Fremdregler z.B. Wärmepumpe
	}
}
	