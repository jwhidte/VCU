/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator_private.h
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

#ifndef RTW_HEADER_Accelerator_private_h_
#define RTW_HEADER_Accelerator_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Accelerator.h"
#include "Accelerator_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

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
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi);
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi);
extern void CAN1_XCP_CAN_PreStart(uint32_T, uint32_T, uint32_T);
extern void can_process_rx_queue_CAN1(void);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look1_iu32td_binlcpw(uint32_T u0, const uint32_T bp0[], const
  real_T table[], uint32_T maxIndex);
extern void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_u32_hiSR_near(uint32_T a, uint32_T b, uint32_T aShift);
extern void Accelerator_MATLABFunction(real_T rtu_a, real_T rtu_b, real_T rtu_c,
  rtB_MATLABFunction_Accelerator *localB);
extern void Accelerator_Background_Init(void);
extern void Accelerator_Background_Reset(void);
extern void Accelerator_Background(void);
extern void Accelerator_FunctionCallSubsystem_Init(void);
extern void Accelerator_FunctionCallSubsystem_Enable(void);
extern void Accelerator_FunctionCallSubsystem_Disable(void);
extern void Accelerator_FunctionCallSubsystem(void);
extern void Accelerator_Foreground_Init(void);
extern void Accelerator_Foreground_Enable(void);
extern void Accelerator_Foreground_Disable(void);
extern void Accelerator_Foreground(void);

#endif                                 /* RTW_HEADER_Accelerator_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
