#ifndef _KEY_H_
#define _KEY_H_

#include "common.h"
#include "include.h"

/* 注意中断中的编号也要修改 */
#define Int_GPIO            PTE26              //按键中断引脚
#define Int_VECT            PORTE_VECTORn
#define Int_PORT            PORTE_IRQn

typedef struct
{
    int8 key_value;
    int8 key_flag;
}KEY;

void Key_Init(void);
void Key_Write(uint8 addr,uint8 dat);
extern void Board_Key_Init();
extern void KEY_Mode();
uint8 Get_Keynum(void);
uint8 Key_Read(uint8 addr);

#endif
