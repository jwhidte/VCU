/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Training_private.h
 *
 * Code generated for Simulink model 'Training'.
 *
 * Model version                  : 8.9
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jan 30 16:09:40 2023
 *
 * Target selection: raptor.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Training_private_h_
#define RTW_HEADER_Training_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Training.h"
#include "Training_types.h"

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

extern uint32_T GetDeltaTime_us(uint32_T*);
extern uint32_T GetDeltaTime_ms(uint32_T*);
extern void UpdateAbsTime(void);
extern real32_T GetAbsTime(void);
extern void Timer_ooqlV(void);
extern void Timer_BGND_G6Wyo(void);
extern void Timed_Trigger_XCP(void);
extern void RxTrig_XCP_BC_CAN1(void);
extern void RxTrig_XCP_CMD_CAN1(void);
extern void CAN1_XCP_CAN_PreStart(uint32_T, uint32_T, uint32_T);
extern void can_process_rx_queue_CAN1(void);
extern void Training_MATLABFunction(const real_T rtu_u[3],
  rtB_MATLABFunction_Training *localB);
extern void Training_Background_Init(void);
extern void Training_Background_Reset(void);
extern void Training_Background(void);
extern void Training_Foreground_Init(void);
extern void Training_Foreground_Reset(void);
extern void Training_Foreground(void);

#endif                                 /* RTW_HEADER_Training_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
