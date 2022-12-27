/**
 * @file Esp8266_Config.h
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Function to configure ESP8266
 */
 
#include "stm32l1xx.h"                  // Device header
#include "stdint.h"
#include "ESP8266_Enums.h"

 /**
 * \struct ESP8266_Config_t
 *
 * \details Config for ESP8266
 * 
 * \param  none
 * \return none
 */
typedef struct {
	uint16_t TIMEOUT;
	uint8_t ECHO_MODE;
}ESP8266_Config_t;

 /**
 * \struct ESP8266_Command_t
 *
 * \details Commands for ESP8266
 * 
 * \param  none
 * \return none
 */
typedef struct {
	const char *Command;
	uint8_t Length;
	const char *Response;
}ESP8266_Command_t;

extern  ESP8266_Command_t ESP8266_Command[AT_COMMANDS_MAX];
