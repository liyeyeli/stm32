#ifndef __ADC_H
#define __ADC_H	

#include "sys.h" 

 							   
void  myAdcInit(void); 				//ADCͨ����ʼ��
u16   getAdc(u8 ch); 				//���ĳ��ͨ��ֵ 
u16   getAdcAverage(u8 ch,u8 times);//�õ�ĳ��ͨ����������������ƽ��ֵ  



#endif 















