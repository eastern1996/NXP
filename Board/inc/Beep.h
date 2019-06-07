#ifndef BEEP_H
#define BEEP_H

#include "common.h"
#include "include.h"

void Beep_Init();
void Beep_Start();
void Beep_Stop();
void Beep_Once(uint16 time);
void PIT3_IRQHandler(void);



#endif