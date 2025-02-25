#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include  "common.h"

/*
 * Include 用户自定义的头文件
 */
#include  "MK66_wdog.h"
#include  "MK66_gpio.h"     //IO口操作
#include  "MK66_uart.h"     //串口
#include  "MK66_i2c.h"      //I2C
#include  "MK66_spi.h"      //SPI
#include  "MK66_rtc.h"      //RTC
#include  "MK66_adc.h"      //ADC
#include  "MK66_dma.h"      //DMA
#include  "MK66_sdhc.h"     //SDHC


#include  "VCAN_LED.H"          //LED
#include  "VCAN_KEY.H"          //KEY
#include  "VCAN_MMA7455.h"      //三轴加速度MMA7455
#include  "VCAN_NRF24L0.h"      //无线模块NRF24L01+
#include  "VCAN_RTC_count.h"    //RTC 时间转换
#include  "VCAN_camera.h"       //摄像头总头文件
#include  "ff.h"                //FatFs
#include  "VCAN_TSL1401.h"      //线性CCD
#include  "VCAN_key_event.h"    //按键消息处理
#include  "VCAN_NRF24L0_MSG.h"  //无线模块消息处理

#include  "VCAN_BMP.h"          //BMP
#include  "vcan_img2sd.h"       //存储图像到sd卡一个文件
#include  "vcan_sd_app.h"       //SD卡应用（显示sd看上图片固件）

#include  "Vcan_touch.h"        //触摸驱动

#include  "VCAN_computer.h"     //多功能调试助手

#include  "enter.h"
#include  "define.h"

//用户函数头文件定义
#include "ADC.h"
#include "key.h"
#include "OLED.h"
#include "menu.h"
#include "Beep.h"
#include "Superware.h"


#endif  //__INCLUDE_H__




/*********************************************\
*                   _ooOoo_                   *
*                  o8888888o                  * 
*                  88" . "88                  *
*                  (| -_- |)                  *
*                  O\  =  /O                  *
*               ____/`---'\____               * 
*             .'  \\|     |//  `.             *
*            /  \\|||  :  |||//  \            *
*           /  _||||| -:- |||||-  \           *
*           |   | \\\  -  /// |   |           *
*           | \_|  ''\---/''  |   |           *
*           \  .-\__  `-`  ___/-. /           *
*         ___`. .'  /--.--\  `. . __          *
*      ."" '<  `.___\_<|>_/___.'  >'"".       *
*     | | :  `- \`.;`\ _ /`;.`/ - ` : | |     *
*     \  \ `-.   \_ __\ /__ _/   .-` /  /     * 
*======`-.____`-.___\_____/___.-`____.-'======*
*                   `=---='                   *
*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*
*          佛祖保佑          永无BUG          *
\*********************************************/
