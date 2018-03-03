/*   CALENDAR IN LCD [ DRIVER ILI9481 ] 
     BY - SUBHANKAR KARMAKAR
     TIME - 3 : 38 PM 
     28 SEPTEMBER , THURSDAY , 2017
     ASANSOL ENGINEERING COLLEGE 
     ELECTRONICS AND COMMUNICATION DEPT. */
     
#include <Adafruit_GFX.h>    
#include <Adafruit_TFTLCD.h> 
#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define RGB(r, g, b) (((r&0xF8)<<8)|((g&0xFC)<<3)|(b>>3))
#define GREY      RGB(127, 127, 127)
#define DARKGREY  RGB(64, 64, 64)
#define TURQUOISE RGB(0, 128, 128)
#define PINK      RGB(255, 128, 192)
#define OLIVE     RGB(30, 30, 0)
#define DOLIVE    RGB(230, 230, 0)
#define PURPLE    RGB(128, 0, 128)
#define AZURE     RGB(0, 128, 255)
#define ORANGE    RGB(255,128,64)

#include <stdio.h>

void setup() 
{
  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9481);
  tft.setRotation(1);
  
  tft.fillScreen(WHITE);
  delay(1000);
  
  tft.fillRect(7,17,75,5,BLACK);
  tft.setCursor(97,10);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.print("CALENDAR");
  tft.fillRect(250,17,220,5,BLACK);
  
  tft.setCursor(75,50);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("Thursday - 28 September 2017");
  
  tft.fillRect(10,75,120,25,BLACK);
  tft.setCursor(22,80);
  tft.setTextColor(RGB(50,100,70));
  tft.print("CALENDAR");
  
  tft.fillRect(45,98,430,2,BLACK);
  tft.fillRect(473,98,2,185,BLACK);
  tft.fillRect(45,98,2,185,BLACK);
  tft.fillRect(45,283,430,2,BLACK);
  tft.setCursor(65,110);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("SUN  MON  TUE  WED  THU  FRI  SAT") ;
  tft.fillRect(45,130,430,1,BLACK);
  
  tft.setCursor(65,140);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("                          1    2 ") ;
  tft.setCursor(65,170);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print(" 3    4    5    6    7    8    9 ") ;
  tft.setCursor(68,200);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("10   11   12   13   14   15   16 ") ;
  tft.setCursor(57,230);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print(" 17   18   19   20   21   22   23") ;
  tft.setCursor(57,260);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print(" 24   25   26   27        29   30") ;
  tft.fillRect(300,255,40,25,BLACK);
  tft.setCursor(310,260);
  tft.setTextColor(RGB(50,100,70));
  tft.setTextSize(2);
  tft.print("28") ;
  
}

void loop()
{ 
  
}
