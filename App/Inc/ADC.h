#ifndef ADC_H
#define ADC_H

#include "common.h"
#include "include.h"
/*************************************************************************
                           板子所用到的AD口
 ADC1_SE8   ADC1_SE11   ADC0_SE12   ADC1_SE12   ADC1_SE10   ADC1_SE13 
   ADC1        ADC2       ADC3        ADC4       ADC5        ADC6
   PTB0        PTB5       PTB2        PTB6       PTB4        PTB7 
*************************************************************************/
#define ADC1 ADC1_SE8     //PTB0
#define ADC2 ADC0_SE9     //PTB1
#define ADC3 ADC0_SE12    //PTB2
#define ADC4 ADC0_SE13    //PTB3
#define ADC5 ADC1_SE10    //PTB4
#define ADC6 ADC1_SE11    //PTB5
#define ADC7 ADC1_SE12    //PTB6
#define ADC8 ADC1_SE13    //PTB7




void ADC_Init();
void Read_ADC();

extern int16  L_AD , R_AD , LS_AD , RS_AD , LM_AD , RM_AD , M_AD , MS_AD;

#endif