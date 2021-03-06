
/*    UserConst.c															*/

/*    Konstanten im Flash-Bereich des Users		*/

#include "struct.h"
#include "ustruct.h"
#include "standdef.h"
#include "userdef.h"
#include "uramext.h"

/* User-Compilierungszeit und Datum	*/
const char user_compile_time[15] = __TIME__;
const char user_compile_date[15] = __DATE__;

	/* Typ und Version des gesamten Projektes												*/
//									             				 "---------------"
	const char Kategorie_Typ[16] 				= {"JMX71: KESSEL  "};  //genau 15 Zeichen
	const char Kategorie_Vers[3] 				= {17,4,4};           	//Jahr, Monat, Tag

	const char Proj_Typ = 1;		// konstantes Projekt, f�r variable Proj. auf 0 setzen

// Unterschriften in der 2.Zeile
const char Zsync[16]								= {"SYNCHRONISIEREN"};
const char Leitstr[16]							= {"RS485, MODEM   "};
const char Ein_Ausg[16]							= {"EIN-/AUSGAENGE "};
const char DMmod1[16]								= {"SLAVE 1: HKV   "};	// ***AnFre 19.04.2012 DatenManager 06.06.2012 HeizKreisVerteiler
const char DMmod2[16]								= {"SLAVE 2: W-PUM."};	// ***AnFre 19.04.2012 DatenManager	06.06.2012 W�rmepumpe
const char DMmod3[16]								= {"SLAVE 3: KESSEL"};	// ***AnFre 19.04.2012 DatenManager	06.06.2012 Kessel-Kaskade
const char Kes1[16]									= {" 1-stufig      "};
const char Kes12[16]								= {" 2-stufig      "};
const char Kesmod[16]								= {"SOLLWE.-VORGABE"};
const char KeViess[16]							= {"Viessmann Kask."};
const char KesBegr[16]							= {"ANHEBUNG       "};
const char KesAllg[16]							= {" allg.Parameter"};
const char KesPu[16]								= {" Drehzahl      "};
const char Ntmod[16]								= {"SEKUND-REGELUNG"};
const char KesTyp[8][16]	= {
	{"               "},
	{"               "},
	{"               "},
	{"               "},
	{" modulierend   "},
	{" Sollwert      "},
	{" 1-stufig      "},
	{" 2-stufig      "},
};	

const char Hkmod_fuss[16]						= {"FUSSBODEN      "};

const char Hkmod[4][16]	= {
	{"mit HKS: SOLAR "},
	{"               "},
	{"               "},
	{"               "},
};	
const char Hkmod_SoL[16]						= {"SOLAR-EINSPEIS."};	//***AnFre

const char Wwmod[16]								= {"DURCHFLUSS     "};
const char Solmod[16]								= {"TWE und HEIZUNG"};
const char Sosmod[16]								= {"               "};
// ***AnFre
const char Kwmod[16]								= {"VOLUMENZAEHLER "};
const char Gasmod[16]								= {"VOLUMEN        "};
const char Extmod[16]								= {"               "};
const char Wilomod[16]							= {"MODBUS         "};	//***AnFre Wilo-Pumpen
const char ModBusmod[16]						= {"SLAVE          "};	//***AnFre 08.05.2013 ModBus allgemein (z.B. MASTER / SLAVE )
const char DiaTH2mod[16]						= {"RL HK1   (TH2) "};	//***AnFre Mittlere Temp. TH2 06.06.2012
const char DiaTN2mod[16]						= {"RL NETZ  (TN2) "};	//***AnFre Mittlere Temp. TN2 06.06.2012

const char Monatswerte[16] 					= {" Monatswerte   "};		//MBus

const char Stoermeld[16]						=	{"STOERMELDUNGEN "};
const char ModBusMasterSlave[16]		=	{"MASTER/SLAVE   "};
const char ModBusMaster[16]					= {"MASTER         "};	
const char ModBusSlave[16]					= {"SLAVE          "};	

/***** ulsch : Heizgradtage *****/
const char HzGrdTg[16]						  =	{"G{15} VDI3807  "};

const char Leistung[16]						  =	{"LEISTUNG       "};

const char Anhang_Wilo[16]					= {"IF-MOD.Stratos "};

// Objekt- und Standortbezeichnungen                      maximale Anzahl von ASCII-Zeichen
//------------------------------------------------------------------------------------------
const char c_Objektbez [16]					= {"               "};  // 15 
const char c_Objektnum [10]					= {"         "};        //  9 
const char c_Strasse   [16]					= {"               "};  // 15 
const char c_Nummer    [10]					= {"         "};        //  9 
const char c_Ort       [16]					= {"               "};  // 15 
const char c_Plz       [10]					= {"         "};        //  9 
// Voreinstellung BUS-Betrieb
const char c_Service_Idf [16]       = {"48160118       "};  // 15 
const char c_ModulAdr               = 10;                   // 0=dummy
const char c_StationsAdr            = 10;                   // 0=dummy

// Voreinstellung Schnittstelle und Funktionen
const char c_Mode_S1                = MASTER;            // NULL_MODE = dummy,  MASTER, SLAVE
const UINT c_Baudrate_S1            = 9600;                    // 0         = dummy,  z.B. 9600
const char c_Funktion_S1            = GBUS_FU;              // NULL_FU   = dummy,  GBUS_FU, MODBUS1_FU, MBUS1_FU, GENI1_FU...siehe projdef.h
const char c_Parity_S1              = NULL_PARI;            // NULL_PARI = dummy,  NOPAR, EVEN, ODD 
const char c_Stopbits_S1            = NULL_STOP;            // NULL_STOP = dummy,  1, 2 

const char c_Mode_S2                = MASTER;            // NULL_MODE = dummy,  MASTER, SLAVE
const UINT c_Baudrate_S2            = 9600;                    // 0         = dummy
const char c_Funktion_S2            = MODBUS1_FU;              // NULL_FU   = dummy   GBUS_FU, MODBUS1_FU, MBUS1_FU, GENI1_FU...siehe projdef.h
const char c_Parity_S2              = EVEN;            // NULL_PARI = dummy,  NOPAR, EVEN, ODD 
const char c_Stopbits_S2            = 1;            // NULL_STOP = dummy,  1, 2 

const char c_Mode_S3                = NULL_MODE;            // NULL_MODE = dummy,  MASTER, SLAVE
const UINT c_Baudrate_S3            = 0;                    // 0         = dummy
const char c_Funktion_S3            = NULL_FU;              // NULL_FU   = dummy,  GBUS_FU, MODBUS1_FU, MBUS1_FU, GENI1_FU...siehe projdef.h
const char c_Parity_S3              = NULL_PARI;            // NULL_PARI = dummy,  NOPAR, EVEN, ODD 
const char c_Stopbits_S3            = NULL_STOP;            // NULL_STOP = dummy,  1, 2 

const char c_ModbusBaudWilo					= 5;				// WILO Pumpenparameter "A" Achtung! immer 5 = 9600 Baud
const char c_ModbusSioWilo					= 6;				// WILO Pumpenparameter "C" SIO-Einstellung Parit�t und StopBit (2, 3, 6, 10)
//------------------------------------------------------------------------------------------



//-------------------------------

//#define VERS_DATUM	{8,3,18}	// neu: UserHandlerS3, R3X_AADAT, R3X_DADAT
//#define VERS_DATUM	{8,5,5}		// SYNC-Gruppe gel�scht. Synchr. erfolgt in zin3-10.h
//#define VERS_DATUM	{8,8,8}		// Kommando WR_KASKADE: Antwort erweitert mit Hk-Informationen
	
//#define VERS_DATUM	{8,12,9}	// Uhr.c: Resetzeit wird gespeichert, Anzeige in parli.h hinter SYS;80; 
//#define VERS_DATUM	{8,12,22} // �nderung des Versionsdatums bewirkt Init_Leittab(); (entspricht Kaltstart 223)
//#define VERS_DATUM	{9,1,8} 	// UserReply.c: Funkempfang implementiert
//#define VERS_DATUM	{9,1,19}	// SteuerWW.c: BM Tauscherpumpe �berwachen
																// RegelHk.c: im St�tzbetrieb abgesenkten Vorlauf benutzen
																// Steuer.c: PUMIN auch bei Bedarfsabsenkung: Minimaldrehzahl in der Absenkphase, nicht bei Aufheizphase													
//#define VERS_DATUM	{9,2,10}	// GENIbus (Grundfos-Pumpen-Bus)
//#define VERS_DATUM	{9,2,11}	// UserReply.c: in SysRTC_InitUser() L�schen Z�hler Vorjahr eingebaut, R37_1 u. R37_2 berichtigt
//#define VERS_DATUM	{9,2,13}	// UserReply.c: in get_zpointer() Z�hlerdummy untersuchen 
//#define VERS_DATUM	{9,3,12}	// Fehler in Absenk.c beseitigt, Aufheizzeiten bei Zeitabsenkung verl�ngert
//#define VERS_DATUM	{9,3,24}	// Z�hlernummer f�r Leittechnik sichtbar, neue R36CLib (LzKonv.c erweitert) vom 24.03.09 verwenden
//#define VERS_DATUM	{9,4,15}	// Monza.c: Fehler korrigiert in Clear_Verbr(..., UINT monats_spadr,...) , vorher char monats_spadr
																// U_Funkempf.c: SRC_RS485_EVC 1 (neues EnOcean Modul)
//#define VERS_DATUM	{9,4,16}	// MBUS-Implementierung	
//#define VERS_DATUM	{9,5,7}		// Korrekturen: MBus,	Neu: Regelabw.alarm NT
//#define VERS_DATUM	{9,5,25}	// Implementierung: Archivierung mit SD-Card
//#define VERS_DATUM	{9,6,3}		// Implementierung: Speicherreservierung (mit malloc und free) 	Heapsize 2K
																// Korrekturen: MBus in U_Mbus.c , im System: BicMove.c erweitert auf maximal 6 Z�hler
//#define VERS_DATUM	{9,6,10}	// Korrekturen: ArchivSD.c	
//#define VERS_DATUM	{9,6,22}	// MBus-Erweiterung auf 6 Z�hler, Parametererweiterung in get_feldadresse(..., char *attr) (auch System�nderung),
																// Korrekturen: ArchivSD.c	
//#define VERS_DATUM	{9,7,1}		// Korrekturen: ArchivSD.c, Alarme.c (Quit-Taste)
//#define VERS_DATUM	{9,7,9}		// Korrekturen: ArchivSD.c, UserRam.c(struct DFILE afile;)
//#define VERS_DATUM	{9,9,29}	// Erweiterung: Anschluss Ni1000 mit Parallelwiderstand 7,5kOhm,  Typauswahl in parli SYS: (hid2) 0=Pt1000 1=Ni1000
//#define VERS_DATUM	{9,10,9}	// UserReply.c: Erweiterung UserPrimReply(...) entsprechend System�nderung vom 09.10.2009
																//              Einbindung CoolBC und HeatBC in Countdownbehandlung, Anzeige hinter SYS: 40: (hid2)
//#define VERS_DATUM	{10,1,5}	// Erweiterung: Neues Kommando RD_ALARMLIST (Lesen der akt. Alarme mit WinRFB V.3.4)
																//              �nderung in Alarme.c, UserReply.c, UserRam.s, uramext.h
//#define VERS_DATUM	{10,3,25}	// SEZ-2010 KESSEL f�r R66E C-System
//#define VERS_DATUM	{10,4,27}	 	// neues R66E-C-System mit neuer SD-Archivierung
																	// und Tyfocor 40,50,60 Vol.%
//	#define VERS_DATUM	{10,5,19}	 	// neuestes R66E-C-System mit neuester SD-Archivierung
//	#define VERS_DATUM	{10,9,9}	 	// neuestes R66E-C-System 
//	#define VERS_DATUM	{10,10,26}	// Solarkreis Pumpensteuerung 0...10Volt 
//	#define VERS_DATUM	{10,11,16}	// HK-Sollwert-Ausgabe  0...10Volt 
//	#define VERS_DATUM	{11,8,17}	// Absenk.c neu aus Pool, Korrekturen in ustrct.h (char->UINT)
																// neues System 11.05.2011 
//	#define VERS_DATUM	{11,9,8}	// SteuerWw.c: Vorrang MAX berichtigt
																// neues System 18.08.2011 
//	#define VERS_DATUM	{11,11,2}	// Parli's und Komtab.c nach Wunsch von Parabel
//	#define VERS_DATUM	{11,12,7}	// zin07.h: AKT.MON.VERBR. aus Komtab.c
//	#define VERS_DATUM	{12,1,4}	// Stations-IDF in Komtab.c
//	#define VERS_DATUM	{12,2,15}	// Jurisch: Frostschutz von TS5 auf TS2 und in Parli.h einstellbar

//	#define VERS_DATUM	{12,8,2}	 	//  Umger�stet auf neues C-System 30:05:12
																	//  TA-Ersatz pro Monat
																	// Daten-Manager
																	// Pumpenbus
																	// Solare Sonden-Regeneration
//	#define VERS_DATUM	{12,8,22}	 	// neues C-System 01:08:12
																	// gemittelte RL-Temp. TH2 gesichert im E-EPROM
//	#define VERS_DATUM	{12,9,19}	 	// Wmeng.c Vol.strom berechnung richtig
																	// puBm-Alarm mit Verz�gerung puBmVerz
																	// pusoBm-Alarm mit Verz�gerung pusoBmVerz
																	// pupuBm-Alarm mit Verz�gerung pupuBmVerz
																	// neue Funktion: dynamische Ventilstellung Min
//	#define VERS_DATUM	{12,9,25}	 	// neue Funktionen: siehe Munzert_Mail 25.09.2012
//	#define VERS_DATUM	{12,11,1}	 	// neue Funktionen: Kessel Ein entsprechend WPU-Ventilstellung
//	#define VERS_DATUM	{12,12,18}	// Wilo-Pumpenbus zugef�gt und neues System 20:11:12
//	#define VERS_DATUM	{13,1,22}	 	// Berechnung Drehzahl Ladepumpe �ber Ta neu ( PuDzTaMin/Max )
//	#define VERS_DATUM	{13,2,12}	 	// Berichtigung Pumpentext HKN:/HK1: *73 ff
																		// Standardwert f�r Stichtag GAS eingetragen {1,1,1} statt {0,1,1} und x2in1.h Monatswerte und VJ-Werte
//	#define VERS_DATUM	{13,4,4}	 	// Berichtigung Regel-Sollwert in RegelHk.c und RegelHkSol.c
//	#define VERS_DATUM	{13,6,19}	 	// Juri-MAXX 2013 Kessel-Standard
//	#define VERS_DATUM	{13,6,26}	 	// U_ModBusSio_Wilo.c eingebunden mit Parameter C =6, 8,E,1 (MR_Sx = 0x65)
//	#define VERS_DATUM	{13,8,14}	 	// von KE-R-1ss3-JMX31 und FW-R-1ss3-JMX21 abgeleitet in Halberstadt eingesetzt
//	#define VERS_DATUM	{13,8,21}	 	// neues C-System vom 08:08:13 mit DYN_ASCII_FORMAT
//	#define VERS_DATUM	{13,9,5}	 	//  Wilo-Modbus Handschaltung in jeweiliger Parameter-Gruppe
//	#define VERS_DATUM	{13,9,30}	 	// Fehler in parli_Solar.h beseitigt:
																	// SM SOLARPUMPE 	-> solPuSmAnz statt pusoBm
																	// SM PUFFERPUMPE -> pufPuSmAnz statt pupuBm
																	// Fehler in SteuerSol.c 			PUPUFEA[SO1]->wert = 1;	(statt =0)
																	// UserReply.c 		// ModBus WILO-Pumpen:	S2-Vorbelegung entfernt
																	// parli_Wilo.h   ANHANG WILO teilweise von hid2 nach hid4
//	#define VERS_DATUM	{14,2,20}	 	// "dynamische" kes[KE1].Tvma (90�C), sos[SO1].TW2Max (75�C) und sos[SO1].TW3Max (75�C) bei wws[WW1].Twwsol > 70�C
//	#define VERS_DATUM	{14,3,20}	 	// FWI: Korrektur RL-Begrenzung in SteuerKeNt.c, in RegelNt.c entfernt
//	#define VERS_DATUM	{14,5,28}	 	// Fehler in parli_Solar.h: Anzeige BM Puffer-Pumpe ein berichtigt
//	#define VERS_DATUM	{15,4,30}	 	// U_Wilo.c: modb_state_control=17: Bus_restart = 1; bei CRC-Fehler (modb_rx_status=4)
																	//						und modb_state_control=0 bei switch = default 
																	// neues System 16:12:14
//	#define VERS_DATUM	{16,6,8}	 // neues System 14.4.16
// #define VERS_DATUM	{16,10,10}	 // GPRS in parli,h
//#define VERS_DATUM	{17,4,4}			//SiWa: Neues System und neue Bezeichnungen
//#define VERS_DATUM	{17,11,1}			// SiWa: System 12.04.17, Betriebsmeldung von Puffer- und Solarpumpe korrigiert (war vertauscht)
			
			//VERS_DATUM Historie von Riedel Pool
			//#define VERS_DATUM  {16,1,14}  // Josch-SDM : Neues Betriebssystem {16,1,14} mit Erweiterung IrDA als IrDA-S4 Schnittstelle (�ber Modul RIEcon83)
                                 // ArchivSD.c mit Filesystem entf�llt. ArchivSDM.c erweitert mit Testkommando f�r Pr�fplatz.
                                 // Erforderliche �nderungen sind in "R36CPool_Anpassung_160114.txt " dokumentiert.
			//#define VERS_DATUM  {16,2,9}   // ulsch: 2 WW-Bereitungen. Ge�ndert: SteuerWw,c, RegelWw.c, parli.h, ustruct.h, UserConst.c, uconstext.h, projdef.h, Steuer.c, RegelHk.c, Alarme.c, UserReply.c
			  
			//#define VERS_DATUM  {16,5,19}  // Josch: Fehler in Archiv_SDM.c korrigiert.Ge�ndert: parli.h SYS; 88; ff.

			//#define VERS_DATUM  {16,5,23}  // Software f�r 1 Kessel komplett neu
			//#define VERS_DATUM  {16,6,21}  // Fehler in SteuerWw.c beseitigt: nach Speicherladung geht der Vorrang u.U.nicht zu Ende
			
			//#define VERS_DATUM  {16,6,29}  // Josch: Neue Implementierung Modbus (mit Pumpen (WILO_MODBUS, GENI, BELIMO), ohne Pumpen als Master oder Slave)
			//#define VERS_DATUM  {16,7,26}	 // ulsch: Kessel-Implementierung neu
			//#define VERS_DATUM  {16,9,29}  // AnBu: �nderung Gprs: parli.h ("work handler")
			//#define VERS_DATUM  {16,11,9}  // Josch,Joja: Modbus-Erg�nzung (StopBits, READ_MULTIPLE_COILS, ModbusExtract.c) 
			//#define VERS_DATUM  {16,11,15} // Josch: Alarme.c, parli.h: Soft-Quittierung ohne Quittiertaste m�glich.
			//#define VERS_DATUM  {16,11,29} // Josch: DTimer.c : Erweiterung - Sende Broadcast-Uhr
			//#define VERS_DATUM  {17,2,1}   // Josch: ArchivSDM.c: Automatische Fehlerkorrektur, betrifft: UserRam.c, uramext.h, archivsdm.h, UserReply.c, parli.h
			//#define VERS_DATUM  {17,4,5}   // Josch: ArchivSDM.c bugfix,  parli.h Neuordnung siehe ARCHIV_SDM
			//#define VERS_DATUM  {17,4,12}  // Josch: Neues System {17,4,12} : StationsAdresse synchronisieren mit Moduladresse.
			                                 //        betrifft  parli.h ZLT; *20; und folgenden ( ->;) Parameter �bernehmen   
			                                 //        au�erdem: Eine User-Compile-Zeit wird generiert, zu sehen in TES; *92; bis *93; 
			//#define VERS_DATUM  {17,6,19}	 // Ulsch: 8 MBus-Z�hler
			
			//#define VERS_DATUM  {17,6,21}  // Josch: Neues System {17,6,21} :
                                 //        Parit�t und Stopbits f�r 3 Schnittstellen sind in UserConst.c voreinstellbar. Sichtbar in Gruppe ZLT;   
                                 //        Deaktivierung von Sensor- und Analogeing�ngen m�glich. Zugriff in SYS: 09;SENSOR-IN LIFE und 10;ANALOG-IN LIFE  und in R38_MODULE 055;
                                 // AnBu:  GPRS zur�ck zur Version vom 29.09.2016                                                                                                  
                                    
			//#define VERS_DATUM  {17,8,30}  // Josch: ZLT Anzeige des Funktionsnamens. Betrifft: parli.h, UserKonv.c, uskonvform.h, UserConst.c, uconstext.h
			                                 // JoJa:  Modbus.c: Spezialkommando WRITE_SINGLE_COIL korrigiert
			
			//#define VERS_DATUM  {17,9,26}  // Josch: EA-Simulation mit System {17,9,26}
			                                 //        betrifft InOutR.c, UserRam.c .h, userdef.h, parli.h
			//#define VERS_DATUM  {17,11,13} // Josch: R3X-Simulator mit System {17,11,1} incl. Modulkonfiguration
			                                 //        betrifft InOutR.c, UserRam.c uramext.h
			//#define VERS_DATUM  {18,3,14}  // Josch: ArchivSDM.c erweitert. Datenbl�cke enthalten zus�tzlich Archiv-Info Kennzeichen. System vom {18,3,14} erforderlich
		
//#define VERS_DATUM	{18,03,21}	 // 	SiWa: Systemanpassung von 12.04.17 auf 14.03.18
#define VERS_DATUM	{18,6,6}	 // 	SiWa: Systemanpassung von 12.04.17 auf 14.03.18 und ModBus-Wilo-Implementierung, Absenktage in parli_HK1 aus komtab entfernt
/*--------------------------------------------------------------------------------*/
/* 										Liste von Anlagen																						*/
/*--------------------------------------------------------------------------------*/
const Anlage Projekte[] = {
	// 0. Projekt (Dummy-Projekt)
	{	
	 // Typ und Version
	 //"??-R-????-?????"			//Kennzeichen an fester Position !!	
		{"XX-R-????-?????"},		//genau 15 ASCII-Zeichen
		{1,1,1},	           		//Jahr, Monat, Tag
		// Kategoriebezeichnung f�r variable Projekte
		{"KEIN PROJEKT   "},
		
		// Steuercode f�r Heizkreise
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden Heizkreis [HK_PROFILE]
					// 0 = Heizkreis nicht vorhanden
		
		{0},	// Nummern der Absenkprofile f�r jeden Heizkreis [ABS_PROFILE]
					// 0 = nicht vorhanden
		
		// Steuercode f�r Solare Heizkreise	***AnFre
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden Heizkreis [HKSoL_PROFILE]
					// 0 = Solar-Heizkreis nicht vorhanden
		
		// Steuercode f�r Warmwasser
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden WWkreis [WW_PROFILE]
					// 0 = nicht vorhanden
		
		// Steuercode f�r Warmwasser-Temp-Profile
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden WWkreis [WW_PROFILE]
					// 0 = nicht vorhanden
		
		// Steuercode f�r Kessel
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden Kesselkreis [KE_PROFILE]
					// 0 = nicht vorhanden

		// Steuercode f�r Fernw�rmevorregelkreis (Netztrennumg)
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden Vorregelkreis [NT_PROFILE]
					// 0 = nicht vorhanden

		// Steuercode f�r Solar-Regelkreis
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden Solar-Regelkreis [SO_PROFILE]
					// 0 = nicht vorhanden
		
		// Steuercode f�r MBUS
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden MBUS-Z�hler[MB_PROFILE]
					// 0 = nicht vorhanden

		// Steuercode f�r SteuerUni
		{0},	// Nummern der Kaltstartparameters�tze f�r jede UNI-Steuerung [UNI_PROFILE]
					// 0 = nicht vorhanden

		// Namen f�r Prozess Ein- und Ausg�nge (Namensvereinbarung in "userdef.h")
		// Aus den Namen werden Steuercodes generiert
		TP_FREI,							// 				Eingang IN1		Pt1000 / ----- / -------	
		TP_FREI,							// 				Eingang IN2		Pt1000 / ----- / -------	
		TP_FREI,							// Block  Eingang IN3		Pt1000 / 0-10V / Digital
		TP_FREI,							// Block  Eingang IN4		Pt1000 / 0-10V / Digital
		TP_FREI,							// Block  Eingang IN5		Pt1000 / 0-10V / Digital
		TP_FREI,							// 				Eingang IN6		Pt1000 / 0-10V / Digital
		TP_FREI,							// 				Eingang IN7		Pt1000 / 0-10V / Digital
		TP_FREI,							// 				Eingang IN8		Pt1000 / 0-10V / Digital
		AE_FREI,							// 				Eingang IN9		------ / 0-10V / Digital
		DE_FREI,							// 				Eingang IN10	------ / 0-10V / Digital
		
		AA_FREI,							// Analog-Ausgang  AA1
		AA_FREI,							// Analog-Ausgang  AA2
		
		DA_FREI,							// Digital-Ausgang DA1
		DA_FREI,							// Digital-Ausgang DA2
		DA_FREI,							// Digital-Ausgang DA3
		DA_FREI,							// Digital-Ausgang DA4
		DA_FREI,							// Digital-Ausgang DA5
		DA_FREI,							// Digital-Ausgang DA6
		
		// Externe Erweiterungen mit R37, R38 , siehe Liste Anl37 oder Anl38
		{	{  0, 0, 0},				// Ger�tekennzeichen, Ger�tenummer, Nummer des Belegungsblockes
			{  0, 0, 0},
			{  0, 0, 0},
			{  0, 0, 0},
		},

		// NAMUR-Kennzeichnung f�r Digitale Eing�nge R36
		0x00,									// Bit=1...NAMUR-Eingang,	BIT0...7 = IN3...IN10
	},
	
	// 1. Projekt: Kessel Standard
	//						 1 Kesselsteuerung: 1 Kessel Sollwert-Vorgabe,
	//						 1 Heizkreis: "normal" HK1:,
	//						 1 Heizkreis: "Solar-Einspeisung" HKS:,
	//						 1 Warmwasser: Regelung und Speicherladung (1 Speicherf�hler)
	//						 1 Solarkreis: 
	//						 1 W�rmez�hler: Q1 Heizung    (mit Monatswerten)
	//						 1 W�rmez�hler: Q2 Kollektor  (mit Monatswerten)
	//						 1 W�rmez�hler: Q3 Warmwasser (mit Monatswerten)
	//						 1 VolumenZ�hler Trink-Warmwasser
	//																											 
	{	
	 // Typ und Version
	 //"??-R-????-?????"			//Kennzeichen an fester Position !!	
		{"KE-R-1ss3-JMX71"},		//genau 15 ASCII-Zeichen
		VERS_DATUM,	           		//Jahr, Monat, Tag
		// Kategoriebezeichnung f�r variable Projekte
		{"TEST PROJEKT   "},
		
		// Steuercode f�r Heizkreise
		{1},	// Nummern der Kaltstartparameters�tze f�r jeden Heizkreis [HK_PROFILE]
					// 0 = Heizkreis nicht vorhanden
		
		{1},	// Nummern der Absenkprofile f�r jeden Heizkreis [ABS_PROFILE]
					// 0 = nicht vorhanden
		
		// Steuercode f�r Solare Heizkreise		***AnFre
		{1},	// Nummern der Kaltstartparameters�tze f�r jeden Heizkreis [HKSoL_PROFILE]
					// 0 = Solar-Heizkreis nicht vorhanden
		
		// Steuercode f�r Warmwasser
		{1},	// Nummern der Kaltstartparameters�tze f�r jeden WWkreis [WW_PROFILE]
					// 0 = nicht vorhanden
		
		// Steuercode f�r Warmwasser-Temp-Profile
		{1},	// Nummern der Kaltstartparameters�tze f�r jeden WWkreis [PR_PROFILE]
					// 0 = nicht vorhanden
		
		// Steuercode f�r Kessel
		{1},	// Nummern der Kaltstartparameters�tze f�r jeden Kesselkreis [KE_PROFILE]
					// 0 = nicht vorhanden

		// Steuercode f�r Fernw�rmevorregelkreis (Netztrennumg)
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden Fernw�rmevorregelkreis [NT_PROFILE]
					// 0 = nicht vorhanden

		// Steuercode f�r Solar-Regelkreis
		{1},	// Nummern der Kaltstartparameters�tze f�r jeden Solar-Regelkreis [SO_PROFILE]
					// 0 = nicht vorhanden

		// Steuercode f�r MBUS
		{0},	// Nummern der Kaltstartparameters�tze f�r jeden MBUS-Z�hler[MB_PROFILE]
							// 0 = nicht vorhanden

		// Steuercode f�r SteuerUni
		{0},	// Nummern der Kaltstartparameters�tze f�r jede UNI-Steuerung [UNI_PROFILE]
					// 0 = nicht vorhanden

		// Namen f�r Prozess Ein- und Ausg�nge (Namensvereinbarung in "userdef.h")
		// Aus den Namen werden Steuercodes generiert
		TA1,			// Au�entemp.						// 				Eingang IN1		Pt1000 / ----- / -------	
		TVS1,			// HK1 Vorlauf		neu: TVH alt: TH1		// 				Eingang IN2		Pt1000 / ----- / -------	
		AE_UNI3,	// SOL: Druck Koll. neu: PS alt: PS1	// Block  Eingang IN3		0...10 Volt
		AE_UNI4,	// SOL: Druck Puff. neu: PP alt: PP	// Block  Eingang IN4		0...10 Volt
		AE_UNI1,	// StrahlungsSensor		neu: ST	// Block  Eingang IN5		0...10 Volt
		AE_UNI2,	// ANL: Ext.Anford. UST1// 				Eingang IN6		0...10 Volt
		TRS1,			// HK1 R�cklauf		neu: TRH alt: TH2		// 				Eingang IN7		Pt1000
		ZIN8,			// Volumengeber Heizung	neu: WHZ alt: WZ1 // 				Eingang IN8		Digital
		ZIN9,			// Volumengeber Solar	neu: WSK alt: WZ2   // 				Eingang IN9		Digital
		ZIN10,		// Volumengeber TWE			neu: WTW alt: WZ3 // 				Eingang IN10	Digital

		RVENT1,		// Regelventil neu: RV H alt: HK1		 	// Analog-Ausgang  AA1
		RVENTWW1,	// Regelventil neu: RV TWE alt: WW		 		// Analog-Ausgang  AA2

		MVWL1EA,	// Lade-MotorVentil			// Digital-Ausgang DA1
		PUWZ1EA,	// Zirkulationspumpe		// Digital-Ausgang DA2
		MVKOL1EA,	// UV Kollektor	0=Kollektorweg, 1=Pufferweg (Puffer entladen)// Digital-Ausgang DA3
		PUSOL1EA,	// Pumpe Solarkreis			// Digital-Ausgang DA4
		MVPUF1EA,	// UV Puffer	 	0=entladen,1=laden// Digital-Ausgang DA5
		PUPUF1EA,	// Pumpe Solar-Puffer		// Digital-Ausgang DA6

		// Externe Erweiterungen mit R37, R38 , siehe Liste Anl37 oder Anl38
		{	{R37, 1, 1},				// Ger�tekennzeichen, Ger�tenummer, Nummer des Belegungsblockes
			{R37, 2, 2},
			{R38, 1, 1},
			{  0, 0, 0},
		},			

		// NAMUR-Kennzeichnung f�r Digitale Eing�nge R36
		0x00,									// Bit=1...NAMUR-Eingang,	BIT0...7 = IN3...IN10
	},
	
};
const char PROJTYPEN = sizeof(Projekte) / sizeof(Anlage);
	
/*----------------------------------------------------------------------------*/
/*  							Liste von Ein-/Ausgangs-Belegungss�tzen f�r R37-Module			*/
/*----------------------------------------------------------------------------*/
const Anl37 R37_Beleg[] = {
	// 0. Belegungssatz (Dummy-Set)
	{	
		DE_FREI,		// Digital-Eingang DE1 
		DE_FREI,		// Digital-Eingang DE2
		DE_FREI,		// Digital-Eingang DE3 
		DE_FREI,		// Digital-Eingang DE4 
		DE_FREI,		// Digital-Eingang DE5 
		DE_FREI,		// Digital-Eingang DE6
		
		AA_FREI,		// Analog-Ausgang  AA1
		AA_FREI,		// Analog-Ausgang  AA2
		AA_FREI,		// Analog-Ausgang  AA3
		AA_FREI,		// Analog-Ausgang  AA4
	
		DA_FREI,		// Digital-Ausgang DA1
		DA_FREI,		// Digital-Ausgang DA2
		DA_FREI,		// Digital-Ausgang DA3
	},

				
	// 1. Belegungssatz Anwendung f�r R37_1
	{	
		ZIN11,		// Externer Z�hler					// Digital-Eingang DE1	(ZIN11)	
		ZIN12,		// Volumengeber Kaltw.			// Digital-Eingang DE2	
		KEAL1,		// Kesselalarm Si-Kette			// Digital-Eingang DE3  
		STWWW1,		// STW TWE									// Digital-Eingang DE4	
		STWHK1,		// STW HK1									// Digital-Eingang DE5	
		SAMAL1,		// externer Sammelalarm			// Digital-Eingang DE6	(ZIN16)  

		

		RVENTSO1,		// Regelventil HK1-Solar	// Analog-Ausgang  AA1
		MVKALTW1,		// UV KaltWasser					// Analog-Ausgang  AA2
		RVENTKE1,		// Vorl.-Sollwert Kessel	// Analog-Ausgang  AA3
		TAA1,				// Au�entemp.an Fremdregler// Analog-Ausgang  AA4
	
		UVWW1EA,		// UV TWE-Solar						// Digital-Ausgang DA1	war SEZ-2008: analog MVSOLWW1, 
		PU1EA,	  	// Pumpe HK1            	// Digital-Ausgang DA2
		PUWT1EA,		// TWE Tauscherpumpe			// Digital-Ausgang DA3
	},

	// 2. Belegungssatz Anwendung f�r R37_2
	{	
		BMPU1,		// Betriebsmeldung Pumpe		// Digital-Eingang DE1	(ZIN21)	
		BMPUPUF1,	// Betriebsm. Pumpe	Solar		// Digital-Eingang DE2 
		BMPUSOL1,	// Betriebsm. Pumpe	Puffer	// Digital-Eingang DE3	
		BMPUWZ1,	// Betriebsm. Zirk.-Pumpe		// Digital-Eingang DE4	
		BMPUWT1,	// Betriebsm.Tauscher-Pumpe	// Digital-Eingang DE5
		QUITTS1,	// Quittierungstaste				// Eingang Digital DE6	(ZIN26)
		
		
		AA_UNI1,	// Drehzahl Solar-Pumpe		// Analog-Ausgang  AA1
		AA_UNI2,	// HK Sollwert-Ausgabe		// Analog-Ausgang  AA2
		AA_UNI3,	// HK-Ventilstellung			// Analog-Ausgang  AA3
		AA_UNI4,	// TWE-Ventilstellung			// Analog-Ausgang  AA4
	
		SSTM1,		// Sammelst�rmeldung							// Digital-Ausgang DA1
		PUKE1EA,	// Kessel- bzw. Pumpenfreigabe		// Digital-Ausgang DA2
		DA_FREI,	// 																// Digital-Ausgang DA3
	},				
		
};	
const char R37SETS = sizeof(R37_Beleg) / sizeof(Anl37);

/*----------------------------------------------------------------------------*/
/*  							Liste von Ein-/Ausgangs-Belegungss�tzen f�r R38-Module			*/
/*----------------------------------------------------------------------------*/
const Anl38 R38_Beleg[] = {
	// 0. Belegungssatz (Dummy-Set)
	{	
		TP_FREI,		// Pt1000 Eingang IN1
		TP_FREI,		// Pt1000 Eingang IN2
		TP_FREI,		// Pt1000 Eingang IN3
		TP_FREI,		// Pt1000 Eingang IN4
		TP_FREI,		// Pt1000 Eingang IN5
		TP_FREI,		// Pt1000 Eingang IN6
		TP_FREI,		// Pt1000 Eingang IN7
		TP_FREI,		// Pt1000 Eingang IN8
		TP_FREI,		// Pt1000 Eingang IN9
		TP_FREI,		// Pt1000 Eingang IN10
		TP_FREI,		// Pt1000 Eingang IN11
		TP_FREI,		// Pt1000 Eingang IN12
		TP_FREI,		// Pt1000 Eingang IN13
		TP_FREI,		// Pt1000 Eingang IN14
	},

	// 1. Belegungssatz 
	{	
// Pt1000 Eingang IN1
		TS1,			// Kollektor Vorlauf				TS1				// Pt1000 Eingang IN1
		TS2,			// Vorlauf PW� TWE  				TS2				// Pt1000 Eingang IN2
		TS3,			// Vorlauf PW� Solar-HK			TS3				// Pt1000 Eingang IN3
		TS4,			// Vorlauf PW� Puffer				TS4				// Pt1000 Eingang IN4
		TS5,			// Kollektor R�cklauf				neu: TS6 alt:TS5				// Pt1000 Eingang IN5
		TS6,			// Puffer-Speicher oben			TS6				// Pt1000 Eingang IN6
		TS7,			// Puffer-Speicher unten		TS7				// Pt1000 Eingang IN7
		TVKE1,		// Kesselvorl. 							TVKES			// Pt1000 Eingang IN8
		TW1,			// TWE-Regeltemp.						TW1				// Pt1000 Eingang IN9
		TW2,			// Speicher oben						TW2				// Pt1000 Eingang IN10
		TW3,			// Speicher mittig					TW3				// Pt1000 Eingang IN11
		TW4,			// Speicher unten						TW4				// Pt1000 Eingang IN12
		TWWZ1,		// Zirkulation-RL						TW5				// Pt1000 Eingang IN13
		TWWP1,		// TWW-RL	prim.							TW6				// Pt1000 Eingang IN14
	},

};
const char R38SETS = sizeof(R38_Beleg) / sizeof(Anl38);
			
/*----------------------------------------------------------------------------*/
/*  							Liste von Ein-/Ausgangs-Belegungss�tzen f�r R39-Module			*/
/*----------------------------------------------------------------------------*/
const Anl39 R39_Beleg[] = {
	// 0. Belegungssatz (Dummy-Set)
	{	
		DE_FREI,		// Eingang DE1
		DE_FREI,		// Eingang DE2
		DE_FREI,		// Eingang DE3
		DE_FREI,		// Eingang DE4
		DE_FREI,		// Eingang DE5
		DE_FREI,		// Eingang DE6
		DE_FREI,		// Eingang DE7
		DE_FREI,		// Eingang DE8
		DE_FREI,		// Eingang DE9
		DE_FREI,		// Eingang DE10
		DE_FREI,		// Eingang DE11
		DE_FREI,		// Eingang DE12
		// Signalart: 0=Schlie�er 1=�ffner  Bit0=DE1
		0x0000,			// .... 0000 0000 0000
	},

	{	
		HKAUS1,			// Schalter Nichtnutzung HK1			// Eingang DE1
		DE_FREI,		// Eingang DE2
		DE_FREI,		// Eingang DE3
		DE_FREI,		// Eingang DE4
		DE_FREI,		// Eingang DE5
		DE_FREI,		// Eingang DE6
		DE_FREI,		// Eingang DE7
		DE_FREI,		// Eingang DE8
		DE_FREI,		// Eingang DE9
		DE_FREI,		// Eingang DE10
		DE_FREI,		// Eingang DE11
		DE_FREI,		// Eingang DE12
		// Signalart: 0=Schlie�er 1=�ffner  Bit0=DE1
		0x0000,			// .... 0000 0000 0000
	},
	
//	// 1. Belegungssatz
//	{	
//		PUAL1,			// St�rmeldung Pumpe HK1			// Eingang DE1
//		PUAL2,			// St�rmeldung Pumpe HK2			// Eingang DE2
//		PUWLAL1,		// St�rmeldung Ladepumpe			// Eingang DE3
//		DE_FREI,		//                        		// Eingang DE4
//		PUWZAL1,		// St�rmeldung Zirk.pumpe			// Eingang DE5
//		STWWW1,			// Si.Temp.W�chter WW					// Eingang DE6
//		BRAL1,			// St�rmeldung Kesselanlage		// Eingang DE7
//		KEAL1,			// St�rmeldung Si-Kette				// Eingang DE8
//		DE_FREI,		// Eingang DE9
//		HKAUS1,			// Schalter Nichtnutzung HK1	// Eingang DE10
//		HKAUS2,			// Schalter Nichtnutzung HK2	// Eingang DE11
//		WWAUS1,			// Schalter Nichtnutzung WWB	// Eingang DE12
//		// Signalart: 0=Schlie�er 1=�ffner  Bit0=DE1
//		0x0000,			// .... 0000 0000 0000
//	},

};
const char R39SETS = sizeof(R39_Beleg) / sizeof(Anl39);

/*----------------------------------------------------------------------------*/
/*  							Liste von Ausgangs-Belegungss�tzen f�r R33-Module						*/
/*----------------------------------------------------------------------------*/
const Anl33 R33_Beleg[] = {
	// 0. Belegungssatz (Dummy-Set)
	{	
		DA_FREI,		// Digital-Ausgang DA1
		DA_FREI,		// Digital-Ausgang DA2
		DA_FREI,		// Digital-Ausgang DA3
		DA_FREI,		// Digital-Ausgang DA4
		DA_FREI,		// Digital-Ausgang DA5
		DA_FREI,		// Digital-Ausgang DA6
	},

	// 1. Belegungssatz
	{	
		DA_FREI,		// Digital-Ausgang DA1
		DA_FREI,		// Digital-Ausgang DA2
		DA_FREI,	  // Digital-Ausgang DA3
		DA_FREI,		// Digital-Ausgang DA4
		DA_FREI,		// Digital-Ausgang DA5
		DA_FREI,		// Digital-Ausgang DA6
	},

};	
const char R33SETS = sizeof(R33_Beleg) / sizeof(Anl33);

/*----------------------------------------------------------------------------*/
/*  							Liste von Standardwerten f�r MBUS														*/
/*----------------------------------------------------------------------------*/
const MbusStandard  Mbus_Standparam[] = {
 // Profil 0 (dummy)
 {
	0,															// Freigabe
	0,															// Telegramm-Folge
	0,															// Z�hler-Typ: W�rme 4, Kaltwasser 22, Warmwasser 6, Elektro 2
	0,
 },

 // Profil 1: W�rmez�hler ISTA Sensonic II, freigegeben
 {1,1,4,2},

 // Profil 2: Wasserz�hler ISTA, freigegeben
 {1,1,6,22},

 // Profil 3: Elektroz�hler PadPuls M2, freigegeben
 {
	1,1,2,6},

 // Profil 4: Kaltwasserz�hler PadPuls M2, freigegeben
 {1,1,0x16,8},

 // Profil 5 (dummy)
 {0,1,0,0},

 // Profil 6 (Standard: W�rmez�hler, nicht freigegeben, Adresse 0)
 {0,1,4,0},
}; 	
const char MB_PROFILE = sizeof ( Mbus_Standparam ) / sizeof ( MbusStandard ); 	



/*----------------------------------------------------------------------------*/
/*  							Liste von Standardwerten f�r alle Bus-Pumpen						   */
/*								Zuordnung f�r Pumpen 1 bis 8 entsprechend projdef.h		      */
/*----------------------------------------------------------------------------*/
const PuBusStandard  PuBus_Standparam[] = {

	// Profil 1 Pumpe 1 (Index 0)
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"SOL: SOLARPUMPE"},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		1,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		1,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
	800,														// UINT	Sollwert = 80,0 %			
		2,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

	// Profil 2 Pumpe 2 (Index 1)
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"SOL:PUFFERPUMPE"},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		2,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		1,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
	800,														// UINT	Sollwert = 80,0 %			
		2,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

	// Profil 3 Pumpe 3 (Index 2)
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"HK1: HEIZPUMPE "},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		3,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		1,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
	800,														// UINT	Sollwert;				// [%] / 10			
		2,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

	// Profil 4 Pumpe 4 (Index 3)
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"TWE: WT PUMPE  "},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		4,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		1,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
	800,														// UINT	Sollwert;				// [%] / 10			
		2,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

	// Profil 5 Pumpe 5 (Index 4)
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"TWE: ZIRK.PUMPE"},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		5,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		1,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		2,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
	700,														// UINT	Sollwert;				// [%] / 10			
		2,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

	// Profil 6 Pumpe 6 (Index 5)
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"               "},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		6,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		0,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		2,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// UINT	Sollwert;				// [%] / 10			
		3,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

	// Profil 7 Pumpe 7 (Index 6)
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"               "},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		7,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		0,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// UINT	Sollwert;				// [%] / 10			
		3,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

 // Profil 8 Pumpe 8 (Index 7) 
 {
		0,														// char	Funktion; 			// deaktiviert (0), remote (1), local (2)
		{"               "},					// Name[16];						// Beispiele: "PUMPE HK1       ", "ZIRK.-PUMPE     "
		0,														// char Adresse;				// frei w�hlbar, Standard = Nummer
		0,														// char	Betrieb;				// Betriebsart bei Automatikbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	Regelart;				// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// UINT	Sollwert;				// [%] / 10				
		0,														// char	RMverz;					// Verz�gerung R�ckmeldung [min]
		0,														// char	Hand;						// Hand/Automatik, Hand = 1
		0,														// char	BetriebHand;		// Betriebsart bei Handbetrieb, Stop (0), Ein (1), Minimal-Kurve (2), Maximal-Kurve (3)
		0,														// char	SollHand;				// [%] / 10
		0,														// char	RegelartHand;		// Konstantdruck (0), Proportionaldruck (1), Konstantfrequenz (2), Automatik (3)
		0,														// char	AlarmQuit;
		2,														// char	HoldingReg300;	// Manual (5), siehe Modbus_RS485_spec_V_1_09_en.pdf Abschnitt 5.1.8 Table 5.4
 },

};

			
/*----------------------------------------------------------------------------*/
/*  							Liste von Standardwerten f�r verschiedene Heizkreise				*/
/*----------------------------------------------------------------------------*/
const HkStandard  Hk_Standparam[] = {
 // Profil 0 (dummy)
 {
	  0,	//int		Ts;						= 0		// Tastzeit (>= 1 s)						[s] * 10
	  0,	//UINT	Tn;						= 0		// Nachstellzeit								[s] * 10
	  0,	//int		Kp;						= 0		// P-Verst�rkung							[%/K] * 100
	  0,	//int		Kd;						= 0		// D-Verst�rkung							[%/K] * 100
	  0,	//int		Kpk;					= 0		// P-Verst�rkung Kaskade			[%/K] * 100
	  0,	//int		Kpr;					= 0		// P-Verst�rkung TRS-Begrenzg.[%/K] * 100
	  0,	//int		Anst;					= 0		// Steigung									 		[1] * 100	
	  0,	//int		Tvpa;					= 0		// Niveau											 [�C] * 10		
	  0,	//int		Tvma;					= 0		// max. Vorlauftemp.					 [�C] * 10		
	  0,	//int		Tvmi;					= 0		// min. Vorlauftemp.					 [�C] * 10		
	  0,	//int		Trma;					= 0		// max. R�cklauftemp.					 [�C] * 10		
	  0,	//int		Taha;					= 0		// Temp. am Heizkurvenanfang	 [�C] * 10	
	  0,	//int		Tiso;					= 0		// Raumsolltemp. f�r Kaskade	 [�C] * 10		
	  0,	//int		Timi;					= 0		// Mindest-Raumtemp.					 [�C] * 10	
	  0,	//int		Tsolu;				= 0		// Start-Sollwert Heizung			 [�C] * 10	
	  0,	//int		Beabs;				= 0		// Bedarfs-Absenk.keine Nutzung [K] * 10	
	  0,	//int		Fzk;					= 0		// Filterzk. f. tsol						[s] * 10
	  0,	//char	Hub;					= 0		// Ventilhub									 [mm]
	  0,	//char	Vst;					= 0		// Stellgeschwindigkeit		 [mm/min]
	  0,	//char	Haut;					= 0		// HAND/AUTO-Umschaltung
	  0,	//char	Puea;					= 0		// Hand: Pumpe	ein/aus
	  0,	//char	Pu2ea;				= 0		// Hand: bei Doppelpumpe Pumpe 2	ein/aus	
	  0,	//int		Vstell;				= 0		// Hand: Ventil stellen 0-10V Ventil	[%] * 10
	  0,	//char	Puna;					= 0		// Pumpennachlaufzeit										[min]		
	  0,	//char	Swhk;					= 0		// Schalter Sommer/Winter-Automatik 		ja/nein
	  0,	//char	Wwvh;					= 0		// Schalter WW-Vorrang 									ja/nein
	  0,	//char	Sauf;					= 0		// Schalter Schnellaufheizung 					ja/nein
	  0,	//char	Psbegr;				= 0		// Schalter Prim�r/Sekund�r R�ckl.begr.	Prim=1 Sek=0
	  0,	//int	  Kpww;					= 0		// P-Verst�rkung f�r gleitenden Warmwasservorrang [%/K] * 100 (in Wwsteu behandelt)
	  0,	//char	TabwMax;			= 0		// maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	  0,	//char	TabwZeit;			= 0		// Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	  0,	//char	FerienAutom;	= 0		// Schalter
	  0,	//UINT	FerienAbsenk;	= 0		// Absenkwert
	  0,	//UINT	SchalterAbsenk= 0		// Anlagenschalter-Absenk. keine Nutzung [K] * 10	
	  0,	//UINT	Y_rel_min;		= 0		// Minimale Stellausgabe an 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_beg;		= 0		// �ffnungsbeginn des 0-10V Ventils				[%] * 10

	  0,	//int		TaFrostgrenze;= 0		// Ta-FrostGrenze bei Absenkung				 	[�C] * 10		
	  0,	//int		TaHeizgrenze;	= 0		// Ta-HeizGrenze beim Heizbetrieb			 	[�C] * 10		
		0,	//int		AbschZeitKonst;= 0	// Zur Berechnung der Abschaltdauer in der Absenkzeit		[h/K] * 10
	  0,	//char 	SoWiExtra;		= 0		// Schalter Auswahl Sommer/Winter Extrawerte ja/nein 
	  0,	//int		Tae;					= 0		// Temp. Winter ein						 					[�C] * 10	
	  0,	//int		Taa;					= 0		// Temp. Sommer aus						 					[�C] * 10	

	  0,	//char	MessBeginn;		= 0		// Beginn der Adaption, Stunde
	  0,	//char	AdaptWert;		= 0		// [K] * 10
	  0,	//int		EiMaxAdapt;		= 0		// max. Regelabweichung, bei der Adaptionswert berechnet wird [K] * 10

	  0,	//char 	FuehrPu;			= 0		// F�hrunspumpe
	  0,	//UINT 	PuWechseln;		= 0		// laufzeitabh. Umschalten der F�hrungspumpe  [h]
	  0,	//char 	FuehrPuFest;	= 0		// F�hrunspumpe fest vorgegeben, wenn ungestoert	(1,2); 3=beide Pu laufen gleichzeitig, 0=laufzeitabh.
	  0,	//char	KaskMode;			= 0		// Modus der Raum-Kaskade bei gleichzeitiger Adaption : 0 -> nur anhebend und bei Unterversorgung, 1 -> immer
	  0,	//int 	TvpAnh;				= 0		// Anhebung der Anforderung an den W�rmeerzeuger		[K] * 10		
		0,	//char	ExtAnf1_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//char	ExtAnf2_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//int		TvAnhExt;					// Anhebung externe Anforderung			***AnFre 06.06.2012

// Estrich-Programm
		{ 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

	  0,	// TimiHyst;					= 0		// Hysterese Raum-Mindesttemp. [K] * 10
 	  0,	// XpLeistBegr;				= 0 	// Ventil schliesst zur Leistungsbegrenzung um LeistBegr[K/% * 100]
	  0,	// KaskBegr;					= 0		// Begrenzung des Raum-Sollwerts f�r Kaskade	[�C] * 10
//#####090119													
	  0,	// PuMin							= 0		// Pumpe auf Mindestdrehzahl													

// Pumpenbus
		0,	// BusPuSollwert = 0				// 0...100,0 %
		0,	// BusPuSollwertAbsenk = 0	// 0...100,0 %

// Heizkreis abschalten mangels Bedarf 
// Bedingungen: Funktion freigegeben, Raum ext Ist > Soll sowie (wenn parametriert) offene Ventile <= VentOffenMax
		0,	//AbschRaumanf;		// Funktion freigegeben ?
		0,	//VentilAuswert;	// Ventilstellung ber�cksichtigen ? (sonst nur Raumtemperatur)
		0,	//VentOffenMax;		// HK abschalten, wenn offene Ventile (%) kleiner VentOffenMax
		0,	// Tvsol10=100,0	Solltemperatur bei 10V				[�C] * 10
		0,	// Tvsol0 =  0,0	Solltemperatur bei 0V					[�C] * 10
		0,	// UINT Sollstell	// HAND Sollwert stellen	Volt *100
		0,	//VorlaufMaxSommer;	// wenn VL > VorlaufMaxSommer, wird ucHeat = 1 trotz Sommer (R50 �ffnet dann nicht die Heizungs-Ventile)
		0,	//VorrangZeitabsenkung;
// ***AnFre 08.07.2010 Legionellen im Nahw�rmenetz
 },
 
 // Profil 1: Heizkreis 
 {
	100,	//int		Ts;						= 10,0		// Tastzeit (>= 1 s)						[s] * 10
	400,	//UINT	Tn;						= 50,0		// Nachstellzeit								[s] * 10
	125,	//int		Kp;						=  2,00		// P-Verst�rkung							[%/K] * 100
	  0,	//int		Kd;						=  0,00		// D-Verst�rkung							[%/K] * 100
	300,	//int		Kpk;					=  3,00		// P-Verst�rkung Kaskade			[%/K] * 100
	100,	//int		Kpr;					=  2,25		// P-Verst�rkung TRS-Begrenzg.[%/K] * 100
	120,	//int		Anst;					=  1,40		// Steigung									 		[1] * 100	
	300,	//int		Tvpa;					= 25,0		// Niveau											 [�C] * 10		
	700,	//int		Tvma;					= 75,0		// max. Vorlauftemp.					 [�C] * 10		
	400,	//int		Tvmi;					= 30,0		// min. Vorlauftemp.					 [�C] * 10		
	500,	//int		Trma;					= 60,0		// max. R�cklauftemp.					 [�C] * 10		
	200,	//int		Taha;					= 20,0		// Temp. am Heizkurvenanfang	 [�C] * 10	
	210,	//int		Tiso;					= 21,0		// Raumsolltemp. f�r Kaskade	 [�C] * 10		
	150,	//int		Timi;					= 15,0		// Mindest-Raumtemp.					 [�C] * 10	
	400,	//int		Tsolu;				= 40,0		// Start-Sollwert Heizung			 [�C] * 10	
	200,	//int		Beabs;				= 20,0		// Bedarfs-Absenk.keine Nutzung [K] * 10	
	600,	//int		Fzk;					= 60,0		// Filterzk. f. tsol						[s] * 10
	 25,	//char	Hub;					= 25			// Ventilhub									 [mm]
	 25,	//char	Vst;					= 25			// Stellgeschwindigkeit		 [mm/min]
	  0,	//char	Haut;					=  0			// HAND/AUTO-Umschaltung
	  1,	//char	Puea;					=  1			// Hand: Pumpe	ein/aus
	  1,	//char	Pu2ea;				=  1			// Hand: bei Doppelpumpe Pumpe 2	ein/aus	
	  0,	//int		Vstell;				=  0,0		// Hand: Ventil stellen 0-10V Ventil	[%] * 10
	 10,	//char	Puna;					= 10			// Pumpennachlaufzeit										[min]		
	  1,	//char	Swhk;					=  1			// Schalter Sommer/Winter-Automatik 		ja/nein
	  0,	//char	Wwvh;					=  1			// Schalter WW-Vorrang 									ja/nein
	  0,	//char	Sauf;					=  0			// Schalter Schnellaufheizung 					ja/nein
	  0,	//char	Psbegr;				=  0			// Schalter Prim�r/Sekund�r R�ckl.begr.	Prim=1 Sek=0
		0,	//int	  Kpww;					=  0,00 !!!		// P-Verst�rkung f�r gleitenden Warmwasservorrang [%/K] * 100 (in Wwsteu behandelt)
	100,	//char	TabwMax;			= 10,0		// maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	 60,	//char	TabwZeit;			= 60			// Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	  0,	//char	FerienAutom;	=  0			// Schalter
	200,	//UINT	FerienAbsenk;	= 20,0		// Absenkwert
	200,	//UINT	SchalterAbsenk= 20,0		// Anlagenschalter-Absenk. keine Nutzung [K] * 10	
	  0,	//UINT	Y_rel_min;		=  0,0		// Minimale Stellausgabe an 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_beg;		=  0,0		// �ffnungsbeginn des 0-10V Ventils				[%] * 10

	 30,	//int		TaFrostgrenze;=  3,0		// Ta-FrostGrenze bei Absenkung				 	[�C] * 10		
	220,	//int		TaHeizgrenze;	= 22,0		// Ta-HeizGrenze beim Heizbetrieb			 	[�C] * 10		
	 	0,	//int		AbschZeitKonst=  1,0		// Zur Berechnung der Abschaltdauer in der Absenkzeit		[h/K] * 10 ***AnFre Funktion nicht aktiv
	  0,	//char 	SoWiExtra;		=  0			// Schalter Auswahl Sommer/Winter Extrawerte ja/nein 
	990,	//int		Tae;					= 17,0		// Temp. Winter ein						 					[�C] * 10	
	999,	//int		Taa;					= 18,0		// Temp. Sommer aus						 					[�C] * 10	

	 10,	//char	MessBeginn;		= 10			// Beginn der Adaption, Stunde
	 10,	//char	AdaptWert;		=  0,0		// [K] * 10
	 30,	//int		EiMaxAdapt;		=  3,0		// max. Regelabweichung, bei der Adaptionswert berechnet wird [K] * 10

	  0,	//char 	FuehrPu;			=  0		// F�hrungspumpe
	  0,	//UINT 	PuWechseln;		=  0		// laufzeitabh. Umschalten der F�hrungspumpe  [h]
	  0,	//char 	FuehrPuFest;	=  0		// F�hrungspumpe fest vorgegeben, wenn ungestoert	(1,2); 3=beide Pu laufen gleichzeitig, 0=laufzeitabh.
	  0,	//char	KaskMode;			=  0		// Modus der Raum-Kaskade bei gleichzeitiger Adaption : 0 -> nur anhebend und bei Unterversorgung, 1 -> immer
	  0,	//int 	TvpAnh;				=  0		// Anhebung der Anforderung an den W�rmeerzeuger		[K] * 10		
		0,	//char	ExtAnf1_Ja;	=	1			// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//char	ExtAnf2_Ja;	=	0			// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
	  0,	//int		TvAnhExt;						// Anhebung externe Anforderung			***AnFre 06.06.2012
// Estrich-Programm
		{ 0, 1, 1},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

	  0,	// TimiHyst;					= 2,0		// Hysterese Raum-Mindesttemp. [K] * 10
 	  0,	// LeistBegrTs;				= 0 		// Ventil schliesst zur Leistungsbegrenzung um LeistBegrTs/Ts [%]
		0,	// KaskBegr;					= 21,0	// Begrenzung des Raum-Sollwerts f�r Kaskade	[�C] * 10
//#####090119													
	  0,	// PuMin							= 0		// Pumpe auf Mindestdrehzahl													

// Pumpenbus
		800,	// BusPuSollwert = 0				// 0...100,0 %
		500,	// BusPuSollwertAbsenk = 0	// 0...100,0 %

// Heizkreis abschalten mangels Bedarf 
// Bedingungen: Funktion freigegeben, Raum ext Ist > Soll sowie (wenn parametriert) offene Ventile <= VentOffenMax
		0,	//AbschRaumanf;		// Funktion freigegeben ?
		0,	//VentilAuswert;	// Ventilstellung ber�cksichtigen ? (sonst nur Raumtemperatur)
		0,	//VentOffenMax;		// HK abschalten, wenn offene Ventile (%) kleiner VentOffenMax
	1000,	// Tvsol10=100,0	Solltemperatur bei 10V				[�C] * 10
		0,	// Tvsol0 =  0,0	Solltemperatur bei 0V					[�C] * 10
		0,	// UINT Sollstell	// HAND Sollwert stellen	Volt *100
	990,	//VorlaufMaxSommer;	// wenn VL > VorlaufMaxSommer, wird ucHeat = 1 trotz Sommer (R50 �ffnet dann nicht die Heizungs-Ventile)
		0,	//VorrangZeitabsenkung;
 },

 
 // Profil 2 
 {
	100,	//int		Ts;						= 10,0		// Tastzeit (>= 1 s)						[s] * 10
  400,	//UINT	Tn;						= 120,0		// Nachstellzeit								[s] * 10
	125,	//int		Kp;						=  2,00		// P-Verst�rkung							[%/K] * 100
	  0,	//int		Kd;						=  0,00		// D-Verst�rkung							[%/K] * 100
	400,	//int		Kpk;					=  3,00		// P-Verst�rkung Kaskade			[%/K] * 100
	150,	//int		Kpr;					=  1,50		// P-Verst�rkung TRS-Begrenzg.[%/K] * 100
	120,	//int		Anst;					=  1,40		// Steigung									 		[1] * 100	
	300,	//int		Tvpa;					= 25,0		// Niveau											 [�C] * 10		
	650,	//int		Tvma;					= 75,0		// max. Vorlauftemp.					 [�C] * 10		
	500,	//int		Tvmi;					= 35,0		// min. Vorlauftemp.					 [�C] * 10		
	990,	//int		Trma;					= 99,0		// max. R�cklauftemp.					 [�C] * 10		
	200,	//int		Taha;					= 20,0		// Temp. am Heizkurvenanfang	 [�C] * 10	
	210,	//int		Tiso;					= 21,0		// Raumsolltemp. f�r Kaskade	 [�C] * 10		
	150,	//int		Timi;					= 15,0		// Mindest-Raumtemp.					 [�C] * 10	
	400,	//int		Tsolu;				= 40,0		// Start-Sollwert Heizung			 [�C] * 10	
	150,	//int		Beabs;				= 15,0		// Bedarfs-Absenk.keine Nutzung [K] * 10	
	600,	//int		Fzk;					= 60,0		// Filterzk. f. tsol						[s] * 10
	 20,	//char	Hub;					= 20			// Ventilhub									 [mm]
	 10,	//char	Vst;					= 10			// Stellgeschwindigkeit		 [mm/min]
	  0,	//char	Haut;					=  0			// HAND/AUTO-Umschaltung
	  1,	//char	Puea;					=  1			// Hand: Pumpe	ein/aus
		0,	//int		PuDzHand;								// Hand: Pumpen-Drehzahl							[%] * 10		***AnFre 06.06.2012
	  0,	//int		Vstell;				=  0,0		// Hand: Ventil stellen 0-10V Ventil	[%] * 10
	 15,	//char	Puna;					=  5			// Pumpennachlaufzeit										[min]		
	  0,	//char	Swhk;					=  1			// Schalter Sommer/Winter-Automatik 		ja/nein	// ***AnFre 06.06.2012
	  0,	//char	Wwvh;					=  1			// Schalter WW-Vorrang 									ja/nein	***AnFre Kein WW-Vorrang !!!
	  0,	//char	Sauf;					=  0			// Schalter Schnellaufheizung 					ja/nein
	  0,	//char	Psbegr;				=  0			// Schalter Prim�r/Sekund�r R�ckl.begr.	Prim=1 Sek=0
		0,	//int	  Kpww;					=  1,00		// P-Verst�rkung f�r gleitenden Warmwasservorrang [%/K] * 100 (in Wwsteu behandelt)
	100,	//char	TabwMax;			= 10,0		// maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	 60,	//char	TabwZeit;			= 60			// Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	  0,	//char	FerienAutom;	=  0			// Schalter
	200,	//UINT	FerienAbsenk;	= 20,0		// Absenkwert
	200,	//UINT	SchalterAbsenk= 20,0		// Anlagenschalter-Absenk. keine Nutzung [K] * 10	
	  0,	//UINT	Y_rel_min;		=  0,0		// Minimale Stellausgabe an 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_beg;		=  0,0		// �ffnungsbeginn des 0-10V Ventils				[%] * 10

	 30,	//int		TaFrostgrenze;=  3,0		// Ta-FrostGrenze bei Absenkung				 	[�C] * 10		
	990,	//int		TaHeizgrenze;	= 22,0		// Ta-HeizGrenze beim Heizbetrieb			 	[�C] * 10		
	  0,	//int		AbschZeitKonst=  1,0		// Zur Berechnung der Abschaltdauer in der Absenkzeit		[h/K] * 10
	  0,	//char 	SoWiExtra;		=  0			// Schalter Auswahl Sommer/Winter Extrawerte ja/nein 
	160,	//int		Tae;					= 17,0		// Temp. Winter ein						 					[�C] * 10	
	170,	//int		Taa;					= 18,0		// Temp. Sommer aus						 					[�C] * 10	

	  8,	//char	MessBeginn;		=  8			// Beginn der Adaption, Stunde
	  0,	//char	AdaptWert;		=  0,0		// [K] * 10
	 30,	//int		EiMaxAdapt;		=  3,0		// max. Regelabweichung, bei der Adaptionswert berechnet wird [K] * 10

	  0,	//char 	FuehrPu;			=  0		// F�hrungspumpe
	  0,	//UINT 	PuWechseln;		=  0		// laufzeitabh. Umschalten der F�hrungspumpe  [h]
	  0,	//char 	FuehrPuFest;	=  0		// F�hrungspumpe fest vorgegeben, wenn ungestoert	(1,2); 3=beide Pu laufen gleichzeitig, 0=laufzeitabh.
	  0,	//char	KaskMode;			=  0		// Modus der Raum-Kaskade bei gleichzeitiger Adaption : 0 -> nur anhebend und bei Unterversorgung, 1 -> immer
	  0,	//int 	TvpAnh;				=  0		// Anhebung der Anforderung an den W�rmeerzeuger		[K] * 10		
		0,	//char	ExtAnf1_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//char	ExtAnf2_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
	 30,	//int		TvAnhExt;						// Anhebung externe Anforderung			***AnFre 06.06.2012
// Estrich-Programm
		{ 0, 1, 1},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

	  5,	// TimiHyst;					= 2,0		// Hysterese Raum-Mindesttemp. [K] * 10
 	  0,	// LeistBegrTs;				= 0 		// Ventil schliesst zur Leistungsbegrenzung um LeistBegrTs/Ts [%]
	210,	// KaskBegr;					= 21,0	// Begrenzung des Raum-Sollwerts f�r Kaskade	[�C] * 10
//#####090119													
	  0,	// PuMin							= 0		// Pumpe auf Mindestdrehzahl													

// Pumpenbus
		800,	// BusPuSollwert = 0				// 0...100,0 %
		800,	// BusPuSollwertAbsenk = 0	// 0...100,0 %

// Heizkreis abschalten mangels Bedarf 
// Bedingungen: Funktion freigegeben, Raum ext Ist > Soll sowie (wenn parametriert) offene Ventile <= VentOffenMax
		0,	//AbschRaumanf;		// Funktion freigegeben ?
		0,	//VentilAuswert;	// Ventilstellung ber�cksichtigen ? (sonst nur Raumtemperatur)
		0,	//VentOffenMax;		// HK abschalten, wenn offene Ventile (%) kleiner VentOffenMax
		0,	// Tvsol10=100,0	Solltemperatur bei 10V				[�C] * 10
		0,	// Tvsol0 =  0,0	Solltemperatur bei 0V					[�C] * 10
		0,	// UINT Sollstell	// HAND Sollwert stellen	Volt *100
	990,	//VorlaufMaxSommer;	// wenn VL > VorlaufMaxSommer, wird ucHeat = 1 trotz Sommer (R50 �ffnet dann nicht die Heizungs-Ventile)
		0,	//VorrangZeitabsenkung;
// ***AnFre 08.07.2010 Legionellen im Nahw�rmenetz
 },
 
 // Profil 3 (Fu�boden)
 {
	100,	//int		Ts;						= 10,0		// Tastzeit (>= 1 s)						[s] * 10
 1200,	//UINT	Tn;						= 120,0		// Nachstellzeit								[s] * 10
	250,	//int		Kp;						=  2,50		// P-Verst�rkung							[%/K] * 100
	  0,	//int		Kd;						=  0,00		// D-Verst�rkung							[%/K] * 100
	300,	//int		Kpk;					=  3,00		// P-Verst�rkung Kaskade			[%/K] * 100
	150,	//int		Kpr;					=  1,50		// P-Verst�rkung TRS-Begrenzg.[%/K] * 100
	 80,	//int		Anst;					=  0,80		// Steigung									 		[1] * 100	
	200,	//int		Tvpa;					= 20,0		// Niveau											 [�C] * 10		
	500,	//int		Tvma;					= 50,0		// max. Vorlauftemp.					 [�C] * 10		
	250,	//int		Tvmi;					= 25,0		// min. Vorlauftemp.					 [�C] * 10		
	990,	//int		Trma;					= 99,0		// max. R�cklauftemp.					 [�C] * 10		
	200,	//int		Taha;					= 20,0		// Temp. am Heizkurvenanfang	 [�C] * 10	
	210,	//int		Tiso;					= 21,0		// Raumsolltemp. f�r Kaskade	 [�C] * 10		
	150,	//int		Timi;					= 15,0		// Mindest-Raumtemp.					 [�C] * 10	
	300,	//int		Tsolu;				= 30,0		// Start-Sollwert Heizung			 [�C] * 10	
	 50,	//int		Beabs;				=  5,0		// Bedarfs-Absenk.keine Nutzung [K] * 10	
	600,	//int		Fzk;					= 60,0		// Filterzk. f. tsol						[s] * 10
	 20,	//char	Hub;					= 20			// Ventilhub									 [mm]
	 10,	//char	Vst;					= 10			// Stellgeschwindigkeit		 [mm/min]
	  0,	//char	Haut;					=  0			// HAND/AUTO-Umschaltung
	  1,	//char	Puea;					=  1			// Hand: Pumpe	ein/aus
		0,	//int		PuDzHand;								// Hand: Pumpen-Drehzahl							[%] * 10		***AnFre 06.06.2012
	  0,	//int		Vstell;				=  0,0		// Hand: Ventil stellen 0-10V Ventil	[%] * 10
	  5,	//char	Puna;					=  5			// Pumpennachlaufzeit										[min]		
	  1,	//char	Swhk;					=  1			// Schalter Sommer/Winter-Automatik 		ja/nein
	  0,	//char	Wwvh;					=  1			// Schalter WW-Vorrang 									ja/nein	***AnFre Kein WW-Vorrang !!!
	  0,	//char	Sauf;					=  0			// Schalter Schnellaufheizung 					ja/nein
	  0,	//char	Psbegr;				=  0			// Schalter Prim�r/Sekund�r R�ckl.begr.	Prim=1 Sek=0
		0,	//int	  Kpww;					=  1,00		// P-Verst�rkung f�r gleitenden Warmwasservorrang [%/K] * 100 (in Wwsteu behandelt)
	 50,	//char	TabwMax;			=  5,0		// maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	 60,	//char	TabwZeit;			= 60			// Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	  0,	//char	FerienAutom;	=  0			// Schalter
	100,	//UINT	FerienAbsenk;	= 10,0		// Absenkwert
	100,	//UINT	SchalterAbsenk= 10,0		// Anlagenschalter-Absenk. keine Nutzung [K] * 10	
	  0,	//UINT	Y_rel_min;		=  0,0		// Minimale Stellausgabe an 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_beg;		=  0,0		// �ffnungsbeginn des 0-10V Ventils				[%] * 10

	 30,	//int		TaFrostgrenze;=  3,0		// Ta-FrostGrenze bei Absenkung				 	[�C] * 10		
	220,	//int		TaHeizgrenze;	= 22,0		// Ta-HeizGrenze beim Heizbetrieb			 	[�C] * 10		
	 10,	//int		AbschZeitKonst=  1,0		// Zur Berechnung der Abschaltdauer in der Absenkzeit		[h/K] * 10
	  0,	//char 	SoWiExtra;		=  0			// Schalter Auswahl Sommer/Winter Extrawerte ja/nein 
	160,	//int		Tae;					= 17,0		// Temp. Winter ein						 					[�C] * 10	
	170,	//int		Taa;					= 18,0		// Temp. Sommer aus						 					[�C] * 10	

	 10,	//char	MessBeginn;		= 10			// Beginn der Adaption, Stunde
	  0,	//char	AdaptWert;		=  0,0		// [K] * 10
	 30,	//int		EiMaxAdapt;		=  3,0		// max. Regelabweichung, bei der Adaptionswert berechnet wird [K] * 10

	  0,	//char 	FuehrPu;			=  0		// F�hrungspumpe
	  0,	//UINT 	PuWechseln;		=  0		// laufzeitabh. Umschalten der F�hrungspumpe  [h]
	  0,	//char 	FuehrPuFest;	=  0		// F�hrungspumpe fest vorgegeben, wenn ungestoert	(1,2); 3=beide Pu laufen gleichzeitig, 0=laufzeitabh.
	  0,	//char	KaskMode;			=  0		// Modus der Raum-Kaskade bei gleichzeitiger Adaption : 0 -> nur anhebend und bei Unterversorgung, 1 -> immer
	  0,	//int 	TvpAnh;				=  0		// Anhebung der Anforderung an den W�rmeerzeuger		[K] * 10		
		0,	//char	ExtAnf1_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//char	ExtAnf2_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//int		TvAnhExt;						// Anhebung externe Anforderung			***AnFre 06.06.2012
// Estrich-Programm
		{ 0, 1, 1},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

	  5,	// TimiHyst;					= 2,0		// Hysterese Raum-Mindesttemp. [K] * 10
 	  0,	// LeistBegrTs;				= 0 		// Ventil schliesst zur Leistungsbegrenzung um LeistBegrTs/Ts [%]
	210,	// KaskBegr;					= 21,0	// Begrenzung des Raum-Sollwerts f�r Kaskade	[�C] * 10
//#####090119													
	  0,	// PuMin							= 0		// Pumpe auf Mindestdrehzahl													

// Pumpenbus
		800,	// BusPuSollwert = 0				// 0...100,0 %
		500,	// BusPuSollwertAbsenk = 0	// 0...100,0 %

// Heizkreis abschalten mangels Bedarf 
// Bedingungen: Funktion freigegeben, Raum ext Ist > Soll sowie (wenn parametriert) offene Ventile <= VentOffenMax
		0,	//AbschRaumanf;		// Funktion freigegeben ?
		0,	//VentilAuswert;	// Ventilstellung ber�cksichtigen ? (sonst nur Raumtemperatur)
		0,	//VentOffenMax;		// HK abschalten, wenn offene Ventile (%) kleiner VentOffenMax
		0,	// Tvsol10=100,0	Solltemperatur bei 10V				[�C] * 10
		0,	// Tvsol0 =  0,0	Solltemperatur bei 0V					[�C] * 10
		0,	// UINT Sollstell	// HAND Sollwert stellen	Volt *100
	990,	//VorlaufMaxSommer;	// wenn VL > VorlaufMaxSommer, wird ucHeat = 1 trotz Sommer (R50 �ffnet dann nicht die Heizungs-Ventile)
		0,	//VorrangZeitabsenkung;
// ***AnFre 08.07.2010 Legionellen im Nahw�rmenetz
 },

 
 // Profil 4 (Zubringer L�ftung)
 {
	100,	//int		Ts;						= 10,0		// Tastzeit (>= 1 s)						[s] * 10
 1200,	//UINT	Tn;						= 120,0		// Nachstellzeit								[s] * 10
	200,	//int		Kp;						=  2,00		// P-Verst�rkung							[%/K] * 100
	  0,	//int		Kd;						=  0,00		// D-Verst�rkung							[%/K] * 100
	  0,	//int		Kpk;					=  0,00		// P-Verst�rkung Kaskade			[%/K] * 100
	150,	//int		Kpr;					=  1,50		// P-Verst�rkung TRS-Begrenzg.[%/K] * 100
	 80,	//int		Anst;					=  0,80		// Steigung									 		[1] * 100	
	450,	//int		Tvpa;					= 20,0		// Niveau											 [�C] * 10		
	750,	//int		Tvma;					= 75,0		// max. Vorlauftemp.					 [�C] * 10		
	500,	//int		Tvmi;					= 50,0		// min. Vorlauftemp.					 [�C] * 10		
	990,	//int		Trma;					= 99,0		// max. R�cklauftemp.					 [�C] * 10		
	200,	//int		Taha;					= 20,0		// Temp. am Heizkurvenanfang	 [�C] * 10	
	210,	//int		Tiso;					= 21,0		// Raumsolltemp. f�r Kaskade	 [�C] * 10		
	150,	//int		Timi;					= 15,0		// Mindest-Raumtemp.					 [�C] * 10	
	300,	//int		Tsolu;				= 30,0		// Start-Sollwert Heizung			 [�C] * 10	
	  0,	//int		Beabs;				=  0,0		// Bedarfs-Absenk.keine Nutzung [K] * 10	
	600,	//int		Fzk;					= 60,0		// Filterzk. f. tsol						[s] * 10
	 20,	//char	Hub;					= 20			// Ventilhub									 [mm]
	 10,	//char	Vst;					= 10			// Stellgeschwindigkeit		 [mm/min]
	  0,	//char	Haut;					=  0			// HAND/AUTO-Umschaltung
	  1,	//char	Puea;					=  1			// Hand: Pumpe	ein/aus
		0,	//int		PuDzHand;								// Hand: Pumpen-Drehzahl							[%] * 10		***AnFre 06.06.2012
	  0,	//int		Vstell;				=  0,0		// Hand: Ventil stellen 0-10V Ventil	[%] * 10
	  5,	//char	Puna;					=  5			// Pumpennachlaufzeit										[min]		
	  1,	//char	Swhk;					=  1			// Schalter Sommer/Winter-Automatik 		ja/nein
	  0,	//char	Wwvh;					=  1			// Schalter WW-Vorrang 									ja/nein	***AnFre Kein WW-Vorrang !!!
	  0,	//char	Sauf;					=  0			// Schalter Schnellaufheizung 					ja/nein
	  0,	//char	Psbegr;				=  0			// Schalter Prim�r/Sekund�r R�ckl.begr.	Prim=1 Sek=0
		0,	//int	  Kpww;					=  1,00		// P-Verst�rkung f�r gleitenden Warmwasservorrang [%/K] * 100 (in Wwsteu behandelt)
	100,	//char	TabwMax;			= 10,0		// maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	 60,	//char	TabwZeit;			= 60			// Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	  0,	//char	FerienAutom;	=  0			// Schalter
	100,	//UINT	FerienAbsenk;	= 10,0		// Absenkwert
	100,	//UINT	SchalterAbsenk= 10,0		// Anlagenschalter-Absenk. keine Nutzung [K] * 10	
	  0,	//UINT	Y_rel_min;		=  0,0		// Minimale Stellausgabe an 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_beg;		=  0,0		// �ffnungsbeginn des 0-10V Ventils				[%] * 10

	 30,	//int		TaFrostgrenze;=  3,0		// Ta-FrostGrenze bei Absenkung				 	[�C] * 10		
	220,	//int		TaHeizgrenze;	= 22,0		// Ta-HeizGrenze beim Heizbetrieb			 	[�C] * 10		
	  0,	//int		AbschZeitKonst=  0,0		// Zur Berechnung der Abschaltdauer in der Absenkzeit		[h/K] * 10
	  0,	//char 	SoWiExtra;		=  0			// Schalter Auswahl Sommer/Winter Extrawerte ja/nein 
	160,	//int		Tae;					= 17,0		// Temp. Winter ein						 					[�C] * 10	
	170,	//int		Taa;					= 18,0		// Temp. Sommer aus						 					[�C] * 10	

	 10,	//char	MessBeginn;		= 10			// Beginn der Adaption, Stunde
	  0,	//char	AdaptWert;		=  0,0		// [K] * 10
	 30,	//int		EiMaxAdapt;		=  3,0		// max. Regelabweichung, bei der Adaptionswert berechnet wird [K] * 10

	  0,	//char 	FuehrPu;			=  0		// F�hrungspumpe
	  0,	//UINT 	PuWechseln;		=  0		// laufzeitabh. Umschalten der F�hrungspumpe  [h]
	  0,	//char 	FuehrPuFest;	=  0		// F�hrungspumpe fest vorgegeben, wenn ungestoert	(1,2); 3=beide Pu laufen gleichzeitig, 0=laufzeitabh.
	  0,	//char	KaskMode;			=  0		// Modus der Raum-Kaskade bei gleichzeitiger Adaption : 0 -> nur anhebend und bei Unterversorgung, 1 -> immer
	  0,	//int 	TvpAnh;				=  0		// Anhebung der Anforderung an den W�rmeerzeuger		[K] * 10		
		0,	//char	ExtAnf1_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//char	ExtAnf2_Ja;				// Externe Anforderung f�r diesen HK g�ltig			***AnFre 04.12.2008
		0,	//int		TvAnhExt;						// Anhebung externe Anforderung			***AnFre 06.06.2012
// Estrich-Programm
		{ 0, 1, 1},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

	  5,	// TimiHyst;					= 2,0		// Hysterese Raum-Mindesttemp. [K] * 10
 	  0,	// LeistBegrTs;				= 0 		// Ventil schliesst zur Leistungsbegrenzung um LeistBegrTs/Ts [%]
	210,	// KaskBegr;					= 21,0	// Begrenzung des Raum-Sollwerts f�r Kaskade	[�C] * 10
//#####090119													
	  0,	// PuMin							= 0		// Pumpe auf Mindestdrehzahl													

// Pumpenbus
		800,	// BusPuSollwert = 0				// 0...100,0 %
		500,	// BusPuSollwertAbsenk = 0	// 0...100,0 %

// Heizkreis abschalten mangels Bedarf 
// Bedingungen: Funktion freigegeben, Raum ext Ist > Soll sowie (wenn parametriert) offene Ventile <= VentOffenMax
		0,	//AbschRaumanf;		// Funktion freigegeben ?
		0,	//VentilAuswert;	// Ventilstellung ber�cksichtigen ? (sonst nur Raumtemperatur)
		0,	//VentOffenMax;		// HK abschalten, wenn offene Ventile (%) kleiner VentOffenMax
		0,	// Tvsol10=100,0	Solltemperatur bei 10V				[�C] * 10
		0,	// Tvsol0 =  0,0	Solltemperatur bei 0V					[�C] * 10
		0,	// UINT Sollstell	// HAND Sollwert stellen	Volt *100
	990,	//VorlaufMaxSommer;	// wenn VL > VorlaufMaxSommer, wird ucHeat = 1 trotz Sommer (R50 �ffnet dann nicht die Heizungs-Ventile)
		0,	//VorrangZeitabsenkung;
// ***AnFre 08.07.2010 Legionellen im Nahw�rmenetz
 },

}; 	
const char HK_PROFILE = sizeof ( Hk_Standparam ) / sizeof ( HkStandard ); 	


/*----------------------------------------------------------------------------*/
/* 						Liste von Absenktabellen f�r verschiedene Heizkreise						*/
/*----------------------------------------------------------------------------*/
const absenktab abs_standard[][8] = {
// begin[min], begin[h], dauer[h], absenktemp[0.1 K]
	
	{ // Absenkprofil 0 (dummy)
		{0,   0,	0,	  0},		// Alle Tage
		{0,   0,	0,	  0},		// Mo
		{0,   0,	0,	  0},		// Di
		{0,   0,	0,	  0},		// Mi
		{0,   0,	0,	  0},		// Do
		{0,   0,	0,	  0},		// Fr
		{0,   0	,	0,	  0},		// Sa
		{0,	  0,	0,	  0},		// So
	},
	
	{ // Absenkprofil 1: HK1
		{0,  23,	6,	50},		// Alle Tage
		{0,  23,	6,	50},		// Mo
		{0,  23,	6,	50},		// Di
		{0,  23,	6,	50},		// Mi
		{0,  23,	6,	50},		// Do
		{0,  23,	6,	50},		// Fr
		{0,  23	,	6,	50},		// Sa
		{0,	 23,	6,	50},		// So
	},
	
	{ // Absenkprofil 2: HK2: HK1: Solar
		{0,  0, 0,	0},		// Alle Tage
		{0,  0, 0,	0},		// Mo
		{0,  0, 0,	0},		// Di
		{0,  0, 0,	0},		// Mi
		{0,  0, 0,	0},		// Do
		{0,  0, 0,	0},		// Fr
		{0,  0, 0,	0},		// Sa
		{0,	 0, 0,	0},		// So
	},

	{ // Absenkprofil 3: HK3: HK2: 2.Heizkreis
		{0,  23,	6,	50},		// Alle Tage
		{0,  23,	6,	50},		// Mo
		{0,  23,	6,	50},		// Di
		{0,  23,	6,	50},		// Mi
		{0,  23,	6,	50},		// Do
		{59, 23,	6,	50},		// Fr
		{59, 23	,	6,	50},		// Sa
		{0,	 23,	6,	50},		// So
	},

	{ // Absenkprofil 4: FBH Schulen/B�ros/Gewerbe
		{0,  18, 12,	 50},		// Alle Tage
		{0,  18, 12,	 50},		// Mo
		{0,  18, 12,	 50},		// Di
		{0,  18, 12,	 50},		// Mi
		{0,  18, 12,	 50},		// Do
		{0,  15, 24,	 50},		// Fr
		{0,  15, 24,	 50},		// Sa
		{0,	 15, 14,	 50},		// So
	},

	
	{ // Absenkprofil 5: Turnhalle
		{0,  21, 11,	200},		// Alle Tage
		{0,  21, 11,	200},		// Mo
		{0,  21, 11,	200},		// Di
		{0,  21, 11,	200},		// Mi
		{0,  21, 11,	200},		// Do
		{0,  21, 11,	200},		// Fr
		{0,  21, 11,	200},		// Sa
		{0,	 21, 11,	200},		// So
	},               
	
	{ // Absenkprofil 6: Kita
		{0,  20, 10,	150},		// Alle Tage
		{0,  20, 10,	150},		// Mo
		{0,  20, 10,	150},		// Di
		{0,  20, 10,	150},		// Mi
		{0,  20, 10,	150},		// Do
		{0,  20, 12,	150},		// Fr
		{0,  12, 20,	150},		// Sa
		{0,	 12, 18,	150},		// So
	},

	{ // Absenkprofil 7: alles aus
		{0,   0,	0,	  0},		// Alle Tage
		{0,   0,	0,	  0},		// Mo
		{0,   0,	0,	  0},		// Di
		{0,   0,	0,	  0},		// Mi
		{0,   0,	0,	  0},		// Do
		{0,   0,	0,	  0},		// Fr
		{0,   0	,	0,	  0},		// Sa
		{0,	  0,	0,	  0},		// So
	},
	
};	
const char ABS_PROFILE =  ( sizeof ( abs_standard ) / 8 ) / sizeof ( absenktab ) ;
			
/*----------------------------------------------------------------------------*/
/* ***AnFre			Liste von Standardwerten f�r Solar Heizkreis				*/
/*----------------------------------------------------------------------------*/
const HkSoLStandard  HkSoL_Standparam[] = {
 // Profil 0 (dummy)
 {
	  0,	//int		Ts;						= 0		// Tastzeit (>= 1 s)						[s] * 10
	  0,	//UINT	Tn;						= 0		// Nachstellzeit								[s] * 10
	  0,	//int		Kp;						= 0		// P-Verst�rkung							[%/K] * 100
	  0,	//int		Kd;						= 0		// D-Verst�rkung							[%/K] * 100
		0,	//int		DTSoLad;			= 0		// dT-Heiz. TS3-TH2						 [K] * 10		
	  0,	//int		TvAbsenk;			= 0		// Absenkung HK1:								[K] * 10		
	  0,	//int		Fzk;					= 0		// Filterzk. f. tsol						[s] * 10
	  0,	//char	Hub;					= 0		// Ventilhub									 [mm]
	  0,	//char	Vst;					= 0		// Stellgeschwindigkeit		 [mm/min]
	  0,	//char	Haut;					= 0		// HAND/AUTO-Umschaltung
	  0,	//int		Vstell;				= 0		// Hand: Ventil stellen 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_min;		= 0		// Minimale Stellausgabe an 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_beg;		= 0		// �ffnungsbeginn des 0-10V Ventils				[%] * 10
		0,	//UINT	RVSoMax;			= 0		// RegelVentil maximale �ffnung						[%] * 10
		0,	//	char	RVzu;			// Dauer HK1-RV ist ZU 	--> kein Bedarf		f�r Kessel KES:		[min]
		0,	//	char	RVauf;		// Dauer HK1-RV ist AUF --> wieder Bedarf	f�r Kessel KES:		[min]
// 30.05.2013 Munzert		0,	// TvPaKes				Absenkung Vorl.Soll HK1:, wenn Kessel AUS
// ***AnFre 06.06.2012	RegelParameter f�r PumpenRegelung

 },
 // Profil 1
 {
	 100,	//int		Ts;						= 0		// Tastzeit (>= 1 s)						[s] * 10
	 400,	//UINT	Tn;						= 0		// Nachstellzeit								[s] * 10
	 125,	//int		Kp;						= 0		// P-Verst�rkung							[%/K] * 100
	  0,	//int		Kd;						= 0		// D-Verst�rkung							[%/K] * 100
	 60,	//int		DTSoLad;			= 0		// dT-Heiz. TS3-TH2						 [K] * 10		
	 30,	//int		TvAbsenk;			= 0		// Absenkung HK1:								[K] * 10		// 06.06.2012 entf�llt	
	  1,	//int		Fzk;					= 0		// Filterzk. f. tsol						[s] * 10
	  0,	//char	Hub;					= 0		// Ventilhub									 [mm]
	  0,	//char	Vst;					= 0		// Stellgeschwindigkeit		 [mm/min]
	  0,	//char	Haut;					= 0		// HAND/AUTO-Umschaltung
	  0,	//int		Vstell;				= 0		// Hand: Ventil stellen 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_min;		= 0		// Minimale Stellausgabe an 0-10V Ventil	[%] * 10
	  0,	//UINT	Y_rel_beg;		= 0		// �ffnungsbeginn des 0-10V Ventils				[%] * 10
	1000,	//UINT	RVSoMax;			= 0		// RegelVentil maximale �ffnung						[%] * 10
		3,	//	char	RVzu;			// Dauer HK1-RV ist ZU 	--> kein Bedarf		f�r Kessel KES:		[min]
		1,	//	char	RVauf;		// Dauer HK1-RV ist AUF --> wieder Bedarf	f�r Kessel KES:		[min]
// 30.05.2013 Munzert	  0,		// TvPaKes = 0,0	Absenkung Vorl.Soll HK1:, wenn Kessel AUS				[K] * 10
// ***AnFre 06.06.2012	RegelParameter f�r PumpenRegelung
 },
}; 	
const char HKSoL_PROFILE = sizeof ( HkSoL_Standparam ) / sizeof ( HkSoLStandard ); 	

/*----------------------------------------------------------------------------*/
/*  							Liste von Standardwerten f�r verschiedene Kesselkreise			*/
/*----------------------------------------------------------------------------*/

const KeStandard  Ke_Standparam[] = {
 // Profil 0 (dummy)
 {
	0,		// Tvma	=  0,0		max. Kesseltemp.							[�C] * 10
	0,		// Tvmi =  0,0		min. Kesseltemp.							[�C] * 10
	0,		// Trma =  0,0		max. R�cklauftemp.					 [�C] * 10	***AnFre	
	0,		// Kpr	=  0,0		P-Verst�rkung TRS-Begrenzg	[%/K] * 100
	0,		// Ttaup=  0,0		Kessel-Taupunkttemp.		 			[�C] * 10
	0,		// Tvpa =  0,0		Kesselanhebung								[�C] * 10
	0,		// TvPaWw =	0,0		Kesselanhebung	WW			 				[�C] * 10	//***AnFre
	0,		// Tvsol10 = 0		Solltemperatur bei 10V				[�C] * 10
	0,		// Tvsol0  = 0		Solltemperatur bei 0V					[�C] * 10
	0,		// Haut    = 0		Hand/Automatik
	0,		// Kesea	 = 0		Hand Kesselfreigabe ein/aus		
	0,		// Kestufe1= 0		Hand Kesselstufe 1  ein/aus		
	0,		// Kestufe2= 0	  Hand Kesselstufe 2  ein/aus
	0,		// Kestell = 0		Hand F�hrungswert 0-10,0 Volt 		
	0,		// Kespuea = 0    Hand Kesselpumpe ein/aus
	0,		// Kesklaz = 0	  Hand Kesselabsperrklappe auf/zu
	0,		// Kepuna  = 0	  Kesselpumpen- bzw. Absperrklappen-Nachlauf [min]
 	0,		// char Kepuverz;	Kesselpumpen- Verz�gerung [min]

	0,		// Haut_begr  = 0		Hand/Automatik R�cklauf-Begrenzung(Anhebung)
	0,		// Vstell  = 0		Hand Ventil F�hrungswert 0-10,0
	0,		// Ts_begr = 0		Tastzeit (>= 1 s)							 [s] * 10
	0,		// Tn_begr = 0		Nachstellzeit									 [s] * 10
	0,		// Kp_begr = 0		P-Verst�rkung								 [%/K] * 100
	0,		// Kd_begr = 0		D-Verst�rkung								 [%/K] * 100		
	
	0,		// KeBm_verz = 0	Verz�gerung Kesselbetriebsmeldung  [min]
	0,		//char KeAl_verz;	Verz�gerung KesselSt�rung  [min]
	0,		// DTLadWw = 0,0	Delta Temp. WWB Pufferladung ein 		[�C] * 10
	0,		// DTLadHyst =1,0	Delta Temp. Schalt-Hysterese
	0,		// PufMvea = 0	 	Hand Motorventil Kessel/Puffer( 1 = Kesselweg )
	0,		// UvHkea = 0	 	Hand Umschalt-Ventil Kessel/Puffer( 1 = Kesselweg )
	0,		//	int HkAbsenk;		// Absenkung HK, wenn PufferLadung
	0,		//	int	DTHeizSol;	// Delta Temp. Solare Heizung �ber Puffer
	0,		//	int	DTHeizKon;	// Delta Temp. Konventionelle Heizung �ber Puffer
	0,		//	char DTHeizStu;	// Delta Temp. Stufung von dT-Konventionell nach dT-Solar 
	0,		//	int	DTHeizFBH;	// Delta Temp. FB-Heizung 		Kes/Puff-Umschaltung
	0,		//	UINT PuffLadStell;// Hand Puffer-Ladung 0-100%
	0,		//	UINT PuffLadMin;	// Puffer-Ladung Minimum %
	0,		//	UINT PuffLadMax;	// Puffer-Ladung Maximum %
	0,		//	UINT PuffLadHkV;	// Puffer-Ladung HK-Ventil ge�ffnet % *10
	0,		//char	ExtAnf1_Ja;	// Externe Anforderung f�r Kessel g�ltig			***AnFre 04.12.2008
	0,		//char	ExtAnf2_Ja;	// Externe Anforderung f�r Kessel g�ltig			***AnFre 04.12.2008
	0,		//UINT TvsbSteig;			// langsame Sollwert-Steigerung     [K/30s] * 10
	0,		//UINT TvsbMinde;			// langsame Sollwert-Minderung     	[K/30s] * 10
	0,		//int	SchaltDiff;			// maximale Temp.-Abweichung abschalten	[ % ] *10
// 24.10.2012 Kessel-Freigabe entsprechend der Ventilstellung der W�rmepumpe: DM_WPU_Ventil
	0,	//int	WpVentEin;			// WP-Ventilstellung min	[ % ] *10
	0,	//int	WpVentAus;			// WP-Ventilstellung max	[ % ] *10
 },
 
 // Profil 1 Kessel 1
 {
	800,	// Tvma		= 90,0	max. Kesseltemp.						[�C] * 10
	400,	// Tvmi 	= 40,0	min. Kesseltemp.						[�C] * 10
	700,	// Trma 	= 60,0	max. R�cklauftemp.					 [�C] * 10	***AnFre	
	100,	// Kpr		= 4,00	P-Verst�rkung TRS-Begrenzg	[%/K] * 100	***AnFre
	250,	// Ttaup	= 10,0	Kessel-DT-Kaltstarttemp.	 		[K] * 10 	***AnFre
	50,		// Tvpa 	=  3,0	Kesselanhebung [HK1]				[�C] * 10
		0,	// TvPaWw =	 5,0	Kesselanhebung	[WW]	 			[�C] * 10	// ***AnFre 06.06.2012
	900,	// Tvsol10= 90,0	Solltemperatur bei 10V			[�C] * 10
	50,		// Tvsol0 =		5,0	Solltemperatur bei 0V				[�C] * 10
	0,		// Haut    = 0		Hand/Automatik
	0,		// Kesea	 = 0		Hand Kesselfreigabe ein/aus		
	0,		// Kestufe1= 0		Hand Kesselstufe 1  ein/aus		
	0,		// Kestufe2= 0	  Hand Kesselstufe 2  ein/aus
	0,		// Kestell = 0		Hand F�hrungswert 0-10,0 Volt 		
	0,		// Kespuea = 0    Hand Kesselpumpe ein/aus
	0,		// Kesklaz = 0	  Hand Kesselabsperrklappe auf/zu
	0,		// Kepuna  = 30	  Kesselpumpen- bzw. Absperrklappen-Nachlauf [min]
	0,		// char Kepuverz;	Kesselpumpen- Verz�gerung [min]

	0,		// Haut_begr= 0		Hand/Automatik R�cklauf-Begrenzung(Anhebung)
	0,		// Vstell  = 0		Hand Ventil F�hrungswert 0-10,0
	100,	// Ts_begr = 10,0	Tastzeit (>= 1 s)							 [s] * 10
	500,	// Tn_begr = 50,0	Nachstellzeit									 [s] * 10
	200,	// Kp_begr = 2,00	P-Verst�rkung								 [%/K] * 100
	0,		// Kd_begr = 0		D-Verst�rkung								 [%/K] * 100		

	10,		// KeBm_verz = 10	Verz�gerung Kesselbetriebsmeldung  [min]
	 2,		//char KeAl_verz;	Verz�gerung KesselSt�rung  [min]		***AnFre 06.03.2008
// ***AnFre 10.10.2007
	40,		// DTLadWw = 0,0	Delta Temp. WWB Pufferladung ein 		[�C] * 10
	10,		// DTLadHyst =1,0	Delta Temp. Schalt-Hysterese
	0,		// PufMvea = 0	 	Hand Motorventil Kessel/Puffer( 1 = Kesselweg )
// ***AnFre 31.01.2008
	0,		// UvHkea = 0	 	Hand Umschalt-Ventil Kessel/Puffer( 1 = Kesselweg )
	50,		//	int HkAbsenk;		// Absenkung HK, wenn PufferLadung
	 50,	//	int	DTHeizSol;	// DElta Temp. Solare Heizung �ber Puffer
// ***AnFre 08.04.2008
	200,	//	int	DTHeizKon;	// DElta Temp. Konventionelle Heizung �ber Puffer					[K] * 10 	***AnFre 08.04.2008
	1,		//	char DTHeizStu;	// DElta Temp. Stufung von dT-Konventionell nach dT-Solar [K] * 10 	***AnFre 08.04.2008
// ***AnFre 08.04.2008
	100,	//	int	DTHeizFBH;	// Delta Temp. FB-Heizung 		Kes/Puff-Umschaltung
// ***AnFre 20.10.2008
	0,		//	UINT PuffLadStell;// Hand Puffer-Ladung 0-100%
	250,	//	UINT PuffLadMin;	// Puffer-Ladung Minimum % *10
	600,	//	UINT PuffLadMax;	// Puffer-Ladung Maximum % *10
	600,	//	UINT PuffLadHkV;	// Puffer-Ladung HK-Ventil ge�ffnet % *10
	0,		//char	ExtAnf1_Ja;	// Externe Anforderung f�r Kessel g�ltig			***AnFre 04.12.2008
	0,		//char	ExtAnf2_Ja;	// Externe Anforderung f�r Kessel g�ltig			***AnFre 04.12.2008
	10,		//UINT TvsbSteig;			// langsame Sollwert-Steigerung     [K/30s] * 10
	 5,		//UINT TvsbMinde;			// langsame Sollwert-Minderung     	[K/30s] * 10
// Modulation nicht mehr im Programm ab	15.08.2013
	200,	//int	SchaltDiff;			// maximale Temp.-Abweichung abschalten	[ % ] *10
// 24.10.2012 Kessel-Freigabe entsprechend der Ventilstellung der W�rmepumpe: DM_WPU_Ventil
	200,	//int	WpVentEin;			// WP-Ventilstellung min	[ % ] *10
	100,	//int	WpVentAus;			// WP-Ventilstellung max	[ % ] *10
 },
 
 // Profil 2: Kessel 2 nicht vorh.

}; 
const char KE_PROFILE = sizeof ( Ke_Standparam ) / sizeof ( KeStandard );

/*----------------------------------------------------------------------------*/
/*						Liste von Standardwerten f�r verschiedene Warmwasserkreise			*/
/*----------------------------------------------------------------------------*/
const WwStandard  Ww_Standparam[] = {
 // Profil 0 (dummy)
 {
	0,		// Twwsol	= 0,0			Regel-Solltemp										[�C] * 10
	0,		// DTTwwlad = 0,0		delta	Regel-Ladetemperatur				[K] * 10
	0,		// TwwladLegio = 0,0	Speicher-Ladetemperatur bei therm.Desinf.	[�C] * 10 Nicht benutzt !!!
	0,		// DTTwwlbeg= 0,0		delta	Speicherlade-Beginn-Temp.			[K] * 10
	0,		// DTTwwlbegS= 0,0	delta	Speicherlade-Beginn-Temp.			[K] * 10
	0,		// DTTwwlend= 0,0		delta Speicherlade-Ende-Temperatur	[K] * 10
	0,		// Puwlna = 0				Ladepumpe Nachlaufzeit				[min]
	0,		// Puwtna = 0				Tauscherpumpe Nachlaufzeit		[min]	
	0,		// Puwzdau = 0			Zirkulationspumpe Abschaltdauer [std]
	{0,0},// Puwzab[2] =			Zirkulationspumpe Abschaltzeit [min][std]
	0,		// PuwwEin 	= 0			WW-Pumpen Einschaltdauer [min]
	0,		// Legjn	= 0				Legionellentod
	0,		// Legtag = 0				Legionellentage
	{0,0},// Legzeit[2]				Legionellen Einschaltzeit			[min][std]
	0,		// Legdau = 60			Legionellen Einschaltdauer		[min]
	0,		// LegSperr = 			Legionellen sperren						[std]
	0,		// Twwleg = 0,0			Legionellen Temperatur				[�C] * 10
	0,		// Vorrad = 0				Vorrangdauer	max							[min]
// ***AnFre 14.04.2009
	0,		//int  DTTwwVor;		// delta WW-Regel-Vorrang Temperatur	[K] * 10
	0,		//int	 DTRegSol;	// DeltaTemp	Regel-Sollwert Solar		[K] * 10
	0,		//int	 DTTwwUnter; 	// delta WW-Unterwert-Temp			[K] * 10
	0,		//int	 TwwHkAbsenk; // HK1-Absenk-Temp			[K] * 10

	0,		// Ts			= 0,0			Tastzeit (>= 1 s)						[s] * 10
	0,		// Tn			= 0,0			Nachstellzeit								[s] * 10
	0,		// Kp			= 0,00		P-Verst�rkung							[%/K] * 100
	0,		// Kd			= 0,00		D-Verst�rkung							[%/K] * 100
	0,		// Hub		= 0				Ventilhub									 [mm]
	0,		// Vst		= 0				Stellgeschwindigkeit		 [mm/min]
	0,		// Haut		= 0				Hand/Automatik
	0,		// Vstell	= 0				Hand Ventil stellen			0-10V Ventil	[%] * 10
	0,		// Lpea		= 0				Hand Ladepumpe ein/aus 
	0,		// Zpea		= 0				Hand Zirkpumpe ein/aus
	0,		// Tpea		= 0				Hand Tauscherpumpe ein/aus	
	0,		// Fzk		= 0				Filterzk. f. tsol						[s] * 10
	0,		// TabwMax = 0			maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	0,		// TabwZeit= 0			Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]	
	0,		// TvorrDiff = 0		Regelabweichung zur Aktivierung des WW-Vorrangs [K] * 10	
	0,		// TvorrZeit = 0		Mindestzeit zur Aktivierung des WW-Vorrangs [min]			
	0,		// ZpuAusLad = 0		ZirkPu bei Ladung ausschalten		
	0,		// char	FrLadBedarf;	// Freigabe f�r Schalten des Ladebetriebs nach Bedarfsanford. ( �ber Kommando WR_KASKADE )
	0,		// char	FrZirkBedarf;	// Freigabe f�r Schalten der Zirk.pumpe   nach Bedarfsanford. ( �ber Kommando WR_KASKADE )	
	0,		// AuswahlFuehler			// Speicherladung: Auswahl F�hler ( 1 = oben, 2 = unten, 0 = beide )																															
	0,		// TvpAnh = 0				Anhebung der Anforderung an den W�rmeerzeuger		[K] * 10		
	0,		// TempWWmin;			// minimale Geb�ude-Vorlauftemp. zur Bildung eines Alarms [�C] * 10
	0,		// TempWWminZeit;	// Zeitdauer der minimalen Geb�ude-Vorlauftemp. bis zum Alarm [min]	
	0,		// LadungMax;			// [ h ]			
	0,		// UINT	VentStell;	// WW-Ventilstellung bei Wiederanlauf der Regelung	[% *10]
	0,		// char	RVzu;			// Dauer RV ist ZU --> 	kein TWW-Bedarf 	f�r Kessel KES:		[min]
	0,		// char	RVauf;		// Dauer RV ist AUF --> wieder TWW-Bedarf	f�r Kessel KES:		[min]
	0,		// UINT	RegHyst;	// DT TW2 > Twwsol ---> Regelventil ZU			[K] * 10
	0,		// UINT	VentGrenz;// WW-Ventilstellung max. bei Kesseltemp. zu niedrig	 [�C] * 10
	0,		//	char AbsTag;		// Absenk-Tage (Mo,Di.. wie Legionelle)
	0,		//	int  TwwAbs;		// Absenk Soll-Temperatur
	0,		//	int		BusTauPuSoll		// Sollwert Tauscherpumpe, wenn WILO-Modbus
	0,		//	int		BusZirPuSoll		// Sollwert Zirk.pumpe, wenn WILO-Modbus
	0,		//	int		BusZirPuSollLad	// Sollwert bei Ladebetrieb Zirk.pumpe, wenn WILO-Modbus
 },
 
 // Profil 1 
 {
	600,	// Twwsol		= 60,0		WW-Solltemp										[�C] * 10
	 20,	// DTTwwlad 	= 2,0		delta	Speicher-Ladetemperatur				[K] * 10
	700,	// TwwladLegio = 70,0	Speicher-Ladetemperatur bei therm.Desinf.	[�C] * 10
	-50,	// DTTwwlbeg	= 40,0		Speicherlade-Beginn-Kessel	[�C] * 10
	-20,	// DTTwwlbegS	= 50,0		Speicherlade-Beginn-Solar		[�C] * 10
	-10,	// DTTwwlend	= 58,0		Speicherlade-Ende-Temperatur	[�C] * 10
	1,		// Puwlna 	= 1				Ladepumpe Nachlaufzeit				[min]
	1,		// Puwtna 	= 5				Tauscherpumpe Nachlaufzeit				[min]	
	0,		// Puwzdau 	= 0				Zirkulationspumpe Abschaltdauer [std]
	{0,23},	// Puwzab[2]				Zirkulationspumpe Abschaltzeit [min][std]
	10,		// PuwwEin 	= 0				WW-Pumpen Einschaltdauer [min]
	0,		// Legjn		= 1				Legionellentod
	0x12,	// Legtag 	= Mo+Do		Legionellentage
	{30,14},// Legzeit[2]				Legionellen Einschaltzeit			[min][std]
	60,		// Legdau 	= 60			Legionellen Einschaltdauer		[Minuten]		*** AnFre 25.09.2007
	24,		// LegSperr = 48			Legionellen sperren						[std]
	650,	// Twwleg 	= 62,0		Legionellen Temperatur				[�C] * 10
	30,		// Vorrad 	= 30			Vorrangdauer	max							[min]
// ***AnFre 14.04.2009
	 30,	//int  DTTwwVor;			delta	WW-Regel-Vorrang Temperatur	[K] * 10
	30,		//int	 DTRegSol;		 	DeltaTemp	Regel-Sollwert Solar		[K] * 10
	-80,	//int	 DTTwwUnter; 		delta	WW-Unterwert-Temp			[K] * 10
	50,		//int	 TwwHkAbsenk;  	HK1-Absenk-Temp			[K] * 10

	20,		// Ts				= 5,0			Tastzeit (>= 1 s)						[s] * 10
	100,	// Tn				= 10,0		Nachstellzeit								[s] * 10
	125,	// Kp				= 1,25		P-Verst�rkung							[%/K] * 100
	0,		// Kd				= 0,00		D-Verst�rkung							[%/K] * 100
	25,		// Hub			= 25			Ventilhub									 [mm]
	25,		// Vst			= 25			Stellgeschwindigkeit		 [mm/min]
	0,		// Haut			= 0				Hand/Automatik
	0,		// Vstell		= 0				Hand Ventil stellen			0-10V Ventil	[%] * 10
	0,		// Lpea			= 0				Hand Ladepumpe ein/aus 
	0,		// Zpea			= 0				Hand Zirkpumpe ein/aus
	0,		// Tpea			= 0				Hand Tauscherpumpe ein/aus
	200,	// Fzk			= 60,0		Filterzk. f. tsol						[s] * 10	***AnFre
	100,	// TabwMax = 10,0			maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	60,		// TabwZeit= 60				Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	50,		// TvorrDiff = 5,0		Regelabweichung zur Aktivierung des WW-Vorrangs [K] * 10	
	5,		// TvorrZeit = 5			Mindestzeit zur Aktivierung des WW-Vorrangs [min]					
	0,		// ZpuAusLad = 1			ZirkPu bei Ladung ausschalten					
	0,		// char	FrLadBedarf  = 0 Freigabe f�r Schalten des Ladebetriebs nach Bedarfsanford. ( �ber Kommando WR_KASKADE )
	0,		// char	FrZirkBedarf = 0 Freigabe f�r Schalten der Zirk.pumpe   nach Bedarfsanford. ( �ber Kommando WR_KASKADE )	
	0,		// AuswahlFuehler			Speicherladung: Auswahl F�hler ( 1 = oben, 2 = unten, 0 = beide )																															
	0,		// TvpAnh = 0				Anhebung der Anforderung an den W�rmeerzeuger		[K] * 10		
	400,	// TempWWmin = 50,0		minimale Geb�ude-Vorlauftemp. zur Bildung eines Alarms [�C] * 10
	60,		// TempWWminZeit			Zeitdauer der minimalen Geb�ude-Vorlauftemp. bis zum Alarm [min]	
	8,		// LadungMax;					[ h	]	
	100,	// UINT	VentStell =10,0	WW-Ventilstellung bei Wiederanlauf der Regelung	[% *10]
	5,		// char	RVzu;			// Dauer RV ist ZU --> 	kein TWW-Bedarf 	f�r Kessel KES:		[min]
	1,		// char	RVauf;		// Dauer RV ist AUF --> wieder TWW-Bedarf	f�r Kessel KES:		[min]
	20,		// UINT	RegHyst;	// DT TW2 > Twwsol ---> Regelventil ZU			[K] * 10
	1000,	// UINT	VentGrenz;// WW-Ventilstellung max. bei Kesseltemp. zu niedrig	 [�C] * 10
	0x00,	//	char AbsTag;=kein Absenk-Tage (Mo,Di.. wie Legionelle)
	400,	//	int  TwwAbs;			Absenk Soll-Temperatur
// ***AnFre 14.08.2013
	800,	//	int		BusTauPuSoll		// Sollwert Tauscherpumpe, wenn WILO-Modbus
	700,	//	int		BusZirPuSoll		// Sollwert Zirk.pumpe, wenn WILO-Modbus
	800,	//	int		BusZirPuSollLad	// Sollwert bei Ladebetrieb Zirk.pumpe, wenn WILO-Modbus
 },	

};
const char WW_PROFILE = sizeof ( Ww_Standparam ) / sizeof ( WwStandard );

/*----------------------------------------------------------------------------*/
/*	***AnFre		Liste von Standardwerten f�r verschiedene Warmwasser-Temp-Profile			*/
/*----------------------------------------------------------------------------*/
const PrStandard  Pr_Standparam[] = {
 // Profil 0 (dummy)
 {
	0,		// Zeit					Profil-Einschaltzeit			[min]
	0,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 3				Profil-Einschaltdauer		[std]
	0,		// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
	0,		// Zeit					Profil-Einschaltzeit			[min]
	0,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 3				Profil-Einschaltdauer		[std]
	0,		// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
	0,		// Zeit					Profil-Einschaltzeit			[min]
	0,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 3				Profil-Einschaltdauer		[std]
	0,		// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
	0,		// Zeit					Profil-Einschaltzeit			[min]
	0,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 3				Profil-Einschaltdauer		[std]
	0,		// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
 },
 // Profil 1 
 {
	0,		// Zeit							Profil-Einschaltzeit			[min]
	5,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 3				Profil-Einschaltdauer		[std]
	550,	// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
	0,		// Zeit							Profil-Einschaltzeit			[min]
	11,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 2				Profil-Einschaltdauer		[std]
	550,	// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
	0,		// Zeit							Profil-Einschaltzeit			[min]
	17,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 3				Profil-Einschaltdauer		[std]
	550,	// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
	0,		// Zeit							Profil-Einschaltzeit			[min]
	23,		// ZeitStd					Profil-Einschaltzeit			[std]
	0,		// Dauer 	= 3				Profil-Einschaltdauer		[std]
	450,	// Twwsol	= 50,0		WW-Solltemp							[�C] * 10
 },	
};
const char PR_PROFILE = sizeof ( Pr_Standparam ) / sizeof ( PrStandard );

/*----------------------------------------------------------------------------------*/
/*				Liste von Standardwerten f�r verschiedene Vorregelkreise (Netztrennung)		*/
/*----------------------------------------------------------------------------------*/
const NtStandard  Nt_Standparam[] = {
 // Profil 0 (dummy)
 {
	0,		//char	FuehrWt;	// F�hrungs-Tauscher

	0,		// Ts 		=  0,0 		Tastzeit (>= 1 s)							[s] * 10
	0,		// Tn 		=  0,0 		Nachstellzeit									[s] * 10
	0,		// Kp		 	=  0,00		P-Verst�rkung								[%/K] * 100
	0,		// Kd		 	=  0,00		D-Verst�rkung								[%/K] * 100
	0,		// Kpr		=  0,00		P-Verst�rkung TRS-Begrenzg	[%/K] * 100
	0,		// Tvma		=  0,0		max. Vorlauftemp.						.[�C] * 10		
	0,		// Tvmi		=  0,0		min. Vorlauftemp.						 [�C] * 10		
	0,		// Trma 	=  0,0		max. R�cklauftemp.					 [�C] * 10		
	0,		// Tvpa =  0,0		Kesselanhebung								[�C] * 10
	0,		// TvPaWw =	0,0		Kesselanhebung	WW			 				[�C] * 10	//***AnFre
	0,		// Fzk		=  0,0		Filterzk. f. tsol							[s] * 10
	0,		// Hub		=  0			Ventilhub										 [mm]
	0,		// Vst		=  0			Stellgeschwindigkeit		 [mm/min]
	0,		// Haut		=  0			HAND/AUTO-Umschaltung
	0,		// Vstell	=  0			Hand Ventil stellen			0-10V Ventil	[%] * 10
	0,		// Puea =  0			Pumpe	ein/aus bei Handstellung
	0,		// TabwMax = 10		maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	0,		// TabwZeit= 60		Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	0,		// char	Puna;			Pumpennachlaufzeit										[min]	

// Parameter f�r 2 Tauscher (Tauscher-Folge)
	0,		// FuehrWtFest	= 0    F�hrungs-Tauscher fest vorgegeben, wenn ungestoert	
	0,		// WtWechseln		= 0    laufzeitabh. Umschalten des F�hrungs-Tauschers  [h]
	0,		// FolgeWtAus		= 0,0  Abschalten des Folge-Tauschers, wenn VL - RL des F�hrungs-Tauschers zu klein [K] * 10 	
	0,		// WtSchaltDiff	= 0,0  Schaltdifferenz zum Abschalten des F�hrungs-Tauschers [K] * 10 
	0,		// Einkrit			= 0,0  Einschaltkriterium Folge-Tauscher	[K*min] * 10
	0,		// Auskrit			= 0,0  Ausschaltkriterium Folge-Tauscher	[K*min] * 10
	0,		// KlAZ					= 0    Klappenstellung bei Hand	
	0,		// KlappeVerz		= 0		 Verz�gerung des Schlie�ens der Klappe [min]
	
	// Sollwert-Anhebung
	0,		// Ts_anh				= 0		 Tastzeit (>= 1 s)							 [s] * 10
	0,		// Tn_anh				= 0		 Nachstellzeit									 [s] * 10
	0,		// Kp_anh				= 0		 P-Verst�rkung								 [%/K] * 100
	0,		// Kd_anh				= 0		 D-Verst�rkung								 [%/K] * 100	
 },
 
 // Profil 1
 {
		1,	//char	FuehrWt;	// F�hrungs-Tauscher

	100,	// Ts 		= 10,0 		Tastzeit (>= 1 s)							[s] * 10
	400,	// Tn 		= 50,0 		Nachstellzeit									[s] * 10
	125,	// Kp 		=  2,00		P-Verst�rkung								[%/K] * 100
	0,		// Kd 		=  0,00		D-Verst�rkung								[%/K] * 100
	225,	// Kpr		=  2,25		P-Verst�rkung TRS-Begrenzg	[%/K] * 100
	950,	// Tvma		= 95,0		max. Vorlauftemp.						.[�C] * 10	System 90/70		
	200,	// Tvmi		= 20,0		min. Vorlauftemp.						 [�C] * 10		
	700,	// Trma 	= 70,0		max. R�cklauftemp.					 [�C] * 10		
	30,		// Tvpa 	=  3,0	Kesselanhebung [HK1]				[�C] * 10
	 0,		// TvPaWw =	 5,0	Kesselanhebung	[WW]	 			[�C] * 10	//***AnFre
	600,	// Fzk		= 60,0		Filterzk. f. tsol							[s] * 10
	25,		// Hub		= 25			Ventilhub										 [mm]
	25,		// Vst		= 25			Stellgeschwindigkeit		 [mm/min]
	0,		// Haut		=  0			HAND/AUTO-Umschaltung
	0,		// Vstell	=  0			Hand Ventil stellen			0-10V Ventil	[%] * 10
	0,		// Puea =  0			Pumpe	ein/aus bei Handstellung
	100,	// TabwMax = 10		maximale Regelabweichung zur Bildung eines Alarms [K] * 10
	60,		// TabwZeit= 60		Zeitdauer der maximalen Regelabweichung bis zum Alarm [min]
	3,		// char	Puna;			Pumpennachlaufzeit										[min]	

// Parameter f�r 2 Tauscher (Tauscher-Folge)
	0,		// FuehrWtFest	= 0    F�hrungs-Tauscher fest vorgegeben, wenn ungestoert	
	50,		// WtWechseln		= 50   laufzeitabh. Umschalten des F�hrungs-Tauschers  [h]
	30,		// FolgeWtAus		= 3,0  Abschalten des Folge-Tauschers, wenn VL - RL des F�hrungs-Tauschers zu klein [K] * 10 	
	80,		// WtSchaltDiff	= 8,0  Schaltdifferenz zum Abschalten des F�hrungs-Tauschers [K] * 10 
 200,		// Einkrit			= 20,0 Einschaltkriterium Folge-Tauscher	[K*min] * 10
	50,		// Auskrit			= 5,0  Ausschaltkriterium Folge-Tauscher	[K*min] * 10
	0,		// KlAZ					= 0    Klappenstellung bei Hand	
	1,		// KlappeVerz		= 0		 Verz�gerung des Schlie�ens der Klappe [min]

	// Sollwert-Anhebung
	10,		// Ts_anh 			= 1,0	 Tastzeit (>= 1 s)						[s] * 10
	12000,// Tn_anh				= 1200,0 	Nachstellzeit							[s] * 10
	100,	// Kp_anh 			= 1,00 P-Verst�rkung								[%/K] * 100
	0,		// Kd_anh				= 0		 D-Verst�rkung								[%/K] * 100	

 },

};
const char NT_PROFILE = sizeof ( Nt_Standparam ) / sizeof ( NtStandard );


/*----------------------------------------------------------------------------------*/
/*				Liste von Standardwerten f�r Solar-Regelkreise		*/
/*----------------------------------------------------------------------------------*/
const SoStandard  So_Standparam[] = {
 // Profil 0 (dummy)
	{
		0,	// TSolBeg = 0	 		erforderliche Mindesttemp. am Kollektor-F�hler ( Solar-Lad. ein ) [�C] * 10
		0,	// TSolEnd = 0	 		Min. Temp. am Kollektor-F�hler ( Solar-Lad. aus ) [�C] * 10
		0,	// SolAbDau = 0			Solar-Abschaltdauer [std]
	{0,0},// SolAb[2] =				Solar-Abschaltzeit [min][std]
		0,	// TS6Max = 0	 		Max. Temp. am oberen Puffer-F�hler ( Solar-Lad. aus ) [�C] * 10
		0,	// TW3Max = 0	 		Max. Temp. am oberen Speicher-F�hler ( Solar-Lad. aus ) [�C] * 10
		0,	// TW2Max = 0	 		Max. Temp. VL-Zirkulation ( Solar-Lad. aus ) [�C] * 10
		0,	// V2Min = 0			Min. Kollektor-Vol.Strom
		0,	// TDiffEnd = 0	 		Differenz Kollektor - unterer Puffer-F�hler ( Solar-Lad. aus )	[K] * 10
		0,	// DTSoHk		= 0			Delta-Temp Solar-Heizung	 	TS3-TH2
		0,	// DTSoWwZ	= 0			Delta-Temp Solar-WW-Zirk. 	TS2-TW2
		0,	// DTSoWwL	= 0			Delta-Temp Solar-WW-Ladung 	TS2-TW4
		0,	// DTKoll	= 0				Delta-Temp KollektorBetrieb ein 	TS1>TS6
		0,	// DTPuff	= 0				Delta-Temp Pufferbetrieb ein 	TS6>TW2oder3+DTSoWwZoderL
		0,	// DTPufLad	= 0			Delta-Temp Puffer-Ladung ein 	TS4>TS7+DT
		0,	// TS1Leg = 0	 			Legionellen-Temp. am Kollektor ( Solar-Legio ein ) [�C] * 10
		0,	// TS6Leg = 0	 			Legionellen-Temp. am oberen Puffer-F�hler ( Solar-Legio ein ) [�C] * 10
		0,	// LegPause = 0			Legionellen Pause						[std]
		0,	// RVSoMax	= 0			RegelVentil-Solar maximale �ffnung 
		0,	// Puna = 0	 				Kollektorpumpen-Nachlaufzeit	[min]
		0,	// Haut = 0	 				HAND/AUTO-Umschaltung
		0,	// SolPuea = 0	 		Hand Solarpumpe ein/aus
		0,	// PufPuea = 0	 		Hand Pufferpumpe ein/aus
		0,	// KolMvea = 0	 		Hand MotorVentil Kollektor auf/zu
		0,	// PufMvea = 0	 		Hand MotorVentil Puffer auf/zu
		0,	// SolMvea = 0	 		Hand MotorVentil TWW-Solar auf/zu
		0,	// KwMvst = 0	 			Hand MotorVentil KaltWasser stellen
		0,	// NotCode =0				Code und Eingabefeld f�r Notbetrieb
		0,	// NotTemp =0				Temperatur f�r Notbetrieb
		0,	// zNotBetr >20			Z�hler 20 Sekunden	
		0,	// VerzKollEin			Verz�gerung Einschalten Kollektorbetrieb [min]
		0,	// VerzPuffEin			Verz�gerung Einschalten Pufferbetrieb [min]
		0,	//	int		SS1_Skal0;	Skalierung Solar-Sensor Watt/m^2 bei 0 Volt
		0,	//	int		SS1_Skal10;	Skalierung Solar-Sensor Watt/m^2 bei 10 Volt
//10.04.2008		0,	// SS1_Off					Sensor-Offset
		0,	// SS1_Filter				Sensor-Filter in ganzer Zahl
	 	0,	// vts23Al = 20			Verz�gerung des T3>T2-Alarm
		0,	// TS5Max = 0	 			Max. Temp. TS5 ( Solar-Pmpe. aus ) [�C] * 10
		0,	//int		TS2Frost;		Frostgefahr an der Solar-Pumpe						 [�C] * 10
		0,	//int KwVol0;				Kaltwasser-Volumenstr. f�r KW-Ventil 0,0% offen	 					[m^3 ] *10
		0,	//int KwVol100;			Kaltwasser-Volumenstr. f�r KW-Ventil 100,0% offen 				[m^3 ] *10
		0,	//int		KwVentMin;	Kaltwasser-Ventilstellung min.														[ % ] *10
		0,	//int		KwSolVolMax;Kaltwasser-Volumenstr. Max., wenn Solar  KW-Ventil 				[m^3 ] *10
		0,	//int		KwSolVentMinKaltwasser-Ventilstellung Mindest�ffnung	Vorw�rmerweg		[ % ] *10
		0,	//UINT	DzSoPuKol;	Drehzahl SolarPumpe Kollektorbetrieb												[ % ] *10
		0,	//UINT	DzSoPuPuf;	Drehzahl SolarPumpe Pufferbetrieb													[ % ] *10
		0,	//UINT	DzSoPuHand;	Drehzahl SolarPumpe Handbetrieb												[ % ] *10
// 03.08.2011 Pr�fbetrieb (Schnupper-Schaltung)
		0,	//	int		PruefSS1;		// pr�fen ab SS1 > 300 W/m*2
		0,	//	int		PruefTS1;		// oder pr�fen ab TS1 > 20,0 �C
		0,	//	int		PruefDauer;	// Pumpe ein f�r 3 Minuten
		0,	//	int		PruefSperre;// Pr�fen sperren f�r 60 Minuten
// ***AnFre 06.06.2012
		0,	// int		RvHksStart;	// RV-HKS Stellung f�r Pufferbeladung starten  [ % ] *10
		0,	// int		RvHksEnde;	// RV-HKS Stellung f�r Pufferbeladung beenden  [ % ] *10
		0,	// int		PumStart;		// L-Pumpen-Drehzahl f�r Pufferbeladung starten, wenn Solare Ladung Ein   [ % ] *10
		0,	// int		PumEnde;		// L-Pumpen-Drehzahl f�r Pufferbeladung beenden, wenn Solare Ladung Ein   [ % ] *10
// ***AnFre 14.08.2013
		0,	// int		BusPufPuSoll;	// Sollwert Pufferpumpe, wenn WILO-Modbus
	},
	// Profil 1	
	{
		350,// TSolBeg = 31,0	 	erforderliche Mindesttemp. am Kollektor-F�hler ( Solar-Lad. ein ) [�C] * 10
		300,// TSolEnd = 29,0	 	Temp. am Kollektor-F�hler ( Solar-Lad. aus ) [�C] * 10
			0,// SolAbDau = 0			Solar-Abschaltdauer [std]
	{0,10},// SolAb[2] =			Solar-Abschaltzeit [min][std]
		980,// TS6Max = 95,0		Max. Temp. am oberen Puffer-F�hler ( Solar-Lad. aus ) [�C] * 10
		700,// TW3Max = 70,0	 	Max. Temp. am oberen Speicher-F�hler ( Solar-Lad. aus ) [�C] * 10
		680,// TW2Max =65,0	 		Max. Temp. VL-Zirkulation ( Solar-Lad. aus ) [�C] * 10
		300,// V2Min = 0,500		Min. Kollektor-Vol.Strom
		40,	// TDiffEnd = 4,0	 	Differenz Kollektor - unterer Puffer-F�hler ( Solar-Lad. aus )	[K] * 10
		60,	// DTSoHk		= 6,0		Delta-Temp Solar-Heizung TS3-TH2
		40,	// DTSoWwZ	= 4,0		Delta-Temp Solar-WW-Zirk. 	TS2-TW2
		50,	// DTSoWwL	= 5,0		Delta-Temp Solar-WW-Ladung 	TS2-TW4
	  80, // DTKoll	= 8,0				Delta-Temp KollektorBetrieb ein (TS1 > TH5 + DTKoll) oder (TS1 > TS7)
		50,	// DTPuff	= 5,0				Delta-Temp Pufferbetrieb ein 	TS6>TW2oder3+DTSoWwZoderL
		30,	// DTPufLad	= 2,0		Delta-Temp Puffer-Ladung ein 	TS4>TS7+DT
		850,	// TS1Leg = 75,0	Legionellen-Temp. am Kollektor ( Solar-Legio ein ) [�C] * 10
		850,	// TS6Leg = 70,0	Legionellen-Temp. am oberen Puffer-F�hler ( Solar-Legio ein ) [�C] * 10
		12,	// LegPause = 12		Legionellen Pause						[std]
		800,// RVSoMax	= 80,0	RegelVentil-Solar maximale �ffnung [%] 
		4,	// Puna = 4	 				Kollektorpumpen-Nachlaufzeit	[min*2]
		0,	// Haut = 0	 				HAND/AUTO-Umschaltung
		0,	// SolPuea = 0	 		Hand Solarpumpe ein/aus
		0,	// PufPuea = 0	 		Hand Pufferpumpe ein/aus
		0,	// KolMvea = 0	 		Hand MotorVentil Kollektor auf/zu
		0,	// PufMvea = 0	 		Hand MotorVentil Puffer auf/zu
		0,	// SolMvea = 0	 		Hand MotorVentil TWW-Solar auf/zu
		0,	// KwMvst = 0		 		Hand MotorVentil KaltWasser stellen
		0,	// NotCode =0				Code und Eingabefeld f�r Notbetrieb
	350,	// NotTemp =35,0		Temperatur f�r Notbetrieb
		99,	// zNotBetr >20			Z�hler 20 Sekunden	
		8,	// VerzKollEin			Verz�gerung Einschalten Kollektorbetrieb [min]
		5,	// VerzPuffEin			Verz�gerung Einschalten Pufferbetrieb 		[min]
	-30,	//	int		SS1_Skal0;	Skalierung Solar-Sensor Watt/m^2 bei 0 Volt
	1300,	//	int		SS1_Skal10;	Skalierung Solar-Sensor Watt/m^2 bei 10 Volt
//10.04.2008	-20,	// SS1_Off					Sensor-Offset
		2,	// SS1_Filter				Sensor-Filter in ganzer Zahl
	 	20,	// vts23Al = 20			Verz�gerung des T3>T2-Alarm 10 Minuten
	1100,	// TS5Max = 0	 			Max. Temp. TS5 ( Solar-Pmpe. aus ) [�C] * 10
		30,	//int		TS2Frost;		Frostgefahr an der Solar-Pumpe						 [�C] * 10
		40,	//int KwVol0;				Kaltwasser-Volumenstr. f�r KW-Ventil 0,0% AB->B Solar			[m3 * 10]
		15,	//int KwVol100;			Kaltwasser-Volumenstr. f�r KW-Ventil 100,0% AB->A Nachw�rmer
	 500,	//int KwVentMin; 		Kaltwasser-Ventilstellung min.			[ % ]
	 100,	//int	KwSolVolMax;	Kaltwasser-Volumenstr. Max., wenn Solar  KW-Ventil 				[m^3 ] *10
		 0,	//int	KwSolVentMin;	Kaltwasser-Ventilstellung Mindest�ffnung	Vorw�rmerweg		[ % ] *10
	 800,	//UINT	DzSoPuKol;	Drehzahl SolarPumpe Kollektorbetrieb											[ % ] *10
	 400,	//UINT	DzSoPuPuf;	Drehzahl SolarPumpe Pufferbetrieb													[ % ] *10
		0,	//UINT	DzSoPuHand;	Drehzahl SolarPumpe Handbetrieb												[ % ] *10
// 03.08.2011 Pr�fbetrieb (Schnupper-Schaltung)
	300,	//	int		PruefSS1;		// pr�fen ab SS1 > 300 W/m*2
	200,	//	int		PruefTS1;		// oder pr�fen ab TS1 > 20,0 �C
		0,	//	int		PruefDauer;	// Pumpe ein f�r 3 Minuten
	 60,	//	int		PruefSperre;// Pr�fen sperren f�r 60 Minuten
// ***AnFre 06.06.2012
	600,	// int		RvHksStart;	// RV-HKS Stellung f�r Pufferbeladung starten  [ % ] *10
	800,	// int		RvHksEnde;	// RV-HKS Stellung f�r Pufferbeladung beenden  [ % ] *10
	700,	// int		PumStart;		// L-Pumpen-Drehzahl f�r Pufferbeladung starten, wenn Solare Ladung Ein   [ % ] *10
	500,	// int		PumEnde;		// L-Pumpen-Drehzahl f�r Pufferbeladung beenden, wenn Solare Ladung Ein   [ % ] *10
// ***AnFre 14.08.2013
	400,	// int		BusPufPuSoll;	// Sollwert Pufferpumpe, wenn WILO-Modbus
	},
};
const char SO_PROFILE = sizeof ( So_Standparam ) / sizeof ( SoStandard );		 	

/*----------------------------------------------------------------------------------------*/
/*  							Liste von Standardwerten f�r Benutzersteuerung mit UNI-Elementen				*/
/*----------------------------------------------------------------------------------------*/
const UniStandard  Uni_Standparam[] = {
 // Profil 0 (dummy)
	{
		 0,		// char	Loader;			// Testparameter
	},
	// Profil 1
	{
		10,		// char	Loader;			// Testparameter
	},
};
const char UNI_PROFILE = sizeof ( Uni_Standparam ) / sizeof ( UniStandard );		




/*----------------------------------------------------------------------------------*/

// Dimensionsnamen f�r Z�hler
const zdname ze_dim_namen[10] = {
//   Text  , Einheit,	Basiseinheit  dim_idx
	{"      ", 0x00,		0},						// 0
	{"GJ    ", 0xE0,		8},						// 1		(E_GIGA + E_JOULE)
	{"MJ    ", 0xA0,		8},						// 2		(E_MEGA + E_JOULE)
	{"kJ    ", 0x60,		8},						// 3		(E_KILO + E_JOULE)
	{"MWh   ", 0x83,		7},						// 4		(E_MEGA + E_WATT + E_STUNDE)
	{"kWh   ", 0x43,		7},						// 5		(E_KILO + E_WATT + E_STUNDE)
	{"m    ", 0x08,		9},						// 6		(E_QMETER)
	{"Wh    ", 0x03,		0},						// 7		(E_WATT + E_STUNDE)						Basiseinheit
	{"J     ", 0x40,		0},						// 8		(E_JOULE)											Basiseinheit
	{"l     ", 0x04,		0},						// 9		(E_LITER)											Basiseinheit
}; 


// Funktionsnamen f�r Schnittstellen
const char fu_namen[9][7] = {
	{"      "},  // #define NULL_FU         0         // keine Funktion                
	{"GBUS  "},  // #define GBUS_FU         1         // RS485 RIEcon Geb�udebus       
	{"FUNK  "},  // #define FUNK1_FU        2         // RS485 Funkmodul EnOcean       
	{"GENI  "},  // #define GENI1_FU        3         // RS485 Genibus Pumpen          
	{"MBUS  "},  // #define MBUS1_FU        4         // RS232 MBUS                    
	{"TEST  "},  // #define GBUS1_FU        5         // RS485 Test Geb�udebus         
	{"MODBUS"},  // #define MODBUS1_FU      6         // RS485 oder RS232 MODBUS Master
	{"KNXBUS"},  // #define KNXBUS1_FU      7         // KNX/EIB �ber RIEcon66-SPL-KNX 
	{"ANYBUS"},  // #define ANYBUS1_FU      8         // RS232 Anybus                  
};	

/* Z�hlerdimensionierungen f�r Systemstart 	(leerer EEPROM, Kaltstart 67 oder Kaltstart 99)  */
// Stichtag 01.01.00 ( {0,1,1} ) verhindert Stichtag !
// Stichtag ausf�hren : konfig Bit 4 setzen (konfig = 0x10)

const zaehldim ze_dimsys[20 + MBUSANZ] = {
// Der Impulswert wird als Exponent zur Basiseinheit eingetragen.

// komma, dim_idx, faktor, exp, konfig, medium, name_idx, stich_tag, reserve, zname(Z�hlername),	znumm(Z�hlernummer)
// R36-E2
	{0, 			0,			0,			0,		0,			0,			1,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN3
	{0,				0,			0,			0,		0,			0,			2,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN4
	{0,				0,			0,			0,		0,			0,			3,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN5
	{0,				0,			0,			0,		0,			0,			4,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN6
	{3,				6,			0,			0,		0,			0,			5,			{1,1,1},	 {0},			"               ", "               "},// ZIN7		// war Kaltwasser
	{2,				6,			0,			1,		0,			0,			6,			{0,1,1},	 {0},			"HEIZUNG        ", "               "},// ZIN8		// 1 Impuls =   10 l  (0,01m�)
	{3,				6,			0,			0,		0,			0,			7,			{0,1,1},	 {0},			"SOLAR-EINTRAG  ", "               "},// ZIN9		// 1 Impuls =    1 l  (0,001m�)
	{3,				6,			0,			0,		0,			0,			8,			{0,1,1},	 {0},			"WARMWASSER     ", "               "},// ZIN10	// 1 Impuls =   10 l  (0,01m�)
// R37_1
	{1,				6,			0,			2,		0,			0,			11,			{1,1,1},	 {0},			"GAS            ", "               "},// ZIN11	// 1 Impuls =  100 l  (0,1m�)
	{3,				6,			0,			0,		0,			0,			12,			{1,1,1},	 {0},			"KALTWASSER TWE ", "               "},// ZIN12	// 1 Impuls =   1 l  (0,001m�)
	{0,				0,			0,			0,		0,			0,			13,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN13
	{0,				0,			0,			0,		0,			0,			14,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN14
	{0,				0,			0,			0,		0,			0,			15,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN15
	{0,				0,			0,			0,		0,			0,			16,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN16
// R37_2
	{1,				6,			0,			2,		0,			0,			21,			{0,1,1},	 {0},			"               ", "               "},// ZIN21	// 1 Impuls =  100 l  (0,1m�)
	{0,				0,			0,			0,		0,			0,			22,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN22
	{0,				0,			0,			0,		0,			0,			23,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN23	// 1 Impuls = 1000000 Wh (1MWh)
	{0,				0,			0,			0,		0,			0,			24,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN24
	{0,				0,			0,			0,		0,			0,			25,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN25
	{0,				0,			0,			0,		0,			0,			26,			{0,1,1},	 {0},			"UNBEKANNT      ", "               "},// ZIN26
// MBus
#if MBUSANZ > 0
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,31,	{1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z01
#endif
#if MBUSANZ > 1
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,32,	{1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z02
#endif
#if MBUSANZ > 2
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,33,	{1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z03
#endif
#if MBUSANZ > 3
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,34,	{1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z04
#endif
#if MBUSANZ > 4
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,35, {1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z05
#endif
#if MBUSANZ > 5
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,36,	{1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z06
#endif
#if MBUSANZ > 6
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,37,	{1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z07
#endif
#if MBUSANZ > 7
	{3,				4,			0,			0,		Z_KONFIG_STICHTAG,0,38,	{1,1,1},	 {0},			"UNBEKANNT      ", "               "},// MB_Z08
#endif
};	


/*------------------------------------------------------------------------------------*/
/*  							Liste von Standardwerten f�r Skalierung von Analogausg�ngen					*/
/*------------------------------------------------------------------------------------*/
//Skal bei 0% und 100%			Werteingabe in [Volt] * 100

const aask R36_37_Standparam[][5] = {
	{	// R36
		{   0, 1000},	// AA1
		{   0, 1000},	// AA2
		{   0,    0},	// 
		{   0,    0},	//
	},

	{	// R37_1
		{   0, 1000},	// AA1
		{   0, 1000},	// AA2
		{   0, 1000},	// AA3
		{   0, 1000},	// AA4
	},

	{	// R37_2
		{   0, 1000},	// AA1
		{   0, 1000},	// AA2
		{   0, 1000},	// AA3
		{   0, 1000},	// AA4
	},

	{	// R37_3
		{   0, 1000},	// AA1
		{   0, 1000},	// AA2
		{   0, 1000},	// AA3
		{   0, 1000},	// AA4
	},

	{	// R37_4
		{   0, 1000},	// AA1
		{   0, 1000},	// AA2
		{   0, 1000},	// AA3
		{   0, 1000},	// AA4
	},	
};

/*--------------------------------------------------------------------------------------*/
/*				Liste von Standardwerten f�r die Skalierung der universellen Analogeing�nge		*/
/*--------------------------------------------------------------------------------------*/
// Brandenburg, Klosterquartier, Heizung
const sAnaInpPara AnaInpStandardPara[] = {
// Beispiel f�r 	AE_UNI1 : Druck R�cklauf Anlage: 2 V = 0,00, 10 V = 6,00 bar
//	 {-150,				// Skalierung 0 V
//		600,				// Skalierung 10 V
//		5,					// Filterzeitkonstante [s]		
//		200,				// UGW	2,00 bar
//		0,					// OGW												kein OGW
//		20},				// Hysterese Grenzwerte 0,2 bar

// ***AnFre			// AE_UNI1  !!! Reserviert f�r Solar-Sensor (z.Zt. andere Skalierung)
	 {0,					// Skalierung 0 V
		1000,				// Skalierung 10 V
		5,					// Filterzeitkonstante [s]		
		0,					// UGW												keine Grenzwerte
		0,					// OGW
		0},					// Hysterese Grenzwerte 	

								// AE_UNI2 : Externe SollwertVorgabe UST ***AnFre
	 {0,					// Skalierung 0 V
		1000,				// Skalierung 10 V
		5,					// Filterzeitkonstante [s]		
		0,					// UGW												keine Grenzwerte
		0,					// OGW
		0},					// Hysterese Grenzwerte 	

								// AE_UNI3 : Druck Kollektor PS1 0,1 bar ***AnFre 06.06.2012
	 {0,					// Skalierung 0 V
		100,				// Skalierung 10 V
		3,					// Filterzeitkonstante [s]		
		15,					// UGW				
		70,					// OGW
		5},					// Hysterese Grenzwerte 	

								// AE_UNI4 : Druck Puffer PS2 0,1 bar ***AnFre 06.06.2012
	 {0,					// Skalierung 0 V
		40,					// Skalierung 10 V
		3,					// Filterzeitkonstante [s]		
		8,					// UGW
		28,					// OGW
		3},					// Hysterese Grenzwerte 	

								// AE_UNI5 : 
	 {0,					// Skalierung 0 V
		1000,				// Skalierung 10 V
		5,					// Filterzeitkonstante [s]		
		0,					// UGW												keine Grenzwerte
		0,					// OGW
		0},					// Hysterese Grenzwerte 	

								// AE_UNI6 : 
	 {0,					// Skalierung 0 V
		1000,				// Skalierung 10 V
		5,					// Filterzeitkonstante [s]		
		0,					// UGW												keine Grenzwerte
		0,					// OGW
		0},					// Hysterese Grenzwerte 	

								// AE_UNI7 : 
	 {0,					// Skalierung 0 V
		1000,				// Skalierung 10 V
		5,					// Filterzeitkonstante [s]		
		0,					// UGW												keine Grenzwerte
		0,					// OGW
		0},					// Hysterese Grenzwerte 	

								// AE_UNI8 : 
	 {0,					// Skalierung 0 V
		1000,				// Skalierung 10 V
		5,					// Filterzeitkonstante [s]		
		0,					// UGW												keine Grenzwerte
		0,					// OGW
		0},					// Hysterese Grenzwerte 	
};

#if RM_POWER_ANZ
const sPowInpPara RmPowerStandardPara[] = {
								// RM_POW1
	 {20,					// Skalierung 0 % = 2,0 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#if RM_POWER_ANZ > 1
								// RM_POW2 : 
	 {20,					// Skalierung 0 % = 2,0 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#endif
#if RM_POWER_ANZ > 2
								// RM_POW3 : 
	 {0,					// Skalierung 0 % = 0,00 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#endif
#if RM_POWER_ANZ > 3
								// RM_POW4 : 
	 {0,					// Skalierung 0 % = 0,00 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#endif
#if RM_POWER_ANZ > 4
								// RM_POW5 : 
	 {0,					// Skalierung 0 % = 0,00 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#endif
#if RM_POWER_ANZ > 5
								// RM_POW6 : 
	 {0,					// Skalierung 0 % = 0,00 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#endif
#if RM_POWER_ANZ > 6
								// RM_POW7 : 
	 {0,					// Skalierung 0 % = 0,00 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#endif
#if RM_POWER_ANZ > 7
								// RM_POW8 : 
	 {0,					// Skalierung 0 % = 0,00 V
		1000,				// Skalierung 10,0 V = 100,0 %
		10},				// Filterzeitkonstante [s]		
#endif
};
#endif

#if AE_DRUCK_ANZ
const sAnaInpPara DruckStandardPara[] = {
// Beispiel: Druck R�cklauf Anlage: 0 bar = 2,0 V, 10 V = 6,00 bar
//	 {20					// Skalierung 0 bar = 2,0 V
//		600,				// Skalierung 10 V = 6,00 bar
//		10,					// Filterzeitkonstante [s]		
//		200,				// UGW	2,00 bar
//		000,				// OGW	kein OGW
//		20},				// Hysterese Grenzwerte 0,20 bar

								// AE_DRU1
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,00 bar
		20},				// Hysterese Grenzwerte 0,20 bar	
#if AE_DRUCK_ANZ > 1
								// AE_DRU2 : 
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,0 bar
		20},				// Hysterese Grenzwerte 0,20 bar	
#endif
#if AE_DRUCK_ANZ > 2
								// AE_DRU3 : 
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,00 bar
		20},				// Hysterese Grenzwerte 0,20 bar	
#endif
#if AE_DRUCK_ANZ > 3
								// AE_DRU4 : 
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,00 bar
		20},				// Hysterese Grenzwerte 0,20 bar		
#endif
#if AE_DRUCK_ANZ > 4
								// AE_DRU5 : 
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,00 bar
		20},				// Hysterese Grenzwerte 0,20 bar	
#endif
#if AE_DRUCK_ANZ > 5
								// AE_DRU6 : 
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,00 bar
		20},				// Hysterese Grenzwerte 0,20 bar		
#endif
#if AE_DRUCK_ANZ > 6
								// AE_DRU7 : 
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,00 bar
		20},				// Hysterese Grenzwerte 0,20 bar	
#endif
#if AE_DRUCK_ANZ > 7
								// AE_DRU8 : 
	 {00,					// Skalierung 0 bar = 2,0 V
		1600,				// Skalierung 10 V = 6,00 bar
		10,					// Filterzeitkonstante [s]		
		100,				// UGW = 2,00 bar
		300,				// OGW = 3,00 bar
		20},				// Hysterese Grenzwerte 0,20 bar		
#endif
};
#endif

/*----------------------------------------------------------------------------------*/

/* Tabelle der Aufheizzeiten											*/
const char tabse[6][5] = {
	//tvab	<=20,		<=30,	<=40,		<=50,		>50		[K] 
//UlSch auf Wunsch von ThoSi 090312
	//tvab	<=5,		<=10,	<=15,		<=20,		>20		[K] 
					{60,		80,		100,		120,		150},	// ta < -10 �C	
					{50,		70,		 90,		110,		140},	// ta <  -5 �C	
					{30,		50,		 70,		100,		100},	// ta <   0 �C	
					{20,		30,		 50,		 80,		 80},	// ta <   5 �C	
					{10,		20,		 30,		 50,		 50},	// ta <  10 �C	
					{ 0,		 0,		  0,		  0,		  0},	// ta >  10 �C	
};					


/* Sonderzeichen LCD */
const char CarTab[64] = {										//  Code:	Zeichen			in RFB	
	0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x00,	//  0x04:	Kasten					"�"  'gef�lltes Karo	
	0x00,0x01,0x03,0x05,0x09,0x11,0x1F,0x00,	//  0x05:	Delta						'8'
	0x06,0x09,0x09,0x06,0x00,0x00,0x00,0x00,	//  0x06:	Grad						'�'
	0x18,0x04,0x0C,0x04,0x18,0x00,0x00,0x00,	//  0x07:	hoch 3					'�'
	0x00,0x04,0x0E,0x15,0x04,0x04,0x00,0x00,	//  0x00:	Pfeil hoch			'0'
	0x00,0x04,0x04,0x15,0x0E,0x04,0x00,0x00,	//  0x01:	Pfeil runter		'2'
	0x10,0x18,0x1C,0x1E,0x1C,0x18,0x10,0x00,	//  0x02:	Dreieck					'4'
	0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00		//  0x03:	Mittelpunkt			'6'
};

//---------- Bus-Pumpen --------------------------------------------------
const char * pu_operation_set[]	=
	{	
		"PUMPE STOP     \0",		// 0
		"PUMPE EIN      \0",		// 1
		"MIN-DREHZAHL   \0",		// 2
		"MAX-DREHZAHL   \0",		// 3
	  "Keine Antwort !\0",		// 4	***AnFre 12.12.2012
	};

const char * pu_control_set[]	=
	{	
		"KONSTANTDRUCK  \0",		// 0
		"PROPORT.DRUCK  \0",		// 1
		"KONSTANTFREQU. \0",		// 2
		"AUTOMATIK-MODE \0",		// 3
	  "Keine Antwort !\0",		// 4	***AnFre 12.12.2012
	};


const char ClearDisplay[] =
	{ "               \0"};

const char * pu_func_set[]	=
	{	
		"DEAKTIVIERT!   \0",		// 0
		"REMOTE MODE    \0",		// 1
		"LOCAL MODE     \0",		// 2
	};

const char * wilo_servstat_set[]	=
	{	
		"Keine Meldung  \0",
		"Servicebedarf  \0",				
		"Lager wechseln \0",				
		"Lager fetten   \0",				
		"Dichtung tausch\0",				
		"Undef Meldung! \0",
	};

const char * wilo_error_set[]	=
	{	
		"Keine Meldung  \0",
		"Modul-Fehler   \0",				
		"Motor-Fehler   \0",				
		"Nicht belegt   \0",				
		"Pumpen-Fehler  \0",				
		"Versorg.Spannun\0",				
		"Undef Meldung! \0",
	};

const char * wilo_errorstat_set[]	=
	{	
		"Keine Meldung  \0",
		"Unterspannung  \0",		
		"Ueberspannung  \0",
		"Phase fehlt    \0",
		"Trockenlauf    \0",
		"Druck zu hoch  \0",
		"Druck zu niedr.\0",
		"Nicht belegt   \0",
		"Nicht belegt   \0",
		"UeberTemp Motor\0",
		"Motorfehler    \0",
		"Blockierung    \0",
		"UeberTemp Modul\0",
		"Modulfe.Warnung\0",
		"Modulfehler    \0",
		"Sensorfehler   \0",
		"Undef Meldung! \0",
	};

const char * wilo_pustat_set[]	=
	{	
		"Keine Meldung  \0",
		"Betriebsm.  EIN\0",	
		"Drehricht.Links\0",	
		"Soll-Ist A.>10%\0",
		"Extern Aus     \0",	
		"Doppelpumpe    \0",	
		"Lokale Bedien. \0",	
		"Q/H nicht ermit\0",	
		"Extern Min.    \0",	
		"Nicht belegt   \0",
		"Nicht belegt   \0",
		"Nicht belegt   \0",
		"Nicht belegt   \0",
		"Nicht belegt   \0",
		"Wink/Service   \0",	
		"Undef Meldung! \0",
	};

const char * wilo_statdiag_set[]	=
	{	
		"Keine Meldung  \0",
		"Pu o.Modul-Fehl\0",
		"Versorgung Eo.H\0",
		"Nicht belegt   \0",
		"Untere Regelgr.\0",
		"Obere Regelgr. \0",
		"Nicht belegt   \0",
		"Sollwert-Fehler\0",
		"Nicht belegt   \0",
		"Lokale Bedien. \0",
		"Nicht belegt   \0",
		"Pumpe laeuft   \0",
		"Undef Meldung! \0",
	};
//---------- Ende Bus-Pumpen --------------------------------------------------



// im System ben�tigte Definitionen werden in const umgewandelt. Zugriff erfolgt dann �ber "extern ..."
// aktuelle Z�hlwerte
const UINT uiZAEHLER01_ADR 		= ZAEHLER01_ADR;	// R36
const UINT uiZAEHLER11_ADR		= ZAEHLER11_ADR;	// R37_1
const UINT uiZAEHLER21_ADR 		= ZAEHLER21_ADR;	// R37_2
const UINT uiZAEHLERMB1_ADR 	= ZAEHLERMB1_ADR;	// MBus
const UINT uiZVJ_OFFSET				= ZVJ_OFFSET;			// Offset zum Vorjahres-Hauptz�hler

// Verbrauchswerte des aktuellen Monats 
const UINT uiVERBRAU01_ADR 		= VERBRAU01_ADR;	// R36  
const UINT uiVERBRAU11_ADR 		= VERBRAU11_ADR;	// R37_1
const UINT uiVERBRAU21_ADR 		= VERBRAU21_ADR;	// R37_2
const UINT uiVERBRAUMB1_ADR 	= VERBRAUMB1_ADR;	// MBus

// Z�hlerdimensionierungen
const UINT uiZAEHL01_DIM_ADR 	= ZAEHL01_DIM_ADR;	// R36
const UINT uiZAEHL11_DIM_ADR 	= ZAEHL11_DIM_ADR;	// R37_1
const UINT uiZAEHL21_DIM_ADR 	= ZAEHL21_DIM_ADR;	// R37_2

// Monatsverbr�uche
const UINT uiZMV01_ADR				=	ZMV01_ADR;			// R36  
const UINT uiZMV11_ADR				=	ZMV11_ADR;			// R37_1
const UINT uiZMV21_ADR				=	ZMV21_ADR;			// R37_2
const UINT uiZMVMB1_ADR				=	ZMVMB1_ADR;			// MBus
const UINT uiZMV_OFFSET				=	ZMV_OFFSET;			// Offset zur n�chsten Z�hleradresse
const UINT uiZMV_VJOFFS				=	ZMV_VJOFFS;			// Offset zum Vorjahresbereich innerhalb eines Z�hlerspeicherbereiches

const char ucZEX1BELEG				=	ZEX1BELEG;			// Z�hlerbelegung R37_1
const char ucZEX2BELEG				=	ZEX2BELEG;			// Z�hlerbelegung R37_2
const char ucR37_MODULE 			= R37_MODULE;
const char ucMBUSANZ					= MBUSANZ;
 
const UINT uiPE_ADR 					= PE_TAB_ADR;
const UINT uiSE_ADR 					= SE_TAB_ADR;
const UINT uiAL_ADR 					= AL_TAB_ADR;
const char ucGRUP							= GRUP; 
const char ucHKANZ						= HKANZ; 
const char ucLED_DEBUG				= LED_DEBUG; 

// Serieller Schnittstellen Index
const char ucS1 =	S1;
const char ucS2 =	S2;
const char ucS3 =	S3;
const char ucWRE100  = WRE100;



// diese allgemeinen Namen entfallen, wenn jedem Z�hler individuell ein Name zugeordnet wird
//#####MBUS
const char ZlrWaerme[16]  = {"Waerme         "};														 
const char ZlrElektr[16]  = {"Elektrizitaet  "};														 
const char ZlrWarmwas[16] = {"Warmwasser     "};														 
const char ZlrKaltwas[16] = {"Kaltwasser     "};														 
const char ZlrFrei[16]    = {"nicht benutzt  "};														 
