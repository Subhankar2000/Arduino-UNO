// Code by Tunir Saha.
// Visit www.skubotics.in
// This code is for testing the Motor 

const int lm1 = 5;
const int lm2 = 6;
const int lspeed = 9;
const int rm1 = 7;
const int rm2 = 8;
const int rspeed = 10;

// Ultra Sonic Module
int trigPin=13; //Sensor Trig pin connected to Arduino pin 13
int echoPin=11;  //Sensor Echo pin connected to Arduino pin 11
float pingTime ;
float targetDistance ;
float cms ;

// Above is the motor driver pin connection. LM1 and LM2 are the
// digital input pins from arduino to the motor driver. Same for
// RM1 and RM2 and lspeed and rspeed are the enable pins.
// Change accordingly.

int spd=255;
// Above sets the speed of the bot

void setup()
{
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lspeed, OUTPUT);
  pinMode(rspeed, OUTPUT);
  analogWrite(lspeed, spd);
  analogWrite(rspeed, spd);
  Serial.begin(9600);           
}

void loop()
{  
  
   digitalWrite(trigPin,LOW) ;
   delayMicroseconds(2) ; 
   digitalWrite(trigPin,HIGH) ;
   delayMicroseconds(2) ;
   digitalWrite(trigPin,LOW) ;
   delayMicroseconds(2) ;

   pingTime = pulseIn( echoPin , HIGH ) ;
   targetDistance = pingTime / ( 29 * 2 ) ;
   
   
   Serial.print("Distance in Centimeters :") ;
   Serial.println(targetDistance) ;
   //delay( 1000 ) ;
    go_straight() ;
   while( targetDistance < 12 ) 
   {
    digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  if ( targetDistance < 12 )
  {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  }
   }
    
   delay(100) ;
   
   
   

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
  digitalWrite(lm2,LOW);
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
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
void go_rightb()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
