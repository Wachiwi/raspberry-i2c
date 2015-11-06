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

#include "srf02.h"

/* Method that puts the program to sleep for a given time.
 *
 * @param ns - Specifies the nanoseconds you want to sleep.
 */
void wait_ns(long ns) {
	struct timespec req = {0};
	req.tv_nsec = ns;
	nanosleep(&req, NULL);
}

/* Method that puts the program to sleep for a given time.
 *
 * @param ns - Specifies the milliseconds you want to sleep.
 */
void wait_ms(long ms) {
	long i = 0;
	while(i < ms) {
		wait_ns(1000000L);
		i++;
	}
}

/* Method that puts the program to sleep for a given time.
 *
 * @param ss - Specifies the seconds you want to sleep.
 */
void wait_s(long s){
	long i = 0;
	while(i < s) {
		wait_ms(1000);
		i++;
	}
}

/* Simple method to read the firmware version of the sensor.
 *
 * @param fd - This is the reference to the file handle of the opened i2c-bus.
 *
 * Returns the firmware version as an integer.
 */
int  get_firmware_version(int *fd) {
	return read_i2c_byte_data(fd, SRF02_R0);
}


/* Simple method to read the measured distance of the srf02 sensor.
 *
 * @param fd 		 - This is the reference to the file handle of the opened i2c-bus.
 * @param values - This is the reference to a variable owned by the caller that will 
 *								 contain the measured values as an array:
 * 								 	[0] = calculated distance by adding the lowbyte to the highbyte
 * 									[1] = highbyte of measurement
 * 									[2] = lowbyte of measurement
 */
void get_distance_cm(int *fd, int *values) {
	int status = 0;

	status = write_i2c_byte_data(fd, SRF02_R0, SRF02_MEASURE_CM);

	// Wait 100ms for measurement to complete.
	// Datasheet value is 65ms but I added some time as backup.
	wait_ms(100);

	values[1] = read_i2c_byte_data(fd, SRF02_R2);
	values[2] = read_i2c_byte_data(fd, SRF02_R3);

	// printf("DEBUG: Value high byte:\t%d\n", values[1]);
	// printf("DEBUG: Value low byte:\t%d\n", values[2]);

	if (values[1] > 0) {
		values[1] += 256;
	}

	// Calculate the result by adding the lowbyte to the highbyte
	values[0] = values[1] + values[2];

	// printf("DEBUG: Calculated distance:\t%dcm\n", values[0]);
}

/* Simple method to read the measured time of the srf02 sensor.
 *
 * @param fd 		 - This is the reference to the file handle of the opened i2c-bus.
 * @param values - This is the reference to a variable owned by the caller that will
 *								 contain the measured values as an array:
 * 								 	[0] = calculated time by adding the lowbyte to the highbyte
 * 									[1] = highbyte of measurement
 * 									[2] = lowbyte of measurement
 */
void get_time_mcs(int *fd, int *values) {
	int status = 0;

	status = write_i2c_byte_data(fd, SRF02_R0, SRF02_MEASURE_MCS);

	// Wait 100ms for measurement to complete.
	// Datasheet value is 65ms but I added some time as backup.
	wait_ms(100);

	values[1] = read_i2c_byte_data(fd, SRF02_R2);
	values[2] = read_i2c_byte_data(fd, SRF02_R3);

	// printf("DEBUG: Value high byte:\t%d\n", values[1]);
	// printf("DEBUG: Value low byte:\t%d\n", values[2]);

	if (values[1] > 0) {
		values[1] += 256;
	}

	// Calculate the result by adding the lowbyte to the highbyte
	values[0] = values[1] + values[2];

	// printf("Measured time: %dmicrosecond\n", values[0]);
}