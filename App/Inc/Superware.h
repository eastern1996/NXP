#ifndef _SUPERWARE_H_
#define _SUPERWARE_H_

#include "common.h"
#include "include.h"
extern uint16 distance;

void PORTC_IRQHandler(void);
void Superware_Init();
void Superware_Get_Distance();

extern uint32 viameter;//路程计数器
extern uint8 viameter_on_flag;//路程计数器开启标志位

#endif