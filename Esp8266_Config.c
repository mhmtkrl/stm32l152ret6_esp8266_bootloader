/**
 * @file Esp8266_Config.c
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Function to configure ESP8266
 */
 
 #include "Esp8266_Config.h"
 
  /**
 * \struct ESP8266_Config_t
 *
 * \details Config for ESP8266
 * 
 * \param  none
 * \return none
 */
 ESP8266_Config_t ESP8266_Config = {
	 500U,
	 ECHO_OFF,
	 {
		 6U,
		 "\r\nOK\r\n",
		 9U,
		 "\r\nERROR\r\n"
	 }
 };

  /**
 * \struct ESP8266_Command_t
 *
 * \details Commands for ESP8266
 * 
 * \param  none
 * \return none
 */
 ESP8266_Command_t ESP8266_Command[AT_COMMANDS_MAX] = {
	 {
		 "ATr\r\n",
		 5U,
		 "OK"
	 },
	 {
		 "AT+RST\r\n",
		 4U,
		 "OK"
	 },
	 {
		 "AT+GMR\r\n",
		 8U,
		 "OK"
	 },
	 {
		 "ATE0\r\n",
		 6U,
		 "OK"
	 }
 };
 
 
 