#include "Gpio.h"
#include "Sys_Timer_Api.h"
#include "Uart_Api.h"
#include "Esp8266_Api.h"
#include "CRC_Calculation_Api.h"
#include "My_Protocol_Api.h"
#include "Flash_Unit_Api.h"
#include <stdio.h>

ESP8266_Command_t Message;
uint16_t Test_Counter = 0;

Checksum_Compare_Result_t result = 0;

int main() {
	/* Init SysTick Timer for generating Delay */
	Init_System_Timer(2097000);
	/* Init UART for debugging and communacating with esp8266 */
	Init_Uart_For_Communication();
	/* Init GPIO for user LED */
	Init_User_Led();
	/* Init CRC */
	Crc_Init();
	/* Init Flash */
	FLASH_Init();
	
	volatile int i = 0;
	
	ESP8266_Echo_Off();
	for(i = 0 ; i < 209700 ; i++) {
		
	}
	ESP8266_Test();
	for(i = 0 ; i < 209700 ; i++) {
		
	}
	ESP8266_Version();
	for(i = 0 ; i < 209700 ; i++) {
		
	}
	UDP();	
	
	while(1) {
		Message.Length = sprintf(Message.Command, "Counter = %d\r\n", Test_Counter++);
		ESP8266_Sends_Data_UDP_Transmission(Message);
		for(i = 0 ; i < 209700 ; i++) {
			
		}
	}
}
