#include <Arduino.h>

void setup() {
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT);  //Initiates Brake Channel A pin
  delay(1000);
}

void loop(){
  digitalWrite(12, LOW); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);  //Disengage the Brake for Channel A

  analogWrite(3, 120);   //Spins the motor on Channel A at slow speed
  delay(2000);

  digitalWrite(9, HIGH); //Engage the Brake for Channel A
  delay (3000);
}
