/**
 * @file Esp8266.h
 * @author Mehmet KORAL
 * @date 27 Dec 2022
 * @brief Manage ESP8266 related tasks
 */
 
#include "stm32l1xx.h"                  // Device header
#include "stdint.h"
#include "stdio.h"
 
#include "Esp8266_Config.h"

/* Include APIs */
#include "Uart_Api.h"
#include "Gpio.h"
