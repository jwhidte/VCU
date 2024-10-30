/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Training.h
 *
 * Code generated for Simulink model 'Training'.
 *
 * Model version                  : 8.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jan 17 17:54:55 2023
 *
 * Target selection: raptor.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Training_h_
#define RTW_HEADER_Training_h_
#ifndef Training_COMMON_INCLUDES_
#define Training_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "data.h"
#include "sws_dio.h"
#include "gnu_pragma_conf.h"
#include "memlay_pub.h"
#include "syc_postdrv_pub.h"
#include "sws_pwmout.h"
#include "swadp_pub.h"
#include "xcp_protocol.h"
#include "can_CAN1.h"
#endif                                 /* Training_COMMON_INCLUDES_ */

#include "Training_types.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S5>/Unit Delay' */
  uint32_T raptor_delta_time_DWORK1;   /* '<S1>/raptor_delta_time' */
  uint32_T raptor_delta_time_DWORK1_d; /* '<S5>/raptor_delta_time' */
  boolean_T DelayInput1_DSTATE;        /* '<S9>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S5>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S4>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S4>/Unit Delay1' */
} D_Work_Training;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StoreEEPROM_Trig_ZCE;     /* '<S4>/Store EEPROM' */
  ZCSigState RaiseStartupEvent_Trig_ZCE;/* '<S4>/Raise Startup Event' */
  ZCSigState RaiseShutdownEvent_Trig_ZCE;/* '<S4>/Raise Shutdown Event' */
} PrevZCSigStates_Training;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S5>/Logic'
   */
  boolean_T Logic_table[8];
} ConstParam_Training;

/* Block states (default storage) */
extern D_Work_Training Training_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_Training Training_PrevZCSigState;

/* Constant parameters (default storage) */
extern const ConstParam_Training Training_ConstP;

/* Model entry point functions */
extern void Training_initialize(void);
extern void Training_step(void);
extern void Training_terminate(void);

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
 * '<Root>' : 'Training'
 * '<S1>'   : 'Training/Foreground'
 * '<S2>'   : 'Training/Power Up_Down'
 * '<S3>'   : 'Training/raptor_xcp_def'
 * '<S4>'   : 'Training/Power Up_Down/Background'
 * '<S5>'   : 'Training/Power Up_Down/Background/Debounce'
 * '<S6>'   : 'Training/Power Up_Down/Background/Raise Shutdown Event'
 * '<S7>'   : 'Training/Power Up_Down/Background/Raise Startup Event'
 * '<S8>'   : 'Training/Power Up_Down/Background/Store EEPROM'
 * '<S9>'   : 'Training/Power Up_Down/Background/Debounce/Detect Change'
 * '<S10>'  : 'Training/Power Up_Down/Background/Raise Shutdown Event/raptor_shutdown'
 * '<S11>'  : 'Training/Power Up_Down/Background/Raise Startup Event/raptor_startup'
 * '<S12>'  : 'Training/Power Up_Down/Background/Store EEPROM/raptor_store_nv'
 */
#endif                                 /* RTW_HEADER_Training_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
