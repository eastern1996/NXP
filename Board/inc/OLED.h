#ifndef OLED_H
#define OLED_H

#include "common.h"
#include "include.h"

void OLED_Init(void);                                                           // OLED屏初始化程序，此函数应在操作屏幕之前最先调用
void OLED_IIC_Init(void);
void OLED_WrDat(unsigned char dat);                                            // 向OLED屏写数据
void OLED_WrCmd(unsigned char cmd);                                            // 向OLED屏写命令
void OLED_Set_Pos(unsigned char x, unsigned char y);                          // 设置显示坐标
void OLED_Fill(unsigned char bmp_dat);                                         // 全屏显示(显示BMP图片时才会用到此功能)
void OLED_CLS(void);                                                            // 复位/清屏
void OLED_P6x8Str(unsigned char x, unsigned char y, char ch[]);               // 6x8点整，用于显示ASCII码的最小阵列，不太清晰
void OLED_P8x16Str(unsigned char x, unsigned char y, char ch[]);              // 8x16点整，用于显示ASCII码，非常清晰
void OLED_P16x16Ch(unsigned char x, unsigned char y, unsigned char N);        // 16x16点整，用于显示汉字的最小阵列，可设置各种字体、加粗、倾斜、下划线等
void OLED_nurbem(uint8 x,uint8 y,uint8 a,uint8 b);
void OLED_nurbem_int(uint8 x,uint8 y,uint16 a);

void OLED_Show_Length(uint8 *table);                                            //显示纵向的图片
void OLED_Show_Cross(uint8 *table, uint8 wide, uint8 high);                     //显示横向的图片
void OLED_Show_Uncompress(uint8 *Table,uint16 usRowNum, uint16 usColumnNum);    //显示解压后的图片

#define	Brightness	0xCF
#define X_WIDTH 	128
#define Y_WIDTH 	64
#define LED_IMAGE_WHITE       0x01
#define LED_IMAGE_BLACK       0

#define SDAIN    gpio_get(IMU_SDA)

#endif