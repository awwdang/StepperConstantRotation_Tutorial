// Stepper Motor Continous Rotation with Joystick Input
// Brandon Dang
// 03/03/2016

/*
 * Manual input control of the stepper motor is handled by connecting a joystick horizontal or vertical pin
 * to the A0Pin of an Arduino Board. Functionality of the system works like a D-Pad. Pulling the stick in 
 * either direction will trigeger the movement loops below and cause the motor to perform one step at a time
 * in it's relative direction.
 * 
 * EasyDriver boards are rated for up to 30V and 700mA. The amperage can be adjusted by turning the
 * potentiometer knob on the board itself to allow for a current range of 0 to 700mA
 */

#define step_pin 3    //Connected to Steps pin on EasyDriver
#define dir_pin 2     //Connected to Direction pin
#define MS1 5         //Connected to MS1 pin
#define MS2 4         //Connected to MS2 pin
#define inA0Pin A0    //Connected to an Analog Input, change to PWM pin for Taranis Control

/*
 * Wires from the Bipolar Stepper Motor correlate to the positive and negative ends of the magnetic 
 * coils inside a Bipolar Stepper Motor. Using the EasyDriver board, positive ends of the coils need 
 * to be attached to A positive and B positive, and negative ends fo the coils to be attached to
 * A negative and B negative.
 * Check the specification sheets of a stepper motor for a hookup guides.
 */
 
int direction;      //Counter Clockwise/Clockwise Rotation Variable

void setup() {
   /*
    * Setting Pins as OUTPUT to the Stepper
    */
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(dir_pin, OUTPUT);
   pinMode(step_pin, OUTPUT);
  
   delay(5000);               // Delay to allow user preparation and hookup
   digitalWrite(MS1, LOW);    // Full Steps Initialization
   digitalWrite(MS2, LOW);    // Full Steps Initialization   
}

void loop() {
/*
 * INCOMPLETE, inA0Pin needs to be mapped to its specific input device
 * inA0Pin compare values below used a Analog Joystick as an Input.
 * Joystick has a Default value of 512, with an operating range of 0 to 1024
 */
  while (analogRead(inA0Pin) >= 0 && analogRead(inA0Pin) <= 200) {
    digitalWrite(dir_pin, HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
    digitalWrite(step_pin, HIGH);
    delay(5);
    digitalWrite(step_pin, LOW);
    delay(5);     
  }
  while (analogRead(inA0Pin) >= 800 && analogRead(inA0Pin) <= 1024) {
    digitalWrite(dir_pin, LOW);
    digitalWrite(step_pin, HIGH);
    delay(5);
    digitalWrite(step_pin, LOW);
    delay(5);
  }
}
