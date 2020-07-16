#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "motor28335_2.h"
#include "motor28335_2_private.h"

void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint)
{
  EALLOW;                              /* Enable EALLOW*/

  /* Enable internal pull-up for the selected pins */
  GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;  /* Enable pull-up on GPIO20 (EQEP1A)*/
  GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;  /* Enable pull-up on GPIO21 (EQEP1B)*/
  GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;  /* Enable pull-up on GPIO22 (EQEP1S)*/
  GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;  /* Enable pull-up on GPIO23 (EQEP1I)*/

  /* Configure eQEP-1 pins using GPIO regs*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1; /* Configure GPIO20 as EQEP1A*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1; /* Configure GPIO21 as EQEP1B  */
  GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 1; /* Configure GPIO22 as EQEP1S*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 1; /* Configure GPIO23 as EQEP1I*/
  EDIS;
  EQep1Regs.QPOSINIT= pcInitialvalue;  /*eQEP Initialization Position Count*/
  EQep1Regs.QPOSMAX= pcmaximumvalue;   /*eQEP Maximum Position Count*/
  EQep1Regs.QUPRD= unittimerperiod;    /*eQEP Unit Period Register*/
  EQep1Regs.QWDPRD= watchdogtimer;     /*eQEP watchdog timer Register*/
  EQep1Regs.QDECCTL.all = qdecctl;     /*eQEP Decoder Control (QDECCTL) Register*/
  EQep1Regs.QEPCTL.all = qepctl;       /*eQEP Control (QEPCTL) Register*/
  EQep1Regs.QPOSCTL.all = qposctl;     /*eQEP Position-compare Control (QPOSCTL) Register*/
  EQep1Regs.QCAPCTL.all = qcapctl;     /*eQEP Capture Control (QCAPCTL) Register*/
  EQep1Regs.QEPCTL.bit.FREE_SOFT= 2;   /*unaffected by emulation suspend*/
  EQep1Regs.QPOSCMP = comparevalue;    /*eQEP Position-compare*/
  EQep1Regs.QEINT.all = qeint;         /*eQEPx interrupt enable register*/
}
