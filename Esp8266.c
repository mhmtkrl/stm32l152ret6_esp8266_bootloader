/**
 * @file Esp8266.c
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Manage ESP8266 related tasks
 */
 
 #include "Esp8266.h"

 static void ESP8266_DeleteUDP_transmission(void);
 static void ESP8266_CreateUDP_transmission(void);
 
 char *Response;
 

 
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
	 ESP8266_Config_t *Config = &ESP8266_Config;
	 ESP8266_Command_t *Cmd = &ESP8266_Command[Establishes_UDP_Transmission];
	 ESP8266_Command_t Temp;

	 Temp.Length = sprintf(Temp.Command , "%s,\"%s\",%d,%d\r\n", Cmd->Command, Config->Destination_IP, Config->Destination_Port, Config->Local_Port);
	 
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
 void ESP8266_Sends_Data_UDP_Transmission(ESP8266_Command_t Message) {
	/* internal command variable */
	 ESP8266_Command_t *Cmd = &ESP8266_Command[Sends_Data_UDP_Transmission];
	 ESP8266_Command_t Command;
	 
	 Command.Length = sprintf(Command.Command , "%s=%d\r\n", Cmd->Command, Message.Length);
	 
	 /* send command */
	 Uart_Send_Command(Command.Length, Command.Command);
	 
	 for(volatile int i = 0; i < 20970 ; i++) ;
	 
	 /* send command */
	 Uart_Send_Command(Message.Length, Message.Command);
 }	
 
void UDP(void) {
	volatile int i = 0;
	ESP8266_DeleteUDP_transmission();
	for(i = 0 ; i < 209700 ; i++) {
		
	}
	ESP8266_CreateUDP_transmission();
	for(i = 0 ; i < 209700 ; i++) {
		
	}
	
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
	 /* Process circular buffer */
	 while(Circular_Buffer.head != Circular_Buffer.tail) {
		Uart_Send_Debug_Message(Circular_Buffer.length, &Circular_Buffer.data[Circular_Buffer.head-1][0]);
		if(Circular_Buffer.data[Circular_Buffer.head-1][2] == '+' && Circular_Buffer.data[Circular_Buffer.head-1][3] == 'I') {
			MY_PROTOCOL_T	*Request = &Protocol;
			/* \todo: Use struct feature */
			Request->Cmd = Circular_Buffer.data[Circular_Buffer.head-1][10];
			Request->Length = Circular_Buffer.data[Circular_Buffer.head-1][11];
			Request->Counter = (Circular_Buffer.data[Circular_Buffer.head-1][12] << 8) | Circular_Buffer.data[Circular_Buffer.head-1][13];
			Request->Frame_Type = Circular_Buffer.data[Circular_Buffer.head-1][14];
			Request->Data[0] = Circular_Buffer.data[Circular_Buffer.head-1][15];
			Request->Data[1] = Circular_Buffer.data[Circular_Buffer.head-1][16];
			Request->Data[2] = Circular_Buffer.data[Circular_Buffer.head-1][17];
			Request->Data[3] = Circular_Buffer.data[Circular_Buffer.head-1][18];
			Request->Checksum = Circular_Buffer.data[Circular_Buffer.head-1][23];
		
			if(PERIPHERAL_CONTROL == Request->Cmd) {
				Peripheral_Control(Request->Data[0], Request->Data[1], Request->Data[2], 0U);
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
 