#include "uart.h"



void UART1_Init(u32 bol)
{

	GPIO_InitTypeDef GPIO_InitStructure;//GPIO��ʼ��
	USART_InitTypeDef USART_InitStruct;//���ڳ�ʼ��
	NVIC_InitTypeDef NVIC_InitStruct;//�����ж����ȼ�
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	
	//��1��ʹ�ܴ���ʱ�Ӽ�GPIO�˿�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//ʹ��USART1ʱ�� 

	//��2���������Ÿ�����ӳ�� 
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9����ΪUSART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10����ΪUSART1 
	
	//��3��GPIO�˿�ģʽ���ã����ô��ڶ�Ӧ������Ϊ���ù���
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	 GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	 GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
	 
	 GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//(4)���ڳ�ʼ��
	//void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
	USART_InitStruct.USART_BaudRate = bol;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode =  USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	
	USART_Cmd(USART1, ENABLE);
	
	//���ô����ж����Ͳ�ʹ��
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//���������ж�
	//�����ж����ȼ�
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


