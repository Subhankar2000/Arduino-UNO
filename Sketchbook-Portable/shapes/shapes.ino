// Code by Tunir Saha.
// Visit www.skubotics.in
// This code is for testing the Motor 

const int lm1 = 5;
const int lm2 = 6;
const int lspeed = 9;
const int rm1 = 7;
const int rm2 = 8;
const int rspeed = 10;
// Above is the motor driver pin connection. LM1 and LM2 are the
// digital input pins from arduino to the motor driver. Same for
// RM1 and RM2 and lspeed and rspeed are the enable pins.
// Change accordingly.

int spd=255 , spdl = 100;
// Above sets the speed of the bot
void setup()
{
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lspeed, OUTPUT);
  pinMode(rspeed, OUTPUT);
  analogWrite(lspeed, 255);
  analogWrite(rspeed, 255);
  Serial.begin(9600);           
}

void loop()
{  
  stop_bot() ;
  
  delay(5000) ;
  
  go_straight() ;
  delay(10000) ;
  analogWrite(lspeed, 100);
  analogWrite(rspeed, 255);
  go_left() ;
  delay(2225) ;

  analogWrite(lspeed, 255);
  analogWrite(rspeed, 255);
  
  go_straight() ;
  delay(5000) ;
  analogWrite(lspeed, 100);
  analogWrite(rspeed, 255);
  go_left() ;
  delay(2210) ;

analogWrite(lspeed, 255);
  analogWrite(rspeed, 255);
  
  
  go_straight() ;
  delay(10000) ;
  analogWrite(lspeed, 100);
  analogWrite(rspeed, 255);
  go_left() ;
  delay(2225) ;

analogWrite(lspeed, 255);
  analogWrite(rspeed, 255);
  

  go_straight() ;
  delay(5000) ;
  analogWrite(lspeed, 100);
  analogWrite(rspeed, 255);
  go_left() ;
  delay(2225) ;

  analogWrite(lspeed, 255);
  analogWrite(rspeed, 255);
  

}  

//  Here are the functions that are used in the program

void go_straight()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void go_backward()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void stop_bot()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void go_left()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void go_leftb()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void go_right()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void go_rightb()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
