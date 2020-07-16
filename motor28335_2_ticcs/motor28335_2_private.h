/*
 * File: motor28335_2_private.h
 *
 * Code generated for Simulink model 'motor28335_2'.
 *
 * Model version                  : 1.354
 * Simulink Coder version         : 8.3 (R2012b) 20-Jul-2012
 * TLC version                    : 8.3 (Jul 21 2012)
 * C/C++ source code generated on : Thu Jul 30 16:48:49 2015
 *
 * Target selection: idelink_ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor28335_2_private_h_
#define RTW_HEADER_motor28335_2_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);
void config_ADC_A(uint16_T maxconvReg , uint16_T adcChselSEQ1Reg, uint16_T
                  adcChselSEQ2Reg, uint16_T adcChselSEQ3Reg, uint16_T
                  adcChselSEQ4Reg);

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C16S16I16L32N16F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C16S16I16L32N16F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void motor28335_2_step0(void);
extern void motor28335_2_step1(void);

#endif                                 /* RTW_HEADER_motor28335_2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
