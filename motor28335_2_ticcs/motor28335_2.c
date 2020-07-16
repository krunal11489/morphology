/*
 * File: motor28335_2.c
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
#include "motor28335_2_private.h"

/* Block signals (auto storage) */
BlockIO_motor28335_2 motor28335_2_B;

/* Block states (auto storage) */
D_Work_motor28335_2 motor28335_2_DWork;

/* Real-time model */
RT_MODEL_motor28335_2 motor28335_2_M_;
RT_MODEL_motor28335_2 *const motor28335_2_M = &motor28335_2_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void motor28335_2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(motor28335_2_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (motor28335_2_M->Timing.TaskCounters.TID[1])++;
  if ((motor28335_2_M->Timing.TaskCounters.TID[1]) > 199) {/* Sample time: [0.01s, 0.0s] */
    motor28335_2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void motor28335_2_step0(void)          /* Sample time: [5.0E-5s, 0.0s] */
{
  /* local block i/o variables */
  int32_T rtb_ShiftArithmetic[2];
  int32_T rtb_Add_h[3];
  int32_T rtb_cosIQN;
  int32_T rtb_Sum1_d;
  int32_T rtb_SpaceVectorGenerator_o1;
  int32_T rtb_ShiftArithmetic1_n;
  int32_T rtb_Saturation;
  int32_T rtb_SpaceVectorGenerator_o3;
  int32_T rtb_SpaceVectorGenerator_o2;
  int32_T rtb_Product_cs;
  int32_T rtb_MagnitudeIQN;
  int32_T rtb_Saturation_b;
  int32_T rtb_IQN1toIQN2[3];
  uint16_T rtb_DataTypeConversion[3];
  uint16_T rtb_Add1_i;
  uint16_T rtb_DataTypeConversion2_o;
  uint16_T rtb_BitwiseOperator;
  uint16_T rtb_Switch_l;
  uint16_T rtb_Add_j;
  int32_T rtb_Sum2;
  int32_T rtb_Sum1_d2;
  int32_T rtb_Product;
  int32_T rtb_Product_j;
  int32_T rtb_UnitDelay;
  int32_T rtb_Sum1_l;
  int32_T rtb_Sum1_i;
  int32_T rtb_Sum3;
  int32_T rtb_UnitDelay_o_idx;
  int32_T rtb_UnitDelay_o_idx_0;

  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* UnitDelay: '<S16>/Unit Delay' */
  rtb_UnitDelay_o_idx = motor28335_2_DWork.UnitDelay_DSTATE[0];
  rtb_UnitDelay_o_idx_0 = motor28335_2_DWork.UnitDelay_DSTATE[1];

  /* S-Function Block: <S3>/ADC1 (c280xadc) */
  {
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;  /* Reset SEQ1 module*/
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;/*clear INT sequencer*/
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  /* Software Trigger*/
    while (AdcRegs.ADCST.bit.INT_SEQ1 == 0) {
    }                                  /*Wait for Sequencer INT bit to clear */

    asm(" RPT #11 || NOP");
    motor28335_2_B.ADC1[0] = (AdcRegs.ADCRESULT0) >> 4;
    motor28335_2_B.ADC1[1] = (AdcRegs.ADCRESULT1) >> 4;
    motor28335_2_B.ADC1[2] = (AdcRegs.ADCRESULT2) >> 4;
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  motor28335_2_B.DataTypeConversion[0] = motor28335_2_B.ADC1[0];
  motor28335_2_B.DataTypeConversion[1] = motor28335_2_B.ADC1[1];
  motor28335_2_B.DataTypeConversion[2] = motor28335_2_B.ADC1[2];

  /* ArithShift: '<S4>/Shift Arithmetic' incorporates:
   *  Sum: '<S4>/Add'
   */
  rtb_ShiftArithmetic[0] = (motor28335_2_B.DataTypeConversion[0] - 2048L) << 6U;
  rtb_ShiftArithmetic[1] = (motor28335_2_B.DataTypeConversion[1] - 2048L) << 6U;

  /* C28x IQmath Library (stiiqmath_iqmpyi32) - '<S25>/IQN x int1' */
  {
    rtb_Product_cs = _IQ17mpyI32 (rtb_ShiftArithmetic[0], (((int32_T)-1L)));
  }

  /* S-Function (scheckfractionlength): '<S10>/ ' */
  rtb_cosIQN = rtb_Product_cs;

  /* S-Function Block: <S3>/eQEP (c280xqep) */
  {
    motor28335_2_B.eQEP = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
  }

  /* S-Function Block: <S22>/CAPFIFOA1 (memorycopy) */
  {
    uint16_T *memindsrc = (uint16_T *) (29730U);
    uint16_T *meminddst = (uint16_T *) (&rtb_Add1_i);
    *(uint16_T *) (meminddst) = *(uint16_T *) (memindsrc);
  }

  /* S-Function (sfix_bitop): '<S22>/Bitwise Operator' */
  rtb_BitwiseOperator = rtb_Add1_i & 8192U;

  /* If: '<S22>/If' */
  if (rtb_BitwiseOperator > 0U) {
    /* Outputs for IfAction SubSystem: '<S22>/Subsystem' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */

    /* S-Function Block: <S27>/CAP1FBOT (memorycopy) */
    {
      uint16_T *memindsrc = (uint16_T *) (29737U);
      uint16_T *meminddst = (uint16_T *) (&motor28335_2_B.CAP1FBOT);
      *(uint16_T *) (meminddst) = *(uint16_T *) (memindsrc);
    }

    /* End of Outputs for SubSystem: '<S22>/Subsystem' */
  }

  /* End of If: '<S22>/If' */

  /* Switch: '<S22>/Switch' incorporates:
   *  UnitDelay: '<S22>/Unit Delay2'
   */
  if (rtb_BitwiseOperator != 0U) {
    rtb_Switch_l = motor28335_2_B.CAP1FBOT;
  } else {
    rtb_Switch_l = motor28335_2_DWork.UnitDelay2_DSTATE_b;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<S24>/offset1'
   */
  rtb_Add_j = (motor28335_2_B.eQEP - rtb_Switch_l) + 850U;

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/negative direction offset'
   *  Sum: '<S24>/Add2'
   */
  if (rtb_Add_j >= 32768U) {
    rtb_Add1_i = rtb_Add_j - 1536U;
  } else {
    rtb_Add1_i = rtb_Add_j;
  }

  /* End of Switch: '<S24>/Switch' */

  /* Product: '<S24>/Divide' incorporates:
   *  Constant: '<S24>/Encoder Resolution'
   */
  rtb_DataTypeConversion2_o = rtb_Add1_i / 2000U;

  /* Sum: '<S24>/Add1' incorporates:
   *  Constant: '<S24>/Encoder Resolution'
   *  Product: '<S24>/Product'
   */
  rtb_Add1_i -= rtb_DataTypeConversion2_o * 2000U;

  /* DataTypeConversion: '<S24>/Data Type Conversion1' */
  rtb_SpaceVectorGenerator_o3 = rtb_Add1_i;

  /* C28x IQmath Library (stiiqmath_iqmpy) - '<S24>/IQN x IQN' */
  {
    rtb_SpaceVectorGenerator_o2 = _IQ17mpy (((int32_T)8589935L),
      rtb_SpaceVectorGenerator_o3);
  }

  /* ArithShift: '<S22>/Shift Arithmetic' */
  motor28335_2_B.ShiftArithmetic = rtb_BitwiseOperator >> 13U;

  /* Sum: '<S22>/Add' incorporates:
   *  UnitDelay: '<S22>/Unit Delay1'
   */
  rtb_DataTypeConversion2_o = motor28335_2_B.ShiftArithmetic +
    motor28335_2_DWork.UnitDelay1_DSTATE;

  /* Switch: '<S22>/Switch1' */
  if (rtb_DataTypeConversion2_o == 0U) {
    rtb_DataTypeConversion2_o = motor28335_2_B.ShiftArithmetic;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* Saturate: '<S22>/Saturation' */
  if (rtb_DataTypeConversion2_o <= 1U) {
    motor28335_2_B.Saturation_d = rtb_DataTypeConversion2_o;
  } else {
    motor28335_2_B.Saturation_d = 1U;
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* UnitDelay: '<S29>/Unit Delay' */
  rtb_UnitDelay = motor28335_2_DWork.UnitDelay_DSTATE_m;

  /* C28x DMC Library (tidmcrampcntl) - '<S26>/Ramp Control' */
  {
    int32_T* ptrrampDlyCntl = &motor28335_2_DWork.RampControl_RAMP_DLY_CNTL;
    int32_T* ptrOldSetPoint = &motor28335_2_DWork.RampControl_PREV_SETPOINT;
    if (((int32_T)13107L) != *ptrOldSetPoint ) {
      /* Original location of the update, now moved after the "if" branch */
      if (*ptrrampDlyCntl >= (long) 1) {
        if (((int32_T)13107L) >= *ptrOldSetPoint) {
          motor28335_2_B.RampControl_o1 = *ptrOldSetPoint + _IQ17(0.0000305);
          if (motor28335_2_B.RampControl_o1 > _IQ17(1.0F))
            motor28335_2_B.RampControl_o1 = _IQ17(1.0F);
          *ptrrampDlyCntl = 0;
        } else {
          motor28335_2_B.RampControl_o1 = *ptrOldSetPoint - _IQ17(0.0000305);
          if (motor28335_2_B.RampControl_o1 < _IQ17(0.0F))
            motor28335_2_B.RampControl_o1 = _IQ17(0.0F);
          *ptrrampDlyCntl = 0;
        }

        *ptrOldSetPoint++ = motor28335_2_B.RampControl_o1;
      }

      /* Moved the update here to get more consistent Simulink time change */
      *ptrrampDlyCntl += 1;
    } else {
      motor28335_2_B.RampControl_o1 = *ptrOldSetPoint;
      motor28335_2_B.RampControl_o2 = 0x7FFFFFFF;
    }

    ptrrampDlyCntl++;
  }

  /* S-Function (scheckfractionlength): '<S29>/ ' */
  /* MATLAB Function 'Ramp Generator/Convert Param To fix-pt with floor  rounding mode/Embedded MATLAB Function': '<S33>:1' */
  /* '<S33>:1:5' */
  rtb_SpaceVectorGenerator_o3 = motor28335_2_B.RampControl_o1;

  /* Product: '<S29>/Product1' incorporates:
   *  MATLAB Function: '<S30>/Embedded MATLAB Function'
   */
  rtb_MagnitudeIQN = _IQ17mpy(655L, rtb_SpaceVectorGenerator_o3);

  /* Sum: '<S29>/Sum2' */
  rtb_Sum2 = rtb_UnitDelay + rtb_MagnitudeIQN;

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/1'
   *  RelationalOperator: '<S31>/Relational Operator'
   *  Sum: '<S31>/Sum2'
   */
  if (rtb_Sum2 > 131072L) {
    rtb_Sum2 -= 131072L;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/1'
   *  RelationalOperator: '<S31>/Relational Operator1'
   *  Sum: '<S31>/Sum1'
   */
  if (rtb_Sum2 < -131072L) {
    rtb_Sum2 += 131072L;
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Switch: '<S4>/Switch1' */
  if (motor28335_2_B.Saturation_d == 0U) {
    /* Sum: '<S29>/Sum1' incorporates:
     *  Product: '<S29>/Product2'
     */
    rtb_UnitDelay = rtb_Sum2;

    /* Switch: '<S32>/Switch2' incorporates:
     *  Constant: '<S32>/1'
     *  Product: '<S29>/Product2'
     *  RelationalOperator: '<S32>/Relational Operator2'
     *  Sum: '<S32>/Sum4'
     */
    if (rtb_Sum2 > 131072L) {
      rtb_UnitDelay = rtb_Sum2 - 131072L;
    }

    /* End of Switch: '<S32>/Switch2' */

    /* Switch: '<S32>/Switch3' incorporates:
     *  Constant: '<S32>/1'
     *  RelationalOperator: '<S32>/Relational Operator3'
     *  Sum: '<S32>/Sum3'
     */
    if (rtb_UnitDelay < -131072L) {
      rtb_SpaceVectorGenerator_o2 = rtb_UnitDelay + 131072L;
    } else {
      rtb_SpaceVectorGenerator_o2 = rtb_UnitDelay;
    }

    /* End of Switch: '<S32>/Switch3' */
  }

  /* End of Switch: '<S4>/Switch1' */

  /* S-Function (scheckfractionlength): '<S10>/ 1' */
  rtb_MagnitudeIQN = rtb_SpaceVectorGenerator_o2;

  /* C28x IQmath Library (stiiqmath_iqtrig) - '<S10>/cos IQN1' */
  {
    rtb_SpaceVectorGenerator_o3 = _IQ17cosPU(rtb_MagnitudeIQN);
  }

  /* Product: '<S10>/Product' */
  rtb_Saturation = _IQ17mpy(rtb_cosIQN, rtb_SpaceVectorGenerator_o3);

  /* C28x IQmath Library (stiiqmath_iqmpyi32) - '<S25>/IQN x int2' */
  {
    rtb_Saturation_b = _IQ17mpyI32 (rtb_ShiftArithmetic[1], (((int32_T)-1L)));
  }

  /* Product: '<S8>/Product1' incorporates:
   *  MATLAB Function: '<S12>/Embedded MATLAB Function'
   *  Product: '<S8>/Product'
   *  Sum: '<S8>/Sum1'
   */
  /* MATLAB Function 'Ramp Generator/Convert Param To fix-pt with floor  rounding mode/Embedded MATLAB Function': '<S13>:1' */
  /* '<S13>:1:5' */
  rtb_Sum1_d2 = _IQ17mpy(75674L, (rtb_Saturation_b << 1U) + rtb_Product_cs);

  /* C28x IQmath Library (stiiqmath_iqtrig) - '<S10>/sin IQN1' */
  {
    rtb_Saturation_b = _IQ17sinPU(rtb_MagnitudeIQN);
  }

  /* Product: '<S10>/Product1' */
  rtb_MagnitudeIQN = _IQ17mpy(rtb_Sum1_d2, rtb_Saturation_b);

  /* Sum: '<S10>/Sum4' */
  rtb_Product_cs = rtb_Saturation + rtb_MagnitudeIQN;

  /* Sum: '<S14>/Sum2' */
  rtb_Saturation = -rtb_Product_cs;

  /* Product: '<S14>/Product' */
  rtb_Product = _IQ17mpyIQX(rtb_Saturation, 17, 13107L, 16);

  /* Product: '<S17>/Product' */
  rtb_MagnitudeIQN = 0L;

  /* Product: '<S18>/Product' */
  rtb_Saturation = _IQ17mpyIQX(131L, 16, rtb_Product, 17);

  /* UnitDelay: '<S14>/Unit Delay4' */
  rtb_Product_cs = motor28335_2_DWork.UnitDelay4_DSTATE;

  /* Sum: '<S18>/Sum1' incorporates:
   *  Product: '<S18>/Product1'
   *  UnitDelay: '<S14>/Unit Delay3'
   */
  rtb_Sum1_l = (motor28335_2_DWork.UnitDelay3_DSTATE + rtb_Saturation) +
    _IQ17mpyIQX(131L, 16, rtb_Product_cs, 17);

  /* Sum: '<S14>/Sum1' */
  rtb_UnitDelay = (rtb_Product + rtb_MagnitudeIQN) + rtb_Sum1_l;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_UnitDelay >= 131072L) {
    rtb_Saturation = 131072L;
  } else if (rtb_UnitDelay <= -131072L) {
    rtb_Saturation = -131072L;
  } else {
    rtb_Saturation = rtb_UnitDelay;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* S-Function (scheckfractionlength): '<S15>/ ' */
  rtb_MagnitudeIQN = motor28335_2_B.Saturation;

  /* Product: '<S10>/Product2' */
  rtb_Product_cs = _IQ17mpy(rtb_Sum1_d2, rtb_SpaceVectorGenerator_o3);

  /* Sum: '<S10>/Sum3' incorporates:
   *  Product: '<S10>/Product3'
   */
  rtb_Saturation_b = rtb_Product_cs - _IQ17mpy(rtb_cosIQN, rtb_Saturation_b);

  /* Product: '<S15>/Product' incorporates:
   *  Sum: '<S15>/Sum2'
   */
  rtb_Product_j = _IQ17mpyIQX(rtb_MagnitudeIQN - rtb_Saturation_b, 17, 13107L,
    16);

  /* Product: '<S19>/Product' */
  rtb_Saturation_b = 0L;

  /* UnitDelay: '<S15>/Unit Delay4' */
  rtb_MagnitudeIQN = motor28335_2_DWork.UnitDelay4_DSTATE_c;

  /* Product: '<S20>/Product1' */
  rtb_SpaceVectorGenerator_o3 = _IQ17mpyIQX(131L, 16, rtb_MagnitudeIQN, 17);

  /* Sum: '<S20>/Sum1' incorporates:
   *  Product: '<S20>/Product'
   *  UnitDelay: '<S15>/Unit Delay3'
   */
  rtb_Sum1_i = (motor28335_2_DWork.UnitDelay3_DSTATE_i + _IQ17mpyIQX(131L, 16,
    rtb_Product_j, 17)) + rtb_SpaceVectorGenerator_o3;

  /* Sum: '<S15>/Sum1' */
  rtb_Sum1_d2 = (rtb_Product_j + rtb_Saturation_b) + rtb_Sum1_i;

  /* Saturate: '<S15>/Saturation' */
  if (rtb_Sum1_d2 >= 131072L) {
    rtb_Saturation_b = 131072L;
  } else if (rtb_Sum1_d2 <= -131072L) {
    rtb_Saturation_b = -131072L;
  } else {
    rtb_Saturation_b = rtb_Sum1_d2;
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* C28x IQmath Library (stiiqmath_iqmag) - '<S16>/Magnitude IQN' */
  {
    rtb_MagnitudeIQN = _IQ17mag (rtb_Saturation, rtb_Saturation_b);
  }

  /* Switch: '<S16>/Switch1' */
  if (!(rtb_MagnitudeIQN >= 131072L)) {
    rtb_UnitDelay_o_idx = rtb_Saturation;
  }

  if (!(rtb_MagnitudeIQN >= 131072L)) {
    rtb_UnitDelay_o_idx_0 = rtb_Saturation_b;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* S-Function (scheckfractionlength): '<S9>/ ' */
  rtb_SpaceVectorGenerator_o3 = rtb_UnitDelay_o_idx;

  /* C28x IQmath Library (stiiqmath_iqtrig) - '<S9>/cos IQN' */
  {
    rtb_cosIQN = _IQ17cosPU(rtb_SpaceVectorGenerator_o2);
  }

  /* Product: '<S9>/Product' */
  rtb_Product_cs = _IQ17mpy(rtb_SpaceVectorGenerator_o3, rtb_cosIQN);

  /* S-Function (scheckfractionlength): '<S9>/ 1' */
  rtb_SpaceVectorGenerator_o1 = rtb_UnitDelay_o_idx_0;

  /* C28x IQmath Library (stiiqmath_iqtrig) - '<S9>/sin IQN' */
  {
    rtb_Sum1_d = _IQ17sinPU(rtb_SpaceVectorGenerator_o2);
  }

  /* Product: '<S9>/Product1' */
  rtb_SpaceVectorGenerator_o2 = _IQ17mpy(rtb_SpaceVectorGenerator_o1, rtb_Sum1_d);

  /* Sum: '<S9>/Sum2' */
  rtb_ShiftArithmetic1_n = rtb_Product_cs - rtb_SpaceVectorGenerator_o2;

  /* Product: '<S9>/Product2' */
  rtb_SpaceVectorGenerator_o2 = _IQ17mpy(rtb_SpaceVectorGenerator_o1, rtb_cosIQN);

  /* Product: '<S9>/Product3' */
  rtb_SpaceVectorGenerator_o1 = _IQ17mpy(rtb_SpaceVectorGenerator_o3, rtb_Sum1_d);

  /* Sum: '<S9>/Sum1' */
  rtb_Sum1_d = rtb_SpaceVectorGenerator_o2 + rtb_SpaceVectorGenerator_o1;

  /* C28x DMC Library (tidmcsvgendq) - '<S6>/Space Vector Generator' */
  {
    int16_T sector;
    int32_T Va, Vb, Vc;
    sector = 0;
    Va = rtb_Sum1_d;
    Vb = _IQ17mpy (_IQ17(-0.5),rtb_Sum1_d) + _IQ17mpy (_IQ17(0.8660254),
      rtb_ShiftArithmetic1_n);
    Vc = _IQ17mpy (_IQ17(-0.5),rtb_Sum1_d) - _IQ17mpy (_IQ17(0.8660254),
      rtb_ShiftArithmetic1_n);
    if (Va > 0)
      sector = 1;
    if (Vb > 0)
      sector = sector + 2;
    if (Vc > 0)
      sector = sector + 4;
    Vb = _IQ17mpy (_IQ17(0.5),rtb_Sum1_d) + _IQ17mpy (_IQ17(0.8660254),
      rtb_ShiftArithmetic1_n);
    Vc = _IQ17mpy (_IQ17(0.5),rtb_Sum1_d) - _IQ17mpy (_IQ17(0.8660254),
      rtb_ShiftArithmetic1_n);
    if (sector==0) {
      rtb_SpaceVectorGenerator_o1 = _IQ17(0.5);
      rtb_SpaceVectorGenerator_o2 = _IQ17(0.5);
      rtb_SpaceVectorGenerator_o3 = _IQ17(0.5);
    } else if (sector==1) {
      rtb_SpaceVectorGenerator_o2 = _IQ17mpy (_IQ17(0.5), (_IQ17(1) - Vc - Vb));
      rtb_SpaceVectorGenerator_o1 = rtb_SpaceVectorGenerator_o2 + Vc;
      rtb_SpaceVectorGenerator_o3 = rtb_SpaceVectorGenerator_o1 + Vb;
    } else if (sector==2) {
      rtb_SpaceVectorGenerator_o1 = _IQ17mpy (_IQ17(0.5), (_IQ17(1) - Vb + Va));
      rtb_SpaceVectorGenerator_o3 = rtb_SpaceVectorGenerator_o1 + Vb;
      rtb_SpaceVectorGenerator_o2 = rtb_SpaceVectorGenerator_o3 - Va;
    } else if (sector==3) {
      rtb_SpaceVectorGenerator_o1 = _IQ17mpy (_IQ17(0.5), (_IQ17(1) + Vc - Va));
      rtb_SpaceVectorGenerator_o2 = rtb_SpaceVectorGenerator_o1 - Vc;
      rtb_SpaceVectorGenerator_o3 = rtb_SpaceVectorGenerator_o2 + Va;
    } else if (sector==4) {
      rtb_SpaceVectorGenerator_o3 = _IQ17mpy (_IQ17(0.5), (_IQ17(1) + Va - Vc));
      rtb_SpaceVectorGenerator_o2 = rtb_SpaceVectorGenerator_o3 - Va;
      rtb_SpaceVectorGenerator_o1 = rtb_SpaceVectorGenerator_o2 + Vc;
    } else if (sector==5) {
      rtb_SpaceVectorGenerator_o2 = _IQ17mpy (_IQ17(0.5), (_IQ17(1) - Va + Vb));
      rtb_SpaceVectorGenerator_o3 = rtb_SpaceVectorGenerator_o2 + Va;
      rtb_SpaceVectorGenerator_o1 = rtb_SpaceVectorGenerator_o3 - Vb;
    } else if (sector==6) {
      rtb_SpaceVectorGenerator_o3 = _IQ17mpy (_IQ17(0.5), (_IQ17(1) + Vb + Vc));
      rtb_SpaceVectorGenerator_o1 = rtb_SpaceVectorGenerator_o3 - Vb;
      rtb_SpaceVectorGenerator_o2 = rtb_SpaceVectorGenerator_o1 - Vc;
    }

    rtb_SpaceVectorGenerator_o1 = _IQ17mpy (_IQ17(2),
      (rtb_SpaceVectorGenerator_o1 - _IQ17(0.5)));
    rtb_SpaceVectorGenerator_o2 = _IQ17mpy (_IQ17(2),
      (rtb_SpaceVectorGenerator_o2 - _IQ17(0.5)));
    rtb_SpaceVectorGenerator_o3 = _IQ17mpy (_IQ17(2),
      (rtb_SpaceVectorGenerator_o3 - _IQ17(0.5)));
  }

  /* Sum: '<S7>/Add' incorporates:
   *  Constant: '<S7>/Constant'
   */
  rtb_Add_h[0] = 131072L + rtb_SpaceVectorGenerator_o1;
  rtb_Add_h[1] = 131072L + rtb_SpaceVectorGenerator_o2;
  rtb_Add_h[2] = 131072L + rtb_SpaceVectorGenerator_o3;

  /* C28x IQmath Library (stiiqmath_iqntoiq) - '<S7>/IQN1 to IQN2' */
  {
    rtb_IQN1toIQN2[0] = (long)(rtb_Add_h[0] >> 6);
    rtb_IQN1toIQN2[1] = (long)(rtb_Add_h[1] >> 6);
    rtb_IQN1toIQN2[2] = (long)(rtb_Add_h[2] >> 6);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  rtb_DataTypeConversion[0] = (uint16_T)rtb_IQN1toIQN2[0];
  rtb_DataTypeConversion[1] = (uint16_T)rtb_IQN1toIQN2[1];
  rtb_DataTypeConversion[2] = (uint16_T)rtb_IQN1toIQN2[2];

  /* S-Function (c280xpwm): '<Root>/ePWM' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion[0]);
  }

  /*-- Update CMPB value for ePWM1 --*/
  {
    EPwm1Regs.CMPB = (uint16_T)(rtb_DataTypeConversion[0]);
  }

  /* S-Function (c280xpwm): '<Root>/ePWM1' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion[1]);
  }

  /*-- Update CMPB value for ePWM2 --*/
  {
    EPwm2Regs.CMPB = (uint16_T)(rtb_DataTypeConversion[1]);
  }

  /* S-Function (c280xpwm): '<Root>/ePWM2' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion[2]);
  }

  /*-- Update CMPB value for ePWM3 --*/
  {
    EPwm3Regs.CMPB = (uint16_T)(rtb_DataTypeConversion[2]);
  }

  /* Sum: '<S14>/Sum3' */
  rtb_Sum3 = rtb_Saturation - rtb_UnitDelay;

  /* Sum: '<S15>/Sum3' */
  rtb_UnitDelay = rtb_Saturation_b - rtb_Sum1_d2;

  /* ArithShift: '<S21>/Shift Arithmetic' incorporates:
   *  Constant: '<S21>/Constant'
   *  Sum: '<S21>/Add'
   */
  rtb_ShiftArithmetic1_n = (rtb_MagnitudeIQN + 131072L) >> 3U;

  /* DataTypeConversion: '<S21>/Data Type Conversion1' */
  rtb_DataTypeConversion2_o = (uint16_T)rtb_ShiftArithmetic1_n;

  /* S-Function (c280xpwm): '<S21>/ePWM' */

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion2_o);
  }

  /*-- Update CMPB value for ePWM4 --*/
  {
    EPwm4Regs.CMPB = (uint16_T)(rtb_DataTypeConversion2_o);
  }

  /* ArithShift: '<S21>/Shift Arithmetic1' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Sum: '<S21>/Add1'
   */
  rtb_ShiftArithmetic1_n = (rtb_Saturation + 131072L) >> 3U;

  /* DataTypeConversion: '<S21>/Data Type Conversion2' */
  rtb_DataTypeConversion2_o = (uint16_T)rtb_ShiftArithmetic1_n;

  /* S-Function (c280xpwm): '<S21>/ePWM1' */

  /*-- Update CMPA value for ePWM5 --*/
  {
    EPwm5Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion2_o);
  }

  /*-- Update CMPB value for ePWM5 --*/
  {
    EPwm5Regs.CMPB = (uint16_T)(rtb_DataTypeConversion2_o);
  }

  /* S-Function Block: <S22>/Digital Output (c280xgpio_do) */
  {
    GpioDataRegs.GPBSET.bit.GPIO32 = (motor28335_2_B.ShiftArithmetic != 0);
    GpioDataRegs.GPBCLEAR.bit.GPIO32 = !(motor28335_2_B.ShiftArithmetic != 0);
  }

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  motor28335_2_DWork.UnitDelay_DSTATE[0] = rtb_UnitDelay_o_idx;
  motor28335_2_DWork.UnitDelay_DSTATE[1] = rtb_UnitDelay_o_idx_0;

  /* Update for UnitDelay: '<S22>/Unit Delay2' */
  motor28335_2_DWork.UnitDelay2_DSTATE_b = rtb_Switch_l;

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  motor28335_2_DWork.UnitDelay1_DSTATE = motor28335_2_B.Saturation_d;

  /* Update for UnitDelay: '<S29>/Unit Delay' */
  motor28335_2_DWork.UnitDelay_DSTATE_m = rtb_Sum2;

  /* Update for UnitDelay: '<S14>/Unit Delay2' */
  motor28335_2_DWork.UnitDelay2_DSTATE = rtb_Product;

  /* Update for UnitDelay: '<S14>/Unit Delay3' */
  motor28335_2_DWork.UnitDelay3_DSTATE = rtb_Sum1_l;

  /* Update for UnitDelay: '<S14>/Unit Delay4' */
  motor28335_2_DWork.UnitDelay4_DSTATE = rtb_Sum3;

  /* Update for UnitDelay: '<S15>/Unit Delay2' */
  motor28335_2_DWork.UnitDelay2_DSTATE_ot = rtb_Product_j;

  /* Update for UnitDelay: '<S15>/Unit Delay3' */
  motor28335_2_DWork.UnitDelay3_DSTATE_i = rtb_Sum1_i;

  /* Update for UnitDelay: '<S15>/Unit Delay4' */
  motor28335_2_DWork.UnitDelay4_DSTATE_c = rtb_UnitDelay;
}

/* Model step function for TID1 */
void motor28335_2_step1(void)          /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  int32_T rtb_Product_m;
  int32_T rtb_Product_p;
  int32_T rtb_UnitDelay4;
  int32_T rtb_Product_c;
  int32_T rtb_Sum1_pk;
  int32_T rtb_Add1;
  int32_T rtb_Sum1_g;

  /* Sum: '<S23>/Add2' incorporates:
   *  ArithShift: '<S23>/Shift Arithmetic1'
   *  Constant: '<S23>/Constant2'
   */
  rtb_UnitDelay4 = (motor28335_2_B.DataTypeConversion[2] << 5U) - 13107L;

  /* Saturate: '<S23>/Saturation' */
  if (rtb_UnitDelay4 >= 131072L) {
    rtb_UnitDelay4 = 131072L;
  } else {
    if (rtb_UnitDelay4 <= 0L) {
      rtb_UnitDelay4 = 0L;
    }
  }

  /* End of Saturate: '<S23>/Saturation' */

  /* C28x IQmath Library (stiiqmath_iqmpy) - '<S23>/IQN x IQN' */
  {
    rtb_Product_m = _IQ17mpy (rtb_UnitDelay4, ((int32_T)10486L));
  }

  /* UnitDelay: '<S23>/Unit Delay' */
  rtb_UnitDelay4 = motor28335_2_DWork.UnitDelay_DSTATE_mm;

  /* C28x IQmath Library (stiiqmath_iqmpy) - '<S23>/IQN x IQN1' */
  {
    rtb_Product_p = _IQ17mpy (motor28335_2_ConstB.Add, rtb_UnitDelay4);
  }

  /* Sum: '<S23>/Add1' */
  rtb_Add1 = rtb_Product_m + rtb_Product_p;

  /* Switch: '<S23>/Switch1' incorporates:
   *  Constant: '<S23>/Constant3'
   */
  if (motor28335_2_B.Saturation_d != 0U) {
    rtb_Product_p = rtb_Add1;
  } else {
    rtb_Product_p = 13107L;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* DataTypeConversion: '<S28>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S28>/Data Type Conversion2'
   *  Sum: '<S28>/Add'
   *  UnitDelay: '<S28>/Unit Delay'
   */
  rtb_Product_m = (int16_T)(motor28335_2_B.eQEP -
    motor28335_2_DWork.UnitDelay_DSTATE_f);

  /* C28x IQmath Library (stiiqmath_iqntoiq) - '<S28>/IQN1 to IQN2' */
  {
    rtb_UnitDelay4 = (long)(rtb_Product_m << 7);
  }

  /* C28x IQmath Library (stiiqmath_iqmpyi32) - '<S24>/IQN x int2' */
  {
    rtb_Product_m = _IQ17mpyI32 (rtb_UnitDelay4, ((int32_T)1L));
  }

  /* Sum: '<S35>/Sum2' */
  rtb_UnitDelay4 = rtb_Product_p - rtb_Product_m;

  /* Product: '<S35>/Product' */
  rtb_Product_c = rtb_UnitDelay4 >> 1U;

  /* Product: '<S36>/Product' */
  rtb_Product_m = 0L;

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant'
   */
  rtb_Product_p = _IQ17mpy(13107L, rtb_Product_c);

  /* UnitDelay: '<S35>/Unit Delay4' */
  rtb_UnitDelay4 = motor28335_2_DWork.UnitDelay4_DSTATE_o;

  /* Sum: '<S37>/Sum1' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Product: '<S37>/Product1'
   *  UnitDelay: '<S35>/Unit Delay3'
   */
  rtb_Sum1_g = (motor28335_2_DWork.UnitDelay3_DSTATE_o + rtb_Product_p) +
    _IQ17mpy(13107L, rtb_UnitDelay4);

  /* Sum: '<S35>/Sum1' */
  rtb_Sum1_pk = (rtb_Product_c + rtb_Product_m) + rtb_Sum1_g;

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Sum1_pk >= 131072L) {
    motor28335_2_B.Saturation = 131072L;
  } else if (rtb_Sum1_pk <= -131072L) {
    motor28335_2_B.Saturation = -131072L;
  } else {
    motor28335_2_B.Saturation = rtb_Sum1_pk;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  motor28335_2_DWork.UnitDelay_DSTATE_mm = rtb_Add1;

  /* Update for UnitDelay: '<S28>/Unit Delay' */
  motor28335_2_DWork.UnitDelay_DSTATE_f = motor28335_2_B.eQEP;

  /* Update for UnitDelay: '<S35>/Unit Delay2' */
  motor28335_2_DWork.UnitDelay2_DSTATE_o = rtb_Product_c;

  /* Update for UnitDelay: '<S35>/Unit Delay3' */
  motor28335_2_DWork.UnitDelay3_DSTATE_o = rtb_Sum1_g;

  /* Update for UnitDelay: '<S35>/Unit Delay4' incorporates:
   *  Sum: '<S35>/Sum3'
   */
  motor28335_2_DWork.UnitDelay4_DSTATE_o = motor28335_2_B.Saturation -
    rtb_Sum1_pk;
}

/* Model step wrapper function for compatibility with a static main program */
void motor28335_2_step(int_T tid)
{
  switch (tid) {
   case 0 :
    motor28335_2_step0();
    break;

   case 1 :
    motor28335_2_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void motor28335_2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor28335_2_M, 0,
                sizeof(RT_MODEL_motor28335_2));

  /* block I/O */
  (void) memset(((void *) &motor28335_2_B), 0,
                sizeof(BlockIO_motor28335_2));

  /* states (dwork) */
  (void) memset((void *)&motor28335_2_DWork, 0,
                sizeof(D_Work_motor28335_2));

  /* Start for S-Function (c280xadc): '<S3>/ADC1' */
  InitAdc();
  config_ADC_A (2U, 1808U, 0U, 0U, 0U);

  /* Start for S-Function (c280xqep): '<S3>/eQEP' */
  config_QEP_eQEP1(65535U, 0, 0, 0, 0, 0, 8, 32768, 119, 0);

  /* Start for S-Function (c280xpwm): '<Root>/ePWM' */

  /*** Initialize ePWM1 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 4097;

    /* // Time-Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm1Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm1Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm1Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm1Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FB7) | 0x32;

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm1Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;  // Compare A block operating mode. Always enable shadow mode, no immediate mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;  // Compare b block operating mode. Always enable shadow mode, no immediate mode
       EPwm1Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm1Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm1Regs.CMPA.half.CMPA = 0;
    EPwm1Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 36;
    EPwm1Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm1Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x3F) | 0x3;
    EPwm1Regs.DBRED = 15;
    EPwm1Regs.DBFED = 15;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN      = 0;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL     = 1;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD      = 1;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<Root>/ePWM1' */

  /*** Initialize ePWM2 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 4097;

    /* // Time-Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm2Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm2Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm2Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm2Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FB7) | 0x32;

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm2Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;  // Compare A block operating mode. Always enable shadow mode, no immediate mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;  // Compare b block operating mode. Always enable shadow mode, no immediate mode
       EPwm2Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm2Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm2Regs.CMPA.half.CMPA = 0;
    EPwm2Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 36;
    EPwm2Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm2Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0x3;
    EPwm2Regs.DBRED = 15;
    EPwm2Regs.DBFED = 15;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL     = 1;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD      = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<Root>/ePWM2' */

  /*** Initialize ePWM3 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 4097;

    /* // Time-Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm3Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm3Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm3Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm3Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FB7) | 0x32;

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm3Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;  // Compare A block operating mode. Always enable shadow mode, no immediate mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;  // Compare b block operating mode. Always enable shadow mode, no immediate mode
       EPwm3Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm3Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm3Regs.CMPA.half.CMPA = 0;
    EPwm3Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 36;
    EPwm3Regs.AQCTLB.all = 264;

    /* // Action-Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm3Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x3F) | 0x3;
    EPwm3Regs.DBRED = 15;
    EPwm3Regs.DBFED = 15;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm3Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM3SOCA Period Select
       EPwm3Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm3Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSEL.bit.INTEN      = 0;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSEL     = 1;          // EPWM3INTn Select
       EPwm3Regs.ETPS.bit.INTPRD      = 1;          // EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM3B
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<S21>/ePWM' */

  /*** Initialize ePWM4 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 37500;

    /* // Time-Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm4Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm4Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm4Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm4Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FB7) | 0x32;

    /* // Time-Base Phase Register
       EPwm4Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm4Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;  // Compare A block operating mode. Always enable shadow mode, no immediate mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;  // Compare b block operating mode. Always enable shadow mode, no immediate mode
       EPwm4Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm4Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm4Regs.CMPA.half.CMPA = 0;
    EPwm4Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 36;
    EPwm4Regs.AQCTLB.all = 516;

    /* // Action-Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm4Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x3F) | 0x3;
    EPwm4Regs.DBRED = 15;
    EPwm4Regs.DBFED = 15;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm4Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM4SOCA Period Select
       EPwm4Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm4Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM4SOCB Period Select
       EPwm4Regs.ETSEL.bit.INTEN      = 0;          // EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSEL     = 1;          // EPWM4INTn Select
       EPwm4Regs.ETPS.bit.INTPRD      = 1;          // EPWM4INTn Period Select
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM4B
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xpwm): '<S21>/ePWM1' */

  /*** Initialize ePWM5 modules ***/
  {
    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm5Regs.TBPRD = 37500;

    /* // Time-Base Control Register
       EPwm5Regs.TBCTL.bit.CTRMODE    = 2;          // Counter Mode
       EPwm5Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
       EPwm5Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
       EPwm5Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
       EPwm5Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
       EPwm5Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
     */
    EPwm5Regs.TBCTL.all = (EPwm5Regs.TBCTL.all & ~0x3FB7) | 0x32;

    /* // Time-Base Phase Register
       EPwm5Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
     */
    EPwm5Regs.TBPHS.all = (EPwm5Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
    EPwm5Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /* // Counter-Compare Control Register
       EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;  // Compare A block operating mode. Always enable shadow mode, no immediate mode
       EPwm5Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;  // Compare b block operating mode. Always enable shadow mode, no immediate mode
       EPwm5Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
       EPwm5Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
     */
    EPwm5Regs.CMPCTL.all = (EPwm5Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm5Regs.CMPA.half.CMPA = 0;
    EPwm5Regs.CMPB = 0;

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm5Regs.AQCTLA.all = 36;
    EPwm5Regs.AQCTLB.all = 516;

    /* // Action-Qualifier Software Force Register
       EPwm5Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
     */
    EPwm5Regs.AQSFRC.all = (EPwm5Regs.AQSFRC.all & ~0xC0) | 0x0;

    /* // Action-Qualifier Continuous S/W Force Register Set
       EPwm5Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
       EPwm5Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
     */
    EPwm5Regs.AQCSFRC.all = (EPwm5Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /* // Dead-Band Generator Control Register
       EPwm5Regs.DBCTL.bit.OUT_MODE   = 3;          // Dead Band Output Mode Control
       EPwm5Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
       EPwm5Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
     */
    EPwm5Regs.DBCTL.all = (EPwm5Regs.DBCTL.all & ~0x3F) | 0x3;
    EPwm5Regs.DBRED = 15;
    EPwm5Regs.DBFED = 15;

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
       EPwm5Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
       EPwm5Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
       EPwm5Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM5SOCA Period Select
       EPwm5Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
       EPwm5Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
       EPwm5Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM5SOCB Period Select
       EPwm5Regs.ETSEL.bit.INTEN      = 0;          // EPWM5INTn Enable
       EPwm5Regs.ETSEL.bit.INTSEL     = 1;          // EPWM5INTn Select
       EPwm5Regs.ETPS.bit.INTPRD      = 1;          // EPWM5INTn Period Select
     */
    EPwm5Regs.ETSEL.all = (EPwm5Regs.ETSEL.all & ~0xFF0F) | 0x1101;
    EPwm5Regs.ETPS.all = (EPwm5Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /* // PWM-Chopper Control Register
       EPwm5Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
       EPwm5Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
       EPwm5Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
       EPwm5Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
     */
    EPwm5Regs.PCCTL.all = (EPwm5Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm5Regs.TZSEL.all = 0;

    /* // Trip-Zone Control Register
       EPwm5Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM5A
       EPwm5Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM5B
     */
    EPwm5Regs.TZCTL.all = (EPwm5Regs.TZCTL.all & ~0xF) | 0xF;

    /* // Trip-Zone Enable Interrupt Register
       EPwm5Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
       EPwm5Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
     */
    EPwm5Regs.TZEINT.all = (EPwm5Regs.TZEINT.all & ~0x6) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<S22>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 4294967292U;
  GpioCtrlRegs.GPBDIR.all |= 1U;
  EDIS;

  /* S-Function Block: <S22>/CAPCONA (memorycopy) */
  {
    {
      uint16_T *meminddst = (uint16_T *) (29728U);
      *(uint16_T *) (meminddst) = (uint16_T) (4100);
    }
  }

  /* S-Function Block: <S22>/CAPFIFOA (memorycopy) */
  {
    {
      uint16_T *meminddst = (uint16_T *) (29730U);
      *(uint16_T *) (meminddst) = (uint16_T) (4096);
    }
  }

  /* S-Function Block: <S22>/CAPCONA (memorycopy) */
  {
    uint16_T *memindsrc = (uint16_T *) (&motor28335_2_ConstP.Constant_Value_o);
    uint16_T *meminddst = (uint16_T *) (29728U);
    *(uint16_T *) (meminddst) = *(uint16_T *) (memindsrc);
  }

  /* S-Function Block: <S22>/CAPFIFOA (memorycopy) */
  {
    uint16_T *memindsrc = (uint16_T *) (&motor28335_2_ConstP.Constant2_Value_i);
    uint16_T *meminddst = (uint16_T *) (29730U);
    *(uint16_T *) (meminddst) = *(uint16_T *) (memindsrc);
  }
}

/* Model terminate function */
void motor28335_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
