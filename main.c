#include "Gpio.h"
#include "Sys_Timer_Api.h"
#include "Uart_Api.h"
#include "Esp8266_Api.h"

uint8_t msg[14] = "Hello World!\r\n";
uint8_t AT[4] = "AT\r\n";

int main() {
	/* Init SysTick Timer for generating Delay */
	Init_System_Timer(2097000);
	/* Init UART for debugging and communacating with esp8266 */
	Init_Uart_For_Communication();
	/* Init GPIO for user LED */
	Init_User_Led();

	Set_User_Led();
	ESP8266_Test();
	volatile int i = 0;
	for(i = 0 ; i < 509700 ; i++) {
		
	}
	Reset_User_Led();
	ESP8266_Version();
	
	while(1) {
	
	}
}
