/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator.c
 *
 * Code generated for Simulink model 'Accelerator'.
 *
 * Model version                  : 8.79
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 22 19:52:38 2024
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

/* System initialize for function-call system: '<S3>/Background' */
void Accelerator_Background_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_in): '<S27>/raptor_digital_in' */

  /* S-Function Block: WAKE_INPUT1 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S27>/raptor_digital_out' */

  /* S-Function Block: POWER_HOLD */
  {
  }

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S28>/raptor_delta_time' */
  Accelerator_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay2' */
  Accelerator_DWork.UnitDelay2_DSTATE = true;
}

/* System reset for function-call system: '<S3>/Background' */
void Accelerator_Background_Reset(void)
{
  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S28>/raptor_delta_time' */
  Accelerator_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay2' */
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

  /* S-Function (raptor_sfun_digital_in): '<S27>/raptor_digital_in' */
  /* S-Function Block: WAKE_INPUT1 */
  {
    rtb_raptor_digital_in = swsh_ignswSt();
  }

  /* S-Function (raptor_sfun_delta_time): '<S28>/raptor_delta_time' */
  {
    rtb_raptor_delta_time = (GetDeltaTime_ms
      (&Accelerator_DWork.raptor_delta_time_DWORK1) * 0.001f);
  }

  /* MultiPortSwitch: '<S28>/Multiport Switch1' incorporates:
   *  Constant: '<S28>/Constant'
   *  RelationalOperator: '<S32>/FixPt Relational Operator'
   *  Sum: '<S28>/Add'
   *  UnitDelay: '<S28>/Unit Delay'
   *  UnitDelay: '<S32>/Delay Input1'
   */
  if (rtb_raptor_digital_in == Accelerator_DWork.DelayInput1_DSTATE_c) {
    rtb_MultiportSwitch1 = rtb_raptor_delta_time +
      Accelerator_DWork.UnitDelay_DSTATE_b;
  } else {
    rtb_MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S28>/Multiport Switch1' */
  /* UnitDelay: '<S28>/Unit Delay2' */
  rtb_raptor_sfun_nv_status = Accelerator_DWork.UnitDelay2_DSTATE;

  /* CombinatorialLogic: '<S28>/Logic' incorporates:
   *  Logic: '<S28>/Logical Operator1'
   *  Logic: '<S28>/Logical Operator2'
   *  Logic: '<S28>/Logical Operator3'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  S-Function (raptor_sfun_adjustment): '<S28>/raptor_adjustment3'
   *  S-Function (raptor_sfun_adjustment): '<S28>/raptor_adjustment4'
   */
  rtb_Logic = Accelerator_ConstP.Logic_table[((((uint32_T)(rtb_raptor_digital_in
    && (rtb_MultiportSwitch1 >= (KeySwHiTimeThr_Data()))) << 1) + (uint32_T)
    ((!rtb_raptor_digital_in) && (rtb_MultiportSwitch1 >= (KeySwLoTimeThr_Data()))))
    << 1) + rtb_raptor_sfun_nv_status];

  /* Logic: '<S27>/Logical Operator1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S27>/raptor_data_read1'
   */
  rtb_LogicalOperator1_h = (rtb_Logic || KeepModuleOn_Data());

  /* Outputs for Triggered SubSystem: '<S27>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S29>/Trigger'
   */
  if ((!rtb_LogicalOperator1_h) &&
      (Accelerator_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (raptor_sfun_data_write): '<S29>/raptor_data_write' incorporates:
     *  Constant: '<S29>/Constant'
     */
    FgndTasksStopped_Data() = true;

    /* S-Function (fcgen): '<S29>/Function-Call Generator' incorporates:
     *  SubSystem: '<S29>/raptor_shutdown'
     */
    /* S-Function (raptor_sfun_shutdown): '<S33>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Shutdown(void);
      App_Shutdown();
    }

    /* End of Outputs for S-Function (fcgen): '<S29>/Function-Call Generator' */
  }

  Accelerator_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE =
    rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S27>/Raise Shutdown Event' */
  /* Outputs for Enabled and Triggered SubSystem: '<S27>/Raise Startup Event' incorporates:
   *  EnablePort: '<S30>/Enable'
   *  TriggerPort: '<S30>/Trigger'
   */
  if (FgndTasksStopped_Data() && (rtb_LogicalOperator1_h &&
       (Accelerator_PrevZCSigState.RaiseStartupEvent_Trig_ZCE != POS_ZCSIG))) {
    /* S-Function (fcgen): '<S30>/Function-Call Generator' incorporates:
     *  SubSystem: '<S30>/raptor_startup'
     */
    /* S-Function (raptor_sfun_startup): '<S34>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Startup(void);
      App_Startup();
    }

    /* End of Outputs for S-Function (fcgen): '<S30>/Function-Call Generator' */
  }

  /* End of S-Function (raptor_sfun_data_read): '<S27>/raptor_data_read' */

  /* Outputs for Triggered SubSystem: '<S27>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S29>/Trigger'
   */
  Accelerator_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S27>/Raise Shutdown Event' */
  /* End of Outputs for SubSystem: '<S27>/Raise Startup Event' */

  /* UnitDelay: '<S27>/Unit Delay' */
  rtb_LogicalOperator2_c = Accelerator_DWork.UnitDelay_DSTATE_e;

  /* Outputs for Triggered SubSystem: '<S27>/Store EEPROM' incorporates:
   *  TriggerPort: '<S31>/Trigger'
   */
  if ((!Accelerator_DWork.UnitDelay_DSTATE_e) &&
      (Accelerator_PrevZCSigState.StoreEEPROM_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (fcgen): '<S31>/Function-Call Generator' incorporates:
     *  SubSystem: '<S31>/raptor_store_nv'
     */
    /* S-Function (raptor_sfun_store_nv): '<S35>/raptor_data_write' */
    /* S-Function Block */
    {
      App_EE_Store();
    }

    /* End of Outputs for S-Function (fcgen): '<S31>/Function-Call Generator' */
  }

  /* End of UnitDelay: '<S27>/Unit Delay' */
  Accelerator_PrevZCSigState.StoreEEPROM_Trig_ZCE = rtb_LogicalOperator2_c;

  /* End of Outputs for SubSystem: '<S27>/Store EEPROM' */

  /* S-Function (raptor_sfun_data_write): '<S27>/raptor_data_write' */
  KeySw_Bgnd_Data() = rtb_Logic;

  /* S-Function (raptor_sfun_nv_status): '<S27>/raptor_sfun_nv_status' */
  /* S-Function Block */
  {
    rtb_raptor_sfun_nv_status = (EEPROM_State_Data() == EE_STORE_IN_PROGESS);
  }

  /* Logic: '<S27>/Logical Operator2' incorporates:
   *  UnitDelay: '<S27>/Unit Delay1'
   */
  rtb_raptor_sfun_nv_status = (rtb_raptor_sfun_nv_status ||
    rtb_LogicalOperator1_h || Accelerator_DWork.UnitDelay1_DSTATE_f);

  /* S-Function (raptor_sfun_digital_out): '<S27>/raptor_digital_out' */
  /* S-Function Block: POWER_HOLD */
  {
    {
      if (rtb_raptor_sfun_nv_status && !swsh_ignswSt()) {
        SyC_WaitPostDrv();
      }
    }
  }

  /* Update for UnitDelay: '<S32>/Delay Input1' */
  Accelerator_DWork.DelayInput1_DSTATE_c = rtb_raptor_digital_in;

  /* Update for UnitDelay: '<S28>/Unit Delay' */
  Accelerator_DWork.UnitDelay_DSTATE_b = rtb_MultiportSwitch1;

  /* Update for UnitDelay: '<S28>/Unit Delay2' */
  Accelerator_DWork.UnitDelay2_DSTATE = rtb_Logic;

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  Accelerator_DWork.UnitDelay_DSTATE_e = rtb_LogicalOperator1_h;

  /* Update for UnitDelay: '<S27>/Unit Delay1' */
  Accelerator_DWork.UnitDelay1_DSTATE_f = rtb_LogicalOperator2_c;
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_FunctionCallSubsystem_Init(void)
{
  /* Start for If: '<S2>/If' */
  Accelerator_DWork.If_ActiveSubsystem = -1;
}

/* Disable for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_FunctionCallSubsystem_Disable(void)
{
  /* Disable for If: '<S2>/If' */
  if (Accelerator_DWork.If_ActiveSubsystem == 0) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S26>/raptor_can_txmsg' incorporates:
     *  Constant: '<S26>/Constant'
     */
    /* Level2 S-Function Block: '<S26>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_1917__0001(0);
  }

  Accelerator_DWork.If_ActiveSubsystem = -1;

  /* End of Disable for If: '<S2>/If' */
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_FunctionCallSubsystem(void)
{
  real_T rtb_DataTypeConversion3;
  uint32_T rtb_raptor_time;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S25>/Compare'
   *  S-Function (raptor_sfun_data_read): '<S2>/raptor_data_read'
   */
  rtPrevAction = Accelerator_DWork.If_ActiveSubsystem;
  rtAction = -1;
  if (AbsoluteTime_Data() >= 5.0) {
    rtAction = 0;
  }

  Accelerator_DWork.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S26>/raptor_can_txmsg' incorporates:
     *  Constant: '<S26>/Constant'
     */
    /* Level2 S-Function Block: '<S26>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_1917__0001(0);
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* Enable for If: '<S2>/If' incorporates:
       *  Constant: '<S26>/Constant'
       *  S-Function (raptor_sfun_can_txmsg): '<S26>/raptor_can_txmsg'
       */
      /* Level2 S-Function Block: '<S26>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
      can_set_period_1917__0001(0U);

      /* End of Enable for SubSystem: '<S2>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* S-Function (raptor_sfun_can_txmsg): '<S26>/raptor_can_txmsg' incorporates:
     *  Constant: '<S26>/Constant'
     */

    /* S-Function Block:<S26>/raptor_can_txmsg */
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
      can_set_period_1917__0001(0U);
      can_send_1917__0001(192U & 0x7FF, 0, 8U, &data[0]);
    }

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  }

  /* End of If: '<S2>/If' */

  /* S-Function (raptor_sfun_time): '<S2>/raptor_time' */
  rtb_raptor_time = ticks();

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  rtb_DataTypeConversion3 = rtb_raptor_time;

  /* S-Function (raptor_sfun_data_write): '<S2>/raptor_data_write' */
  AbsoluteTime_Data() = rtb_DataTypeConversion3;
}

/*
 * Output and update for atomic system:
 *    '<S15>/MATLAB Function'
 *    '<S16>/MATLAB Function'
 */
void Accelerator_MATLABFunction(real_T rtu_a, real_T rtu_b, real_T rtu_c,
  rtB_MATLABFunction_Accelerator *localB)
{
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S20>:1' */
  /* '<S20>:1:2' */
  localB->y = (rtu_a - rtu_c) / (rtu_b - rtu_c);
}

/* System initialize for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground_Init(void)
{
  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in4' */

  /* S-Function Block: INPUT21 */
  {
  }

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

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in5' */

  /* S-Function Block: INPUT26 */
  {
  }

  /* Start for S-Function (raptor_sfun_pwm_out): '<S1>/raptor_pwm_out' */

  /* S-Function Block: OUTPUT11 */
  {
  }

  /* Start for S-Function (raptor_sfun_freq_in): '<S1>/raptor_freq_in' */

  /* S-Function Block: INPUT43 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in3' */

  /* S-Function Block: INPUT24 */
  {
  }
}

/* Enable for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_1396__0001(0U);
}

/* Disable for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground_Disable(void)
{
  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_1396__0001(0);
}

/* Output and update for function-call system: '<Root>/Foreground' */
void Accelerator_Foreground(void)
{
  /* local block i/o variables */
  uint16_T rtb_raptor_analog_in4;
  uint16_T rtb_raptor_analog_in2;
  uint16_T rtb_raptor_analog_in5;
  uint16_T rtb_raptor_analog_in3;
  uint16_T rtb_raptor_analog_in;
  uint16_T rtb_raptor_analog_in1;
  boolean_T rtb_Compare_c;
  boolean_T rtb_GreaterThan3;
  real_T rtb_VectorConcatenate[4];
  real_T rtb_DataTypeConversion4;
  real_T rtb_IRkOhmOTC;
  real_T rtb_Switch;
  real_T rtb_raptor_adjustment7;
  real_T tmp;
  uint32_T rtb_ConvtoHz;
  uint32_T rtb_Diff_a;
  uint16_T rtb_for001inc;
  uint8_T rtb_FixPtRelationalOperator_g;
  boolean_T rtb_GreaterThan1;
  boolean_T rtb_LogicalOperator3_g;

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
  if (Temp_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override12 = Temp_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override12 = rtb_raptor_analog_in4;
  }

  /* Product: '<S1>/Product3' incorporates:
   *  Constant: '<S1>/ADC_corrected'
   */
  rtb_Switch = (real_T)Accelerator_B.raptor_override12 * 0.00122100122;

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/PU (Ohms)'
   *  Constant: '<S1>/Vs (V)'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add2'
   */
  rtb_Switch = rtb_Switch * 2145.0 / (5.0 - rtb_Switch);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override13' */
  if (Temp_resistance_override_OvrSts_Data()) {
    Accelerator_B.raptor_override13 = Temp_resistance_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override13 = rtb_Switch;
  }

  /* Lookup_n-D: '<S1>/I: R (kOhm) O: T (C)' incorporates:
   *  S-Function (raptor_sfun_override): '<S1>/raptor_override13'
   */
  rtb_IRkOhmOTC = look1_binlxpw(Accelerator_B.raptor_override13,
    Accelerator_ConstP.IRkOhmOTC_bp01Data,
    Accelerator_ConstP.IRkOhmOTC_tableData, 24U);

  /* RelationalOperator: '<S1>/GreaterThan1' incorporates:
   *  S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment5'
   *  Sum: '<S10>/Diff'
   *  UnitDelay: '<S10>/UD'
   */
  rtb_GreaterThan1 = (rtb_IRkOhmOTC - Accelerator_DWork.UD_DSTATE >
                      (tempRateFault_Data()));

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
  rtb_GreaterThan1 = (rtb_Switch > 100.0);

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
  rtb_GreaterThan1 = (rtb_Switch < 0.1);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def2' */

  /* Fault Reference : tempSenseSC */
  {
    {
      updateFaultInput(11, rtb_GreaterThan1, tempSenseSC_X_Limit_Data(),
                       tempSenseSC_Y_Limit_Data(), 0);
    }
  }

  /* RelationalOperator: '<S1>/GreaterThan4' incorporates:
   *  Constant: '<S1>/100 C'
   */
  rtb_GreaterThan1 = (rtb_IRkOhmOTC > 80.0);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def5' */

  /* Fault Reference : tempHigh */
  {
    {
      updateFaultInput(9, rtb_GreaterThan1, tempHigh_X_Limit_Data(),
                       tempHigh_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement13' */
  Temp_raw_Data() = Accelerator_B.raptor_override12;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement14' */
  Temp_resistance_Data() = Accelerator_B.raptor_override13;

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  if (Direction_cmd_override_OvrSts_Data()) {
    Accelerator_B.raptor_override1 = Direction_cmd_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override1 = 0.0;
  }

  /* S-Function (raptor_sfun_override): '<S15>/raptor_override2' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S15>/raptor_fault_status'
   */
  if (POT1_InputHi_Override_OvrSts_Data()) {
    Accelerator_B.u1_d = POT1_InputHi_Override_OvrVal_Data();
  } else {
    Accelerator_B.u1_d = (getFaultState(1, (E_FaultState)FAULT_ACTIVE_MASK));
  }

  POT1_InputHi_Override_Data() = Accelerator_B.u1_d;

  /* S-Function (raptor_sfun_override): '<S15>/raptor_override3' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S15>/raptor_fault_status1'
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

  /* S-Function (raptor_sfun_override): '<S15>/raptor_override' */
  if (POT1_ADC_OvrSts_Data()) {
    Accelerator_B.u1_n = POT1_ADC_OvrVal_Data();
  } else {
    Accelerator_B.u1_n = rtb_raptor_analog_in;
  }

  POT1_ADC_Data() = Accelerator_B.u1_n;

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment1' */
  rtb_Switch = (POT1_ADCHiPT_Data());

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion1'
   */
  rtb_raptor_analog_in1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S15>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = rtb_raptor_analog_in1;

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment' */
  rtb_Switch = (POT1_ADCLoPT_Data());

  /* DataTypeConversion: '<S15>/Data Type Conversion2' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion2'
   */
  rtb_raptor_analog_in1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion3'
   *  DataTypeConversion: '<S15>/Data Type Conversion5'
   */
  Accelerator_MATLABFunction((real_T)Accelerator_B.u1_n, rtb_DataTypeConversion4,
    (real_T)rtb_raptor_analog_in1, &Accelerator_B.sf_MATLABFunction_m);

  /* MultiPortSwitch: '<S15>/Multiport Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Logic: '<S15>/Logical Operator'
   */
  if ((!Accelerator_B.u1_d) && (!Accelerator_B.u1_g)) {
    /* Saturate: '<S15>/Saturation' */
    if (Accelerator_B.sf_MATLABFunction_m.y > 100.0) {
      rtb_Switch = 100.0;
    } else if (Accelerator_B.sf_MATLABFunction_m.y < 0.0) {
      rtb_Switch = 0.0;
    } else {
      rtb_Switch = Accelerator_B.sf_MATLABFunction_m.y;
    }

    /* End of Saturate: '<S15>/Saturation' */
  } else {
    rtb_Switch = 0.0;
  }

  /* End of MultiPortSwitch: '<S15>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S15>/raptor_override1' */
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

  /* S-Function (raptor_sfun_override): '<S16>/raptor_override2' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S16>/raptor_fault_status'
   */
  if (POT2_InputHi_Override_OvrSts_Data()) {
    Accelerator_B.u1_a = POT2_InputHi_Override_OvrVal_Data();
  } else {
    Accelerator_B.u1_a = (getFaultState(3, (E_FaultState)FAULT_ACTIVE_MASK));
  }

  POT2_InputHi_Override_Data() = Accelerator_B.u1_a;

  /* S-Function (raptor_sfun_override): '<S16>/raptor_override3' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S16>/raptor_fault_status1'
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

  /* S-Function (raptor_sfun_override): '<S16>/raptor_override' */
  if (POT2_ADC_OvrSts_Data()) {
    Accelerator_B.u1_l = POT2_ADC_OvrVal_Data();
  } else {
    Accelerator_B.u1_l = rtb_raptor_analog_in1;
  }

  POT2_ADC_Data() = Accelerator_B.u1_l;

  /* S-Function (raptor_sfun_adjustment): '<S16>/raptor_adjustment1' */
  rtb_Switch = (POT2_ADCHiPT_Data());

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  rtb_for001inc = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S16>/Data Type Conversion1' */

  /* DataTypeConversion: '<S16>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = rtb_for001inc;

  /* S-Function (raptor_sfun_adjustment): '<S16>/raptor_adjustment' */
  rtb_Switch = (POT2_ADCLoPT_Data());

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  tmp = floorf(rtb_Switch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  rtb_for001inc = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S16>/Data Type Conversion2' */

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S16>/Data Type Conversion3'
   *  DataTypeConversion: '<S16>/Data Type Conversion5'
   */
  Accelerator_MATLABFunction((real_T)Accelerator_B.u1_l, rtb_DataTypeConversion4,
    (real_T)rtb_for001inc, &Accelerator_B.sf_MATLABFunction_i);

  /* MultiPortSwitch: '<S16>/Multiport Switch' incorporates:
   *  Constant: '<S16>/Constant'
   *  Logic: '<S16>/Logical Operator'
   */
  if ((!Accelerator_B.u1_a) && (!Accelerator_B.u1_p)) {
    /* Saturate: '<S16>/Saturation' */
    if (Accelerator_B.sf_MATLABFunction_i.y > 100.0) {
      rtb_Switch = 100.0;
    } else if (Accelerator_B.sf_MATLABFunction_i.y < 0.0) {
      rtb_Switch = 0.0;
    } else {
      rtb_Switch = Accelerator_B.sf_MATLABFunction_i.y;
    }

    /* End of Saturate: '<S16>/Saturation' */
  } else {
    rtb_Switch = 0.0;
  }

  /* End of MultiPortSwitch: '<S16>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S16>/raptor_override1' */
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
   *  SignalConversion generated from: '<S12>/ SFunction '
   */
  /* MATLAB Function 'Foreground/MATLAB Function': '<S12>:1' */
  /* '<S12>:1:2' */
  rtb_GreaterThan1 = (fabsf((real32_T)(Accelerator_B.raptor_override9 -
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

  /* Outputs for Enabled SubSystem: '<S9>/D Latch' incorporates:
   *  EnablePort: '<S19>/C'
   */
  /* Logic: '<S1>/Logical Operator' */
  if (Accelerator_B.raptor_override_b == rtb_Compare_c) {
    /* SignalConversion generated from: '<S19>/D' */
    Accelerator_B.D = Accelerator_B.raptor_override_b;
  }

  /* End of Logic: '<S1>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S9>/D Latch' */

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override11' */
  if (Starter_button_override_OvrSts_Data()) {
    Accelerator_B.raptor_override11 = Starter_button_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override11 = Accelerator_B.D;
  }

  /* S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in1' */
  /* S-Function Block: INPUT35 */
  {
    rtb_GreaterThan3 = swsh_DIO_in_ECUK049();
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override5' */
  if (Precharge_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override5 = Precharge_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override5 = rtb_GreaterThan3;
  }

  /* S-Function (raptor_sfun_digital_in): '<S1>/raptor_digital_in2' */
  /* S-Function Block: INPUT34 */
  {
    rtb_GreaterThan3 = swsh_DIO_in_ECUK047();
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override6' */
  if (Charge_mode_raw_override_OvrSts_Data()) {
    Accelerator_B.raptor_override6 = Charge_mode_raw_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override6 = rtb_GreaterThan3;
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
   */
  rtb_LogicalOperator3_g = (rtb_GreaterThan1 && Accelerator_B.raptor_override11 &&
    Accelerator_B.raptor_override5 && (!Accelerator_B.raptor_override6) &&
    Accelerator_B.raptor_override14);

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
   *  SignalConversion generated from: '<S12>/ SFunction '
   */
  /* MATLAB Function 'Foreground/MATLAB Function1': '<S13>:1' */
  /* '<S13>:1:2' */
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
    can_get_1619__0001(NULL, NULL, NULL, &data[0], 8);

    /* Signal: D2_Motor_Speed */
    temp = 0;
    temp |= ((uint32_T)data[2U]) ;
    temp |= ((uint32_T)data[3U]) << 8;
    if (temp & 32768)
      temp |= (uint32_T)-65536;
    rtb_raptor_adjustment7 = (((real_T) ((int32_T) temp) ) );
  }

  /* Abs: '<S1>/Abs' */
  rtb_raptor_adjustment7 = fabsf((real32_T)rtb_raptor_adjustment7);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override3' */
  if (RPM_override_OvrSts_Data()) {
    Accelerator_B.raptor_override3 = RPM_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override3 = rtb_raptor_adjustment7;
  }

  /* S-Function (raptor_sfun_table_axis): '<S18>/raptor_table_axis' */
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

  /* S-Function (raptor_sfun_table_interpolate_1d): '<S18>/raptor_table_interpolate_1d' */
  {
    rtb_raptor_adjustment7 = TableInterpolate1D_real32_T
      ( Accelerator_B.raptor_table_axis, MaxTorqueMap_Data(), 33u);
    MaxTorqueMap_Y_IN_IDX_Data() = Accelerator_B.raptor_table_axis;
  }

  /* Gain: '<S5>/Safety factor' incorporates:
   *  Product: '<S5>/Product'
   */
  rtb_raptor_adjustment7 = rtb_Switch * rtb_raptor_adjustment7 * 0.9;

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override16' */
  if (Torque_map_val_override_OvrSts_Data()) {
    Accelerator_B.raptor_override16 = Torque_map_val_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override16 = rtb_raptor_adjustment7;
  }

  /* Saturate: '<S6>/Saturation' */
  if (Accelerator_B.raptor_override16 > 3276.0) {
    rtb_raptor_adjustment7 = 3276.0;
  } else if (Accelerator_B.raptor_override16 < 0.0) {
    rtb_raptor_adjustment7 = 0.0;
  } else {
    rtb_raptor_adjustment7 = Accelerator_B.raptor_override16;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override' */
  if (Torque_cmd_override_OvrSts_Data()) {
    Accelerator_B.raptor_override = Torque_cmd_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override = rtb_raptor_adjustment7;
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
    can_set_period_1396__0001(0U);
    can_send_1396__0001(192U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement' */
  Torque_cmd_Data() = Accelerator_B.raptor_override;

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement1' */
  Direction_cmd_Data() = Accelerator_B.raptor_override1;

  /* Outputs for Atomic SubSystem: '<S1>/Triggered Single Pulse' */
  /* RelationalOperator: '<S22>/FixPt Relational Operator' incorporates:
   *  RelationalOperator: '<S24>/Compare'
   *  UnitDelay: '<S22>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_g = (uint8_T)((int32_T)
    Accelerator_B.raptor_override10 > Accelerator_DWork.DelayInput1_DSTATE);

  /* UnitDelay: '<S17>/Unit Delay1' */
  rtb_raptor_adjustment7 = Accelerator_DWork.UnitDelay1_DSTATE;

  /* Saturate: '<S17>/Saturation' */
  if (rtb_raptor_adjustment7 > 1.0) {
    rtb_raptor_adjustment7 = 1.0;
  } else if (rtb_raptor_adjustment7 < 0.0) {
    rtb_raptor_adjustment7 = 0.0;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* RelationalOperator: '<S1>/GreaterThan3' incorporates:
   *  Constant: '<S23>/Constant'
   *  Logic: '<S17>/Logical Operator'
   *  RelationalOperator: '<S23>/Compare'
   *  UnitDelay: '<S17>/Unit Delay'
   */
  rtb_GreaterThan3 = !(Accelerator_DWork.UnitDelay_DSTATE_l > 4.0);

  /* Product: '<S17>/Product3' */
  rtb_DataTypeConversion4 = rtb_raptor_adjustment7 * (real_T)rtb_GreaterThan3;

  /* Update for UnitDelay: '<S22>/Delay Input1' incorporates:
   *  RelationalOperator: '<S24>/Compare'
   */
  Accelerator_DWork.DelayInput1_DSTATE = Accelerator_B.raptor_override10;

  /* Update for UnitDelay: '<S17>/Unit Delay1' incorporates:
   *  Sum: '<S17>/Add1'
   */
  Accelerator_DWork.UnitDelay1_DSTATE = rtb_DataTypeConversion4 + (real_T)
    rtb_FixPtRelationalOperator_g;

  /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
   *  Product: '<S17>/Product'
   *  Product: '<S17>/Product1'
   *  Sum: '<S17>/Add'
   */
  Accelerator_DWork.UnitDelay_DSTATE_l = (rtb_DataTypeConversion4 +
    Accelerator_DWork.UnitDelay_DSTATE_l) * rtb_DataTypeConversion4;

  /* End of Outputs for SubSystem: '<S1>/Triggered Single Pulse' */

  /* RelationalOperator: '<S1>/GreaterThan3' incorporates:
   *  DataTypeConversion: '<S1>/Cast To Boolean'
   */
  rtb_GreaterThan3 = (rtb_DataTypeConversion4 != 0.0);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override2' */
  if (RTDS_override_OvrSts_Data()) {
    Accelerator_B.raptor_override2_b = RTDS_override_OvrVal_Data();
  } else {
    Accelerator_B.raptor_override2_b = rtb_GreaterThan3;
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

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def6' */

  /* Fault Reference : Throttle_plausibility */
  {
    {
      updateFaultInput(5, rtb_GreaterThan1, Throttle_plausibility_X_Limit_Data(),
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

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement17' */
  Cooling_fault_any_Data() = Accelerator_B.raptor_override14;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement2' */
  Charge_mode_Data() = Accelerator_B.raptor_override6;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement4' */
  RPM_val_Data() = Accelerator_B.raptor_override3;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement5' */
  TP_val_Data() = rtb_Switch;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement6' */
  APP1_Data() = Accelerator_B.raptor_override8;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement7' */
  APP2_Data() = Accelerator_B.raptor_override9;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement8' */
  Throttle_plausibility_probe_Data() = rtb_GreaterThan1;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement9' */
  Drive_enable_Data() = Accelerator_B.raptor_override10;

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment2' */
  rtb_raptor_adjustment7 = (POT1_InputHighThresh_Data());

  /* RelationalOperator: '<S1>/GreaterThan3' incorporates:
   *  RelationalOperator: '<S15>/Relational Operator1'
   */
  rtb_GreaterThan3 = (Accelerator_B.u1_n > rtb_raptor_adjustment7);

  /* S-Function (raptor_sfun_fault_def): '<S15>/raptor_fault_def' */

  /* Fault Reference : POT1_InputHi */
  {
    {
      updateFaultInput(1, rtb_GreaterThan3, POT1_InputHi_X_Limit_Data(),
                       POT1_InputHi_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S15>/raptor_adjustment3' */
  rtb_raptor_adjustment7 = (POT1_InputLowThresh_Data());

  /* RelationalOperator: '<S1>/GreaterThan3' incorporates:
   *  RelationalOperator: '<S15>/Relational Operator'
   */
  rtb_GreaterThan3 = (Accelerator_B.u1_n < rtb_raptor_adjustment7);

  /* S-Function (raptor_sfun_fault_def): '<S15>/raptor_fault_def1' */

  /* Fault Reference : POT1_InputLow */
  {
    {
      updateFaultInput(2, rtb_GreaterThan3, POT1_InputLow_X_Limit_Data(),
                       POT1_InputLow_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S15>/raptor_measurement' */
  POT1HighProbe_Data() = Accelerator_B.u1_d;

  /* S-Function (raptor_sfun_measurement): '<S15>/raptor_measurement1' */
  POT1LowProbe_Data() = Accelerator_B.u1_g;

  /* S-Function (raptor_sfun_measurement): '<S15>/raptor_measurement2' */
  POT1_ADC_Raw_Data() = rtb_raptor_analog_in;

  /* S-Function (raptor_sfun_adjustment): '<S16>/raptor_adjustment2' */
  rtb_raptor_adjustment7 = (POT2_InputHighThresh_Data());

  /* RelationalOperator: '<S1>/GreaterThan3' incorporates:
   *  RelationalOperator: '<S16>/Relational Operator1'
   */
  rtb_GreaterThan3 = (Accelerator_B.u1_l > rtb_raptor_adjustment7);

  /* S-Function (raptor_sfun_fault_def): '<S16>/raptor_fault_def' */

  /* Fault Reference : POT2_InputHi */
  {
    {
      updateFaultInput(3, rtb_GreaterThan3, POT2_InputHi_X_Limit_Data(),
                       POT2_InputHi_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S16>/raptor_adjustment3' */
  rtb_raptor_adjustment7 = (POT2_InputLowThresh_Data());

  /* RelationalOperator: '<S1>/GreaterThan3' incorporates:
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  rtb_GreaterThan3 = (Accelerator_B.u1_l < rtb_raptor_adjustment7);

  /* S-Function (raptor_sfun_fault_def): '<S16>/raptor_fault_def1' */

  /* Fault Reference : POT2_InputLow */
  {
    {
      updateFaultInput(4, rtb_GreaterThan3, POT2_InputLow_X_Limit_Data(),
                       POT2_InputLow_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S16>/raptor_measurement' */
  POT2HighProbe_Data() = Accelerator_B.u1_a;

  /* S-Function (raptor_sfun_measurement): '<S16>/raptor_measurement1' */
  POT2LowProbe_Data() = Accelerator_B.u1_p;

  /* S-Function (raptor_sfun_measurement): '<S16>/raptor_measurement2' */
  POT2_ADC_Raw_Data() = rtb_raptor_analog_in1;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant1'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Switch = Accelerator_DWork.UnitDelay_DSTATE + 1.0;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement3' */
  Counter_Data() = rtb_Switch;

  /* SignalConversion generated from: '<S1>/Vector Concatenate' incorporates:
   *  Constant: '<S1>/F'
   */
  rtb_VectorConcatenate[0] = 0.0;

  /* SignalConversion generated from: '<S1>/Vector Concatenate' incorporates:
   *  Constant: '<S1>/Constant7'
   */
  rtb_VectorConcatenate[3] = 300.0;

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment2' */
  rtb_VectorConcatenate[1] = (LowerFanPoint_Data());

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment3' */
  rtb_VectorConcatenate[2] = (UpperFanPoint_Data());

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
  rtb_raptor_adjustment7 = ((real_T)Accelerator_B.raptor_override7 - 2047.0) /
    2047.0 * 50.0;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement16' */
  GLV_hall_amp_Data() = rtb_raptor_adjustment7;

  /* Gain: '<S1>/for 0.01% inc' */
  rtb_for001inc = 10000U;

  /* S-Function (raptor_sfun_pwm_out): '<S1>/raptor_pwm_out' incorporates:
   *  S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment4'
   */
  /* S-Function Block: OUTPUT11 */
  {
    {
      static uint16_T lastDuty = 0;
      static uint32_T lastFreq = 0;
      if ((lastDuty != rtb_for001inc) || (lastFreq != (FanFrequency_Data()))) {
        uint32_T uDuty = 32767;        /* 100% */
        if (rtb_for001inc < 10000) {
          uDuty = (uint32_T)(((real32_T)rtb_for001inc) * 3.2767f);
        }

        swsh_PWMout_Period_Duty_ECUK057(100000000 /((FanFrequency_Data()) == 0 ?
          1 : (FanFrequency_Data())), uDuty);
              /* freq is in 1/100 Hz, period in uSec, duty is 0-100 [0-32767] */
        lastDuty = rtb_for001inc;
        lastFreq = (FanFrequency_Data());
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
  rtb_ConvtoHz = 100U * rtb_Diff_a;

  /* Lookup_n-D: '<S1>/Q (L//H) vs. F (Hz)' incorporates:
   *  Gain: '<S1>/Conv. to Hz'
   */
  rtb_raptor_adjustment7 = look1_iu32td_binlcpw(rtb_ConvtoHz,
    Accelerator_ConstP.QLHvsFHz_bp01Data, Accelerator_ConstP.QLHvsFHz_tableData,
    5U);

  /* Gain: '<S1>/Conv. to Hz1' */
  tmp = floorf(227.1 * rtb_raptor_adjustment7);
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
  rtb_raptor_adjustment7 = (lowFlowRateFault_Data());

  /* RelationalOperator: '<S1>/GreaterThan3' incorporates:
   *  RelationalOperator: '<S1>/Less Than2'
   */
  rtb_GreaterThan3 = (Accelerator_B.raptor_override19 < rtb_raptor_adjustment7);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def3' */

  /* Fault Reference : lowFlowRate */
  {
    {
      updateFaultInput(8, rtb_GreaterThan3, lowFlowRate_X_Limit_Data(),
                       lowFlowRate_Y_Limit_Data(), 1);
    }
  }

  /* Sum: '<S11>/Diff' incorporates:
   *  UnitDelay: '<S11>/UD'
   */
  rtb_Diff_a = Accelerator_B.raptor_override19 - Accelerator_DWork.UD_DSTATE_p;

  /* S-Function (raptor_sfun_adjustment): '<S1>/raptor_adjustment7' */
  rtb_raptor_adjustment7 = (eradicFlowRateFault_Data());

  /* RelationalOperator: '<S1>/GreaterThan3' */
  rtb_GreaterThan3 = (rtb_Diff_a > rtb_raptor_adjustment7);

  /* S-Function (raptor_sfun_fault_def): '<S1>/raptor_fault_def4' */

  /* Fault Reference : eradicFlow */
  {
    {
      updateFaultInput(6, rtb_GreaterThan3, eradicFlow_X_Limit_Data(),
                       eradicFlow_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement18' */
  Flow_rate_freq_corrected_Data() = rtb_ConvtoHz;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement19' */
  Flow_rate_gpm_Data() = Accelerator_B.raptor_override19;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in3' */
  /* S-Function Block: INPUT24 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK035();
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

  /* Saturate: '<S1>/Saturation' */
  /* MATLAB Function 'Foreground/MATLAB Function2': '<S14>:1' */
  /* '<S14>:1:2' */
  if (Accelerator_B.raptor_override4 <= 4095) {
    rtb_for001inc = Accelerator_B.raptor_override4;
  } else {
    rtb_for001inc = 4095U;
  }

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  rtb_for001inc = (uint16_T)((int32_T)roundf((real32_T)((real_T)rtb_for001inc /
    4095.0)) * 100);

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement' */
  BMS_SOC_percent_Data() = rtb_for001inc;

  /* Update for UnitDelay: '<S10>/UD' */
  Accelerator_DWork.UD_DSTATE = rtb_IRkOhmOTC;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  Accelerator_DWork.UnitDelay_DSTATE = rtb_Switch;

  /* Update for UnitDelay: '<S11>/UD' */
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
    Accelerator_B.raptor_override17 = 0.0;
    Accelerator_B.raptor_override15 = 0.0;
    Accelerator_B.raptor_override13 = 0.0;
    Accelerator_B.raptor_override1 = 0.0;
    Accelerator_B.u1 = 0.0;
    Accelerator_B.u1_c = 0.0;
    Accelerator_B.raptor_override3 = 0.0;
    Accelerator_B.raptor_override16 = 0.0;
    Accelerator_B.raptor_override = 0.0;
    Accelerator_B.sf_MATLABFunction_i.y = 0.0;
    Accelerator_B.sf_MATLABFunction_m.y = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Accelerator_DWork, 0,
                sizeof(D_Work_Accelerator));
  Accelerator_DWork.UD_DSTATE = 0.0;
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
