
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

int spd=255;
// Above sets the speed of the bot

void setup()
{ pinMode(LED_BUILTIN, OUTPUT);
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
  int left = analogRead(A0);
  int right = analogRead(A1);

  Serial.print("left =") ;
  Serial.print( left) ;
  Serial.print("      ||   right =") ;
  Serial.println( right) ;
   if(left > 220 && left < 260 && right > 300)
  go_left() ;
  else if(right > 220 && right < 260 && left > 300 )
  go_right() ;
  else if(left > 200 && left < 300 && right > 200 && right < 300 )
  go_straight() ;
 
  else if(left > 230 && right > 300 )
  stop_bot() ;
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
