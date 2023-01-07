/**
 * @file Uart_Comm.c
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to handle uart communication
 */
 
 #include "Uart_Comm.h"
 #include "Uart_Api.h"
 
/* internal variables */
static USART_TypeDef *Debug = (USART_TypeDef*)USART2_BASE;
static USART_TypeDef *Esp8266 = (USART_TypeDef*)USART3_BASE;

/* internal buffer for esp8266 */
char ESP8266_Response_Buffer[256];
uint8_t ESP8266_Response_Length = 0;

/* internal buffer for debug */
char Debug_Response_Buffer[256];
uint8_t Debug_Response_Length = 0;

/* internal flag for received packet */
uint8_t received = 0;

 /**
 * \brief Received packet handler for esp8266
 *
 * \details none
 * 
 * \param uint8_t none
 * \return none
 */
void USART3_IRQHandler(void) {
	/* \todo: create an api for processing received packet
	 * command or data comming via UDP/TCP-IP
	 * If it's a cmd call related funtion and perform desired task
	*/
	if(Esp8266->SR & (1ul << 5)) {
		ESP8266_Response_Buffer[ESP8266_Response_Length] = Esp8266->DR;

		ESP8266_Response_Length++;
		//if(ESP8266_Response_Length > 4) {
			/* Check if OK received */
			if(ESP8266_Response_Buffer[ESP8266_Response_Length-1] == '\n' 
			&& ESP8266_Response_Buffer[ESP8266_Response_Length-2] == '\r'
			&& ESP8266_Response_Buffer[ESP8266_Response_Length-3] == 'K'
			&& ESP8266_Response_Buffer[ESP8266_Response_Length-4] == 'O'
			) {
				ESP8266_Process_Response(&ESP8266_Response_Buffer[0], ESP8266_Response_Length, 0);
				ESP8266_Response_Length = 0;
			}
			
			/* Check if ERROR received */
			else if(ESP8266_Response_Buffer[ESP8266_Response_Length-1] == '\n' 
					 && ESP8266_Response_Buffer[ESP8266_Response_Length-2] == '\r'
					 && ESP8266_Response_Buffer[ESP8266_Response_Length-3] == 'R'
					 && ESP8266_Response_Buffer[ESP8266_Response_Length-4] == 'O'
			) {
				ESP8266_Process_Response(&ESP8266_Response_Buffer[0], ESP8266_Response_Length, 0);
				ESP8266_Response_Length = 0;
			}
			
			/* Check if any message transmitted from server is available */
			else if(ESP8266_Response_Buffer[ESP8266_Response_Length-1] == 'D' 
				&& ESP8266_Response_Buffer[ESP8266_Response_Length-2] == 'P'
				&& ESP8266_Response_Buffer[ESP8266_Response_Length-3] == 'I' 
			) {
				/* Server has sent packet */
				received = 1;
			}
			
			/* Message completly received from server than transfer it to the main app for processing */
			else if(received == 1
			 && ESP8266_Response_Buffer[ESP8266_Response_Length-1] == '\n' 
			 && ESP8266_Response_Buffer[ESP8266_Response_Length-2] == '\r'
			) {
				ESP8266_Process_Response(&ESP8266_Response_Buffer[0], ESP8266_Response_Length, 0);
				ESP8266_Response_Length = 0;
				received = 0;
			}
			
			else {
				
			}
		
		
		/* Reset ISR Flag */
		Esp8266->SR &= ~(1ul << 5);
	}
}

 /**
 * \brief Received packet handler for debug channel
 *
 * \details none
 * 
 * \param uint8_t none
 * \return none
 */
void USART2_IRQHandler(void) {
	if(Debug->SR & (1ul << 5)) {
		Debug_Response_Buffer[Debug_Response_Length] = Debug->DR;
		Debug_Response_Length++;
		
		if(Debug->DR == '\r') {

			Debug_Response_Buffer[Debug_Response_Length] = '\n';
			Debug_Response_Length++;
			Uart_Send_Command(Debug_Response_Length, &Debug_Response_Buffer[0]);
			Debug_Response_Length = 0;
		}

		/* Reset ISR Flag */
		Debug->SR &= ~(1ul << 5);
	}
}

 /**
 * \brief Send debug packet via UART channel
 *
 * \details none
 * 
 * \param uint8_t length
 * \param uint8_t *cmd
 * \return none
 */
 void Uart_Send_Debug_Message(uint8_t length, char *cmd) {
	 uint8_t cmdIndex = 0;
	 for(cmdIndex = 0 ; cmdIndex < length ; cmdIndex++) {
		 Uart_Send_Char(Debug, cmd[cmdIndex]);
	 }
 }
 
 /**
 * \brief Send command via UART channel
 *
 * \details none
 * 
 * \param uint8_t length
 * \param uint8_t *cmd
 * \return none
 */
 void Uart_Send_Command(uint8_t length, char *cmd) {
	 uint8_t cmdIndex = 0;
	 for(cmdIndex = 0 ; cmdIndex < length ; cmdIndex++) {
		 Uart_Send_Char(Esp8266, cmd[cmdIndex]);
	 }
 }

 /**
 * \brief Send 1 byte data via UART channel
 *
 * \details none
 * 
 * \param USART_TypeDef *Channel
 * \param uint8_t ch
 * \return none
 */
 void Uart_Send_Char(USART_TypeDef *Channel, char ch) {
	 /* Transmit data register empty */
	 
	 while(!(Channel->SR & (1ul << 7)));
	 Channel->DR = ch;
}

