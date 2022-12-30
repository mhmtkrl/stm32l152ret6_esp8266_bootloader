/**
 * @file Esp8266.c
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Manage ESP8266 related tasks
 */
 
 #include "Esp8266.h"
 
 char *buffer;
 uint8_t len = 0;
 uint8_t otp = 0;
 int8_t count = 0;
 ESP8266_Response_End_t *Response = &ESP8266_Config.Response;
 
 char data[10][128];
 
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
 * \brief Checks Version Information
 *
 * \details AT+GMR
 * 
 * \param none
 * \param none
 * \return none
 */
 void ESP8266_Echo_Off(void) {
	 /* internal command variable */
	 ESP8266_Command_t *Cmd = &ESP8266_Command[AT_Commands_Echoing];
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
	 //Uart_Send_Debug_Message(Length, &Response[0]);
	// buffer =&Response[0];
	 len = Length;
	 otp = 1;
	 for(int i = 0 ; i < Length ; i++) {
		data[count][i] = Response[i];
	 }
	 
	 count++;
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
	 while(count!=0) {
		Uart_Send_Debug_Message(len, &data[count-1][0]);
		count--;
	 }


 }
 