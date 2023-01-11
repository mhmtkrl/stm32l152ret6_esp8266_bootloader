/**
 * @file My_Protocol.c
 * @author Mehmet KORAL
 * @date 04 01 2023
 * @brief Function to handle uart communication
 */
 
#include "My_Protocol_Api.h"
#include "Flash_Unit_Api.h"
 
MY_PROTOCOL_T Protocol = {
	NOT_REQUSTED_YET,
	0U,
	0U,
	0U,
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	0U
};

/**
 * \brief Device Information
 *
 * \details STM32L152REt6
 * 
 * \param none
 * \return none
 */
ERROR_CODES_T Firmware_Update_Function(FLASH_OPERATION_t Operation, uint8_t Length, uint8_t *Data) {
	ERROR_CODES_T Error_Code = NO_ERROR;
	uint16_t Byte[4];
	uint16_t Len = 4;
	
	switch(Operation) {
		case ERASE:
			Error_Code = NO_ERROR;
		break;
		case WRITE:
			for(uint8_t i = 0 ; i < Len ; i++) {
				Byte[i] = (Data[i*2] << 8) | Data[i*2+1];
			}
			FLASH_Eeprom_Write(Eeprom_Data.Start_Address, Len, &Byte[0]);
			Error_Code = NO_ERROR;
		break;
		default:
			Error_Code = NO_ERROR;
	}
	return (Error_Code);
}

/**
 * \brief Device Information
 *
 * \details STM32L152REt6
 * 
 * \param none
 * \return none
 */
ERROR_CODES_T Device_Information_Function(char *info) {
	ERROR_CODES_T Error_Code = NO_ERROR;
	info[0] = 'S';
	info[1] = 'T';
	info[2] = 'M';
	info[3] = '3';
	info[4] = '2';
	info[5] = 'L';
	info[6] = '1';
	info[7] = '5';
	info[8] = '2';
	info[9] = 'R';
	info[10] = 'E';
	info[11] = 'T';
	info[12] = '6';
	return (Error_Code);
}
	
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
		if(Gpio_Mask == USER_LED) {
			/* Return LED status */
			*Return_Value = (GPIOA->IDR & (1ul << 5)) >> 5;
		}
		else if(Gpio_Mask == USER_BUTTON) {
			/* Return Button status */
			*Return_Value = 1;
		}
		else if(Gpio_Mask == TEMPERATURE_SENSOR) {
			/* Return Temperature Value */
			*Return_Value = 64;
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
