/*
  clock-arch.c - Arduino implementation of uIP clock devie.
  Copyright (c) 2010 Adam Nielsen <malvineous@shikadi.net>
  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#if (ARDUINO >= 100)
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "clock-arch.h"

static volatile unsigned long seconds = 0;

clock_time_t 
clock_time(void)
{
	return (clock_time_t)millis();
}

/*---------------------------------------------------------------------------*/
void
clock_init(void)
{
  
}
/*---------------------------------------------------------------------------*/
unsigned long
clock_seconds(void)
{
  return clock_time()/1000;
}
/*---------------------------------------------------------------------------*/
void
clock_set_seconds(unsigned long sec)
{
  seconds = sec;
}
/*---------------------------------------------------------------------------*/
void
clock_delay(unsigned int i)
{
  for(; i > 0; i--) {
    unsigned int j;
    for(j = 50; j > 0; j--) {
      asm ("nop");
    }
  }
}
/*---------------------------------------------------------------------------*/
/* Wait for a multiple of clock ticks (7.8 ms at 128 Hz). */
void
clock_wait(clock_time_t t)
{
  clock_time_t start;
  start = clock_time();
  while(clock_time() - start < (clock_time_t)t) ;
}
/*---------------------------------------------------------------------------*/

