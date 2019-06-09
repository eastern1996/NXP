/*£¡
 * @file       Server_ctrl.c
 * @brief      ÁÔ»§×ù¶æ»úPID¿ØÖÆ
 * @author     MAZY
 * @version    v1.0
 * @date       2019-06-02
 */
#include "Server_ctrl.h"
#include "Motor_ctrl.h"
#define SERVER_MIDDLE 7575
#define SERVER_LIMIT 1700

PID Server;

void PID_Init(void)
{
    Server.Kp = 20;
    Server.Ki = 2;
    Server.Kd = 0;
    
    Motor.Kp = 50;
    Motor.Ki = 5;
    Motor.Kd = 0;
    Motor.Set_Speed = 30;
}

void Server_Init()
{
    ftm_pwm_init(FTM2,FTM_CH0,50,SERVER_MIDDLE,FTM2_CH0_PIN);
}

void Server_Run(float duty)
{
#ifdef SERVER_DEBUG
    float text_duty = 0;
    if(key_get(KEY_1) == KEY_DOWN)
    {
        if(key_get(KEY_2) == KEY_DOWN)text_duty = SERVER_MIDDLE;
        else text_duty = SERVER_MIDDLE+SERVER_LIMIT;//ÓÒ
    }
    else text_duty = SERVER_MIDDLE-SERVER_LIMIT;//×ó

    ftm_pwm_duty(FTM2, FTM_CH0,text_duty/1000.0);
#endif
#ifndef SERVER_DEBUG
    if(duty > SERVER_MIDDLE+SERVER_LIMIT)duty = SERVER_MIDDLE+SERVER_LIMIT;
    if(duty < SERVER_MIDDLE-SERVER_LIMIT)duty = SERVER_MIDDLE-SERVER_LIMIT;
    ftm_pwm_duty(FTM2, FTM_CH0,duty/1000.0);
#endif
}

void Server_PID_Ctrl()
{
    float error = Get_Direction_Error();
    float derror = error - Server.Last_Error;
    Server.OUTPWM = SERVER_MIDDLE - (Server.Kp*error + Server.Kd*derror);
#ifdef SERVER_PID_UP_DATA
    UP_Value[0] = (int32)error;
    UP_Value[1] = (int32)Server.Last_Error;
    UP_Value[2] = (int32)Server.OUTPWM;
#endif 
    Server.Last_Error = error;
    Server_Run(Server.OUTPWM);
}
float Get_Direction_Error()
{
    float error,xerror,serror,error_sum;
    error  = 100.0*(L_AD-R_AD)/(L_AD+R_AD);
    xerror = 100.0*(LM_AD-RM_AD)/(LM_AD+RM_AD);
    serror = 100.0*(LS_AD-RS_AD)/(LS_AD+RS_AD);
    error_sum = 0.7*error + 0.3*xerror;//+ serror;
    return error_sum;
}