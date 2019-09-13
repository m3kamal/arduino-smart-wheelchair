#include <VirtualWire.h>
#include "Wire.h"
#define    MPU9250_ADDRESS            0x68
#define    MAG_ADDRESS                0x0C
#define    GYRO_FULL_SCALE_250_DPS    0x00  
#define    GYRO_FULL_SCALE_500_DPS    0x08
#define    GYRO_FULL_SCALE_1000_DPS   0x10
#define    GYRO_FULL_SCALE_2000_DPS   0x18
#define    ACC_FULL_SCALE_2_G        0x00  
#define    ACC_FULL_SCALE_4_G        0x08
#define    ACC_FULL_SCALE_8_G        0x10
#define    ACC_FULL_SCALE_16_G       0x18

void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.endTransmission();
  
  // Read Nbytes
  Wire.requestFrom(Address, Nbytes); 
  uint8_t index=0;
  while (Wire.available())
    Data[index++]=Wire.read();
}


void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data)
{

// Configure gyroscope range
  I2CwriteByte(MPU9250_ADDRESS,27,GYRO_FULL_SCALE_2000_DPS);
  // Configure accelerometers range
  I2CwriteByte(MPU9250_ADDRESS,28,ACC_FULL_SCALE_16_G);
  // Set by pass mode for the magnetometers
  I2CwriteByte(MPU9250_ADDRESS,0x37,0x02);
  // Request first magnetometer single measurement
  I2CwriteByte(MAG_ADDRESS,0x0A,0x01);

  
  // Set register address
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.write(Data);
  Wire.endTransmission();
}



char *data;
void setup() 
{
  Serial.begin(9600);
 pinMode(LED_BUILTIN,OUTPUT);
 vw_set_ptt_inverted(true);
 vw_set_tx_pin(9);
 vw_setup(1000);
}

void loop()
{


// Read accelerometer and gyroscope
  uint8_t Buf[14];
  I2Cread(MPU9250_ADDRESS,0x3B,14,Buf);

  // Gyroscope
  int16_t gx=-(Buf[0]<<8 | Buf[1]);
  int16_t gy=-(Buf[2]<<8 | Buf[3]);
  int16_t gz=Buf[4]<<8 | Buf[5];
  int16_t az=Buf[12]<<8 | Buf[13];
  
  
  if(gx>2000)
  data="3";
  else if(gx<-2000)
  data="4";
  else if(gy>1000)
  data="2";
  else if(gy<-1000)
  data="1";
  else if(az>1000)
  data="5";
  else if(az<-1000)
  data="6";
  
  
  else
  data="0";
 Serial.println(data);
 vw_send((uint8_t *)data, strlen(data));
 vw_wait_tx();

}
