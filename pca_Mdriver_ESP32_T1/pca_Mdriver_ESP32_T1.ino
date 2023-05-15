
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;
uint8_t feedbackPin = 34;


void setup() {
  
  
  Serial.begin(115200);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

// the code inside loop() has been updated by Robojax
void loop() {

    // Initial Feedback read
    int feedbackRead = analogRead(feedbackPin); 
    
    int pluses[] = {125,255,450,575};
    for(int i=0; i<4;i++){
      
      pwm.setPWM(0, 0, pluses[i] );
      Serial.printf("Initial FeedbackRead: %d \n",feedbackRead);
      Serial.printf("Pulse Length: %d \n ",pluses[i]);
      Serial.printf("After pluse adjust FeedbackRead: %d \n",analogRead(feedbackPin));
      delay(1500);
      
    }
    Serial.println("========= End cycle =========");
    
}
