#include "Beep.h"

#define BEEP_PIN PTD3

void Beep_Init()
{
    gpio_init(BEEP_PIN, GPO,0);
    
}
void Beep_Start()
{
    gpio_set(BEEP_PIN,1);
}
void Beep_Stop()
{
    gpio_set(BEEP_PIN,0);
}
void Beep_Once(uint16 time)
{
    pit_init_ms(PIT3, 200);    //初始化LPTMR
    set_vector_handler(PIT3_VECTORn ,PIT3_IRQHandler);      //设置PIT0的中断服务函数为 PIT0_IRQHandler
    enable_irq (PIT3_IRQn);
    Beep_Start();
}
void PIT3_IRQHandler(void)
{
    PIT_Flag_Clear(PIT3);
    Beep_Stop();       //清中断标志位
    disable_irq(PIT3_IRQn);
}
