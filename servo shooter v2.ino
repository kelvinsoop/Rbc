#include <Servo.h>

#define Button_Pin 7 // GIOP21 pin connected to button
#define LServo_Pin 5 //GPIO 12 Left servo pin
#define RServo_Pin 3 //GPIO 13 Right servo pin

// Variables will change:
int buttonState;
//int lastState = 1; // the previous state from the input pin
//int currentState = 1;     // the current reading from the input pin
//int tempState;
bool state = false;
bool a = false;

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
 //buttonState = digitalRead(Button_Pin);


    if(digitalRead(Button_Pin) != HIGH && !state){
      a = !a;
      if (a){
        Serial.println(a);
        LServo.write(80);
        RServo.write(115);
        delay(200);
      }
      else{
      	LServo.write(130);
    	RServo.write(60);
        delay(200);
      }
      state = true;
    }
  	
    else if(digitalRead(Button_Pin) == HIGH){
      state = false;
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
