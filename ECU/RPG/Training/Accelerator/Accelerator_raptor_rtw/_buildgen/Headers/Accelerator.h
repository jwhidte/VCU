/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator.h
 *
 * Code generated for Simulink model 'Accelerator'.
 *
 * Model version                  : 8.123
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May  9 15:17:16 2024
 *
 * Target selection: raptor.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Accelerator_h_
#define RTW_HEADER_Accelerator_h_
#ifndef Accelerator_COMMON_INCLUDES_
#define Accelerator_COMMON_INCLUDES_
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
#include "sws_pwmin.h"
#include "xcp_protocol.h"
#include "can_CAN1.h"
#include "can_CAN2.h"
#include "faultmanager.h"
#endif                                 /* Accelerator_COMMON_INCLUDES_ */

#include "Accelerator_types.h"
#include "rtGetInf.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Block signals for system '<S17>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S17>/MATLAB Function' */
} rtB_MATLABFunction_Accelerator;

/* Block signals (default storage) */
typedef struct {
  real_T raptor_override8;             /* '<S1>/raptor_override8' */
  real_T raptor_override9;             /* '<S1>/raptor_override9' */
  real_T raptor_override18;            /* '<S1>/raptor_override18' */
  real_T raptor_override17;            /* '<S1>/raptor_override17' */
  real_T raptor_override15;            /* '<S1>/raptor_override15' */
  real_T raptor_override1;             /* '<S6>/raptor_override1' */
  real_T u1;                           /* '<S17>/raptor_override1' */
  real_T u1_c;                         /* '<S18>/raptor_override1' */
  real_T raptor_override3;             /* '<S1>/raptor_override3' */
  real_T raptor_override16;            /* '<S1>/raptor_override16' */
  real_T raptor_override;              /* '<S6>/raptor_override' */
  real_T raptor_override13;            /* '<S1>/raptor_override13' */
  uint32_T raptor_override19;          /* '<S1>/raptor_override19' */
  uint32_T raptor_override20;          /* '<S1>/raptor_override20' */
  uint16_T raptor_table_axis;          /* '<S20>/raptor_table_axis' */
  uint16_T raptor_override4;           /* '<S1>/raptor_override4' */
  uint16_T u1_n;                       /* '<S17>/raptor_override' */
  uint16_T u1_l;                       /* '<S18>/raptor_override' */
  uint16_T raptor_override1_p;         /* '<S1>/raptor_override1' */
  uint16_T raptor_override22;          /* '<S1>/raptor_override22' */
  uint16_T raptor_override12;          /* '<S1>/raptor_override12' */
  uint16_T raptor_override21;          /* '<S1>/raptor_override21' */
  uint16_T raptor_override7;           /* '<S1>/raptor_override7' */
  boolean_T raptor_override_b;         /* '<S1>/raptor_override' */
  boolean_T raptor_override10;         /* '<S1>/raptor_override10' */
  boolean_T D;                         /* '<S21>/D' */
  boolean_T Logic;                     /* '<S21>/Logic' */
  boolean_T u1_d;                      /* '<S17>/raptor_override2' */
  boolean_T u1_g;                      /* '<S17>/raptor_override3' */
  boolean_T u1_a;                      /* '<S18>/raptor_override2' */
  boolean_T u1_p;                      /* '<S18>/raptor_override3' */
  boolean_T raptor_override11;         /* '<S1>/raptor_override11' */
  boolean_T raptor_override5;          /* '<S1>/raptor_override5' */
  boolean_T raptor_override6;          /* '<S1>/raptor_override6' */
  boolean_T raptor_override14;         /* '<S1>/raptor_override14' */
  boolean_T raptor_override2;          /* '<S6>/raptor_override2' */
  boolean_T raptor_override2_b;        /* '<S1>/raptor_override2' */
  boolean_T raptor_override24;         /* '<S1>/raptor_override24' */
  boolean_T raptor_override23;         /* '<S1>/raptor_override23' */
  rtB_MATLABFunction_Accelerator sf_MATLABFunction_i;/* '<S18>/MATLAB Function' */
  rtB_MATLABFunction_Accelerator sf_MATLABFunction_m;/* '<S17>/MATLAB Function' */
} BlockIO_Accelerator;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S12>/UD' */
  real_T Delay_DSTATE[1000];           /* '<S1>/Delay' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S19>/Unit Delay1' */
  real_T UnitDelay_DSTATE_l;           /* '<S19>/Unit Delay' */
  real_T UnitDelay_DSTATE_b;           /* '<S30>/Unit Delay' */
  uint32_T UD_DSTATE_p;                /* '<S13>/UD' */
  uint32_T raptor_delta_time_DWORK1;   /* '<S30>/raptor_delta_time' */
  uint8_T DelayInput1_DSTATE;          /* '<S24>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S34>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S30>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S29>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_f;       /* '<S29>/Unit Delay1' */
  int8_T If_ActiveSubsystem;           /* '<S2>/If' */
} D_Work_Accelerator;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StoreEEPROM_Trig_ZCE;     /* '<S29>/Store EEPROM' */
  ZCSigState RaiseStartupEvent_Trig_ZCE;/* '<S29>/Raise Startup Event' */
  ZCSigState RaiseShutdownEvent_Trig_ZCE;/* '<S29>/Raise Shutdown Event' */
} PrevZCSigStates_Accelerator;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [100;93.75;87.5;81.25;75;68.75;62.5;56.25;50;43.75;37.5;31.25;25;18.75;12.5;6.25;0]
   * Referenced by: '<S1>/I: 0-80W O: DC'
   */
  real_T I080WODC_tableData[17];

  /* Expression: [0;5;10;15;20;25;30;35;40;45;50;55;60;65;70;75;80]
   * Referenced by: '<S1>/I: 0-80W O: DC'
   */
  real_T I080WODC_bp01Data[17];

  /* Expression: [0;0;80;80]
   * Referenced by: '<S1>/Constant5'
   */
  real_T Constant5_Value[4];

  /* Expression: [120;115;110;105;100;95;90;85;80;75;70;65;60;55;50;45;40;35;30;25;20;15;10;5;0]
   * Referenced by: '<S1>/I: R (kOhm) O: T (C)'
   */
  real_T IRkOhmOTC_tableData[25];

  /* Expression: [0.583;0.6601;0.7487;0.8508;0.9688;1.106;1.265;1.452;1.67;1.928;2.232;2.593;3.025;3.541;4.163;4.914;5.827;6.942;8.311;10;12.1;14.71;17.99;22.13;27.39]
   * Referenced by: '<S1>/I: R (kOhm) O: T (C)'
   */
  real_T IRkOhmOTC_bp01Data[25];

  /* Expression: [120;240;360;480;600;720]
   * Referenced by: '<S1>/Q (L//H) vs. F (Hz)'
   */
  real_T QLHvsFHz_tableData[6];

  /* Computed Parameter: QLHvsFHz_bp01Data
   * Referenced by: '<S1>/Q (L//H) vs. F (Hz)'
   */
  uint32_T QLHvsFHz_bp01Data[6];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S30>/Logic'
   */
  boolean_T Logic_table[8];
} ConstParam_Accelerator;

/* Block signals (default storage) */
extern BlockIO_Accelerator Accelerator_B;

/* Block states (default storage) */
extern D_Work_Accelerator Accelerator_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_Accelerator Accelerator_PrevZCSigState;

/* Constant parameters (default storage) */
extern const ConstParam_Accelerator Accelerator_ConstP;

/* Model entry point functions */
extern void Accelerator_initialize(void);
extern void Accelerator_step(void);
extern void Accelerator_terminate(void);

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
 * '<Root>' : 'Accelerator'
 * '<S1>'   : 'Accelerator/Foreground'
 * '<S2>'   : 'Accelerator/Function-Call Subsystem'
 * '<S3>'   : 'Accelerator/Power Up_Down'
 * '<S4>'   : 'Accelerator/raptor_xcp_def'
 * '<S5>'   : 'Accelerator/Foreground/Calculate Torque'
 * '<S6>'   : 'Accelerator/Foreground/Command Troque'
 * '<S7>'   : 'Accelerator/Foreground/Compare To Constant'
 * '<S8>'   : 'Accelerator/Foreground/Compare To Constant1'
 * '<S9>'   : 'Accelerator/Foreground/Compare To Constant2'
 * '<S10>'  : 'Accelerator/Foreground/Compare To Constant3'
 * '<S11>'  : 'Accelerator/Foreground/D Latch'
 * '<S12>'  : 'Accelerator/Foreground/Difference'
 * '<S13>'  : 'Accelerator/Foreground/Difference1'
 * '<S14>'  : 'Accelerator/Foreground/MATLAB Function'
 * '<S15>'  : 'Accelerator/Foreground/MATLAB Function1'
 * '<S16>'  : 'Accelerator/Foreground/MATLAB Function2'
 * '<S17>'  : 'Accelerator/Foreground/POT1'
 * '<S18>'  : 'Accelerator/Foreground/POT2'
 * '<S19>'  : 'Accelerator/Foreground/Triggered Single Pulse'
 * '<S20>'  : 'Accelerator/Foreground/Calculate Torque/raptor_table_1d'
 * '<S21>'  : 'Accelerator/Foreground/D Latch/D Latch'
 * '<S22>'  : 'Accelerator/Foreground/POT1/MATLAB Function'
 * '<S23>'  : 'Accelerator/Foreground/POT2/MATLAB Function'
 * '<S24>'  : 'Accelerator/Foreground/Triggered Single Pulse/+ve edge detect'
 * '<S25>'  : 'Accelerator/Foreground/Triggered Single Pulse/Compare To Constant'
 * '<S26>'  : 'Accelerator/Foreground/Triggered Single Pulse/+ve edge detect/Positive'
 * '<S27>'  : 'Accelerator/Function-Call Subsystem/Compare To Constant'
 * '<S28>'  : 'Accelerator/Function-Call Subsystem/If Action Subsystem'
 * '<S29>'  : 'Accelerator/Power Up_Down/Background'
 * '<S30>'  : 'Accelerator/Power Up_Down/Background/Debounce'
 * '<S31>'  : 'Accelerator/Power Up_Down/Background/Raise Shutdown Event'
 * '<S32>'  : 'Accelerator/Power Up_Down/Background/Raise Startup Event'
 * '<S33>'  : 'Accelerator/Power Up_Down/Background/Store EEPROM'
 * '<S34>'  : 'Accelerator/Power Up_Down/Background/Debounce/Detect Change'
 * '<S35>'  : 'Accelerator/Power Up_Down/Background/Raise Shutdown Event/raptor_shutdown'
 * '<S36>'  : 'Accelerator/Power Up_Down/Background/Raise Startup Event/raptor_startup'
 * '<S37>'  : 'Accelerator/Power Up_Down/Background/Store EEPROM/raptor_store_nv'
 */
#endif                                 /* RTW_HEADER_Accelerator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
