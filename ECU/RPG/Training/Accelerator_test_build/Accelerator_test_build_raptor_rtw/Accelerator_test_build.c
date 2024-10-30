/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator_test_build.c
 *
 * Code generated for Simulink model 'Accelerator_test_build'.
 *
 * Model version                  : 8.120
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 19 15:40:22 2024
 *
 * Target selection: raptor.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Accelerator_test_build.h"
#include "Accelerator_test_build_private.h"
#include "rtwtypes.h"
#include "math.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_Accelerator_test_build Accelerator_test_build_B;

/* Block states (default storage) */
D_Work_Accelerator_test_build Accelerator_test_build_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_Accelerator_test_build Accelerator_test_build_PrevZCSigState;

// Block : Accelerator_test_build/raptor_timed_trigger
void Timer_ooqlV(void)
{
  /* Timer_ooqlV  ------   Foreground  */
  {
    {
      Accelerator_test_build_Foreground();
    }
  }
}

// Block : Accelerator_test_build/raptor_app_trigger
#define START_SECTION_Task_oem_r1ms
#include "swsh_rb2oem.h"

void AppTrigger_FGND_sMxs9(void)
{
  /* AppTrigger_FGND_sMxs9  ------   Startup  */
  {
    {
      Accelerator_test_build_FunctionCallSubsystem();
    }
  }
}

#define STOP_SECTION_Task_oem_r1ms
#include "swsh_rb2oem.h"

// Block : Accelerator_test_build/Power Up_Down/raptor_timed_trigger
void Timer_BGND_G6Wyo(void)
{
  /* Timer_BGND_G6Wyo  ------   Background  */
  {
    {
      Accelerator_test_build_Background();
    }
  }
}

/* System initialize for function-call system: '<S3>/Background' */
void Accelerator_test_build_Background_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_in): '<S12>/raptor_digital_in' */

  /* S-Function Block: WAKE_INPUT1 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S12>/raptor_digital_out' */

  /* S-Function Block: POWER_HOLD */
  {
  }

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S13>/raptor_delta_time' */
  Accelerator_test_build_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay2' */
  Accelerator_test_build_DWork.UnitDelay2_DSTATE = true;
}

/* System reset for function-call system: '<S3>/Background' */
void Accelerator_test_build_Background_Reset(void)
{
  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S13>/raptor_delta_time' */
  Accelerator_test_build_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay2' */
  Accelerator_test_build_DWork.UnitDelay2_DSTATE = true;
}

/* Output and update for function-call system: '<S3>/Background' */
void Accelerator_test_build_Background(void)
{
  /* local block i/o variables */
  real_T rtb_raptor_delta_time;
  boolean_T rtb_raptor_digital_in;
  real_T rtb_MultiportSwitch1;
  boolean_T rtb_Logic;
  boolean_T rtb_LogicalOperator1_h;
  boolean_T rtb_LogicalOperator2_c;
  boolean_T rtb_raptor_sfun_nv_status;

  /* S-Function (raptor_sfun_digital_in): '<S12>/raptor_digital_in' */
  /* S-Function Block: WAKE_INPUT1 */
  {
    rtb_raptor_digital_in = swsh_ignswSt();
  }

  /* S-Function (raptor_sfun_delta_time): '<S13>/raptor_delta_time' */
  {
    rtb_raptor_delta_time = (GetDeltaTime_ms
      (&Accelerator_test_build_DWork.raptor_delta_time_DWORK1) * 0.001f);
  }

  /* MultiPortSwitch: '<S13>/Multiport Switch1' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  Sum: '<S13>/Add'
   *  UnitDelay: '<S13>/Unit Delay'
   *  UnitDelay: '<S17>/Delay Input1'
   */
  if (rtb_raptor_digital_in == Accelerator_test_build_DWork.DelayInput1_DSTATE)
  {
    rtb_MultiportSwitch1 = rtb_raptor_delta_time +
      Accelerator_test_build_DWork.UnitDelay_DSTATE;
  } else {
    rtb_MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S13>/Multiport Switch1' */
  /* UnitDelay: '<S13>/Unit Delay2' */
  rtb_raptor_sfun_nv_status = Accelerator_test_build_DWork.UnitDelay2_DSTATE;

  /* CombinatorialLogic: '<S13>/Logic' incorporates:
   *  Logic: '<S13>/Logical Operator1'
   *  Logic: '<S13>/Logical Operator2'
   *  Logic: '<S13>/Logical Operator3'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  S-Function (raptor_sfun_adjustment): '<S13>/raptor_adjustment3'
   *  S-Function (raptor_sfun_adjustment): '<S13>/raptor_adjustment4'
   */
  rtb_Logic = Accelerator_test_build_ConstP.Logic_table[((((uint32_T)
    (rtb_raptor_digital_in && (rtb_MultiportSwitch1 >= (KeySwHiTimeThr_Data())))
    << 1) + (uint32_T)((!rtb_raptor_digital_in) && (rtb_MultiportSwitch1 >=
    (KeySwLoTimeThr_Data())))) << 1) + rtb_raptor_sfun_nv_status];

  /* Logic: '<S12>/Logical Operator1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S12>/raptor_data_read1'
   */
  rtb_LogicalOperator1_h = (rtb_Logic || KeepModuleOn_Data());

  /* Outputs for Triggered SubSystem: '<S12>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  if ((!rtb_LogicalOperator1_h) &&
      (Accelerator_test_build_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE !=
       ZERO_ZCSIG)) {
    /* S-Function (raptor_sfun_data_write): '<S14>/raptor_data_write' incorporates:
     *  Constant: '<S14>/Constant'
     */
    FgndTasksStopped_Data() = true;

    /* S-Function (fcgen): '<S14>/Function-Call Generator' incorporates:
     *  SubSystem: '<S14>/raptor_shutdown'
     */
    /* S-Function (raptor_sfun_shutdown): '<S18>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Shutdown(void);
      App_Shutdown();
    }

    /* End of Outputs for S-Function (fcgen): '<S14>/Function-Call Generator' */
  }

  Accelerator_test_build_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE =
    rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S12>/Raise Shutdown Event' */
  /* Outputs for Enabled and Triggered SubSystem: '<S12>/Raise Startup Event' incorporates:
   *  EnablePort: '<S15>/Enable'
   *  TriggerPort: '<S15>/Trigger'
   */
  if (FgndTasksStopped_Data() && (rtb_LogicalOperator1_h &&
       (Accelerator_test_build_PrevZCSigState.RaiseStartupEvent_Trig_ZCE !=
        POS_ZCSIG))) {
    /* S-Function (fcgen): '<S15>/Function-Call Generator' incorporates:
     *  SubSystem: '<S15>/raptor_startup'
     */
    /* S-Function (raptor_sfun_startup): '<S19>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Startup(void);
      App_Startup();
    }

    /* End of Outputs for S-Function (fcgen): '<S15>/Function-Call Generator' */
  }

  /* End of S-Function (raptor_sfun_data_read): '<S12>/raptor_data_read' */

  /* Outputs for Triggered SubSystem: '<S12>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  Accelerator_test_build_PrevZCSigState.RaiseStartupEvent_Trig_ZCE =
    rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S12>/Raise Shutdown Event' */
  /* End of Outputs for SubSystem: '<S12>/Raise Startup Event' */

  /* UnitDelay: '<S12>/Unit Delay' */
  rtb_LogicalOperator2_c = Accelerator_test_build_DWork.UnitDelay_DSTATE_e;

  /* Outputs for Triggered SubSystem: '<S12>/Store EEPROM' incorporates:
   *  TriggerPort: '<S16>/Trigger'
   */
  if ((!Accelerator_test_build_DWork.UnitDelay_DSTATE_e) &&
      (Accelerator_test_build_PrevZCSigState.StoreEEPROM_Trig_ZCE != ZERO_ZCSIG))
  {
    /* S-Function (fcgen): '<S16>/Function-Call Generator' incorporates:
     *  SubSystem: '<S16>/raptor_store_nv'
     */
    /* S-Function (raptor_sfun_store_nv): '<S20>/raptor_data_write' */
    /* S-Function Block */
    {
      App_EE_Store();
    }

    /* End of Outputs for S-Function (fcgen): '<S16>/Function-Call Generator' */
  }

  /* End of UnitDelay: '<S12>/Unit Delay' */
  Accelerator_test_build_PrevZCSigState.StoreEEPROM_Trig_ZCE =
    rtb_LogicalOperator2_c;

  /* End of Outputs for SubSystem: '<S12>/Store EEPROM' */

  /* S-Function (raptor_sfun_data_write): '<S12>/raptor_data_write' */
  KeySw_Bgnd_Data() = rtb_Logic;

  /* S-Function (raptor_sfun_nv_status): '<S12>/raptor_sfun_nv_status' */
  /* S-Function Block */
  {
    rtb_raptor_sfun_nv_status = (EEPROM_State_Data() == EE_STORE_IN_PROGESS);
  }

  /* Logic: '<S12>/Logical Operator2' incorporates:
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  rtb_raptor_sfun_nv_status = (rtb_raptor_sfun_nv_status ||
    rtb_LogicalOperator1_h || Accelerator_test_build_DWork.UnitDelay1_DSTATE);

  /* S-Function (raptor_sfun_digital_out): '<S12>/raptor_digital_out' */
  /* S-Function Block: POWER_HOLD */
  {
    {
      if (rtb_raptor_sfun_nv_status && !swsh_ignswSt()) {
        SyC_WaitPostDrv();
      }
    }
  }

  /* Update for UnitDelay: '<S17>/Delay Input1' */
  Accelerator_test_build_DWork.DelayInput1_DSTATE = rtb_raptor_digital_in;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  Accelerator_test_build_DWork.UnitDelay_DSTATE = rtb_MultiportSwitch1;

  /* Update for UnitDelay: '<S13>/Unit Delay2' */
  Accelerator_test_build_DWork.UnitDelay2_DSTATE = rtb_Logic;

  /* Update for UnitDelay: '<S12>/Unit Delay' */
  Accelerator_test_build_DWork.UnitDelay_DSTATE_e = rtb_LogicalOperator1_h;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  Accelerator_test_build_DWork.UnitDelay1_DSTATE = rtb_LogicalOperator2_c;
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_test_build_FunctionCallSubsystem_Init(void)
{
  /* Start for If: '<S2>/If' */
  Accelerator_test_build_DWork.If_ActiveSubsystem = -1;
}

/* Disable for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_test_build_FunctionCallSubsystem_Disable(void)
{
  /* Disable for If: '<S2>/If' */
  if (Accelerator_test_build_DWork.If_ActiveSubsystem == 0) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S11>/raptor_can_txmsg' incorporates:
     *  Constant: '<S11>/Constant'
     */
    /* Level2 S-Function Block: '<S11>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_773__0001(0);
  }

  Accelerator_test_build_DWork.If_ActiveSubsystem = -1;

  /* End of Disable for If: '<S2>/If' */
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_test_build_FunctionCallSubsystem(void)
{
  real_T rtb_DataTypeConversion3;
  uint32_T rtb_raptor_time;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   *  S-Function (raptor_sfun_data_read): '<S2>/raptor_data_read'
   */
  rtPrevAction = Accelerator_test_build_DWork.If_ActiveSubsystem;
  rtAction = -1;
  if (AbsoluteTime_Data() >= 5.0) {
    rtAction = 0;
  }

  Accelerator_test_build_DWork.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S11>/raptor_can_txmsg' incorporates:
     *  Constant: '<S11>/Constant'
     */
    /* Level2 S-Function Block: '<S11>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_773__0001(0);
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Enable for If: '<S2>/If' incorporates:
       *  Constant: '<S11>/Constant'
       *  S-Function (raptor_sfun_can_txmsg): '<S11>/raptor_can_txmsg'
       */
      /* Level2 S-Function Block: '<S11>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
      can_set_period_773__0001(0U);

      /* End of Enable for SubSystem: '<S2>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* S-Function (raptor_sfun_can_txmsg): '<S11>/raptor_can_txmsg' incorporates:
     *  Constant: '<S11>/Constant'
     */

    /* S-Function Block:<S11>/raptor_can_txmsg */
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
      can_set_period_773__0001(0U);
      can_send_773__0001(192U & 0x7FF, 0, 8U, &data[0]);
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

/* System initialize for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground_Init(void)
{
  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in' */

  /* S-Function Block: INPUT30 */
  {
  }
}

/* Enable for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_684__0001(10U);
}

/* Disable for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground_Disable(void)
{
  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_684__0001(0);
}

/* Output and update for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground(void)
{
  /* local block i/o variables */
  uint16_T rtb_raptor_analog_in;
  real_T rtb_raptor_adjustment3_k;
  real_T tmp;
  uint16_T rtb_DataTypeConversion2;
  boolean_T rtb_RelationalOperator_j;

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  if (Direction_cmd_override_OvrSts_Data()) {
    Accelerator_test_build_B.raptor_override1 =
      Direction_cmd_override_OvrVal_Data();
  } else {
    Accelerator_test_build_B.raptor_override1 = 0.0;
  }

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override2' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (Inverter_enb_override_OvrSts_Data()) {
    Accelerator_test_build_B.raptor_override2 =
      Inverter_enb_override_OvrVal_Data();
  } else {
    Accelerator_test_build_B.raptor_override2 = 1.0;
  }

  /* S-Function (raptor_sfun_override): '<S7>/raptor_override2' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S7>/raptor_fault_status'
   */
  if (POT1_InputHi_Override_OvrSts_Data()) {
    Accelerator_test_build_B.u1_n = POT1_InputHi_Override_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1_n = (getFaultState(1, (E_FaultState)
      FAULT_ACTIVE_MASK));
  }

  POT1_InputHi_Override_Data() = Accelerator_test_build_B.u1_n;

  /* S-Function (raptor_sfun_override): '<S7>/raptor_override3' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S7>/raptor_fault_status1'
   */
  if (POT1_InputLow_Override_OvrSts_Data()) {
    Accelerator_test_build_B.u1_k = POT1_InputLow_Override_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1_k = (getFaultState(2, (E_FaultState)
      FAULT_ACTIVE_MASK));
  }

  POT1_InputLow_Override_Data() = Accelerator_test_build_B.u1_k;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in' */
  /* S-Function Block: INPUT30 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK082();
      rtb_raptor_analog_in = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S7>/raptor_override' */
  if (POT1_ADC_OvrSts_Data()) {
    Accelerator_test_build_B.u1_c = POT1_ADC_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1_c = rtb_raptor_analog_in;
  }

  POT1_ADC_Data() = Accelerator_test_build_B.u1_c;

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment1' */
  rtb_raptor_adjustment3_k = (POT1_ADCHiPT_Data());

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  tmp = floorf(rtb_raptor_adjustment3_k);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment' */
  rtb_raptor_adjustment3_k = (POT1_ADCLoPT_Data());

  /* DataTypeConversion: '<S7>/Data Type Conversion2' */
  rtb_raptor_adjustment3_k = floorf(rtb_raptor_adjustment3_k);
  if (rtIsNaN(rtb_raptor_adjustment3_k) || rtIsInf(rtb_raptor_adjustment3_k)) {
    rtb_raptor_adjustment3_k = 0.0;
  } else {
    rtb_raptor_adjustment3_k = fmodf((real32_T)rtb_raptor_adjustment3_k,
      65536.0F);
  }

  rtb_DataTypeConversion2 = (uint16_T)(rtb_raptor_adjustment3_k < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-rtb_raptor_adjustment3_k : (int32_T)(uint16_T)
    rtb_raptor_adjustment3_k);

  /* End of DataTypeConversion: '<S7>/Data Type Conversion2' */

  /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Logic: '<S7>/Logical Operator'
   */
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S9>:1' */
  /* '<S9>:1:2' */
  if ((!Accelerator_test_build_B.u1_n) && (!Accelerator_test_build_B.u1_k)) {
    /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion1'
     *  DataTypeConversion: '<S7>/Data Type Conversion3'
     *  DataTypeConversion: '<S7>/Data Type Conversion5'
     */
    rtb_raptor_adjustment3_k = (real_T)(Accelerator_test_build_B.u1_c -
      rtb_DataTypeConversion2) / (real_T)((tmp < 0.0 ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp) -
      rtb_DataTypeConversion2);

    /* Saturate: '<S7>/Saturation' */
    if (rtb_raptor_adjustment3_k > 100.0) {
      rtb_raptor_adjustment3_k = 100.0;
    } else if (rtb_raptor_adjustment3_k < 0.0) {
      rtb_raptor_adjustment3_k = 0.0;
    }

    /* End of Saturate: '<S7>/Saturation' */
  } else {
    rtb_raptor_adjustment3_k = 0.0;
  }

  /* End of MultiPortSwitch: '<S7>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S7>/raptor_override1' */
  if (POT1_OvrSts_Data()) {
    Accelerator_test_build_B.u1 = POT1_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1 = rtb_raptor_adjustment3_k;
  }

  POT1_Data() = Accelerator_test_build_B.u1;

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override' */
  if (TP_override_OvrSts_Data()) {
    Accelerator_test_build_B.raptor_override = TP_override_OvrVal_Data();
  } else {
    Accelerator_test_build_B.raptor_override = Accelerator_test_build_B.u1;
  }

  /* S-Function (raptor_sfun_can_rxmsg): '<S1>/raptor_can_rxmsg' */

  /* S-Function Block:<S1>/raptor_can_rxmsg */
  {
    uint8_T data[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint32_T temp;
    can_get_719__0001(NULL, NULL, NULL, &data[0], 8);

    /* Signal: D2_Motor_Speed */
    temp = 0;
    temp |= ((uint32_T)data[2U]) ;
    temp |= ((uint32_T)data[3U]) << 8;
    if (temp & 32768)
      temp |= (uint32_T)-65536;
    rtb_raptor_adjustment3_k = (((real_T) ((int32_T) temp) ) );
  }

  /* Abs: '<S1>/Abs' */
  rtb_raptor_adjustment3_k = fabsf((real32_T)rtb_raptor_adjustment3_k);

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override1' */
  if (RPM_override_OvrSts_Data()) {
    Accelerator_test_build_B.raptor_override1_o = RPM_override_OvrVal_Data();
  } else {
    Accelerator_test_build_B.raptor_override1_o = rtb_raptor_adjustment3_k;
  }

  /* S-Function (raptor_sfun_table_axis): '<S8>/raptor_table_axis' */
  {
    int idx;
    for (idx=0;idx<1;idx++) {
      Accelerator_test_build_B.raptor_table_axis = TableAxis_real32_T
        ( Accelerator_test_build_B.raptor_override1_o, RPM_Data(), 33u,
         Accelerator_test_build_B.raptor_table_axis);
    }

    idx = 0;
    RPM_IN_Data() = Accelerator_test_build_B.raptor_override1_o;
  }

  /* S-Function (raptor_sfun_table_interpolate_1d): '<S8>/raptor_table_interpolate_1d' */
  {
    rtb_raptor_adjustment3_k = TableInterpolate1D_real32_T
      ( Accelerator_test_build_B.raptor_table_axis, MaxTorqueMap_Data(), 33u);
    MaxTorqueMap_Y_IN_IDX_Data() = Accelerator_test_build_B.raptor_table_axis;
  }

  /* Gain: '<S5>/Safety factor' incorporates:
   *  Product: '<S5>/Product'
   */
  rtb_raptor_adjustment3_k = Accelerator_test_build_B.raptor_override *
    rtb_raptor_adjustment3_k * 0.9;

  /* S-Function (raptor_sfun_override): '<S1>/raptor_override3' */
  if (Torque_map_val_override_OvrSts_Data()) {
    Accelerator_test_build_B.raptor_override3 =
      Torque_map_val_override_OvrVal_Data();
  } else {
    Accelerator_test_build_B.raptor_override3 = rtb_raptor_adjustment3_k;
  }

  /* Saturate: '<S6>/Saturation' */
  if (Accelerator_test_build_B.raptor_override3 > 3276.0) {
    rtb_raptor_adjustment3_k = 3276.0;
  } else if (Accelerator_test_build_B.raptor_override3 < 0.0) {
    rtb_raptor_adjustment3_k = 0.0;
  } else {
    rtb_raptor_adjustment3_k = Accelerator_test_build_B.raptor_override3;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override' */
  if (Torque_cmd_override_OvrSts_Data()) {
    Accelerator_test_build_B.raptor_override_f = Torque_cmd_override_OvrVal_Data
      ();
  } else {
    Accelerator_test_build_B.raptor_override_f = rtb_raptor_adjustment3_k;
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
    if (Accelerator_test_build_B.raptor_override1 < 0.0000000000F)
      temp = (uint32_T)0U;
    else if (Accelerator_test_build_B.raptor_override1 > 1.0000000000F)
      temp = (uint32_T)1U;
    else {
      if ((real_T)Accelerator_test_build_B.raptor_override1 < 0)
        temp = (uint32_T)(int32_T)((Accelerator_test_build_B.raptor_override1));
      else
        temp = (uint32_T)((Accelerator_test_build_B.raptor_override1));
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)1U);
    data[4U] |= temp_shift;

    /* Signal: Inverter_Enable   */
    /* Inverter_Enable   - StartBit: 40U, BitLength: 1U, Endian: 0U */

    /* signal type is unsigned */
    if (Accelerator_test_build_B.raptor_override2 < 0.0000000000F)
      temp = (uint32_T)0U;
    else if (Accelerator_test_build_B.raptor_override2 > 1.0000000000F)
      temp = (uint32_T)1U;
    else {
      if ((real_T)Accelerator_test_build_B.raptor_override2 < 0)
        temp = (uint32_T)(int32_T)((Accelerator_test_build_B.raptor_override2));
      else
        temp = (uint32_T)((Accelerator_test_build_B.raptor_override2));
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)1U);
    data[5U] |= temp_shift;

    /* Signal: Torque_Command    */
    /* Torque_Command    - StartBit: 0U, BitLength: 16U, Endian: 0U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)Accelerator_test_build_B.raptor_override_f < -3276.8)
        tempS = (int32_T)-32768.0;
      else if ((real_T)Accelerator_test_build_B.raptor_override_f >
               3276.7000000000003)
        tempS = (int32_T)32767.0;
      else if ((real_T)Accelerator_test_build_B.raptor_override_f < 0)
        tempS = (int32_T)(int32_T)((Accelerator_test_build_B.raptor_override_f) *
          10.0f);
      else
        tempS = (int32_T)((Accelerator_test_build_B.raptor_override_f) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[0U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[1U] |= temp_shift;
    can_set_period_684__0001(10U);
    can_send_periodic_684__0001(192U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement' */
  Torque_cmd_Data() = Accelerator_test_build_B.raptor_override_f;

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement1' */
  Direction_cmd_Data() = Accelerator_test_build_B.raptor_override1;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement' */
  TP_cmd_Data() = Accelerator_test_build_B.raptor_override;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement1' */
  RPM_val_Data() = Accelerator_test_build_B.raptor_override1_o;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement2' */
  Inverter_enb_Data() = Accelerator_test_build_B.raptor_override2;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement3' */
  Torque_map_val_Data() = Accelerator_test_build_B.raptor_override3;

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment2' */
  rtb_raptor_adjustment3_k = (POT1_InputHighThresh_Data());

  /* RelationalOperator: '<S7>/Relational Operator1' */
  rtb_RelationalOperator_j = (Accelerator_test_build_B.u1_c >
    rtb_raptor_adjustment3_k);

  /* S-Function (raptor_sfun_fault_def): '<S7>/raptor_fault_def' */

  /* Fault Reference : POT1_InputHi */
  {
    {
      updateFaultInput(1, rtb_RelationalOperator_j, POT1_InputHi_X_Limit_Data(),
                       POT1_InputHi_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment3' */
  rtb_raptor_adjustment3_k = (POT1_InputLowThresh_Data());

  /* RelationalOperator: '<S7>/Relational Operator' */
  rtb_RelationalOperator_j = (Accelerator_test_build_B.u1_c <
    rtb_raptor_adjustment3_k);

  /* S-Function (raptor_sfun_fault_def): '<S7>/raptor_fault_def1' */

  /* Fault Reference : POT1_InputLow */
  {
    {
      updateFaultInput(2, rtb_RelationalOperator_j, POT1_InputLow_X_Limit_Data(),
                       POT1_InputLow_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S7>/raptor_measurement' */
  POT1HighProbe_Data() = Accelerator_test_build_B.u1_n;

  /* S-Function (raptor_sfun_measurement): '<S7>/raptor_measurement1' */
  POT1LowProbe_Data() = Accelerator_test_build_B.u1_k;

  /* S-Function (raptor_sfun_measurement): '<S7>/raptor_measurement2' */
  POT1_ADC_Raw_Data() = rtb_raptor_analog_in;
}

/* Model step function */
void Accelerator_test_build_step(void)
{
  /* S-Function (raptor_sfun_target_def): '<Root>/raptor_target_def' */

  /*
   * New Eagle LLC 2011
   */
}

/* Model initialize function */
void Accelerator_test_build_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &Accelerator_test_build_B), 0,
                sizeof(BlockIO_Accelerator_test_build));

  {
    Accelerator_test_build_B.raptor_override1 = 0.0;
    Accelerator_test_build_B.raptor_override2 = 0.0;
    Accelerator_test_build_B.u1 = 0.0;
    Accelerator_test_build_B.raptor_override = 0.0;
    Accelerator_test_build_B.raptor_override1_o = 0.0;
    Accelerator_test_build_B.raptor_override3 = 0.0;
    Accelerator_test_build_B.raptor_override_f = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Accelerator_test_build_DWork, 0,
                sizeof(D_Work_Accelerator_test_build));
  Accelerator_test_build_DWork.UnitDelay_DSTATE = 0.0;

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

  Accelerator_test_build_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = ZERO_ZCSIG;
  Accelerator_test_build_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = POS_ZCSIG;
  Accelerator_test_build_PrevZCSigState.StoreEEPROM_Trig_ZCE = ZERO_ZCSIG;

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  Accelerator_test_build_Foreground_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  Accelerator_test_build_FunctionCallSubsystem_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S3>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<S3>/Background'
   */
  Accelerator_test_build_Background_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S3>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<Root>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */
  Accelerator_test_build_Foreground_Enable();

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  Accelerator_test_build_Foreground_Enable();

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
void Accelerator_test_build_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
