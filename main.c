#include "stm32l1xx.h"                  // Device header
#include "gpio_config.h"
#include "sysTick_timer_config.h"
#include "esp8266_driver.h"

uint8_t txt[] = "FOTA over WiFi!\r\n";

char pkt[64];
char destinationIP[] = "192.168.43.221";
const int destinationPORT = 6666;
const int localIP = 7777;
char udpPkt[128];

uint8_t getData = 0;
char pkt[64];
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
	InitUARTforBluetooth();
	InitUserLED();
	clearEntireScreen();
	UARTDebugSend(txt);

	
	
	
	while(1) {
		//UARTBluetoothSend("AT\r\n");
		sendCommandToEsp8266("AT\r\n", pkt, "\r\nOK\r\n");
		
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
