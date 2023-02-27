/**
 * @file Sys_Timer.c
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init system timer
 */
 
 #include "Sys_Timer.h"
 #include "Sys_Timer_Api.h"
 
/* Internal pointers to acces system registers */
static uint32_t *sysTickCSR = (uint32_t *)SysTickControlStatusRegister;
static uint32_t *sysTickRVR = (uint32_t *)SysTickReloadValueRegister;

/* Internal variables */
uint32_t Internal_Counter = 0;

 /**
 * \brief Get current timer value in miliseconds
 *
 * \details This function returns the current timer value systick
 * 
 * \param none 
 * \param none
 * \return uint32_t counter
 */
uint32_t Elapsed_Time_In_Miliseconds(void) {
	uint32_t Current_Value = 0;
	/* Get counter */
	Current_Value = Internal_Counter;
	/* Disable systick timer */
	Disable_Timeout_Counter();
	/* Clear internal counter */
	Internal_Counter = 0;
	
	return (Current_Value);
}

 /**
 * \brief set systick timer
 *
 * \details This function enables the systick timer
 * 
 * \param none 
 * \return none
 */
void Enable_Timeout_Counter(void) {
	/* SysTick Enable */
	*sysTickCSR |= 1ul << 0;
}

 /**
 * \brief Disable systick 
 *
 * \details This function disables the systick timer
 * 
 * \param none 
 * \return none
 */
void Disable_Timeout_Counter(void) {
	/* SysTick Enable */
	*sysTickCSR &= ~(1ul << 0);
}
	
 /**
 * \brief Init system timer in miliseconds
 *
 * \details This function set the system timer to 1ms
 * 
 * \param none 
 * \param none
 * \return none
 */
 void Init_System_Timer(uint32_t Clock_Frequency) {
	/* Clock source is Core Clock */
	*sysTickCSR |= 1ul << 2;
	/* SysTick Handler is enabled */
	*sysTickCSR |= 1ul << 1;
	/* Calculate RELOAD Value */
	*sysTickRVR = (Clock_Frequency / 1000) - 1;
	 /* Enable Timer */
	 Enable_Timeout_Counter();
}

 /**
 * \brief 1ms timer
 *
 * \details This function is called every 1ms
 * 
 * \param none 
 * \param none
 * \return none
 */
void SysTick_Handler(void) {
	/* @todo do something */
	Internal_Counter++;
	/* ESP8266 Main function */
	if(Internal_Counter > 10) {
		ESP8266_Main();
		Internal_Counter = 0;
	}
}

