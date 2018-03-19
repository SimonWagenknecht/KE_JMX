const Pgrup dia[] = {
	{"***."," DIAGNOSE       ","       ", P&Leer15,							ASCII_FORM, 0, P&hid2,	V0, 0, 0},

	{" 01."," DIAGNOSE BEGINN","       ", P&dis.begin,		 		 	 DATE_FORM, 1, P&hid2,	V0, 0, 0},	
	{" 02."," DIAGNOSE ENDE  ","       ", P&dis.end, 			 		 	 DATE_FORM, 1, P&hid2,	V0, 0, 0}, 
	
	{"*06."," VOLUMENSTR.MAX "," m/h  ", P&did.flow_max,	   		 	 US_LONG, 3, P&hid2,	V0, 0, 0}, 
	{"*07."," LEISTUNG MAX   "," kW    ", P&did.wmLeistg_max,				US_INT,	0, P&hid2,	V0, 0, 0},	
	
	{" 10."," LEIST-BEREICH 1"," kW    ", P&dis.leistgBereich[0],		US_INT, 0, P&hid2,	V0, 0, 0},
	{"*11."," ZEIT LEISTBER 1"," h     ", P&did.leistgBereich_h[0],	US_INT,	0, P&hid2,	V0, 0, 0},
	{" 12."," LEIST-BEREICH 2"," kW    ", P&dis.leistgBereich[1],		US_INT, 0, P&hid2,	V0, 0, 0},
	{"*13."," ZEIT LEISTBER 2"," h     ", P&did.leistgBereich_h[1],	US_INT,	0, P&hid2,	V0, 0, 0},
	{" 14."," LEIST-BEREICH 3"," kW    ", P&dis.leistgBereich[2],		US_INT, 0, P&hid2,	V0, 0, 0},
	{"*15."," ZEIT LEISTBER 3"," h     ", P&did.leistgBereich_h[2],	US_INT,	0, P&hid2,	V0, 0, 0},
	{" 16."," LEIST-BEREICH 4"," kW    ", P&dis.leistgBereich[3],		US_INT, 0, P&hid2,	V0, 0, 0},
	{"*17."," ZEIT LEISTBER 4"," h     ", P&did.leistgBereich_h[3],	US_INT,	0, P&hid2,	V0, 0, 0},
	
	{" 20."," VOL-BEREICH 1  "," m/h  ", P&dis.flowBereich[0],		 US_LONG,	3, P&hid2,	V0, 0, 0},
	{"*21."," ZEIT VOLBER 1  "," h     ", P&did.flowBereich_h[0],		US_INT,	0, P&hid2,	V0, 0, 0},
	{" 22."," VOL-BEREICH 2  "," m/h  ", P&dis.flowBereich[1],		 US_LONG,	3, P&hid2,	V0, 0, 0},
	{"*23."," ZEIT VOLBER 2  "," h     ", P&did.flowBereich_h[1],		US_INT,	0, P&hid2,	V0, 0, 0},										 	
	{" 24."," VOL-BEREICH 3  "," m/h  ", P&dis.flowBereich[2],		 US_LONG,	3, P&hid2,	V0, 0, 0},
	{"*25."," ZEIT VOLBER 3  "," h     ", P&did.flowBereich_h[2],		US_INT,	0, P&hid2,	V0, 0, 0},										 	
	{" 26."," VOL-BEREICH 4  "," m/h  ", P&dis.flowBereich[3],		 US_LONG,	3, P&hid2,	V0, 0, 0},
	{"*27."," ZEIT VOLBER 4  "," h     ", P&did.flowBereich_h[3],		US_INT,	0, P&hid2,	V0, 0, 0},	

#if WWANZ > 0
	{"*30."," ANZ. SP.-LADUNG","       ", P&did.wwlad_anz, 					US_INT, 0, P&hid2,	V0, 0, 0},
	{"*31."," SP.-LADUNG MAX "," min   ", P&did.wwlad_time,					US_INT, 0, P&hid2,	V0, 0, 0},										 	
	{"*32."," ANZ. WW-VORRANG","       ", P&did.wwvor_anz, 					US_INT, 0, P&hid2,	V0, 0, 0},
	{"*33."," WW-VORRANG MAX "," min   ", P&did.wwvor_time,					US_INT, 0, P&hid2,	V0, 0, 0},
#endif

	{"*40."," TVKES MAXIMUM  "," C    ", P&did.tvpMax.temp, 				 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*41."," DATUM TVKES MAX","       ", P&did.tvpMax.tag,		 	 DATE_FORM, 1, P&hid2,	V0, 0, 0},		
	{"*42."," Ta TVKES MAX   "," C    ", P&did.tvpMax.ta,				ANA_FORM, 1, P&hid2,	V0, 0, 0},
	{"*43."," TVKES MINIMUM  "," C    ", P&did.tvpMin.temp, 				 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*44."," DATUM TVKES MIN","       ", P&did.tvpMin.tag,		 	 DATE_FORM, 1, P&hid2,	V0, 0, 0},		
	{"*45."," Ta TVKES MIN   "," C    ", P&did.tvpMin.ta,				ANA_FORM, 1, P&hid2,	V0, 0, 0},														 	

	{" **."," MITTLERE TEMP. ","       ", P&DiaTH2mod,					ASCII_FORM, 0, P&hid2,	V0, 0, 0},
	{"*51."," TH2 JANUAR     "," C    ", P&TH2Mittel[0], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*52."," TH2 FEBRUAR    "," C    ", P&TH2Mittel[1], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*53."," TH2 MAERZ      "," C    ", P&TH2Mittel[2], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*54."," TH2 APRIL      "," C    ", P&TH2Mittel[3], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*55."," TH2 MAI        "," C    ", P&TH2Mittel[4], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*56."," TH2 JUNI       "," C    ", P&TH2Mittel[5], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*57."," TH2 JULI       "," C    ", P&TH2Mittel[6], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*58."," TH2 AUGUST     "," C    ", P&TH2Mittel[7], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*59."," TH2 SEPTEMBER  "," C    ", P&TH2Mittel[8], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*60."," TH2 OKTOBER    "," C    ", P&TH2Mittel[9], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*61."," TH2 NOVEMBER   "," C    ", P&TH2Mittel[10], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*62."," TH2 DEZEMER    "," C    ", P&TH2Mittel[11], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},

	{"*71."," TH2 VJ JANUAR  "," C    ", P&TH2MittelVJ[0], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*72."," TH2 VJ FEBRUAR "," C    ", P&TH2MittelVJ[1], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*73."," TH2 VJ MAERZ   "," C    ", P&TH2MittelVJ[2], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*74."," TH2 VJ APRIL   "," C    ", P&TH2MittelVJ[3], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*75."," TH2 VJ MAI     "," C    ", P&TH2MittelVJ[4], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*76."," TH2 VJ JUNI    "," C    ", P&TH2MittelVJ[5], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*77."," TH2 VJ JULI    "," C    ", P&TH2MittelVJ[6], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*78."," TH2 VJ AUGUST  "," C    ", P&TH2MittelVJ[7], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*79."," TH2 VJ SEPTEMBE"," C    ", P&TH2MittelVJ[8], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*80."," TH2 VJ OKTOBER "," C    ", P&TH2MittelVJ[9], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*81."," TH2 VJ NOVEMBER"," C    ", P&TH2MittelVJ[10], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*82."," TH2 VJ DEZEMER "," C    ", P&TH2MittelVJ[11], 				 	 S_INT, 1, P&hid2,	V0, 0, 0},

};

