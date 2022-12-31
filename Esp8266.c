/**
 * @file Esp8266.c
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Manage ESP8266 related tasks
 */
 
 #include "Esp8266.h"

 static void ESP8266_DeleteUDP_transmission(void);
 static void ESP8266_CreateUDP_transmission(void);
 static void ESP8266_Sends_Data_UDP_Transmission(void);
 
 ESP8266_Response_End_t *Response = &ESP8266_Config.Response;
 
 typedef struct {
	 uint8_t bufferSize;
	 uint8_t head;
	 uint8_t tail;
	 uint8_t length;
	 char data[5][128];
 }Circular_Buffer_t;
 
 Circular_Buffer_t Circular_Buffer = {5, 0, 0, 0, 0U};
 
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
 * \brief Close current UDP socket
 *
 * \details none
 * 
 * \param none
 * \return none
 */
 static void ESP8266_DeleteUDP_transmission(void) {
	/* internal command variable */
	 ESP8266_Command_t *Cmd = &ESP8266_Command[Closes_UDP_Connection];
	 /* send command */
	 Uart_Send_Command(Cmd->Length, Cmd->Command);
 }	 
 
/**
 * \brief Estaplish UDP connection
 *
 * \details none
 * 
 * \param none
 * \return none
 */
 static void ESP8266_CreateUDP_transmission(void) {
	/* internal command variable */
	 ESP8266_Command_t *Cmd = &ESP8266_Command[Establishes_UDP_Transmission];
	 ESP8266_Command_t Temp;

	 Temp.Length = sprintf(Temp.Command , "%s,\"IP\",%d,%d\r\n", Cmd->Command, 456, 457);
	 
	 /* send command */
	 Uart_Send_Command(Temp.Length, Temp.Command);
}	
 
 /**
 * \brief Send UDP Packet
 *
 * \details none
 * 
 * \param none
 * \return none
 */
 static void ESP8266_Sends_Data_UDP_Transmission(void) {
	/* internal command variable */
	 ESP8266_Command_t *Cmd = &ESP8266_Command[Sends_Data_UDP_Transmission];
	 ESP8266_Command_t Command, Message;
	 uint8_t len = 8;

	 Message.Length = sprintf(Message.Command , "Hello STM32 Wireless Communication\r\n");
	 Command.Length = sprintf(Command.Command , "%s=%d\r\n", Cmd->Command, Message.Length);
	 
	 /* send command */
	 Uart_Send_Command(Command.Length, Command.Command);
	 
	 
	 for(volatile int i = 0; i < 20970 ; i++) ;
	 
	 
	 
	 /* send command */
	 Uart_Send_Command(Message.Length, Message.Command);
 }	
 
void UDP(void) {
	//ESP8266_DeleteUDP_transmission();
	//ESP8266_CreateUDP_transmission();
	ESP8266_Sends_Data_UDP_Transmission();
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
	 /* Printf received responses */
	 while(Circular_Buffer.head != Circular_Buffer.tail) {
		Uart_Send_Debug_Message(Circular_Buffer.length, &Circular_Buffer.data[Circular_Buffer.head-1][0]);
		if(Circular_Buffer.data[Circular_Buffer.head-1][2] == '+' && Circular_Buffer.data[Circular_Buffer.head-1][3] == 'I') {
			if(Circular_Buffer.data[Circular_Buffer.head-1][9] == '1') {
				Uart_Send_Debug_Message(7, "LED ON!");
				Set_User_Led();
			}
			else if(Circular_Buffer.data[Circular_Buffer.head-1][9] == '0') {
				Uart_Send_Debug_Message(8, "LED OFF!");
				Reset_User_Led();
			}
			else {
				Uart_Send_Debug_Message(17, "UNDEFINED PACKET!");
			}
			
		}
		Circular_Buffer.tail++;
		 if(Circular_Buffer.tail >= Circular_Buffer.bufferSize) {
			 Circular_Buffer.tail = 0;
		 }
		 if(Circular_Buffer.head >= Circular_Buffer.bufferSize) {
			 Circular_Buffer.head = 0;
		 }
	 }

	 

 }
 