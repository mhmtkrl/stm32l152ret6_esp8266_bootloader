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
 
Checksum_Compare_Result_t Crc_Res = Checksum_Invalid;
 
uint8_t otp = 0;
 
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
	for(i = 0 ; i < 209701 ; i++) {
		
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
 void ESP8266_Process_Response(uint8_t type, char *Response, uint8_t Length, uint16_t Time_Diff) {
	 Circular_Buffer.length = Length;
	 for(int i = 0 ; i < Length ; i++) {
		Circular_Buffer.data[Circular_Buffer.head][i] = Response[i];
	 }
	 if(type == 1)
	 Circular_Buffer.head++;
	 else {
		 otp = 1;
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
	 /* Process circular buffer */
	 if(Circular_Buffer.head != Circular_Buffer.tail) {
		Uart_Send_Debug_Message(Circular_Buffer.length, &Circular_Buffer.data[Circular_Buffer.tail][0]);

			uint8_t indis = Circular_Buffer.tail;
			MY_PROTOCOL_T	*Request = &Protocol;
			/* \todo: Use struct feature */
		  uint8_t Struct_Indis = 0;
		 uint8_t dummy[12];
		  for(Struct_Indis = 0 ; Struct_Indis < 13 ; Struct_Indis++) {
				((uint8_t *)(&Request[0]))[Struct_Indis] = Circular_Buffer.data[indis][10 + Struct_Indis];
				
				if(Struct_Indis != 12) {
					dummy[Struct_Indis] = Circular_Buffer.data[indis][10 + Struct_Indis];
				}
			}
			
			Crc_Res = Crc_Calculate(12, &dummy[0], Request->Checksum);
			if(Checksum_Correct == Crc_Res) {
				if(PERIPHERAL_CONTROL == Request->Cmd) {
					/* \todo: Inputs depend only Request->Data optimize function arguments */
					 ERROR_CODES_T code = Peripheral_Control(Request->Data[0], Request->Data[1], Request->Data[2], &Request->Data[3]);
					if(NO_ERROR == code) {
						ESP8266_Command_t Message;
						Message.Length = sprintf(Message.Command, "Value = %d\r\n", Request->Data[3]);
						ESP8266_Sends_Data_UDP_Transmission(Message);
					}
				}
				if(DEVICE_INFORMATION == Request->Cmd) {
					 char Info[13];
					 ERROR_CODES_T code = Device_Information_Function(&Info[0]);
					if(NO_ERROR == code) {
						ESP8266_Command_t Message;
						Message.Length = sprintf(Message.Command, "%s\r\n", Info);
						ESP8266_Sends_Data_UDP_Transmission(Message);
					}
				}
				if(FIRMWARE_UPDATE == Request->Cmd) {
					uint32_t ReadData[2];
					ERROR_CODES_T code = Firmware_Update_Function(Request->Frame_Type, Request->Length, &Request->Data[0], &ReadData[0]);
					if(NO_ERROR == code) {
						ESP8266_Command_t Message;
						Message.Length = sprintf(Message.Command, "Firmware Update response okay\r\n");
						ESP8266_Sends_Data_UDP_Transmission(Message);
					}					
				}
			}else {
				ESP8266_Command_t Message;
				Message.Length = sprintf(Message.Command, "Invalid Checksum!\r\n");
				ESP8266_Sends_Data_UDP_Transmission(Message);
			}
			Circular_Buffer.tail++;
		 if(Circular_Buffer.tail >= Circular_Buffer.bufferSize) {
			 Circular_Buffer.tail = 0;
		 }
		 if(Circular_Buffer.head >= Circular_Buffer.bufferSize) {
			 Circular_Buffer.head = 0;
		 }
	 }
	 
	 if(otp) {
		 Uart_Send_Debug_Message(Circular_Buffer.length, &Circular_Buffer.data[Circular_Buffer.head][0]);
		 otp = 0;
	 }
 }
 