/**
 * @file Esp8266_Api.h
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief API for esp8266
 */
 
 #include "stdint.h"
 #include "Esp8266_Config.h"

 void UDP(void);
 
  /**
 * \brief Test ESP8266 
 *
 * \details sent AT command
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Test(void);

/**
 * \brief Checks Version Information
 *
 * \details AT+GMR
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Version(void);
 
 /**
 * \brief Process response data
 *
 * \details none
 * 
 * \param none
 * \param none
 * \return none
 */
 
   /**
 * \brief Checks Version Information
 *
 * \details AT+GMR
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Echo_Off(void);
	 
 void ESP8266_Process_Response(uint8_t type, char *Response, uint8_t Length, uint16_t Time_Diff);
	
 /**
 * \brief Send UDP Packet
 *
 * \details none
 * 
 * \param none
 * \return none
 */
 void ESP8266_Sends_Data_UDP_Transmission(ESP8266_Command_t Message);
 
 /**
 * \brief Manage ESP8266
 *
 * \details main function
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Main(void);
 
 
 