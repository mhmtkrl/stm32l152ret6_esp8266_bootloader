/**
 * @file Uart_Comm.h
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to handle uart communication
 */
 
#include "stm32l1xx.h"                  // Device header
#include "stdint.h"

 /**
 * \brief Received packet handler for external channel
 *
 * \details none
 * 
 * \param uint8_t none
 * \return none
 */
void USART3_IRQHandler(void);

 /**
 * \brief Received packet handler for debug channel
 *
 * \details none
 * 
 * \param uint8_t none
 * \return none
 */
void USART2_IRQHandler(void);
 /**
 * \brief Send 1 byte data via UART channel
 *
 * \details none
 * 
 * \param USART_TypeDef *Channel
 * \param uint8_t ch
 * \return none
 */
 void Uart_Send_Char(USART_TypeDef *Channel, uint8_t ch);

