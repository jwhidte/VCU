/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator_test_build.c
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

#include "Accelerator_test_build.h"
#include "rtwtypes.h"
#include "Accelerator_test_build_private.h"
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
  /* Start for S-Function (raptor_sfun_digital_in): '<S15>/raptor_digital_in' */

  /* S-Function Block: WAKE_INPUT1 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S15>/raptor_digital_out' */

  /* S-Function Block: POWER_HOLD */
  {
  }

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S16>/raptor_delta_time' */
  Accelerator_test_build_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay2' */
  Accelerator_test_build_DWork.UnitDelay2_DSTATE = true;
}

/* System reset for function-call system: '<S3>/Background' */
void Accelerator_test_build_Background_Reset(void)
{
  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S16>/raptor_delta_time' */
  Accelerator_test_build_DWork.raptor_delta_time_DWORK1 = ticks();

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay2' */
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

  /* S-Function (raptor_sfun_digital_in): '<S15>/raptor_digital_in' */
  /* S-Function Block: WAKE_INPUT1 */
  {
    rtb_raptor_digital_in = swsh_ignswSt();
  }

  /* S-Function (raptor_sfun_delta_time): '<S16>/raptor_delta_time' */
  {
    rtb_raptor_delta_time = (GetDeltaTime_ms
      (&Accelerator_test_build_DWork.raptor_delta_time_DWORK1) * 0.001f);
  }

  /* MultiPortSwitch: '<S16>/Multiport Switch1' incorporates:
   *  Constant: '<S16>/Constant'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  Sum: '<S16>/Add'
   *  UnitDelay: '<S16>/Unit Delay'
   *  UnitDelay: '<S20>/Delay Input1'
   */
  if (rtb_raptor_digital_in == Accelerator_test_build_DWork.DelayInput1_DSTATE)
  {
    rtb_MultiportSwitch1 = rtb_raptor_delta_time +
      Accelerator_test_build_DWork.UnitDelay_DSTATE;
  } else {
    rtb_MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S16>/Multiport Switch1' */
  /* UnitDelay: '<S16>/Unit Delay2' */
  rtb_raptor_sfun_nv_status = Accelerator_test_build_DWork.UnitDelay2_DSTATE;

  /* CombinatorialLogic: '<S16>/Logic' incorporates:
   *  Logic: '<S16>/Logical Operator1'
   *  Logic: '<S16>/Logical Operator2'
   *  Logic: '<S16>/Logical Operator3'
   *  RelationalOperator: '<S16>/Relational Operator'
   *  RelationalOperator: '<S16>/Relational Operator1'
   *  S-Function (raptor_sfun_adjustment): '<S16>/raptor_adjustment3'
   *  S-Function (raptor_sfun_adjustment): '<S16>/raptor_adjustment4'
   */
  rtb_Logic = Accelerator_test_build_ConstP.Logic_table[((((uint32_T)
    (rtb_raptor_digital_in && (rtb_MultiportSwitch1 >= (KeySwHiTimeThr_Data())))
    << 1) + (uint32_T)((!rtb_raptor_digital_in) && (rtb_MultiportSwitch1 >=
    (KeySwLoTimeThr_Data())))) << 1) + rtb_raptor_sfun_nv_status];

  /* Logic: '<S15>/Logical Operator1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S15>/raptor_data_read1'
   */
  rtb_LogicalOperator1_h = (rtb_Logic || KeepModuleOn_Data());

  /* Outputs for Triggered SubSystem: '<S15>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S17>/Trigger'
   */
  if ((!rtb_LogicalOperator1_h) &&
      (Accelerator_test_build_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE !=
       ZERO_ZCSIG)) {
    /* S-Function (raptor_sfun_data_write): '<S17>/raptor_data_write' incorporates:
     *  Constant: '<S17>/Constant'
     */
    FgndTasksStopped_Data() = true;

    /* S-Function (fcgen): '<S17>/Function-Call Generator' incorporates:
     *  SubSystem: '<S17>/raptor_shutdown'
     */
    /* S-Function (raptor_sfun_shutdown): '<S21>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Shutdown(void);
      App_Shutdown();
    }

    /* End of Outputs for S-Function (fcgen): '<S17>/Function-Call Generator' */
  }

  Accelerator_test_build_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE =
    rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S15>/Raise Shutdown Event' */
  /* Outputs for Enabled and Triggered SubSystem: '<S15>/Raise Startup Event' incorporates:
   *  EnablePort: '<S18>/Enable'
   *  TriggerPort: '<S18>/Trigger'
   */
  if (FgndTasksStopped_Data() && (rtb_LogicalOperator1_h &&
       (Accelerator_test_build_PrevZCSigState.RaiseStartupEvent_Trig_ZCE !=
        POS_ZCSIG))) {
    /* S-Function (fcgen): '<S18>/Function-Call Generator' incorporates:
     *  SubSystem: '<S18>/raptor_startup'
     */
    /* S-Function (raptor_sfun_startup): '<S22>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Startup(void);
      App_Startup();
    }

    /* End of Outputs for S-Function (fcgen): '<S18>/Function-Call Generator' */
  }

  /* End of S-Function (raptor_sfun_data_read): '<S15>/raptor_data_read' */

  /* Outputs for Triggered SubSystem: '<S15>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S17>/Trigger'
   */
  Accelerator_test_build_PrevZCSigState.RaiseStartupEvent_Trig_ZCE =
    rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S15>/Raise Shutdown Event' */
  /* End of Outputs for SubSystem: '<S15>/Raise Startup Event' */

  /* UnitDelay: '<S15>/Unit Delay' */
  rtb_LogicalOperator2_c = Accelerator_test_build_DWork.UnitDelay_DSTATE_e;

  /* Outputs for Triggered SubSystem: '<S15>/Store EEPROM' incorporates:
   *  TriggerPort: '<S19>/Trigger'
   */
  if ((!Accelerator_test_build_DWork.UnitDelay_DSTATE_e) &&
      (Accelerator_test_build_PrevZCSigState.StoreEEPROM_Trig_ZCE != ZERO_ZCSIG))
  {
    /* S-Function (fcgen): '<S19>/Function-Call Generator' incorporates:
     *  SubSystem: '<S19>/raptor_store_nv'
     */
    /* S-Function (raptor_sfun_store_nv): '<S23>/raptor_data_write' */
    /* S-Function Block */
    {
      App_EE_Store();
    }

    /* End of Outputs for S-Function (fcgen): '<S19>/Function-Call Generator' */
  }

  /* End of UnitDelay: '<S15>/Unit Delay' */
  Accelerator_test_build_PrevZCSigState.StoreEEPROM_Trig_ZCE =
    rtb_LogicalOperator2_c;

  /* End of Outputs for SubSystem: '<S15>/Store EEPROM' */

  /* S-Function (raptor_sfun_data_write): '<S15>/raptor_data_write' */
  KeySw_Bgnd_Data() = rtb_Logic;

  /* S-Function (raptor_sfun_nv_status): '<S15>/raptor_sfun_nv_status' */
  /* S-Function Block */
  {
    rtb_raptor_sfun_nv_status = (EEPROM_State_Data() == EE_STORE_IN_PROGESS);
  }

  /* Logic: '<S15>/Logical Operator2' incorporates:
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  rtb_raptor_sfun_nv_status = (rtb_raptor_sfun_nv_status ||
    rtb_LogicalOperator1_h || Accelerator_test_build_DWork.UnitDelay1_DSTATE);

  /* S-Function (raptor_sfun_digital_out): '<S15>/raptor_digital_out' */
  /* S-Function Block: POWER_HOLD */
  {
    {
      if (rtb_raptor_sfun_nv_status && !swsh_ignswSt()) {
        SyC_WaitPostDrv();
      }
    }
  }

  /* Update for UnitDelay: '<S20>/Delay Input1' */
  Accelerator_test_build_DWork.DelayInput1_DSTATE = rtb_raptor_digital_in;

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  Accelerator_test_build_DWork.UnitDelay_DSTATE = rtb_MultiportSwitch1;

  /* Update for UnitDelay: '<S16>/Unit Delay2' */
  Accelerator_test_build_DWork.UnitDelay2_DSTATE = rtb_Logic;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  Accelerator_test_build_DWork.UnitDelay_DSTATE_e = rtb_LogicalOperator1_h;

  /* Update for UnitDelay: '<S15>/Unit Delay1' */
  Accelerator_test_build_DWork.UnitDelay1_DSTATE = rtb_LogicalOperator2_c;
}

/* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_test_build_FunctionCallSubsystem_Init(void)
{
  /* Start for If: '<S2>/If' */
  Accelerator_test_build_DWork.If_ActiveSubsystem = -1;
}

/* Enable for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_test_build_FunctionCallSubsystem_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S2>/raptor_can_txmsg' incorporates:
   *  Constant: '<S2>/Constant'
   */
  /* Level2 S-Function Block: '<S2>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_97__0002(0U);
}

/* Disable for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_test_build_FunctionCallSubsystem_Disable(void)
{
  /* Disable for If: '<S2>/If' */
  if (Accelerator_test_build_DWork.If_ActiveSubsystem == 0) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S14>/raptor_can_txmsg' incorporates:
     *  Constant: '<S14>/Constant'
     */
    /* Level2 S-Function Block: '<S14>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_94__0002(0);
  }

  Accelerator_test_build_DWork.If_ActiveSubsystem = -1;

  /* End of Disable for If: '<S2>/If' */

  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S2>/raptor_can_txmsg' incorporates:
   *  Constant: '<S2>/Constant'
   */
  /* Level2 S-Function Block: '<S2>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_97__0002(0);
}

/* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
void Accelerator_test_build_FunctionCallSubsystem(void)
{
  real_T rtb_DataTypeConversion3;
  uint32_T rtb_raptor_time;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S13>/Compare'
   *  S-Function (raptor_sfun_data_read): '<S2>/raptor_data_read'
   */
  rtPrevAction = Accelerator_test_build_DWork.If_ActiveSubsystem;
  rtAction = -1;
  if (AbsoluteTime_Data() >= 5.0) {
    rtAction = 0;
  }

  Accelerator_test_build_DWork.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for S-Function (raptor_sfun_can_txmsg): '<S14>/raptor_can_txmsg' incorporates:
     *  Constant: '<S14>/Constant'
     */
    /* Level2 S-Function Block: '<S14>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
    can_set_period_94__0002(0);
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* Enable for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Enable for If: '<S2>/If' incorporates:
       *  Constant: '<S14>/Constant'
       *  S-Function (raptor_sfun_can_txmsg): '<S14>/raptor_can_txmsg'
       */
      /* Level2 S-Function Block: '<S14>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
      can_set_period_94__0002(0U);

      /* End of Enable for SubSystem: '<S2>/If Action Subsystem' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* S-Function (raptor_sfun_can_txmsg): '<S14>/raptor_can_txmsg' incorporates:
     *  Constant: '<S14>/Constant'
     */

    /* S-Function Block:<S14>/raptor_can_txmsg */
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
      can_set_period_94__0002(0U);
      can_send_94__0002(192U & 0x7FF, 0, 8U, &data[0]);
    }

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  }

  /* End of If: '<S2>/If' */

  /* S-Function (raptor_sfun_can_txmsg): '<S2>/raptor_can_txmsg' incorporates:
   *  Constant: '<S2>/Constant'
   */

  /* S-Function Block:<S2>/raptor_can_txmsg */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: Inverter_Enable */
    /* Inverter_Enable - StartBit: 40U, BitLength: 1U, Endian: 0U */

    /* signal type is unsigned */
    if (0.0 < 0.0000000000F)
      temp = (uint32_T)0U;
    else if (0.0 > 1.0000000000F)
      temp = (uint32_T)1U;
    else {
      if ((real_T)0.0 < 0)
        temp = (uint32_T)(int32_T)((0.0));
      else
        temp = (uint32_T)((0.0));
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)1U);
    data[5U] |= temp_shift;
    can_set_period_97__0002(0U);
    can_send_97__0002(192U & 0x7FF, 0, 8U, &data[0]);
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
 *    '<S8>/MATLAB Function'
 *    '<S9>/MATLAB Function'
 */
void Accelerator_test_build_MATLABFunction(real_T rtu_a, real_T rtu_b, real_T
  rtu_c, rtB_MATLABFunction_Accelerator_test_build *localB)
{
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:2' */
  localB->y = (rtu_a - rtu_c) / (rtu_b - rtu_c) * 100.0;
}

/* System initialize for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground_Init(void)
{
  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in' */

  /* S-Function Block: INPUT29 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' */

  /* S-Function Block: INPUT30 */
  {
  }
}

/* Enable for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_31__0002(0U);
}

/* Disable for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground_Disable(void)
{
  /* Disable for S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  /* Level2 S-Function Block: '<S6>/raptor_can_txmsg' (raptor_sfun_can_txmsg) */
  can_set_period_31__0002(0);
}

/* Output and update for function-call system: '<Root>/Foreground' */
void Accelerator_test_build_Foreground(void)
{
  /* local block i/o variables */
  real_T rtb_raptor_adjustment3_f;
  uint16_T rtb_raptor_analog_in;
  uint16_T rtb_raptor_analog_in1;
  real_T rtb_DataTypeConversion4;
  real_T tmp;
  boolean_T rtb_RelationalOperator_j;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in' */
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
        rtb_raptor_analog_in = last_value;
      } else {
        int16_T input = swsh_Read_ADC_ECUK065();
        last_value = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
        rtb_raptor_analog_in = last_value;
      }
    }
  }

  /* S-Function (raptor_sfun_override): '<S8>/raptor_override' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in'
   */
  if (POT1_ADC_OvrSts_Data()) {
    Accelerator_test_build_B.u1_b = POT1_ADC_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1_b = rtb_raptor_analog_in;
  }

  POT1_ADC_Data() = Accelerator_test_build_B.u1_b;

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment1' */
  rtb_raptor_adjustment3_f = (POT1_ADCHiPT_Data());

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  tmp = floorf(rtb_raptor_adjustment3_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion4' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   */
  rtb_DataTypeConversion4 = tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(uint16_T)tmp;

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment' */
  rtb_raptor_adjustment3_f = (POT1_ADCLoPT_Data());

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  tmp = floorf(rtb_raptor_adjustment3_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   *  DataTypeConversion: '<S8>/Data Type Conversion3'
   *  DataTypeConversion: '<S8>/Data Type Conversion5'
   */
  Accelerator_test_build_MATLABFunction((real_T)Accelerator_test_build_B.u1_b,
    rtb_DataTypeConversion4, (real_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp),
    &Accelerator_test_build_B.sf_MATLABFunction);

  /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
   *  Logic: '<S8>/Logical Operator'
   *  S-Function (raptor_sfun_fault_status): '<S8>/raptor_fault_status'
   *  S-Function (raptor_sfun_fault_status): '<S8>/raptor_fault_status1'
   */
  if ((!(getFaultState(1, (E_FaultState)FAULT_ACTIVE_MASK))) && (!(getFaultState
        (2, (E_FaultState)FAULT_ACTIVE_MASK)))) {
    /* Saturate: '<S8>/Saturation' */
    if (Accelerator_test_build_B.sf_MATLABFunction.y > 100.0) {
      /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' */
      rtb_raptor_adjustment3_f = 100.0;
    } else if (Accelerator_test_build_B.sf_MATLABFunction.y < 0.0) {
      /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' */
      rtb_raptor_adjustment3_f = 0.0;
    } else {
      /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' */
      rtb_raptor_adjustment3_f = Accelerator_test_build_B.sf_MATLABFunction.y;
    }

    /* End of Saturate: '<S8>/Saturation' */
  } else {
    /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_raptor_adjustment3_f = 0.0;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S8>/raptor_override1' */
  if (POT1_OvrSts_Data()) {
    Accelerator_test_build_B.u1 = POT1_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1 = rtb_raptor_adjustment3_f;
  }

  POT1_Data() = Accelerator_test_build_B.u1;

  /* S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1' */
  /* S-Function Block: INPUT30 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK082();
      rtb_raptor_analog_in1 = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S9>/raptor_override' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S1>/raptor_analog_in1'
   */
  if (POT2_ADC_OvrSts_Data()) {
    Accelerator_test_build_B.u1_l = POT2_ADC_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1_l = rtb_raptor_analog_in1;
  }

  POT2_ADC_Data() = Accelerator_test_build_B.u1_l;

  /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment1' */
  rtb_raptor_adjustment3_f = (POT2_ADCHiPT_Data());

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  tmp = floorf(rtb_raptor_adjustment3_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion4' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   */
  rtb_DataTypeConversion4 = tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(uint16_T)tmp;

  /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment' */
  rtb_raptor_adjustment3_f = (POT2_ADCLoPT_Data());

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  tmp = floorf(rtb_raptor_adjustment3_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  DataTypeConversion: '<S9>/Data Type Conversion3'
   *  DataTypeConversion: '<S9>/Data Type Conversion5'
   */
  Accelerator_test_build_MATLABFunction((real_T)Accelerator_test_build_B.u1_l,
    rtb_DataTypeConversion4, (real_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp),
    &Accelerator_test_build_B.sf_MATLABFunction_i);

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Logic: '<S9>/Logical Operator'
   *  S-Function (raptor_sfun_fault_status): '<S9>/raptor_fault_status'
   *  S-Function (raptor_sfun_fault_status): '<S9>/raptor_fault_status1'
   */
  if ((!(getFaultState(3, (E_FaultState)FAULT_ACTIVE_MASK))) && (!(getFaultState
        (4, (E_FaultState)FAULT_ACTIVE_MASK)))) {
    /* Saturate: '<S9>/Saturation' */
    if (Accelerator_test_build_B.sf_MATLABFunction_i.y > 100.0) {
      /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' */
      rtb_raptor_adjustment3_f = 100.0;
    } else if (Accelerator_test_build_B.sf_MATLABFunction_i.y < 0.0) {
      /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' */
      rtb_raptor_adjustment3_f = 0.0;
    } else {
      /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' */
      rtb_raptor_adjustment3_f = Accelerator_test_build_B.sf_MATLABFunction_i.y;
    }

    /* End of Saturate: '<S9>/Saturation' */
  } else {
    /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtb_raptor_adjustment3_f = 0.0;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S9>/raptor_override1' */
  if (POT2_OvrSts_Data()) {
    Accelerator_test_build_B.u1_c = POT2_OvrVal_Data();
  } else {
    Accelerator_test_build_B.u1_c = rtb_raptor_adjustment3_f;
  }

  POT2_Data() = Accelerator_test_build_B.u1_c;

  /* S-Function (raptor_sfun_can_rxmsg): '<S1>/raptor_can_rxmsg' */
  /* MATLAB Function 'Foreground/MATLAB Function1': '<S7>:1' */
  /* '<S7>:1:2' */

  /* S-Function Block:<S1>/raptor_can_rxmsg */
  {
    uint8_T data[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint32_T temp;
    can_get_68__0002(NULL, NULL, NULL, &data[0], 8);

    /* Signal: D2_Motor_Speed */
    temp = 0;
    temp |= ((uint32_T)data[2U]) ;
    temp |= ((uint32_T)data[3U]) << 8;
    if (temp & 32768)
      temp |= (uint32_T)-65536;
    rtb_raptor_adjustment3_f = (((real_T) ((int32_T) temp) ) );
  }

  /* S-Function (raptor_sfun_table_axis): '<S10>/raptor_table_axis' */
  {
    int idx;
    for (idx=0;idx<1;idx++) {
      Accelerator_test_build_B.raptor_table_axis = TableAxis_real32_T
        ( rtb_raptor_adjustment3_f, RPM_Data(), 33u,
         Accelerator_test_build_B.raptor_table_axis);
    }

    idx = 0;
    RPM_IN_Data() = rtb_raptor_adjustment3_f;
  }

  /* S-Function (raptor_sfun_table_interpolate_1d): '<S10>/raptor_table_interpolate_1d' */
  {
    rtb_raptor_adjustment3_f = TableInterpolate1D_real32_T
      ( Accelerator_test_build_B.raptor_table_axis, MaxTorqueMap_Data(), 33u);
    MaxTorqueMap_Y_IN_IDX_Data() = Accelerator_test_build_B.raptor_table_axis;
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S5>/Safety factor'
   *  Gain: '<S6>/Gain'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  Product: '<S5>/Product'
   *  SignalConversion generated from: '<S7>/ SFunction '
   */
  rtb_DataTypeConversion4 = (Accelerator_test_build_B.u1 +
    Accelerator_test_build_B.u1_c) / 2.0 * rtb_raptor_adjustment3_f * 0.9 * 10.0
    - 256.0;

  /* S-Function (raptor_sfun_can_txmsg): '<S6>/raptor_can_txmsg' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S6>/Constant1'
   */

  /* S-Function Block:<S6>/raptor_can_txmsg */
  {
    uint8_T data[8U] = { 0, 0, 0, 0, 0, 0, 0, 0, };

    uint32_T temp;
    uint8_T temp_shift;

    /* Signal: Direction_Command */
    /* Direction_Command - StartBit: 32U, BitLength: 1U, Endian: 0U */

    /* signal type is unsigned */
    if (0.0 < 0.0000000000F)
      temp = (uint32_T)0U;
    else if (0.0 > 1.0000000000F)
      temp = (uint32_T)1U;
    else {
      if ((real_T)0.0 < 0)
        temp = (uint32_T)(int32_T)((0.0));
      else
        temp = (uint32_T)((0.0));
    }

    temp_shift = (uint8_T)(temp >> 0);
    temp_shift &= ((uint8_T)1U);
    data[4U] |= temp_shift;

    /* Signal: Inverter_Enable   */
    /* Inverter_Enable   - StartBit: 40U, BitLength: 1U, Endian: 0U */

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

    /* Signal: Torque_Command    */
    /* Torque_Command    - StartBit: 0U, BitLength: 16U, Endian: 0U */
    {
      /* signal type is signed */
      int32_T tempS;
      if ((real_T)rtb_DataTypeConversion4 < -3276.8)
        tempS = (int32_T)-32768.0;
      else if ((real_T)rtb_DataTypeConversion4 > 3276.7000000000003)
        tempS = (int32_T)32767.0;
      else if ((real_T)rtb_DataTypeConversion4 < 0)
        tempS = (int32_T)(int32_T)((rtb_DataTypeConversion4) * 10.0f);
      else
        tempS = (int32_T)((rtb_DataTypeConversion4) * 10.0f);
      temp = *((uint32_T*)&tempS);
    }

    temp_shift = (uint8_T)(temp >> 0);
    data[0U] |= temp_shift;
    temp_shift = (uint8_T)(temp >> 8);
    data[1U] |= temp_shift;
    can_set_period_31__0002(0U);
    can_send_31__0002(192U & 0x7FF, 0, 8U, &data[0]);
  }

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment2' */
  rtb_raptor_adjustment3_f = (POT1_InputHighThresh_Data());

  /* RelationalOperator: '<S8>/Relational Operator1' */
  rtb_RelationalOperator_j = (Accelerator_test_build_B.u1_b >
    rtb_raptor_adjustment3_f);

  /* S-Function (raptor_sfun_fault_def): '<S8>/raptor_fault_def' */

  /* Fault Reference : POT1_InputHi */
  {
    {
      updateFaultInput(1, rtb_RelationalOperator_j, POT1_InputHi_X_Limit_Data(),
                       POT1_InputHi_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S8>/raptor_adjustment3' */
  rtb_raptor_adjustment3_f = (POT1_InputLowThresh_Data());

  /* RelationalOperator: '<S8>/Relational Operator' */
  rtb_RelationalOperator_j = (Accelerator_test_build_B.u1_b <
    rtb_raptor_adjustment3_f);

  /* S-Function (raptor_sfun_fault_def): '<S8>/raptor_fault_def1' */

  /* Fault Reference : POT1_InputLow */
  {
    {
      updateFaultInput(2, rtb_RelationalOperator_j, POT1_InputLow_X_Limit_Data(),
                       POT1_InputLow_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S8>/raptor_fault_status'
   */
  POT1HighProbe_Data() = (getFaultState(1, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement1' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S8>/raptor_fault_status1'
   */
  POT1LowProbe_Data() = (getFaultState(2, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment2' */
  rtb_raptor_adjustment3_f = (POT2_InputHighThresh_Data());

  /* RelationalOperator: '<S9>/Relational Operator1' */
  rtb_RelationalOperator_j = (Accelerator_test_build_B.u1_l >
    rtb_raptor_adjustment3_f);

  /* S-Function (raptor_sfun_fault_def): '<S9>/raptor_fault_def' */

  /* Fault Reference : POT2_InputHi */
  {
    {
      updateFaultInput(3, rtb_RelationalOperator_j, POT2_InputHi_X_Limit_Data(),
                       POT2_InputHi_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S9>/raptor_adjustment3' */
  rtb_raptor_adjustment3_f = (POT2_InputLowThresh_Data());

  /* RelationalOperator: '<S9>/Relational Operator' */
  rtb_RelationalOperator_j = (Accelerator_test_build_B.u1_l <
    rtb_raptor_adjustment3_f);

  /* S-Function (raptor_sfun_fault_def): '<S9>/raptor_fault_def1' */

  /* Fault Reference : POT2_InputLow */
  {
    {
      updateFaultInput(4, rtb_RelationalOperator_j, POT2_InputLow_X_Limit_Data(),
                       POT2_InputLow_Y_Limit_Data(), 1);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S9>/raptor_measurement' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S9>/raptor_fault_status'
   */
  POT2HighProbe_Data() = (getFaultState(3, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S9>/raptor_measurement1' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S9>/raptor_fault_status1'
   */
  POT2LowProbe_Data() = (getFaultState(4, (E_FaultState)FAULT_ACTIVE_MASK));
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
    Accelerator_test_build_B.u1 = 0.0;
    Accelerator_test_build_B.u1_c = 0.0;
    Accelerator_test_build_B.sf_MATLABFunction_i.y = 0.0;
    Accelerator_test_build_B.sf_MATLABFunction.y = 0.0;
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
  Accelerator_test_build_FunctionCallSubsystem_Enable();

  /* End of Enable for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' */

  /* Enable for S-Function (raptor_sfun_app_trigger): '<Root>/raptor_app_trigger' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  Accelerator_test_build_FunctionCallSubsystem_Enable();

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
