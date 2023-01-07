/**
 * @file My_Protocol.c
 * @author Mehmet KORAL
 * @date 04 01 2023
 * @brief Function to handle uart communication
 */
 
 #include "My_Protocol_Api.h"
 
MY_PROTOCOL_T Protocol = {
	NOT_REQUSTED_YET,
	0U,
	0U,
	0U,
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	0U
};
	
 /**
 * \brief Peripheral control
 *
 * \details none
 * 
 * \param uint8_t Operation_Type => 0: Read, 1: Write
 * \param uint8_t Gpio_Mask => 0: User LED, 1: User Button, 2: Temperature Sensor, etc.
 * \param uint8_t Control_Value => Digital High/Low or PWM
 * \param uint16_t *Return_Value => LED Status, Button Status, Temperature Value, etc.
 * \return none
 */
ERROR_CODES_T Peripheral_Control(uint8_t Operation_Type, PERIPHERAL_UNITS_T Gpio_Mask, uint8_t Control_Value, uint8_t *Return_Value) {
	ERROR_CODES_T Error_Code = NO_ERROR;
	
	if(READ_OPERATION == Operation_Type) {
		if(USER_LED == Gpio_Mask) {
			/* Return LED status */
		}
		else if(USER_BUTTON == Gpio_Mask) {
			/* Return Button status */
		}
		else if(TEMPERATURE_SENSOR == Gpio_Mask) {
			/* Return Temperature Value */
		}
		else {
			Error_Code = UNDEFINED_PERIPHERAL;
		}
	}
	else if(WRITE_OPERATION == Operation_Type) {
		/* Write */
		if(USER_LED == Gpio_Mask) {
			if(0x00 == Control_Value) {
				/* \todo: Use function pointer */
				Reset_User_Led();
			}
			else if(0x01 == Control_Value) {
				/* \todo: Use function pointer */
				Set_User_Led();
			}
			else {
				Error_Code = CONTROL_VALUE_NOT_IN_RANGE;
			}
		}
		else if(USER_BUTTON == Gpio_Mask) {
			/* That is not controllable */
			Error_Code = INVALID_ACTION;
		}
		else if(TEMPERATURE_SENSOR == Gpio_Mask) {
			/* That is not controllable */
			Error_Code = INVALID_ACTION;
		}
		else {
			Error_Code = UNDEFINED_PERIPHERAL;
		}
	}
	else {
		Error_Code = UNDEFINED_OPERATION;
	}
	
	return (Error_Code);
}
