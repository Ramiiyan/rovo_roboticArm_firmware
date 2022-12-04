// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>
 
// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width
 
#define SERVOMIN  80  // Minimum value
#define SERVOMAX  600  // Maximum value

// Define servo motor connections (expand as required)
#define SER0  3   //Servo Motor 0 on connector 0
#define SER1  12  //Servo Motor 1 on connector 12
