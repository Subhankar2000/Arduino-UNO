/*
 * Copyright to #Author# 2016
 * Author = Veerendra_Nath
 * Email  = venkat@veerendranath.com
 * Site   = veerendranath.com
 * Shifting bits to diaply numbers on &segment 
Number Byte_to_diplay_7sgment(a-g) Decimal_number
  0            0b0000001            1
  1            0b1001111            79
  2            0b0110110            18
  3            0b0000110            6
  4            0b1001100            76
  5            0b0100100            36
  6            0b0100000            32
  7            0b0001111            15
  8            0b0000000            0
  9            0b0001100            12
 
 */
int n[3]={1,0,0};
int dot=128;
int p[4]={1,2,4,8};
int data_Pin=10;
int clock_Pin=9;
int latch_Pin=8;
int a=0;
void setup() {
 Serial.begin(9600);
 pinMode(data_Pin,OUTPUT);
 pinMode(clock_Pin,OUTPUT);
 pinMode(latch_Pin,OUTPUT);

}

void loop() {
int data[4];
data[0]=a%10;
data[1]=(a/10)%10;
data[2]=(a/100)%10;
data[3]=a/1000;
while(1)
{
  digitalWrite(latch_Pin, LOW);
  shiftOut(data_Pin, clock_Pin, LSBFIRST,p[0]);//first digit
  shiftOut(data_Pin, clock_Pin, LSBFIRST,n[data[0]]);
  digitalWrite(latch_Pin, HIGH);
   digitalWrite(latch_Pin, LOW);
  shiftOut(data_Pin, clock_Pin, LSBFIRST,p[1]);//second digit
  shiftOut(data_Pin, clock_Pin, LSBFIRST,n[data[1]]);
  digitalWrite(latch_Pin, HIGH);
   digitalWrite(latch_Pin, LOW);
  shiftOut(data_Pin, clock_Pin, LSBFIRST,p[2]);//third digit
  shiftOut(data_Pin, clock_Pin, LSBFIRST,n[data[2]]);
  digitalWrite(latch_Pin, HIGH);
   digitalWrite(latch_Pin, LOW);
  shiftOut(data_Pin, clock_Pin, LSBFIRST,p[3]);//fourth digit 
  shiftOut(data_Pin, clock_Pin, LSBFIRST,n[data[3]]);
  digitalWrite(latch_Pin, HIGH);
  if (Serial.available())
  {
    int temp=Serial.parseInt();
    if (temp<10000 && temp>0)
    {
      a=temp;
      break;
    }
    
  }
  
}


}
