/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
 
  ******************************************************************************
  */
  
#include "bsp_led.h"   
#include "delay.h"

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_AHB1PeriphClockCmd ( LED1_GPIO_CLK|
	                           LED2_GPIO_CLK|
	                           LED3_GPIO_CLK, ENABLE); 

		/*ѡ��Ҫ���Ƶ�GPIO����*/															   
		GPIO_InitStructure.GPIO_Pin = LED1_PIN;	

		/*��������ģʽΪ���ģʽ*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
    
    /*�������ŵ��������Ϊ�������*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    
    /*��������Ϊ����ģʽ*/
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

		/*������������Ϊ2MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 

		/*���ÿ⺯����ʹ���������õ�GPIO_InitStructure��ʼ��GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
    
    /*ѡ��Ҫ���Ƶ�GPIO����*/															   
		GPIO_InitStructure.GPIO_Pin = LED2_PIN;	
    GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);	
    
    /*ѡ��Ҫ���Ƶ�GPIO����*/															   
		GPIO_InitStructure.GPIO_Pin = LED3_PIN;	
    GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	
		
		/*�ر�RGB��*/
		LED_RGBOFF;		
}
void Init_BEEP(void)
{
	//��һ�� ����ṹ�����
	GPIO_InitTypeDef  GPIO_BeepInitStructure;
  /* GPIOG Peripheral clock enable */
	//�ڶ�������ʱ��
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Configure PG6 and PG8 in output pushpull mode */
	//���������ṹ���Ա������ֵ
  GPIO_BeepInitStructure.GPIO_Pin = LED3_PIN;
  GPIO_BeepInitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_BeepInitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_BeepInitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_BeepInitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	//���Ĳ�  ��ʼ���ṹ��
  GPIO_Init(GPIOB, &GPIO_BeepInitStructure);
	
	GPIO_ResetBits(GPIOB,LED3_PIN);
	//GPIO_SetBits(GPIOB,LED3_PIN);
	
	//����IO�ڵĸߵ�ƽ
	//GPIO_SetBits(GPIOE,LED2_PIN);
	//����IO�ڵĵ͵�ƽ
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
