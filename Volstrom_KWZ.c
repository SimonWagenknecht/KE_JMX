
/***** Berechnung von Volumenstrom aus dem Volumenimpuls eines Zaehleingangs *****/
/***** speziell fuer SEZ40-200 																				 *****/

/* zur Berechnung des Volumenstromes sind zu aendern :
	UserRam.c		uramext.h
	ustruct.h
	UserReply.c
	standdef.h	standard.h
	main.c
	parli.h			zin09.h			
	usertask.h	projdef.h			UserConst.c
*/

#include "struct.h"
#include "ustruct.h"
#include "defins.h"
#include "sramext.h"
#include "uramext.h"
#include "standdef.h"
#include "uconstext.h"


/* Berechnet wird die mit einem der Zaehleingaenge des R36 erfassten Volumen */
/* Dabei wird hier auf eine variable Eingangsdefinition noch verzichtet, sondern lediglich */
/* von ZIN12 (war ZIN7) berechnet. Die Task laeuft alle 100 ms, die Vol.Stromberechnung einmal pro Sekunde.	*/

#define MAXDMPF 10								// Daempfungsfaktor fuer Volumenstrom max. 10
#define MAXZEIT 36100							// 36100  100ms (ca.60min) Zeit des zuletzt erfassten Impulses bis Volumenstrom = 0 wenn kein Impuls

void Volstr ( void )
{
	static char taskCtr = 0;
	zaehlsp *pZaehlsp;

	ULONG impWert;									// in Liter/Impuls
	static ULONG long lastWert;			// letzter Zaehlerstand;
	static ULONG volstr;						// berechneter Vol-Strom
//im RAM.c und zin07.h	static ULONG timeDiff = 0;			// Zeit-Zaehler 100ms
//im RAM.c und zin07.h	static ULONG lasttimeDiff = 0;	// Zeit-Zaehler letzter Impuls 100ms
	static char start = 1;

	static char impIst = 1;					// Impuls ist gewesen
	static char	wotagAlt = 0;				// Impuls-Test pro Tag

	static char neustart = 1;
	


// Volumenimpuls von ZIN12 wird hier fuer Volumenzaehler Warmwasser benutzt		
//	pZaehlsp = ZE[4];										// ***AnFre Impulseingang IN7
	pZaehlsp = X1ZE[1];										// ***AnFre Impulseingang DE2 am R37_1
	if ( pZaehlsp->zdim.dim_idx != 6 )	// nur m^3 zugelassen
		pZaehlsp->zdim.dim_idx = 6; 
	if ( pZaehlsp->zdim.komma > 3 )			// nur 3 Kommastellen zugelassen
		pZaehlsp->zdim.komma = 3;
	if ( pZaehlsp->zdim.exponent > 3 )	// nur Impuls-Wertigkeit 1..1000 l/Imp. zugelassen 
		pZaehlsp->zdim.exponent = 3;

// Neustart : gespeicherte Werte aus nichtfluechtigem RAM	
	if ( neustart )
	{
		lastWert = pZaehlsp->zwert;
		timeDiff = 0;
		neustart = 0;
		return;		
	}


// ----------- Maxima Volstr loeschen	-------------------------
	if ( volstrCtr.resVMax == 1 )
	{
		volstrCtr.flow_max = 0;
		volstrCtr.VmaxDatum.jahr	= 0;
		volstrCtr.VmaxDatum.monat = 1;
		volstrCtr.VmaxDatum.tag		= 1;
		volstrCtr.VmaxZeit.std		= 0;
		volstrCtr.VmaxZeit.min		= 0;
		volstrCtr.VmaxTW1.messw		= 0;
		volstrCtr.VmaxTW1.stat		= 0;
		volstrCtr.VmaxTW2.messw		= 0;
		volstrCtr.VmaxTW2.stat		= 0;
		bicbus ( EEPADR,	(char *)( &volstrCtr ), KWZVOLMAX_ADR, sizeof(volstrCtr), BICWR );
		volstrCtr.resVMax = 0;	
		return;
	}
	volstrCtr.resVMax = 0;						// Fehleingaben loeschen

// Impuls-Test:	Volumengeber defekt, wenn innerhalb 24 h kein Kontakt war	 14.05.2009
	if ( wotagAlt == 0 )		
		wotagAlt = Wotag;
	if ( wotagAlt != Wotag )		
	{
		wotagAlt = Wotag;
		if ( impIst > 0 )
		{
			impIst = 0;	
			kwzDefekt = 0;							// 'KW-Zähler Defekt' löschen
		}
		else
		{
			kwzDefekt = 1;							// 'KW-Zähler Defekt' setzen
		}
	}

// --------------- Volumenstrom-Berechnung ------------------------
	switch ( pZaehlsp->zdim.exponent )			
	{																// Volumen in Liter	fuer einen Impuls
		case 0 :
			impWert =	1;
			break;
		case 1 :
			impWert =	10;
			break;
		case 2 :
			impWert =	100;
			break;
		case 3 :
			impWert =	1000;
			break;
		default :
			impWert =	0;
			break;																			
	}

	if ( timeDiff <= MAXZEIT ) 
	{
		++timeDiff;
	}
	
	if ( pZaehlsp->zwert != lastWert )
	{
		if ( start == 1 )
		{
			start = 0;
		}
		else
		{
			impIst = 1;	
			kwzDefekt = 0;							// 'KW-Zähler Defekt' löschen 14.05.2009
			volstr = ( (ULONG)impWert *36000 ) / timeDiff; 
			lasttimeDiff = timeDiff;
			timeDiff = 0;
			lastWert = pZaehlsp->zwert;
		}
	}
	else
	{
		if ( timeDiff > lasttimeDiff )
		{
			if ( timeDiff > (lasttimeDiff *3) || (timeDiff >= MAXZEIT) )
			{
				volstr = 0;												// Impulszeit zu gross
			}
			else
			{
				volstr = ( (ULONG)impWert *36000 ) / timeDiff; 
			}	
		}	
	}		

// -------------------- 1-Sekunden-Takt ----------------------------	
	if ( ++taskCtr < 10 )
		return;								// Zeit noch nicht erreicht
	taskCtr = 0; 		

	volstrCtr.flow = volstr;

	// Maximaler Volumenstrom
	if ( volstrCtr.flow > volstrCtr.flow_max )
	{
		volstrCtr.flow_max = volstrCtr.flow;
		volstrCtr.VmaxDatum.jahr 	= Jahr;
		volstrCtr.VmaxDatum.monat = Mon;
		volstrCtr.VmaxDatum.tag 	= Tag;
		volstrCtr.VmaxZeit.min 		= Min;
		volstrCtr.VmaxZeit.std 		= Std;
		volstrCtr.VmaxTW1.messw 	= TW1_[0]->messw;
		volstrCtr.VmaxTW1.stat	 	= TW1_[0]->stat;
		volstrCtr.VmaxTW2.messw 	= TW2_[0]->messw;
		volstrCtr.VmaxTW2.stat	 	= TW2_[0]->stat;
			
		bicbus ( EEPADR,	(char *)( &volstrCtr ), KWZVOLMAX_ADR, sizeof(volstrCtr), BICWR );
	}		
		

}
																																					