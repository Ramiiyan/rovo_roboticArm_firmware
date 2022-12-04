#ifndef SERVO_MOTOR_H 
#define SERVO_MOTOR_H

//#include <ESP32Servo.h>  // ESP32Servo Library
//#include <Servo.h>  //servo library
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>

#include <Arduino.h>

// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width


 
#define SERVOMIN  80  // Minimum value
#define SERVOMAX  600  // Maximum value


class ServoMotor {
  //private variables. 
  // Soon will include full servo specifications. 
  private:
    byte servo_DIOpin;
    int servo_AIpin;
    //Servo servo_Obj;
    
    unsigned int servo_Range_Min;
    unsigned int servo_Range_Max;
    
  public:
    ServoMotor();
    ServoMotor(byte servo_DIOpin, int servo_AIpin);
    void init();
    void switch_To_control();
    void switch_To_monitor();
    void calibrate_Range(int d_of_min, int d_of_max);
    long cur_Pos(int d_of_min, int d_of_max);
    void control(int pos);
    
};

#endif
