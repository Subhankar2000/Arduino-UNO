#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Arduino Uno / 2009:
// -------------------
// Standard Arduino Uno/2009 shield            : <display model>,A5,A4,A3,A2
// DisplayModule Arduino Uno TFT shield        : <display model>,A5,A4,A3,A2
//
// Arduino Mega:
// -------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Mega      : <display model>,38,39,40,41
//
// Remember to change the model parameter to suit your display module!
UTFT myGLCD(ILI9481,38,39,40,41);

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

void loop()
{
  static char i=1;
  myGLCD.clrScr();
  if(i==1)
  myGLCD.setColor(255, 0, 0);  
  else if(i==2)
  myGLCD.setColor(0, 255, 0);
  else if(i==3)
  {
  myGLCD.setColor(0, 0, 255);
  i=0;
  }
  i++;
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(BigFont);
  myGLCD.print("wwww.14core.com", CENTER, 0);
  myGLCD.print("Download Example Code Below", CENTER, 16);
  myGLCD.print("---------------------------", CENTER, 32);
  delay(1000);
  //while(1) {};
}
