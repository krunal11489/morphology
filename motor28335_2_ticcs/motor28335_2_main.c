/*
 * File: motor28335_2_main.c
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

#include "motor28335_2.h"
#include "rtwtypes.h"
#include "motor28335_2_private.h"
#include "c2000_main.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include <stdlib.h>
#include <stdio.h>

void init_board(void);
void enable_interrupts(void);
void config_schedulerTimer(void);
void disable_interrupts(void);
volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

/* Function: rt_OneStep -------------------------------------------
 *
 * Abstract:
 *      Perform one step of the model.  Multi-tasking implementation.
 */
void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  motor28335_2_SetEventsForThisBaseStep(eventFlags);
  asm(" SETC INTM");
  PieCtrlRegs.PIEIER1.all |= (1 << 6);
  asm(" CLRC INTM");
  motor28335_2_step(0);

  /* Get model outputs here */
  asm(" SETC INTM");
  PieCtrlRegs.PIEIER1.all &= ~(1 << 6);
  asm(" RPT #5 || NOP");
  IFR &= 0xFFFE;
  PieCtrlRegs.PIEACK.all = 0x1;
  asm(" CLRC INTM");
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    asm(" SETC INTM");
    PieCtrlRegs.PIEIER1.all |= (1 << 6);
    asm(" CLRC INTM");

    /* Step the model for subrate "1" */
    switch (1) {
     case 1 :
      motor28335_2_step(1);

      /* Get model outputs here */
      break;

     default :
      break;
    }

    asm(" SETC INTM");
    PieCtrlRegs.PIEIER1.all &= ~(1 << 6);
    asm(" RPT #5 || NOP");
    IFR &= 0xFFFE;
    PieCtrlRegs.PIEACK.all = 0x1;
    asm(" CLRC INTM");
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

/* Function: main -------------------------------------------
 *
 * Abstract:
 *      Entry point into the code.
 */
void main(void)
{
  volatile boolean_T noErr;
  init_board();
  rtmSetErrorStatus(motor28335_2_M, 0);
  motor28335_2_initialize();
  config_schedulerTimer();
  noErr =
    rtmGetErrorStatus(motor28335_2_M) == (NULL);
  enable_interrupts();
  while (noErr ) {
    noErr =
      rtmGetErrorStatus(motor28335_2_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  motor28335_2_terminate();
  disable_interrupts();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
