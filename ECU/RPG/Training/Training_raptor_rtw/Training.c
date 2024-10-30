/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Training.c
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

#include "Training.h"
#include "rtwtypes.h"
#include "Training_private.h"
#include "math.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_Training Training_B;

/* Block states (default storage) */
D_Work_Training Training_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_Training Training_PrevZCSigState;

// Block : Training/raptor_timed_trigger
void Timer_ooqlV(void)
{
  /* Timer_ooqlV  ------   Foreground  */
  {
    {
      Training_Foreground();
    }
  }
}

// Block : Training/Power Up_Down/raptor_timed_trigger
void Timer_BGND_G6Wyo(void)
{
  /* Timer_BGND_G6Wyo  ------   Background  */
  {
    {
      Training_Background();
    }
  }
}

/* System initialize for function-call system: '<S2>/Background' */
void Training_Background_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_in): '<S10>/raptor_digital_in' */

  /* S-Function Block: WAKE_INPUT1 */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S10>/raptor_digital_out' */

  /* S-Function Block: POWER_HOLD */
  {
  }

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S11>/raptor_delta_time' */
  Training_DWork.raptor_delta_time_DWORK1_d = ticks();

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay2' */
  Training_DWork.UnitDelay2_DSTATE = true;
}

/* System reset for function-call system: '<S2>/Background' */
void Training_Background_Reset(void)
{
  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S11>/raptor_delta_time' */
  Training_DWork.raptor_delta_time_DWORK1_d = ticks();

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay2' */
  Training_DWork.UnitDelay2_DSTATE = true;
}

/* Output and update for function-call system: '<S2>/Background' */
void Training_Background(void)
{
  /* local block i/o variables */
  real_T rtb_raptor_delta_time;
  boolean_T rtb_raptor_digital_in;
  real_T rtb_MultiportSwitch1;
  boolean_T rtb_Logic;
  boolean_T rtb_LogicalOperator1_h;
  boolean_T rtb_LogicalOperator2_c;
  boolean_T rtb_raptor_sfun_nv_status;

  /* S-Function (raptor_sfun_digital_in): '<S10>/raptor_digital_in' */
  /* S-Function Block: WAKE_INPUT1 */
  {
    rtb_raptor_digital_in = swsh_ignswSt();
  }

  /* S-Function (raptor_sfun_delta_time): '<S11>/raptor_delta_time' */
  {
    rtb_raptor_delta_time = (GetDeltaTime_ms
      (&Training_DWork.raptor_delta_time_DWORK1_d) * 0.001f);
  }

  /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S15>/FixPt Relational Operator'
   *  Sum: '<S11>/Add'
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S15>/Delay Input1'
   */
  if (rtb_raptor_digital_in == Training_DWork.DelayInput1_DSTATE) {
    rtb_MultiportSwitch1 = rtb_raptor_delta_time +
      Training_DWork.UnitDelay_DSTATE;
  } else {
    rtb_MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch1' */
  /* UnitDelay: '<S11>/Unit Delay2' */
  rtb_raptor_sfun_nv_status = Training_DWork.UnitDelay2_DSTATE;

  /* CombinatorialLogic: '<S11>/Logic' incorporates:
   *  Logic: '<S11>/Logical Operator1'
   *  Logic: '<S11>/Logical Operator2'
   *  Logic: '<S11>/Logical Operator3'
   *  RelationalOperator: '<S11>/Relational Operator'
   *  RelationalOperator: '<S11>/Relational Operator1'
   *  S-Function (raptor_sfun_adjustment): '<S11>/raptor_adjustment3'
   *  S-Function (raptor_sfun_adjustment): '<S11>/raptor_adjustment4'
   */
  rtb_Logic = Training_ConstP.Logic_table[((((uint32_T)(rtb_raptor_digital_in &&
    (rtb_MultiportSwitch1 >= (KeySwHiTimeThr_Data()))) << 1) + (uint32_T)
    ((!rtb_raptor_digital_in) && (rtb_MultiportSwitch1 >= (KeySwLoTimeThr_Data()))))
    << 1) + rtb_raptor_sfun_nv_status];

  /* Logic: '<S10>/Logical Operator1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S10>/raptor_data_read1'
   */
  rtb_LogicalOperator1_h = (rtb_Logic || KeepModuleOn_Data());

  /* Outputs for Triggered SubSystem: '<S10>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  if ((!rtb_LogicalOperator1_h) &&
      (Training_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (raptor_sfun_data_write): '<S12>/raptor_data_write' incorporates:
     *  Constant: '<S12>/Constant'
     */
    FgndTasksStopped_Data() = true;

    /* S-Function (fcgen): '<S12>/Function-Call Generator' incorporates:
     *  SubSystem: '<S12>/raptor_shutdown'
     */
    /* S-Function (raptor_sfun_shutdown): '<S16>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Shutdown(void);
      App_Shutdown();
    }

    /* End of Outputs for S-Function (fcgen): '<S12>/Function-Call Generator' */
  }

  Training_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S10>/Raise Shutdown Event' */
  /* Outputs for Enabled and Triggered SubSystem: '<S10>/Raise Startup Event' incorporates:
   *  EnablePort: '<S13>/Enable'
   *  TriggerPort: '<S13>/Trigger'
   */
  if (FgndTasksStopped_Data() && (rtb_LogicalOperator1_h &&
       (Training_PrevZCSigState.RaiseStartupEvent_Trig_ZCE != POS_ZCSIG))) {
    /* S-Function (fcgen): '<S13>/Function-Call Generator' incorporates:
     *  SubSystem: '<S13>/raptor_startup'
     */
    /* S-Function (raptor_sfun_startup): '<S17>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Startup(void);
      App_Startup();
    }

    /* End of Outputs for S-Function (fcgen): '<S13>/Function-Call Generator' */
  }

  /* End of S-Function (raptor_sfun_data_read): '<S10>/raptor_data_read' */

  /* Outputs for Triggered SubSystem: '<S10>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  Training_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = rtb_LogicalOperator1_h;

  /* End of Outputs for SubSystem: '<S10>/Raise Shutdown Event' */
  /* End of Outputs for SubSystem: '<S10>/Raise Startup Event' */

  /* UnitDelay: '<S10>/Unit Delay' */
  rtb_LogicalOperator2_c = Training_DWork.UnitDelay_DSTATE_e;

  /* Outputs for Triggered SubSystem: '<S10>/Store EEPROM' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  if ((!Training_DWork.UnitDelay_DSTATE_e) &&
      (Training_PrevZCSigState.StoreEEPROM_Trig_ZCE != ZERO_ZCSIG)) {
    /* S-Function (fcgen): '<S14>/Function-Call Generator' incorporates:
     *  SubSystem: '<S14>/raptor_store_nv'
     */
    /* S-Function (raptor_sfun_store_nv): '<S18>/raptor_data_write' */
    /* S-Function Block */
    {
      App_EE_Store();
    }

    /* End of Outputs for S-Function (fcgen): '<S14>/Function-Call Generator' */
  }

  /* End of UnitDelay: '<S10>/Unit Delay' */
  Training_PrevZCSigState.StoreEEPROM_Trig_ZCE = rtb_LogicalOperator2_c;

  /* End of Outputs for SubSystem: '<S10>/Store EEPROM' */

  /* S-Function (raptor_sfun_data_write): '<S10>/raptor_data_write' */
  KeySw_Bgnd_Data() = rtb_Logic;

  /* S-Function (raptor_sfun_nv_status): '<S10>/raptor_sfun_nv_status' */
  /* S-Function Block */
  {
    rtb_raptor_sfun_nv_status = (EEPROM_State_Data() == EE_STORE_IN_PROGESS);
  }

  /* Logic: '<S10>/Logical Operator2' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  rtb_raptor_sfun_nv_status = (rtb_raptor_sfun_nv_status ||
    rtb_LogicalOperator1_h || Training_DWork.UnitDelay1_DSTATE);

  /* S-Function (raptor_sfun_digital_out): '<S10>/raptor_digital_out' */
  /* S-Function Block: POWER_HOLD */
  {
    {
      if (rtb_raptor_sfun_nv_status && !swsh_ignswSt()) {
        SyC_WaitPostDrv();
      }
    }
  }

  /* Update for UnitDelay: '<S15>/Delay Input1' */
  Training_DWork.DelayInput1_DSTATE = rtb_raptor_digital_in;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  Training_DWork.UnitDelay_DSTATE = rtb_MultiportSwitch1;

  /* Update for UnitDelay: '<S11>/Unit Delay2' */
  Training_DWork.UnitDelay2_DSTATE = rtb_Logic;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  Training_DWork.UnitDelay_DSTATE_e = rtb_LogicalOperator1_h;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  Training_DWork.UnitDelay1_DSTATE = rtb_LogicalOperator2_c;
}

/*
 * Output and update for atomic system:
 *    '<S6>/MATLAB Function'
 *    '<S7>/MATLAB Function'
 */
void Training_MATLABFunction(const real_T rtu_u[3], rtB_MATLABFunction_Training *
  localB)
{
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S8>:1' */
  /* '<S8>:1:2' */
  localB->y = (rtu_u[0] - rtu_u[2] / (rtu_u[1] - rtu_u[2])) * 100.0;
}

/* System initialize for function-call system: '<Root>/Foreground' */
void Training_Foreground_Init(void)
{
  /* Start for S-Function (raptor_sfun_analog_in): '<S5>/raptor_analog_in' */

  /* S-Function Block: INPUT29 */
  {
  }

  /* Start for S-Function (raptor_sfun_analog_in): '<S5>/raptor_analog_in1' */

  /* S-Function Block: INPUT30 */
  {
  }

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
  Training_DWork.raptor_delta_time_DWORK1 = ticks();
}

/* System reset for function-call system: '<Root>/Foreground' */
void Training_Foreground_Reset(void)
{
  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
  Training_DWork.raptor_delta_time_DWORK1 = ticks();
}

/* Output and update for function-call system: '<Root>/Foreground' */
void Training_Foreground(void)
{
  /* local block i/o variables */
  real_T rtb_raptor_delta_time_n;
  uint16_T rtb_raptor_analog_in;
  uint16_T rtb_raptor_analog_in1;
  real_T rtb_DataTypeConversion3[3];
  real_T tmp;
  int16_T rtb_DataTypeConversion;
  boolean_T rtb_RelationalOperator_g;

  /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
   *  S-Function (raptor_sfun_fault_action): '<S4>/raptor_fault_action'
   */
  if (!getFaultActionState(0)) {
    /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' incorporates:
     *  Constant: '<S1>/Constant'
     */
    rtb_raptor_delta_time_n = 1.0;
  } else {
    /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    rtb_raptor_delta_time_n = 0.0;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S4>/raptor_override' */
  if (ETC_DC_OvrSts_Data()) {
    Training_B.raptor_override = ETC_DC_OvrVal_Data();
  } else {
    Training_B.raptor_override = rtb_raptor_delta_time_n;
  }

  ETC_DC_Data() = Training_B.raptor_override;

  /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' incorporates:
   *  Gain: '<S4>/Gain'
   */
  rtb_raptor_delta_time_n = 100.0 * Training_B.raptor_override;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  tmp = floorf(rtb_raptor_delta_time_n);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  rtb_DataTypeConversion = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */
  /* S-Function (raptor_sfun_hbridge_out): '<S4>/raptor_hbridge_out' incorporates:
   *  Constant: '<S4>/Constant'
   *  S-Function (raptor_sfun_adjustment): '<S4>/raptor_adjustment'
   *  S-Function (raptor_sfun_adjustment): '<S4>/raptor_adjustment1'
   */
  /* S-Function Block: OUTPUT50_51 */
  {
    swsh_Write_HBridgeShutOff(1, ((PWM_Enable_Data()) == 0));

    /* freq is in 1/100 Hz, period in 1us, duty is 0 - 10000 [-32767 - 32767] */
    swsh_Write_HBridgePeriodDuty(1, 100000000U / ((PWM_Freq_Data()) == 0 ? 1 :
      (PWM_Freq_Data())), (int16_T)(((real32_T)rtb_DataTypeConversion) * 3.2767f));
  }

  /* S-Function (raptor_sfun_analog_in): '<S5>/raptor_analog_in' */
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

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S5>/raptor_analog_in'
   */
  if (APP_ADC_OvrSts_Data()) {
    Training_B.u1_an = APP_ADC_OvrVal_Data();
  } else {
    Training_B.u1_an = rtb_raptor_analog_in;
  }

  APP_ADC_Data() = Training_B.u1_an;

  /* S-Function (raptor_sfun_adjustment): '<S6>/raptor_adjustment2' */
  rtb_raptor_delta_time_n = (APP_InputHighThresh_Data());

  /* RelationalOperator: '<S6>/Relational Operator1' */
  rtb_RelationalOperator_g = (Training_B.u1_an > rtb_raptor_delta_time_n);

  /* S-Function (raptor_sfun_fault_def): '<S6>/raptor_fault_def' */

  /* Fault Reference : APP_InputHi */
  {
    {
      updateFaultInput(1, rtb_RelationalOperator_g, APP_InputHi_X_Limit_Data(),
                       APP_InputHi_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S6>/raptor_adjustment3' */
  rtb_raptor_delta_time_n = (APP_InputLowThresh_Data());

  /* RelationalOperator: '<S6>/Relational Operator' */
  rtb_RelationalOperator_g = (Training_B.u1_an < rtb_raptor_delta_time_n);

  /* S-Function (raptor_sfun_fault_def): '<S6>/raptor_fault_def1' */

  /* Fault Reference : APP_InputLow */
  {
    {
      updateFaultInput(2, rtb_RelationalOperator_g, APP_InputLow_X_Limit_Data(),
                       APP_InputLow_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S6>/raptor_fault_status'
   */
  APPHighProbe_Data() = (getFaultState(1, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S6>/raptor_measurement1' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S6>/raptor_fault_status1'
   */
  APPLowProbe_Data() = (getFaultState(2, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_adjustment): '<S6>/raptor_adjustment1' */
  rtb_raptor_delta_time_n = (APP_ADCHiPT_Data());

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  tmp = floorf(rtb_raptor_delta_time_n);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* S-Function (raptor_sfun_adjustment): '<S6>/raptor_adjustment' */
  rtb_raptor_delta_time_n = (APP_ADCLoPT_Data());

  /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   */
  rtb_DataTypeConversion3[0] = Training_B.u1_an;
  rtb_DataTypeConversion3[1] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  tmp = floorf(rtb_raptor_delta_time_n);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   */
  rtb_DataTypeConversion3[2] = tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp;

  /* MATLAB Function: '<S6>/MATLAB Function' */
  Training_MATLABFunction(rtb_DataTypeConversion3, &Training_B.sf_MATLABFunction);

  /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
   *  Logic: '<S6>/Logical Operator'
   *  S-Function (raptor_sfun_fault_status): '<S6>/raptor_fault_status'
   *  S-Function (raptor_sfun_fault_status): '<S6>/raptor_fault_status1'
   */
  if ((!(getFaultState(1, (E_FaultState)FAULT_ACTIVE_MASK))) && (!(getFaultState
        (2, (E_FaultState)FAULT_ACTIVE_MASK)))) {
    /* Saturate: '<S6>/Saturation' */
    if (Training_B.sf_MATLABFunction.y > 100.0) {
      /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
      rtb_raptor_delta_time_n = 100.0;
    } else if (Training_B.sf_MATLABFunction.y < 0.0) {
      /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
      rtb_raptor_delta_time_n = 0.0;
    } else {
      /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
      rtb_raptor_delta_time_n = Training_B.sf_MATLABFunction.y;
    }

    /* End of Saturate: '<S6>/Saturation' */
  } else {
    /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' incorporates:
     *  S-Function (raptor_sfun_adjustment): '<S6>/raptor_adjustment4'
     */
    rtb_raptor_delta_time_n = (APP_DefaultValue_Data());
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S6>/raptor_override1' */
  if (APP_OvrSts_Data()) {
    Training_B.u1 = APP_OvrVal_Data();
  } else {
    Training_B.u1 = rtb_raptor_delta_time_n;
  }

  APP_Data() = Training_B.u1;

  /* S-Function (raptor_sfun_analog_in): '<S5>/raptor_analog_in1' */
  /* S-Function Block: INPUT30 */
  {
    {
      int16_T input = swsh_Read_ADC_ECUK082();
      rtb_raptor_analog_in1 = (uint16_T) ((input > 0 ? input : 0) * 0.32768f);
    }
  }

  /* S-Function (raptor_sfun_override): '<S7>/raptor_override' incorporates:
   *  S-Function (raptor_sfun_analog_in): '<S5>/raptor_analog_in1'
   */
  if (TPS_ADC_OvrSts_Data()) {
    Training_B.u1_o = TPS_ADC_OvrVal_Data();
  } else {
    Training_B.u1_o = rtb_raptor_analog_in1;
  }

  TPS_ADC_Data() = Training_B.u1_o;

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment2' */
  rtb_raptor_delta_time_n = (TPS_InputHighThresh_Data());

  /* RelationalOperator: '<S7>/Relational Operator1' */
  rtb_RelationalOperator_g = (Training_B.u1_o > rtb_raptor_delta_time_n);

  /* S-Function (raptor_sfun_fault_def): '<S7>/raptor_fault_def' */

  /* Fault Reference : TPS_InputHi */
  {
    {
      updateFaultInput(3, rtb_RelationalOperator_g, TPS_InputHi_X_Limit_Data(),
                       TPS_InputHi_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment3' */
  rtb_raptor_delta_time_n = (TPS_InputLowThresh_Data());

  /* RelationalOperator: '<S7>/Relational Operator' */
  rtb_RelationalOperator_g = (Training_B.u1_o < rtb_raptor_delta_time_n);

  /* S-Function (raptor_sfun_fault_def): '<S7>/raptor_fault_def1' */

  /* Fault Reference : TPS_InputLow */
  {
    {
      updateFaultInput(4, rtb_RelationalOperator_g, TPS_InputLow_X_Limit_Data(),
                       TPS_InputLow_Y_Limit_Data(), 0);
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S7>/raptor_measurement' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S7>/raptor_fault_status'
   */
  TPSHighProbe_Data() = (getFaultState(3, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_measurement): '<S7>/raptor_measurement1' incorporates:
   *  S-Function (raptor_sfun_fault_status): '<S7>/raptor_fault_status1'
   */
  TPSLowProbe_Data() = (getFaultState(4, (E_FaultState)FAULT_ACTIVE_MASK));

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment1' */
  rtb_raptor_delta_time_n = (TPS_ADCHiPT_Data());

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  tmp = floorf(rtb_raptor_delta_time_n);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment' */
  rtb_raptor_delta_time_n = (TPS_ADCLoPT_Data());

  /* DataTypeConversion: '<S7>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   */
  rtb_DataTypeConversion3[0] = Training_B.u1_o;
  rtb_DataTypeConversion3[1] = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* DataTypeConversion: '<S7>/Data Type Conversion2' */
  tmp = floorf(rtb_raptor_delta_time_n);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmodf((real32_T)tmp, 65536.0F);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   */
  rtb_DataTypeConversion3[2] = tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  Training_MATLABFunction(rtb_DataTypeConversion3,
    &Training_B.sf_MATLABFunction_j);

  /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
   *  Logic: '<S7>/Logical Operator'
   *  S-Function (raptor_sfun_fault_status): '<S7>/raptor_fault_status'
   *  S-Function (raptor_sfun_fault_status): '<S7>/raptor_fault_status1'
   */
  if ((!(getFaultState(3, (E_FaultState)FAULT_ACTIVE_MASK))) && (!(getFaultState
        (4, (E_FaultState)FAULT_ACTIVE_MASK)))) {
    /* Saturate: '<S7>/Saturation' */
    if (Training_B.sf_MATLABFunction_j.y > 100.0) {
      /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
      rtb_raptor_delta_time_n = 100.0;
    } else if (Training_B.sf_MATLABFunction_j.y < 0.0) {
      /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
      rtb_raptor_delta_time_n = 0.0;
    } else {
      /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
      rtb_raptor_delta_time_n = Training_B.sf_MATLABFunction_j.y;
    }

    /* End of Saturate: '<S7>/Saturation' */
  } else {
    /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' incorporates:
     *  S-Function (raptor_sfun_adjustment): '<S7>/raptor_adjustment4'
     */
    rtb_raptor_delta_time_n = (TPS_DefaultValue_Data());
  }

  /* End of MultiPortSwitch: '<S7>/Multiport Switch' */

  /* S-Function (raptor_sfun_override): '<S7>/raptor_override1' */
  if (TPS_OvrSts_Data()) {
    Training_B.u1_a = TPS_OvrVal_Data();
  } else {
    Training_B.u1_a = rtb_raptor_delta_time_n;
  }

  TPS_Data() = Training_B.u1_a;

  /* S-Function (raptor_sfun_delta_time): '<S1>/raptor_delta_time' */
  {
    rtb_raptor_delta_time_n = (GetDeltaTime_ms
      (&Training_DWork.raptor_delta_time_DWORK1) * 0.001f);
  }

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement1' */
  Delta_Time_Data() = rtb_raptor_delta_time_n;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement' incorporates:
   *  S-Function (raptor_sfun_time): '<S1>/raptor_time'
   */
  Absolute_Time_Data() = (GetAbsTime());
}

/* Model step function */
void Training_step(void)
{
  /* S-Function (raptor_sfun_target_def): '<Root>/raptor_target_def' */

  /*
   * New Eagle LLC 2011
   */
}

/* Model initialize function */
void Training_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &Training_B), 0,
                sizeof(BlockIO_Training));

  {
    Training_B.u1 = 0.0;
    Training_B.u1_a = 0.0;
    Training_B.raptor_override = 0.0;
    Training_B.sf_MATLABFunction_j.y = 0.0;
    Training_B.sf_MATLABFunction.y = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Training_DWork, 0,
                sizeof(D_Work_Training));
  Training_DWork.UnitDelay_DSTATE = 0.0;

  /* Start for S-Function (raptor_sfun_xcp): '<S3>/raptor_xcp_update' */

  /* S-Function Block - Start: <S3>/raptor_xcp_update */
  {
    CAN1_XCP_CAN_PreStart(CAN1__XCP_BC_ID_Data(), CAN1__XCP_RX_ID_Data(),
                          CAN1__XCP_TX_ID_Data());
  }

  /* Start for S-Function (raptor_sfun_fault_manager): '<Root>/raptor_fault_manager' */

  /* Fault Manager */
  {
    initFaultManager();
  }

  Training_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = ZERO_ZCSIG;
  Training_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = POS_ZCSIG;
  Training_PrevZCSigState.StoreEEPROM_Trig_ZCE = ZERO_ZCSIG;

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  Training_Foreground_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<S2>/Background'
   */
  Training_Background_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<Root>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<S2>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */
}

/* Model terminate function */
void Training_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
