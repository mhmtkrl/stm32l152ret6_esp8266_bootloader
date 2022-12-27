/**
 * @file Sys_Timer.h
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init system timer
 */
 
#include "stm32l1xx.h"                  // Device header
#include "stdint.h"

/* API include */
#include "Esp8266_Api.h"

/* SysTick Registers Table 4-1 System Control Registers Cortex M3 Technical Reference Manual */
#define SysTickControlStatusRegister		0xE000E010
#define SysTickReloadValueRegister			0xE000E014

 /**
 * \brief Disable systick 
 *
 * \details This function disables the systick timer
 * 
 * \param none 
 * \return none
 */
void Disable_Timeout_Counter(void);

 /**
 * \brief 1ms timer
 *
 * \details This function is called every 1ms
 * 
 * \param none 
 * \param none
 * \return none
 */
void SysTick_Handler(void);
