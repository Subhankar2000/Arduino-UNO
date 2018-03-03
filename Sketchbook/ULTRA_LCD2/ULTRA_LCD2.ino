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

int trigPin=13; 
int echoPin=11;  
int myCounter=0;  

float pingTime;  
float targetDistance; 
float speedOfSound=776.5; 


void setup() {
  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9481);
  tft.setRotation(1);
  
  tft.fillScreen(WHITE);
  delay(1000);
  
  tft.fillRect(7,17,85,5,BLACK);
  tft.setCursor(110,10);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.print("TARGET DISTANCE");
  tft.fillRect(390,17,85,5,BLACK);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2000); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10); 

  pingTime = pulseIn(echoPin, HIGH);  
  pingTime=pingTime/1000000; 
  pingTime=pingTime/3600; 
  targetDistance= speedOfSound * pingTime;  
  targetDistance=targetDistance/2; 
  targetDistance= targetDistance*63360;    

  tft.fillRect(15,50,450,100,WHITE);
  tft.setCursor(20,54);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print("In Centimeters :");
    tft.print(targetDistance*2.54);
    tft.print(" cm") ;
    tft.setCursor(20,74);
    tft.print("In Inches :");
    tft.print(targetDistance);
    tft.print(" in") ;
    delay(250);
}
