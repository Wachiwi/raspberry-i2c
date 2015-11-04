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

#include <stdio.h>
#include <stdlib.h>

#include "srf02.h"

int main(int argc, const char * argv[]) {
	// Open logfile - pathname
	int lfd = open("values.log",
								 // Flags: Open read and write or create if it does not exist
								 O_RDWR | O_CREAT,
								 // Mode: Results in -rw-r--r--
								 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	// Calling the init method to open and initialize the i2c-bus
	int i2c_desc = init_i2c(SRF02_ADDR);

	if (i2c_desc > 0) {
		// Read firmware of srf02 sensor (should be version 6)
		int fw_version = get_firmware_version(&i2c_desc);
		// printf("DEBUG: FW version: %d\n", fw_version);

		do {
			int *distance = malloc(3 * sizeof(int)),
					*delta_time = malloc(3 * sizeof(int));

			// Start Measurement
			get_distance_cm(&i2c_desc, distance);

			// Measure time
			// get_time_mcs(&i2c_desc, delta_time);

			if(lfd > 0) {
				char *s = malloc(sizeof(int) + 2);
				printf("Measured distance: %dcm\n", distance[0]);
				sprintf(s, "%d\n", distance[0]);
				write(lfd, s, sizeof(int) + 2);
				// free(s);
			}

			// Wait 1s before repeating measurement process
			wait_s(1);

			// free(distance);
			// free(delta_time);

			// Total execution time of loop is around 1.1-1.2s
		} while(1);

		// Close opened files
		close(lfd);
		close(i2c_desc);

		return 0;
	}
	
	// Close opened files
	close(lfd);

	return (i2c_desc * -1);
}
