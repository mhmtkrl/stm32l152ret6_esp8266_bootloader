/**
 * @file Sys_Timer_Api.h
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init system timer
 */
 
#include "stdint.h"

 /**
 * \brief Get current timer value in miliseconds
 *
 * \details This function returns the current timer value systick
 * 
 * \param none 
 * \param none
 * \return uint32_t counter
 */
uint32_t Elapsed_Time_In_Miliseconds(void);

 /**
 * \brief set systick timer
 *
 * \details This function enables the systick timer
 * 
 * \param none 
 * \return none
 */
void Enable_Timeout_Counter(void);
	
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
