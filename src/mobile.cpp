#include <Arduino.h>

int const directionPin = 12;
int const pwmPin       = 3;
int const brakePin     = 9;

void setup() {
    // Setup Channel A
    pinMode (directionPin, OUTPUT);    // Initiates Motor Channel A pin
    pinMode (brakePin, OUTPUT);        // Initiates Brake Channel A pin
    digitalWrite (directionPin, LOW);  // Establishes forward direction of Channel A
}

typedef struct {
    unsigned char pwm;
    int           duration;
} Pulse;

Pulse pulses[] = {
    {100, 200},  //
    {200, 500},  //
    {255, 700},  //
    {0, 15000},   //
};

int const num_pulses = sizeof (pulses) / sizeof (Pulse);

void loop() {
    digitalWrite (brakePin, LOW);  // Disengage the Brake for Channel A

    for (int ii = 0; ii < num_pulses; ++ii) {
        analogWrite (pwmPin, pulses[ii].pwm);  // Spins the motor on Channel A at slow speed
        delay (pulses[ii].duration);
    }

    //    digitalWrite (brakePin, HIGH);  // Engage the Brake for Channel A
}
