#ifndef __EXTI_H
#define	__EXTI_H

#include "stm32f4xx.h"

//Òý½Å¶¨Òå
/*******************************************************/
#define KEY1_INT_GPIO_PORT                GPIOE
#define KEY1_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOE
#define KEY1_INT_GPIO_PIN                 GPIO_Pin_4
#define KEY1_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOE  
#define KEY1_INT_EXTI_PINSOURCE           EXTI_PinSource4       
#define KEY1_INT_EXTI_LINE                EXTI_Line4
#define KEY1_INT_EXTI_IRQ                 EXTI4_IRQn

#define KEY1_IRQHandler                   EXTI4_IRQHandler

#define KEY2_INT_GPIO_PORT                GPIOE
#define KEY2_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOE
#define KEY2_INT_GPIO_PIN                 GPIO_Pin_5
#define KEY2_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOE
#define KEY2_INT_EXTI_PINSOURCE           EXTI_PinSource5
#define KEY2_INT_EXTI_LINE                EXTI_Line5
#define KEY2_INT_EXTI_IRQ                 EXTI9_5_IRQn

#define KEY2_IRQHandler                   EXTI9_5_IRQHandler

#define KEY3_INT_GPIO_PORT                GPIOE
#define KEY3_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOE
#define KEY3_INT_GPIO_PIN                 GPIO_Pin_6
#define KEY3_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOE
#define KEY3_INT_EXTI_PINSOURCE           EXTI_PinSource6
#define KEY3_INT_EXTI_LINE                EXTI_Line6
#define KEY3_INT_EXTI_IRQ                 EXTI9_5_IRQn

#define KEY3_IRQHandler                   EXTI9_5_IRQHandler


#define KEY4_INT_GPIO_PORT                GPIOC
#define KEY4_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOC
#define KEY4_INT_GPIO_PIN                 GPIO_Pin_13
#define KEY4_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOC
#define KEY4_INT_EXTI_PINSOURCE           EXTI_PinSource13
#define KEY4_INT_EXTI_LINE                EXTI_Line13
#define KEY4_INT_EXTI_IRQ                 EXTI15_10_IRQn

#define KEY4_IRQHandler                   EXTI15_10_IRQHandler

/*******************************************************/


void EXTI_Key_Config(void);

#endif /* __EXTI_H */
