################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/THERMOSTAT/thermostat.c 

OBJS += \
./App/THERMOSTAT/thermostat.o 

C_DEPS += \
./App/THERMOSTAT/thermostat.d 


# Each subdirectory must supply rules for building sources it contributes
App/THERMOSTAT/%.o: ../App/THERMOSTAT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


