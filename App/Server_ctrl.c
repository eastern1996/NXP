/*£¡
 * @file       Server_ctrl.c
 * @brief      ÁÔ»§×ù¶æ»úPID¿ØÖÆ
 * @author     MAZY
 * @version    v1.0
 * @date       2019-06-02
 */
#include "Server_ctrl.h"
#include "Motor_ctrl.h"
#define SERVER_MIDDLE 7.25
#define SERVER_LIMIT 4.75

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

void Server_Init()
{
    ftm_pwm_init(FTM2,FTM_CH0,50,SERVER_MIDDLE,FTM2_CH0_PIN);
}

void Server_Run(float duty)
{
#ifdef SERVER_DEBUG
    static uint8 flag = 0;
    static float text_duty = 0;

    if(flag)text_duty -= 0.1;
    else text_duty += 0.1;
    if(text_duty > SERVER_MIDDLE+SERVER_LIMIT)
    {
        text_duty = SERVER_MIDDLE+SERVER_LIMIT;
        flag = 1;
    }
    if(text_duty < SERVER_MIDDLE-SERVER_LIMIT)
    {
        text_duty = SERVER_MIDDLE-SERVER_LIMIT;
        flag = 0;
    }
#ifdef SERVER_GO_TO_MIDDLE
    text_duty = SERVER_MIDDLE;
#endif
    ftm_pwm_duty(FTM2, FTM_CH0,text_duty);
#endif
#ifndef SERVER_DEBUG
    if(duty > SERVER_MIDDLE+SERVER_LIMIT)duty = SERVER_MIDDLE+SERVER_LIMIT;
    if(duty < SERVER_MIDDLE-SERVER_LIMIT)duty = SERVER_MIDDLE-SERVER_LIMIT;
    ftm_pwm_duty(FTM2, FTM_CH0,duty);
#endif
}

void Server_PID_Ctrl()
{
    float derror = 0;
    Server_Run(derror);
    
}
