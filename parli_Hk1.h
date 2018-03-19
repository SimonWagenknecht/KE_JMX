/*------------------------------ Heizkreis 1 -------------------------------------------*/
const Pgrup hk1[] = {
//-------------------
	{"_**:"," HEIZKREIS 1    ","       ", P&hkd[HK1].raumname,	ASCII_FORM, 0, P&vis,		V0, 0, 0},
	{"*01:"," VL-HEIZUNG  TVH"," C    ", P&TVS[HK1],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},      
	{"*01:"," VL-HEIZUNG  TVH"," C    ", P&TVS[HK1],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},	// ***AnFre

	#if TRLBEG_HK1==1
	{"*02:"," RL-HEIZUNG  TRH"," C    ", P&TRS[HK1],						 ANA_FORMP, 1, P&vis,		V1, 0, 0},      
	{"*02:"," RL-HEIZUNG  TRH"," C    ", P&TRS[HK1],					ANA_FORMP, 0x81, P&kom,		E1, FUEHLER, 0},	// ***AnFre
	#endif
	
	{" 06;"," SO/WI HK-EXTRA "," 1=JA  ", P&hks[HK1].SoWiExtra,		 US_CHAR, 0, P&hid1,	V0, 0, 0},
	{" 07;"," Ta-WINTER [EIN]"," C    ", P&hks[HK1].Tae,						US_INT, 1, P&hid1,	V0, 0, 0},
	{" 08;"," Ta-SOMMER [AUS]"," C    ", P&hks[HK1].Taa,						US_INT, 1, P&hid1,	V0, 0, 0},
	{"*09;"," SOMMER HK  ?   ","       ", P&hkd[HK1].sowi,		 JANEIN_FORM, 0, P&hid1,	V0, 0, 0},

	{" 10;"," STEIGUNG       ","       ", P&hks[HK1].Anst,					US_INT, 2, P&hid1,	V1, 0, 0},
	{" 11;"," NIVEAU         "," C    ", P&hks[HK1].Tvpa,					US_INT, 1, P&hid1,	V1, 0, 0},
	{" 12;"," VORLAUF   MAX  "," C    ", P&hks[HK1].Tvma,					US_INT, 1, P&hid1,	V1, 0, 0},
	{" 13;"," VORLAUF   MIN  "," C    ", P&hks[HK1].Tvmi,					US_INT, 1, P&hid1,	V1, 0, 0},
// ***AnFre
	{"*14:"," ANFORDER.EXT 1 "," C    ", P&hkd[HK1].ExtAnf1Hk,			ANA_FORM, 1, P&vis,	V1, 0, 0},
	{"*14:"," ANFORDER.EXT 1 "," C    ", P&hkd[HK1].ExtAnf1Hk,	 ANA_FORM, 0x81, P&kom,	E1, FUEHLER, 0},
	{" ->."," ANFORD.GUELTIG "," 1=JA  ", P&hks[HK1].ExtAnf1_Ja,	 	 US_CHAR, 0, P&hid2,V0, 0, 0},
	{"*15:"," ANFORDER.EXT 2 "," C    ", P&hkd[HK1].ExtAnf2Hk,			ANA_FORM, 1, P&vis,	V1, 0, 0},
	{"*15:"," ANFORDER.EXT 2 "," C    ", P&hkd[HK1].ExtAnf2Hk,	 ANA_FORM, 0x81, P&kom,	E1, FUEHLER, 0},
	{" ->."," ANFORD.GUELTIG "," 1=JA  ", P&hks[HK1].ExtAnf2_Ja,	   US_CHAR, 0, P&hid2,V0, 0, 0},
	{" 16;"," ANHEB. EXT.ANF."," K     ", P&hks[HK1].TvAnhExt,				US_INT, 1, P&hid1,V1, 0, 0},

	#if TRLBEG_HK1==1
	{" 18;"," RUECKLAUF MAX  "," C    ", P&hks[HK1].Trma,					US_INT, 1, P&hid1,		V1, 0, 0},
	{" 19;"," Xp-RUECKL.BEGR.","       ", P&hks[HK1].Kpr,						US_INT, 2, P&hid1,		V1, 0, 0},
	#endif

	{"*20:"," VORLAUF BERECHN"," C    ", P&hkd[HK1].tvsb,					US_INT, 1, P&vis,		V1, 0, 0},
	{"*->."," Vorlauf ber.HKl"," C    ", P&hkd[HK1].tvsb_hkl,			US_INT, 1, P&hid2,	V0, 0, 0},
	{"*->."," Korrektur RL   "," K     ", P&hkd[HK1].rlKorr,			 	 S_INT, 1, P&hid2,	V0, 0, 0},
// ***AnFre	{"*->:"," korrektur adapt"," K     ", P&hkd[HK1].adaptKorr,			 S_INT, 1, P&hid2,	V0, 0, 0},
// ***AnFre	{"*->:"," korrektur kaska"," K     ", P&hkd[HK1].kaskaKorr,			 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*->."," Korrektur wwvor"," K     ", P&hkd[HK1].wwvorKorr,			 S_INT, 1, P&hid2,	V0, 0, 0},
	{" ->."," Vorlauf Filt.ZK"," s     ", P&hks[HK1].Fzk,						US_INT, 1, P&hid2,	V0, 0, 0},

	#if FBH_HK1==1
	{" 25;"," ESTR.-PR.START ","       ", P&hks[HK1].StartAufheiz, DATE_FORM, 1, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG1 "," C    ", P&hks[HK1].EstrichTemp[0], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG2 "," C    ", P&hks[HK1].EstrichTemp[1], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG3 "," C    ", P&hks[HK1].EstrichTemp[2], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG4 "," C    ", P&hks[HK1].EstrichTemp[3], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG5 "," C    ", P&hks[HK1].EstrichTemp[4], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG6 "," C    ", P&hks[HK1].EstrichTemp[5], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG7 "," C    ", P&hks[HK1].EstrichTemp[6], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG8 "," C    ", P&hks[HK1].EstrichTemp[7], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG9 "," C    ", P&hks[HK1].EstrichTemp[8], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG10"," C    ", P&hks[HK1].EstrichTemp[9], US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG11"," C    ", P&hks[HK1].EstrichTemp[10],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG12"," C    ", P&hks[HK1].EstrichTemp[11],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG13"," C    ", P&hks[HK1].EstrichTemp[12],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG14"," C    ", P&hks[HK1].EstrichTemp[13],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG15"," C    ", P&hks[HK1].EstrichTemp[14],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG16"," C    ", P&hks[HK1].EstrichTemp[15],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG17"," C    ", P&hks[HK1].EstrichTemp[16],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG18"," C    ", P&hks[HK1].EstrichTemp[17],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG19"," C    ", P&hks[HK1].EstrichTemp[18],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG20"," C    ", P&hks[HK1].EstrichTemp[19],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG21"," C    ", P&hks[HK1].EstrichTemp[20],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG22"," C    ", P&hks[HK1].EstrichTemp[21],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG23"," C    ", P&hks[HK1].EstrichTemp[22],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG24"," C    ", P&hks[HK1].EstrichTemp[23],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG25"," C    ", P&hks[HK1].EstrichTemp[24],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG26"," C    ", P&hks[HK1].EstrichTemp[25],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG27"," C    ", P&hks[HK1].EstrichTemp[26],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG28"," C    ", P&hks[HK1].EstrichTemp[27],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG29"," C    ", P&hks[HK1].EstrichTemp[28],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{" ->;"," ESTR.TEMP.TAG30"," C    ", P&hks[HK1].EstrichTemp[29],US_CHAR, 0, P&hid4,	V0, 0, 0},
	{"*26:"," ESTRICH-PROGR.?","       ", P&hkd[HK1].estrichProg,JANEIN_FORM, 0, P&vis, 	V0, 0, 0},
	{"*27:"," ESTRICH AKT.TAG","       ", P&hkd[HK1].estrichTag,		 US_CHAR, 0, P&vis,		V0, 0, 0},
	{"*28:"," ESTR.AKT.SOLLT."," C    ", P&hkd[HK1].estrichTemp,			US_INT, 0, P&vis,		V0, 0, 0},
	#endif

// ***AnFre	{" 28:"," ANFORD.ANHEBUNG"," K     ", P&hks[HK1].TvpAnh,				US_INT, 1, P&vis,			V1, 0, 0},

	{" 30;"," ABSENK-BEGIN WO"," h:min ", P&abs_tab[HK1][0].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" 31;"," ABSENK-DAUER WO"," h     ", P&abs_tab[HK1][0].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" 32;"," ABSENK-WERT  WO"," K     ", P&abs_tab[HK1][0].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},
	{" 34;"," GANZE WOCHE SET"," 1=JA  ", P&setwoche[HK1],				 US_CHAR, 0, P&hid1,		V1, 0, 0},

	{" 35;"," ABSENK-BEGIN Mo"," h:min ", P&abs_tab[HK1][1].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-DAUER Mo"," h     ", P&abs_tab[HK1][1].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-WERT  Mo"," K     ", P&abs_tab[HK1][1].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},

	{" 36;"," ABSENK-BEGIN Di"," h:min ", P&abs_tab[HK1][2].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-DAUER Di"," h     ", P&abs_tab[HK1][2].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-WERT  Di"," K     ", P&abs_tab[HK1][2].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},

	{" 37;"," ABSENK-BEGIN Mi"," h:min ", P&abs_tab[HK1][3].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-DAUER Mi"," h     ", P&abs_tab[HK1][3].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-WERT  Mi"," K     ", P&abs_tab[HK1][3].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},

	{" 38;"," ABSENK-BEGIN Do"," h:min ", P&abs_tab[HK1][4].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-DAUER Do"," h     ", P&abs_tab[HK1][4].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-WERT  Do"," K     ", P&abs_tab[HK1][4].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},

	{" 39;"," ABSENK-BEGIN Fr"," h:min ", P&abs_tab[HK1][5].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-DAUER Fr"," h     ", P&abs_tab[HK1][5].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-WERT  Fr"," K     ", P&abs_tab[HK1][5].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},

	{" 40;"," ABSENK-BEGIN Sa"," h:min ", P&abs_tab[HK1][6].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-DAUER Sa"," h     ", P&abs_tab[HK1][6].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-WERT  Sa"," K     ", P&abs_tab[HK1][6].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},

	{" 41;"," ABSENK-BEGIN So"," h:min ", P&abs_tab[HK1][7].begin,ZEIT_FORM,0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-DAUER So"," h     ", P&abs_tab[HK1][7].dauer, US_CHAR, 0, P&hid1,		V1, 0, 0},
	{" ->;"," ABSENK-WERT  So"," K     ", P&abs_tab[HK1][7].abwert,	US_INT, 1, P&hid1,		V1, 0, 0},
	
	
//#####ulsch : Ferienautomatik #####
	#if FER == 1
	{" 42:"," FERIENAUTOMATIK"," JA=1  ", P&hks[HK1].FerienAutom,	 		US_CHAR, 0, P&vis,	V1, 0, 0},
	{" 43:"," FER.ABSENK-WERT"," K     ", P&hks[HK1].FerienAbsenk,		 US_INT, 1, P&vis,	V1, 0, 0},
	{"*->."," Ferienbetrieb ?","       ", P&hkd[HK1].absenFerien,	JANEIN_FORM, 0, P&hid2,	V0, 0, 0},
	#endif

	#if BEDARF_HK1==1
	{" 44:"," BEDARFS-ABSENK."," K     ", P&hks[HK1].Beabs,					US_INT, 1, P&vis,		V1, 0, 0},
	#else
// ***AnFre	{" ->;"," bedarfs-absenk."," K     ", P&hks[HK1].Beabs,					US_INT, 1, P&hid2,	V0, 0, 0},
	#endif

	#if BEDRAUM_HK1 == 1
	{" 45:"," RAUMABSCHALTUNG"," JA=1  ", P&hks[HK1].AbschRaumanf,	 US_CHAR, 0, P&vis,	V1, 0, 0},
	{" 46:"," VENTILE AUSWERT"," JA=1  ", P&hks[HK1].VentilAuswert,	 US_CHAR, 0, P&vis,	V1, 0, 0},
	{" 47:"," VENT_AUF ABSCH."," %     ", P&hks[HK1].VentOffenMax,	 US_CHAR, 0, P&vis,	V1, 0, 0},
	{"*->;"," ventile offen  ","       ", P&hkd[HK1].ventOffen,				US_INT, 0, P&hid2,V0, 0, 0},
	{"*->;"," ventile gesamt ","       ", P&hkd[HK1].ventGesamt,			US_INT, 0, P&hid2,V0, 0, 0},
	{"*48:"," VENTILE OFFEN  "," %     ", P&hkd[HK1].ventOffenBer,	 US_CHAR, 0, P&vis,	V1, 0, 0},
	{"*49:"," RAUMABSCHALTG.?","       ", P&hkd[HK1].raumAbsch, JAFRAGE_FORM, 0, P&vis,	V1, 0, 0},
	#endif

	{" 50;"," HEIZGRENZE  Ta "," C    ", P&hks[HK1].TaHeizgrenze,		 S_INT, 1, P&hid1,	V1, 0, 0},
	{" 51."," Frostgrenze Ta "," C    ", P&hks[HK1].TaFrostgrenze,		 S_INT, 1, P&hid2,	V0, 0, 0},
	{" 52."," Absch-Zeitkonst"," h/K   ", P&hks[HK1].AbschZeitKonst,	US_INT, 1, P&hid2,	V0, 0, 0},
	{" 53."," Schnellaufheiz."," JA=1  ", P&hks[HK1].Sauf,				 	 US_CHAR, 0, P&hid2,	V0, 0, 0},

	{" 55;"," PU-SOLL NORMAL "," %     ", P&hks[HK1].BusPuSollwert,		 		US_INT, 1, P&wilo3,	V1, 0, 0},
	{" 56;"," PU-SOLL ABSENK "," %     ", P&hks[HK1].BusPuSollwertAbsenk,	US_INT, 1, P&wilo3,	V1, 0, 0},
	{" 57;"," REGELART SOLL  "," 0-3   ", P&BusPuPara[PU_BUS_HK1 - 1].Regelart, US_CHAR, 0, P&wilo3,	V0, 0, 0},

	{" 60;"," SO/WI-AUTOMATIK"," JA=1  ", P&hks[HK1].Swhk,				 US_CHAR, 0, P&hid1,	V1, 0, 0},

	#if SWAUS_HK1 == 1	// Anlagenschalter für HK-Nichtnutzung
	{" 64:"," HKAUS-ABSENKW. "," K     ", P&hks[HK1].SchalterAbsenk,US_INT, 1, P&vis,		V1, 0, 0},
	#endif

	#if TRLBEG_HK1==1
// ***AnFre	{" ->."," r-begr.prim/sek"," PRIM=1", P&hks[HK1].Psbegr,			 US_CHAR, 0, P&hid2,	V0, 0, 0},
	#endif

	#if FRG_HK1 == 1
	{"*66:"," ANFORDERUNG ?  ","       ", P&FRGHK[HK1], 		 JANEIN_FORMIP, 0, P&vis,		V1, 0, 0},
	#endif

	{" 68."," TDiff.Alarm Ein"," K     ", P&hks[HK1].TabwMax,			 US_CHAR, 1, P&hid2,	V0, 0, 0},
	{" 69."," ZVerz.Alarm Ein"," min   ", P&hks[HK1].TabwZeit,		 US_CHAR, 0, P&hid2,	V0, 0, 0},

	{"*70:"," PU H       EIN?","       ", P&hkd[HK1].puEinAnz, JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{"*->."," Pumpen-Laufzeit"," h     ", P&hkd[HK1].puLzAnz,			 US_LONG, 0, P&hid2,	V1, 0, 0},
	{" ->."," Pu-Nachlaufzeit"," min   ", P&hks[HK1].Puna,				 US_CHAR, 0, P&hid2,	V0, 0, 0},
	{" ->."," Pum-Nachl.  Cnt"," *30 s ", P&hkd[HK1].zpu,						US_INT, 0, P&hid2,	V0, 0, 0},
//	{"*->:"," PUMPENDREHZAHL "," %     ", P&AA_UNI[U2],					AOUT_FORMP, 1, P&vis,		V1, 0, 0},
	{"*->:"," BM PU H    EIN?","       ", P&hkd[HK1].puBmAnz,  JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{"*->:"," WILO-BUS PU H  ","       ", P&BusPuPara[PU_BUS_HK1 - 1].Funktion, PU_FUNC_FORM,0, P&vis,	V0, 0, 0},
	{"*->;"," BUS-ADRESSE    ","       ", P&BusPuPara[PU_BUS_HK1 - 1].Adresse,		 US_CHAR,  0, P&wilo3,V0, 0, 0},
	{"*->;"," REGELART IST   ","       ", P&BusPuData[PU_BUS_HK1 - 1].regelArtIst,DYN_ASCII_FORM,15,P&wilo3,V0,	0, 0},
	{"*->;"," DREHZAHL IST   "," 1/min ", P&modb_data[PU_BUS_HK1 - 1].input_reg5, 	US_INT,  0, P&wilo3,V0, 0, 0},
	{"*->;"," DIFFERENZDRUCK "," mWS   ", P&modb_data[PU_BUS_HK1 - 1].input_reg0, 	US_INT,	 1, P&wilo3,V0, 0, 0},
	{"*->;"," FOERDERSTROM   "," m/h  ", P&modb_data[PU_BUS_HK1 - 1].input_reg1, 	US_INT,	 1, P&wilo3,V0, 0, 0},


	{"*80;"," BETRIEBS-REGIE ","       ", P&hkd[HK1].regie_txt, DYN_ASCII_FORM, 0, P&hid1,	V0, 0, 0},
	{"*81:"," ABSENKPHASE ?  ","       ", P&hkd[HK1].absen,		 JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{" ->."," Absenkwert abs "," K     ", P&abs_ram[HK1].tvab,			US_INT, 1, P&hid2,	V0, 0, 0},
	{" ->."," Absenkzeit abs "," *10 s ", P&abs_ram[HK1].zasd,			US_INT, 0, P&hid2,	V0, 0, 0},
	{"*82:"," ABSCHALTPHASE ?","       ", P&hkd[HK1].absch,		 JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{" ->."," Abschalt   abs "," *10 s ", P&abs_ram[HK1].zAbsch,		US_INT, 0, P&hid2,	V0, 0, 0},
	{"*83;"," AUFHEIZPHASE ? ","       ", P&hkd[HK1].aufhe,		 JANEIN_FORM, 0, P&hid1,	V1, 0, 0},
	{" ->."," Aufheiz    abs "," *10 s ", P&abs_ram[HK1].zahd,			US_INT, 0, P&hid2,	V0, 0, 0},
	{"*84:"," SOMMERBETRIEB ?","       ", P&hkd[HK1].somme,	 	 JANEIN_FORM, 0, P&vis,		V1, 0, 0},
//	{"*->:"," STUETZBETRIEB ?","       ", P&hkd[HK1].stuetz,	 JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{"*->:"," FROSTBETRIEB ? ","       ", P&hkd[HK1].frost,		 JANEIN_FORM, 0, P&hid1,	V0, 0, 0},

// ***AnFre	{" ->:"," absenkwert bed "," K     ", P&abs_bed[HK1].tvab,			US_INT, 1, P&hid2,	V0, 0, 0},
// ***AnFre	{" ->:"," absenkzeit bed "," s/10  ", P&abs_bed[HK1].zasd,			US_INT, 0, P&hid2,	V0, 0, 0},
// ***AnFre	{" ->:"," abschalt   bed "," s/10  ", P&abs_bed[HK1].zAbsch,		US_INT, 0, P&hid2,	V0, 0, 0},
// ***AnFre	{" ->:"," aufheiz    bed "," s/10  ", P&abs_bed[HK1].zahd,			US_INT, 0, P&hid2,	V0, 0, 0},

	#if WWANZ > 0
	{"*84:"," WW-VORRANG ?   ","       ", P&hkd[HK1].vorra,	 	 JANEIN_FORM, 0, P&vis,		V0, 0, 0},
	#else
// ***AnFre	{" ->:"," ww-vorrang ?   ","       ", P&hkd[HK1].vorra,	 	 JANEIN_FORM, 0, P&hid2,	V0, 0, 0},
	#endif

	{"*85:"," RUECKL.BEGR. ? ","       ", P&hkd[HK1].rlbegr,	 JANEIN_FORM, 0, P&vis,		V1, 0, 0},
	{"*86:"," SM REGELABW.?  ","       ", P&hkd[HK1].abwAlarm, JANEIN_FORM, 0, P&vis, 	A1, EINZEL,   0},
	{"*87:"," SM STW H     ? ","       ", P&STWHK[HK1], 		 JANEIN_FORMIP, 0, P&vis,		A1, EINZEL,   0},
	{"*88:"," SM PU H       ?","       ", P&hkd[HK1].puSmAnz,	 JANEIN_FORM, 0, P&vis,		E1, STANDARD, 0},

	{"*89:"," HANDBETRIEB ?  ","       ", P&hks[HK1].Haut,		 JANEIN_FORM, 0, P&vis,		E1, EREIGNIS, 0},

	{" 90;"," P-VERSTAERKUNG "," %/K   ", P&hks[HK1].Kp,						US_INT, 2, P&hid1,	V0, 0, 0},
	{" 91;"," D-VERSTAERKUNG ","       ", P&hks[HK1].Kd,						US_INT, 2, P&hid1,	V0, 0, 0},
	{" 92;"," TASTZEIT       "," s     ", P&hks[HK1].Ts,						US_INT, 1, P&hid1,	V0, 0, 0},
	{" 93;"," NACHSTELLZEIT  "," s     ", P&hks[HK1].Tn,						US_INT, 1, P&hid1,	V0, 0, 0},

	#if DREIP_HK1==1
	{" 94;"," VENTILHUB MAX  "," mm    ", P&hks[HK1].Hub,					 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{" 95;"," STELLGESCHWIND."," mm/min", P&hks[HK1].Vst,			 		 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{"*->."," Stellzeit ber. "," s     ", P&hkd[HK1].stellzeit,			 S_INT, 2, P&hid2,	V0, 0, 0},
	{"*->."," Stellsumme     "," s     ", P&hkd[HK1].stellsum,			 S_INT, 2, P&hid2,	V0, 0, 0},
	{"*->."," Fahrzeit       "," s     ", P&hkd[HK1].fahren,				 S_INT, 0, P&hid2,	V0, 0, 0},
	#else
	{" 94;"," VENTILSTELL.MIN"," %     ", P&hks[HK1].Y_rel_min,	 		US_INT, 1, P&hid1,	V0, 0, 0},
	{" 95;"," OEFFNUNGSBEGINN"," %     ", P&hks[HK1].Y_rel_beg,	 		US_INT, 1, P&hid1,	V0, 0, 0},
	#endif

	{"*96:"," SOLLWERT       "," C    ", P&hkd[HK1].tsol,					US_INT, 1, P&vis,		V1, 0, 0},
	{" ->."," Sollw.Ausg.  0V"," C    ", P&hks[HK1].Tvsol0,				 S_INT, 1, P&hid2,	V0, 0, 0},
	{" ->."," Sollw.Ausg. 10V"," C    ", P&hks[HK1].Tvsol10,				 S_INT, 1, P&hid2,	V0, 0, 0},
	{"*->."," SollwertAusgabe"," Volt  ", P&AA_UNI[U2],					AOUT_FORMP, 2, P&hid2,	V0, 0, 0},

	{"*97:"," REGELABWEICHUNG"," K     ", P&hkd[HK1].ei,						 S_INT, 1, P&vis,		V1, 0, 0},
	{"*->."," dy_rel         ","       ", P&hkd[HK1].dy_rel,				 S_INT, 3, P&hid2,	V0, 0, 0},

	{"*98:"," V.STELL.  RV H "," %     ", P&RVENT[HK1],					AOUT_FORMP, 1, P&vis,	V1, 0, 0},

	//-------------------------------------------------------------------------------------------------
	{" 99;"," HAND/AUTOMATIK "," HAND=1", P&hks[HK1].Haut,				 US_CHAR, 0, P&hid1,	V1, 0, 0},

	{" ->:"," PU H  EIN/AUS  "," EIN=1 ", P&hks[HK1].Puea,		 		 US_CHAR, 0, P&hid1,	V1, 0, 0},
	{" ->;"," PU H  REGELART "," 0..3  ", P&BusPuPara[PU_BUS_HK1-1].RegelartHand,	US_CHAR, 0, P&wilo3,	V1, 0, 0},
	{" ->;"," PU H  SOLLWERT "," %     ", P&BusPuPara[PU_BUS_HK1-1].SollHand,	 		US_INT,  1, P&wilo3,	V1, 0, 0},

	{" ->;"," STELLEN   RV H "," %     ", P&hks[HK1].Vstell,			  US_INT, 1, P&hid1,	V1, 0, 0},

};


/*------------------------------ Heizkurven-Adaption ----------------------------------------------*/
