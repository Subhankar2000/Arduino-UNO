
const int lm1 = 5;
const int lm2 = 6;
const int lspeed = 9;
const int rm1 = 7;
const int rm2 = 8;
const int rspeed = 10;
int spd=255;
void setup() {
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lspeed, OUTPUT);
  pinMode(rspeed, OUTPUT);
  analogWrite(lspeed, spd);
  analogWrite(rspeed, spd);
pinMode(14, INPUT);
pinMode(11, INPUT);
pinMode(12, INPUT);
pinMode(13, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Q1 = digitalRead(14);
  int Q2 = digitalRead(11);
  int Q3 = digitalRead(12);
  int Q4 = digitalRead(13);
  int Button = Q4*1 + Q3*2 + Q2*4 + Q1*8 ;
  Serial.print("Q1 = ");
  Serial.print(Q1);
  Serial.print("       Q2 = ");
  Serial.print(Q2) ;
  Serial.print("       Q3 = ");
  Serial.print(Q3) ;
  Serial.print("       Q4 = ");
  Serial.print(Q4) ;
  Serial.print("       Button = ") ;
  Serial.println(Q4*1 + Q3*2 + Q2*4 + Q1*8) ;
  
  if( Button == 2) 
  go_straight() ;
  else if( Button == 0 )
  {
    digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  }
  else if( Button == 5 ){
    go_lleft() ;
  }
  
  else if( Button == 4 )
  {
    go_lleft() ;
   
  }
  else if( Button == 6 )
  {
    go_rright();
    }
  
  else 
  stop_bot();
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
  digitalWrite(rm2,LOW);}

