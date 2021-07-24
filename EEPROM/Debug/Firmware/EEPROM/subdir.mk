################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Firmware/EEPROM/eeprom.c 

OBJS += \
./Firmware/EEPROM/eeprom.o 

C_DEPS += \
./Firmware/EEPROM/eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
Firmware/EEPROM/%.o: ../Firmware/EEPROM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


