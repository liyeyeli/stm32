#include "uart.h"



void UART1_Init(u32 bol)
{

	GPIO_InitTypeDef GPIO_InitStructure;//GPIO初始化
	USART_InitTypeDef USART_InitStruct;//串口初始化
	NVIC_InitTypeDef NVIC_InitStruct;//配置中断优先级
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	
	//（1）使能串口时钟及GPIO端口时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//使能USART1时钟 

	//（2）设置引脚复用器映射 
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9复用为USART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10复用为USART1 
	
	//（3）GPIO端口模式设置，设置串口对应的引脚为复用功能
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推完输出
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	 GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	 GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
	 
	 GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//(4)串口初始化
	//void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
	USART_InitStruct.USART_BaudRate = bol;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode =  USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	
	USART_Cmd(USART1, ENABLE);
	
	//设置串口中断类型并使能
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启接收中断
	//配置中断优先级
	//void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct)
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	
}


void USART1_IRQHandler(void)
{
	u8 data_bit;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		data_bit = USART_ReceiveData(USART1);
		USART_SendData(USART1,data_bit);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	}
	
}


