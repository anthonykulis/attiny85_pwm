#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
 
#include "attiny85_pwm.h"


struct attached_t {
  uint8_t counter;
  uint8_t pin;
  uint16_t micros;
  attached_t() : counter(0), pin(-1), micros(0) {}
  void refresh(){
    digitalWrite(pin, HIGH);
    delayMicroseconds(micros);
    digitalWrite(pin, LOW);
  }
};


// Used when there will only be on PWM out
// Allows you to use a simpler write
Attiny85_PWM::Attiny85_PWM(int pin) {
  Attiny85Attached();
  Attiny85Attached.pin = pin;
  OCR0A = 0xAF;
  TIMSK |= _BV(OCIE0A);
}

void Attiny85_PWM::write(uint8_t degrees){
  Attiny85Attached.micros = map(degrees, 180, 1000, 2000);
}

void Attiny85_PWM::write(float duty_cyle){
  uint8_t degrees = duty_cyle/180;
  Attiny85Attached.micros = map(degrees, 180, 1000, 2000);
}

SIGNAL(TIMER0_COMPA_vect) {
  if(++Attiny85Attached.counter >= 10){
    Attiny85Attached.counter = 0;
    Attiny85Attached.refresh();
  }
} 












