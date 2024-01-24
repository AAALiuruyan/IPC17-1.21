#include "SPI1.h"
//PE3:CS
//PB4:MISO
//PA7:MOSI
//PA5:SCK
 //PE8:INT
void SPI1_Init(void)
{
			 GPIO_InitTypeDef GPIO_InitStructure;
       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA ,ENABLE); // 使能GPIOA时钟
       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB ,ENABLE); // 使能GPIOB时钟
       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE ,ENABLE); // 使能GPIOE时钟

       // GPIOB4初始化设置
			 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 													 // PB4上拉输入
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;                        // 输入
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                  
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                        // 上拉
       GPIO_Init(GPIOB, &GPIO_InitStructure);                              // 初始化
			 // GPIOB5/7初始化设置
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_5; 							 // PA5/7   推挽功能输出
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;                        // 输出
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                      // 推挽输出
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                  
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                        // 上拉
       GPIO_Init(GPIOA, &GPIO_InitStructure);                              // 初始化
			 // GPIOE3初始化设置
			 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                           // PE3   推挽功能输出
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;                        // 输出
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                      // 推挽输出
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                  
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                        // 上拉
       GPIO_Init(GPIOE, &GPIO_InitStructure);			 // 初始化
	
	
}

/**
  * 函    数：SPI起始
  * 参    数：无
  * 返 回 值：无
  */
void SPI1_Start(void)
{
	GPIO_WriteBit(GPIOE, GPIO_Pin_3, 0);				//拉低cS，开始时序
}

/**
  * 函    数：SPI终止
  * 参    数：无
  * 返 回 值：无
  */
void SPI1_Stop(void)
{
	GPIO_WriteBit(GPIOE, GPIO_Pin_3, 1);				//拉高cS，终止时序
}

// SPI1 读写一个字节
// TxData:要写入的字节
// 返回值:读取到的字节
u8 SPI1_ReadWriteByte(u8 TxData)
{
      uint8_t i, ByteReceive = 0x00;					//定义接收的数据，并赋初值0x00
	
	for (i = 0; i < 8; i++)						//循环8次，依次交换每一位数据
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_5, 0);							//拉低SCK，上升沿移出数据
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, (TxData & (0x80 >> i)));		//使用掩码的方式取出TxData的指定一位数据并写入到MOSI线
		GPIO_WriteBit(GPIOA, GPIO_Pin_5, 1);								//拉高SCK，下降沿移入数据
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) == 1)
			{
			ByteReceive |= (0x80 >> i);
			}													//读取MISO数据，并存储到Byte变量，当MISO为1时，置变量指定位为1，当MISO为0时，不做处理，指定位为默认的初值0
		
	}
	
	return ByteReceive;								//返回接收到的一个字节数据
}
