/**
 * @file Sys_Timer.c
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init system timer
 */
 
 #include "Sys_Timer.h"
 
 uint32_t count = 0;
 
static uint32_t *sysTickCSR = (uint32_t *)SysTickControlStatusRegister;
static uint32_t *sysTickRVR = (uint32_t *)SysTickReloadValueRegister;
static uint32_t *sysTickCVR = (uint32_t *)SysTickCurrentValueRegister;
static uint32_t *sysTickCalibrationVR = (uint32_t *)SysTickCalibrationValueRegister;
 
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
	/* SysTick Enable */
	*sysTickCSR |= 1ul << 0;
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
	count++;
	if(count >= 1000) {
		Set_User_Led();
	}
	if(count >= 2000) {
		Reset_User_Led();
		count = 0;
	}
}
 