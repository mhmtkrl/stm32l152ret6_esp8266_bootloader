#include "Gpio.h"
#include "Sys_Timer.h"
#include "Uart_Api.h"

int main() {
	/* Init SysTick Timer for generating Delay */
	Init_System_Timer(2097000);
	/* Init UART for debugging and communacating with esp8266 */
	Init_Uart_For_Communication();
	/* Init GPIO for user LED */
	Init_User_Led();

	while(1) {
	
	}
}
