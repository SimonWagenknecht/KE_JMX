/*------------------------------ Solar-Regelung------------ ----------------------------*/
const Pgrup so1[] = {
	{"***:"," SOLAR-ANLAGE   ","       ", P&Solmod,							ASCII_FORM, 0, P&vis,		V0, 0, 0},
	{"*01:"," KOLLEKTOR   TS1"," C    ", P&TS1_[0],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},	
	{"*01:"," KOLLEKTOR   TS1"," C    ", P&TS1_[0],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},
	{"*->."," TS1 akt.benutzt"," C    ", P&ts1,										S_INT,	1, P&hid2,	V0, 0, 0},
	{"*02:"," SOLAR-TWE   TS2"," C    ", P&TS2_[0],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},
	{"*02:"," SOLAR-TWE   TS2"," C    ", P&TS2_[0],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},
	{"*->."," TS2 akt.benutzt"," C    ", P&ts2,										S_INT,	1, P&hid2,	V0, 0, 0},
	{"*03:"," SOLAR-HEIZ. TS3"," C    ", P&TS3_[0],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},
	{"*03:"," SOLAR-HEIZ. TS3"," C    ", P&TS3_[0],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},
	{"*04:"," SOLAR-PUFF. TS4"," C    ", P&TS4_[0],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},
	{"*04:"," SOLAR-PUFF. TS4"," C    ", P&TS4_[0],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},
	{"*05:"," RL-SOLAR    TS6"," C    ", P&TS5_[0],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},
	{"*05:"," RL-SOLAR    TS6"," C    ", P&TS5_[0],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},
	{"*06:"," PUFFERSP TSPo-P"," C    ", P&TS6_[0],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},	// ***AnFre auch in ANL: ZEILE 2
	{"*06:"," PUFFERSP TSPo-P"," C    ", P&TS6_[0],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},
	{"*->."," TSPo-P  benutzt"," C    ", P&ts6warm,								S_INT,	1, P&hid2,	V0, 0, 0},
	{"*07:"," PUFFERSP TSPu-P"," C    ", P&TS7_[0],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},
	{"*07:"," PUFFERSP TSPu-P"," C    ", P&TS7_[0],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},
	{"*->."," TSPu-P  benutzt"," C    ", P&ts7kalt,								S_INT,	1, P&hid2,	V0, 0, 0},

	{"*08:"," DRUCK KOLL.  PS"," bar   ", P&anaInp[U3].mwSkal,			 ANA_FORM, 1, P&vis,	V1, 0 , 0},
	{"*08:"," DRUCK KOLL.  PS"," bar   ", P&anaInp[U3].mwSkal, 	  ANA_FORM, 0x81, P&kom,	V1, 0 , 0},
	{" ->."," Druck  0 Volt  "," bar   ", P&AnaInpPara[U3].Skal0,		 		S_INT, 1, P&hid2,	V0, 0 , 0},	
	{" ->."," Druck 10 Volt  "," bar   ", P&AnaInpPara[U3].Skal10,			S_INT, 1, P&hid2,	V0, 0 , 0},	
	{" ->."," Filterzeit     "," s     ", P&AnaInpPara[U3].ZkFilt,		 US_INT, 0, P&hid2,	V0, 0 , 0},

	{"*09:"," DRUCK PUFF.  PP"," bar   ", P&anaInp[U4].mwSkal,			 ANA_FORM, 1, P&vis,	V1, 0 , 0},
	{"*09:"," DRUCK PUFF.  PP"," bar   ", P&anaInp[U4].mwSkal, 	  ANA_FORM, 0x81, P&kom,	V1, 0 , 0},
	{" ->."," Druck  0 Volt  "," bar   ", P&AnaInpPara[U4].Skal0,		 		S_INT, 1, P&hid2,	V0, 0 , 0},	
	{" ->."," Druck 10 Volt  "," bar   ", P&AnaInpPara[U4].Skal10,			S_INT, 1, P&hid2,	V0, 0 , 0},	
	{" ->."," Filterzeit     "," s     ", P&AnaInpPara[U4].ZkFilt,		 US_INT, 0, P&hid2,	V0, 0 , 0},

	{" 10;"," SOLAR-BEGINN   "," C    ", P&sos[SO1].TSolBeg,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 11;"," SOLAR-ENDE     "," C    ", P&sos[SO1].TSolEnd,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 12;"," SOLAR ABSCHALT."," h:min ", P&sos[SO1].SolAb,			 ZEIT_FORM, 0, P&hid1,	V0, 0, 0},
	{" 13;"," ABSCHALT-DAUER "," h     ", P&sos[SO1].SolAbDau,		 US_CHAR, 0, P&hid1,	V0, 0, 0},
	{" ->."," Abschaltung Cnt"," *30 s ", P&sod[SO1].zSolAus, 	 	 	US_INT, 0, P&hid2,	V0, 0, 0},
	{" 15;"," PUFF  TSPo-Pmax"," C    ", P&sos[SO1].TS6Max,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 16;"," SPEICHER TW3max"," C    ", P&sos[SO1].TW3Max,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 17;"," VL-ZIRK. TW2max"," C    ", P&sos[SO1].TW2Max,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 18;"," VOL.STROM  MIN "," m/h  ", P&sos[SO1].V2Min,				 US_LONG,	3, P&hid1,	V0, 0, 0},
	{" 19;"," PU SOL   TS6max"," C    ", P&sos[SO1].TS5Max,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 20;"," dT ZIRK TS2>TW2"," K     ", P&sos[SO1].DTSoWwZ,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 21;"," dT LADE TS2>TW4"," K     ", P&sos[SO1].DTSoWwL,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 22;"," dT PUFFER-BETR."," K     ", P&sos[SO1].DTPuff,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 23;"," dT KOLLEKTOR-B."," K     ", P&sos[SO1].DTKoll,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 24;"," dT PUFFERLADUNG"," K     ", P&sos[SO1].DTPufLad,			US_INT, 1, P&hid1,	V0, 0, 0},
	{" 25;"," RV TW SOLAR-WEG"," m/h  ", P&sos[SO1].KwVol0,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 26;"," RV TW VORW.-WEG"," m/h  ", P&sos[SO1].KwVol100,			US_INT, 1, P&hid1,	V0, 0, 0},
	{" 27;"," RV TW MINDEST  "," %-VW  ", P&sos[SO1].KwVentMin,			US_INT, 1, P&hid1,	V0, 0, 0},
	{" 28;"," RV TW V-STR MAX"," m/h  ", P&sos[SO1].KwSolVolMax,		US_INT, 1, P&hid1,	V0, 0, 0},
	{" 29;"," RV TW TWE-VORW."," %-VW  ", P&sos[SO1].KwSolVentMin,	US_INT, 1, P&hid1,	V0, 0, 0},

	{" 30;"," LEGION.TEMP TS1"," C    ", P&sos[SO1].TS1Leg,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 31;"," LEGION.TEMP TS6"," C    ", P&sos[SO1].TS6Leg,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 32;"," LEGION.-PAUSE  "," h     ", P&sos[SO1].LegPause,		 US_CHAR, 0, P&hid1,	V0, 0, 0},
	{" ->."," Leg-Pause   Cnt"," *30 s ", P&sod[SO1].zLegPause,			US_INT, 0, P&hid2,	V0, 0, 0},

	{" 35;"," PU SOL SOLL KOL"," %     ", P&sos[SO1].DzSoPuKol,			US_INT, 1, P&hid1,	V1, 0, 0},
	{" 36;"," PU PK  SOLL PUF"," %     ", P&sos[SO1].DzSoPuPuf,			US_INT, 1, P&hid1,	V1, 0, 0},
	{" 37;"," PU SOL REG.-ART"," 0..3  ", P&BusPuPara[PU_BUS_SOL - 1].Regelart,	US_CHAR,  0, P&wilo1,	V0, 0, 0},
	{" 38;"," PU PK  SOLLWERT"," %     ", P&sos[SO1].BusPufPuSoll,	US_INT, 1, P&wilo2,	V1, 0, 0},
	{" 39;"," PU PK  REG.-ART"," 0..3  ", P&BusPuPara[PU_BUS_PUF - 1].Regelart,	US_CHAR,  0, P&wilo2,	V0, 0, 0},

	{" 40;"," SOL-PRUEFEN  ST"," W/m  ", P&sos[SO1].PruefSS1,			US_INT, 0, P&hid1,	V0, 0, 0},	// 03.08.2011
	{" 41;"," SOL-PRUEFEN TS1"," C    ", P&sos[SO1].PruefTS1,			US_INT, 1, P&hid1,	V0, 0, 0},
	{" 42;"," PRUEF-DAUER    "," min   ", P&sos[SO1].PruefDauer,		US_INT, 0, P&hid1,	V0, 0, 0},
	{" ->."," Pruefdauer  Cnt"," *30 s ", P&sod[SO1].zPruefDauer, 	US_INT, 0, P&hid2,	V0, 0, 0},	// 03.08.2011
	{" 43;"," PRUEF-SPERRE   "," min   ", P&sos[SO1].PruefSperre,		US_INT, 0, P&hid1,	V0, 0, 0},	// 03.08.2011
	{" ->."," Pruefsperre Cnt"," *30 s ", P&sod[SO1].zPruefSperre, 	US_INT, 0, P&hid2,	V0, 0, 0},	// 03.08.2011

	{" 50;"," FROSTSCHUTZ    "," C    ", P&sos[SO1].TS2Frost,			 S_INT, 1, P&hid1,	V0, 0, 0},	// 14.02.2012
	{" 51;"," DRUCK KOLL.MAX "," bar   ", P&AnaInpPara[U3].OGW,	   	 S_INT, 1, P&hid1,	V0, 0, 0},
	{" 52;"," DRUCK KOLL.MIN "," bar   ", P&AnaInpPara[U3].UGW,	 		 S_INT, 1, P&hid1,	V0, 0, 0},
	{" ->."," Hysterese SM   "," bar   ", P&AnaInpPara[U3].Hyst,		US_INT, 1, P&hid2,	V0, 0, 0},
	{" 53;"," DRUCK PUFF.MAX "," bar   ", P&AnaInpPara[U4].OGW,	 		 S_INT, 1, P&hid1,	V0, 0, 0},
	{" 54;"," DRUCK PUFF.MIN "," bar   ", P&AnaInpPara[U4].UGW,	 		 S_INT, 1, P&hid1,	V0, 0, 0},
	{" ->."," Hysterese SM   "," bar   ", P&AnaInpPara[U4].Hyst,		US_INT, 1, P&hid2,	V0, 0, 0},
	{" 56;"," PUFF  TSPo-Pmax"," C    ", P&sos[SO1].TS6Max,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 57;"," PU SOL   TS6max"," C    ", P&sos[SO1].TS5Max,				US_INT, 1, P&hid1,	V0, 0, 0},
	{" 58;"," VOL.STROM  MIN "," m/h  ", P&sos[SO1].V2Min,				 US_LONG, 3, P&hid1,	V0, 0, 0},
                                                                                       
	{"*70:"," KOLLEKTORBETR.?","       ", P&sod[SO1].kollEin,	 JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{" ->."," KollektorBe.Cnt"," *30 s ", P&sod[SO1].zKollEin, 	 	 	US_INT, 0, P&hid2,	V0, 0, 0},
	{" ->."," Verz. Kollektor"," min   ", P&sos[SO1].VerzKollEin,  	US_CHAR,0, P&hid2,	V0, 0, 0},
	{"*71:"," PUFFERRBETRIEB?","       ", P&sod[SO1].puffEin,	 JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{" ->."," PufferBetr. Cnt"," *30 s ", P&sod[SO1].zPuffEin, 		 	US_INT, 0, P&hid2,	V0, 0, 0},
	{" ->."," Verzoeg. Puffer"," min   ", P&sos[SO1].VerzPuffEin,  	US_CHAR,0, P&hid2,	V0, 0, 0},
	{"*72:"," PUFFERLADUNG ? ","       ", P&sod[SO1].pufLad,	 JANEIN_FORM, 0, P&vis,		V1, 0, 0},

	{"*73:"," PU SOL    EIN? ","       ", P&sod[SO1].solPuEinAnz, JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*->."," PU SOL Laufzeit"," h     ", P&sod[SO1].solPuLzAnz,			US_LONG, 0, P&hid2,	V1, 0, 0},
	{"*->:"," PU SOL SOLL-AUS"," Volt  ", P&AA_UNI[U1],						 AOUT_FORMP, 2, P&vis,	V1, 0, 0},
	{"*->:"," BM PU SOL EIN ?","       ", P&sod[SO1].solPuBmAnz,	JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*->:"," WILO-BUS PU SOL","       ", P&BusPuPara[PU_BUS_SOL - 1].Funktion,	PU_FUNC_FORM,0, P&vis,	V0, 0, 0},
	{"*->;"," BUS-ADRESSE    ","       ", P&BusPuPara[PU_BUS_SOL - 1].Adresse,		 US_CHAR,  0, P&wilo1,V0, 0, 0},
	{"*->:"," REGELART IST   ","       ", P&BusPuData[PU_BUS_SOL - 1].regelArtIst,DYN_ASCII_FORM,15,P&wilo1,V0, 0, 0},
	{"*->;"," DREHZAHL IST   "," 1/min ", P&modb_data[PU_BUS_SOL - 1].input_reg5, 	US_INT,  0, P&wilo1,V0, 0, 0},
	{"*->;"," DIFFERENZDRUCK "," mWS   ", P&modb_data[PU_BUS_SOL - 1].input_reg0, 	US_INT,	 1, P&wilo1,V0, 0, 0},
	{"*->;"," FOERDERSTROM   "," m/h  ", P&modb_data[PU_BUS_SOL - 1].input_reg1, 	US_INT,	 1, P&wilo1,V0, 0, 0},

	{"*74:"," PU PK     EIN? ","       ", P&sod[SO1].pufPuEinAnz, JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*->."," PU PK Laufzeit "," h     ", P&sod[SO1].pufPuLzAnz,			US_LONG, 0, P&hid2,	V1, 0, 0},
	{"*->:"," BM PU PK EIN ? ","       ", P&sod[SO1].pufPuBmAnz, 	JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*->;"," WILO-BUS PU PK ","       ", P&BusPuPara[PU_BUS_PUF - 1].Funktion,	PU_FUNC_FORM,0, P&vis,	V0, 0, 0},
	{"*->;"," BUS-ADRESSE    ","       ", P&BusPuPara[PU_BUS_PUF - 1].Adresse,		 US_CHAR,  0, P&wilo2,V0, 0, 0},
	{"*->:"," REGELART IST   ","       ", P&BusPuData[PU_BUS_PUF - 1].regelArtIst,DYN_ASCII_FORM,15,P&wilo2,V0,	0, 0},
	{"*->;"," DREHZAHL IST   "," 1/min ", P&modb_data[PU_BUS_PUF - 1].input_reg5, 	US_INT,  0, P&wilo2,V0, 0, 0},
	{"*->;"," DIFFERENZDRUCK "," mWS   ", P&modb_data[PU_BUS_PUF - 1].input_reg0, 	US_INT,	 1, P&wilo2,V0, 0, 0},
	{"*->;"," FOERDERSTROM   "," m/h  ", P&modb_data[PU_BUS_PUF - 1].input_reg1, 	US_INT,	 1, P&wilo2,V0, 0, 0},

	{"*75:"," UV SOL PUF.WEG?","       ", P&MVKOLEA[SO1], 	 JANEIN_FORMOP, 0, P&vis,		V1, 0, 0},
	{"*76:"," UV PK  LADEWEG?","       ", P&MVPUFEA[SO1], 	 JANEIN_FORMOP, 0, P&vis,		V1, 0, 0},
	{"*77:"," UV TWS  Solar ?","       ", P&UVWWEA[SO1],		 JANEIN_FORMOP,	0, P&vis,		V1, 0, 0},
	{"*78:"," RV TW VORWAERM."," %-VW  ", P&MVKALTW[SO1],				AOUT_FORMP, 1, P&vis,		V1, 0, 0},
	{"*79:"," PRUEFBETRIEB ? ","       ", P&sod[SO1].pruefBetrieb,JANEIN_FORM, 0, P&vis,V1, 0, 0},	// 03.08.2011
	{"*79:"," ABSCHALTUNG ?  ","       ", P&sod[SO1].solAus,	 JANEIN_FORM, 0, P&vis,		V0, 0, 0},
	{" ->."," Abschaltung Cnt"," *30 s ", P&sod[SO1].zSolAus, 	 	 	US_INT, 0, P&hid2,	V0, 0, 0},
	{"*79:"," FROSTGEFAHR ?  ","       ", P&pusoFrostAl, 			 JANEIN_FORM, 0, P&vis,		V1, 0, 0},

	{"*80:"," SM DRU.KOL.MAX?","       ", P&anaInp[U3].ogwSM,		JANEIN_FORM, 0, P&vis,	A1, EINZEL ,	0},
	{"*->:"," SM DRU.KOL.MIN?","       ", P&anaInp[U3].ugwSM,		JANEIN_FORM, 0, P&vis,	A1, EINZEL ,	0},
	{"*81:"," SM DRU.PUF.MAX?","       ", P&anaInp[U4].ogwSM,		JANEIN_FORM, 0, P&vis,	A1, EINZEL ,	0},
	{"*->:"," SM DRU.PUF.MIN?","       ", P&anaInp[U4].ugwSM,		JANEIN_FORM, 0, P&vis,	A1, EINZEL ,	0},
	{"*82:"," VOL.STR. ALARM?","       ", P&v2MinAlarm,			 		JANEIN_FORM, 0, P&vis,	E1, STANDARD, 0},
	{"*83:"," PUFFER MAX ?   ","       ", P&pufferMax,			 		JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*84:"," TS3 > TS2 ?    ","       ", P&sod[SO1].ts23Alarm,	JANEIN_FORM, 0, P&vis,	E1, EREIGNIS, 0},
	{" ->."," TS3>TS2 Verzoeg"," *30 s ", P&sos[SO1].vts23Al,	 	 	 	US_CHAR, 0, P&hid2,	V0, 0, 0},
	{" ->."," TS3>TS2 Dauer  "," *30 s ", P&sod[SO1].ts23AlDauer,	 	 US_INT, 0, P&hid2,	V0, 0, 0},
	{"*85:"," SPEICHER MAX ? ","       ", P&speicherMax,		 		JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*86:"," VL-ZIRK. MAX ? ","       ", P&zirkMax,		 				JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*->:"," KWZ DEFEKT ?   ","       ", P&kwzDefekt,					JANEIN_FORM, 0, P&vis,	E1, STANDARD, 0},
	{"*87:"," SM PU SOL     ?","       ", P&sod[SO1].solPuSmAnz,JANEIN_FORM, 0, P&vis,	E1, STANDARD, 0},
	{"*->:"," TEMP PU SOL   ?","       ", P&pusoTempAl,					JANEIN_FORM, 0, P&vis,	V1, 0, 0},
	{"*88:"," SM PU PK      ?","       ", P&sod[SO1].pufPuSmAnz,JANEIN_FORM, 0, P&vis,	E1, STANDARD, 0},
	{"*89:"," HANDBETRIEB   ?","       ", P&sos[SO1].Haut,		  JANEIN_FORM, 0, P&vis,	E1, EREIGNIS, 0},

// ***AnFre 29.08.2013: HAND-Einstellungen gelten auch f�r WILO-ModBus 
	{" 99;"," HAND/AUTOMATIK "," HAND=1", P&sos[SO1].Haut,				 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{" ->;"," PU SOL EIN/AUS "," EIN=1 ", P&sos[SO1].SolPuea,			 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{" ->;"," PU SOL REGELART"," 0..3  ", P&BusPuPara[PU_BUS_SOL-1].RegelartHand,	US_CHAR, 0, P&wilo1,	V1, 0, 0},
	{" ->;"," PU SOL SOLLWERT"," %     ", P&sos[SO1].DzSoPuHand,	 US_INT,  1, P&hid1,	V1, 0, 0},
	{" ->;"," PU PK   EIN/AUS"," EIN=1 ", P&sos[SO1].PufPuea,			 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{" ->;"," PU PK  REGELART"," 0..3  ", P&BusPuPara[PU_BUS_PUF-1].RegelartHand,	US_CHAR, 0, P&wilo2,	V1, 0, 0},
	{" ->;"," PU PK SOLLWERT"," %     ", P&BusPuPara[PU_BUS_PUF-1].SollHand, 		US_INT,  1, P&wilo2,	V1, 0, 0},
	{" ->;"," UV SOL         "," KOLL=0", P&sos[SO1].KolMvea,			 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{" ->;"," UV PK          "," ENTL=0", P&sos[SO1].PufMvea,			 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{" ->;"," UV TWS         "," SOL=1 ", P&sos[SO1].SolMvea,			 US_CHAR,	0, P&hid1,	V1, 0, 0},
	{" ->;"," RV TW  STELLEN "," %-VW  ", P&sos[SO1].KwMvst,			 US_INT,  1, P&hid1,	V1, 0, 0},
};
	
/*------------------------------ Solar-Sensor -----------------------------------------*/
const Pgrup so2[] = {
	{"***:"," SOLAR-SENSOR   ","       ", P&Sosmod,							ASCII_FORM, 0, P&vis,		V0, 0, 0},
	{"*01:"," SOL.-SENSOR  ST"," W/m  ", P&sod[SO1].SS1_Anz,			ANA_FORM, 0, P&vis,		V1, 0, 0},
	{"*01:"," SOL.-SENSOR  ST"," W/m  ", P&sod[SO1].SS1_Anz,			ANA_FORM, 0x81, P&kom,V1, FUEHLER, 0},
	{"*->;"," Sol.-Sensor  ST"," Volt  ", P&AE_UNI[U1],					 ANA_FORMP, 2, 	 P&hid2,V0, 0, 0},
	{" ->."," Skalieren 0Volt"," W/m  ", P&sos[SO1].SS1_Skal0,				S_INT, 	0, P&hid2,V0, 0, 0},	
	{" ->."," Skalier. 10Volt"," W/m  ", P&sos[SO1].SS1_Skal10,	 		S_INT, 	0, P&hid2,V0, 0, 0},	
	{" ->."," Sensor-Filter  ","       ", P&sos[SO1].SS1_Filter,		US_CHAR,	0, P&hid2,V0, 0, 0},

	{"*10:"," STRAHLUNG GESAM"," kWh/m", P&sod[SO1].SS1_kWh_g,				US_LONG,0, P&vis,	V1, 0, 0},
	{" ->."," Synchronisieren","       ", P&sod[SO1].SS1_Sync,			 US_CHAR, 0, P&hid3,V0, 0, 0},
	{"*11:"," STRAHL. AKT.JAH"," kWh/m", P&sod[SO1].SS1_kWh_j,				US_INT,	0, P&vis,	V1, 0, 0},
	{"*12:"," STRAHL. AKT.MON"," kWh/m", P&sod[SO1].SS1_kWh_m,				US_INT,	0, P&vis,	V1, 0, 0},
	{"*13:"," STRAHL. AKT.TAG"," Wh/m ", P&sod[SO1].SS1_Wh_d,				US_INT,	0, P&vis,	V1, 0, 0},
	{"*14:"," STRAHL. AKT.STD"," Wh/m ", P&sod[SO1].SS1_Wh_h,				US_INT,	0, P&vis,	V1, 0, 0},

	{"*21:"," STRAHL. VORJAHR"," kWh/m", P&sod[SO1].SS1_kWh_vj,			US_INT,	0, P&vis,	V1, 0, 0},
	{"*22:"," STRAHL. VORMONA"," kWh/m", P&sod[SO1].SS1_kWh_vm,			US_INT,	0, P&vis,	V1, 0, 0},
	{"*23:"," STRAHL. VORTAG "," Wh/m ", P&sod[SO1].SS1_Wh_vd,				US_INT,	0, P&vis,	V1, 0, 0},
	{"*24:"," STRAHL. VORSTUN"," Wh/m ", P&sod[SO1].SS1_Wh_vh,				US_INT,	0, P&vis,	V1, 0, 0},

	{"*31:"," STRAHL. JANUAR "," kWh/m", P&sod[SO1].SS1_Monat[0],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*32:"," STRAHL. FEBRUAR"," kWh/m", P&sod[SO1].SS1_Monat[1],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*33:"," STRAHL. MAERZ  "," kWh/m", P&sod[SO1].SS1_Monat[2],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*34:"," STRAHL. APRIL  "," kWh/m", P&sod[SO1].SS1_Monat[3],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*35:"," STRAHL. MAI    "," kWh/m", P&sod[SO1].SS1_Monat[4],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*36:"," STRAHL. JUNI   "," kWh/m", P&sod[SO1].SS1_Monat[5],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*37:"," STRAHL. JULI   "," kWh/m", P&sod[SO1].SS1_Monat[6],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*38:"," STRAHL. AUGUST "," kWh/m", P&sod[SO1].SS1_Monat[7],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*39:"," STRAHL. SEPTEMB"," kWh/m", P&sod[SO1].SS1_Monat[8],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*40:"," STRAHL. OKTOBER"," kWh/m", P&sod[SO1].SS1_Monat[9],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*41:"," STRAHL. NOVEMBE"," kWh/m", P&sod[SO1].SS1_Monat[10],		US_INT,	0, P&vis,	V1, 0, 0},
	{"*42:"," STRAHL. DEZEMBE"," kWh/m", P&sod[SO1].SS1_Monat[11],		US_INT,	0, P&vis,	V1, 0, 0},

	{"*51:"," VORJAHR JANUAR "," kWh/m", P&sod[SO1].SS1_VJ_Monat[0],	US_INT,	0, P&vis,V1, 0, 0},
	{"*52:"," VORJAHR FEBRUAR"," kWh/m", P&sod[SO1].SS1_VJ_Monat[1],	US_INT,	0, P&vis,V1, 0, 0},
	{"*53:"," VORJAHR MAERZ  "," kWh/m", P&sod[SO1].SS1_VJ_Monat[2],	US_INT,	0, P&vis,V1, 0, 0},
	{"*54:"," VORJAHR APRIL  "," kWh/m", P&sod[SO1].SS1_VJ_Monat[3],	US_INT,	0, P&vis,V1, 0, 0},
	{"*55:"," VORJAHR MAI    "," kWh/m", P&sod[SO1].SS1_VJ_Monat[4],	US_INT,	0, P&vis,V1, 0, 0},
	{"*56:"," VORJAHR JUNI   "," kWh/m", P&sod[SO1].SS1_VJ_Monat[5],	US_INT,	0, P&vis,V1, 0, 0},
	{"*57:"," VORJAHR JULI   "," kWh/m", P&sod[SO1].SS1_VJ_Monat[6],	US_INT,	0, P&vis,V1, 0, 0},
	{"*58:"," VORJAHR AUGUST "," kWh/m", P&sod[SO1].SS1_VJ_Monat[7],	US_INT,	0, P&vis,V1, 0, 0},
	{"*59:"," VORJAHR SEPTEMB"," kWh/m", P&sod[SO1].SS1_VJ_Monat[8],	US_INT,	0, P&vis,V1, 0, 0},
	{"*60:"," VORJAHR OKTOBER"," kWh/m", P&sod[SO1].SS1_VJ_Monat[9],	US_INT,	0, P&vis,V1, 0, 0},
	{"*61:"," VORJAHR NOVEMBE"," kWh/m", P&sod[SO1].SS1_VJ_Monat[10],US_INT,	0, P&vis,V1, 0, 0},
	{"*62:"," VORJAHR DEZEMBE"," kWh/m", P&sod[SO1].SS1_VJ_Monat[11],US_INT,	0, P&vis,V1, 0, 0},
};
