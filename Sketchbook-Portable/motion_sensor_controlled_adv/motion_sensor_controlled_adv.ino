#include<Wire.h>
/*
 * SCL ------ A5
 * SDA ------ A4
 */

const int lm1 = 5;
const int lm2 = 6;
const int lspeed = 9;
const int rm1 = 7;
const int rm2 = 8;
const int rspeed = 10;

const int MPU_addr=0x68;  // I2C address of the MPU-6050
const int PWR_MGMT_1=0x6B;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int spd=255;

void setup(){
  initMPU6050();
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lspeed, OUTPUT);
  pinMode(rspeed, OUTPUT);
  analogWrite(lspeed, spd);
  analogWrite(rspeed, spd);
}

void loop(){

  readMPU6050();

  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.println(AcZ);
  
 /* Serial.print("GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ); */
  /* delay(350) ; */
   
  if( AcX > 0 && AcX < 10000 )//&& AcY > 15000  && AcY < 21000 && AcZ > 7000 && AcZ < 15000) 
  stop_bot() ;
  else if( AcX < 0 && AcX > -10000 )//&& AcY > 10000  && AcY < 20000 && AcZ > 500 && AcZ < 10000)
  go_straight() ;
  else if( AcY < 0)// && AcY > 11000  && AcY < 20000 && AcZ > 6000 && AcZ < 18000)
  go_backward() ;
  else if( AcX < 0 && AcX > -10000 && AcZ < 10000 && AcZ > 7000)
  go_left() ;
  else if( AcY < 0 && AcZ < 11000 && AcZ > 7000) 
  go_right() ;
  
  else
  stop_bot() ;
}

void initMPU6050(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
}

void readMPU6050(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  Tmp=Tmp/340.00+36.53;
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
}

void go_straight()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void go_backward()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void stop_bot()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void go_left()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void go_leftb()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void go_right()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void go_lleft()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void go_rright() 
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void go_rightb()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

