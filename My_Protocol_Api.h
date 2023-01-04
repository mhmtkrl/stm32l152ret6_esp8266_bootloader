/**
 * @file My_Protocol_Api.h
 * @author Mehmet KORAL
 * @date 04 01 2023
 * @brief Function to handle uart communication
 */
 
 #include <stdint.h>
 
   /**
 * \enum MY_PROTOCOL_T
 *
 * \details protocol units
 * 
 * \param  none
 * \return none
 */
 typedef struct {
	 uint8_t Cmd;
	 uint8_t Length;
	 uint16_t Counter;
	 uint8_t Frame_Type;
	 uint8_t Data[8];
	 uint8_t Checksum;
 }MY_PROTOCOL_T;
 