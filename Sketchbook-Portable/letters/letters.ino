char ground[8] = {A5, A4, A3, A2, A1, A0 , 2, 3};

char ALPHA[] = {0,0,0,0,0,0,0,0,0,0,0,
60,102,96,96,96,102,60,0,0,0,
60,24,24,24,24,24,60,0,0,0,
124,102,102,124,120,108,102,0,0,0,
60,102,96,96,96,102,60,0,0,0,
102,102,102,102,102,102,60,0,0,0,
60,24,24,24,24,24,60,0,0,0,
126,24,24,24,24,24,24,0,0,0,
120,108,102,102,102,108,120,0,0,0,
60,24,24,24,24,24,60,0,0,0,
60,102,96,110,102,102,60,0,0,0,
126,96,96,120,96,96,126,0,0,0,
60,102,96,60,6,102,60,0,0,0,
126,24,24,24,24,24,24,0,0,0,
0,0,0,0,0,0,0,0,0,0,0
};
void setup() 
{
  for (int x=8;x<14;x++)
  {
    pinMode(x, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  
  for (int i=0;i<8;i++)
  {
    digitalWrite(ground[i],HIGH);
  }
  DDRD = 0xFF;
  PORTD =0;
}

void loop() 
{
  for(int x=0;x<142;x++)
  {
    for(int a=0;a<20;a++)
    {
         for (int i=0;i<8;i++)
          { 
             digitalWrite(ground[i],LOW);
             PORTD = ALPHA[i+x];
            delay(1);
            digitalWrite(ground[i],HIGH);
          }    
    }
  }
  delay(1000);
}