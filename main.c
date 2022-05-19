#include "stm32l1xx.h"                  // Device header
#include "gpio_config.h"
#include "sysTick_timer_config.h"

int main() {
	InitSysTickTimerInMiliseconds(1, (uint32_t)CLOCK_FREQ);
	InitUserLED();
	
	while(1) {
		OnUserLED();
		delayMS(1000);
		OffUserLED();
		delayMS(1000);
	}
}
