#ifndef __CLOCK_H
#define __CLOCK_H

#include "stm32f4xx.h"
#include "oled.h"

extern uint8_t ImportSecond;
extern void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
extern void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);

typedef struct Clock *pClock;

typedef struct Clock{
	uint8_t Second;
	uint8_t Minute;
	uint8_t Hour;
	
	void (*pClock_Update)(void);
	void (*pClock_Print)(void);
}Clock;

pClock Clock_Create(void);
pClock Clock_CreateWithArgs(uint8_t Second, uint8_t Minute, uint8_t Hour);

#endif

