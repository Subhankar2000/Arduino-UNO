// UTFT_Demo_480x320 (C)2013 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of how to use most of the functions
// of the library with a supported display modules.
//
// This demo was made for modules with a screen resolution 
// of 480x320 pixels.
//
// This program requires the UTFT library.
//

#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>
UTFTGLUE myGLCD(0x9488,A2,A1,A3,A4,A0);

// Declare which fonts we will be using
#if !defined(SmallFont)
extern uint8_t SmallFont[];    //.kbv GLUE defines as GFXFont ref
#endif

void setup()
{
  randomSeed(analogRead(5));   //.kbv Due does not like A0
    pinMode(A0, OUTPUT);       //.kbv mcufriend have RD on A0
    digitalWrite(A0, HIGH);
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop()
{
  int buf[478];
  int x, x2;
  int y, y2;
  int r;

// Clear the screen and draw the frame
  myGLCD.clrScr();
//
//  myGLCD.setColor(0, 0, 255);
//  myGLCD.setBackColor(0, 0, 0);
//  myGLCD.drawLine(239, 15, 239, 304);
//  myGLCD.drawLine(1, 159, 478, 159);
//  for (int i=9; i<470; i+=10)
//    myGLCD.drawLine(i, 157, i, 161);
//  for (int i=19; i<220; i+=10)
//    myGLCD.drawLine(237, i, 241, i);
// myGLCD.setColor(0,255,255);
//  myGLCD.print("Sin", 5, 15);
//  for (int i=1; i<478; i++)
//  {
//    myGLCD.drawPixel(i,159+(sin(((i*1.13)*3.14)/180)*95));
//  }
//  
  myGLCD.setColor(255,0,0);
  myGLCD.print("Cos", 5, 27);
  for (int i=1; i<478; i++)
  {
    myGLCD.drawPixel(i,159+(cos(((i*1.13)*3.14)/180)*95));
  }

  myGLCD.setColor(255,255,0);
  myGLCD.print("Tan", 5, 39);
  for (int i=1; i<478; i++)
  {
    myGLCD.drawPixel(i,159+(tan(((i*1.13)*3.14)/180)));
  }

}
