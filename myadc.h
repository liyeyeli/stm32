#ifndef __ADC_H
#define __ADC_H	

#include "sys.h" 

 							   
void  myAdcInit(void); 				//ADC通道初始化
u16   getAdc(u8 ch); 				//获得某个通道值 
u16   getAdcAverage(u8 ch,u8 times);//得到某个通道给定次数采样的平均值  



#endif 















