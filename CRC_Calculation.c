/**
 * @file CRC_Calculation.c
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief API for esp8266
 */
 
 #include "CRC_Calculation.h"

 /**
 * \brief init crc unit
 *
 * \details none
 * 
 * \param none
 * \param none
 * \return none
 */
 void Crc_Init(void) {
	 RCC->AHBENR |= 1ul << 12;
 }
	 
/**
 * \brief Calculate 32 bit CRC
 *
 * \details Computes the CRC-32/MPEG-2 checksum
 *					Uses a left shifting (not reflected) CRC along with the CRC polynomial 0x04C11DB7 
 *    			and initial CRC value of 0xFFFFFFFF, and is not post complemented.
 *    -Test Sample-
 *		uint8_t byte[8] = {1, 2, 3, 4, 5, 6, 7, 8};
 *		result = Crc_Calculate(8, &byte[0], 0xc2);
 *    http://www.sunshine2k.de/coding/javascript/crc/crc_js.html
 *    0x4 0x3 0x2 0x1 0x08 0x7 0x6 0x5
 *    Result CRC value: 0xA3141BDA
 * 
 * \param none
 * \param none
 * \return none
 */
 Checksum_Compare_Result_t Crc_Calculate(uint8_t length, uint8_t *Source, uint8_t Expected_Checksum) {
	 Checksum_Compare_Result_t returnValue = Checksum_Invalid;
	 uint8_t index = 0;
	 uint8_t indexByte = 0;
	 uint32_t result_CRC = 0;
	 uint8_t result_Checksum = 0;
	 /* Reset CRC */
	 CRC->CR = 0x01;
	 /* Calculate CRC */
	 for(index = 0 ; index < 3 ; index++) {
		 uint32_t tempData = 0;
		 /* Make 32bit data with 8 bit input */
		 for(indexByte = 0 ; indexByte < 4 ; indexByte++) {
			 tempData |= (Source[index*4 + indexByte] << ((3-indexByte) * 8));
		 }
		 /* Update CRC input for calculation */
		 CRC->DR = tempData;
	 }
	 /* get CRC value */
	 result_CRC = CRC->DR;
	 /* Calculate checksum value of the calculated 32-bit CRC */
	 for(index = 0 ; index < 4 ; index++) {
		 result_Checksum ^= ((result_CRC >> (index * 8)) & 0xFF);
	 }
	 /* Compare calculated and expected checksum */ 
	 if(result_Checksum == Expected_Checksum) {
		 returnValue = Checksum_Correct;
	 }
	 
	 return (returnValue);
 }
 
 