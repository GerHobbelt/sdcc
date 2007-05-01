/* Register definitions for pic16c782.
 * This file was automatically generated by:
 *   inc2h.pl V4585
 *   Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
 */
#include <pic16c782.h>

__sfr  __at (INDF_ADDR)                    INDF;
__sfr  __at (TMR0_ADDR)                    TMR0;
__sfr  __at (PCL_ADDR)                     PCL;
__sfr  __at (STATUS_ADDR)                  STATUS;
__sfr  __at (FSR_ADDR)                     FSR;
__sfr  __at (PORTA_ADDR)                   PORTA;
__sfr  __at (PORTB_ADDR)                   PORTB;
__sfr  __at (PCLATH_ADDR)                  PCLATH;
__sfr  __at (INTCON_ADDR)                  INTCON;
__sfr  __at (PIR1_ADDR)                    PIR1;
__sfr  __at (TMR1L_ADDR)                   TMR1L;
__sfr  __at (TMR1H_ADDR)                   TMR1H;
__sfr  __at (T1CON_ADDR)                   T1CON;
__sfr  __at (ADRES_ADDR)                   ADRES;
__sfr  __at (ADCON0_ADDR)                  ADCON0;
__sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
__sfr  __at (TRISA_ADDR)                   TRISA;
__sfr  __at (TRISB_ADDR)                   TRISB;
__sfr  __at (PIE1_ADDR)                    PIE1;
__sfr  __at (PCON_ADDR)                    PCON;
__sfr  __at (WPUB_ADDR)                    WPUB;
__sfr  __at (IOCB_ADDR)                    IOCB;
__sfr  __at (REFCON_ADDR)                  REFCON;
__sfr  __at (LVDCON_ADDR)                  LVDCON;
__sfr  __at (ANSEL_ADDR)                   ANSEL;
__sfr  __at (ADCON1_ADDR)                  ADCON1;
__sfr  __at (PMDATL_ADDR)                  PMDATL;
__sfr  __at (PMADRL_ADDR)                  PMADRL;
__sfr  __at (PMDATH_ADDR)                  PMDATH;
__sfr  __at (PMADRH_ADDR)                  PMADRH;
__sfr  __at (CALCON_ADDR)                  CALCON;
__sfr  __at (PSMCCON0_ADDR)                PSMCCON0;
__sfr  __at (PSMCCON1_ADDR)                PSMCCON1;
__sfr  __at (CM1CON0_ADDR)                 CM1CON0;
__sfr  __at (CM2CON0_ADDR)                 CM2CON0;
__sfr  __at (CM2CON1_ADDR)                 CM2CON1;
__sfr  __at (OPACON_ADDR)                  OPACON;
__sfr  __at (DAC_ADDR)                     DAC;
__sfr  __at (DACON0_ADDR)                  DACON0;
__sfr  __at (PMCON1_ADDR)                  PMCON1;

// 
// bitfield definitions
// 
volatile __ADCON0_bits_t __at(ADCON0_ADDR) ADCON0_bits;
volatile __ADCON1_bits_t __at(ADCON1_ADDR) ADCON1_bits;
volatile __CALCON_bits_t __at(CALCON_ADDR) CALCON_bits;
volatile __CM1CON0_bits_t __at(CM1CON0_ADDR) CM1CON0_bits;
volatile __CM2CON0_bits_t __at(CM2CON0_ADDR) CM2CON0_bits;
volatile __CM2CON1_bits_t __at(CM2CON1_ADDR) CM2CON1_bits;
volatile __DACON0_bits_t __at(DACON0_ADDR) DACON0_bits;
volatile __INTCON_bits_t __at(INTCON_ADDR) INTCON_bits;
volatile __LVDCON_bits_t __at(LVDCON_ADDR) LVDCON_bits;
volatile __OPACON_bits_t __at(OPACON_ADDR) OPACON_bits;
volatile __OPTION_REG_bits_t __at(OPTION_REG_ADDR) OPTION_REG_bits;
volatile __PCON_bits_t __at(PCON_ADDR) PCON_bits;
volatile __PIE1_bits_t __at(PIE1_ADDR) PIE1_bits;
volatile __PIR1_bits_t __at(PIR1_ADDR) PIR1_bits;
volatile __PMCON1_bits_t __at(PMCON1_ADDR) PMCON1_bits;
volatile __PORTA_bits_t __at(PORTA_ADDR) PORTA_bits;
volatile __PORTB_bits_t __at(PORTB_ADDR) PORTB_bits;
volatile __PSMCCON0_bits_t __at(PSMCCON0_ADDR) PSMCCON0_bits;
volatile __PSMCCON1_bits_t __at(PSMCCON1_ADDR) PSMCCON1_bits;
volatile __REFCON_bits_t __at(REFCON_ADDR) REFCON_bits;
volatile __STATUS_bits_t __at(STATUS_ADDR) STATUS_bits;
volatile __T1CON_bits_t __at(T1CON_ADDR) T1CON_bits;
volatile __TRISA_bits_t __at(TRISA_ADDR) TRISA_bits;
volatile __TRISB_bits_t __at(TRISB_ADDR) TRISB_bits;

