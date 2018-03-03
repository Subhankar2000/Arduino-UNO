/* 7 Segment LED Displays X 4 */

int pinA=2 ;
int pinB=3 ;
int pinC=4 ;
int pinD=5 ;
int pinE=6 ;
int pinF=7 ;
int pinG=8 ;
int D1=9 ;
int D2=10 ;
int D3=11 ;
int D4=12 ;


void setup()
{   
    pinMode(pinA, OUTPUT) ;
    pinMode(pinB, OUTPUT) ;
    pinMode(pinC, OUTPUT) ;
    pinMode(pinD, OUTPUT) ;
    pinMode(pinE, OUTPUT) ;
    pinMode(pinF, OUTPUT) ;
    pinMode(pinG, OUTPUT) ;    
    pinMode(D1, OUTPUT) ;
    pinMode(D2, OUTPUT) ;
    pinMode(D3, OUTPUT) ;
    pinMode(D4, OUTPUT) ;
}

void loop()
{
    digitalWrite(D1 , HIGH) ;
    digitalWrite(D2 , HIGH) ;
    digitalWrite(D3 , HIGH) ;
    digitalWrite(D4 , HIGH) ;
   
    digitalWrite(pinA , LOW) ;
    digitalWrite(pinB , LOW) ;
    digitalWrite(pinC , LOW) ;
    digitalWrite(pinD , LOW) ;
    digitalWrite(pinE , LOW) ;
    digitalWrite(pinF , LOW) ;
    digitalWrite(pinG , HIGH) ;
    delay(1000);
    
    digitalWrite(pinA , HIGH) ;
    digitalWrite(pinB , LOW) ;
    digitalWrite(pinC , LOW) ;
    digitalWrite(pinD , HIGH) ;
    digitalWrite(pinE , HIGH) ;
    digitalWrite(pinF , HIGH) ;
    digitalWrite(pinG , HIGH) ;
    delay(1000);
}
    
