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
int a =1 ;
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
{ delay(5000) ;  
  ultra() ;
    //follow
    if( targetDistance < 15 ) 
    {digitalWrite(13,HIGH) ;
      go_straight() ;
    delay(500) ;
    stop_bot() ;
    delay(150) ;
    }
    else
    {
      if( a <= 24 ) 
      {
        while( a <  14 ) 
        {
           go_lleft() ;
           delay(80) ;
           stop_bot() ;
           delay(700) ;
           ultra() ;

           if( targetDistance < 15) 
           break ;
           else
           a++ ;
         }
          while( a == 14 ) 
          {     
              go_rright() ;
              delay(650) ;
              a++ ;
          }
          while( a > 14 && a < 28)
          {
            go_rright() ;
            delay(80) ;
            stop_bot() ;
            delay(700) ;
            ultra() ;

            if( targetDistance < 15) 
           break ;
           else a++ ;
          }
          while ( a== 28 ) 
          {
            go_lleft() ;
            delay(650) ;
            break;
            stop_bot() ;
          }
      }
    }
}

//  Here are the functions that are used in the program


void ultra() 
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
}

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

void go_lleft()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void go_rright() 
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void go_rightb()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
