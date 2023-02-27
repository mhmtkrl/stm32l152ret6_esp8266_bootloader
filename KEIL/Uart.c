/**
 * @file Uart.c
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init uart
 */
 
#include "Uart.h"
#include "Uart_Api.h"

/**
 * \brief Init Uart peripherals for debugging and esp8266
 *
 * \details baudrate: 115200
 * 
 * \param none
 * \param none
 * \return none
 */
void Init_Uart_For_Communication(void) {
	/* Init uart for Wifi */
	Init_Uart_For_Esp8266();
	/* Init uart for debug */
	Init_Uart_For_Debug();
}

/**
 * \brief Init UART3 for ESP8266
 *
 * \details pin description
 *	PB10 -> USART3_TX	  -> AFIO7
 *	PB11 -> USART3_RX		-> AFIO7
 * 
 * \param none
 * \param none
 * \return none
 */
static void Init_Uart_For_Esp8266(void) {
	/* AHB is enabled for GPIOB */
	RCC->AHBENR |= 1ul << 1;
	/* AFIO7 for PB10 */
	GPIOB->AFR[1] |= (7ul << 8);
	/* AFIO7 for PB11 */
	GPIOB->AFR[1] |= (7ul << 12);
	/* PB10 is alternate function mode */
	GPIOB->MODER &= ~(1ul << 20);
	GPIOB->MODER |= (1ul << 21);
	/* PB11 is alternate function mode */
	GPIOB->MODER &= ~(1ul << 22);
	GPIOB->MODER |= (1ul << 23);
	
	/* USART3 clock enable */
	RCC->APB1ENR |= (1ul << 18);
	/* Enable USART3 */
	USART3->CR1 |= (1ul << 13);
	/* 1 Start bit, 8 Data bits, n Stop bit */
	USART3->CR1 &= ~(1ul << 12);
	/* 1 Stop bit */
	USART3->CR2 &= ~(1ul << 12);
	USART3->CR2 &= ~(1ul << 13);
	/* oversampling by 16 */
	USART3->CR1 &= ~(1ul << 15);
	/* 
	*BRR
	*OVER8 = 0;
	*USARTDIV = Fclk / (8*2*BaudRate)
	*USARTDIV = 2097000/16*115200 = 1.1376..
	*Mantissa -> 1
	*Fraction -> 0.1376 * 16 ~= 2;
	*USARTDIV = 0x12;
	*/
	USART3->BRR = 0x00000012;
	/* RXNE interrupt enable */
	USART3->CR1 |= (1ul << 5);
  /* Receiver enable */
	USART3->CR1 |= (1ul << 2);
	NVIC_EnableIRQ(USART3_IRQn);
	/* Transmitter enable */
	USART3->CR1 |= (1ul << 3);
}

/**
 * \brief Init UART2 for debugging
 *
 * \details The USART2 interface available on PA2 and PA3 of the STM32 microcontroller can be connected to ST-LINK MCU - Page 25. UM1724
 * PA2 -> USART2_TX	-> AFIO7
 * PA3 -> UART2_RX	-> AFIO7
 * 
 * \param none
 * \param none
 * \return none
 */
static void Init_Uart_For_Debug(void) {
	//AHB is enabled for GPIOA
	RCC->AHBENR |= 1ul << 0;
	//AFIO7 for PA2
	GPIOA->AFR[0] |= (7ul << 8);
	//AFIO7 for PA3
	GPIOA->AFR[0] |= (7ul << 12);
	//PA2 is alternate function mode
	GPIOA->MODER &= ~(1ul << 4);
	GPIOA->MODER |= (1ul << 5);
	//PA3 is alternate function mode
	GPIOA->MODER &= ~(1ul << 6);
	GPIOA->MODER |= (1ul << 7);
	
	//USART2 clock enable
	RCC->APB1ENR |= (1ul << 17);
	//Enable USART2
	USART2->CR1 |= (1ul << 13);
	//1 Start bit, 8 Data bits, n Stop bit
	USART2->CR1 &= ~(1ul << 12);
	//1 Stop bit
	USART2->CR2 &= ~(1ul << 12);
	USART2->CR2 &= ~(1ul << 13);
	//oversampling by 16
	USART2->CR1 &= ~(1ul << 15);
	//BRR
	//OVER8 = 0;
	//USARTDIV = Fclk / (8*2*BaudRate)
	//USARTDIV = 2097000/16*115200 = 1.1376..
	//Mantissa -> 1
	//Fraction -> 0.1376 * 16 ~= 2;
	//USARTDIV = 0x12;
	USART2->BRR = 0x00000012;
	//RXNE interrupt enable
	USART2->CR1 |= (1ul << 5);
	//Receiver enable
	USART2->CR1 |= (1ul << 2);
	NVIC_EnableIRQ(USART2_IRQn);
	//Transmitter enable
	USART2->CR1 |= (1ul << 3);
}

