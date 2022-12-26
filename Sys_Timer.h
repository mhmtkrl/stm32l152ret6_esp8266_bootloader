/**
 * @file Sys_Timer.h
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init system timer
 */
 
#include "stm32l1xx.h"                  // Device header
#include "stdint.h"

/* API include */
#include "Gpio.h"

/* SysTick Registers Table 4-1 System Control Registers Cortex M3 Technical Reference Manual */
#define SysTickControlStatusRegister		0xE000E010
#define SysTickReloadValueRegister			0xE000E014
#define SysTickCurrentValueRegister			0xE000E018
#define SysTickCalibrationValueRegister	0xE000E01C

 /**
 * \brief Init system timer in miliseconds
 *
 * \details This function set the system timer to 1ms
 * 
 * \param none 
 * \param none
 * \return none
 */
void Init_System_Timer(uint32_t Clock_Frequency);

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
