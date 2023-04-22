#include <Servo.h>

#define Button_Pin 14 // GIOP21 pin connected to button
#define LServo_Pin 12 //GPIO 12 Left servo pin
#define RServo_Pin 13 //GPIO 13 Right servo pin

// Variables will change:
int buttonState;
//int lastState = 1; // the previous state from the input pin
//int currentState = 1;     // the current reading from the input pin
//int tempState;
bool state = false;

Servo LServo;
Servo RServo;

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an pull-up input
  pinMode(Button_Pin, INPUT_PULLUP);
  LServo.attach(LServo_Pin);
  RServo.attach(RServo_Pin);
  
}

void loop() {
  // read the state of the switch/button:
  buttonState = digitalRead(Button_Pin);

  if (buttonState != HIGH){
  state = !state;
    if(state == true){
      Serial.println("1");
      LServo.write(130);
      RServo.write(60);
      delay (400);

    }
    if(state == false){
      Serial.println("-1");
      LServo.write(90);
      RServo.write(115);
      delay (400);
    }
  }
  

  /*if(lastState == LOW && currentState == HIGH){
    Serial.println("The state changed from LOW to HIGH");
    LServo.write(130);
    RServo.write(60);
    delay (1000);
    LServo.write(80);
    RServo.write(115);
    delay (1000);
  }*/

  // save the last state
  //lastState = currentState;
}
