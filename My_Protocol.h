/**
 * @file My_Protocol.h
 * @author Mehmet KORAL
 * @date 04 01 2023
 * @brief Function to handle uart communication
 */
 
 #include <stdint.h>
 #include "Gpio.h"
 
 /**
 * \enum MY_PROTOCOL_T
 *
 * \details protocol units
 * 
 * \param  none
 * \return none
 */
typedef enum {
	READ_OPERATION,
	WRITE_OPERATION,
	OPERATION_MAX 
}OPERATION_TYPE_t;

 /**
 * \enum PERIPHERAL_UNITS_T
 *
 * \details Peripheral units
 * 
 * \param  none
 * \return none
 */
typedef enum {
	USER_LED,
	USER_BUTTON,
	TEMPERATURE_SENSOR,
	PERIPHERAL_UNIT_MAX,
}PERIPHERAL_UNITS_T;



