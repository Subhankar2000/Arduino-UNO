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

uint8_t hh, mm, ss;
uint8_t conv2d(const char* p)
{
    uint8_t v = 0;
    if ('0' <= *p && *p <= '9') v = *p - '0';
    return 10 * v + *++p - '0';
}
void setup() {
   Serial.begin(9600);
  tft.reset();
  tft.begin(0x9481);
  tft.setRotation(1);

  tft.fillScreen(BLACK);
  delay(1000);
  tft.setCursor(40,100);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("28 Sep 2017 - Thursday");

  /*tft.setCursor(220,100);
  tft.setTextColor(GREEN);
  tft.setTextSize(4);
  tft.print("Everyone");*/

  /*tft.fillRect(80,200, 321, 60, GREEN);

  tft.setCursor(135,215);
  tft.setTextColor(BLACK);
  tft.setTextSize(4);
  tft.print("Subhankar");

  tft.drawRect(0,0,480,320,WHITE);
  delay(1000);*/
 tft.setCursor(110,170);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Time ");
#if defined(_GFXFONT_H_)
    tft.setFont(&FreeSans9pt7b);
#endif
    hh = conv2d(__TIME__);
    mm = conv2d(__TIME__ + 3);
    ss = conv2d(__TIME__ + 6);
}

void loop() 
{
  //tft.fillRect(80,200,321,60,BLACK);
 
  
  /*tft.print(hh);
  tft.print(" : ") ;
  tft.print(mm);
  tft.print(" : " );
tft.print(ss);
tft.print("  AM") ;*/
while (1) {tft.fillRect(150,150,321,60,BLACK);
  tft.setCursor(150,170);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
     /*   if (++ss > 59) {
            ss = 0;
            mm++;
            if (mm > 59) {
                mm = 0;
                hh++;
                if (hh > 23) hh = 0;
            }
        }
        char buf[20];
        /*sprintf(buf, "%02d : %02d : %02d", hh, mm, ss);tft.print(buf);delay(1000);}
  */
 
 

