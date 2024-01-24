#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

/**
  * @brief  led³õÊ¼»¯
  *
  * @param  None
  *
  * @retval None
  */
void Led_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOC, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
}
/**
  * @brief  ºìµÆ×´Ì¬·­×ª
  *
  * @param  None
  *
  * @retval None
  */
void Led_RedFlib(void)
{
	GPIO_WriteBit(GPIOD, GPIO_Pin_14, !((BitAction)GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_14)));
}
/**
  * @brief  ÂÌµÆ×´Ì¬·­×ª
  *
  * @param  None
  *
  * @retval None
  */
void Led_GreenFlib(void)
{
	GPIO_WriteBit(GPIOC, GPIO_Pin_8, !((BitAction)GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_8)));
}
void Led_BlueFlib(void)
{
	GPIO_WriteBit(GPIOD, GPIO_Pin_15, !((BitAction)GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_15)));
}
void Led_RedOn(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_14);
}
void Led_GreenOn(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_8);
}
void Led_BlueOn(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_15);
}
void Led_RedOff(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_14);
}
void Led_GreenOff(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_8);
}
void Led_BlueOff(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_15);
}


