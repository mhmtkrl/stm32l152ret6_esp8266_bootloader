/**
 * @file Esp8266.c
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Manage ESP8266 related tasks
 */
 
 #include "Esp8266.h"

 ESP8266_Response_End_t *Response = &ESP8266_Config.Response;
 
 typedef struct {
	 uint8_t bufferSize;
	 uint8_t head;
	 uint8_t tail;
	 uint8_t length;
	 char data[10][128];
 }Circular_Buffer_t;
 
 Circular_Buffer_t Circular_Buffer = {10, 0, 0, 0, 0U};
 
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

	 Circular_Buffer.length = Length;
	 for(int i = 0 ; i < Length ; i++) {
		Circular_Buffer.data[Circular_Buffer.head][i] = Response[i];
	 }
	 
	 
	 Circular_Buffer.head++;
	 
	 if(Circular_Buffer.head >= Circular_Buffer.bufferSize) {
		 Circular_Buffer.head = 0;
	 }
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
	 while(Circular_Buffer.head != Circular_Buffer.tail) {
		Uart_Send_Debug_Message(Circular_Buffer.length, &Circular_Buffer.data[Circular_Buffer.head-1][0]);
		Circular_Buffer.tail++;
		 if(Circular_Buffer.tail >= Circular_Buffer.bufferSize) {
			 Circular_Buffer.tail = 0;
		 }
	 }

	 

 }
 