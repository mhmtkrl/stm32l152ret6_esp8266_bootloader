/**
 * @file Gpio.h
 * @author Mehmet KORAL
 * @date 26 Dec 2022
 * @brief Function to init gpio
 */
 
#include "stm32l1xx.h"                  // Device header
#include "stdint.h"
 
void Drive_Step_Motor(void);

/**
 * \brief Init step motor pins
 *
 * \details This function configures the clock line and IO state of related pin
 * 
 * \param none
 * \param none
 * \return none
 */
 void Init_Step_Motor_Pins(void);
 
 /**
 * \brief Init user LED (PA5)
 *
 * \details This function configures the clock line and IO state of related pin
 * 
 * \param none
 * \param none
 * \return none
 */
 void Init_User_Led(void);
 
 /**
 * \brief Set user LED (PA5)
 *
 * \details This function set user led
 * 
 * \param none
 * \param none
 * \return none
 */
void Set_User_Led(void);

/**
 * \brief Reset user LED (PA5)
 *
 * \details This function reset user led
 * 
 * \param none
 * \param none
 * \return none
 */
void Reset_User_Led(void);
