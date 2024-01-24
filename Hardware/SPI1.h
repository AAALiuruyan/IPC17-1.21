#ifndef __SPI1_H
#define __SPI1_H
#include "sys.h" 
/*---------------------- ICM���ú� ------------------------*/

#define ICM_CS_PIN        GPIO_Pin_3       		 //CS����      
#define ICM_MISO_PIN      GPIO_Pin_4       		 //MISO����       
#define ICM_MOSI_PIN      GPIO_Pin_7      		 //MOSI����  
#define ICM_SCK_PIN       GPIO_Pin_5       		 //SCK����
#define ICM_INT_PIN       GPIO_Pin_8      		 //SCK����
#define ICM_MSC_PORT      GPIOA                     // SPI1 MISO MOSI CS �˿�    
#define ICM_MSC_CLK       RCC_AHB1Periph_GPIOA         // SPI1 MISO MOSI CS �˿�     
#define ICM_MISO_PORT     GPIOB    // SPI1 SCK�˿�ʱ��
#define ICM_SCK_CLK       RCC_AHB1Periph_GPIOB    // SPI1 SCK�˿�ʱ��
#define ICM_CSINT_PORT    GPIOE    // CS&INT
#define ICM_CSINT_CLK     RCC_AHB1Periph_GPIOE    // CS&INT
 void SPI1_Init(void);
void SPI1_Start(void);
void SPI1_Stop(void);
//SPI1 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u8 SPI1_ReadWriteByte(u8 TxData);
#endif

