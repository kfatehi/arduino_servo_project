//Knob_servo_4ch Modified from Keyvan’s 2 channel code
//Most comments are from Keyvan for Dad
#include <Servo.h>
Servo servoA;  // create servo object to control a servo
Servo servoB;  // create servo object to control another servo
Servo servoC;  // create servo object to control 3rd servo
Servo servoD;  // create servo object to control 4th servo
 
// These constants won't change.  They're used to give names
// to the pins used:
const int potA_Pin = A0;  // Analog input pin that potentiometer A is attached to
const int potB_Pin = A1;  // Analog input pin that potentiometer B is attached to
const int potC_Pin = A2;  // Analog input pin that potentiometer A is attached to
const int potD_Pin = A3;  // Analog input pin that potentiometer B is attached to
 
const int servoA_Pin = 9; // Analog output pin that servo A is attached to
const int servoB_Pin = 10; // Analog output pin that servo B is attached to
const int servoC_Pin = 11; // Analog output pin that servo C is attached to
const int servoD_Pin = 12; // Analog output pin that servo D is attached to
 
//Input initializations?
int potA_Value = 0;        // value read from the pot A
int potB_Value = 0;        // value read from the pot B
int potC_Value = 0;        // value read from the pot C
int potD_Value = 0;        // value read from the pot D
 
//Output initializations
int servoA_Value = 0;        // value output to servo A
int servoB_Value = 0;        // value output to servo B
int servoC_Value = 0;        // value output to servo C
int servoD_Value = 0;        // value output to servo D
 
 
int ServoMin = 5;            // Stetting the min and max limits to limit range and also to prevent chatter.
int ServoMax = 175;        //MF: Still chattering a bit. May need make limits 10 degrees.
 
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  servoA.attach(servoA_Pin); // tell the servoA object which pin to use
  servoB.attach(servoB_Pin); // tell the servoB object which pin to use
  servoA.attach(servoC_Pin); // tell the servoC object which pin to use
  servoB.attach(servoD_Pin); // tell the servoD object which pin to use
}
 
void loop() {
  // read the analog in values:
  potA_Value = analogRead(potA_Pin);
  servoA_Value = map(potA_Value, 0, 1023, ServoMin, ServoMax);  // Servos take 0 to 179, not 0 to 254
  servoA.write(servoA_Value); // Write the mapped value (from 0 to 179) to the servo
 
  potB_Value = analogRead(potB_Pin);
  servoB_Value = map(potB_Value, 0, 1023, ServoMin, ServoMax);  // Servos take 0 to 179, not 0 to 254
  servoB.write(servoB_Value); // Write the mapped value (from 0 to 179) to the servo
 
  potC_Value = analogRead(potC_Pin);
  servoC_Value = map(potC_Value, 0, 1023, ServoMin, ServoMax);  // Servos take 0 to 179, not 0 to 254
  servoC.write(servoC_Value); // Write the mapped value (from 0 to 179) to the servo
 
  potD_Value = analogRead(potD_Pin);
  servoD_Value = map(potD_Value, 0, 1023, ServoMin, ServoMax);  // Servos take 0 to 179, not 0 to 254
  servoD.write(servoD_Value); // Write the mapped value (from 0 to 179) to the servo
 
 
 
  // If we were not using servo library, this is the raw way to change the analog out value:
  //analogWrite(analogOutPin, outputValue);
 
  // print the results to the serial monitor:
  Serial.print("servoA_Value = " );                      
  Serial.print(servoA_Value);     
  Serial.print("\t servoB_Value = ");     
  Serial.println(servoB_Value);  
  Serial.print("\t servoC_Value = " );                      
  Serial.print(servoC_Value);     
  Serial.print("\t servoD_Value = ");     
  Serial.println(servoD_Value);  
 
  // wait 10 (25?) milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  // and for the servo to go where it needs to go.
  delay(25);
}
