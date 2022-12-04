#include <ArduinoJson.h> //json decoder

#define SERVO_COUNT   4  //{{servo_count_dof}} // based on robotic arm type

/* Wroom ESP32 Servo-motor Control Digital Pins 
//  PCA9685 Driver(16 channels) PINs - 0-16
*/
const byte servo_DPins[SERVO_COUNT] = {3,7,11,15};  //{{Dpin_list}};  // 0-16

/* Wroom ESP32 Servo-motor Feedback Analog Pins */
const int servo_APins[SERVO_COUNT] = {27,33,19,23}; //{{Apin_list}}; //  13,27,33,19,23,15

/*int array1[ rows-2 ][ columns-3 ] = { { 1, 2, 3 }, { 4, 5, 6 } }; EXAMPLE. */
//{{servo_range_list}}; //{ {0, 180}, {0, 180} };
const int servo_range [SERVO_COUNT] [2] = { {0, 180}, {0, 180},{0, 180},{0, 180} };

DynamicJsonDocument doc(512);
void myDeserialize(String getmsg);
//void controller(String getVal);
