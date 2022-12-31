/**
 * @file Esp8266_Enums.h
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief File to create enums
 */
 
 #include "stdint.h"
 
 /**
 * \enum ESP8266_Config_t
 *
 * \details Config for ESP8266
 * 
 * \param  none
 * \return none
 */
 typedef enum {
	 ECHO_OFF,
	 ECHO_ON
 }ECHO_MODE_t;
 
  /**
 * \enum ESP8266_AT_COMMANDS_t
 *
 * \details Config for ESP8266
 * 
 * \param  none
 * \return none
 */
 typedef enum {
	 Test_Module,
	 Restart_The_Module,
	 Check_Version_Information,
	 AT_Commands_Echoing,
	 Closes_UDP_Connection,
	 Establishes_UDP_Transmission,
	 Sends_Data_UDP_Transmission,
	 AT_COMMANDS_MAX
 }ESP8266_AT_COMMANDS_t;
 
 