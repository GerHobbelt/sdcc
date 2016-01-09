/*
 * This definitions of the PIC16F1507 MCU.
 *
 * This file is part of the GNU PIC library for SDCC, originally
 * created by Molnar Karoly <molnarkaroly@users.sf.net> 2016.
 *
 * This file is generated automatically by the cinc2h.pl, 2016-01-09 15:09:01 UTC.
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

#include <pic16f1507.h>

//==============================================================================

__at(0x0000) __sfr INDF0;

__at(0x0001) __sfr INDF1;

__at(0x0002) __sfr PCL;

__at(0x0003) __sfr STATUS;
__at(0x0003) volatile __STATUSbits_t STATUSbits;

__at(0x0004) __sfr FSR0;

__at(0x0004) __sfr FSR0L;

__at(0x0005) __sfr FSR0H;

__at(0x0006) __sfr FSR1;

__at(0x0006) __sfr FSR1L;

__at(0x0007) __sfr FSR1H;

__at(0x0008) __sfr BSR;
__at(0x0008) volatile __BSRbits_t BSRbits;

__at(0x0009) __sfr WREG;

__at(0x000A) __sfr PCLATH;

__at(0x000B) __sfr INTCON;
__at(0x000B) volatile __INTCONbits_t INTCONbits;

__at(0x000C) __sfr PORTA;
__at(0x000C) volatile __PORTAbits_t PORTAbits;

__at(0x000D) __sfr PORTB;
__at(0x000D) volatile __PORTBbits_t PORTBbits;

__at(0x000E) __sfr PORTC;
__at(0x000E) volatile __PORTCbits_t PORTCbits;

__at(0x0011) __sfr PIR1;
__at(0x0011) volatile __PIR1bits_t PIR1bits;

__at(0x0012) __sfr PIR2;
__at(0x0012) volatile __PIR2bits_t PIR2bits;

__at(0x0013) __sfr PIR3;
__at(0x0013) volatile __PIR3bits_t PIR3bits;

__at(0x0015) __sfr TMR0;

__at(0x0016) __sfr TMR1;

__at(0x0016) __sfr TMR1L;

__at(0x0017) __sfr TMR1H;

__at(0x0018) __sfr T1CON;
__at(0x0018) volatile __T1CONbits_t T1CONbits;

__at(0x0019) __sfr T1GCON;
__at(0x0019) volatile __T1GCONbits_t T1GCONbits;

__at(0x001A) __sfr TMR2;

__at(0x001B) __sfr PR2;

__at(0x001C) __sfr T2CON;
__at(0x001C) volatile __T2CONbits_t T2CONbits;

__at(0x008C) __sfr TRISA;
__at(0x008C) volatile __TRISAbits_t TRISAbits;

__at(0x008D) __sfr TRISB;
__at(0x008D) volatile __TRISBbits_t TRISBbits;

__at(0x008E) __sfr TRISC;
__at(0x008E) volatile __TRISCbits_t TRISCbits;

__at(0x0091) __sfr PIE1;
__at(0x0091) volatile __PIE1bits_t PIE1bits;

__at(0x0092) __sfr PIE2;
__at(0x0092) volatile __PIE2bits_t PIE2bits;

__at(0x0093) __sfr PIE3;
__at(0x0093) volatile __PIE3bits_t PIE3bits;

__at(0x0095) __sfr OPTION_REG;
__at(0x0095) volatile __OPTION_REGbits_t OPTION_REGbits;

__at(0x0096) __sfr PCON;
__at(0x0096) volatile __PCONbits_t PCONbits;

__at(0x0097) __sfr WDTCON;
__at(0x0097) volatile __WDTCONbits_t WDTCONbits;

__at(0x0099) __sfr OSCCON;
__at(0x0099) volatile __OSCCONbits_t OSCCONbits;

__at(0x009A) __sfr OSCSTAT;
__at(0x009A) volatile __OSCSTATbits_t OSCSTATbits;

__at(0x009B) __sfr ADRES;

__at(0x009B) __sfr ADRESL;

__at(0x009C) __sfr ADRESH;

__at(0x009D) __sfr ADCON0;
__at(0x009D) volatile __ADCON0bits_t ADCON0bits;

__at(0x009E) __sfr ADCON1;
__at(0x009E) volatile __ADCON1bits_t ADCON1bits;

__at(0x009F) __sfr ADCON2;
__at(0x009F) volatile __ADCON2bits_t ADCON2bits;

__at(0x010C) __sfr LATA;
__at(0x010C) volatile __LATAbits_t LATAbits;

__at(0x010D) __sfr LATB;
__at(0x010D) volatile __LATBbits_t LATBbits;

__at(0x010E) __sfr LATC;
__at(0x010E) volatile __LATCbits_t LATCbits;

__at(0x0116) __sfr BORCON;
__at(0x0116) volatile __BORCONbits_t BORCONbits;

__at(0x0117) __sfr FVRCON;
__at(0x0117) volatile __FVRCONbits_t FVRCONbits;

__at(0x011D) __sfr APFCON;
__at(0x011D) volatile __APFCONbits_t APFCONbits;

__at(0x018C) __sfr ANSELA;
__at(0x018C) volatile __ANSELAbits_t ANSELAbits;

__at(0x018D) __sfr ANSELB;
__at(0x018D) volatile __ANSELBbits_t ANSELBbits;

__at(0x018E) __sfr ANSELC;
__at(0x018E) volatile __ANSELCbits_t ANSELCbits;

__at(0x0191) __sfr PMADR;

__at(0x0191) __sfr PMADRL;

__at(0x0192) __sfr PMADRH;

__at(0x0193) __sfr PMDAT;

__at(0x0193) __sfr PMDATL;

__at(0x0194) __sfr PMDATH;

__at(0x0195) __sfr PMCON1;
__at(0x0195) volatile __PMCON1bits_t PMCON1bits;

__at(0x0196) __sfr PMCON2;

__at(0x0197) __sfr VREGCON;
__at(0x0197) volatile __VREGCONbits_t VREGCONbits;

__at(0x020C) __sfr WPUA;
__at(0x020C) volatile __WPUAbits_t WPUAbits;

__at(0x020D) __sfr WPUB;
__at(0x020D) volatile __WPUBbits_t WPUBbits;

__at(0x0391) __sfr IOCAP;
__at(0x0391) volatile __IOCAPbits_t IOCAPbits;

__at(0x0392) __sfr IOCAN;
__at(0x0392) volatile __IOCANbits_t IOCANbits;

__at(0x0393) __sfr IOCAF;
__at(0x0393) volatile __IOCAFbits_t IOCAFbits;

__at(0x0394) __sfr IOCBP;
__at(0x0394) volatile __IOCBPbits_t IOCBPbits;

__at(0x0395) __sfr IOCBN;
__at(0x0395) volatile __IOCBNbits_t IOCBNbits;

__at(0x0396) __sfr IOCBF;
__at(0x0396) volatile __IOCBFbits_t IOCBFbits;

__at(0x0498) __sfr NCO1ACC;

__at(0x0498) __sfr NCO1ACCL;
__at(0x0498) volatile __NCO1ACCLbits_t NCO1ACCLbits;

__at(0x0499) __sfr NCO1ACCH;
__at(0x0499) volatile __NCO1ACCHbits_t NCO1ACCHbits;

__at(0x049A) __sfr NCO1ACCU;
__at(0x049A) volatile __NCO1ACCUbits_t NCO1ACCUbits;

__at(0x049B) __sfr NCO1INC;

__at(0x049B) __sfr NCO1INCL;
__at(0x049B) volatile __NCO1INCLbits_t NCO1INCLbits;

__at(0x049C) __sfr NCO1INCH;
__at(0x049C) volatile __NCO1INCHbits_t NCO1INCHbits;

__at(0x049D) __sfr NCO1INCU;

__at(0x049E) __sfr NCO1CON;
__at(0x049E) volatile __NCO1CONbits_t NCO1CONbits;

__at(0x049F) __sfr NCO1CLK;
__at(0x049F) volatile __NCO1CLKbits_t NCO1CLKbits;

__at(0x0611) __sfr PWM1DCL;
__at(0x0611) volatile __PWM1DCLbits_t PWM1DCLbits;

__at(0x0612) __sfr PWM1DCH;
__at(0x0612) volatile __PWM1DCHbits_t PWM1DCHbits;

__at(0x0613) __sfr PWM1CON;
__at(0x0613) volatile __PWM1CONbits_t PWM1CONbits;

__at(0x0613) __sfr PWM1CON0;
__at(0x0613) volatile __PWM1CON0bits_t PWM1CON0bits;

__at(0x0614) __sfr PWM2DCL;
__at(0x0614) volatile __PWM2DCLbits_t PWM2DCLbits;

__at(0x0615) __sfr PWM2DCH;
__at(0x0615) volatile __PWM2DCHbits_t PWM2DCHbits;

__at(0x0616) __sfr PWM2CON;
__at(0x0616) volatile __PWM2CONbits_t PWM2CONbits;

__at(0x0616) __sfr PWM2CON0;
__at(0x0616) volatile __PWM2CON0bits_t PWM2CON0bits;

__at(0x0617) __sfr PWM3DCL;
__at(0x0617) volatile __PWM3DCLbits_t PWM3DCLbits;

__at(0x0618) __sfr PWM3DCH;
__at(0x0618) volatile __PWM3DCHbits_t PWM3DCHbits;

__at(0x0619) __sfr PWM3CON;
__at(0x0619) volatile __PWM3CONbits_t PWM3CONbits;

__at(0x0619) __sfr PWM3CON0;
__at(0x0619) volatile __PWM3CON0bits_t PWM3CON0bits;

__at(0x061A) __sfr PWM4DCL;
__at(0x061A) volatile __PWM4DCLbits_t PWM4DCLbits;

__at(0x061B) __sfr PWM4DCH;
__at(0x061B) volatile __PWM4DCHbits_t PWM4DCHbits;

__at(0x061C) __sfr PWM4CON;
__at(0x061C) volatile __PWM4CONbits_t PWM4CONbits;

__at(0x061C) __sfr PWM4CON0;
__at(0x061C) volatile __PWM4CON0bits_t PWM4CON0bits;

__at(0x0691) __sfr CWG1DBR;
__at(0x0691) volatile __CWG1DBRbits_t CWG1DBRbits;

__at(0x0692) __sfr CWG1DBF;
__at(0x0692) volatile __CWG1DBFbits_t CWG1DBFbits;

__at(0x0693) __sfr CWG1CON0;
__at(0x0693) volatile __CWG1CON0bits_t CWG1CON0bits;

__at(0x0694) __sfr CWG1CON1;
__at(0x0694) volatile __CWG1CON1bits_t CWG1CON1bits;

__at(0x0695) __sfr CWG1CON2;
__at(0x0695) volatile __CWG1CON2bits_t CWG1CON2bits;

__at(0x0F0F) __sfr CLCDATA;
__at(0x0F0F) volatile __CLCDATAbits_t CLCDATAbits;

__at(0x0F10) __sfr CLC1CON;
__at(0x0F10) volatile __CLC1CONbits_t CLC1CONbits;

__at(0x0F11) __sfr CLC1POL;
__at(0x0F11) volatile __CLC1POLbits_t CLC1POLbits;

__at(0x0F12) __sfr CLC1SEL0;
__at(0x0F12) volatile __CLC1SEL0bits_t CLC1SEL0bits;

__at(0x0F13) __sfr CLC1SEL1;
__at(0x0F13) volatile __CLC1SEL1bits_t CLC1SEL1bits;

__at(0x0F14) __sfr CLC1GLS0;
__at(0x0F14) volatile __CLC1GLS0bits_t CLC1GLS0bits;

__at(0x0F15) __sfr CLC1GLS1;
__at(0x0F15) volatile __CLC1GLS1bits_t CLC1GLS1bits;

__at(0x0F16) __sfr CLC1GLS2;
__at(0x0F16) volatile __CLC1GLS2bits_t CLC1GLS2bits;

__at(0x0F17) __sfr CLC1GLS3;
__at(0x0F17) volatile __CLC1GLS3bits_t CLC1GLS3bits;

__at(0x0F18) __sfr CLC2CON;
__at(0x0F18) volatile __CLC2CONbits_t CLC2CONbits;

__at(0x0F19) __sfr CLC2POL;
__at(0x0F19) volatile __CLC2POLbits_t CLC2POLbits;

__at(0x0F1A) __sfr CLC2SEL0;
__at(0x0F1A) volatile __CLC2SEL0bits_t CLC2SEL0bits;

__at(0x0F1B) __sfr CLC2SEL1;
__at(0x0F1B) volatile __CLC2SEL1bits_t CLC2SEL1bits;

__at(0x0F1C) __sfr CLC2GLS0;
__at(0x0F1C) volatile __CLC2GLS0bits_t CLC2GLS0bits;

__at(0x0F1D) __sfr CLC2GLS1;
__at(0x0F1D) volatile __CLC2GLS1bits_t CLC2GLS1bits;

__at(0x0F1E) __sfr CLC2GLS2;
__at(0x0F1E) volatile __CLC2GLS2bits_t CLC2GLS2bits;

__at(0x0F1F) __sfr CLC2GLS3;
__at(0x0F1F) volatile __CLC2GLS3bits_t CLC2GLS3bits;

__at(0x0FE3) __sfr BSR_ICDSHAD;

__at(0x0FE4) __sfr STATUS_SHAD;
__at(0x0FE4) volatile __STATUS_SHADbits_t STATUS_SHADbits;

__at(0x0FE5) __sfr WREG_SHAD;

__at(0x0FE6) __sfr BSR_SHAD;

__at(0x0FE7) __sfr PCLATH_SHAD;

__at(0x0FE8) __sfr FSR0L_SHAD;

__at(0x0FE9) __sfr FSR0H_SHAD;

__at(0x0FEA) __sfr FSR1L_SHAD;

__at(0x0FEB) __sfr FSR1H_SHAD;

__at(0x0FED) __sfr STKPTR;

__at(0x0FEE) __sfr TOSL;

__at(0x0FEF) __sfr TOSH;
