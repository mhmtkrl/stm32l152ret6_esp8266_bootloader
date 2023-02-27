################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SourceFiles/SYSTEM_TIMER/Sys_Timer.c 

OBJS += \
./SourceFiles/SYSTEM_TIMER/Sys_Timer.o 

C_DEPS += \
./SourceFiles/SYSTEM_TIMER/Sys_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
SourceFiles/SYSTEM_TIMER/%.o SourceFiles/SYSTEM_TIMER/%.su: ../SourceFiles/SYSTEM_TIMER/%.c SourceFiles/SYSTEM_TIMER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32L1 -DSTM32 -DSTM32L152RETx -c -I../Inc -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/Inc/CMSIS" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/Inc/ST" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/CRC" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/ESP8266" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/FLASH" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/GPIO" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/MY_PROTOCOL" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/SYSTEM_TIMER" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/UART" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SourceFiles-2f-SYSTEM_TIMER

clean-SourceFiles-2f-SYSTEM_TIMER:
	-$(RM) ./SourceFiles/SYSTEM_TIMER/Sys_Timer.d ./SourceFiles/SYSTEM_TIMER/Sys_Timer.o ./SourceFiles/SYSTEM_TIMER/Sys_Timer.su

.PHONY: clean-SourceFiles-2f-SYSTEM_TIMER

