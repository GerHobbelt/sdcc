/*
 * This definitions of the PIC18F27J53 MCU.
 *
 * This file is part of the GNU PIC library for SDCC, originally
 * created by Molnar Karoly <molnarkaroly@users.sf.net> 2014.
 *
 * This file is generated automatically by the cinc2h.pl, 2014-03-09 13:32:39 UTC.
 *
 * SDCC is licensed under the GNU Public license (GPL) v2. Note that
 * this license covers the code to the compiler and other executables,
 * but explicitly does not cover any code or objects generated by sdcc.
 *
 * For pic device libraries and header files which are derived from
 * Microchip header (.inc) and linker script (.lkr) files Microchip
 * requires that "The header files should state that they are only to be
 * used with authentic Microchip devices" which makes them incompatible
 * with the GPL. Pic device libraries and header files are located at
 * non-free/lib and non-free/include directories respectively.
 * Sdcc should be run with the --use-non-free command line option in
 * order to include non-free header files and libraries.
 *
 * See http://sdcc.sourceforge.net/ for the latest information on sdcc.
 */

#include <pic18f27j53.h>

//==============================================================================

__at(0x0EB8) __sfr ADCTRIG;
__at(0x0EB8) volatile __ADCTRIGbits_t ADCTRIGbits;

__at(0x0EB9) __sfr PD0;
__at(0x0EB9) volatile __PD0bits_t PD0bits;

__at(0x0EB9) __sfr PMDIS0;
__at(0x0EB9) volatile __PMDIS0bits_t PMDIS0bits;

__at(0x0EBA) __sfr PD1;
__at(0x0EBA) volatile __PD1bits_t PD1bits;

__at(0x0EBA) __sfr PMDIS1;
__at(0x0EBA) volatile __PMDIS1bits_t PMDIS1bits;

__at(0x0EBB) __sfr PD2;
__at(0x0EBB) volatile __PD2bits_t PD2bits;

__at(0x0EBB) __sfr PMDIS2;
__at(0x0EBB) volatile __PMDIS2bits_t PMDIS2bits;

__at(0x0EBC) __sfr PD3;
__at(0x0EBC) volatile __PD3bits_t PD3bits;

__at(0x0EBC) __sfr PMDIS3;
__at(0x0EBC) volatile __PMDIS3bits_t PMDIS3bits;

__at(0x0EBF) __sfr PPSCON;
__at(0x0EBF) volatile __PPSCONbits_t PPSCONbits;

__at(0x0EC0) __sfr RPOR0;

__at(0x0EC1) __sfr RPOR1;

__at(0x0EC2) __sfr RPOR2;

__at(0x0EC3) __sfr RPOR3;

__at(0x0EC4) __sfr RPOR4;

__at(0x0EC5) __sfr RPOR5;

__at(0x0EC6) __sfr RPOR6;

__at(0x0EC7) __sfr RPOR7;

__at(0x0EC8) __sfr RPOR8;

__at(0x0EC9) __sfr RPOR9;

__at(0x0ECA) __sfr RPOR10;

__at(0x0ECB) __sfr RPOR11;

__at(0x0ECC) __sfr RPOR12;

__at(0x0ECD) __sfr RPOR13;

__at(0x0ED1) __sfr RPOR17;

__at(0x0ED2) __sfr RPOR18;

__at(0x0EE1) __sfr RPINR1;

__at(0x0EE2) __sfr RPINR2;

__at(0x0EE3) __sfr RPINR3;

__at(0x0EE4) __sfr RPINR4;

__at(0x0EE6) __sfr RPINR6;

__at(0x0EE7) __sfr RPINR15;

__at(0x0EE8) __sfr RPINR7;

__at(0x0EE9) __sfr RPINR8;

__at(0x0EEA) __sfr RPINR9;

__at(0x0EF2) __sfr RPINR12;

__at(0x0EF3) __sfr RPINR13;

__at(0x0EF4) __sfr RPINR14;

__at(0x0EF7) __sfr RPINR16;

__at(0x0EF8) __sfr RPINR17;

__at(0x0EFC) __sfr RPINR21;

__at(0x0EFD) __sfr RPINR22;

__at(0x0EFE) __sfr RPINR23;

__at(0x0EFF) __sfr RPINR24;

__at(0x0F00) __sfr CCP10CON;
__at(0x0F00) volatile __CCP10CONbits_t CCP10CONbits;

__at(0x0F01) __sfr CCPR10L;

__at(0x0F02) __sfr CCPR10H;

__at(0x0F03) __sfr CCP9CON;
__at(0x0F03) volatile __CCP9CONbits_t CCP9CONbits;

__at(0x0F04) __sfr CCPR9L;

__at(0x0F05) __sfr CCPR9H;

__at(0x0F06) __sfr CCP8CON;
__at(0x0F06) volatile __CCP8CONbits_t CCP8CONbits;

__at(0x0F07) __sfr CCPR8L;

__at(0x0F08) __sfr CCPR8H;

__at(0x0F09) __sfr CCP7CON;
__at(0x0F09) volatile __CCP7CONbits_t CCP7CONbits;

__at(0x0F0A) __sfr CCPR7L;

__at(0x0F0B) __sfr CCPR7H;

__at(0x0F0C) __sfr CCP6CON;
__at(0x0F0C) volatile __CCP6CONbits_t CCP6CONbits;

__at(0x0F0D) __sfr CCPR6L;

__at(0x0F0E) __sfr CCPR6H;

__at(0x0F0F) __sfr CCP5CON;
__at(0x0F0F) volatile __CCP5CONbits_t CCP5CONbits;

__at(0x0F10) __sfr CCPR5L;

__at(0x0F11) __sfr CCPR5H;

__at(0x0F12) __sfr CCP4CON;
__at(0x0F12) volatile __CCP4CONbits_t CCP4CONbits;

__at(0x0F13) __sfr CCPR4L;

__at(0x0F14) __sfr CCPR4H;

__at(0x0F15) __sfr CCP3CON;
__at(0x0F15) volatile __CCP3CONbits_t CCP3CONbits;

__at(0x0F16) __sfr CCPR3L;

__at(0x0F17) __sfr CCPR3H;

__at(0x0F18) __sfr ECCP3DEL;
__at(0x0F18) volatile __ECCP3DELbits_t ECCP3DELbits;

__at(0x0F19) __sfr ECCP3AS;
__at(0x0F19) volatile __ECCP3ASbits_t ECCP3ASbits;

__at(0x0F1A) __sfr PSTR3CON;
__at(0x0F1A) volatile __PSTR3CONbits_t PSTR3CONbits;

__at(0x0F1B) __sfr T8CON;
__at(0x0F1B) volatile __T8CONbits_t T8CONbits;

__at(0x0F1C) __sfr PR8;

__at(0x0F1D) __sfr TMR8;

__at(0x0F1E) __sfr T6CON;
__at(0x0F1E) volatile __T6CONbits_t T6CONbits;

__at(0x0F1F) __sfr PR6;

__at(0x0F20) __sfr TMR6;

__at(0x0F21) __sfr T5GCON;
__at(0x0F21) volatile __T5GCONbits_t T5GCONbits;

__at(0x0F22) __sfr T5CON;
__at(0x0F22) volatile __T5CONbits_t T5CONbits;

__at(0x0F23) __sfr TMR5L;

__at(0x0F24) __sfr TMR5H;

__at(0x0F25) __sfr CM3CON;
__at(0x0F25) volatile __CM3CONbits_t CM3CONbits;

__at(0x0F26) __sfr UEP0;
__at(0x0F26) volatile __UEP0bits_t UEP0bits;

__at(0x0F27) __sfr UEP1;
__at(0x0F27) volatile __UEP1bits_t UEP1bits;

__at(0x0F28) __sfr UEP2;
__at(0x0F28) volatile __UEP2bits_t UEP2bits;

__at(0x0F29) __sfr UEP3;
__at(0x0F29) volatile __UEP3bits_t UEP3bits;

__at(0x0F2A) __sfr UEP4;
__at(0x0F2A) volatile __UEP4bits_t UEP4bits;

__at(0x0F2B) __sfr UEP5;
__at(0x0F2B) volatile __UEP5bits_t UEP5bits;

__at(0x0F2C) __sfr UEP6;
__at(0x0F2C) volatile __UEP6bits_t UEP6bits;

__at(0x0F2D) __sfr UEP7;
__at(0x0F2D) volatile __UEP7bits_t UEP7bits;

__at(0x0F2E) __sfr UEP8;
__at(0x0F2E) volatile __UEP8bits_t UEP8bits;

__at(0x0F2F) __sfr UEP9;
__at(0x0F2F) volatile __UEP9bits_t UEP9bits;

__at(0x0F30) __sfr UEP10;
__at(0x0F30) volatile __UEP10bits_t UEP10bits;

__at(0x0F31) __sfr UEP11;
__at(0x0F31) volatile __UEP11bits_t UEP11bits;

__at(0x0F32) __sfr UEP12;
__at(0x0F32) volatile __UEP12bits_t UEP12bits;

__at(0x0F33) __sfr UEP13;
__at(0x0F33) volatile __UEP13bits_t UEP13bits;

__at(0x0F34) __sfr UEP14;
__at(0x0F34) volatile __UEP14bits_t UEP14bits;

__at(0x0F35) __sfr UEP15;
__at(0x0F35) volatile __UEP15bits_t UEP15bits;

__at(0x0F36) __sfr UIE;
__at(0x0F36) volatile __UIEbits_t UIEbits;

__at(0x0F37) __sfr UEIE;
__at(0x0F37) volatile __UEIEbits_t UEIEbits;

__at(0x0F38) __sfr UADDR;
__at(0x0F38) volatile __UADDRbits_t UADDRbits;

__at(0x0F39) __sfr UCFG;
__at(0x0F39) volatile __UCFGbits_t UCFGbits;

__at(0x0F3A) __sfr RTCVALL;

__at(0x0F3B) __sfr RTCVALH;

__at(0x0F3C) __sfr PADCFG1;
__at(0x0F3C) volatile __PADCFG1bits_t PADCFG1bits;

__at(0x0F3D) __sfr REFOCON;
__at(0x0F3D) volatile __REFOCONbits_t REFOCONbits;

__at(0x0F3E) __sfr RTCCAL;
__at(0x0F3E) volatile __RTCCALbits_t RTCCALbits;

__at(0x0F3F) __sfr RTCCFG;
__at(0x0F3F) volatile __RTCCFGbits_t RTCCFGbits;

__at(0x0F40) __sfr ODCON3;
__at(0x0F40) volatile __ODCON3bits_t ODCON3bits;

__at(0x0F41) __sfr ODCON2;
__at(0x0F41) volatile __ODCON2bits_t ODCON2bits;

__at(0x0F42) __sfr ODCON1;
__at(0x0F42) volatile __ODCON1bits_t ODCON1bits;

__at(0x0F44) __sfr ALRMVALL;

__at(0x0F45) __sfr ALRMVALH;

__at(0x0F46) __sfr ALRMRPT;
__at(0x0F46) volatile __ALRMRPTbits_t ALRMRPTbits;

__at(0x0F47) __sfr ALRMCFG;
__at(0x0F47) volatile __ALRMCFGbits_t ALRMCFGbits;

__at(0x0F48) __sfr ANCON0;
__at(0x0F48) volatile __ANCON0bits_t ANCON0bits;

__at(0x0F49) __sfr ANCON1;
__at(0x0F49) volatile __ANCON1bits_t ANCON1bits;

__at(0x0F4A) __sfr DSWAKEL;
__at(0x0F4A) volatile __DSWAKELbits_t DSWAKELbits;

__at(0x0F4B) __sfr DSWAKEH;
__at(0x0F4B) volatile __DSWAKEHbits_t DSWAKEHbits;

__at(0x0F4C) __sfr DSCONL;
__at(0x0F4C) volatile __DSCONLbits_t DSCONLbits;

__at(0x0F4D) __sfr DSCONH;
__at(0x0F4D) volatile __DSCONHbits_t DSCONHbits;

__at(0x0F4E) __sfr DSGPR0;

__at(0x0F4F) __sfr DSGPR1;

__at(0x0F50) __sfr CCPTMRS2;
__at(0x0F50) volatile __CCPTMRS2bits_t CCPTMRS2bits;

__at(0x0F51) __sfr CCPTMRS1;
__at(0x0F51) volatile __CCPTMRS1bits_t CCPTMRS1bits;

__at(0x0F52) __sfr CCPTMRS0;
__at(0x0F52) volatile __CCPTMRS0bits_t CCPTMRS0bits;

__at(0x0F53) __sfr CVRCON;
__at(0x0F53) volatile __CVRCONbits_t CVRCONbits;

__at(0x0F60) __sfr UFRM;

__at(0x0F60) __sfr UFRML;
__at(0x0F60) volatile __UFRMLbits_t UFRMLbits;

__at(0x0F61) __sfr UFRMH;
__at(0x0F61) volatile __UFRMHbits_t UFRMHbits;

__at(0x0F62) __sfr UIR;
__at(0x0F62) volatile __UIRbits_t UIRbits;

__at(0x0F63) __sfr UEIR;
__at(0x0F63) volatile __UEIRbits_t UEIRbits;

__at(0x0F64) __sfr USTAT;
__at(0x0F64) volatile __USTATbits_t USTATbits;

__at(0x0F65) __sfr UCON;
__at(0x0F65) volatile __UCONbits_t UCONbits;

__at(0x0F66) __sfr DMABCH;

__at(0x0F67) __sfr DMABCL;

__at(0x0F68) __sfr RXADDRH;

__at(0x0F69) __sfr RXADDRL;

__at(0x0F6A) __sfr TXADDRH;

__at(0x0F6B) __sfr TXADDRL;

__at(0x0F70) __sfr CMSTAT;
__at(0x0F70) volatile __CMSTATbits_t CMSTATbits;

__at(0x0F70) __sfr CMSTATUS;
__at(0x0F70) volatile __CMSTATUSbits_t CMSTATUSbits;

__at(0x0F71) __sfr SSP2CON2;
__at(0x0F71) volatile __SSP2CON2bits_t SSP2CON2bits;

__at(0x0F72) __sfr SSP2CON1;
__at(0x0F72) volatile __SSP2CON1bits_t SSP2CON1bits;

__at(0x0F73) __sfr SSP2STAT;
__at(0x0F73) volatile __SSP2STATbits_t SSP2STATbits;

__at(0x0F74) __sfr SSP2ADD;

__at(0x0F74) __sfr SSP2MSK;
__at(0x0F74) volatile __SSP2MSKbits_t SSP2MSKbits;

__at(0x0F75) __sfr SSP2BUF;

__at(0x0F76) __sfr T4CON;
__at(0x0F76) volatile __T4CONbits_t T4CONbits;

__at(0x0F77) __sfr PR4;

__at(0x0F78) __sfr TMR4;

__at(0x0F79) __sfr T3CON;
__at(0x0F79) volatile __T3CONbits_t T3CONbits;

__at(0x0F7A) __sfr TMR3;

__at(0x0F7A) __sfr TMR3L;

__at(0x0F7B) __sfr TMR3H;

__at(0x0F7C) __sfr BAUDCON2;
__at(0x0F7C) volatile __BAUDCON2bits_t BAUDCON2bits;

__at(0x0F7D) __sfr SPBRGH2;

__at(0x0F7E) __sfr BAUDCON;
__at(0x0F7E) volatile __BAUDCONbits_t BAUDCONbits;

__at(0x0F7E) __sfr BAUDCON1;
__at(0x0F7E) volatile __BAUDCON1bits_t BAUDCON1bits;

__at(0x0F7E) __sfr BAUDCTL;
__at(0x0F7E) volatile __BAUDCTLbits_t BAUDCTLbits;

__at(0x0F7F) __sfr SPBRGH;

__at(0x0F7F) __sfr SPBRGH1;

__at(0x0F80) __sfr PORTA;
__at(0x0F80) volatile __PORTAbits_t PORTAbits;

__at(0x0F81) __sfr PORTB;
__at(0x0F81) volatile __PORTBbits_t PORTBbits;

__at(0x0F82) __sfr PORTC;
__at(0x0F82) volatile __PORTCbits_t PORTCbits;

__at(0x0F85) __sfr HLVDCON;
__at(0x0F85) volatile __HLVDCONbits_t HLVDCONbits;

__at(0x0F86) __sfr DMACON2;
__at(0x0F86) volatile __DMACON2bits_t DMACON2bits;

__at(0x0F87) __sfr OSCCON2;
__at(0x0F87) volatile __OSCCON2bits_t OSCCON2bits;

__at(0x0F88) __sfr DMACON1;
__at(0x0F88) volatile __DMACON1bits_t DMACON1bits;

__at(0x0F89) __sfr LATA;
__at(0x0F89) volatile __LATAbits_t LATAbits;

__at(0x0F8A) __sfr LATB;
__at(0x0F8A) volatile __LATBbits_t LATBbits;

__at(0x0F8B) __sfr LATC;
__at(0x0F8B) volatile __LATCbits_t LATCbits;

__at(0x0F8E) __sfr PIE4;
__at(0x0F8E) volatile __PIE4bits_t PIE4bits;

__at(0x0F8F) __sfr PIR4;
__at(0x0F8F) volatile __PIR4bits_t PIR4bits;

__at(0x0F90) __sfr IPR4;
__at(0x0F90) volatile __IPR4bits_t IPR4bits;

__at(0x0F91) __sfr PIE5;
__at(0x0F91) volatile __PIE5bits_t PIE5bits;

__at(0x0F92) __sfr TRISA;
__at(0x0F92) volatile __TRISAbits_t TRISAbits;

__at(0x0F93) __sfr TRISB;
__at(0x0F93) volatile __TRISBbits_t TRISBbits;

__at(0x0F94) __sfr TRISC;
__at(0x0F94) volatile __TRISCbits_t TRISCbits;

__at(0x0F97) __sfr T3GCON;
__at(0x0F97) volatile __T3GCONbits_t T3GCONbits;

__at(0x0F98) __sfr PIR5;
__at(0x0F98) volatile __PIR5bits_t PIR5bits;

__at(0x0F99) __sfr IPR5;
__at(0x0F99) volatile __IPR5bits_t IPR5bits;

__at(0x0F9A) __sfr T1GCON;
__at(0x0F9A) volatile __T1GCONbits_t T1GCONbits;

__at(0x0F9B) __sfr OSCTUNE;
__at(0x0F9B) volatile __OSCTUNEbits_t OSCTUNEbits;

__at(0x0F9C) __sfr RCSTA2;
__at(0x0F9C) volatile __RCSTA2bits_t RCSTA2bits;

__at(0x0F9D) __sfr PIE1;
__at(0x0F9D) volatile __PIE1bits_t PIE1bits;

__at(0x0F9E) __sfr PIR1;
__at(0x0F9E) volatile __PIR1bits_t PIR1bits;

__at(0x0F9F) __sfr IPR1;
__at(0x0F9F) volatile __IPR1bits_t IPR1bits;

__at(0x0FA0) __sfr PIE2;
__at(0x0FA0) volatile __PIE2bits_t PIE2bits;

__at(0x0FA1) __sfr PIR2;
__at(0x0FA1) volatile __PIR2bits_t PIR2bits;

__at(0x0FA2) __sfr IPR2;
__at(0x0FA2) volatile __IPR2bits_t IPR2bits;

__at(0x0FA3) __sfr PIE3;
__at(0x0FA3) volatile __PIE3bits_t PIE3bits;

__at(0x0FA4) __sfr PIR3;
__at(0x0FA4) volatile __PIR3bits_t PIR3bits;

__at(0x0FA5) __sfr IPR3;
__at(0x0FA5) volatile __IPR3bits_t IPR3bits;

__at(0x0FA6) __sfr EECON1;
__at(0x0FA6) volatile __EECON1bits_t EECON1bits;

__at(0x0FA7) __sfr EECON2;

__at(0x0FA8) __sfr TXSTA2;
__at(0x0FA8) volatile __TXSTA2bits_t TXSTA2bits;

__at(0x0FA9) __sfr TXREG2;

__at(0x0FAA) __sfr RCREG2;

__at(0x0FAB) __sfr SPBRG2;

__at(0x0FAC) __sfr RCSTA;
__at(0x0FAC) volatile __RCSTAbits_t RCSTAbits;

__at(0x0FAC) __sfr RCSTA1;
__at(0x0FAC) volatile __RCSTA1bits_t RCSTA1bits;

__at(0x0FAD) __sfr TXSTA;
__at(0x0FAD) volatile __TXSTAbits_t TXSTAbits;

__at(0x0FAD) __sfr TXSTA1;
__at(0x0FAD) volatile __TXSTA1bits_t TXSTA1bits;

__at(0x0FAE) __sfr TXREG;

__at(0x0FAE) __sfr TXREG1;

__at(0x0FAF) __sfr RCREG;

__at(0x0FAF) __sfr RCREG1;

__at(0x0FB0) __sfr SPBRG;

__at(0x0FB0) __sfr SPBRG1;

__at(0x0FB1) __sfr CTMUICON;
__at(0x0FB1) volatile __CTMUICONbits_t CTMUICONbits;

__at(0x0FB2) __sfr CTMUCONL;
__at(0x0FB2) volatile __CTMUCONLbits_t CTMUCONLbits;

__at(0x0FB3) __sfr CTMUCONH;
__at(0x0FB3) volatile __CTMUCONHbits_t CTMUCONHbits;

__at(0x0FB4) __sfr CCP2CON;
__at(0x0FB4) volatile __CCP2CONbits_t CCP2CONbits;

__at(0x0FB4) __sfr ECCP2CON;
__at(0x0FB4) volatile __ECCP2CONbits_t ECCP2CONbits;

__at(0x0FB5) __sfr CCPR2;

__at(0x0FB5) __sfr CCPR2L;

__at(0x0FB6) __sfr CCPR2H;

__at(0x0FB7) __sfr ECCP2DEL;
__at(0x0FB7) volatile __ECCP2DELbits_t ECCP2DELbits;

__at(0x0FB7) __sfr PWM2CON;
__at(0x0FB7) volatile __PWM2CONbits_t PWM2CONbits;

__at(0x0FB8) __sfr ECCP2AS;
__at(0x0FB8) volatile __ECCP2ASbits_t ECCP2ASbits;

__at(0x0FB9) __sfr PSTR2CON;
__at(0x0FB9) volatile __PSTR2CONbits_t PSTR2CONbits;

__at(0x0FBA) __sfr CCP1CON;
__at(0x0FBA) volatile __CCP1CONbits_t CCP1CONbits;

__at(0x0FBA) __sfr ECCP1CON;
__at(0x0FBA) volatile __ECCP1CONbits_t ECCP1CONbits;

__at(0x0FBB) __sfr CCPR1;

__at(0x0FBB) __sfr CCPR1L;

__at(0x0FBC) __sfr CCPR1H;

__at(0x0FBD) __sfr ECCP1DEL;
__at(0x0FBD) volatile __ECCP1DELbits_t ECCP1DELbits;

__at(0x0FBD) __sfr PWM1CON;
__at(0x0FBD) volatile __PWM1CONbits_t PWM1CONbits;

__at(0x0FBE) __sfr ECCP1AS;
__at(0x0FBE) volatile __ECCP1ASbits_t ECCP1ASbits;

__at(0x0FBF) __sfr PSTR1CON;
__at(0x0FBF) volatile __PSTR1CONbits_t PSTR1CONbits;

__at(0x0FC0) __sfr WDTCON;
__at(0x0FC0) volatile __WDTCONbits_t WDTCONbits;

__at(0x0FC1) __sfr ADCON1;
__at(0x0FC1) volatile __ADCON1bits_t ADCON1bits;

__at(0x0FC2) __sfr ADCON0;
__at(0x0FC2) volatile __ADCON0bits_t ADCON0bits;

__at(0x0FC3) __sfr ADRES;

__at(0x0FC3) __sfr ADRESL;

__at(0x0FC4) __sfr ADRESH;

__at(0x0FC5) __sfr SSP1CON2;
__at(0x0FC5) volatile __SSP1CON2bits_t SSP1CON2bits;

__at(0x0FC5) __sfr SSPCON2;
__at(0x0FC5) volatile __SSPCON2bits_t SSPCON2bits;

__at(0x0FC6) __sfr SSP1CON1;
__at(0x0FC6) volatile __SSP1CON1bits_t SSP1CON1bits;

__at(0x0FC6) __sfr SSPCON1;
__at(0x0FC6) volatile __SSPCON1bits_t SSPCON1bits;

__at(0x0FC7) __sfr SSP1STAT;
__at(0x0FC7) volatile __SSP1STATbits_t SSP1STATbits;

__at(0x0FC7) __sfr SSPSTAT;
__at(0x0FC7) volatile __SSPSTATbits_t SSPSTATbits;

__at(0x0FC8) __sfr SSP1ADD;

__at(0x0FC8) __sfr SSP1MSK;
__at(0x0FC8) volatile __SSP1MSKbits_t SSP1MSKbits;

__at(0x0FC8) __sfr SSPADD;

__at(0x0FC9) __sfr SSP1BUF;

__at(0x0FC9) __sfr SSPBUF;

__at(0x0FCA) __sfr T2CON;
__at(0x0FCA) volatile __T2CONbits_t T2CONbits;

__at(0x0FCB) __sfr PR2;

__at(0x0FCC) __sfr TMR2;

__at(0x0FCD) __sfr T1CON;
__at(0x0FCD) volatile __T1CONbits_t T1CONbits;

__at(0x0FCE) __sfr TMR1;

__at(0x0FCE) __sfr TMR1L;

__at(0x0FCF) __sfr TMR1H;

__at(0x0FD0) __sfr RCON;
__at(0x0FD0) volatile __RCONbits_t RCONbits;

__at(0x0FD1) __sfr CM2CON;
__at(0x0FD1) volatile __CM2CONbits_t CM2CONbits;

__at(0x0FD1) __sfr CM2CON1;
__at(0x0FD1) volatile __CM2CON1bits_t CM2CON1bits;

__at(0x0FD2) __sfr CM1CON;
__at(0x0FD2) volatile __CM1CONbits_t CM1CONbits;

__at(0x0FD2) __sfr CM1CON1;
__at(0x0FD2) volatile __CM1CON1bits_t CM1CON1bits;

__at(0x0FD3) __sfr OSCCON;
__at(0x0FD3) volatile __OSCCONbits_t OSCCONbits;

__at(0x0FD5) __sfr T0CON;
__at(0x0FD5) volatile __T0CONbits_t T0CONbits;

__at(0x0FD6) __sfr TMR0;

__at(0x0FD6) __sfr TMR0L;

__at(0x0FD7) __sfr TMR0H;

__at(0x0FD8) __sfr STATUS;
__at(0x0FD8) volatile __STATUSbits_t STATUSbits;

__at(0x0FD9) __sfr FSR2L;

__at(0x0FDA) __sfr FSR2H;

__at(0x0FDB) __sfr PLUSW2;

__at(0x0FDC) __sfr PREINC2;

__at(0x0FDD) __sfr POSTDEC2;

__at(0x0FDE) __sfr POSTINC2;

__at(0x0FDF) __sfr INDF2;

__at(0x0FE0) __sfr BSR;

__at(0x0FE1) __sfr FSR1L;

__at(0x0FE2) __sfr FSR1H;

__at(0x0FE3) __sfr PLUSW1;

__at(0x0FE4) __sfr PREINC1;

__at(0x0FE5) __sfr POSTDEC1;

__at(0x0FE6) __sfr POSTINC1;

__at(0x0FE7) __sfr INDF1;

__at(0x0FE8) __sfr WREG;

__at(0x0FE9) __sfr FSR0L;

__at(0x0FEA) __sfr FSR0H;

__at(0x0FEB) __sfr PLUSW0;

__at(0x0FEC) __sfr PREINC0;

__at(0x0FED) __sfr POSTDEC0;

__at(0x0FEE) __sfr POSTINC0;

__at(0x0FEF) __sfr INDF0;

__at(0x0FF0) __sfr INTCON3;
__at(0x0FF0) volatile __INTCON3bits_t INTCON3bits;

__at(0x0FF1) __sfr INTCON2;
__at(0x0FF1) volatile __INTCON2bits_t INTCON2bits;

__at(0x0FF2) __sfr INTCON;
__at(0x0FF2) volatile __INTCONbits_t INTCONbits;

__at(0x0FF3) __sfr PROD;

__at(0x0FF3) __sfr PRODL;

__at(0x0FF4) __sfr PRODH;

__at(0x0FF5) __sfr TABLAT;

__at(0x0FF6) __sfr TBLPTR;

__at(0x0FF6) __sfr TBLPTRL;

__at(0x0FF7) __sfr TBLPTRH;

__at(0x0FF8) __sfr TBLPTRU;

__at(0x0FF9) __sfr PC;

__at(0x0FF9) __sfr PCL;

__at(0x0FFA) __sfr PCLATH;

__at(0x0FFB) __sfr PCLATU;

__at(0x0FFC) __sfr STKPTR;
__at(0x0FFC) volatile __STKPTRbits_t STKPTRbits;

__at(0x0FFD) __sfr TOS;

__at(0x0FFD) __sfr TOSL;

__at(0x0FFE) __sfr TOSH;

__at(0x0FFF) __sfr TOSU;
