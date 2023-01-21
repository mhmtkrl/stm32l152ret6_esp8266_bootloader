/**
 * @file Flash_Unit_Api.h
 * @author Mehmet KORAL
 * @date 09 01 2023
 * @brief Header file to manage flash operation
 */
 
 #include <stdint.h>
 
 /**
 * \enum Data Eeprom config
 *
 * \details no info
 * 
 * \param  none
 * \return none
 */
 typedef struct {
	uint32_t Start_Address; 
 }EEPROM_DATA_t;
 extern EEPROM_DATA_t Eeprom_Data;
 
/**
 * \enum Program memory config
 *
 * \details no info
 * 
 * \param  none
 * \return none
 */
 typedef struct {
	uint32_t Start_Address; 
 }PROGRAM_MEMORY_t;
 extern PROGRAM_MEMORY_t Program_Memory;
 
 /**
 * \brief Flash init function
 *
 * \details no more info
 * 
 * \param none
 * \return none
 */
void FLASH_Init(void);

 /**
 * \brief Program memory page erase
 *
 * \details This operation is used to erase a page in program memory (64 words)
 * 
 * \param none
 * \return none
 */
void FLASH_Program_Memory_Page_Erase(uint32_t Start_Address);

 /**
 * \brief Flash Fast Word Write
 *
 * \details This operation is used to write a word to the program memory,
 * 
 * \param none
 * \return none
 */
void FLASH_Program_Memory_Write(uint32_t Start_Address, uint16_t Length, uint16_t *Data);


 /**
 * \brief Data EEPROM Word Write
 *
 * \details This operation is used to write a word to the data EEPROM whatever the previous value of the word to be written to
 * 
 * \param none
 * \return none
 */
void FLASH_Eeprom_Write(uint32_t Start_Address, uint16_t Length, uint16_t *Data);

 /**
 * \brief Program memory read
 *
 * \details This operation is used to read from program memory,
 * 
 * \param none
 * \return none
 */
void FLASH_Memory_Read(uint32_t Start_Address, uint16_t Length, uint32_t *Destination);

