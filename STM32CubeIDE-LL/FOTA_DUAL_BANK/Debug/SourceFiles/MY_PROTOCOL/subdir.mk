################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SourceFiles/MY_PROTOCOL/My_Protocol.c 

OBJS += \
./SourceFiles/MY_PROTOCOL/My_Protocol.o 

C_DEPS += \
./SourceFiles/MY_PROTOCOL/My_Protocol.d 


# Each subdirectory must supply rules for building sources it contributes
SourceFiles/MY_PROTOCOL/%.o SourceFiles/MY_PROTOCOL/%.su: ../SourceFiles/MY_PROTOCOL/%.c SourceFiles/MY_PROTOCOL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32L1 -DSTM32 -DSTM32L152RETx -c -I../Inc -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/Inc/CMSIS" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/Inc/ST" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/CRC" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/ESP8266" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/FLASH" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/GPIO" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/MY_PROTOCOL" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/SYSTEM_TIMER" -I"C:/Users/mehme/Embedded Systems/FOTA/stm32l152ret6_esp8266_bootloader/STM32CubeIDE-LL/FOTA_DUAL_BANK/SourceFiles/UART" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SourceFiles-2f-MY_PROTOCOL

clean-SourceFiles-2f-MY_PROTOCOL:
	-$(RM) ./SourceFiles/MY_PROTOCOL/My_Protocol.d ./SourceFiles/MY_PROTOCOL/My_Protocol.o ./SourceFiles/MY_PROTOCOL/My_Protocol.su

.PHONY: clean-SourceFiles-2f-MY_PROTOCOL

