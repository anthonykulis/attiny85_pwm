// This library is a direct port of Adafruit_SoftServo written
// by Limor Fried.
// 
// Since it is such a small library, there wasn't much of a 
// need to fork their repository and hence the rewrite.
// The reason for the port was to encapsulate the functionality
// so that the user does not need to manage system interrupts.
// Further more, most users will not need to implement multiple
// PWM outputs, so this library provides a set of overloaded 
// write() calls to eliminate that need. Overloading the write()
// functionality will though cause extra overhead, so if your
// project is space heavy and you need every byte available, 
// fork this project, remove the overloaded write()'s you will 
// not need. Also, email me about this fork and I will include 
// a link to it in the libraries readme page.
// 
// Anthony

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

struct attached_t;
attached_t Attiny85Attached;

class Attiny85_PWM {

public: 
  Attiny85_PWM(uint8_t pin);
  void write(uint8_t degrees);
  void write(float duty_cycle);
};

