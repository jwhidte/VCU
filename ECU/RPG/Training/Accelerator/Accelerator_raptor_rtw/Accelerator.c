/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator.c
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

#include "Accelerator.h"
#include "rtwtypes.h"
#include "Accelerator_private.h"
#include "math.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_Accelerator Accelerator_B;

/* Block states (default storage) */
D_Work_Accelerator Accelerator_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_Accelerator Accelerator_PrevZCSigState;

// Block : Accelerator/raptor_timed_trigger
void Timer_ooqlV(void)
{
  /* Timer_ooqlV  ------   Foreground  */
  {
    {
      Accelerator_Foreground();
    }
  }
}

// Block : Accelerator/raptor_app_trigger
#define START_SECTION_Task_oem_r1ms
#include "swsh_rb2oem.h"

void AppTrigger_FGND_sMxs9(void)
{
  /* AppTrigger_FGND_sMxs9  ------   Startup  */
  {
    {
      Accelerator_FunctionCallSubsystem();
    }
  }
}

#define STOP_SECTION_Task_oem_r1ms
#include "swsh_rb2oem.h"

// Block : Accelerator/Power Up_Down/raptor_timed_trigger
void Timer_BGND_G6Wyo(void)
{
  /* Timer_BGND_G6Wyo  ------   Background  */
  {
    {
      Accelerator_Background();
    }
  }
}

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup Utility LookUp_real_T_real_T */
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look1_iu32td_binlcpw(uint32_T u0, const uint32_T bp0[], const real_T
  table[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    bpIdx = bp0[iLeft];
    frac = (real_T)(u0 - bpIdx) / (real_T)(bp0[iLeft + 1U] - bpIdx);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T in1Lo;
  uint32_T outBitsLo;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << 16U) + in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_hiSR_near(uint32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  return (uint32_T)((1U << (aShift - 1U) & u32_chi) != 0U) + (u32_chi >> aShift);
}

/* System initialize for function-call system: '<S3>/Background' */
void Accelerator_Background_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_in): '<S29>/raptor_digital_in' */

  /* S-Function Block: WAKE_INPUT1 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S29>/raptor_digital_out' */

  /* S-Function Block: POWER_HOLD */
  {
  }

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S30>/raptor_delta_time' */
  Accelerator_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
  Accelerator_DWork.UnitDelay2_DSTATE = true;
}

/* System reset for function-call system: '<S3>/Background' */
void Accelerator_Background_Reset(void)
{
  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S30>/raptor_delta_time' */
  Accelerator_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
  Accelerator_DWork.UnitDelay2_DSTATE = true;
}

/* Output and update for function-call system: '<S3>/Background' */
void Accelerator_Background(void)
{
  /* local block i/o variables */
  real_T rtb_raptor_delta_time;
  boolean_T rtb_raptor_digital_in;
  real_T rtb_MultiportSwitch1;
  boolean_T rtb_Logic;
  boolean_T rtb_LogicalOperator1_h;
  boolean_T rtb_LogicalOperator2_c;
  boolean_T rtb_raptor_sfun_nv_status;

  /* S-Function (raptor_sfun_digital_in): '<S29>/raptor_digital_in' */
  /* S-Function Block: WAKE_INPUT1 */
  {
    rtb_raptor_digital_in = swsh_ignswSt();
  }

  /* S-Function (raptor_sfun_delta_time): '<S30>/raptor_delta_time' */
  {
    rtb_raptor_delta_time = (GetDeltaTime_ms
      (&Accelerator_DWork.raptor_delta_time_DWORK1) * 0.001f);
  }

  /* MultiPortSwitch: '<S30>/Multiport Switch1' incorporates:
   *  Constant: '<S30>/Constant'
   *  RelationalOperator: '<S34>/FixPt Relational Operator'
   *  Sum: '<S30>/Add'
   *  UnitDelay: '<S30>/Unit Delay'
   *  UnitDelay: '<S34>/Delay Input1'
   */
  if (rtb_raptor_digital_in == Accelerator_DWork.DelayInput1_DSTATE_c) {
    rtb_MultiportSwitch1 = rtb_raptor_delta_time +
      Accelerator_DWork.UnitDelay_DSTATE_b;
  } else {
    rtb_MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S30>/Multiport Switch1' */
  /* UnitDelay: '<S30>/Unit Delay2' */
  rtb_raptor_sfun_nv_status = Accelerator_DWork.UnitDelay2_DSTATE;

  /* CombinatorialLogic: '<S30>/Logic' incorporates:
   *  Logic: '<S30>/Logical Operator1'
   *  Logic: '<S30>/Logical Operator2'
   *  Logic: '<S30>/Logical Operator3'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  RelationalOperator: '<S30>/Relational Operator1'
   *  S-Function (raptor_sfun_adjustment): '<S30>/raptor_adjustment3'
   *  S-Function (raptor_sfun_adjustment): '<S30>/raptor_adjustment4'
   */
  rtb_Logic = Accelerator_ConstP.Logic_table[((((uint32_T)(rtb_raptor_digital_in
    && (rtb_MultiportSwitch1 >= (KeySwHiTimeThr_Data()))) << 1) + (uint32_T)
    ((!rtb_raptor_digital_in) && (rtb_MultiportSwitch1 >= (KeySwLoTimeThr_Data()))))
    << 1) + rtb_raptor_sfun_nv_status];

  /* Logic: '<S29>/Logical Operator1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S29>/raptor_data_read1'
   */
  rtb_LogicalOperator1_h = (rtb_Logic || KeepModuleOn_Data());

  /* Outputs for Triggered SubSystem: '<S29>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S31>/Trigger'
   */
  if ((!rtb_LogicalOperator1_h) &&
      (Accelerator_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (raptor_sfun_data_write): '<S31>/raptor_data_write' incorporates:
     *  Constant: '<S31>/Constant'
     */
    FgndTasksStopped_Data() = true;

    /* S-Function (fcgen): '<S31>/Function-Call Generator' incorporates:
     *  SubSystem: '<S31>/raptor_shutdown'
     */
    /* S-Function (raptor_sfun_shutdown): '<S35>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Shutdown(void);
      App_Shutdown();
    }

    /* End of Outputs for S-Function (fcgen): '<S31>/Function-Call Generator' */
  }

  Accelerator_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE =
    rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S29>/Raise Shutdown Event' */
  /* Outputs for Enabled and Triggered SubSystem: '<S29>/Raise Startup Event' incorporates:
   *  EnablePort: '<S32>/Enable'
   *  TriggerPort: '<S32>/Trigger'
   */
  if (FgndTasksStopped_Data() && (rtb_LogicalOperator1_h &&
       (Accelerator_PrevZCSigState.RaiseStartupEvent_Trig_ZCE != POS_ZCSIG))) {
    /* S-Function (fcgen): '<S32>/Function-Call Generator' incorporates:
     *  SubSystem: '<S32>/raptor_startup'
     */
    /* S-Function (raptor_sfun_startup): '<S36>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Startup(void);
      App_Startup();
    }

    /* End of Outputs for S-Function (fcgen): '<S32>/Function-Call Generator' */
  }

  /* End of S-Function (raptor_sfun_data_read): '<S29>/raptor_data_read' */

  /* Outputs for Triggered SubSystem: '<S29>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S31>/Trigger'
   */
  Accelerator_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S29>/Raise Shutdown Event' */
  /* End of Outputs for SubSystem: '<S29>/Raise Startup Event' */

  /* UnitDelay: '<S29>/Unit Delay' */
  rtb_LogicalOperator2_c = Accelerator_DWork.UnitDelay_DSTATE_e;

  /* Outputs for Triggered SubSystem: '<S29>/Store EEPROM' incorporates:
   *  TriggerPort: '<S33>/Trigger'
   */
  if ((!Accelerator_DWork.UnitDelay_DSTATE_e) &&
      (Accelerator_PrevZCSigState.StoreEEPROM_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (fcgen): '<S33>/Function-Call Generator' incorporates:
     *  SubSystem: '<S33>/raptor_store_nv'
     */
    /* S-Function (raptor_sfun_store_nv): '<S37>/raptor_data_write' */
    /* S-Function Block */
    {
      App_EE_Store();
    }

    /* End of Outputs for S-Function (fcgen): '<S33>/Function-Call Generator' */
  }

  /* End of UnitDelay: '<S29>/Unit Delay' */
  Accelerator_PrevZCSigState.StoreEEPROM_Trig_ZCE = rtb_LogicalOperator2_c;

  /* End of Outputs for SubSystem: '<S29>/Store EEPROM' */

  /* S-Function (raptor_sfun_data_write): '<S29>/raptor_data_write' */
  KeySw_Bgnd_Data() = rtb_Logic;

  /* S-Function (raptor_sfun_nv_status): '<S29>/raptor_sfun_nv_status' */
  /* S-Function Block */
  {
    rtb_raptor_sfun_nv_status = (EEPROM_State_Data() == EE_STORE_IN_PROGESS);
  }

  /* Logic: '<S29>/Logical Operator2' incorporates:
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  rtb_raptor_sfun_nv_status = (rtb_raptor_sfun_nv_status ||
    rtb_LogicalOperator1_h || Accelerator_DWork.UnitDelay1_DSTATE_f);

  /* S-Function (raptor_sfun_digital_out): '<S29>/raptor_digital_out' */
  /* S-Function Block: POWER_HOLD */
  {
    {
      if (rtb_raptor_sfun_nv_status && !swsh_ignswSt()) {
        SyC_WaitPostDrv();
      }
    }
  }

  /* Update for UnitDelay: '<S34>/Delay Input1' */
  Accelerator_DWork.DelayInput1_DSTATE_c = rtb_raptor_digital_in;

  /* Update for UnitDelay: '<S30>/Unit Delay' */
  Accelerator_DWork.UnitDelay_DSTATE_b = rtb_MultiportSwitch1;

  /* Update for UnitDelay: '<S30>/Unit Delay2' */
  Accelerator_DWork.UnitDelay2_DSTATE = rtb_Logic;

  /* Update for UnitDelay: '<S29>/Unit Delay' */
  Accelerator_DWork.UnitDelay_DSTATE_e = rtb_LogicalOperator1_h;

  /* Update for UnitDelay: '<S29>/Unit Delay1' */
  Accelerator_DWork.UnitDelay1_DSTATE_f = rtb_LogicalOperator2_c;
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_FunctionCallSubsystem_Init(void)
{
  /* Start for If: '<S2>/If' */
  Accelerator_DWork.If_ActiveSubsystem = -1;
}

/* Enable for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_FunctionCallSubsystem_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S2>/raptor_can_txmsg' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */
  /* Level2 S-Function Block: '<S2>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_747__0001(0U);
}

/* Disable for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_FunctionCallSubsystem_Disable(void)
{
  /* Disable for If: '<S2>/If' */
  if (Accelerator_DWork.If_ActiveSubsystem == 0) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S28>/raptor_can_txmsg' incorporates:
     *  Constant: '<S28>/Constant'
     */
    /* Level2 S-Function Block: '<S28>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_744__0001(0);
  }

  Accelerator_DWork.If_ActiveSubsystem = -1;

  /* End of Disable for If: '<S2>/If' */

  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S2>/raptor_can_txmsg' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */
  /* Level2 S-Function Block: '<S2>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_747__0001(0);
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_FunctionCallSubsystem(void)
{
  real_T rtb_DataTypeConversion3;
  uint32_T rtb_raptor_time;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S27>/Compare'
   *  S-Function (raptor_sfun_data_read): '<S2>/raptor_data_read'
   */
  rtPrevAction = Accelerator_DWork.If_ActiveSubsystem;
  rtAction = -1;
  if (AbsoluteTime_Data() >= 5.0) {
    rtAction = 0;
  }

  Accelerator_DWork.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S28>/raptor_can_txmsg' incorporates:
     *  Constant: '<S28>/Constant'
     */
    /* Level2 S-Function Block: '<S28>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_744__0001(0);
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* Enable for If: '<S2>/If' incorporates:
       *  Constant: '<S28>/Constant'
       *  S-Function (raptor_sfun_can_txmsg): '<S28>/raptor_can_txmsg'
       */
      /* Level2 S-Function Block: '<S28>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
      can_set_period_744__0001(0U);

      /* End of Enable for SubSystem: '<S2>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* S-Function (raptor_sfun_can_txmsg): '<S28>/raptor_can_txmsg' incorporates:
     *  Constant: '<S28>/Constant'
     */

    /* S-Function Block:<S28>/raptor_can_txmsg */
    {
      uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

      uint32_T temp;
      uint8_T temp_shift;

      /* Signal: Inverter_Enable */
      /* Inverter_Enable - StartBit: 40U, BitLength: 1U, Endian: 0U */

      /* signal type is unsigned */
      if (1.0 < 0.0000000000F)
        temp = (uint32_T)0U;
      else if (1.0 > 1.0000000000F)
        temp = (uint32_T)1U;
      else {
        if ((real_T)1.0 < 0)
          temp = (uint32_T)(int32_T)((1.0));
        else
          temp = (uint32_T)((1.0));
      }

      temp_shift = (uint8_T)(temp >> 0);
      temp_shift &= ((uint8_T)1U);
      data[5U] |= temp_shift;
      can_set_period_744__0001(0U);
      can_send_744__0001(192U & 0x7FF, 0, 8U, &data[0]);
    }

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  }

  /* End of If: '<S2>/If' */

  /* S-Function (raptor_sfun_can_txmsg): '<S2>/raptor_can_txmsg' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */

  /* S-Function Block:<S2>/raptor_can_txmsg */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: D1_Parameter_Address_Command */
    /* D1_Parameter_Address_Command - StartBit: 0U, BitLength: 16U, Endian: 0U */

    /* signal type is unsigned */
    if (20.0 < 0.0000000000F)
      temp = (uint32_T)0U;
    else if (20.0 > 65535.0000000000F)
      temp = (uint32_T)65535U;
    else {
      if ((real_T)20.0 < 0)
        temp = (uint32_T)(int32_T)((20.0));
      else
        temp = (uint32_T)((20.0));
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[0U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[1U] |= temp_shift;

    /* Signal: D2_Read_Write_Command        */
    /* D2_Read_Write_Command        - StartBit: 16U, BitLength: 1U, Endian: 0U */

    /* signal type is unsigned */
    if (1.0 < 0.0000000000F)
      temp = (uint32_T)0U;
    else if (1.0 > 1.0000000000F)
      temp = (uint32_T)1U;
    else {
      if ((real_T)1.0 < 0)
        temp = (uint32_T)(int32_T)((1.0));
      else
        temp = (uint32_T)((1.0));
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)1U);
    data[2U] |= temp_shift;

    /* Signal: D3_Data_Command              */
    /* D3_Data_Command              - StartBit: 32U, BitLength: 16U, Endian: 0U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)0.0 < -32768.0)
        tempS = (int32_T)-32768.0;
      else if ((real_T)0.0 > 32767.0)
        tempS = (int32_T)32767.0;
      else if ((real_T)0.0 < 0)
        tempS = (int32_T)(int32_T)((0.0));
      else
        tempS = (int32_T)((0.0));
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[4U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[5U] |= temp_shift;
    can_set_period_747__0001(0U);
    can_send_747__0001(193U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_time): '<S2>/raptor_time' */
  rtb_raptor_time = ticks();

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  rtb_DataTypeConversion3 = rtb_raptor_time;

  /* S-Function (raptor_sfun_data_write): '<S2>/raptor_data_write' */
  AbsoluteTime_Data() = rtb_DataTypeConversion3;
}

/*
 * Output and update for atomic system:
 *    '<S17>/MATLAB Function'
 *    '<S18>/MATLAB Function'
 */
void Accelerator_MATLABFunction(real_T rtu_a, real_T rtu_b, real_T rtu_c,
  rtB_MATLABFunction_Accelerator *localB)
{
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S22>:1' */
  /* '<S22>:1:2' */
  localB->y = (rtu_a - rtu_c) / (rtu_b - rtu_c);
}

/* System initialize for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground_Init(void)
{
  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in' */

  /* S-Function Block: INPUT30 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' */

  /* S-Function Block: INPUT29 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in' */

  /* S-Function Block: INPUT37 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in2' */

  /* S-Function Block: INPUT23 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in1' */

  /* S-Function Block: INPUT35 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in2' */

  /* S-Function Block: INPUT34 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S1>/raptor_digital_out' */

  /* S-Function Block: OUTPUT8 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in6' */

  /* S-Function Block: INPUT24 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S1>/raptor_digital_out1' */

  /* S-Function Block: OUTPUT35 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S1>/raptor_digital_out2' */

  /* S-Function Block: OUTPUT38 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in4' */

  /* S-Function Block: INPUT21 */
  {
  }

  /* Start for S-Function (raptor_sfun_pwm_out): '<S1>/raptor_pwm_out' */

  /* S-Function Block: OUTPUT11 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in5' */

  /* S-Function Block: INPUT26 */
  {
  }

  /* Start for S-Function (raptor_sfun_pwm_out): '<S1>/raptor_pwm_out1' */

  /* S-Function Block: OUTPUT7 */
  {
  }

  /* Start for S-Function (raptor_sfun_freq_in): '<S1>/raptor_freq_in' */

  /* S-Function Block: INPUT43 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in3' */

  /* S-Function Block: INPUT25 */
  {
  }

  /* SystemInitialize for Enabled SubSystem: '<S11>/D Latch' */
  /* SystemInitialize for Logic: '<S21>/Logic' incorporates:
   *  Outport: '<S21>/!Q'
   */
  Accelerator_B.Logic = true;

  /* End of SystemInitialize for SubSystem: '<S11>/D Latch' */
}

/* Enable for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_38__0002(10U);
}

/* Disable for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground_Disable(void)
{
  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_38__0002(0);
}

/* Output and update for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground(void)
{
  /* local block i/o variables */
  uint16_T rtb_raptor_analog_in2;
  uint16_T rtb_raptor_analog_in6;
  uint16_T rtb_raptor_analog_in4;
  uint16_T rtb_raptor_analog_in5;
  uint16_T rtb_raptor_analog_in3;
  uint16_T rtb_raptor_analog_in;
  uint16_T rtb_raptor_analog_in1;
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare_f;
  real_T rtb_VectorConcatenate[4];
  real_T rtb_DataTypeConversion4;
  real_T rtb_Divide;
  real_T rtb_ITempOPowerW;
  real_T rtb_Switch;
  real_T tmp;
  int_T idxDelay;
  uint32_T rtb_ConvtoHz;
  uint32_T rtb_Diff_a;
  uint16_T rtb_for001inc1;
  uint8_T rtb_FixPtRelationalOperator_g;
  boolean_T rtb_Compare_k;
  boolean_T rtb_GreaterThan1;
  boolean_T rtb_LogicalOperator3_g;

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override1' incorporates:
   *  S-Function (raptor_sfun_adjustment): '<S6>/raptor_adjustment'
   */
  if (Direction_cmd_override_OvrSts_Data()) {
    Accelerator_B.raptor_override1 = Direction_cmd_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override1 = (Vehicle_direction_Data());
  }

  /* S-Function (raptor_sfun_override): '<S17>/raptor_override2' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S17>/raptor_fault_status'
   */
  if (POT1_InputHi_Override_OvrSts_Data()) {
    Accelerator_B.u1_d = POT1_InputHi_Override_OvrVal_Data();
  } else {
    Accelerator_B.u1_d = (getFaultState(1, (E_FaultState)FAULT_ACTIVE_MASK));
  }

  POT1_InputHi_Override_Data() = Accelerator_B.u1_d;

  /* S-Function (raptor_sfun_override): '<S17>/raptor_override3' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S17>/raptor_fault_status1'
   */
  if (POT1_InputLow_Override_OvrSts_Data()) {
    Accelerator_B.u1_g = POT1_InputLow_Override_OvrVal_Data();
  } else {
    Accelerator_B.u1_g = (getFaultState(2, (E_FaultState)FAULT_ACTIVE_MASK));
  }

  POT1_InputLow_Override_Data() = Accelerator_B.u1_g;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in' */
  /* S-Function Block: INPUT30 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK082();
      rtb_raptor_analog_in = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S17>/raptor_override' */
  if (POT1_ADC_OvrSts_Data()) {
    Accelerator_B.u1_n = POT1_ADC_OvrVal_Data();
  } else {
    Accelerator_B.u1_n = rtb_raptor_analog_in;
  }

  POT1_ADC_Data() = Accelerator_B.u1_n;

  /* S-Function (raptor_sfun_adjustment): '<S17>/raptor_adjustment1' */
  rtb_Switch = (POT1_ADCHiPT_Data());

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion1'
   */
  rtb_raptor_analog_in1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S17>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = rtb_raptor_analog_in1;

  /* S-Function (raptor_sfun_adjustment): '<S17>/raptor_adjustment' */
  rtb_Switch = (POT1_ADCLoPT_Data());

  /* DataTypeConversion: '<S17>/Data Type Conversion2' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion2'
   */
  rtb_raptor_analog_in1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion3'
   *  DataTypeConversion: '<S17>/Data Type Conversion5'
   */
  Accelerator_MATLABFunction((real_T)Accelerator_B.u1_n, rtb_DataTypeConversion4,
    (real_T)rtb_raptor_analog_in1, &Accelerator_B.sf_MATLABFunction_m);

  /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  Logic: '<S17>/Logical Operator'
   */
  if ((!Accelerator_B.u1_d) && (!Accelerator_B.u1_g)) {
    /* Saturate: '<S17>/Saturation' */
    if (Accelerator_B.sf_MATLABFunction_m.y > 100.0) {
      rtb_Switch = 100.0;
    } else if (Accelerator_B.sf_MATLABFunction_m.y < 0.0) {
      rtb_Switch = 0.0;
    } else {
      rtb_Switch = Accelerator_B.sf_MATLABFunction_m.y;
    }

    /* End of Saturate: '<S17>/Saturation' */
  } else {
    rtb_Switch = 0.0;
  }

  /* End of MultiPortSwitch: '<S17>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S17>/raptor_override1' */
  if (POT1_OvrSts_Data()) {
    Accelerator_B.u1 = POT1_OvrVal_Data();
  } else {
    Accelerator_B.u1 = rtb_Switch;
  }

  POT1_Data() = Accelerator_B.u1;

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override8' */
  if (APP1_override_OvrSts_Data()) {
    Accelerator_B.raptor_override8 = APP1_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override8 = Accelerator_B.u1;
  }

  /* S-Function (raptor_sfun_override): '<S18>/raptor_override2' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S18>/raptor_fault_status'
   */
  if (POT2_InputHi_Override_OvrSts_Data()) {
    Accelerator_B.u1_a = POT2_InputHi_Override_OvrVal_Data();
  } else {
    Accelerator_B.u1_a = (getFaultState(3, (E_FaultState)FAULT_ACTIVE_MASK));
  }

  POT2_InputHi_Override_Data() = Accelerator_B.u1_a;

  /* S-Function (raptor_sfun_override): '<S18>/raptor_override3' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S18>/raptor_fault_status1'
   */
  if (POT2_InputLow_Override_OvrSts_Data()) {
    Accelerator_B.u1_p = POT2_InputLow_Override_OvrVal_Data();
  } else {
    Accelerator_B.u1_p = (getFaultState(4, (E_FaultState)FAULT_ACTIVE_MASK));
  }

  POT2_InputLow_Override_Data() = Accelerator_B.u1_p;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' */
  /* S-Function Block: INPUT29 */
  {
    {
      static uint16_T last_value = 0;
      static uint8_T hold = 0;
      if ((MoCADC_stMsg & 0x08) || (MoCADC_stMsg & 0x03)) {
        hold = INPUT29_ADCMon_HoldCount_Data();
      }

      if (hold > 0) {
        hold--;

        //Level 3 monitoring test for APP is active
        rtb_raptor_analog_in1 = last_value;
      } else {
        int16_T input = swsh_Read_ADC_ECUK065();
        last_value = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
        rtb_raptor_analog_in1 = last_value;
      }
    }
  }

  /* S-Function (raptor_sfun_override): '<S18>/raptor_override' */
  if (POT2_ADC_OvrSts_Data()) {
    Accelerator_B.u1_l = POT2_ADC_OvrVal_Data();
  } else {
    Accelerator_B.u1_l = rtb_raptor_analog_in1;
  }

  POT2_ADC_Data() = Accelerator_B.u1_l;

  /* S-Function (raptor_sfun_adjustment): '<S18>/raptor_adjustment1' */
  rtb_Switch = (POT2_ADCHiPT_Data());

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  rtb_for001inc1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S18>/Data Type Conversion1' */

  /* DataTypeConversion: '<S18>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = rtb_for001inc1;

  /* S-Function (raptor_sfun_adjustment): '<S18>/raptor_adjustment' */
  rtb_Switch = (POT2_ADCLoPT_Data());

  /* DataTypeConversion: '<S18>/Data Type Conversion2' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  rtb_for001inc1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S18>/Data Type Conversion2' */

  /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion3'
   *  DataTypeConversion: '<S18>/Data Type Conversion5'
   */
  Accelerator_MATLABFunction((real_T)Accelerator_B.u1_l, rtb_DataTypeConversion4,
    (real_T)rtb_for001inc1, &Accelerator_B.sf_MATLABFunction_i);

  /* MultiPortSwitch: '<S18>/Multiport Switch' incorporates:
   *  Constant: '<S18>/Constant'
   *  Logic: '<S18>/Logical Operator'
   */
  if ((!Accelerator_B.u1_a) && (!Accelerator_B.u1_p)) {
    /* Saturate: '<S18>/Saturation' */
    if (Accelerator_B.sf_MATLABFunction_i.y > 100.0) {
      rtb_Switch = 100.0;
    } else if (Accelerator_B.sf_MATLABFunction_i.y < 0.0) {
      rtb_Switch = 0.0;
    } else {
      rtb_Switch = Accelerator_B.sf_MATLABFunction_i.y;
    }

    /* End of Saturate: '<S18>/Saturation' */
  } else {
    rtb_Switch = 0.0;
  }

  /* End of MultiPortSwitch: '<S18>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S18>/raptor_override1' */
  if (POT2_OvrSts_Data()) {
    Accelerator_B.u1_c = POT2_OvrVal_Data();
  } else {
    Accelerator_B.u1_c = rtb_Switch;
  }

  POT2_Data() = Accelerator_B.u1_c;

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override9' */
  if (APP2_override_OvrSts_Data()) {
    Accelerator_B.raptor_override9 = APP2_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override9 = Accelerator_B.u1_c;
  }

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  SignalConversion generated from: '<S14>/ SFunction '
   */
  /* MATLAB Function 'Foreground/MATLAB Function': '<S14>:1' */
  /* '<S14>:1:2' */
  rtb_Compare_k = (fabsf((real32_T)(Accelerator_B.raptor_override9 -
    Accelerator_B.raptor_override8)) <= 0.1);

  /* S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in' */
  /* S-Function Block: INPUT37 */
  {
    rtb_Compare_c = swsh_DIO_in_ECUK016();
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override' */
  if (Starter_button_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override_b = Starter_button_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override_b = rtb_Compare_c;
  }

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in2' */
  /* S-Function Block: INPUT23 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK034();
      rtb_raptor_analog_in2 = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override1' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in2'
   */
  if (Safety_loop_error_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override1_p =
      Safety_loop_error_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override1_p = rtb_raptor_analog_in2;
  }

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtb_Compare_c = (Accelerator_B.raptor_override1_p >= 2000);

  /* Outputs for Enabled SubSystem: '<S11>/D Latch' incorporates:
   *  EnablePort: '<S21>/C'
   */
  /* Logic: '<S1>/Logical Operator' */
  if (Accelerator_B.raptor_override_b == rtb_Compare_c) {
    /* SignalConversion generated from: '<S21>/D' */
    Accelerator_B.D = Accelerator_B.raptor_override_b;

    /* Logic: '<S21>/Logic' */
    Accelerator_B.Logic = !Accelerator_B.D;
  }

  /* End of Logic: '<S1>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S11>/D Latch' */

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override11' */
  if (Starter_button_override_OvrSts_Data()) {
    Accelerator_B.raptor_override11 = Starter_button_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override11 = Accelerator_B.D;
  }

  /* S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in1' */
  /* S-Function Block: INPUT35 */
  {
    rtb_Compare_f = swsh_DIO_in_ECUK049();
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override5' */
  if (Precharge_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override5 = Precharge_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override5 = rtb_Compare_f;
  }

  /* S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in2' */
  /* S-Function Block: INPUT34 */
  {
    rtb_Compare_f = swsh_DIO_in_ECUK047();
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override6' */
  if (Charge_mode_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override6 = Charge_mode_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override6 = rtb_Compare_f;
  }

  /* Logic: '<S1>/Logical Operator3' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status'
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status1'
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status2'
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status3'
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status4'
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status5'
   */
  rtb_LogicalOperator3_g = ((getFaultState(10, (E_FaultState)FAULT_ACTIVE_MASK))
    || (getFaultState(11, (E_FaultState)FAULT_ACTIVE_MASK)) || (getFaultState(9,
    (E_FaultState)FAULT_ACTIVE_MASK)) || (getFaultState(7, (E_FaultState)
    FAULT_ACTIVE_MASK)) || (getFaultState(8, (E_FaultState)FAULT_ACTIVE_MASK)) ||
    (getFaultState(6, (E_FaultState)FAULT_ACTIVE_MASK)));

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override14' */
  if (Cooling_fault_any_override_OvrSts_Data()) {
    Accelerator_B.raptor_override14 = Cooling_fault_any_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override14 = rtb_LogicalOperator3_g;
  }

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Logic: '<S1>/Logical Operator2'
   *  Logic: '<S1>/Logical Operator7'
   */
  rtb_LogicalOperator3_g = (rtb_Compare_k && Accelerator_B.raptor_override11 &&
    Accelerator_B.raptor_override5 && (!Accelerator_B.raptor_override6) &&
    (!Accelerator_B.raptor_override14));

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override10' */
  if (Drive_enable_override_OvrSts_Data()) {
    Accelerator_B.raptor_override10 = Drive_enable_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override10 = rtb_LogicalOperator3_g;
  }

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override2' */
  if (Inverter_enb_override_OvrSts_Data()) {
    Accelerator_B.raptor_override2 = Inverter_enb_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override2 = Accelerator_B.raptor_override10;
  }

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  SignalConversion generated from: '<S14>/ SFunction '
   */
  /* MATLAB Function 'Foreground/MATLAB Function1': '<S15>:1' */
  /* '<S15>:1:2' */
  rtb_Switch = (Accelerator_B.raptor_override8 + Accelerator_B.raptor_override9)
    / 2.0;

  /* Switch: '<S1>/Switch' */
  if (Accelerator_B.raptor_override10) {
    /* S-Function (raptor_sfun_override): '<S1>/raptor_override15' */
    if (APP_override_OvrSts_Data()) {
      Accelerator_B.raptor_override15 = APP_override_OvrVal_Data();
    } else {
      Accelerator_B.raptor_override15 = rtb_Switch;
    }

    rtb_Switch = Accelerator_B.raptor_override15;
  } else {
    /* S-Function (raptor_sfun_override): '<S1>/raptor_override17' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (APP_default_err_override_OvrSts_Data()) {
      Accelerator_B.raptor_override17 = APP_default_err_override_OvrVal_Data();
    } else {
      Accelerator_B.raptor_override17 = 0.0;
    }

    rtb_Switch = Accelerator_B.raptor_override17;
  }

  /* End of Switch: '<S1>/Switch' */

  /* S-Function (raptor_sfun_can_rxmsg): '<S1>/raptor_can_rxmsg' */

  /* S-Function Block:<S1>/raptor_can_rxmsg */
  {
    uint8_T data[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint32_T temp;
    can_get_286__0002(NULL, NULL, NULL, &data[0], 8);

    /* Signal: D2_Motor_Speed */
    temp = 0;
    temp |= ((uint32_T)data[2U]) ;
    temp |= ((uint32_T)data[3U]) << 8;
    if (temp & 32768)
      temp |= (uint32_T)-65536;
    rtb_Divide = (((real_T) ((int32_T) temp) ) );
  }

  /* Abs: '<S1>/Abs' */
  rtb_Divide = fabsf((real32_T)rtb_Divide);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override3' */
  if (RPM_override_OvrSts_Data()) {
    Accelerator_B.raptor_override3 = RPM_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override3 = rtb_Divide;
  }

  /* S-Function (raptor_sfun_table_axis): '<S20>/raptor_table_axis' */
  {
    int idx;
    for (idx=0;idx<1;idx++) {
      Accelerator_B.raptor_table_axis = TableAxis_real32_T
        ( Accelerator_B.raptor_override3, RPM_Data(), 33u,
         Accelerator_B.raptor_table_axis);
    }

    idx = 0;
    RPM_IN_Data() = Accelerator_B.raptor_override3;
  }

  /* S-Function (raptor_sfun_table_interpolate_1d): '<S20>/raptor_table_interpolate_1d' */
  {
    rtb_Divide = TableInterpolate1D_real32_T( Accelerator_B.raptor_table_axis,
      MaxTorqueMap_Data(), 33u);
    MaxTorqueMap_Y_IN_IDX_Data() = Accelerator_B.raptor_table_axis;
  }

  /* Gain: '<S5>/Safety factor' incorporates:
   *  Product: '<S5>/Product'
   */
  rtb_Divide = rtb_Switch * rtb_Divide * 0.9;

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override16' */
  if (Torque_map_val_override_OvrSts_Data()) {
    Accelerator_B.raptor_override16 = Torque_map_val_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override16 = rtb_Divide;
  }

  /* Saturate: '<S6>/Saturation' */
  if (Accelerator_B.raptor_override16 > 3276.0) {
    rtb_Divide = 3276.0;
  } else if (Accelerator_B.raptor_override16 < 0.0) {
    rtb_Divide = 0.0;
  } else {
    rtb_Divide = Accelerator_B.raptor_override16;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override' */
  if (Torque_cmd_override_OvrSts_Data()) {
    Accelerator_B.raptor_override = Torque_cmd_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override = rtb_Divide;
  }

  /* S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' */

  /* S-Function Block:<S6>/raptor_can_txmsg */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: Direction_Command */
    /* Direction_Command - StartBit: 32U, BitLength: 1U, Endian: 0U */

    /* signal type is unsigned */
    if (Accelerator_B.raptor_override1 < 0.0000000000F)
      temp = (uint32_T)0U;
    else if (Accelerator_B.raptor_override1 > 1.0000000000F)
      temp = (uint32_T)1U;
    else {
      if ((real_T)Accelerator_B.raptor_override1 < 0)
        temp = (uint32_T)(int32_T)((Accelerator_B.raptor_override1));
      else
        temp = (uint32_T)((Accelerator_B.raptor_override1));
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)1U);
    data[4U] |= temp_shift;

    /* Signal: Inverter_Enable   */
    /* Inverter_Enable   - StartBit: 40U, BitLength: 1U, Endian: 0U */

    /* signal type is unsigned */

    /* Optimize the checks out since both the min and max are within the limits of this particular data type */
    {
      temp = (uint32_T)((Accelerator_B.raptor_override2));
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)1U);
    data[5U] |= temp_shift;

    /* Signal: Torque_Command    */
    /* Torque_Command    - StartBit: 0U, BitLength: 16U, Endian: 0U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)Accelerator_B.raptor_override < -3276.8)
        tempS = (int32_T)-32768.0;
      else if ((real_T)Accelerator_B.raptor_override > 3276.7000000000003)
        tempS = (int32_T)32767.0;
      else if ((real_T)Accelerator_B.raptor_override < 0)
        tempS = (int32_T)(int32_T)((Accelerator_B.raptor_override) * 10.0f);
      else
        tempS = (int32_T)((Accelerator_B.raptor_override) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[0U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[1U] |= temp_shift;
    can_set_period_38__0002(10U);
    can_send_periodic_38__0002(192U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement' */
  Torque_cmd_Data() = Accelerator_B.raptor_override;

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement1' */
  Direction_cmd_Data() = Accelerator_B.raptor_override1;

  /* Outputs for Atomic SubSystem: '<S1>/Triggered Single Pulse' */
  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S26>/Compare'
   *  UnitDelay: '<S24>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_g = (uint8_T)((int32_T)
    Accelerator_B.raptor_override10 > Accelerator_DWork.DelayInput1_DSTATE);

  /* UnitDelay: '<S19>/Unit Delay1' */
  rtb_DataTypeConversion4 = Accelerator_DWork.UnitDelay1_DSTATE;

  /* UnitDelay: '<S19>/Unit Delay' */
  rtb_Divide = Accelerator_DWork.UnitDelay_DSTATE_l;

  /* Logic: '<S19>/Logical Operator' incorporates:
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S25>/Compare'
   */
  rtb_LogicalOperator3_g = !(rtb_Divide > 4.0);

  /* Saturate: '<S19>/Saturation' */
  if (rtb_DataTypeConversion4 > 1.0) {
    rtb_DataTypeConversion4 = 1.0;
  } else if (rtb_DataTypeConversion4 < 0.0) {
    rtb_DataTypeConversion4 = 0.0;
  }

  /* Product: '<S19>/Product3' incorporates:
   *  Saturate: '<S19>/Saturation'
   */
  rtb_DataTypeConversion4 *= (real_T)rtb_LogicalOperator3_g;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  RelationalOperator: '<S26>/Compare'
   */
  Accelerator_DWork.DelayInput1_DSTATE = Accelerator_B.raptor_override10;

  /* Update for UnitDelay: '<S19>/Unit Delay1' incorporates:
   *  Sum: '<S19>/Add1'
   */
  Accelerator_DWork.UnitDelay1_DSTATE = rtb_DataTypeConversion4 + (real_T)
    rtb_FixPtRelationalOperator_g;

  /* Update for UnitDelay: '<S19>/Unit Delay' incorporates:
   *  Product: '<S19>/Product'
   *  Product: '<S19>/Product1'
   *  Sum: '<S19>/Add'
   */
  Accelerator_DWork.UnitDelay_DSTATE_l = (rtb_DataTypeConversion4 + rtb_Divide) *
    rtb_DataTypeConversion4;

  /* End of Outputs for SubSystem: '<S1>/Triggered Single Pulse' */

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_LogicalOperator3_g = (rtb_DataTypeConversion4 > 0.0);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override2' */
  if (RTDS_override_OvrSts_Data()) {
    Accelerator_B.raptor_override2_b = RTDS_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override2_b = rtb_LogicalOperator3_g;
  }

  /* S-Function (raptor_sfun_digital_out): '<S1>/raptor_digital_out' */
  /* S-Function Block: OUTPUT8 */
  {
    {
      static uint8_T prevValue = 255;
      if (prevValue != Accelerator_B.raptor_override2_b) {
        swsh_PWMout_Period_Duty_ECUK088(5000, Accelerator_B.raptor_override2_b ?
          32767 : 0);              /* period in uSec, duty is 0-100 [0-65535] */
        prevValue = Accelerator_B.raptor_override2_b;
      }
    }
  }

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in6' */
  /* S-Function Block: INPUT24 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK035();
      rtb_raptor_analog_in6 = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override22' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in6'
   */
  if (TSMS_ADC_override_OvrSts_Data()) {
    Accelerator_B.raptor_override22 = TSMS_ADC_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override22 = rtb_raptor_analog_in6;
  }

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Compare_f = (Accelerator_B.raptor_override22 >= 1800);

  /* Logic: '<S1>/Logical Operator5' incorporates:
   *  Logic: '<S1>/Logical Operator4'
   */
  rtb_LogicalOperator3_g = (rtb_Compare_f && (!Accelerator_B.raptor_override5));

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override24' */
  if (IMD_GLV_override_OvrSts_Data()) {
    Accelerator_B.raptor_override24 = IMD_GLV_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override24 = rtb_LogicalOperator3_g;
  }

  /* S-Function (raptor_sfun_digital_out): '<S1>/raptor_digital_out1' */
  /* S-Function Block: OUTPUT35 */
  {
    {
      static uint8_T prevValue = 255;
      if (prevValue != Accelerator_B.raptor_override24) {
        swsh_DIO_out_ECUK020(Accelerator_B.raptor_override24);
        prevValue = Accelerator_B.raptor_override24;
      }
    }
  }

  /* Logic: '<S1>/Logical Operator6' */
  rtb_LogicalOperator3_g = !rtb_LogicalOperator3_g;

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override23' */
  if (IMD_OkHs_override_OvrSts_Data()) {
    Accelerator_B.raptor_override23 = IMD_OkHs_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override23 = rtb_LogicalOperator3_g;
  }

  /* S-Function (raptor_sfun_digital_out): '<S1>/raptor_digital_out2' */
  /* S-Function Block: OUTPUT38 */
  {
    {
      static uint8_T prevValue = 255;
      if (prevValue != Accelerator_B.raptor_override23) {
        swsh_DIO_out_ECUK038(Accelerator_B.raptor_override23);
        prevValue = Accelerator_B.raptor_override23;
      }
    }
  }

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in4' */
  /* S-Function Block: INPUT21 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK013();
      rtb_raptor_analog_in4 = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override12' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in4'
   */
  if (Temp_adc_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override12 = Temp_adc_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override12 = rtb_raptor_analog_in4;
  }

  /* Product: '<S1>/Product3' incorporates:
   *  Constant: '<S1>/ADC_corrected'
   */
  rtb_Divide = (real_T)Accelerator_B.raptor_override12 * 0.00122100122;

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/PU (Ohms)'
   *  Constant: '<S1>/Vs (V)'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add2'
   */
  rtb_Divide = rtb_Divide * 2.145 / (5.0 - rtb_Divide);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override13' */
  if (Temp_resistance_override_OvrSts_Data()) {
    Accelerator_B.raptor_override13 = Temp_resistance_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override13 = rtb_Divide;
  }

  /* Lookup_n-D: '<S1>/I: R (kOhm) O: T (C)' incorporates:
   *  S-Function (raptor_sfun_override): '<S1>/raptor_override13'
   */
  rtb_DataTypeConversion4 = look1_binlxpw(Accelerator_B.raptor_override13,
    Accelerator_ConstP.IRkOhmOTC_bp01Data,
    Accelerator_ConstP.IRkOhmOTC_tableData, 24U);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override18' */
  if (Temp_actual_celsius_override_OvrSts_Data()) {
    Accelerator_B.raptor_override18 = Temp_actual_celsius_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override18 = rtb_DataTypeConversion4;
  }

  /* RelationalOperator: '<S1>/GreaterThan1' incorporates:
   *  S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment5'
   *  Sum: '<S12>/Diff'
   *  UnitDelay: '<S12>/UD'
   */
  rtb_GreaterThan1 = (Accelerator_B.raptor_override18 -
                      Accelerator_DWork.UD_DSTATE > (tempRateFault_Data()));

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def' */

  /* Fault Reference : eradicTemp */
  {
    {
      updateFaultInput(7, rtb_GreaterThan1, eradicTemp_X_Limit_Data(),
                       eradicTemp_Y_Limit_Data(), 1);
    }
  }

  /* RelationalOperator: '<S1>/GreaterThan2' incorporates:
   *  Constant: '<S1>/100 kOhm'
   */
  rtb_GreaterThan1 = (rtb_Divide > 100.0);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def1' */

  /* Fault Reference : tempSenseOC */
  {
    {
      updateFaultInput(10, rtb_GreaterThan1, tempSenseOC_X_Limit_Data(),
                       tempSenseOC_Y_Limit_Data(), 0);
    }
  }

  /* RelationalOperator: '<S1>/Less Than1' incorporates:
   *  Constant: '<S1>/100 Ohm'
   */
  rtb_GreaterThan1 = (rtb_Divide < 0.1);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def2' */

  /* Fault Reference : tempSenseSC */
  {
    {
      updateFaultInput(11, rtb_GreaterThan1, tempSenseSC_X_Limit_Data(),
                       tempSenseSC_Y_Limit_Data(), 0);
    }
  }

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/25C default'
   *  Delay: '<S1>/Delay'
   */
  if (Accelerator_DWork.Delay_DSTATE[0] > 0.0) {
    rtb_DataTypeConversion4 = Accelerator_B.raptor_override18;
  } else {
    rtb_DataTypeConversion4 = 25.0;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* RelationalOperator: '<S1>/GreaterThan4' incorporates:
   *  Constant: '<S1>/100 C'
   */
  rtb_GreaterThan1 = (rtb_DataTypeConversion4 > 80.0);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def5' */

  /* Fault Reference : tempHigh */
  {
    {
      updateFaultInput(9, rtb_GreaterThan1, tempHigh_X_Limit_Data(),
                       tempHigh_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def6' */

  /* Fault Reference : Throttle_plausibility */
  {
    {
      updateFaultInput(5, rtb_Compare_k, Throttle_plausibility_X_Limit_Data(),
                       Throttle_plausibility_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement1' */
  Precharge_status_Data() = Accelerator_B.raptor_override5;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement10' */
  Starter_button_Data() = Accelerator_B.raptor_override11;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement11' */
  Safety_loop_error_logic_Data() = rtb_Compare_c;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement12' */
  RTDS_Data() = Accelerator_B.raptor_override2_b;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement13' */
  Temp_adc_raw_Data() = Accelerator_B.raptor_override12;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement14' */
  Temp_resistance_Data() = Accelerator_B.raptor_override13;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement17' */
  Cooling_fault_any_Data() = Accelerator_B.raptor_override14;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement2' */
  Charge_mode_Data() = Accelerator_B.raptor_override6;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement20' */
  Starter_button_latch_q_naught_Data() = Accelerator_B.Logic;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement21' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status'
   */
  fault_tempSenseOC_Data() = (getFaultState(10, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement22' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status1'
   */
  fault_tempSenseSC_Data() = (getFaultState(11, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement23' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status2'
   */
  fault_tempSenseHigh_Data() = (getFaultState(9, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement24' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status3'
   */
  fault_eradic_temp_Data() = (getFaultState(7, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement25' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status4'
   */
  fault_lowFlowRate_Data() = (getFaultState(8, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement26' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S1>/raptor_fault_status5'
   */
  fault_eradicFlowRate_Data() = (getFaultState(6, (E_FaultState)
    FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement27' */
  Temp_actual_celsius_Data() = Accelerator_B.raptor_override18;

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Lookup_n-D: '<S1>/I: 0-80W O: DC'
   *  S-Function (sfix_look1_dyn): '<S1>/I: Temp. () O: Power (W)'
   */
  if (Accelerator_B.raptor_override10) {
    /* SignalConversion generated from: '<S1>/Vector Concatenate' incorporates:
     *  Constant: '<S1>/Constant7'
     */
    rtb_VectorConcatenate[3] = 300.0;

    /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment3' */
    rtb_VectorConcatenate[2] = (UpperFanPoint_Data());

    /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment2' */
    rtb_VectorConcatenate[1] = (LowerFanPoint_Data());

    /* SignalConversion generated from: '<S1>/Vector Concatenate' incorporates:
     *  Constant: '<S1>/F'
     */
    rtb_VectorConcatenate[0] = 0.0;

    /* S-Function (sfix_look1_dyn): '<S1>/I: Temp. () O: Power (W)' incorporates:
     *  Constant: '<S1>/Constant5'
     */
    /* Dynamic Look-Up Table Block: '<S1>/I: Temp. () O: Power (W)'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_ITempOPowerW),
                         Accelerator_ConstP.Constant5_Value,
                         Accelerator_B.raptor_override18,
                         &rtb_VectorConcatenate[0], 3U);
    rtb_DataTypeConversion4 = look1_binlxpw(rtb_ITempOPowerW,
      Accelerator_ConstP.I080WODC_bp01Data,
      Accelerator_ConstP.I080WODC_tableData, 16U);
  } else {
    rtb_DataTypeConversion4 = 100.0;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Gain: '<S1>/for 0.01% inc' */
  tmp = floorf(100.0 * rtb_DataTypeConversion4);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  rtb_for001inc1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(uint16_T)tmp);

  /* End of Gain: '<S1>/for 0.01% inc' */

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override21' */
  if (Fan_PWM_D_override_OvrSts_Data()) {
    Accelerator_B.raptor_override21 = Fan_PWM_D_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override21 = rtb_for001inc1;
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement28' */
  Fan_PWM_D_Data() = Accelerator_B.raptor_override21;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement29' */
  TSMS_logic_probe_Data() = rtb_Compare_f;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement30' */
  IMD_OkHs_probe_Data() = rtb_LogicalOperator3_g;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement31' */
  IMD_GLV_probe_Data() = Accelerator_B.raptor_override24;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement4' */
  RPM_val_Data() = Accelerator_B.raptor_override3;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement5' */
  TP_val_Data() = rtb_Switch;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement6' */
  APP1_Data() = Accelerator_B.raptor_override8;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement7' */
  APP2_Data() = Accelerator_B.raptor_override9;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement8' */
  Throttle_plausibility_probe_Data() = rtb_Compare_k;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement9' */
  Drive_enable_Data() = Accelerator_B.raptor_override10;

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment4' */
  rtb_ConvtoHz = (Fan_PWM_freq_Data());

  /* Gain: '<S1>/for 0.01% inc3' */
  rtb_Diff_a = 100U * rtb_ConvtoHz;

  /* S-Function (raptor_sfun_pwm_out): '<S1>/raptor_pwm_out' */
  /* S-Function Block: OUTPUT11 */
  {
    {
      static uint16_T lastDuty = 0;
      static uint32_T lastFreq = 0;
      if ((lastDuty != Accelerator_B.raptor_override21) || (lastFreq !=
           rtb_Diff_a)) {
        uint32_T uDuty = 32767;        /* 100% */
        if (Accelerator_B.raptor_override21 < 10000) {
          uDuty = (uint32_T)(((real32_T)Accelerator_B.raptor_override21) *
                             3.2767f);
        }

        swsh_PWMout_Period_Duty_ECUK057(100000000 /(rtb_Diff_a == 0 ? 1 :
          rtb_Diff_a), uDuty);
              /* freq is in 1/100 Hz, period in uSec, duty is 0-100 [0-32767] */
        lastDuty = Accelerator_B.raptor_override21;
        lastFreq = rtb_Diff_a;
      }
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S17>/raptor_adjustment2' */
  rtb_DataTypeConversion4 = (POT1_InputHighThresh_Data());

  /* RelationalOperator: '<S17>/Relational Operator1' */
  rtb_LogicalOperator3_g = (Accelerator_B.u1_n > rtb_DataTypeConversion4);

  /* S-Function (raptor_sfun_fault_def): '<S17>/raptor_fault_def' */

  /* Fault Reference : POT1_InputHi */
  {
    {
      updateFaultInput(1, rtb_LogicalOperator3_g, POT1_InputHi_X_Limit_Data(),
                       POT1_InputHi_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S17>/raptor_adjustment3' */
  rtb_DataTypeConversion4 = (POT1_InputLowThresh_Data());

  /* RelationalOperator: '<S17>/Relational Operator' */
  rtb_LogicalOperator3_g = (Accelerator_B.u1_n < rtb_DataTypeConversion4);

  /* S-Function (raptor_sfun_fault_def): '<S17>/raptor_fault_def1' */

  /* Fault Reference : POT1_InputLow */
  {
    {
      updateFaultInput(2, rtb_LogicalOperator3_g, POT1_InputLow_X_Limit_Data(),
                       POT1_InputLow_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S17>/raptor_measurement' */
  POT1HighProbe_Data() = Accelerator_B.u1_d;

  /* S-Function (raptor_sfun_measurement): '<S17>/raptor_measurement1' */
  POT1LowProbe_Data() = Accelerator_B.u1_g;

  /* S-Function (raptor_sfun_measurement): '<S17>/raptor_measurement2' */
  POT1_ADC_Raw_Data() = rtb_raptor_analog_in;

  /* S-Function (raptor_sfun_adjustment): '<S18>/raptor_adjustment2' */
  rtb_DataTypeConversion4 = (POT2_InputHighThresh_Data());

  /* RelationalOperator: '<S18>/Relational Operator1' */
  rtb_LogicalOperator3_g = (Accelerator_B.u1_l > rtb_DataTypeConversion4);

  /* S-Function (raptor_sfun_fault_def): '<S18>/raptor_fault_def' */

  /* Fault Reference : POT2_InputHi */
  {
    {
      updateFaultInput(3, rtb_LogicalOperator3_g, POT2_InputHi_X_Limit_Data(),
                       POT2_InputHi_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S18>/raptor_adjustment3' */
  rtb_DataTypeConversion4 = (POT2_InputLowThresh_Data());

  /* RelationalOperator: '<S18>/Relational Operator' */
  rtb_LogicalOperator3_g = (Accelerator_B.u1_l < rtb_DataTypeConversion4);

  /* S-Function (raptor_sfun_fault_def): '<S18>/raptor_fault_def1' */

  /* Fault Reference : POT2_InputLow */
  {
    {
      updateFaultInput(4, rtb_LogicalOperator3_g, POT2_InputLow_X_Limit_Data(),
                       POT2_InputLow_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S18>/raptor_measurement' */
  POT2HighProbe_Data() = Accelerator_B.u1_a;

  /* S-Function (raptor_sfun_measurement): '<S18>/raptor_measurement1' */
  POT2LowProbe_Data() = Accelerator_B.u1_p;

  /* S-Function (raptor_sfun_measurement): '<S18>/raptor_measurement2' */
  POT2_ADC_Raw_Data() = rtb_raptor_analog_in1;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant1'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_ITempOPowerW = Accelerator_DWork.UnitDelay_DSTATE + 1.0;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement3' */
  Counter_Data() = rtb_ITempOPowerW;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in5' */
  /* S-Function Block: INPUT26 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK045();
      rtb_raptor_analog_in5 = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override7' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in5'
   */
  if (GLV_hall_out_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override7 = GLV_hall_out_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override7 = rtb_raptor_analog_in5;
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement15' */
  GLV_hall_adc_Data() = Accelerator_B.raptor_override7;

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Product: '<S1>/Divide1'
   *  Sum: '<S1>/Sum'
   */
  rtb_Switch = ((real_T)Accelerator_B.raptor_override7 - 2047.0) / 2047.0 * 50.0;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement16' */
  GLV_hall_amp_Data() = rtb_Switch;

  /* Gain: '<S1>/for 0.01% inc1' */
  rtb_for001inc1 = 0U;

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment1' */
  rtb_Diff_a = (Pump_PWM_freq_Data());

  /* Gain: '<S1>/for 0.01% inc2' */
  rtb_ConvtoHz = 100U * rtb_Diff_a;

  /* S-Function (raptor_sfun_pwm_out): '<S1>/raptor_pwm_out1' */
  /* S-Function Block: OUTPUT7 */
  {
    {
      static uint16_T lastDuty = 0;
      static uint32_T lastFreq = 0;
      if ((lastDuty != rtb_for001inc1) || (lastFreq != rtb_ConvtoHz)) {
        uint32_T uDuty = 32767;        /* 100% */
        if (rtb_for001inc1 < 10000) {
          uDuty = (uint32_T)(((real32_T)rtb_for001inc1) * 3.2767f);
        }

        swsh_PWMout_Period_Duty_ECUK084(100000000 /(rtb_ConvtoHz == 0 ? 1 :
          rtb_ConvtoHz), uDuty);
              /* freq is in 1/100 Hz, period in uSec, duty is 0-100 [0-32767] */
        lastDuty = rtb_for001inc1;
        lastFreq = rtb_ConvtoHz;
      }
    }
  }

  /* S-Function (raptor_sfun_freq_in): '<S1>/raptor_freq_in' */
  /* S-Function Block: INPUT43 */
  {
    uint32 freq_temp = 0;
    uint32 duty_temp = 0;
    if (swsh_PWMin_Period_Duty_ECUK029((uint32*) &freq_temp, (uint32*)
         &duty_temp)) {
      if (freq_temp > 0) {
        real32_T freqHz = 1000000;
        freqHz /= freq_temp;
        freqHz *= 100;
        rtb_Diff_a = freqHz;
      } else {
        rtb_Diff_a = 0;
      }
    } else {
      rtb_Diff_a = 0;
    }
  }

  /* Gain: '<S1>/Conv. to Hz' */
  rtb_ConvtoHz = mul_u32_hiSR_near(2748779069U, rtb_Diff_a, 6U);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override20' */
  if (Flowrate_hz_corrected_override_OvrSts_Data()) {
    Accelerator_B.raptor_override20 = Flowrate_hz_corrected_override_OvrVal_Data
      ();
  } else {
    Accelerator_B.raptor_override20 = rtb_ConvtoHz;
  }

  /* Lookup_n-D: '<S1>/Q (L//H) vs. F (Hz)' incorporates:
   *  S-Function (raptor_sfun_override): '<S1>/raptor_override20'
   */
  rtb_DataTypeConversion4 = look1_iu32td_binlcpw(Accelerator_B.raptor_override20,
    Accelerator_ConstP.QLHvsFHz_bp01Data, Accelerator_ConstP.QLHvsFHz_tableData,
    5U);

  /* Gain: '<S1>/Conv. to Hz1' */
  tmp = floorf(227.1 * rtb_DataTypeConversion4);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 4.2949673E+9F);
  }

  rtb_Diff_a = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;

  /* End of Gain: '<S1>/Conv. to Hz1' */

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override19' */
  if (Flow_rate_gpm_override_OvrSts_Data()) {
    Accelerator_B.raptor_override19 = Flow_rate_gpm_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override19 = rtb_Diff_a;
  }

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment6' */
  rtb_DataTypeConversion4 = (lowFlowRateFault_Data());

  /* RelationalOperator: '<S1>/Less Than2' */
  rtb_LogicalOperator3_g = (Accelerator_B.raptor_override19 <
    rtb_DataTypeConversion4);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def3' */

  /* Fault Reference : lowFlowRate */
  {
    {
      updateFaultInput(8, rtb_LogicalOperator3_g, lowFlowRate_X_Limit_Data(),
                       lowFlowRate_Y_Limit_Data(), 1);
    }
  }

  /* Sum: '<S13>/Diff' incorporates:
   *  UnitDelay: '<S13>/UD'
   */
  rtb_Diff_a = Accelerator_B.raptor_override19 - Accelerator_DWork.UD_DSTATE_p;

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment7' */
  rtb_DataTypeConversion4 = (eradicFlowRateFault_Data());

  /* RelationalOperator: '<S1>/GreaterThan3' */
  rtb_LogicalOperator3_g = (rtb_Diff_a > rtb_DataTypeConversion4);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def4' */

  /* Fault Reference : eradicFlow */
  {
    {
      updateFaultInput(6, rtb_LogicalOperator3_g, eradicFlow_X_Limit_Data(),
                       eradicFlow_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement18' */
  Flow_rate_freq_corrected_Data() = Accelerator_B.raptor_override20;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement19' */
  Flow_rate_gpm_Data() = Accelerator_B.raptor_override19;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in3' */
  /* S-Function Block: INPUT25 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK042();
      rtb_raptor_analog_in3 = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override4' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in3'
   */
  if (BMS_SOC_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override4 = BMS_SOC_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override4 = rtb_raptor_analog_in3;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' */
  /* MATLAB Function 'Foreground/MATLAB Function2': '<S16>:1' */
  /* '<S16>:1:2' */
  rtb_for001inc1 = (uint16_T)((int32_T)roundf((real32_T)((real_T)
    Accelerator_B.raptor_override4 / 4095.0)) * 100);

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement' */
  BMS_SOC_percent_Data() = rtb_for001inc1;

  /* Update for UnitDelay: '<S12>/UD' */
  Accelerator_DWork.UD_DSTATE = Accelerator_B.raptor_override18;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  Constant: '<S1>/Enable switch'
   */
  for (idxDelay = 0; idxDelay < 999; idxDelay++) {
    Accelerator_DWork.Delay_DSTATE[idxDelay] =
      Accelerator_DWork.Delay_DSTATE[idxDelay + 1];
  }

  Accelerator_DWork.Delay_DSTATE[999] = 1.0;

  /* End of Update for Delay: '<S1>/Delay' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  Accelerator_DWork.UnitDelay_DSTATE = rtb_ITempOPowerW;

  /* Update for UnitDelay: '<S13>/UD' */
  Accelerator_DWork.UD_DSTATE_p = Accelerator_B.raptor_override19;
}

/* Model step function */
void Accelerator_step(void)
{
  /* S-Function (raptor_sfun_target_def): '<Root>/raptor_target_def' */

  /*
   * New Eagle LLC 2011
   */
}

/* Model initialize function */
void Accelerator_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &Accelerator_B), 0,
                sizeof(BlockIO_Accelerator));

  {
    Accelerator_B.raptor_override8 = 0.0;
    Accelerator_B.raptor_override9 = 0.0;
    Accelerator_B.raptor_override18 = 0.0;
    Accelerator_B.raptor_override17 = 0.0;
    Accelerator_B.raptor_override15 = 0.0;
    Accelerator_B.raptor_override1 = 0.0;
    Accelerator_B.u1 = 0.0;
    Accelerator_B.u1_c = 0.0;
    Accelerator_B.raptor_override3 = 0.0;
    Accelerator_B.raptor_override16 = 0.0;
    Accelerator_B.raptor_override = 0.0;
    Accelerator_B.raptor_override13 = 0.0;
    Accelerator_B.sf_MATLABFunction_i.y = 0.0;
    Accelerator_B.sf_MATLABFunction_m.y = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Accelerator_DWork, 0,
                sizeof(D_Work_Accelerator));
  Accelerator_DWork.UD_DSTATE = 0.0;

  {
    int32_T i;
    for (i = 0; i < 1000; i++) {
      Accelerator_DWork.Delay_DSTATE[i] = 0.0;
    }
  }

  Accelerator_DWork.UnitDelay_DSTATE = 0.0;
  Accelerator_DWork.UnitDelay1_DSTATE = 0.0;
  Accelerator_DWork.UnitDelay_DSTATE_l = 0.0;
  Accelerator_DWork.UnitDelay_DSTATE_b = 0.0;

  /* Start for S-Function (raptor_sfun_xcp): '<S4>/raptor_xcp_update' */

  /* S-Function Block - Start: <S4>/raptor_xcp_update */
  {
    CAN1_XCP_CAN_PreStart(CAN1__XCP_BC_ID_Data(), CAN1__XCP_RX_ID_Data(),
                          CAN1__XCP_TX_ID_Data());
  }

  /* Start for S-Function (raptor_sfun_fault_manager): '<Root>/raptor_fault_manager' */

  /* Fault Manager */
  {
    initFaultManager();
  }

  Accelerator_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = ZERO_ZCSIG;
  Accelerator_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = POS_ZCSIG;
  Accelerator_PrevZCSigState.StoreEEPROM_Trig_ZCE = ZERO_ZCSIG;

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  Accelerator_Foreground_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  Accelerator_FunctionCallSubsystem_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S3>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<S3>/Background'
   */
  Accelerator_Background_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S3>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<Root>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */
  Accelerator_Foreground_Enable();

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  Accelerator_Foreground_Enable();

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' */

  /* Level2 S-Function Block: '<Root>/raptor_app_trigger' (raptor_sfun_app_trigger) */

  /* Enable Subsystem */
  Accelerator_FunctionCallSubsystem_Enable();

  /* End of Enable for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' */

  /* Enable for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  Accelerator_FunctionCallSubsystem_Enable();

  /* End of Enable for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<S3>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<S3>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<S3>/raptor_timed_trigger' */
}

/* Model terminate function */
void Accelerator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
