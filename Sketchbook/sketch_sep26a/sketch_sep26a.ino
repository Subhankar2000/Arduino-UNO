#include <Adafruit_GFX.h>    
#include <Adafruit_TFTLCD.h> 

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup() {

  tft.reset();
  tft.begin(0x9481);
  tft.setRotation(1);
  tft.fillScreen(RED);
  tft.fillScreen(GREEN);
  tft.fillScreen(BLUE);
  tft.fillScreen(BLACK);
  delay(1000);
  tft.setCursor(80,100);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("Hello");

  tft.setCursor(220,100);
  tft.setTextColor(RED);
  tft.setTextSize(4);
  tft.print("YouTUBE!");

  tft.fillRect(80,200, 321, 60, RED);

  tft.setCursor(135,215);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("Subscribe");

  tft.drawRect(0,0,480,320,WHITE);
  delay(1000);
}

void loop() 
{
  tft.fillRect(80,200,321,60,BLACK);
  delay(1000);
  tft.fillRect(80,200,321,60,RED);
  tft.setCursor(135,215);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print("Subscribe");
  delay(1000);
}
