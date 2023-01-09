/**
 * @file Flash_Unit.c
 * @author Mehmet KORAL
 * @date 09 01 2023
 * @brief Source file to manage flash operation
 */
 
 #include "Flash_Unit.h"
 #include "Flash_Unit_Api.h"
 
 static void FLASH_Write(void);
 static FLASH_LOCK_STATUS_t Flash_Unlock_Operation(void);
 
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
		FLASH_Write();
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
static void FLASH_Write(void) {
	
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
 
 
 
 