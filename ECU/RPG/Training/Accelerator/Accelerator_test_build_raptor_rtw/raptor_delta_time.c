/*****************************************************************************
   raptor_delta_time.c
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

uint32_T GetDeltaTime_us(uint32_T* last)
{
  uint32_T current_ticks = ticks_us();
  uint32_T delta = 0;
  if (*last > current_ticks) {
    delta = (0xFFFFFFFF - *last) + current_ticks + 1;
  } else {
    delta = current_ticks - *last;
  }

  *last = current_ticks;
  return delta;
}

uint32_T GetDeltaTime_ms(uint32_T* last)
{
  uint32_T current_ticks = ticks();
  uint32_T delta = 0;
  if (*last > current_ticks) {
    delta = (0xFFFFFFFF - *last) + current_ticks + 1;
  } else {
    delta = current_ticks - *last;
  }

  *last = current_ticks;
  return delta;
}
