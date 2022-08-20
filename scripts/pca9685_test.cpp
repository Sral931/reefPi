
// g++ pca9685_text.cpp -o pca9685_test
// ./pca9685_test

#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <sys/ioctl.h> // required for I2C device usage
#include <linux/i2c-dev.h> // required for constant definitions

int i2cAddress = 64;
int probeI2Cfile;  // used when reading and writing to I2C bus
char inData[1];  // incoming data
char command[3];  // instructions to send to circuit

int main(int argc, char *argv[])
{
	// init
	char *filename = (char*)"/dev/i2c-1";  // Define the i2c file path
	probeI2Cfile = open(filename, O_RDWR);  // open file for read and right
	
	// output header
	std::cout <<"PCA9685 Test Script" << std::endl;
	double value = 0;
	if (argc > 1) i2cAddress = atoi(argv[1]);

	std::cout <<"Using i2cAddress        " << i2cAddress << std::endl;
	std::cout <<"------------------------" << std::endl;
	
	// open connection to PCA9685
	if (ioctl(probeI2Cfile, I2C_SLAVE, i2cAddress) < 0)
	{
		std::cout << "Failed to acquire bus access" << std::endl;
	}
	
	// send command
	command[0] = 0x52;
	write(probeI2Cfile, command, 1);
	sleep(0.05);
	
	// read
	short length = 1;  // Number of bytes to read
	if (read(probeI2Cfile, inData, 1) != length) {
		std::cout << "Failed to read from circuit." << std::endl;
	}
	else 
	{
		std::cout <<"preScaler = " << std::to_string(inData[0]) << std::endl;
	}
	
	i2cAddress += 1;
	
	std::cout <<"Using i2cAddress        " << i2cAddress << std::endl;
	std::cout <<"------------------------" << std::endl;
	
	// open connection to PCA9685
	if (ioctl(probeI2Cfile, I2C_SLAVE, i2cAddress) < 0)
	{
		std::cout << "Failed to acquire bus access" << std::endl;
	}
	
	// send command
	command[0] = 0x52;
	write(probeI2Cfile, command, 1);
	sleep(0.05);
	
	// read
	length = 1;  // Number of bytes to read
	if (read(probeI2Cfile, inData, 1) != length) {
		std::cout << "Failed to read from circuit." << std::endl;
	}
	else 
	{
		std::cout <<"preScaler = " << std::to_string(inData[0]) << std::endl;
	}
}
