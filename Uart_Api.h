/**
 * @file Sys_Timer.h
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init system timer
 */

#include "stdint.h"

 /**
 * \brief Send debug packet via UART channel
 *
 * \details none
 * 
 * \param uint8_t length
 * \param uint8_t *cmd
 * \return none
 */
 void Uart_Send_Debug_Message(uint8_t length, uint8_t *cmd);
	 
 /**
 * \brief Send command via UART channel
 *
 * \details none
 * 
 * \param uint8_t length
 * \param uint8_t *cmd
 * \return none
 */
 void Uart_Send_Command(uint8_t length, uint8_t *cmd);
	 
/**
 * \brief Init Uart peripherals for debugging and esp8266
 *
 * \details baudrate: 115200
 * 
 * \param none
 * \param none
 * \return none
 */
void Init_Uart_For_Communication(void);
