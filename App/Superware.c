#include "Superware.h"

uint16 distance = 0;

#define TRIG PTC2
#define ECHO PTC4


void Superware_Init()
{
    gpio_init(TRIG,GPO,0);
    gpio_init(ECHO,GPI,0);
    port_init(ECHO, ALT1 | IRQ_EITHER | PULLDOWN );          //初始化 ECHO 外部中断管脚  遥控停车
    set_vector_handler(PORTC_VECTORn ,PORTC_IRQHandler);    //设置PORTC的中断服务函数为 PORTC_IRQHandler  
    set_irq_priority(PORTC_IRQn ,0);        //按键停车中断优先级
    enable_irq (PORTC_IRQn);
}

void Superware_Get_Distance()
{
    gpio_set (TRIG,1);
    DELAY_US(10);
    gpio_set (TRIG,0);
    //enable_irq (PORTC_IRQn);   
}
void PORTC_IRQHandler(void)
{
    static uint8 flag = 0;
    if(PORTC_ISFR & (1 << 4))           //PTC4 触发中断
    {
        PORTC_ISFR  = (1 << 4);        //写1清中断标志位
        if(!flag)
        {
            lptmr_time_start_us();
            flag = 1;
        }
        else if(flag)
        {
            distance = lptmr_time_get_us()*170/1000;
            flag = 0;
        }
    }
}