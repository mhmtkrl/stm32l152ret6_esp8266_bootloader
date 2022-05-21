#include "stm32l1xx.h"                  // Device header
#include "gpio_config.h"
#include "sysTick_timer_config.h"
#include "esp8266_driver.h"
#include "flash_config.h"
#include "program_memory.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

uint8_t txt[] = "FOTA over WiFi!\r\n";

char pkt[128];
char destinationIP[] = "192.168.1.4";
const int destinationPORT = 5555;
const int localPORT = 7777;

uint8_t transferStart = 0x01;
uint8_t transferContiune = 0x02;
uint16_t len = 0;

uint32_t myData;

char ptr_pos[8];
int j = 0;
char *ptr;
uint32_t adr = 0;
uint16_t packetCounter = 1;

typedef struct {
	uint8_t packetData[8];
}BootPacket;

BootPacket bootPacket[140];
uint8_t udp[128];
uint8_t getData = 0;
int pktAdr = 0;


void USART3_IRQHandler() {
	if((USART3->SR & (1ul << 5))) {
		pkt[pktAdr] = USART3->DR;

		if(pkt[pktAdr] == ':') getData = 1;
		
		pktAdr++;
		USART3->SR &= ~(1ul << 5);
	}
}

int main() {
	//BootJump( ( uint32_t * )APPLICATION_FIRMWARE_BASE_ADDRESS ) ;
	InitSysTickTimerInMiliseconds(1, (uint32_t)CLOCK_FREQ);
	InitUARTforDebug();
	InitUARTforESP8266();
	InitUserLED();
	clearEntireScreen();
	UARTDebugSend(txt);
	
	/*
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x100);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x200);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x300);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x400);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x500);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x600);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x700);
	program_Memory_Page_Erase(APPLICATION_FIRMWARE_BASE_ADDRESS + VECTOR_BASE + 0x800);
	*/
	

	sprintf(udp, "%c", transferStart);
  sendUDPpacket(udp);
	
			
	
	while(1) {
		if(getData) {
			
			delayMS(1);
			ptr = strchr(pkt, ':');
			
			sprintf(msg, "\r#%i. Received Packet: %s", packetCounter, ptr_pos);
			UARTDebugSend(msg);

			for(j = 0 ; j < 4 ; j++) {
				ptr_pos[j] = *(ptr + j + 1);
				sprintf(msg, "\r-->@0x%X = 0x%X", (0x08008000 + j), (uint32_t)ptr_pos[j]);
		    UARTDebugSend(msg);
			}
			program_Memory_Fast_Word_Write((APPLICATION_FIRMWARE_BASE_ADDRESS + adr), ((ptr_pos[3] << 24) | (ptr_pos[2] << 16) | (ptr_pos[1] << 8) | (ptr_pos[0] << 0)));
			adr += 4;
			
			getData = 0;
			for(j = 0 ; j < pktAdr ; j++) {
				pkt[j] = '\0';
			}
			pktAdr = 0;
			sprintf(udp, "%c", transferContiune);
			pktAdr = sendUDPpacket(udp);
			
			if(packetCounter >= 337) {
				locking_Program_Memory();
				BootJump( ( uint32_t * )APPLICATION_FIRMWARE_BASE_ADDRESS ) ;
			}
			
			packetCounter++;
		}
	}
}
