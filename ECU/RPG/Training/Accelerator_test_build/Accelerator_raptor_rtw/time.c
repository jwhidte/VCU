/*****************************************************************************
   time.c
   Generated By:
   Raptor 2022b_1.0.14751 (6897)
   Matlab (R2022b) 9.13

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Mon Apr 22 19:52:38 2024
 *****************************************************************************/

#include "Accelerator.h"
#include "Accelerator_private.h"
#include "rtwtypes.h"
#include "codegen_hwe_cpu.h"
#include "e_rtatr.h"
#include "cpu_pub.h"

uint32_T ticks_us_i(void)
{
  /*MUST BE CALLED WITH INTERUPTS DISABLED*/
  static uint32 _ticksus = 0;
  static uint32 _last_ticksus = 0;
  uint32 current = 0;
  current = swsh_tick2us();            /* rolls over ever 47721858 uSeconds */
  if (current < _last_ticksus) {
    /* Rollover detected */
    _ticksus += (47721858 - _last_ticksus) + current + 1;
  } else {
    _ticksus += (current - _last_ticksus);
  }

  _last_ticksus = current;
  return _ticksus;
}

uint32_T ticks_us(void)
{
  uint32 current = 0;
  SuspInt();
  current = ticks_us_i();
  ResInt();
  return current;
}

uint32_T ticks_i(void)
{
  /*MUST BE CALLED WITH INTERUPTS DISABLED*/
  static uint32 _ticksms = 0;
  static uint32 _last_ticksms = 0;
  uint32 current = ticks_us_i()/1000;
  if (current < _last_ticksms) {
    /* Rollover detected */
    _ticksms += (0x418937 - _last_ticksms) + current + 1;
  } else {
    _ticksms += (current - _last_ticksms);
  }

  _last_ticksms = current;
  return _ticksms;
}

uint32_T ticks(void)
{
  uint32 current = 0;
  SuspInt();
  current = ticks_i();
  ResInt();
  return current;
}