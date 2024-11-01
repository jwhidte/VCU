/*****************************************************************************
   raptor_time.c
   Generated By:
   Raptor 2022b_1.0.14751 (6897)
   Matlab (R2022b) 9.13

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Mon Apr 15 22:06:38 2024
 *****************************************************************************/

#include "Accelerator_test_build.h"
#include "Accelerator_test_build_private.h"
#include "rtwtypes.h"
#include "codegen_hwe_cpu.h"
#include "e_rtatr.h"
#include "cpu_pub.h"

uint32_T abs_time_lo = 0;
uint32_T abs_time_hi = 0;
void UpdateAbsTime(void)
{
  uint32_T currentT = 0;
  SuspInt();
  currentT = ticks_i();
  if (currentT < abs_time_lo)
    abs_time_hi++;
  abs_time_lo = currentT;
  ResInt();
}

real32_T GetAbsTime(void)
{
  real32_T time = 0;
  uint32_T currentT = 0;
  SuspInt();
  currentT = ticks_i();
  if (currentT < abs_time_lo)
    abs_time_hi++;
  abs_time_lo = currentT;
  time = abs_time_hi;
  time *= 4294967.296f;
  time += (real32_T)(abs_time_lo * 0.001f);
  ResInt();
  return time;
}
