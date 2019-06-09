#include "Beep.h"

#define BEEP_PIN PTD3
uint8 beep_on = 0;
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
void Beep(uint16 time)
{
    if(beep_on>0)
    {
        beep_on--;
        Beep_Start();
        DELAY_MS(time);
        Beep_Stop();
    }
}