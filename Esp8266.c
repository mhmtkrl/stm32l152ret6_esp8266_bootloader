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
 uint8_t count = 0;
 ESP8266_Response_End_t *Response = &ESP8266_Config.Response;
 
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
	 //Uart_Send_Debug_Message(Length, &Response[0]);
	 buffer =&Response[0];
	 len = Length;
	 otp = 1;
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
	 uint8_t Positive_Counter1=0;
	 uint8_t Negative_Counter1=0;

	 
	 if(otp == 1 && len >= 9) {
		 for(uint8_t index = 0 ; index < 6 ; index++) {
					if(buffer[(len - 6) + index] == Response->Positive[index]) {
						Positive_Counter1++;
						if(Positive_Counter1 >= 6) {
							Uart_Send_Debug_Message(len, &buffer[0]);
							ESP8266_Response_Length = 0;
							len = 0;
						}
					}
				}
		 Positive_Counter1 = 0;
		 for(uint8_t index = 0 ; index < 9 ; index++) {
					if(buffer[(len - 9) + index] == Response->Negative[index]) {
						Negative_Counter1++;
						if(Negative_Counter1 >= 9) {
							Uart_Send_Debug_Message(len, &buffer[0]);
							ESP8266_Response_Length = 0;
							len = 0;
						}
					}
				}
		 Negative_Counter1 = 0;
		
		otp = 0;
	 }

 }
 