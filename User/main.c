#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "oled.h"
#include "clock.h"
#include "timer.h"

extern uint8_t ImportSecond;

int main(void){
	
	Led_Init();
	OLED_Init();
	Timer_Init();
	pClock clock = Clock_CreateWithArgs(23, 59, 56);
	
	while(1){
		clock->pClock_Update();
		clock->pClock_Print();
	}
}
