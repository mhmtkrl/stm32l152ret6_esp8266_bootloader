/**
 * @file My_Protocol_Api.h
 * @author Mehmet KORAL
 * @date 04 01 2023
 * @brief Function to handle uart communication
 */
 
 #include <stdint.h>
 #include "My_Protocol.h"
 
/**
 * \enum OPERATIONS_t
 *
 * \details list of operations
 * 
 * \param  none
 * \return none
 */
 typedef enum {
	 PERIPHERAL_CONTROL = 0x01,
	 DEVICE_INFORMATION,
	 FIRMWARE_UPDATE,
	 NOT_REQUSTED_YET
 }OPERATIONS_t;
 
/**
 * \enum MY_PROTOCOL_T
 *
 * \details protocol units
 * 
 * \param  none
 * \return none
 */
 typedef struct {
	 OPERATIONS_t Cmd;
	 uint8_t Length;
	 uint16_t Counter;
	 uint8_t Frame_Type;
	 uint8_t Data[8];
	 uint8_t Checksum;
 }MY_PROTOCOL_T;
 
 extern MY_PROTOCOL_T Protocol;
 
/**
 * \enum ERROR_CODES_t
 *
 * \details error values
 * 
 * \param  none
 * \return none
 */
 typedef enum {
	 NO_ERROR,
	 UNDEFINED_OPERATION,
	 UNDEFINED_PERIPHERAL,
	 INVALID_ACTION,
	 CONTROL_VALUE_NOT_IN_RANGE
 }ERROR_CODES_T;
 
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
ERROR_CODES_T Peripheral_Control(uint8_t Operation_Type, PERIPHERAL_UNITS_T Gpio_Mask, uint8_t Control_Value, uint8_t *Return_Value);

 