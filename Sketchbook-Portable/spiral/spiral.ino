int ver[8] = { A5, A4, A3, A2, A1, A0 , 2, 3}; 
int hor[8] = {4, 5, 6, 7, 8, 9, 10, 11}; 


int img[9][8];

void Refresh()
{
  for(int i=0; i<8; i++) {  
    for(int j=0;j<8;j++)
      digitalWrite(hor[j], 1);
      
    for(int j=0;j<8;j++) {
      if(j==i)
        digitalWrite(ver[j], HIGH);
      else
        digitalWrite(ver[j], LOW);
    }

    for(int j=0;j<8;j++)
      digitalWrite(hor[j], img[j][i]);
    
    delayMicroseconds(500);
  }
}

void ResetMatrix()
{
  for(int i=0; i<8; i++) {
    for(int j=0;j<8;j++) {
      img[i][j] = 1;
    }
  }
}
void setup()
{
  ResetMatrix();
  for(int i=0; i<20; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
   int a=0;
   int b=7;
   
  for(int t2=0; t2<4; t2++) {
    for(int tmp=a; tmp<=b; tmp++){
        //ResetMatrix();
        img[a][tmp] = !img[a][tmp];
        for(int k=0; k<10+(t2*3); k++)
          Refresh();  
    }
    for(int tmp=a+1; tmp<=b; tmp++){
        //ResetMatrix();      
        img[tmp][b] = !img[tmp][b];
        for(int k=0; k<10+(t2*3); k++)
          Refresh();  
    }
    for(int tmp=b-1; tmp>=a; tmp--){
        //ResetMatrix();      
        img[b][tmp] = !img[b][tmp];
        for(int k=0; k<10+(t2*3); k++)
          Refresh();          
    }
    for(int tmp=b-1; tmp>=a+1; tmp--){
        //ResetMatrix();      
        img[tmp][a] = !img[tmp][a];  
        for(int k=0; k<10+(t2*3); k++)
          Refresh();          
    }
    a++;
    b--;
  }
}

