/*
 * main.h
 *
 *  Created on: Feb 27, 2023
 *      Author: mehme
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include <stdio.h>
#include "Gpio.h"
#include "Sys_Timer_Api.h"
#include "Uart_Api.h"
#include "Esp8266_Api.h"
#include "CRC_Calculation_Api.h"
#include "Flash_Unit_Api.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#endif /* MAIN_H_ */
