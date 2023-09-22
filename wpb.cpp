#include "wpb.h"
#include <Arduino.h>

wpb ::wpb(byte led ,byte pbon , byte pboff , long mstime){
  led_pin = led ;
  pb1_pin = pbon ;
  pb2_pin = pboff ; 
  del = mstime ; 
}
wpb ::wpb(byte led ,byte pbon , byte pboff){
  led_pin = led ;
  pb1_pin = pbon ;
  pb2_pin = pboff ;  
}
    
void wpb ::init() {
pinMode(led_pin , OUTPUT);
pinMode(pb1_pin , INPUT);
pinMode(pb2_pin , INPUT);
}

void wpb :: waits(){
  if(digitalRead(pb1_pin))
  {
  t = millis();
    digitalWrite(led_pin,1);
  }
  if(digitalRead(pb2_pin)||millis()-t>del)
  {
  digitalWrite(led_pin,0);
  }
}
 
void wpb :: waitms()
{
if(digitalRead(pb1_pin))
  {
  t = millis();
    digitalWrite(led_pin,1);
  }
  if(digitalRead(pb2_pin)||millis()-t>del)
  {
  digitalWrite(led_pin,0);
  }
} 
    
void wpb :: waits(long delay1)
{
delay1=delay1*1000;
  if(digitalRead(pb1_pin))
  {
  t = millis();
    digitalWrite(led_pin,1);
  }
  if(digitalRead(pb2_pin)||millis()-t>delay1)
  {
  digitalWrite(led_pin,0);
  }
}   

void wpb :: waitms(long delay2)
{
if(digitalRead(pb1_pin))
  {
  t = millis();
    digitalWrite(led_pin,1);
  }
  if(digitalRead(pb2_pin)||millis()-t>delay2)
  {
  digitalWrite(led_pin,0);
  }

}