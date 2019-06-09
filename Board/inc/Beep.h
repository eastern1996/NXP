#ifndef BEEP_H
#define BEEP_H

#include "common.h"
#include "include.h"

void Beep_Init();
void Beep_Start();
void Beep_Stop();
void Beep(uint16 time);

extern uint8 beep_on;

#endif