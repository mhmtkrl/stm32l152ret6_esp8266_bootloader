/**
 * @file Esp8266.c
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Manage ESP8266 related tasks
 */
 
 #include "Esp8266.h"
 
 /**
 * \brief Test ESP8266 
 *
 * \details sent AT command
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Test(void) {
	 /* internal command variable */
	 ESP8266_Command_t *Cmd = &ESP8266_Command[Test_Module];
	 /* send command */
	 Uart_Send_Command(Cmd->Length, Cmd->Command);
 }
 
 /**
 * \brief Checks Version Information
 *
 * \details AT+GMR
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Version(void) {
	 /* internal command variable */
	 ESP8266_Command_t *Cmd = &ESP8266_Command[Check_Version_Information];
	 /* send command */
	 Uart_Send_Command(Cmd->Length, Cmd->Command);
 }
 
 /**
 * \brief Process response data
 *
 * \details none
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Process_Response(char *Response, uint8_t Length, uint16_t Time_Diff) {
	 Uart_Send_Debug_Message(Length, &Response[0]);
 }
 
/**
 * \brief Manage ESP8266
 *
 * \details main function
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Main(void) {

 }
 