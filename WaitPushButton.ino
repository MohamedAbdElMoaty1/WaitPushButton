
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

  wpb x1(13,8,7);   // led , pb on , pb off
//wpb x2(13,6,8,5000);

  void setup()
{
   x1.init();
 //x2.init(); 
}

void loop()
{
 //x1.waits(5);
   x1.waitms(5000);
}
