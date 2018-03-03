const int lm1 = 5;
const int lm2 = 6;
const int lspeed = 9;
const int rm1 = 7;
const int rm2 = 8;
const int rspeed = 10;

// Ultra Sonic Module 1
int trigPinf=13; //Sensor Trig pin connected to Arduino pin 13
int echoPinf=11;  //Sensor Echo pin connected to Arduino pin 11
float pingTimef ;
float targetDistancef ;
float cmsf ;

int trigPinb=6; //Sensor Trig pin connected to Arduino pin 13
int echoPinb=3;  //Sensor Echo pin connected to Arduino pin 11
float pingTimeb ;
float targetDistanceb ;
float cmsb ;

// Above is the motor driver pin connection. LM1 and LM2 are the
// digital input pins from arduino to the motor driver. Same for
// RM1 and RM2 and lspeed and rspeed are the enable pins.
// Change accordingly.



int spd=255;
// Above sets the speed of the bot
int a =1 ;
void setup()
{pinMode(LED_BUILTIN, OUTPUT);
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
  
  ultrab();
  ultraf();
  
  if (targetDistancef<42  &&  targetDistanceb>42)
  {go_backward();
  delay(400);}
  else if(targetDistancef>42  &&  targetDistanceb<42)
  {go_straight() ;
  delay(400);}
  else if(targetDistancef>42  &&  targetDistanceb>42)
  go_lleft() ;
  else if(targetDistancef<62  &&  targetDistanceb<42)
  {go_lleft() ;
  delay(400) ;
  go_straight();
  delay(400);} 
  
  
  
}

//  Here are the functions that are used in the program


void ultraf() 
{
digitalWrite(trigPinf,LOW) ;
   delayMicroseconds(2) ; 
   digitalWrite(trigPinf,HIGH) ;
   delayMicroseconds(2) ;
   digitalWrite(trigPinf,LOW) ;
   delayMicroseconds(2) ;

   pingTimef = pulseIn( echoPinf , HIGH ) ;
   targetDistancef = pingTimef / ( 29 * 2 ) ;
   
   
   Serial.print("Front Distance in Centimeters :") ;
   Serial.println(targetDistancef) ;
}


void ultrab() 
{
digitalWrite(trigPinb,LOW) ;
   delayMicroseconds(2) ; 
   digitalWrite(trigPinb,HIGH) ;
   delayMicroseconds(2) ;
   digitalWrite(trigPinb,LOW) ;
   delayMicroseconds(2) ;

   pingTimeb = pulseIn( echoPinb , HIGH ) ;
   targetDistanceb = pingTimeb / ( 29 * 2 ) ;
   
   
   Serial.print("Back Distance in Centimeters :") ;
   Serial.println(targetDistanceb) ;
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
