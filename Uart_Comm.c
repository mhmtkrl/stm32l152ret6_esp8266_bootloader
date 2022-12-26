/**
 * @file Uart_Comm.c
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to handle uart communication
 */
 
 #include "Uart_Comm.h"
 #include "Uart_Api.h"
 
USART_TypeDef *Debug = (USART_TypeDef*)USART2_BASE;
USART_TypeDef *Esp8266 = (USART_TypeDef*)USART3_BASE;

uint8_t data[16];
uint8_t counter = 0;
 /**
 * \brief Received packet handler for esp8266
 *
 * \details none
 * 
 * \param uint8_t none
 * \return none
 */
void USART3_IRQHandler(void) {
	if(Esp8266->SR & (1ul << 5)) {
		data[counter++] = Esp8266->DR;
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
 void Uart_Send_Debug_Message(uint8_t length, uint8_t *cmd) {
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
 void Uart_Send_Command(uint8_t length, uint8_t *cmd) {
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
 void Uart_Send_Char(USART_TypeDef *Channel, uint8_t ch) {
	 /* Transmit data register empty */
	 
	 while(!(Channel->SR & (1ul << 7)));
	 Channel->DR = ch;
}

