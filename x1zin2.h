const Pgrup x1ze1[] = { // ZIN12 KWZ: Kaltwasser
	{"_**:"," VOLUMENZAEHLER ","       ", P&X1ZE[1],			 				ZE_FORMP, 1,	P&vis,	V0, 0, 0},

	{"*01:"," ZAEHLERWERT    ","       ", P&X1ZE[1],			 				ZE_FORMP, 0,	P&vis,	V1, 0, 0},
	{"*08:"," AKT.MON.VERBR. ","       ", P&X1ZE[1],			 				ZE_FORMP, 5,	P&vis,	V0, 0, 0},

	{"*10:"," VOLUMENSTROM   "," m/h  ", P&volstrCtr.flow,				US_LONG,	3, 	P&vis,	V1, 0, 0},		// ***AnFre
	{"*->."," Impuls-Zeit    "," s     ", P&timeDiff,							US_LONG,	1,	P&hid2,	V0, 0, 0},		// ***AnFre
	{"*->."," Vorige Imp-Zeit"," s     ", P&lasttimeDiff,					US_LONG,	1,	P&hid2,	V0, 0, 0},		// ***AnFre
	{"*11:"," VOL-STR MAXIMUM"," m/h  ", P&volstrCtr.flow_max,		US_LONG,	3,	P&vis,	V0, 0, 0},
	{"*->:"," DATUM V-MAXIMUM"," T.M.J ", P&volstrCtr.VmaxDatum,	DATE_FORM,1,	P&vis,	V0, 0, 0},
	{"*->:"," ZEIT  V-MAXIMUM"," h:min ", P&volstrCtr.VmaxZeit,		ZEIT_FORM,0,	P&vis,	V0, 0, 0},
	{"*->:"," TW1   V-MAXIMUM"," C    ", P&volstrCtr.VmaxTW1,		ANA_FORM, 1,	P&vis,	V0, 0, 0},
	{"*->:"," TW2   V-MAXIMUM"," C    ", P&volstrCtr.VmaxTW2,		ANA_FORM, 1,	P&vis,	V0, 0, 0},
	{" 15;"," V-MAXI LOESCHEN"," JA=1  ", P&volstrCtr.resVMax,		US_CHAR,	0,	P&hid1,	V0, 0, 0},
	
	{" 20;"," VOL-BEREICH 1  "," m/h  ", P&kws.FlowBereich[0],		 US_LONG,	3, P&hid1,	V0, 0, 0},
	{"*21;"," ZEIT VOLBER 1  "," h     ", P&kwd.flowBereich_h[0],		US_INT,	0, P&hid1,	V0, 0, 0},
	{" 22;"," VOL-BEREICH 2  "," m/h  ", P&kws.FlowBereich[1],		 US_LONG,	3, P&hid1,	V0, 0, 0},
	{"*23;"," ZEIT VOLBER 2  "," h     ", P&kwd.flowBereich_h[1],		US_INT,	0, P&hid1,	V0, 0, 0},										 	
	{" 24;"," VOL-BEREICH 3  "," m/h  ", P&kws.FlowBereich[2],		 US_LONG,	3, P&hid1,	V0, 0, 0},
	{"*25;"," ZEIT VOLBER 3  "," h     ", P&kwd.flowBereich_h[2],		US_INT,	0, P&hid1,	V0, 0, 0},										 	
	{" 26;"," VOL-BEREICH 4  "," m/h  ", P&kws.FlowBereich[3],		 US_LONG,	3, P&hid1,	V0, 0, 0},
	{"*27;"," ZEIT VOLBER 4  "," h     ", P&kwd.flowBereich_h[3],		US_INT,	0, P&hid1,	V0, 0, 0},	
	{"*28;"," GESAMT-ZEIT VOL"," h     ", P&kwd.gesZeit_h,					US_INT,	0, P&hid1,	V0, 0, 0},	
	{" 29;"," ZEITEN LOESCHEN"," JA=1  ", P&ZeitLoesch,							US_CHAR,0, P&hid1,	V0, 0, 0},

	{"*30:"," JANUAR         ","       ", P&X1ZE[1],			 				ZE_FORMP, 10, P&vis,	V1, 0, 0},
	{"*31:"," FEBRUAR        ","       ", P&X1ZE[1],			 				ZE_FORMP, 11, P&vis,	V1, 0, 0},
	{"*32:"," MAERZ          ","       ", P&X1ZE[1],			 				ZE_FORMP, 12, P&vis,	V1, 0, 0},
	{"*33:"," APRIL          ","       ", P&X1ZE[1],			 				ZE_FORMP, 13, P&vis,	V1, 0, 0},
	{"*34:"," MAI            ","       ", P&X1ZE[1],			 				ZE_FORMP, 14, P&vis,	V1, 0, 0},
	{"*35:"," JUNI           ","       ", P&X1ZE[1],			 				ZE_FORMP, 15, P&vis,	V1, 0, 0},
	{"*36:"," JULI           ","       ", P&X1ZE[1],			 				ZE_FORMP, 16, P&vis,	V1, 0, 0},
	{"*37:"," AUGUST         ","       ", P&X1ZE[1],			 				ZE_FORMP, 17, P&vis,	V1, 0, 0},
	{"*38:"," SEPTEMBER      ","       ", P&X1ZE[1],			 				ZE_FORMP, 18, P&vis,	V1, 0, 0},
	{"*39:"," OKTOBER        ","       ", P&X1ZE[1],			 				ZE_FORMP, 19, P&vis,	V1, 0, 0},
	{"*40:"," NOVEMBER       ","       ", P&X1ZE[1],			 				ZE_FORMP, 20, P&vis,	V1, 0, 0},
	{"*41:"," DEZEMBER       ","       ", P&X1ZE[1],			 				ZE_FORMP, 21, P&vis,	V1, 0, 0},
	{"*42:"," VORJAHR JANUAR ","       ", P&X1ZE[1],			 				ZE_FORMP, 22, P&vis,	V1, 0, 0},
	{"*43:"," VORJAHR FEBRUAR","       ", P&X1ZE[1],			 				ZE_FORMP, 23, P&vis,	V1, 0, 0},
	{"*44:"," VORJAHR MAERZ  ","       ", P&X1ZE[1],			 				ZE_FORMP, 24, P&vis,	V1, 0, 0},
	{"*45:"," VORJAHR APRIL  ","       ", P&X1ZE[1],			 				ZE_FORMP, 25, P&vis,	V1, 0, 0},
	{"*46:"," VORJAHR MAI    ","       ", P&X1ZE[1],			 				ZE_FORMP, 26, P&vis,	V1, 0, 0},
	{"*47:"," VORJAHR JUNI   ","       ", P&X1ZE[1],			 				ZE_FORMP, 27, P&vis,	V1, 0, 0},
	{"*48:"," VORJAHR JULI   ","       ", P&X1ZE[1],			 				ZE_FORMP, 28, P&vis,	V1, 0, 0},
	{"*49:"," VORJAHR AUGUST ","       ", P&X1ZE[1],			 				ZE_FORMP, 29, P&vis,	V1, 0, 0},
	{"*50:"," VORJAHR SEPT.  ","       ", P&X1ZE[1],			 				ZE_FORMP, 30, P&vis,	V1, 0, 0},
	{"*51:"," VORJAHR OKTOBER","       ", P&X1ZE[1],			 				ZE_FORMP, 31, P&vis,	V1, 0, 0},
	{"*52:"," VORJAHR NOVEMB.","       ", P&X1ZE[1],			 				ZE_FORMP, 32, P&vis,	V1, 0, 0},
	{"*53:"," VORJAHR DEZEMB.","       ", P&X1ZE[1],			 				ZE_FORMP, 33, P&vis,	V1, 0, 0},
	{" 54."," SYNC.ZAEHLWERT ","       ", P&X1ZE[1],							ZE_FORMP, 6,  P&hid3,	V0, 0, 0},
	{" 55."," SYNC.AKT.MONAT ","       ", P&X1ZE[1],							ZE_FORMP, 7,  P&hid3,	V0, 0, 0},
	{" 56."," SYNC.MONAT 1-24","       ", P&X1ZE[1],							ZE_FORMP, 9,  P&hid3,	V0, 0, 0},
	{" 57."," SYNC.MON.VERBR.","       ", P&X1ZE[1],							ZE_FORMP, 40, P&hid3,	V0, 0, 0},
	{" 58."," Zaehlerkonfig. "," 8...1 ", P&X1ZE[1],							ZE_FORMP, 34,	P&hid2,	V0, 0, 0},
	{"*59."," Zaehlermedium  ","       ", P&X1ZE[1],							ZE_FORMP, 38,	P&hid2,	V0, 0, 0},
	{"*60."," Fehlerstatus   "," 8...1 ", P&X1ZE[1],							ZE_FORMP, 35,	P&hid2,	V0, 0, 0},
	{"*61."," Stichtag       ","       ", P&X1ZE[1],							ZE_FORMP, 37,	P&hid2,	V0, 0, 0},
	{"_62;"," ZAEHLERNUMMER  ","       ", P&X1ZE[1], 							ZE_FORMP, 41,	P&hid1,	V0, 0, 0},
	{"*63;"," ZAEHLER VORJAHR","       ", P&X1ZE[1], 							ZE_FORMP, 42,	P&hid1,	V0, 0, 0},
	{" 64."," SYNC.ZAEHL.VORJ","       ", P&X1ZE[1], 							ZE_FORMP, 43,	P&hid3,	V0, 0, 0},

	{" 90;"," KOMMASTELLEN   ","       ", P&X1ZE[1],			 				ZE_FORMP, 2,	P&hid1,	V0, 0, 0},
	{" 91;"," DIMENSION      ","       ", P&X1ZE[1],			 				ZE_FORMP, 3,	P&hid1,	V0, 0, 0},
	{" 92;"," TEILERFAKTOR   ","       ", P&X1ZE[1],			 				ZE_FORMP, 4,	P&hid1,	V0, 0, 0},
	{" 93;"," IMPULSWERT     ","       ", P&X1ZE[1],							ZE_FORMP, 39,	P&hid1,	V0, 0, 0},
	{" ->."," Exponent       ","       ", P&X1ZE[1],							ZE_FORMP, 36,	P&hid2,	V0, 0, 0},
	{" 95."," Zwischenzaehler","       ", P&X1ZE[1],							ZE_FORMP, 8,	P&hid2,	V0, 0, 0},
};
