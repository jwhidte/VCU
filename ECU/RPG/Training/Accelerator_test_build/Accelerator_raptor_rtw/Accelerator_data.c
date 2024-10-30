/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accelerator_data.c
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

/* Constant parameters (default storage) */
const ConstParam_Accelerator Accelerator_ConstP = {
  /* Expression: [120;115;110;105;100;95;90;85;80;75;70;65;60;55;50;45;40;35;30;25;20;15;10;5;0]
   * Referenced by: '<S1>/I: R (kOhm) O: T (C)'
   */
  { 120.0, 115.0, 110.0, 105.0, 100.0, 95.0, 90.0, 85.0, 80.0, 75.0, 70.0, 65.0,
    60.0, 55.0, 50.0, 45.0, 40.0, 35.0, 30.0, 25.0, 20.0, 15.0, 10.0, 5.0, 0.0 },

  /* Expression: [0.583;0.6601;0.7487;0.8508;0.9688;1.106;1.265;1.452;1.67;1.928;2.232;2.593;3.025;3.541;4.163;4.914;5.827;6.942;8.311;10;12.1;14.71;17.99;22.13;27.39]
   * Referenced by: '<S1>/I: R (kOhm) O: T (C)'
   */
  { 0.583, 0.6601, 0.7487, 0.8508, 0.9688, 1.106, 1.265, 1.452, 1.67, 1.928,
    2.232, 2.593, 3.025, 3.541, 4.163, 4.914, 5.827, 6.942, 8.311, 10.0, 12.1,
    14.71, 17.99, 22.13, 27.39 },

  /* Expression: [120;240;360;480;600;720]
   * Referenced by: '<S1>/Q (L//H) vs. F (Hz)'
   */
  { 120.0, 240.0, 360.0, 480.0, 600.0, 720.0 },

  /* Computed Parameter: QLHvsFHz_bp01Data
   * Referenced by: '<S1>/Q (L//H) vs. F (Hz)'
   */
  { 16U, 33U, 49U, 66U, 82U, 90U },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S28>/Logic'
   */
  { false, true, false, false, true, true, false, false }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
