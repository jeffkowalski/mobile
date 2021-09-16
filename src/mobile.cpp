#include <Arduino.h>

int const directionPin = 12;
int const pwmPin       = 3;
int const brakePin     = 9;

void setup() {
    // Setup Channel A
    pinMode (directionPin, OUTPUT);  // Initiates Motor Channel A pin
    pinMode (brakePin, OUTPUT);      // Initiates Brake Channel A pin
    delay (1000);
}

void loop() {
    digitalWrite (directionPin, LOW);  // Establishes forward direction of Channel A
    digitalWrite (brakePin, LOW);      // Disengage the Brake for Channel A

    analogWrite (pwmPin, 120);  // Spins the motor on Channel A at slow speed
    delay (2000);

    digitalWrite (brakePin, HIGH);  // Engage the Brake for Channel A
    analogWrite (pwmPin, 0);        // Turn motor off
    delay (3000);
}
