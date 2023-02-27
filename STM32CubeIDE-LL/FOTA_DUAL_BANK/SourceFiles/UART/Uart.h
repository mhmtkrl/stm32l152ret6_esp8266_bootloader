/**
 * @file Uart.h
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init system timer
 */
 
#include "stm32l1xx.h"                  // Device header
#include "stdint.h"

/* API include */

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
static void Init_Uart_For_Esp8266(void);

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
static void Init_Uart_For_Debug(void);
