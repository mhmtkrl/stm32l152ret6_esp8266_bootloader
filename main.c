#include "stm32l1xx.h"                  // Device header
#include "gpio_config.h"
#include "sysTick_timer_config.h"
#include "uart_config.h"

uint8_t txt[] = "FOTA over WiFi!\r\n";

int main() {
	InitSysTickTimerInMiliseconds(1, (uint32_t)CLOCK_FREQ);
	InitUARTforDebug();
	InitUserLED();
	
	UARTDebugSend(txt);
	
	while(1) {
		OnUserLED();
		delayMS(1000);
		OffUserLED();
		delayMS(1000);
	}
}
