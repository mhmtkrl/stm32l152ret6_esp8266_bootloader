/**
 * @file Gpio.c
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init gpio
 */
 
 #include "Gpio.h"

/**
 * \brief Init user LED (PA5)
 *
 * \details This function configures the clock line and IO state of related pin
 * 
 * \param none
 * \param none
 * \return none
 */
 void Init_User_Led() {
	/* AHB is enabled for GPIOA */
	RCC->AHBENR |= 1ul << 0;
	/* PA5 is output */
	GPIOA->MODER |= 1ul << 10;
	GPIOA->MODER &= ~(1ul << 11);
}

/**
 * \brief Set user LED (PA5)
 *
 * \details This function set user led
 * 
 * \param none
 * \param none
 * \return none
 */
void Set_User_Led() {
	//PA5 Lojik-0 -> off
	GPIOA->BSRR |= 1ul << 21;
	//PA5 Lojik-1 -> on
	GPIOA->BSRR |= 1ul << 5;
}

/**
 * \brief Reset user LED (PA5)
 *
 * \details This function reset user led
 * 
 * \param none
 * \param none
 * \return none
 */
void Reset_User_Led() {
	//PA5 Lojik-0 -> off
	GPIOA->BSRR |= 1ul << 5;
	//PA5 Lojik-1 -> on
	GPIOA->BSRR |= 1ul << 21;
}
