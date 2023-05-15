/*
  ESP32 PCA9685 Servo Control
  esp32-pca9685.ino
  Driving multiple servo motors with ESP32 and PCA9685 PWM module
  Use I2C Bus
 
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/
 
// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>
 
// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);
 
// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width
 
#define SERVOMIN  80  //80-default  // Minimum value
#define SERVOMAX  600  // Maximum value

#define SERVOCOUNT 4

// Define servo motor connections (expand as required)
#define SER0  3   //Servo Motor 0 on connector 0
#define SER1  7   //Servo Motor 1 on connector 7
#define SER2  11  //Servo Motor 2 on connector 11
#define SER3  15  //Servo Motor 3 on connector 15

// Variables for Servo Motor positions (expand as required)
int pwmArr[SERVOCOUNT]; 

int servoArr[SERVOCOUNT] = {SER0, SER1, SER2, SER3};
 
void setup() {
 
  // Serial monitor setup
  Serial.begin(115200);
 
  // Print to monitor
  Serial.println("PCA9685 Servo Test");
 
  // Initialize PCA9685
  pca9685.begin();
 
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);
  pca9685.setPWM(SER0, 0, 4096); // OFF the servo
//  pca9685.setPWM(SER1, 0, 4096); // OFF the servo
//  pca9685.setPWM(SER2, 0, 4096); // OFF the servo
//  pca9685.setPWM(SER3, 0, 4096); // OFF the servo
 
}
 
void loop() {
//  for (int i= 0; i <SERVOCOUNT; i++){
//    
//    Serial.print("=============== Servo ID: ");
//    Serial.print(servoArr[i]);
//    Serial.println("===============");

    int posDegrees = 0;
    
    // Move Motor 0 from 0 to 180 degrees
    for (posDegrees = 0; posDegrees <= 180; posDegrees++) {
   
      // Determine PWM pulse width
      //pwm0 = map(posDegrees, 0, 180, SERVOMIN, SERVOMAX);  // sample
      pwmArr[0] = map(posDegrees, 0, 180, SERVOMIN, SERVOMAX);
      
      // Write to PCA9685
      //pca9685.setPWM(SER0, 0, pwm0);  //sample
 
      // Print to serial monitor
      Serial.print("Position = ");
      Serial.println(posDegrees);
      delay(30);
    }
    //pca9685.setPWM(servoArr[i], 0, 4096); // OFF the servo
    Serial.print("Delay... 5 sec - position: ");
    Serial.println(posDegrees);
    delay(5000);
//  }
  delay(1000);
}
