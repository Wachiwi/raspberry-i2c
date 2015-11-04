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

#include "i2c.h"

/*
 * Initializing the i2c bus and the communication to a particular device
 *
 * @param address - The address of the device you want to connect to concerning the datasheet
 *
 * Returns the the id of the file handle (int > 0) if everything was sucessfull. It returns a negative integer
 * if an error occurred. See the documentation of the 'open_i2c_bus' method below.
 */
int init_i2c(int address) {
	// open i2c-bus and get its file descriptor
	int fd = open_i2c_bus();

	if(fd > 0) {
		// Try to init master-slave communication
		if (ioctl(fd, I2C_SLAVE, (address >> 1)) < 0) {
			// Print specific error message depending on the error number
			perror("An error occured while initializing the i2c bus");
		}
	}

	return fd;
}

/*
 * Trys to open the i2c-bus device file ('/dev/i2c-1') and makes it possible to communicate
 * with the i2c-bus device/sensor
 *
 * Returns a file descriptor (int > 0) if everything went right. Otherwise it returns an int less than 0.
 * 	-1 - Could not open i2c bus. See stderr for more information.
 */
int open_i2c_bus() {
	int fd;
	const char *fname = "/dev/i2c-1";

	// Use open() instead of fopen() to prevent buffering issues
	if ((fd = open(fname, O_RDWR)) < 0) {
		// Print specific error message depending on the error number
		perror("An error occured while opening the i2c bus");
		fd = -1;
	}

	return fd;
}

/*
 * Simple wrapper method that makes use of the native i2c fucntions and adds minor error handling.
 *
 * @param *fd 		- Pointer to a integer that contains the file handle
 * @param command - Contains the hex command you want to send to the device
 *
 * Returns the data (int > 0) if everything went right. Otherwise it returns an int less than 0.
 * For more information about errors look at the stderr or the I2C and SMBus Subsystem documentation 
 * of the linux kernel. Search for 'i2c_smbus_read_byte_data'.
 */
int read_i2c_byte_data(int* fd, uint8_t command) {
	int result = i2c_smbus_read_byte_data(*fd, command);

	if (result < 0) 	{
		// Print specific error message depending on the error number
		perror("Failed to read data byte from I2");
	}

	return result;
}

/*
 * Simple wrapper method that makes use of the native i2c fucntions and adds minor error handling.
 *
 * @param *fd 		- Pointer to a integer that contains the file handle
 * @param command - Contains the hex command you want to send to the device. In this case commonly a register.
 * @param value		- Contains the value you want to set
 *
 * Returns the data (int > 0) if everything went right. Otherwise it returns an int less than 0.
 * For more information about errors look at the stderr or the I2C and SMBus Subsystem documentation
 * of the linux kernel. Search for 'i2c_smbus_write_byte_data'.
 */
int write_i2c_byte_data(int* fd, uint8_t command, uint8_t value) {
	int result = i2c_smbus_write_byte_data(*fd, command, value);

	if (result < 0) 	{
		// Print specific error message depending on the error number
		perror("Failed to write data byte to I2");
	}

	return result;
}
