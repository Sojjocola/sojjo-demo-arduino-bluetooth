#include <Servo.h>

int redLedPin = 9;
int orangeLedPin = 10;
int greenLedPin = 11;
int state = 0;
int flag = 0;        
Servo monServo;

void setup() {
    // sets the pins as outputs:
    pinMode(redLedPin, OUTPUT);
    pinMode(orangeLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    digitalWrite(redLedPin, LOW);
    digitalWrite(orangeLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    monServo.attach(5);
    Serial.begin(9600); 
}

void loop() {
    //if some data is sent, read it and save it in the state variable
    if(Serial.available() > 0){
      state = Serial.read();
      flag=0;
    }
    // if the state is 0 the red led will turn off
    if (state == '0') {
        digitalWrite(redLedPin, LOW);
        if(flag == 0){
          Serial.println("red LED: off");
          flag = 1;
        }
    }
    // if the state is 1 the red led will turn on
    else if (state == '1') {
        digitalWrite(redLedPin, HIGH);
        if(flag == 0){
          Serial.println("red LED: on");
          flag = 1;
        }
    }
     // if the state is 2 the orange led will turn off
    else if (state == '2') {
        digitalWrite(orangeLedPin, LOW);
        if(flag == 0){
          Serial.println("orange LED: off");
          flag = 1;
        }
    }
    // if the state is 3 the orange led will turn on
     else if (state == '3') {
        digitalWrite(orangeLedPin, HIGH);
        if(flag == 0){
          Serial.println("orange LED: on");
          flag = 1;
        }
    }
     // if the state is 4 the green led will turn off
    else if (state == '4') {
        digitalWrite(greenLedPin, LOW);
        if(flag == 0){
          Serial.println("green LED: off");
          flag = 1;
        }
    }
    // if the state is 5 the green led will turn on
     else if (state == '5') {
        digitalWrite(greenLedPin, HIGH);
        if(flag == 0){
          Serial.println("green LED: on");
          flag = 1;
        }
    }
    else if (state == '6') {
       monServo.write(90);
        if(flag == 0){
          Serial.println("servo: open");
          flag = 1;
        }
    }
    else if (state == '7') {
        monServo.write(0);
        if(flag == 0){
          Serial.println("servo: close");
          flag = 1;
        }
    }
}
