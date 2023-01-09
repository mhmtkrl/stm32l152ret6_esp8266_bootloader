/**
 * @file Flash_Unit.c
 * @author Mehmet KORAL
 * @date 09 01 2023
 * @brief Source file to manage flash operation
 */
 
 #include "Flash_Unit.h"
 #include "Flash_Unit_Api.h"

static void FLASH_Eeprom_Write(uint32_t Start_Address, uint16_t Length, uint16_t *Data);
static void FLASH_Program_Memory_Write(uint32_t Start_Address, uint16_t Length, uint16_t *Data);
static FLASH_LOCK_STATUS_t Flash_Unlock_Operation(void);

uint16_t myData[4] = {0xFEDC, 0xBA98, 0x7654, 0x3210};
 
 PROGRAM_MEMORY_t Program_Memory = {
	 /* Sector 30  */
	 0x0801E0F0
 };
 
 EEPROM_DATA_t Eeprom_Data = {
	 /* Data EEPROM bank 1 */
	 0x08080014
 };
 
 /**
 * \brief Flash init function
 *
 * \details no more info
 * 
 * \param none
 * \return none
 */
void FLASH_Init(void) {
	/* Enable clock source of the memory */
	FLASH_LOCK_STATUS_t Lock_Status = LOCKED;
	Lock_Status = Flash_Unlock_Operation();
	if(UNLOCKED == Lock_Status) {
		FLASH_Program_Memory_Write(Program_Memory.Start_Address, 4, &myData[0]);
	}
	FLASH_Eeprom_Write(Eeprom_Data.Start_Address, 4, &myData[0]);
}

 /**
 * \brief Data EEPROM Word Write
 *
 * \details This operation is used to write a word to the data EEPROM whatever the previous value of the word to be written to
 * 
 * \param none
 * \return none
 */
static void FLASH_Eeprom_Write(uint32_t Start_Address, uint16_t Length, uint16_t *Data) {
	uint16_t Index = 0U;
	uint16_t Address_Counter = 0U;
	/* execute Word Write */
	FLASH->PECR |= 1ul << 8;
	for(Index = 0 ; Index < Length/2 ; Index+=1) {
		*((uint32_t*)Start_Address + Address_Counter) = ((Data[Index * 2] << 16) | Data[Index * 2 + 1]);
		Address_Counter++;
	}
}

 /**
 * \brief Flash Fast Word Write
 *
 * \details This operation is used to write a word to the program memory,
 * 
 * \param none
 * \return none
 */
static void FLASH_Program_Memory_Write(uint32_t Start_Address, uint16_t Length, uint16_t *Data) {
	uint16_t Index = 0U;
	uint16_t Address_Counter = 0U;
	for(Index = 0 ; Index < Length/2 ; Index+=1) {
		*((uint32_t*)Start_Address + Address_Counter) = ((Data[Index * 2] << 16) | Data[Index * 2 + 1]);
		Address_Counter++;
	}
}

 /**
 * \brief Unlock Program memory and Data Eeprom
 *
 * \details The Program/erase key register is used to allow access to FLASH_PECR and so, 
 *	to allow program and erase operations in the data EEPROM.
 * 
 * \param none
 * \return none
 */
 static FLASH_LOCK_STATUS_t Flash_Unlock_Operation(void) {
	 FLASH_LOCK_STATUS_t Lock_Status = LOCKED;
	 /* Get lock of status of the memory */
	 Lock_Status = ((FLASH->PECR & (1ul << 0)) & 0x01);
	 /* Unlock the Data EEPROM and PECR register */
	 FLASH->PEKEYR = 0x89ABCDEF;
	 FLASH->PEKEYR = 0x02030405;
	 /* Get lock of status of the PECR register */
	 Lock_Status = ((FLASH->PECR & (1ul << 0)) & 0x01);
	 if(UNLOCKED == Lock_Status) {
		 /* Unlock the Program Memory */
		 FLASH->PRGKEYR = 0x8C9DAEBF;
		 FLASH->PRGKEYR = 0x13141516;
		 /* Get lock of status of the Program Memory */
		 Lock_Status = ((FLASH->PECR & (1ul << 0)) & 0x01);
	 }
	 /* return lock status of the memory */
	 return (Lock_Status);
 }
 
 
 
 