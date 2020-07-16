/*
 * File: motor28335_2.h
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

#ifndef RTW_HEADER_motor28335_2_h_
#define RTW_HEADER_motor28335_2_h_
#ifndef motor28335_2_COMMON_INCLUDES_
# define motor28335_2_COMMON_INCLUDES_
#include <IQmathLib.h>
#include <string.h>
#include "rtwtypes.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#include "DSP2833x_Gpio.h"
#endif                                 /* motor28335_2_COMMON_INCLUDES_ */

#include "motor28335_2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  int32_T DataTypeConversion[3];       /* '<S4>/Data Type Conversion' */
  int32_T RampControl_o2;              /* '<S26>/Ramp Control' */
  int32_T RampControl_o1;              /* '<S26>/Ramp Control' */
  int32_T Saturation;                  /* '<S35>/Saturation' */
  uint16_T ADC1[3];                    /* '<S3>/ADC1' */
  uint16_T eQEP;                       /* '<S3>/eQEP' */
  uint16_T Saturation_d;               /* '<S22>/Saturation' */
  uint16_T CAP1FBOT;                   /* '<S27>/CAP1FBOT' */
  uint16_T ShiftArithmetic;            /* '<S22>/Shift Arithmetic' */
} BlockIO_motor28335_2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T UnitDelay_DSTATE[2];         /* '<S16>/Unit Delay' */
  int32_T UnitDelay_DSTATE_m;          /* '<S29>/Unit Delay' */
  int32_T UnitDelay2_DSTATE;           /* '<S14>/Unit Delay2' */
  int32_T UnitDelay3_DSTATE;           /* '<S14>/Unit Delay3' */
  int32_T UnitDelay4_DSTATE;           /* '<S14>/Unit Delay4' */
  int32_T UnitDelay_DSTATE_mm;         /* '<S23>/Unit Delay' */
  int32_T UnitDelay2_DSTATE_o;         /* '<S35>/Unit Delay2' */
  int32_T UnitDelay3_DSTATE_o;         /* '<S35>/Unit Delay3' */
  int32_T UnitDelay4_DSTATE_o;         /* '<S35>/Unit Delay4' */
  int32_T UnitDelay2_DSTATE_ot;        /* '<S15>/Unit Delay2' */
  int32_T UnitDelay3_DSTATE_i;         /* '<S15>/Unit Delay3' */
  int32_T UnitDelay4_DSTATE_c;         /* '<S15>/Unit Delay4' */
  int32_T RampControl_RAMP_DLY_CNTL;   /* '<S26>/Ramp Control' */
  int32_T RampControl_PREV_SETPOINT;   /* '<S26>/Ramp Control' */
  int32_T Add_DWORK1;                  /* '<S23>/Add' */
  uint16_T UnitDelay2_DSTATE_b;        /* '<S22>/Unit Delay2' */
  uint16_T UnitDelay1_DSTATE;          /* '<S22>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE_f;         /* '<S28>/Unit Delay' */
} D_Work_motor28335_2;

/* Invariant block signals (auto storage) */
typedef struct {
  const int32_T Add;                   /* '<S23>/Add' */
} ConstBlockIO_motor28335_2;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S22>/Constant'
   */
  uint16_T Constant_Value_o;

  /* Computed Parameter: Constant2_Value_i
   * Referenced by: '<S22>/Constant2'
   */
  uint16_T Constant2_Value_i;
} ConstParam_motor28335_2;

/* Real-time Model Data Structure */
struct tag_RTM_motor28335_2 {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern BlockIO_motor28335_2 motor28335_2_B;

/* Block states (auto storage) */
extern D_Work_motor28335_2 motor28335_2_DWork;
extern const ConstBlockIO_motor28335_2 motor28335_2_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstParam_motor28335_2 motor28335_2_ConstP;

/* External function called from main */
extern void motor28335_2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void motor28335_2_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void motor28335_2_initialize(void);
extern void motor28335_2_step(int_T tid);
extern void motor28335_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor28335_2 *const motor28335_2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'motor28335_2'
 * '<S1>'   : 'motor28335_2/F2812 eZdsp'
 * '<S2>'   : 'motor28335_2/Generating Space Vectors'
 * '<S3>'   : 'motor28335_2/Inputs'
 * '<S4>'   : 'motor28335_2/Scaling'
 * '<S5>'   : 'motor28335_2/speed controller'
 * '<S6>'   : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors'
 * '<S7>'   : 'motor28335_2/Generating Space Vectors/PWM scaling'
 * '<S8>'   : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/Clarke Transformation'
 * '<S9>'   : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/Inverse Park Transformation'
 * '<S10>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/Park Transformation'
 * '<S11>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control'
 * '<S12>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/Clarke Transformation/Convert Param To fix-pt with floor  rounding mode'
 * '<S13>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/Clarke Transformation/Convert Param To fix-pt with floor  rounding mode/Embedded MATLAB Function'
 * '<S14>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/PID Controller'
 * '<S15>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/PID Controller1'
 * '<S16>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/saturation'
 * '<S17>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/PID Controller/UD_REG3'
 * '<S18>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/PID Controller/UI_REG3'
 * '<S19>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/PID Controller1/UD_REG3'
 * '<S20>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/PID Controller1/UI_REG3'
 * '<S21>'  : 'motor28335_2/Generating Space Vectors/Generating Raw Space Vectors/control/saturation/analog outputs'
 * '<S22>'  : 'motor28335_2/Scaling/CAP3INT'
 * '<S23>'  : 'motor28335_2/Scaling/IIR filter'
 * '<S24>'  : 'motor28335_2/Scaling/Subsystem'
 * '<S25>'  : 'motor28335_2/Scaling/multiply by -1'
 * '<S26>'  : 'motor28335_2/Scaling/startup_ramp'
 * '<S27>'  : 'motor28335_2/Scaling/CAP3INT/Subsystem'
 * '<S28>'  : 'motor28335_2/Scaling/Subsystem/speed_calculator'
 * '<S29>'  : 'motor28335_2/Scaling/startup_ramp/Ramp Generator'
 * '<S30>'  : 'motor28335_2/Scaling/startup_ramp/Ramp Generator/Convert Param To fix-pt with floor  rounding mode'
 * '<S31>'  : 'motor28335_2/Scaling/startup_ramp/Ramp Generator/Subsystem'
 * '<S32>'  : 'motor28335_2/Scaling/startup_ramp/Ramp Generator/Subsystem1'
 * '<S33>'  : 'motor28335_2/Scaling/startup_ramp/Ramp Generator/Convert Param To fix-pt with floor  rounding mode/Embedded MATLAB Function'
 * '<S34>'  : 'motor28335_2/Scaling/startup_ramp/Ramp Generator/Subsystem/Data Type Conversion Inherited'
 * '<S35>'  : 'motor28335_2/speed controller/PID Controller'
 * '<S36>'  : 'motor28335_2/speed controller/PID Controller/UD_REG3'
 * '<S37>'  : 'motor28335_2/speed controller/PID Controller/UI_REG3'
 */
#endif                                 /* RTW_HEADER_motor28335_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
