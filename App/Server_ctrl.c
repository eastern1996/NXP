#include "Server_ctrl.h"
#include "Motor_ctrl.h"


PID Server;

void PID_Init(void)
{
    Server.Kp = 1;
    Server.Ki = 2;
    Server.Kd = 3;
    
    Motor.Kp = 50;
    Motor.Ki = 5;
    Motor.Kd = 0;
    Motor.Set_Speed = 200;
}
