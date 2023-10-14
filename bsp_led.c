/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   led应用函数接口
  ******************************************************************************
 
  ******************************************************************************
  */
  
#include "bsp_led.h"   
#include "delay.h"

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_AHB1PeriphClockCmd ( LED1_GPIO_CLK|
	                           LED2_GPIO_CLK|
	                           LED3_GPIO_CLK, ENABLE); 

		/*选择要控制的GPIO引脚*/															   
		GPIO_InitStructure.GPIO_Pin = LED1_PIN;	

		/*设置引脚模式为输出模式*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
    
    /*设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    
    /*设置引脚为上拉模式*/
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

		/*设置引脚速率为2MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 

		/*调用库函数，使用上面配置的GPIO_InitStructure初始化GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
    
    /*选择要控制的GPIO引脚*/															   
		GPIO_InitStructure.GPIO_Pin = LED2_PIN;	
    GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);	
    
    /*选择要控制的GPIO引脚*/															   
		GPIO_InitStructure.GPIO_Pin = LED3_PIN;	
    GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	
		
		/*关闭RGB灯*/
		LED_RGBOFF;		
}
void Init_BEEP(void)
{
	//第一步 定义结构体变量
	GPIO_InitTypeDef  GPIO_BeepInitStructure;
  /* GPIOG Peripheral clock enable */
	//第二步开启时钟
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Configure PG6 and PG8 in output pushpull mode */
	//第三步给结构体成员变量赋值
  GPIO_BeepInitStructure.GPIO_Pin = LED3_PIN;
  GPIO_BeepInitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_BeepInitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_BeepInitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_BeepInitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	//第四步  初始化结构体
  GPIO_Init(GPIOB, &GPIO_BeepInitStructure);
	
	GPIO_ResetBits(GPIOB,LED3_PIN);
	//GPIO_SetBits(GPIOB,LED3_PIN);
	
	//设置IO口的高电平
	//GPIO_SetBits(GPIOE,LED2_PIN);
	//设置IO口的低电平
	//GPIO_ResetBits(GPIOE,LED2_PIN);
	
}


void LED_LSD(void)
{
		GPIO_ResetBits(GPIOE,GPIO_Pin_10); 
		GPIO_SetBits(GPIOE,GPIO_Pin_8); 
		GPIO_SetBits(GPIOE,GPIO_Pin_9); 
		delay_ms(400);
		GPIO_ResetBits(GPIOE,GPIO_Pin_9); 
		GPIO_SetBits(GPIOE,GPIO_Pin_8); 
		GPIO_SetBits(GPIOE,GPIO_Pin_10); 
		delay_ms(300);
		GPIO_ResetBits(GPIOE,GPIO_Pin_8); 
		GPIO_SetBits(GPIOE,GPIO_Pin_9); 
		GPIO_SetBits(GPIOE,GPIO_Pin_10); 
		delay_ms(200);
		GPIO_ResetBits(GPIOE,GPIO_Pin_9); 
		GPIO_SetBits(GPIOE,GPIO_Pin_8); 
		GPIO_SetBits(GPIOE,GPIO_Pin_10); 
		delay_ms(100);
	
}

/*********************************************END OF FILE**********************/
