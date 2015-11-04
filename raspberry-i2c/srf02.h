/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 David Schwarzmann
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Header file that defines all necessary information that is written in the datasheet.
 * Additionally there are some methods declared that offer some utility for handling
 * the srf02 sensor.
 */
#ifndef srf02_h
#define srf02_h

// Address of the sensore concerning the datasheet
#define SRF02_ADDR 	0xE0

// SFR02 registers
// Software firmware version
#define SRF02_R0 		0x00
// Calculate distance via: (SRF02_R2 + 256) + SRF02_R3
// Distance high-byte
#define SRF02_R2 		0x02
// Distance low-byte
#define SRF02_R3 		0x03

// Types of measurement
// Measure distance in inches
#define SRF02_MEASURE_IN	0x50
// Measure distance in centimeters
#define SRF02_MEASURE_CM	0x51
// Measure time in microseconds
#define SRF02_MEASURE_MCS	0x52

#define SRF02_SYNC_MEASURE_IN		0x56
#define SRF02_SYNC_MEASURE_CM		0x57
#define SRF02_SYNC_MEASURE_MCS 	0x58

#include <time.h>

#include "i2c.h"

void wait_ns(long);
void wait_ms(long);
void wait_s(long);

int  get_firmware_version(int*);
void get_distance_cm(int*, int*);
void get_time_mcs(int*, int*);

#endif /* srf02_h */
