/*   WHITE
     TIME AND CALENDAR DISPLAYED IN LCD 
     BY - SUBHANKAR KARMAKAR
     ASANSOL ENGINEERING COLLEGE 
     ELECTRONICS AND COMMUNICATION DE{PT. */
     
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

uint16_t ID;
uint8_t hh, mm, ss;

uint8_t conv2d(const char* p)
{
    uint8_t v = 0;
    if ('0' <= *p && *p <= '9') v = *p - '0';
    return 10 * v + *++p - '0';
}

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
  tft.print("CALENDAR + CLOCK");
  tft.fillRect(395,17,80,5,BLACK);
  
  tft.setCursor(75,50);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("Thursday - 28 September 2017");
  
  tft.fillRect(10,75,120,25,BLACK);
  tft.setCursor(22,80);
  tft.setTextColor(WHITE);
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
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("28") ;
  tft.fillRect(80,290,350,27,BLACK);
  tft.setCursor(87,295);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("24 HOUR TIME") ;
  tft.fillRect(245,290,110,1,BLACK);
  tft.fillRect(355,290,1,25,BLACK);
  tft.fillRect(245,315,110,1,BLACK);
  #if defined(_GFXFONT_H_)
    tft.setFont(&FreeSans9pt7b);
#endif
    hh = conv2d(__TIME__);
    mm = conv2d(__TIME__ + 3);
    ss = conv2d(__TIME__ + 6);
}

void loop()
{ while (1)
  { 
    tft.fillRect(246,291,150,24,WHITE);
    tft.setCursor(250,296);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    
    delay(50);
    if (++ss > 59) {
            ss = 0;
            mm++;
            if (mm > 59) {
                mm = 0;
                hh++;
                if (hh > 23) hh = 0;
            }
        }
    char buf[20];
    sprintf(buf, "%02d : %02d : %02d", hh, mm, ss);
    tft.print(buf);
  
delay(50);}

}
