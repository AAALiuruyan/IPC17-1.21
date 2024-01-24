#include "Key.h"
#include "oled.h"

extern uint8_t Flag;
/**
  * @brief  按键初始化
  *
  * @param  None
  *
  * @retval None
  */
void Key_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct; 
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed= GPIO_High_Speed;
	
	GPIO_Init(GPIOD, &GPIO_InitStruct);	
	
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource3);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource4);
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = EXTI_Line3 | EXTI_Line4;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_Init(&NVIC_InitStruct);
}

void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3) != RESET)
	{
		delay_ms(20);
		if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == SET)
		{
			Flag = (++Flag)%3;
			Led_BlueFlib();
			EXTI_ClearITPendingBit(EXTI_Line3);
		}
	}
	
}
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4) != RESET)
	{
		delay_ms(20);
		if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_4) == SET)
		{
			Flag = (++Flag)%3;
			Led_BlueFlib();
			EXTI_ClearITPendingBit(EXTI_Line4);
		}
	}
	
}




