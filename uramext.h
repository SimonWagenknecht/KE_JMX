/*          uramext.h                                  */
/*  Header f�r nicht intialisierte User - Variablen  */

#ifndef URAMEXT_H_INCLUDED
#define URAMEXT_H_INCLUDED

#include "userdef.h"
#include "ustruct.h"
#include "archivsdm.h"


extern int k_dummy;
extern char anz_dummy;	// ***AnFre f�r Solar-Anzeigetafel

extern char testClear;
extern char char_test1;
extern char char_test2;
extern int  int_test;
extern mwsp *temperatur;

extern int TaErsatz[12];
extern UINT TaErsatzCtr;
extern char TaErsatzVerz;

// NLT Neue Leittechnik
extern events prim_evtab[];
extern events seku_evtab[];
extern char sms_feld[];				// Merker f�r Feldindex prim_evtab

/* Konfigurations-Anzeigebytes */
extern char ptinput1;
extern char ptinput2;
extern char aeinput1;
extern char aeinput2;
extern char diginput1;
extern char diginput2;
extern char digtherm1;
extern char digtherm2;
extern char digoutput1;
extern char digoutput2;
extern char anaoutput1;
extern char anaoutput2;
extern char zinput1;					// R36
extern char zinput2;					// R36
extern char zinput_r37[4];		// R37_1 und R37_2  ( R37_3 und R37_4 nicht benutzt, aber Speicherplatz reserviert )

extern char ort_idf;
extern char ort_idf_flag;

// Objekt- und Standortbezeichnungen
extern char Objektbez [16];		
extern char Objektnum [10];		
extern char Strasse   [16];		
extern char Nummer    [10];		
extern char Ort       [16];		
extern char Plz       [10];		
extern char Version_PVers_Ascii[10];	// Programmversion

//--------------------------------------------------------------------------------------------------
// M-Bus
#if ( ((IMPLEMENT_S1 & MBUS1_IMPL) == MBUS1_IMPL) || ((IMPLEMENT_S2 & MBUS1_IMPL) == MBUS1_IMPL) || ((IMPLEMENT_S3 & MBUS1_IMPL) == MBUS1_IMPL) )

extern MbusDynam MbusData[];
extern MbusStandard MbusPara[];
extern UINT MbusFrequ;
extern char MbusAktualisierung;
extern char MbusCtrAktiv;
extern char MbusStatus;
extern UINT Timeout;
extern char RxStatus;

extern char MbusTxCtr;
extern char MbusTxLng;
extern char MbusRxCtr;
extern char MbusRxLng;
extern char *pMbusTx;
extern char *pMbusRx;

extern char MbusTxBuf[];
extern char MbusRxBuf[];

extern char MbCtrAkt;
//extern Sichtbarkeit Sichtbar[];
extern Sichtbarkeit Sichtbar;
extern uhrzeit AktStd;
extern uhrzeit LetzteAkt;
extern char mbus_vis;
extern char zaehlerNummer;

#endif

//--------------------------------------------------------------------------------------------------
//// Modbus
//#if ( ((IMPLEMENT_S1 & MODBUS1_IMPL) == MODBUS1_IMPL) || ((IMPLEMENT_S2 & MODBUS1_IMPL) == MODBUS1_IMPL) || ((IMPLEMENT_S3 & MODBUS1_IMPL) == MODBUS1_IMPL) )
//				
//// Jochen Teil
//																											// Kommentare von JoSch
////extern	unsigned int modbusDeviceNr;											// Modbus.c  + modbusparli.h
////extern	int activeRow[3];																	// Modbus.c  + modbusparli.h
////extern	unsigned char modbusSlaveAddresses[3];						// Modbus.c  + modbusparli.h  + modbusstandard.h
////extern	unsigned char modbusSioParity[3];									// Modbus.c  + modbusparli.h  + modbusstandard.h
////extern	unsigned char modbusConvertBuffer[3][256];				// Modbus.c		
////
////extern modbusTableRowData modbusTableData[];		
////extern modbusTableRowData modbusSlaveTableData[];
////extern unsigned char 			modbusDeviceAddresses[];
//
//
//// RKL + Jochen																							
//extern	char modb_leng_tx[3];															// U_ModBusSio.c
//extern	char modb_rts_prescaler[3];												// U_ModBusSio.c
//extern	char modb_rts_timer[3];														// U_ModBusSio.c
//extern	char modb_rx_buff_size;														// U_ModBusSio.c
//extern	char modb_rx_status;															// Modbus.c										
//extern	char modb_tx_count[3];														// U_ModBusSio.c
//extern	char modb_rx_count[3];														// U_ModBusSio.c							
//extern	char modb_rx_buffer_ready[3];											// U_ModBusSio.c							
//extern	char modb_rx_int_state[3];												// U_ModBusSio.c							
//extern	char modb_sio_errorflag[3];												// U_ModBusSio.c
//extern	unsigned int EoF_timer[3];												// U_ModBusSio.c
//extern	char timer_function[3];														// U_ModBusSio.c
//extern	char func_code[3];																// U_ModBusSio.c  + Modbus.c	
//extern	unsigned char byte_count_or_exception[3];					// U_ModBusSio.c  + Modbus.c
//extern	unsigned int first_reg[3];												// U_ModBusSio.c  + Modbus.c	
//extern	unsigned int cnt_regs[3];													// U_ModBusSio.c  + Modbus.c	
//extern	void* reg_address[3];															// U_ModBusSio.c  + Modbus.c
//extern	char modb_curr_adr[3];														// U_ModBusSio.c  + Modbus.c	
//
//#endif						

//--------------------------------------------------------------------------------------------------
// Benutzung der Funktion Test-RS485
// Aufruf durch HandlerS1, HandlerS2 oder HandlerS3 organisiert durch UserHandler
#if ( ((IMPLEMENT_S1 & GBUS1_IMPL) == GBUS1_IMPL) || ((IMPLEMENT_S2 & GBUS1_IMPL) == GBUS1_IMPL) || ((IMPLEMENT_S3 & GBUS1_IMPL) == GBUS1_IMPL) )

extern serial485	serial[3];

#endif

//--------------------------------------------------------------------------------------------------
// Benutzung der Funktion Funkempfang
// Aufruf durch HandlerS1, HandlerS2 oder HandlerS3 organisiert durch UserHandler
#if ( ((IMPLEMENT_S1 & FUNK1_IMPL) == FUNK1_IMPL) || ((IMPLEMENT_S2 & FUNK1_IMPL) == FUNK1_IMPL) || ((IMPLEMENT_S3 & FUNK1_IMPL) == FUNK1_IMPL) )

extern char ucReceiverTyp_RF;		//090310 0=NEU 1=ALT
extern char ucCond_RF;
extern char ucRxFlag_RF;
extern char ucChecksum_RF;
extern char ucBcounter_RF;
extern char ucfRxBuf_RF[12];
extern char ucRF_ComPort;				// mu� in den EEPROM
extern rfsens	rf_feld[12];
extern char ucTeach_idx;
extern char bedien_rf_nummer;
extern char funk_vis;

#endif

//--------------------------------------------------------------------------------------------------
// Grundfos-Pumpen mit GENIbus 
#if ( ( ( IMPLEMENT_S2 & GENI1_IMPL) == GENI1_IMPL ) || ( ( IMPLEMENT_S3 & GENI1_IMPL) == GENI1_IMPL ) )

// Neue Genibus Variablen
	extern GeniDeviceTable genibus_device_table[];		// ToDo: Const Basis Tabelle
	
	extern GeniValues Geni_Values[];
	
	extern unsigned char uc_geni_dummy_stat;
	
	extern unsigned char uc_genibus_device_nr;
	
	extern unsigned char ucf_genibus_rx_buffer[];
	extern unsigned char uc_genibus_rx_count;
	extern unsigned char uc_genibus_rx_buff_size;
	extern unsigned char uc_genibus_rx_errorflag;
	extern unsigned char uc_genibus_rx_error;
	extern unsigned char uc_genibus_rx_telegram_ready;
	extern unsigned char uc_genibus_rx_timeout_ctr;

	extern unsigned char uc_genibus_tx_count;
	extern unsigned char uc_genibus_tx_lenght;

	extern unsigned char uc_genibus_rts_prescaler; 
	extern unsigned char uc_genibus_rts_timer;
	
	extern unsigned char uc_genibus_state;
	extern unsigned char uc_genibus_special_function;
	
	extern unsigned char uc_genibus_own_adr;
	
	extern unsigned char uc_genibus_get_adress;
	extern unsigned char uc_genibus_reset_pump;
	extern unsigned char uc_genibus_reset_result;
	extern unsigned char uc_genibus_start_manual_request;	
	extern GeniManualRequest genibus_manual_request;
		
	extern unsigned char uc_genibus_request_table_idx;
	
	extern unsigned int  ui_genibus_relay_ctr;
	
	extern unsigned char uc_genibus_func_test;
#endif


#if ( GENI || WILO )

extern PuBusStandard BusPuPara[BUS_PU_MAX];
extern PuBusDynam BusPuData[BUS_PU_MAX];
extern char ssmBusPu;
extern char ssmPuCtr;

#endif


#if ( ((IMPLEMENT_S1 & MODBUS1_IMPL) == MODBUS1_IMPL) || ((IMPLEMENT_S2 & MODBUS1_IMPL) == MODBUS1_IMPL) || ((IMPLEMENT_S3 & MODBUS1_IMPL) == MODBUS1_IMPL) )
// F�r Modbus
extern unsigned int mbtest_out[];
extern char modb_curr_port;
extern char modb_power_on;
extern char modb_tsk_wdg_count;
extern char modb_bus_status;
extern char modb_leng_tx;
extern char modb_rts_prescaler;
extern char modb_rts_timer;	
extern char rq_idx;		// wegen parli temp. hier
extern char bus_tio_count;
extern char modb_state_control;	// Statemachine control 
extern char modb_rx_buff_size;
extern char modb_rx_status;
extern char modb_tx_count;
extern char modb_rx_count;
extern char modb_rx_buffer_ready;
extern char modb_rx_int_state;
extern char modb_rx_rxtio;
extern char modb_sio_errorflag;
extern char EoF_timer;
extern char bus_timeout_com;
extern char bus_timeout_com_shad;
extern char pu_timeout_com;
extern char timer_function;
extern char Bus_restart;
extern char cycle_timer;
extern char cycle_timer1;
extern char func_code;
extern char cycle_count;
extern char master_slave_func;
extern unsigned int first_reg;
extern unsigned int cnt_regs;
extern unsigned int modb_adr_offset;
extern char save_tx_count;
extern char modb_slave_idx;
extern char bit_value;
extern unsigned int reg_value;
//extern char tx_data_buff[];
extern char input_reg_idx;
extern char holding_reg_idx;
extern char modb_curr_adr;
extern char	SerialDeviceNr;
extern char TestHandMode;
extern char TaskTimer1;

extern modb_control_value	modb_control[MODB_SLAVE_MAX];

extern char TestpuMax;

#if ( WILO )

extern modb_data_value	modb_data[MODB_SLAVE_MAX];
extern int input_reg6_celsius[];
extern char SerialDeviceNr;
extern char ModbusSioWilo;			// WILO Pumpenparameter "C" SIO-Einstellung Parit�t und StopBit
extern char	ModbusBaudWilo;			// WILO Pumpenparameter "A" Baudrate immer 5 = 9600
#endif

#if ( BELIMO )
extern char modb_device_idx;
extern char Gateway_Device_idx;
extern char Gateway_Device_wr_idx;
extern unsigned char Gateway_Device_Present[DEVICE_MAX];
extern unsigned char Gateway_Device_Dissable[DEVICE_MAX];
extern unsigned int Modb_holding_reg[DEVICE_MAX][MODB_HOLDING_REGS];
extern unsigned int ModB_output_value[DEVICE_MAX][MODB_WR_HOLDING_REGS];
extern unsigned int ModB_out_value_shad[DEVICE_MAX][MODB_WR_HOLDING_REGS];
extern ULONG op_hours[DEVICE_MAX];
#endif

#if ( KWB_KESSEL )
extern char ModbusAlarm[MODB_SLAVE_MAX][256];
#endif

#endif

//----------------------------------------------------------------------------------------------------

// Variabler Kategorie-Typ
extern char KatVar_Typ[16];
// Info �ber Handschalter in ASCCI
extern char sw_stat_info[16];

// Index-Feld f�r Namenslisten R36, R37, R38, R33
extern unsigned int nlist[18];									// 18 Ein/Ausg�nge				R36
extern unsigned int n37list[R37_MODMAX][13];		// 13 Ein/Ausg�nge				R37 
extern unsigned int n38list[R38_MODMAX][14];		// 14 Analogeing�nge			R38
extern unsigned int n39list[R39_MODMAX][12];		// 12 Digitaleing�nge			R39
extern unsigned int n33list[R33_MODMAX][6];			//  6 Digitalausg�nge			R33

extern char ntext[18][21];											// 18 E/A je 20 ASCII
extern char n37text[R37_MODMAX][13][21];				// 13 Ein/Ausg�nge				R37 
extern char n38text[R38_MODMAX][14][21];				// 13 Ein/Ausg�nge				R37 
extern char n39text[R39_MODMAX][12][21];				// 12 Digitaleing�nge			R39
extern char n33text[R33_MODMAX][6][21];					//  6 Digitalausg�nge			R33

//Sichtbarkeitsspeicher f�r Parametergruppen
extern	char	anl_vis;		// Anlage
extern	char	ke_vis[];		// Kessel
extern	char	hk_vis[];		// Heizung
extern	char	ww_vis[];		// Warmwasser
extern  char	nt_vis[];		// Netztrennung
extern	char	so_vis[];		// Solar
extern	char	hkSoL_vis[];	// Solare Heizung ***AnFre

// #####ulsch
extern char	fer_vis;						// Ferienprogramm
extern char qsm_vis;						// Quittierbare Gespeicherte St�rmeldungen

extern	char	ze_vis[];					// Z�hler R36
extern	char	x1ze_vis[];				// Z�hler R37_1
extern	char	x2ze_vis[];				// Z�hler R37_2
extern	char	dia_vis;					// Diagnose
extern	char	zlt_vis;					// Datue
extern	char	syc_vis;					// Synchronisation Z�hler R36
extern	char	tes_vis;					// Test
extern	char	sys_vis;					// System
extern  char	r37vis[];
extern  char	r38vis[];
extern  char	r39vis[];
extern  char	r33vis[];

/***** ulsch : Heizgradtage *****/
extern char	hgt_vis;						// Heizgradtage

//Sichtbarkeitsspeicher f�r Parameter
extern	char	vis;							// Normal sichtbare Parameter
extern	char	hid1;							// Mit Service-Code 1	sichtbare Parameter	(135)
extern	char	hid2;							// Mit Service-Code 2	sichtbare Parameter	(137)
extern	char	hid3;							// Mit Service-Code 3	sichtbare Parameter	(143)
extern	char	hid4;							// Mit Service-Code 4	sichtbare Parameter	(139)
extern	char	kom;							// Nur f�r Komtab sichtbar
//***AnFre 12.12.2012 Sichtbarkeit der Anzeige Wilo-BusPumpen in den Gruppen
extern	char	wilo1;				// Pumpen-Index 1: Solarpumpe
extern	char	wilo2;				// Pumpen-Index 2: Pufferpumpe
extern	char	wilo3;				// Pumpen-Index 3: Ladepumpe
extern	char	wilo4;				// Pumpen-Index 4: Tauscherpumpe (oder Netzpumpe)
extern	char	wilo5;				// Pumpen-Index 5: Zirkpumpe

// Projekttyp 
extern char	proj_typ;					// Auswahl eines implemetierten Anlagen-Projektes
// Projekthilfsgr��en, Auswertung in "Output.c"
extern char temp_proj_typ;		// tempor�r (f�r Bedien) mit Pr�fung und Auswertung 
extern char	newproj;					// neues Projekt aktiviert (Z�hlzelle down bis Reset)
extern char	wpause[];					// Wechselpause zwischen AUF/ZU bei verriegelten Ausg�ngen
extern char	dadat;						// vom R50 R3X_DADAT-Kommando
extern char	dadat_cd;					// 						""		-Countdown
extern char	aadat[];					// vom R50 R3X_AADAT-Kommando
extern char	aadat_cd;					// 						""		-Countdown

// Typ und Version (wird geladen entsprechend proj_typ)
extern char Version_PTyp[];
extern char Version_PVers[];
extern char namur;

// Raumtemperaturen f�r verschiedene L�ftungskreise, �bertragung vom R50
extern mwsp raumtemp[];			
extern int  zuluft;
extern char ablufter;					// Anzahl der Abl�fter im Projekt

// ------------------- Pointer-Felder -------------------------------------------

// --------------------- Temperaturen Pt1000	(Felder von Zeigern auf pt_mewe[i])
extern mwsp *TA[];					// Aussentemp
extern mwsp *TVP[];					// Vorlauf  Prim�r
extern mwsp *TRP[];					// R�cklauf Prim�r

extern mwsp *TVS[];					// Vorlauf  Sekund�r
extern mwsp *TRS[];					// R�cklauf Sekund�r
extern mwsp *TI[];					// Raumtemperaturen

extern mwsp *TWWC[];				// Temperatur nach PW�
extern mwsp *TWW1L[];				// Speichertemp. 1 oben
extern mwsp *TWW2L[];				// Speichertemp. 2 unten
extern mwsp *TWWV[];				// Warmwassertemp.
extern mwsp *TWWP[];				// Temperatur vor PW�
extern mwsp *TWWZ[];				// Zirkulationstemperatur
// ***AnFre Station SEZ 40-200
extern mwsp *TW1_[];
extern mwsp *TW2_[];
extern mwsp *TW3_[];
extern mwsp *TW4_[];
extern mwsp *TS1_[];
extern mwsp *TS2_[];
extern mwsp *TS3_[];
extern mwsp *TS4_[];
extern mwsp *TS5_[];
extern mwsp *TS6_[];
extern mwsp *TS7_[];
// ***AnFre 31.10.2007: tats�chlich benutzte Temp.werte   (wegen ev. Temperaturfehler)
extern int ts1;
extern int ts2;
extern int ts3;
extern int ts4;
extern int ts5;
extern int ts6warm;
extern int ts7kalt;

extern int th2;	//***Anfre 06.06.2012
extern int th3;	//***Anfre 06.06.2012
extern int th4;	//***Anfre 06.06.2012
extern int th5;	//***Anfre 06.06.2012

extern mwsp *TVKE[];				// Vorlauf  Kessel
extern mwsp *TRKE[];				// R�cklauf  Kessel
extern mwsp *TVGKE[];				// Gemeinsamer Kesselvorlauf
extern mwsp *TRGKE[];				// Gemeinsamer Kesselr�cklauf

extern mwsp *TVSEK[];				// Vorlauf Sek. Netztrennung
extern mwsp *TRSEK[];				// R�cklauf Sek. Netztrennung
extern mwsp *TVSGNT[];			// Vorlauf Sekund�r gesamt
extern mwsp *TRSGNT[];			// R�cklauf Sekund�r WT gesamt
extern mwsp *TRPNT[];				// R�cklauf prim. Netztrennung

extern mwsp *TKOLL[];				// Temperatur am Solar-Kollektor
extern mwsp *TPUF1L[];			// Solar-Puffer-Temp. 1 oben
extern mwsp *TPUF2L[];			// Solar-Puffer-Temp. 2 unten
extern mwsp *TWWCSO[];			// Regeltemp.am Solar-�bertrager

extern mwsp *TP_UNI[];			// universeller Pt1000-Eingang

extern mwsp **mwpadr;				// Arbeitsspeicher

// ---------------------- Analogeing�nge 0-10V (Felder von Zeigern auf ae_mewe[i])
extern mwsp *LQF[];						// Beispiel: Luftqualit�tsf�hler
extern mwsp *AE_UNI[];
extern mwsp *ADAPT[];					// Adaptions-Kennwert

#if TAE_ANZ == 1
extern mwsp *TAE[];						// Au�entemperatur
extern int TaeSkalMin;
extern int TaeSkalMax;
#endif

#if TAA_ANZ == 1
extern int TaaSkalMin;
extern int TaaSkalMax;
#endif

#if ANFORD == 1
extern int TmanfSkalMin;
extern int TmanfSkalMax;
extern int TmanfSkalMinSpg;
extern int TmanfSkalMaxSpg;
#endif
 
// ---------------------- Digitaleing�nge			(Felder von Zeigern auf di_mewe[i])
extern dinpsp	*STBHK[];
extern dinpsp	*STBWW[];
extern dinpsp	*STWHK[];
extern dinpsp	*STWWW[];
extern dinpsp	*WWUW[];				
extern dinpsp	*WWOW[];
extern dinpsp	*KEAL[];					// Kesselalarm Si-Kette
extern dinpsp	*BRAL[];					// Brenneralarm 
extern dinpsp	*NACHSP[];				// Nachspeisung
extern dinpsp	*PUAL[];					// Pumpenst�rung 
extern dinpsp* PUWZAL[];				// Pumpenstoerung Zirkulationspumpe (Sammelmeldung)
extern dinpsp* PUWLAL[];				// Stoermeldung (Ent-)Ladepumpe
extern dinpsp* STBWWSP[];				// Stoermeldung STB Speicher
extern dinpsp	*BMKES[];					// Betriebsmeldung Kessel
extern dinpsp	*PUSAMAL[];				// Sammelmeldung Pumpenst�rung
extern dinpsp	*STBNT[];					// Sicherh.temp.begrenzer Netztrennung
extern dinpsp	*STWNT[];					// Sicherh.temp.w�chter Netztrennung
extern dinpsp	*RKZUNT[];				// RM Klappe ZU NT
extern dinpsp	*RKAUFNT[];				// RM Klappe AUF NT
extern dinpsp	*DRMAXNT[];				// Max-Druck NT
extern dinpsp	*DRMASNT[];				// Max-Druck NT sek.
extern dinpsp	*DRMISNT[];				// Min-Druck NT sek.
extern dinpsp	*RVZUNT[];				// RM Ventil ZU NT
extern dinpsp	*SAMAL[];					// Sammelst�rmeldung allgemein
extern dinpsp	*PUWTAL[];				// Stoermeldung Tauscherpumpe
extern dinpsp	*FRGHK[];					// Freigabe Regelung Heizkreis
extern dinpsp	*FERINP[];				// Ferienschalter
extern dinpsp	*DE_UNI[];
extern dinpsp	*SM_UNI[];				// universeller Digitaleingang f�r St�rmeldungen
extern dinpsp	*BM_UNI[];				// universeller Digitaleingang f�r Betriebsmeldungen
extern dinpsp	*PUKEAL[];
extern dinpsp	*BMPUKE[];			// Betriebsmeldung Kessel/Zubringer-Pumpe

extern dinpsp	*BMPU[];			// Betriebsmeldung Heizungspumpe
extern dinpsp	*BMPUWL[];		// Betriebsmeldung Ladepumpe
extern dinpsp	*BMPUWZ[];		// Betriebsmeldung Zirkulationspumpe
extern dinpsp	*BMPUWT[];		// Betriebsmeldung Tauscherpumpe
extern dinpsp	*HKAUS[];			// Anlagenschalter Nichtnutzung HK 
extern dinpsp	*WWAUS[];			// Anlagenschalter Nichtnutzung WWB
extern dinpsp	*QUITTS[];		// Quittierungstaste
extern dinpsp	*SSFKE[];			// Schornsteinfegertaste
extern dinpsp	*STBKE[];			// Sicherh.temp.w�chter Kessel
extern dinpsp	*DRKE[];			// SM Max-Druck Kessel
extern dinpsp	*ADAPT_T[];		// Adaptionsmeldung "zu tief"
extern dinpsp	*ADAPT_H[];		// Adaptionsmeldung "zu hoch"
#if ( PUDO == 1 )
	extern dinpsp	*PUDAL[HKMAX];	// Pumpenst�rung, Doppelpumpe
#endif
extern dinpsp	*PUALNT[];			// Pumpenst�rung Hauptpumpe
// ***AnFre
extern dinpsp	*BMPUSOL[];		// Betriebsmeldung Solar-Pumpe
extern dinpsp	*BMPUPUF[];		// Betriebsmeldung Puffer-Pumpe
extern dinpsp	*BMPUNT[];		// Betriebsmeldung Netz-Pumpe

extern dinpsp	**dipadr;				// Arbeitsspeicher

// ---------------------- Z�hleing�nge R36			(Felder von Zeigern auf zaehler[i])
extern zaehlsp *ZE[8];
// ---------------------- Z�hleing�nge R37_1		(Felder von Zeigern auf zaehler[i])
extern zaehlsp *X1ZE[6];
// ---------------------- Z�hleing�nge R37_2		(Felder von Zeigern auf zaehler[i])
extern zaehlsp *X2ZE[6];
 
// MBus: 3 Z�hler
#if MBUSANZ > 0
extern zaehlsp	mbZaehler[];								// Z�hleing�nge
extern zaehlsp *MBZE[];
#endif

// ---------------------- Analogausg�nge				(Felder von Zeigern auf Aout[i])
extern aasp *AA_UNI[];
extern aasp *RVENT[];						// Regelventil f�r Heizkreise
extern aasp *RVENTWW[];					// Regelventil f�r Warmwasser
extern aasp *RVENTKE[];					// Regelwert f�r Kessel
extern aasp *RVENTKR[];					// Regelventil f�r Kesselr�cklauf-Anhebung
extern aasp *DZPUKE[];					// Drehzahl Kesselpumpe
extern aasp *AASSTM[];					// Sammelst�rmeldung Analogausgabe
extern aasp *PUWZ[];						// Drehzahl Warmwasser-Zirkulationspumpe
extern aasp *PUWL[];						// Drehzahl Ladepumpe (HAST-AKKU : Entladepumpe )
extern aasp *RVENTSP[];					// Strahlpumpe Warmwasser
extern aasp *RVENTMI[];					// Mischer Warmwasser
extern aasp *RVENTNT[];					// Regelventil Netztrennung
extern aasp *RVENTSO[];					// Regelventil WW-Solar
// ***AnFre
extern aasp *MVSOLWW[];					 // MotorVentil Solar-WW
extern aasp *MVKALTW[];					// MotorVentil Kaltwasser

#if TAA_ANZ > 0
extern aasp *TAA[];								// Au�entemperatur
#endif

#if ANFORD > 0
extern aasp *TMANF[];
#endif

extern aasp **aapadr;			// Arbeitsspeicher

// ---------------------- Relaisausg�nge				(Felder von Zeigern auf Dout[i])
extern doutsp *RZU[];						// HK Stellventile zufahren
extern doutsp *RAUF[];					// HK Stellventile auffahren
extern doutsp *RWWZU[];					// WW Stellventil zufahren
extern doutsp *RWWAUF[];				// WW Stellventil auffahren
extern doutsp *PU[];						// Heizungspumpen
extern doutsp *PUMIN[];					// Minimaldrehzahl
extern doutsp *PUWLEA[];				// Ladepumpen 
extern doutsp *PUWZEA[];				// Zirkulationspumpen
extern doutsp *ELVENT[];
extern doutsp *PUGWW[];
extern doutsp *SSTM[];					// Sammelst�rmeldung
extern doutsp *KESTU1[];				// Kessel Brennerstufe 1
extern doutsp *KESTU2[];				// Kessel Brennerstufe 2
extern doutsp *KE[];						// Kessel Freigabe
extern doutsp	*KLKEAZ[];				// Kesselabsperrklappe AUF/ZU
extern doutsp	*PUWTEA[];				// Tauscherpumpe
extern doutsp	*RNTZU[];					// Netztrennung Regelventil zufahren
extern doutsp	*RNTAUF[];				// Netztrennung Regelventil auffahren
extern doutsp	*KLNTAZ[];				// Tauscher-Absperrklappe AUF/ZU
extern doutsp	*FEROUT[];				// Ferienstatus
//ulsch
extern doutsp	*DA_UNI[];
extern doutsp	*MKEZU[];					// Kessel Modulation ZU
extern doutsp	*MKEAUF[];				// Kessel Modulation AUF
extern doutsp	*RKEZU[];					// R�cklauf-Anhebung: Kesselkreis ZU
extern doutsp	*RKEAUF[];				// R�cklauf-Anhebung: Kesselkreis AUF
extern doutsp	*PUKEEA[];				// Kesselpumpe
extern doutsp	*PUKOLEA[];				// Solar-Kollektor-Pumpe
extern doutsp	*PUSOEA[];				// Solar-Pumpe
//ulsch
extern doutsp	*KLKEZU[];				// Kesselabsperrklappe ZU
extern doutsp	*KLKEAUF[];				// Kesselabsperrklappe AUF
// ***AnFre
extern doutsp	*PUSOLEA[];				// Solar-Kreis-Pumpe
extern doutsp	*PUPUFEA[];				// Solar-Puffer-Pumpe
extern doutsp	*MVKOLEA[];				// ***AnFre MotorVentil Kollektor 
extern doutsp	*MVPUFEA[];				// ***AnFre MotorVentil Kessel/Puffer 
extern doutsp	*MVWLEA[];				// ***AnFre MotorVentil Ladepumpen 

#if PUDO == 1 
	extern doutsp	*PUD[];					// Heizungspumpen, Doppelpumpe
#endif

extern doutsp	*PUNTEA[];				// Pumpe Netztrennung (Hauptpumpe)
extern doutsp	*UVHKEA[SOMAX];			// ***AnFre 31.01.2008 Umschalt-Ventil HK1: Kessel/Puffer 
extern doutsp	*UVWWEA[SOMAX];			// ***AnFre 23.04.2009 Umschalt-Ventil TWW-Solar 

extern doutsp	**dopadr;					// Arbeitsspeicher

//--------------------------------------------------------------
// Speicherpl�tze f�r R37-In/Out-Modul und R38-PT1000-Modul
//-------------------------------------------------------
extern Ram37	mod37[];			// maximal 4 (dann keine weiteren Module)
extern Ram38	mod38[];			// maximal 4 (dann keine weiteren Module)
extern Ram39	mod39[];			// maximal 4 (dann keine weiteren Module)
extern Ram33	mod33[];			// maximal 4 (dann keine weiteren Module)
extern char mod39sysinit;		// Merkmal f�r SysEEP_InitUser  (Kaltstart 66 wurde ausgef�hrt)	
																	
extern char proc_IO;									// Auftragsmerker
extern char iocnt;										// Counter �ber maximal 4 Module
extern char oready;										// Flag: wenn Output-Task abgelaufen
//--------------------------------------------------------------

// Sammelst�rmeldung f�r Anzeige und LT
extern char sstm[];				// Feld mit Z�hlerst�nden der jeweiligen Sammelalarmklasse, Index entsprechend userdef.h 
extern char sstm_old[];		// Merker f�r Event.c (Erh�hung des Z�hlerstandes bei Sammelalarmen (neuer Alarm) )

// Schaltpause f�r statische Relais, wenn mehrere Relais gleichzeitig einschalten wollen
extern char Schalt_Pause;		// Sekunden
extern char schalt_count;

/*-------------- Absenkung nach Zeit f�r mehrere Heizkreise --------------*/
extern char	 abx;									// Reglerindex f�r Absenkung
extern char	 setwoche[];			// Schalter Absenkzeiten"Woche" kopieren auf alle Tage
extern absenktab abs_tab[][8];	// Absenkzeiten und Temperaturen
/*-------------- Absenkung bei Bedarf f�r mehrere Heizkreise -------------*/
extern char	 bex;								// Reglerindex f�r Bedarfs-Absenkung


/*-------------------- Steuer ----------------------------------------*/

// Skalierungswerte f�r Analogausgabe R36
extern aask		AASkal[];		// Grundwerte (EEPROM gest�tzt, Voreinstellung in UserReply.c bei Kaltstart 66)
extern UINT		AoutSk[];		// aktuelle skalierte Ausgabewerte; Umrechnung Aout[i]->awert nach AoutSk[i] in Output.c

// ged�mpfte Au�enlufttemperatur 
extern mwsp		ta1m;				// ged�mpfte Au�entemp.
//extern float	fl_ta1m;		//		"								(f�r Filterberechnung) ist im Noinit-Rambereich
extern char		Ta1mzk;			// Filterzeitkonstante 				[min]
extern char		steustart;	// Steuerstart nach Reset

extern mwsp  bcta;				// Broadcast Au�entemp. + Status
extern char  bc_vorra;		// Vorrang Broadcast-Au�entemp.
extern char  bc_flag;			// Flag = 1 wenn ta von bcta abstammt 
extern char  bc_simu;			// Simulation eines BCTA1-Kommandos
extern mwsp  ta;					// Arbeitsspeicher f�r Au�entemperatur

// gemittelte Au�enlufttemperatur �ber Stunden
extern mwsp		ta1mh;			// ged�mpfte Au�entemp. + Status
//extern float	fl_ta1mh;		//		"			(f�r Filterberechnung) ist im Noinit-Rambereich
extern int		ta1mh_temp;	// Eingebbarer Parameter zum Einstellen der ged�mpften Ta 

extern char		Ta1mhzk;		// Filterzeitkonstante 				[h]
extern char		zzta1mh;		// Z�hler f�r Tastzeit
extern char		zzsave;			// Zeitz�hler f�r Ablage im EEPROM 

// Sommer Winter,	zentrale Parameter in ANL
extern int		Tae;			// Temp. Winter ein						 [�C] * 10	
extern int		Taa;			// Temp. Sommer aus						 [�C] * 10	
extern char		sowi;			// 1 = Sommer
// ***AnFre
extern char	SomBegin[];	// Datum Sommer-Anfang [Tag,Monat]
extern char	SomEnd[];		// Datum Sommer-Ende	 [Tag,Monat]

extern char		Klima;			// Klimaschutz
extern int		DTKlima;		// Absenkung Klima

#if ANF_EXT > 0
extern mwsp anfExt[];							// Anforderung �ber Bus
#endif

extern int maxAnford;

/*--------------- Reglerparameter f�r alle Heizkreise ----------------------*/
//	Die Parameternamen sind in den Strukturdefinitionen festgelegt (ustruct.h) 

// Statische Parameter (mit Standdardwerten)	
//   Der Bereich wird gef�llt:
//	 a)nach Kaltstart aus der Liste mit Standardwerten (in UserConst.c)
//		 (Transport mit Funktion "Typelist_copy()" in UserReply.c)
//	 b)nach Reset mit Werten aus EEPROM
//		 (Transport mit Funktion "Ram__Bicram(0)" in Main.c )
extern HkStandard	hks[];	

// Dynamische Parameter
//	 Der Bereich dient als Arbeitsspeicher f�r die Regelprogramme
extern HkDynam		hkd[];

/*--------------- Reglerparameter f�r Solare Heizkreise  ***AnFre---------------*/
// Statische Parameter (mit Standdardwerten)	
extern HkSoLStandard	hksSoL[];	
// Dynamische Parameter
extern HkSoLDynam			hkdSoL[];

/*--------------- Reglerparameter f�r mehrere Warmwasserkreise -------*/
// Statische Parameter (mit Standdardwerten)	
//   Der Bereich wird gef�llt:
//	 a)nach Kaltstart aus der Liste mit Standardwerten (in UserConst.c)
//		 (Transport mit Funktion "Typelist_copy()" in UserReply.c)
//	 b)nach Reset mit Werten aus EEPROM
//		 (Transport mit Funktion "Ram__Bicram(0)" in Main.c )
extern WwStandard	wws[];	

// Dynamische Parameter
//	 Der Bereich dient als Arbeitsspeicher f�r die Regelprogramme
extern WwDynam		wwd[];

//--------*** AnFre ***-----------------------------------------------------
/* Struktur der Profilparameter eines Warmwasserkreises				*/
// Teil1: Statische Parameter (mit Standdardwerten)
extern PrStandard prs[];
// Dynamische Parameter
//	 Der Bereich dient als Arbeitsspeicher 
extern PrDynam		prd[];

/*--------------- Reglerparameter f�r mehrere Kesselkreise -------*/
// Statische Parameter (mit Standdardwerten)	
//   Der Bereich wird gef�llt:
//	 a)nach Kaltstart aus der Liste mit Standardwerten (in UserConst.c)
//		 (Transport mit Funktion "Typelist_copy()" in UserReply.c)
//	 b)nach Reset mit Werten aus EEPROM
//		 (Transport mit Funktion "Ram__Bicram(0)" in Main.c )
extern KeStandard	kes[];

// Dynamische Parameter
//	 Der Bereich dient als Arbeitsspeicher f�r die Regelprogramme
extern KeDynam		ked[];

/*--------------- Reglerparameter f�r mehrere Vorregelkreise (Netztrennung)------*/
//	Die Parameternamen sind in den Strukturdefinitionen festgelegt (ustruct.h) 

// Statische Parameter (mit Standdardwerten)	
//   Der Bereich wird gef�llt:
//	 a)nach Kaltstart aus der Liste mit Standardwerten (in UserConst.c)
//		 (Transport mit Funktion "Typelist_copy()" in UserReply.c)
//	 b)nach Reset mit Werten aus EEPROM
//		 (Transport mit Funktion "Ram__Bicram(0)" in Main.c )
extern NtStandard	nts[NTMAX];	

// Dynamische Parameter
//	 Der Bereich dient als Arbeitsspeicher f�r die Vorregelprogramme
extern NtDynam			ntd[NTMAX];


/*--------------- Reglerparameter f�r Solar-Regelung -------------*/
extern SoStandard	sos[SOMAX];
extern SoDynam	sod[SOMAX];
// ***AnFre 
extern char NotBetr;		//Anzeige Notbetrieb
extern UINT NotTage;		//Anzahl Tage bis Notbetrieb
// ***AnFre 
extern char zirkMax;	//Anzeige WW-Zirkulation zu warm
extern char speicherMax;	//Anzeige WW-Speicher zu warm
//char speicherAlarm_sp;	//Quittierbarer Alarm
extern char pufferMax;	//Anzeige  Solar-Puffer zu warm
//char pufferAlarm_sp;	//Quittierbarer Alarm
extern char pusoTempAl;		// Solarpumpe Temp.Alarm
//char pusoTempAl_sp;
extern char v2MinAlarm;	//Anzeige Koll.Vol.Strom minimal
//char v2MinAlarm_sp; //Quittierbarer Alarm
extern char pusoFrostAl;		// Solarpumpe Frost-Alarm
// ***AnFre in Alarme.c als static definiert char zVolAlarm;		// Z�hler bis Alarm EIN
extern char kwzDefekt;		// Kaltwasser-Z�hler defekt
// ***AnFre externe HAST-Alarme
extern char ext1SammelSM;	//Anzeige EXT 1: Sammel-Alarm HKV
extern char ext2SammelSM;	//Anzeige EXT 2: Sammel-Alarm WPU
extern char ext3SammelSM;	//Anzeige EXT 2: Sammel-Alarm KES 02.10.2012
// ***AnFre externer SSM Bezeichnung �ndern
extern char extAlarmText[];

/*--------------- Alarmtabelle -----------------------------------*/
extern AlarmVar	alarmtab[];

extern char quit_taste;
extern char un_qsm;							// 1 = Unquittierte St�rungen vorhanden
extern char unbek_Alarm;				// unbekannter Alarm (alarmtab - Index)

extern UINT alarmlist_dae[];		// aktuelle Alarme in einer Liste merken (f�r RFB):  2 Byte DAE-Nummer
extern char alarmanz_dae;

/*---------------- Z�hlerspeicherung pro Monat ------------------------*/
extern char	std_old;
extern char	monza_first;
extern char	monza_znum;
// Rest verlagert nach unoinitext.h

/***** ulsch : Archivparameter *****/
extern char arch_par;						// char = UCHAR !	
extern char	arp_vis;
extern char archivAktiv;
extern char ParaBuffer[];

/***** ulsch Adaption*****/
/*---------------- Adaption --------------------------------------------------------*/
extern char mwAdapt[HKMAX][ADAP_STAT_MAX];		// uebermittelte Werte 2,5,8
extern char adapt_countdown[];								// Wert in min, empfangen vom R50 �ber Kommando WR_ADAKENNZ

#if ( ADAP_STAT_HK1 > 0 || ADAP_STAT_HK2 > 0 || ADAP_STAT_HK3 > 0 || ADAP_STAT_HK4 > 0 )
extern mwsp mwAdaption[HKMAX][ADAP_STAT_MAX];	// Kopie von mwAdapt mit selbst gebildetem Status ( Datenuebertrag.fehler .stat = 1 )
extern char AdaptMeldg[HKMAX][16];
extern int AdaptKorr[HKMAX][10];							// 10 temperaturspez.Adaptionswerte fuer -25 grd C ...+20 grd C, in 0,1 grd
extern char tvsHigh[];												// Zaehler zur Ueberwachung der Vorlauf-Temperatur
extern char tvsLow[];
extern char tvsNormal[];
extern char leistgLow[];											// Zaehler
extern char leistgHigh[];
#endif

/***** ulsch : Ferienprogramm *****/
extern char ferienStat;					// Zustand Ferien	
extern ferienZeit ferien[];			// Feld fuer 10 Ferien-Termine

extern char absenkStat;					// Zustand Absenkung

/***** ulsch : Heizgradtage *****/
#if HEIZGRD == 1
extern char indexMon;
extern int ta7;
extern int ta14;								// Speicherplatz unmittelbar nach ta7 !
extern monHzGrd sMonHzGrd;
extern monHzGrd sMonHzGrdAnz;
extern char merkerStd;
extern char monHzGrdAnz;
#endif

/***** ulsch : Waermemenge, Diagnose *****/
#if WMENG > 0
extern zaehlspWmeng wmengCtr[];
#endif

#if ( LEIST_BER > 0 )
extern maxLeistung MaxLeistung[];
#endif

#if ( LEIST_BEGR > 0 )
extern grenzLeistungStat GrenzLeistung;
extern grenzLeistungDyn grenzLeistung;
extern UINT AnzahlBegrenzung;
extern UINT DauerBegrenzung;
#endif

// ***AnFre : Kaltwasser TWW *****
extern zaehlspVolstr volstrCtr;	
// ***AnFre 03.09.2009 Diagnose KWZ
extern diagnoseKWZ kwd;											// dyn. Parameter
extern diagParamKWZ kws;										// stat. Parameter
extern char ZeitLoesch; 											// Zeiten l�schen (auch bei KS66=1)
extern ULONG timeDiff;			// Zeit-Zaehler 100ms
extern ULONG lasttimeDiff;	// Zeit-Zaehler letzter Impuls 100ms

#if DIAG == 1	
extern diagnose did;
extern diagParam dis;

// ***AnFre 06.06.2012 RL HK1: TH2
extern UINT TH2MittelZaehler;			// Minuten-Z�hler Mittlere TH2 diesen Monat (max. 44640)
extern UINT TH2Mittel[];					// Mittlere TH2 Jan. bis Dez.
extern UINT TH2MittelVJ[];				// Mittlere TH2 Vorjahr Jan. bis Dez.
extern ULONG TH2MittelSumme;
extern char TH2MittelMonAlt;				// Mittlere TH2 alter Monat
extern char TH2MittelJahrAlt;			// Mittlere TH2 altes Jahr
// ***AnFre 06.06.2012 RL Netz: TN2
extern UINT TN2MittelZaehler;			// Minuten-Z�hler Mittlere TH2 diesen Monat (max. 44640)
extern UINT TN2Mittel[];					// Mittlere TH2 Jan. bis Dez.
extern UINT TN2MittelVJ[];				// Mittlere TH2 Vorjahr Jan. bis Dez.
extern ULONG TN2MittelSumme;
extern char TN2MittelMonAlt;				// Mittlere TH2 alter Monat
extern char TN2MittelJahrAlt;			// Mittlere TH2 altes Jahr
#endif

//#####josch:
extern copydata CopyData[];
extern char		 	LeerData[];
extern int			CopySend[];
extern int			LeerSend[];

// ***AnFre: R101-Copy entfernt
//extern mwsp SSM_Ext1;						// HAST 1: Sammelst�rung  �ber Bus	(R101-Copy)
//extern mwsp ANF_Ext1;						// HAST 1: Sollwert-Anforderung  �ber Bus	(R101-Copy)
//extern mwsp SSM_Ext2;						// HAST 2: Sammelst�rung  �ber Bus	(R101-Copy)
//extern mwsp ANF_Ext2;						// HAST 2: Sollwert-Anforderung  �ber Bus	(R101-Copy)

// Sollwert-Anforderung von Daten-Manager	***AnFre 19.04.2012
extern mwsp DM_ANF_Ext1;					// HKV 1: Sollwert-Anforderung  �ber S1/S2
extern mwsp DM_ANF_Ext2;					// HKV 2: Sollwert-Anforderung  �ber S1/S2
extern mwsp DM_SSM_Ext1;					// HKV 	: Sammelst�rung 				 �ber S1/S2
extern mwsp DM_SSM_Ext2;					// WPU	: Sammelst�rung 				 �ber S1/S2
extern mwsp DM_SSM_Ext3;					// KES	: Sammelst�rung 				 �ber S1/S2

extern mwsp DM_WPU_Frei;					// WPU-Freigabe
extern mwsp DM_WPU_Ventil;				// WPU Stellung Regelventil HK1

// Ausgew�hlte (g�ltige) Sollwert-Anforderung	***AnFre 21.01.2009
extern mwsp ExtAnf1;	// von Unterstation 1
extern mwsp ExtAnf2;	// von Unterstation 2

// ***AnFre
extern UINT	CO2_Faktor;				// CO2-Faktor 0,000 [kg/kWh]
extern ULONG	CO2_Einspar;			// CO2-Einsparung in 0 kg
extern char	Tyfocor;					// Anteil Tyfocor in Vol.% (nur 40, 50 oder 60)
// ***AnFre 30.04.2014: Korrekturwert f�r WZx Vorlauf- R�cklauf-Temperatur	[ 0,1 K ]
// spezielle Behandlung in WmengSolar.c
extern mwsp	WZxTV[];					//  WZx: Vorlauf zur Anzeige
extern int		WZxTVKorr[];		//	WZx: Vorlauf
extern int		WZxTVKorrAlt[];
extern mwsp	WZxTR[];					//  WZx: R�cklauf zur Anzeige
extern int		WZxTRKorr[];		//	WZx: R�cklauf
extern int		WZxTRKorrAlt[];

extern char ssfEinAnl;	// Schornsteinfeger-Funktion ( KE1 OR KE2 )	

#if TAE_ANZ == 1
extern mwsp ta_ae;
extern int TaeSkalMin;
extern int TaeSkalMax;
#endif

#if TAA_ANZ > 0
extern int TaaSkalMin;
extern int TaaSkalMax;
#endif

#if ANFORD == 1
extern int TmanfSkalMin;
extern int TmanfSkalMax;
extern int TmanfSkalMinSpg;
extern int TmanfSkalMaxSpg;
#endif
 
extern sAnaInpPara AnaInpPara[AE_UNI_ANZ];
extern sAnaInp anaInp[AE_UNI_ANZ];

// ***** josch: Datenmanager ***************************************************************
// Ger�t im DS_Modus (Data Slave),	Auswertung in der Funktion DReply() 
#if DS_MODE == 1
extern char DS_RxBuf[DS_RXBUF_MAX];				// vom Master empfangene Daten
extern char DS_RxTout;										// Timeout in Minuten
extern char DS_RxStat;										// Status der Empfangsdaten
extern char DS_TxBuf[DS_TXBUF_MAX];				// an den Master zu sendende Daten
extern char DS_TxLeng;										// Datenanzahl zu senden

// Empfangene Daten vom Master (Variable m�ssen vom Typ mwsp sein)
extern mwsp zentrale_ea;									// Beispiel f�r 1 Byte: Ein/Aus              
extern mwsp zentrale_istwert;							// Beispiel f�r 3 Byte: Temperatur mit Status
extern mwsp zentrale_sollwert;						// Beispiel f�r 2 Byte: Sollwert             

#endif

// Ger�t im DM_Modus (Data Master),	Datenbearbeitung in der Funktion DManager(), Organisation der Daten�bertragung im Task DTimer() 
#if DM_MODE == 1
extern dm_param DM[DM_SLAVES];						// DM Struktur
extern char dtslave;											// DTimer aktueller Slave
extern char dtstate;											// DTimer aktueller Bearbeitungsstatus
extern char dtauftrag;										// DTimer aktueller Auftrag
extern char proc_TI;											// DTimer Auftragsmerker 
extern char Slave[4];											// Slave 1 - 4 Adressen

// Empfangene Daten von den Slaves  (Variable m�ssen vom Typ mwsp sein)
extern mwsp station1_ea;									// Beispiel f�r 1 Byte: Ein/Aus              
extern mwsp station1_istwert;							// Beispiel f�r 3 Byte: Temperatur mit Status
extern mwsp station1_sollwert;						// Beispiel f�r 2 Byte: Sollwert             

	#if DM_SLAVES > 1
extern mwsp station2_ea;			
extern mwsp station2_istwert;
extern mwsp station2_sollwert;
	#endif

#endif

//***** josch: Archiv mit SD-Card-Memory ***************************************************//
#if ARCHIV_SDM == 1
extern UINT	werks_sdm_code;						// Code eingeben f�r Werkseinstellung
extern UINT	sdm_akt_dae;
extern char	a_sperre;
extern char	sdm_arch_stop;						// Benutzer-Stopp (1), wird gesichert in Standard.c 
extern char	mount_check;
extern char	test_start;
extern char	sdm_base_check;
extern char	sdm_alarm_check;

// Funktion: Zeitmessung (in Upro.c)
// IN:       char  onoff ...ON (1=Start), OFF ( 0=Stop)
// OUT:      ULONG Zeit.....ms
#if ZEIT_MESSUNG == 1
extern ULONG read_zeit;
extern ULONG write_zeit;	
extern ULONG write_zeit_max;
#endif

extern char	c_erg_gl;									// Ergebnis der Card-Zugriffe ver�ffentlichen in der parli
extern char c_erg_text[16];
extern char	a_erg_gl;									// Ergebnis der Archivierung  ver�ffentlichen in der parli
extern char a_erg_text[16];
extern char	cardType;
extern char	speedClass;
extern char	performanceMove;
extern char ferro_err;
extern char card_err;

extern char	bic_err;
extern char	asdm_status;
extern char	asdm_action;
extern char	sdm_ret;										// Fehleranzeige
extern char	asdm_minut;
extern ULONG asdm_time;									// Zeitmarke aktuell
extern ULONG read_time;									// Zeitmarke: Erster Zeitstempel der Datenpage, deren Eintrag in der Verweispage fehlt
extern char asdm_buffer[64];						// Puffer f�r Zeitstempel und Datenwert
extern char	asdm_page[512];							// Puffer f�r eine Page
extern ULONG timeout_max;

extern UINT	current_dae;
extern char	current_dae_exp;
extern char	max_expand;
extern char	exp_index;
extern UINT	dae_append;
extern UINT	komtab_changed;
extern char	daily_init;
extern int  reset_dae;									// ferro Init f�r ein DAE

extern UINT	ferro_adr;
extern UINT	ferro_mnext;
extern UINT	ferro_msize;
extern ferro_info	dae_info[1];
extern ferro_info *exp_ferro_tab[256];			// Pointer auf Expanddaten-Tabelle im alloziierten Ferro-Bereich

// DAE Archivierung
extern ULONG hp_adr;										// aktuelle Adresse der Hauptpage.    Anzahl 1
extern ULONG vp_adr;										// aktuelle Adresse der Verweispage.  Anzahl 15
extern ULONG dp_adr;										// aktuelle Adresse der Datenpage.    Anzahl 2032
extern ULONG sdm_mnext;									// Expand-Allocation: n�chster freier Platz
extern ULONG sdm_msize;									// Expand-Allocation: Gr��e des verf�gbaren Speicherbereiches
extern ULONG exp_sdm_tab[256];					// Expand-Allocation; die Expanddaten-Tabelle enth�lt alle alloziierten Hauptpage-Adressen

// DAE Suche
extern ULONG search_hp_adr;							// gefundene Adresse der Hauptpage.
extern UINT  search_vp_num;							// gefundene Verweispagenummer in der Hauptpage (1-15)
extern ULONG search_vp_adr;							// gefundene Adresse der Verweispage.
extern UINT  search_dp_num;							// gefundene Datenpagenummer in der Verweispage (1-2032)
extern ULONG search_dp_adr;							// gefundene Adresse der Datenpage.
extern UINT  search_ts_num;							// gefundene Zeitstempelnummer in der Datenpage
extern char	 sd_buf[512];								// Puffer f�r eine Page

#if SPEED_SAVE == 1			//$ Test
extern ULONG asdm_test_start;
#endif

#endif	// ARCHIV_SDM == 1

// ***AnFre : Kaltwasser TWW *********************************************/
extern zaehlspVolstr volstrCtr;	
// ***AnFre 03.09.2009 Diagnose KWZ
extern diagnoseKWZ kwd;											// dyn. Parameter
extern diagParamKWZ kws;										// stat. Parameter
extern char ZeitLoesch; 											// Zeiten l�schen (auch bei KS66=1)
extern ULONG timeDiff;			// Zeit-Zaehler 100ms
extern ULONG lasttimeDiff;	// Zeit-Zaehler letzter Impuls 100ms


extern UINT	CO2_Faktor;				// CO2-Faktor 0,000 [kg/kWh]
extern ULONG	CO2_Einspar;			// CO2-Einsparung in 0 kg
extern char	Tyfocor;					// Anteil Tyfocor in Vol.% (nur 40, 50 oder 60)

#endif	// URAMEXT_H_INCLUDED

