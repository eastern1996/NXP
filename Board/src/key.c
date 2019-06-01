#include "key.h"
#include "IIC.h"

KEY key = {0, 0};                       //存储按键值，和按键标志位
extern uint8 mode;

void PORTE_IRQHandler(void);           //按键中断函数
void Key_Handler(void);                //按键服务函数

void Key_Init(void)                    //按键初始化
{
	I2C1_SCL_H
	DELAY_MS(20);
	I2C1_SDA_H
	DELAY_MS(500);
	Key_Write(0x48,0x4d);

    port_init(Int_GPIO , ALT1 | IRQ_FALLING | PULLUP );           //中断引脚初始化
    set_vector_handler(Int_VECT ,PORTE_IRQHandler);          //配置中断
    enable_irq (Int_PORT);                                        //使能中断
}

void Key_Write(uint8 addr,uint8 dat)    //对ch455写指令
{
	IIC_start(I2C_1);
	IIC_send_byte(I2C_1,addr);
	IIC_send_byte(I2C_1,dat);
	IIC_stop(I2C_1);
}

uint8 Get_Keynum(void)                  //读取键值
{
    const uint8 table[12] = {109, 110, 111, 101, 102, 103, 93, 94, 95, 85, 86, 87};     //按键值转化表
	uint8 count = 0;

	key.key_value = Key_Read(0x4f);

    for(count = 0; count < 12; count ++)
    {
        if(table[count] == key.key_value)
        {
            key.key_flag = 1;
            break;
        }
    }
	return (count + 1);
}

uint8 Key_Read(uint8 addr)                  //读取ch455寄存器
{
	uint8 dat;

	IIC_start(I2C_1);
	IIC_send_byte(I2C_1,addr);
	dat=IIC_read_byte(I2C_1);
    DELAY_MS(1);
    IIC_stop(I2C_1);

    return dat;
}

void PORTE_IRQHandler(void)                 //按键中断函数
{
    PORT_FUNC(E, 26, Key_Handler);
}

void Key_Handler(void)                      //按键服务函数
{
    key.key_value = Get_Keynum();
}

void Board_Key_Init()
{
	gpio_init(PTD7,GPI,1);               
        port_init_NoALT(PTD7,PULLUP);  //KEY-1
        
	gpio_init(PTD8,GPI,1);    			          
        port_init_NoALT(PTD8,PULLUP);  //KEY-2
        
	gpio_init(PTD9,GPI,1);               
        port_init_NoALT(PTD9,PULLUP);  //KEY-3
        
	gpio_init(PTD10,GPI,1);               
        port_init_NoALT(PTD10,PULLUP);  //KEY-4
    

        
	gpio_init(PTD1,GPI,1);
        port_init_NoALT(PTD1,PULLUP);  //拨码开关SK1
        
	gpio_init(PTD2,GPI,1);               
        port_init_NoALT(PTD2,PULLUP);  //拨码开关SK2
        
	gpio_init(PTD3,GPI,1);    			          
        port_init_NoALT(PTD3,PULLUP);  //拨码开关SK3
        
	gpio_init(PTD4,GPI,1);               
        port_init_NoALT(PTD4,PULLUP);  //拨码开关SK4
        
	gpio_init(PTD7,GPI,1);               
        port_init_NoALT(PTD7,PULLUP);   //核心板按键
	
}
void KEY_Mode()
{
  if(gpio_get(PTD1))
    mode =1;
  else if(gpio_get(PTD2))
    mode = 2;
  else if(gpio_get(PTD3))
    mode = 3;
  else if(gpio_get(PTD4))
    mode = 4;
  else{}
}