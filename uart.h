#ifndef  __UART_H_
#define  __UART_H_

#include "stm32f4xx.h"

void UART1_Init(u32 bol);

void USART1_IRQHandler(void);

#endif
