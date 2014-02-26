
#include <Servo.h>

const int buttonPin = 3;  // trigger's button
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
Servo myservo;
Servo myservo1;
Servo myservo2;
void setup() {   
  // initialize the pushbutton pin as an input:
  myservo.attach(9);
  myservo1.attach(10);
  myservo2.attach(11);
  pinMode(buttonPin, INPUT);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {   
    myservo2.write(0);
    delay(3000);
    myservo.write(0);
    delay(2000);
    myservo2.write(180);
    delay(3000);
    myservo.write(90);
  } 
  
  else {
    myservo.write(90);
    myservo2.write(180);
    // read the state of the pushbutton value:
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
    val = map(val, 0, 1023, 110, 160);     // scale it to use it with the servo (value between 0 and 180) 
    myservo1.write(val);     // sets the servo position according to the scaled value 
  }
}
