################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/SLAVE_APP/twi_slave_app.c 

OBJS += \
./App/SLAVE_APP/twi_slave_app.o 

C_DEPS += \
./App/SLAVE_APP/twi_slave_app.d 


# Each subdirectory must supply rules for building sources it contributes
App/SLAVE_APP/%.o: ../App/SLAVE_APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


