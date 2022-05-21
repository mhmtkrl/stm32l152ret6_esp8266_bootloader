#include "stm32l1xx.h"                  // Device header
#include "gpio_config.h"
#include "sysTick_timer_config.h"
#include "esp8266_driver.h"
#include <stdint.h>

uint8_t txt[] = "FOTA over WiFi!\r\n";

char pkt[64];
char destinationIP[] = "192.168.1.4";
const int destinationPORT = 6666;
const int localPORT = 7777;

uint8_t transferStart = 0x01;
uint8_t transferContiune = 0x02;
uint16_t len = 0;
	
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

		if(pkt[pktAdr] == '\r') getData = 1;
		
		pktAdr++;
		USART3->SR &= ~(1ul << 5);
	}
}

int main() {
	InitSysTickTimerInMiliseconds(1, (uint32_t)CLOCK_FREQ);
	InitUARTforDebug();
	InitUARTforESP8266();
	InitUserLED();
	clearEntireScreen();
	UARTDebugSend(txt);


	UARTESP8266Send("AT+CIPCLOSE\r\n");
	delayMS(500);
	sprintf(udp, "AT+CIPSTART=\"UDP\",\"%s\",%d,%d\r\n", destinationIP, destinationPORT, localPORT);
	UARTESP8266Send(udp);
	delayMS(500);
	sendUDPpacket("Hello World!");
	
	while(1) {
		OnUserLED();
		delayMS(1000);
		OffUserLED();
		delayMS(1000);
		if(getData == 1) {
			UARTDebugSend(pkt);
			getData = 0;
			pktAdr = 0;
		}
	}
}
