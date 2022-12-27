/**
 * @file Esp8266_Api.h
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief API for esp8266
 */
 
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
 
 