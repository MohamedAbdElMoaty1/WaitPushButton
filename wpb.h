#ifndef wpb_h
#define wpb_h
#include <Arduino.h>
class wpb {
 private:
  byte led_pin, pb1_pin, pb2_pin;
  long del = 1000, t = 0 ;
 public:
 void init();
 void waits();
 void waitms();
 void waits(long delay1);
 void waitms(long delay2);
  
 wpb(byte led ,byte pbon , byte pboff , long mstime ) ;
 wpb(byte led ,byte pbon , byte pboff) ;
};

#endif