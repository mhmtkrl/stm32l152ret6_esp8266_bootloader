#include "esp8266_driver.h"
#include "stdio.h"
#include <string.h>
#include "sysTick_timer_config.h"

int sendCommandToEsp8266(char *cmd, char *response, char *check) {
	int errorCount = 0;
	char *ptr;
	GPIOD->ODR &= ~(1ul << 12);
	ptr=NULL;
		while(ptr == NULL) {
			ptr = NULL;
			GPIOD->ODR |= 1ul << 15;
			UARTBluetoothSend(cmd);
//			delayMs(800);
			ptr = strstr(response, check);
//			if(strstr(response, "\r\n+IPD")) {
//				GPIOD->ODR |= 1ul << 13;
//			}
			errorCount++;
			//if(errorCount >= 5) NVIC_SystemReset();
		}
		
	GPIOD->ODR &= ~(1ul << 15);
	GPIOD->ODR |= 1ul << 12;
	return 0;
}

int estaplishUDPsoket(char IPd[], int dIP, int lIP, char *response, char *check) {
	char udp[128];
	sendCommandToEsp8266("AT+CIPCLOSE\r\n", response, check);
	sprintf(udp, "AT+CIPSTART=\"UDP\",\"192.168.43.221\",%d,%d\r\n", dIP, lIP);
	sendCommandToEsp8266(udp, response, check);
	return 0;
}

int sendUDPpacket(char *pkt, char *response, char *check) {
	char msg[128];
	char tcpPkt[128];
	
	uint16_t len = 0;
	
	len = sprintf(msg, "%s", pkt);
	sprintf(tcpPkt, "AT+CIPSEND=%d\r\n", len);
	sendCommandToEsp8266(tcpPkt, response, check);
	sendCommandToEsp8266(msg, response, check);
	return 0;
}

int sendUDP(char *pkt) {
	char msg[128];
	char tcpPkt[128];
	
	uint16_t len = 0;
	
	len = sprintf(msg, "%s", pkt);
	sprintf(tcpPkt, "AT+CIPSEND=%d\r\n", len);
	UARTBluetoothSend(tcpPkt);
//	delayMs(500);
	UARTBluetoothSend(msg);
//	delayMs(500);
	return 0;
}
