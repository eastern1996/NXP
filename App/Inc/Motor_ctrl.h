#ifndef _MOTOR_CTRL_H_
#define _MOTOR_CTRL_H_
#include "Server_ctrl.h"


extern PID Motor;
void Motor_Init(void);
void Motor_Run(float *duty);
void Encoder_init(void);
void Get_Speed(void);
void Speed_PID_Ctrl(void);




#endif