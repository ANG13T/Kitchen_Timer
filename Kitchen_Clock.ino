#include <Servo.h>

Servo dial;

int potpin = 0; //base
int potVal;
const int warningLight = 11;
const int greenLight = 10;
const int speaker = 9;
const int buttonInput = 12;
int buttonVal;
int newPotVal;

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(warningLight, OUTPUT);
  pinMode(buttonInput, INPUT);
  dial.attach(8);
  dial.write(0);
}

void loop() {
  potVal = analogRead(potpin);
  potVal = map(potVal, 0, 1023, 0, 180);
  buttonVal = digitalRead(buttonInput);
  
  if(buttonVal == HIGH){
    int remainder = potVal % 6;
    newPotVal = potVal - remainder;
    Serial.println(potVal);
    moveDial(newPotVal);
    delay(1000);
  }
  
  digitalWrite(speaker, LOW);
  
}

void moveDial(int val){
  Serial.println(val);
  for(int i = val; i >= 0; i-= 6){
    dial.write(i);
    delay(1000);
  }
  digitalWrite(warningLight, HIGH);
  digitalWrite(speaker, HIGH);
  delay(2000);
  digitalWrite(warningLight, LOW);
  digitalWrite(speaker, LOW);
}
