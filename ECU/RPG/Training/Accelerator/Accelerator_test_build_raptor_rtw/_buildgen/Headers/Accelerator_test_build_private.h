/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator_test_build_private.h
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

#ifndef RTW_HEADER_Accelerator_test_build_private_h_
#define RTW_HEADER_Accelerator_test_build_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Accelerator_test_build.h"
#include "Accelerator_test_build_types.h"

extern uint16_T crc16_spd(void* in, uint32_T length, uint16_T prevCRC);
boolean_T is_crc_valid(void * buffer, uint32_T buffer_size, uint16_T checkCrc);
extern char *__NE_CODE0_START __attribute__ ((asection (".asw0_prolog","f=aw")));

#define CODESTART0                     ((char*)&__NE_CODE0_START)

extern char *__NE_CODE0_END __attribute__ ((asection (".asw0_free","f=aw")));

#define CODEEND0                       ((char*)&__NE_CODE0_END)

extern char *__NE_CODE1_START __attribute__ ((asection (".asw0_epilog","f=aw")));

#define CODESTART1                     ((char*)&__NE_CODE1_START)

extern char *__NE_CODE1_END __attribute__ ((asection (".asw0_epilog","f=aw")));

#define CODEEND1                       ((char*)&__NE_CODE1_END)

extern uint16_T TableAxis_real32_T(const real32_T invalue, const real32_T * data,
  const uint32_T width, const uint16_T prev);
extern real32_T TableInterpolate1D_real32_T( const uint16_T idx, const real32_T *
  data, const uint16_T width);
extern uint32_T GetDeltaTime_us(uint32_T*);
extern uint32_T GetDeltaTime_ms(uint32_T*);
extern void UpdateAbsTime(void);
extern real32_T GetAbsTime(void);
extern void Timer_ooqlV(void);
extern void AppTrigger_FGND_sMxs9(void);
extern void Timer_BGND_G6Wyo(void);
extern void Timed_Trigger_XCP(void);
extern void RxTrig_XCP_BC_CAN1(void);
extern void RxTrig_XCP_CMD_CAN1(void);
extern void CAN1_XCP_CAN_PreStart(uint32_T, uint32_T, uint32_T);
extern void can_process_rx_queue_CAN1(void);
extern void Accelerator_test_build_MATLABFunction(real_T rtu_a, real_T rtu_b,
  real_T rtu_c, rtB_MATLABFunction_Accelerator_test_build *localB);
extern void Accelerator_test_build_Background_Init(void);
extern void Accelerator_test_build_Background_Reset(void);
extern void Accelerator_test_build_Background(void);
extern void Accelerator_test_build_FunctionCallSubsystem_Init(void);
extern void Accelerator_test_build_FunctionCallSubsystem_Enable(void);
extern void Accelerator_test_build_FunctionCallSubsystem_Disable(void);
extern void Accelerator_test_build_FunctionCallSubsystem(void);
extern void Accelerator_test_build_Foreground_Init(void);
extern void Accelerator_test_build_Foreground_Enable(void);
extern void Accelerator_test_build_Foreground_Disable(void);
extern void Accelerator_test_build_Foreground(void);

#endif                        /* RTW_HEADER_Accelerator_test_build_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
