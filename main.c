#include "stm32l1xx.h"                  // Device header
#include "Gpio.h"
#include "Sys_Timer.h"
#include "esp8266_driver.h"
#include "flash_config.h"
#include "program_memory.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Welcome message
uint8_t txt[] = "FOTA over WiFi!\r\n";

//Network related variables
char pkt[128];
char destinationIP[] = "X.X.X.X";
const int destinationPORT = 457;
const int localPORT = 456;

//Protocol related variables
uint8_t transferStart = 0x01;
uint8_t transferContiune = 0x02;
char ptr_pos[8];
int j = 0;
char *ptr;
uint32_t adr = 0;
uint16_t packetCounter = 1;
uint8_t getData = 0;
int pktAdr = 0;

//Processing the response of ESP8266
void USART3_IRQHandler() {
	if((USART3->SR & (1ul << 5))) {
		pkt[pktAdr] = USART3->DR;

		if(pkt[pktAdr] == ':') getData = 1;
		
		pktAdr++;
		USART3->SR &= ~(1ul << 5);
	}
}

int main() {
	/* Init SysTick Timer for generating Delay */
	Init_System_Timer(2097000);
	//Init UART for debugging pupose via USB cable
	InitUARTforDebug();
	//Init UART for communication with ESP8266
	InitUARTforESP8266();
	/* Init GPIO for user LED */
	Init_User_Led();
	//Clear debug screen
	clearEntireScreen();
	//Welcome message
	UARTDebugSend(txt);
	
	//Before writing any data to the FLASH first clear it
	eraseApplicationCodeArea();
	
	//Delay for auto-connection to the hotspot for ESP8266
	//delayMS(5000);
	
	//If is there already a connection close it first
	UARTESP8266Send("AT+CIPCLOSE\r\n");
	//delayMS(500);
	//Establishing a connection
	sprintf(msg, "AT+CIPSTART=\"UDP\",\"%s\",%d,%d\r\n", destinationIP, destinationPORT, localPORT);
	UARTESP8266Send(msg);
	//delayMS(500);
	
	//Ready to receive file packets
	sendUDPChar(transferStart);

	while(1) {
		//If there is received packet
		if(getData) {
			
			//delayMS(1);
			//Get the address of specific character in the received packet
			ptr = strchr(pkt, ':');
			
			sprintf(msg, "\r#%i. Received Packet: %s", packetCounter, ptr_pos);
			UARTDebugSend(msg);

			//Processing for bytes data
			for(j = 0 ; j < 4 ; j++) {
				ptr_pos[j] = *(ptr + j + 1);
				sprintf(msg, "\r-->@0x%X = 0x%X", (0x08008000 + adr + j), (uint32_t)ptr_pos[j]);
		    UARTDebugSend(msg);
			}
			//Writing the packets to the Flash 
			program_Memory_Fast_Word_Write((APPLICATION_FIRMWARE_BASE_ADDRESS + adr), ((ptr_pos[3] << 24) | (ptr_pos[2] << 16) | (ptr_pos[1] << 8) | (ptr_pos[0] << 0)));
			adr += 4;
			
			//Clear the buffer
			getData = 0;
			for(j = 0 ; j < pktAdr ; j++) {
				pkt[j] = '\0';
			}
			pktAdr = 0;
	
			//Says ready to new packet
			sendUDPChar(transferContiune);
			
			//If packet count is reached to the file size then jump to the Application code
			if(packetCounter >= 550) {
				//delayMS(100);
				locking_Program_Memory();
				BootJump( ( uint32_t * )APPLICATION_FIRMWARE_BASE_ADDRESS ) ;
			}
			
			packetCounter++;
		}
	}
}
