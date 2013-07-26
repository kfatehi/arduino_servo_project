 
//Most comments are from Keyvan for Dad
#include <Servo.h>
Servo servoA;  // create servo object to control a servo
Servo servoB;  // create servo object to control another servo
 
// These constants won't change.  They're used to give names
// to the pins used:
const int potA_Pin = A0;  // Analog input pin that potentiometer A is attached to
const int potB_Pin = A1;  // Analog input pin that potentiometer B is attached to
const int servoA_Pin = 9; // Analog output pin that servo A is attached to
const int servoB_Pin = 10; // Analog output pin that servo B is attached to
 
int potA_Value = 0;        // value read from the pot A
int potB_Value = 0;        // value read from the pot B
int servoA_Value = 0;        // value output to servo A
int servoB_Value = 0;        // value output to servo B
 
int ServoMin = 5;            // Stetting the min and max limits to limit range and also to prevent chatter.
int ServoMax = 175;
 
void setup() {
 // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  servoA.attach(servoA_Pin); // tell the servoA object which pin to use
  servoB.attach(servoB_Pin); // tell the servoB object which pin to use
}
 
void loop() {
  // read the analog in value:
  potA_Value = analogRead(potA_Pin);
  servoA_Value = map(potA_Value, 0, 1023, ServoMin, ServoMax);  // Servos take 0 to 179, not 0 to 254
  servoA.write(servoA_Value); // Write the mapped value (from 0 to 179) to the servo
 
  potB_Value = analogRead(potB_Pin);
  servoB_Value = map(potB_Value, 0, 1023, ServoMin, ServoMax);  // Servos take 0 to 179, not 0 to 254
  servoB.write(servoB_Value); // Write the mapped value (from 0 to 179) to the servo
 
  // If we were not using servo library, this is the raw way to change the analog out value:
  //analogWrite(analogOutPin, outputValue);
 
  // print the results to the serial monitor:
  Serial.print("servoA_Value = " );                      
  Serial.print(servoA_Value);     
  Serial.print("\t servoB_Value = ");     
  Serial.println(servoB_Value);  
 
  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  // And for the servo to go where it needs to go.
  delay(25);
}
