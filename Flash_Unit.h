/**
 * @file Flash_Unit.h
 * @author Mehmet KORAL
 * @date 09 01 2023
 * @brief Header file to manage flash operation
 */
#include "stm32l1xx.h"                  // Device header
#include <stdint.h>

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
 
 /**
 * \enum Flash lock status
 *
 * \details no info
 * 
 * \param  none
 * \return none
 */
 typedef enum {
	 UNLOCKED,
	 LOCKED
 }FLASH_LOCK_STATUS_t;
 
 
 
 
 