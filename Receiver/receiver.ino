#include <VirtualWire.h>

#define l1 8
#define l2 9
#define r1 10
#define r2 11
#define b1 6
#define b2 5
#define datain 7
void setup()
{

 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(b1,OUTPUT);
 pinMode(b2,OUTPUT);
 Serial.begin(9600);
 vw_set_ptt_inverted(true);
 vw_set_rx_pin(datain);
 vw_setup(1000);
 vw_rx_start();
}

void up(){
  digitalWrite(b1,HIGH);
  digitalWrite(b2,LOW);
  delay(200);
  digitalWrite(b1,LOW);
  
 
}

void down(){
  digitalWrite(b2,HIGH);
  digitalWrite(b1,LOW);
  delay(200);
  digitalWrite(b2,LOW);
 
}
void right(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
}
void left(){
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void front(){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void back(){
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}

void halt
(){
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
}






 void loop()
{
  int value;
 uint8_t buf[VW_MAX_MESSAGE_LEN];
 uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
 vw_get_message(buf, &buflen);
 value=atoi(buf);
 switch(value){
  case 1:
  Serial.println("left");
  left();
  break;
  
  case 2:
  Serial.println("right");
  right();
  break;
  
  case 3:
  Serial.println("back");
  back();
  break;

  case 4:
  Serial.println("front");
  front();
  break;

   case 5:
  Serial.println("up");
  up();
  break;

   case 6:
  Serial.println("down");
  down();
  break;


  case 0:
  Serial.println("stop");
  halt();

 
    }
 }
