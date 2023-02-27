/**
 * @file CRC_Calculation_Api.h
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief API for esp8266
 */
 
 #include <stdint.h>
 
 /**
 * \brief init crc unit
 *
 * \details none
 * 
 * \param none
 * \param none
 * \return none
 */
 typedef enum {
	Checksum_Correct,
	Checksum_Invalid
 }Checksum_Compare_Result_t;
 
/**
 * \brief init crc unit
 *
 * \details none
 * 
 * \param none
 * \param none
 * \return none
 */
 void Crc_Init(void);
	 
/**
 * \brief Calculate 32 bit CRC
 *
 * \details Computes the CRC-32/MPEG-2 checksum
 *					Uses a left shifting (not reflected) CRC along with the CRC polynomial 0x04C11DB7 
 *    			and initial CRC value of 0xFFFFFFFF, and is not post complemented.
 * 
 * \param none
 * \param none
 * \return none
 */
 Checksum_Compare_Result_t Crc_Calculate(uint8_t length, uint8_t *Source, uint8_t Expected_Checksum);
 
	 