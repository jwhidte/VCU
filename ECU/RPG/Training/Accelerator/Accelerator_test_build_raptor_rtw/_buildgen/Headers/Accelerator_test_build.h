/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator_test_build.h
 *
 * Code generated for Simulink model 'Accelerator_test_build'.
 *
 * Model version                  : 8.76
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 15 22:06:38 2024
 *
 * Target selection: raptor.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Accelerator_test_build_h_
#define RTW_HEADER_Accelerator_test_build_h_
#ifndef Accelerator_test_build_COMMON_INCLUDES_
#define Accelerator_test_build_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "data.h"
#include "sws_dio.h"
#include "gnu_pragma_conf.h"
#include "memlay_pub.h"
#include "syc_postdrv_pub.h"
#include "sws_pwmout.h"
#include "swadp_pub.h"
#include "sws_adc.h"
#include "mocadc_msg.h"
#include "xcp_protocol.h"
#include "can_CAN1.h"
#include "can_CAN2.h"
#include "faultmanager.h"
#endif                             /* Accelerator_test_build_COMMON_INCLUDES_ */

#include "Accelerator_test_build_types.h"
#include "rtGetInf.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Block signals for system '<S8>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S8>/MATLAB Function' */
} rtB_MATLABFunction_Accelerator_test_build;

/* Block signals (default storage) */
typedef struct {
  real_T u1;                           /* '<S8>/raptor_override1' */
  real_T u1_c;                         /* '<S9>/raptor_override1' */
  uint16_T raptor_table_axis;          /* '<S10>/raptor_table_axis' */
  uint16_T u1_b;                       /* '<S8>/raptor_override' */
  uint16_T u1_l;                       /* '<S9>/raptor_override' */
  rtB_MATLABFunction_Accelerator_test_build sf_MATLABFunction_i;/* '<S9>/MATLAB Function' */
  rtB_MATLABFunction_Accelerator_test_build sf_MATLABFunction;/* '<S8>/MATLAB Function' */
} BlockIO_Accelerator_test_build;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S16>/Unit Delay' */
  uint32_T raptor_delta_time_DWORK1;   /* '<S16>/raptor_delta_time' */
  boolean_T DelayInput1_DSTATE;        /* '<S20>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S16>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S15>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S15>/Unit Delay1' */
  int8_T If_ActiveSubsystem;           /* '<S2>/If' */
} D_Work_Accelerator_test_build;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StoreEEPROM_Trig_ZCE;     /* '<S15>/Store EEPROM' */
  ZCSigState RaiseStartupEvent_Trig_ZCE;/* '<S15>/Raise Startup Event' */
  ZCSigState RaiseShutdownEvent_Trig_ZCE;/* '<S15>/Raise Shutdown Event' */
} PrevZCSigStates_Accelerator_test_build;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S16>/Logic'
   */
  boolean_T Logic_table[8];
} ConstParam_Accelerator_test_build;

/* Block signals (default storage) */
extern BlockIO_Accelerator_test_build Accelerator_test_build_B;

/* Block states (default storage) */
extern D_Work_Accelerator_test_build Accelerator_test_build_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_Accelerator_test_build
  Accelerator_test_build_PrevZCSigState;

/* Constant parameters (default storage) */
extern const ConstParam_Accelerator_test_build Accelerator_test_build_ConstP;

/* Model entry point functions */
extern void Accelerator_test_build_initialize(void);
extern void Accelerator_test_build_step(void);
extern void Accelerator_test_build_terminate(void);

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
 * '<Root>' : 'Accelerator_test_build'
 * '<S1>'   : 'Accelerator_test_build/Foreground'
 * '<S2>'   : 'Accelerator_test_build/Function-Call Subsystem'
 * '<S3>'   : 'Accelerator_test_build/Power Up_Down'
 * '<S4>'   : 'Accelerator_test_build/raptor_xcp_def'
 * '<S5>'   : 'Accelerator_test_build/Foreground/Calculate Torque'
 * '<S6>'   : 'Accelerator_test_build/Foreground/Command Troque'
 * '<S7>'   : 'Accelerator_test_build/Foreground/MATLAB Function1'
 * '<S8>'   : 'Accelerator_test_build/Foreground/POT1'
 * '<S9>'   : 'Accelerator_test_build/Foreground/POT2'
 * '<S10>'  : 'Accelerator_test_build/Foreground/Calculate Torque/raptor_table_1d'
 * '<S11>'  : 'Accelerator_test_build/Foreground/POT1/MATLAB Function'
 * '<S12>'  : 'Accelerator_test_build/Foreground/POT2/MATLAB Function'
 * '<S13>'  : 'Accelerator_test_build/Function-Call Subsystem/Compare To Constant'
 * '<S14>'  : 'Accelerator_test_build/Function-Call Subsystem/If Action Subsystem'
 * '<S15>'  : 'Accelerator_test_build/Power Up_Down/Background'
 * '<S16>'  : 'Accelerator_test_build/Power Up_Down/Background/Debounce'
 * '<S17>'  : 'Accelerator_test_build/Power Up_Down/Background/Raise Shutdown Event'
 * '<S18>'  : 'Accelerator_test_build/Power Up_Down/Background/Raise Startup Event'
 * '<S19>'  : 'Accelerator_test_build/Power Up_Down/Background/Store EEPROM'
 * '<S20>'  : 'Accelerator_test_build/Power Up_Down/Background/Debounce/Detect Change'
 * '<S21>'  : 'Accelerator_test_build/Power Up_Down/Background/Raise Shutdown Event/raptor_shutdown'
 * '<S22>'  : 'Accelerator_test_build/Power Up_Down/Background/Raise Startup Event/raptor_startup'
 * '<S23>'  : 'Accelerator_test_build/Power Up_Down/Background/Store EEPROM/raptor_store_nv'
 */
#endif                                /* RTW_HEADER_Accelerator_test_build_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
