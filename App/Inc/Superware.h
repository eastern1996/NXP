#ifndef _SUPERWARE_H_
#define _SUPERWARE_H_

#include "common.h"
#include "include.h"
extern uint16 distance;

void PORTC_IRQHandler(void);
void Superware_Init();
void Superware_Get_Distance();



#endif