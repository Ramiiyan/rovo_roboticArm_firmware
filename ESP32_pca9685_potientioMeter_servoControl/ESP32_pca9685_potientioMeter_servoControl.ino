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
 
// Create object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);
 
// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width
 
#define SERVOMIN  80  //80-default  // Minimum value
#define SERVOMAX  600  // Maximum value

#define SERVOCOUNT 5

// Define servo motor connections (expand as required)
#define SER0  3   //Servo Motor 0 on connector 0
#define SER1  5   //Servo Motor 1 on connector 7
#define SER2  7   //Servo Motor 1 on connector 7
#define SER3  11  //Servo Motor 2 on connector 11
#define SER4  15  //Servo Motor 3 on connector 15

#define SER_CLAW  0  //Servo Motor Claw on connector 0


static const int potentiometerPin = 4;// pin printed as G4 or 4

// Variables for Servo Motor positions (expand as required)
int pwmArr[SERVOCOUNT]; 
int pwm_Claw, pwm_Claw_i;

int servoArr[SERVOCOUNT] = {SER0, SER1, SER2, SER3, SER4};
 
void setup() {
 
  // Serial monitor setup
  Serial.begin(115200);
 
  // Print to monitor
  Serial.println("PCA9685 Servo Test");
 
  // Initialize PCA9685
  pca9685.begin();
 
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);
 
  // Turn off all the servo motors initially
  for (int i = 0; i < SERVOCOUNT; i++) {
    pca9685.setPWM(servoArr[i], 0, 4096); // OFF the servo
  }
    
  pca9685.setPWM(SER_CLAW, 0, 4096); // OFF the servo

  //set the claw to 0. (closed state)
  pwm_Claw_i = map(0, 0, 180, SERVOMIN, SERVOMAX);
      
  // Write to PCA9685 (set the Claw to 0)
  pca9685.setPWM(SER_CLAW, 0, pwm_Claw_i);

//  // Open the claw  (0 to 5 degrees
//    for (int posDegrees = 0; posDegrees <= 5; posDegrees++) {
//   
//      // Determine PWM pulse width
//      pwm_Claw = map(posDegrees, 0, 180, SERVOMIN, SERVOMAX);
//      
//      // Write to PCA9685
//      pca9685.setPWM(SER_CLAW, 0, pwm_Claw);
// 
//      // Print to serial monitor
//      Serial.print("Claw Position = ");
//      Serial.println(posDegrees);
//      
//      delay(30);
//    }

    // Close the claw  (5 to 0 degrees)
//    for (int posDegrees = 5; posDegrees >= 0; posDegrees--) {
//   
//      // Determine PWM pulse width
//      pwm_Claw = map(posDegrees, 0, 180, SERVOMIN, SERVOMAX);
//      
//      // Write to PCA9685
//      pca9685.setPWM(SER_CLAW, 0, pwm_Claw);
// 
//      // Print to serial monitor
//      Serial.print("Claw Position = ");
//      Serial.println(posDegrees);
//      
//      delay(30);
//    }
    
    
    // Turn off the motor after reaching 180 degrees
    //pca9685.setPWM(SER_CLAW, 0, 4096); // OFF the servo
}
 
void loop() {
  // Loop through all the servo motors
//  for (int i = 0; i < SERVOCOUNT; i++) {
//    
//    Serial.print("=============== Servo ID: ");
//    Serial.print(servoArr[i]);
//    Serial.println("===============");
//    
//    // Move each motor from 0 to 180 degrees
//    for (int posDegrees = 0; posDegrees <= 180; posDegrees++) {
//   
//      // Determine PWM pulse width
//      pwmArr[i] = map(posDegrees, 0, 180, SERVOMIN, SERVOMAX);
//      
//      // Write to PCA9685
//      pca9685.setPWM(servoArr[i], 0, pwmArr[i]);
// 
//      // Print to serial monitor
//      Serial.print("Position = ");
//      Serial.println(posDegrees);
//      
//      delay(30);
//    }
//    
//    // Turn off the motor after reaching 180 degrees
//    //pca9685.setPWM(servoArr[i], 0, 4096); // OFF the servo
//    Serial.print("Delay... 5 sec - position: ");
//    Serial.println(180);
//    delay(5000);
//  }
//  
//  delay(1000);

    // Get the potentiometer value.
    int potentiometerValue = analogRead(potentiometerPin);

    /*
     * Map the potentiometer value to the desired servo angle range. 
     * Assuming the potentiometer provides values between 0 and 1023 and 
       you want to control the servo from 0 to 180 degrees:
    */
    int angle = map(potentiometerValue, 0, 4096, 0, 180);

    /*
     * Set the servo position using the mapped angle value.
     * The PCA9685 library provides a setPWM() function for this purpose:
    */
    int servoPosition = map(angle, 0, 180, SERVOMIN, SERVOMAX);
    
    pca9685.setPWM(SER_CLAW, 0, servoPosition);
    Serial.printf("potentio= %d \n", potentiometerValue);
    Serial.printf("angle= %d \n", angle);
    Serial.printf("servoPostion= %d \n", servoPosition);
    delay(30);

}
