#ifndef IIC_H
#define IIC_H

#include "common.h"
#include "include.h"

//****************IIC0*******************mpu
#define IMU_SCL0  PTA16 //SCL IO
#define IMU_SDA0  PTA17  //SDA IO
//****************IIC1*******************oled
#define IMU_SCL1  PTE27 //SCL IO
#define IMU_SDA1  PTE28 //SDA IO
//***************************************


#define SDAIN0    gpio_get(IMU_SDA0)
#define SDAIN1    gpio_get(IMU_SDA1)


//****************IIC0*******************
#define I2C0_SDA_H    gpio_set(IMU_SDA0, 1);
#define I2C0_SCL_H    gpio_set(IMU_SCL0, 1);

#define I2C0_SDA_L    gpio_set(IMU_SDA0, 0);
#define I2C0_SCL_L    gpio_set(IMU_SCL0, 0);

#define SDA0_Out  gpio_init(IMU_SDA0, GPO,1);
#define SDA0_In   gpio_init(IMU_SDA0, GPI,0);
//***************************************

//****************IIC1*******************
#define I2C1_SDA_H    gpio_set(IMU_SDA1, 1);
#define I2C1_SCL_H    gpio_set(IMU_SCL1, 1);

#define I2C1_SDA_L    gpio_set(IMU_SDA1, 0);
#define I2C1_SCL_L    gpio_set(IMU_SCL1, 0);

#define SDA1_Out  gpio_init(IMU_SDA1, GPO,1);
#define SDA1_In   gpio_init(IMU_SDA1, GPI,0);
//***************************************

#define ack      1
#define no_ack   0
//¶¨ÒåÄ£¿éºÅ
typedef enum I2Cn
{
    I2C_0  = 0,
    I2C_1  = 1
} I2Cn;

void IIC_Delay(long t);
void IMU_IIC_Init(I2Cn i2cn);
void IIC_start(I2Cn i2cn);
void IIC_stop(I2Cn i2cn);

uint8_t IIC_Wait_Ack(I2Cn i2cn);
void IIC_Ack(I2Cn i2cn);
void IIC_NAck(I2Cn i2cn);
void IIC_send_byte(I2Cn i2cn,uint8 c);
uint8 IIC_read_byte(I2Cn i2cn);

void  IMU_WriteRegister(I2Cn i2cn,uint8 SlaveID, uint8 reg, uint8 Data);
uint8 IMU_ReadRegister(I2Cn i2cn,uint8 SlaveID, uint8 reg);



#endif