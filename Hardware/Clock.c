#include "clock.h"
#include "stdlib.h"

pClock cthis;

void Clock_Print(void);
void Clock_Update(void);

pClock Clock_Create(void)
{
	pClock clock_c = (pClock)malloc(sizeof(pClock));
	
	if(clock_c == NULL)
	{
		return NULL;
	}
	
	clock_c->Second = 0;
	clock_c->Minute = 0;
	clock_c->Hour = 0;
	
	clock_c->pClock_Print = Clock_Print;
	clock_c->pClock_Update = Clock_Update;
	
	cthis = clock_c;
	return clock_c;
}

pClock Clock_CreateWithArgs(uint8_t Hour, uint8_t Minute, uint8_t Second)
{
	pClock clock_c = Clock_Create();
	if(clock_c == NULL)
	{
		return NULL;
	}
	ImportSecond = Second;
	clock_c->Second = Second;
	clock_c->Minute = Minute;
	clock_c->Hour = Hour;
	
	return clock_c;
}

void Clock_Print(void)
{
	OLED_ShowNum(1, 1, cthis->Hour, 2);
	OLED_ShowString(1, 3, ":");
	OLED_ShowNum(1, 4, cthis->Minute, 2);
	OLED_ShowString(1, 6, ":");
	OLED_ShowNum(1, 7, cthis->Second, 2);
}

void Clock_Update(void)
{
	cthis->Second = ImportSecond;
	if(cthis->Second >= 60)
	{
		cthis->Minute += cthis->Second / 60;
		cthis->Second %= 60;
		ImportSecond %= 60;
		
		if(cthis->Minute >= 60)
		{
			cthis->Hour += cthis->Minute / 60;
			cthis->Minute %= 60;
			
			if(cthis->Hour == 24)
			{
				cthis->Hour %= 24;
			}
		}
	}
}

