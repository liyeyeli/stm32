#ifndef __DHT11_H
#define __DHT11_H 

#include "sys.h"   



//IO方向设置
#define DHT11_IO_IN()  {GPIOA->MODER&=~(3<<(3*2));GPIOA->MODER|=0<<3*2;}	//PA3输入模式
#define DHT11_IO_OUT() {GPIOA->MODER&=~(3<<(3*2));GPIOA->MODER|=1<<3*2;} 	//PA3输出模式 
////IO操作函数											   
#define	DHT11_DQ_OUT PAout(3) //数据端口	PA3 
#define	DHT11_DQ_IN  PAin(3)  //数据端口	PA3

u8 DHT11_Init(void);//初始化DHT11
u8 DHT11_Read_Data(u8 *temp,u8 *humi);//读取温湿度
u8 DHT11_Read_Byte(void);//读出一个字节
u8 DHT11_Read_Bit(void);//读出一个位
u8 DHT11_Check(void);//检测是否存在DHT11
void DHT11_Rst(void);//复位DHT11    
void TX_String(char *String);
void Tx_Data(uint8_t byte);
void printff(char str[],unsigned char num);


#endif















