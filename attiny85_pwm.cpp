#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
 
#include "attiny85_pwm.h"


struct attached_t {
  int counter;
  int pin;
  int micros;
  void refresh(){
    digitalWrite(pin, HIGH);
    delayMicroseconds(micros);
    digitalWrite(pin, LOW);
  }
} Attiny85Attached;


Attiny85_PWM::Attiny85_PWM(int pin) {
  Attiny85Attached.pin = pin;
  Attiny85Attached.counter = 0;
  Attiny85Attached.micros = 0;

  // using adafruits defines here
  OCR0A = 0xAF;
  TIMSK |= _BV(OCIE0A);
}

void Attiny85_PWM::write(int degrees){
  if(degrees < 0 || degrees > 180) return;
  Attiny85Attached.micros = map(degrees, 0, 180, 1000, 2000);
}

void Attiny85_PWM::write(float duty_cycle){
  if(duty_cycle < 0 || duty_cycle > 1) return;
  int degrees = duty_cycle/180;
  Attiny85Attached.micros = map(degrees, 0, 180, 1000, 2000);
}

// note, signal is every 2 microseconds
SIGNAL(TIMER0_COMPA_vect) {
  if(++Attiny85Attached.counter >= 10){
    Attiny85Attached.counter = 0;
    Attiny85Attached.refresh();
  }
} 












