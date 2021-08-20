################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/I2C/I2C.c \
../Mcal/I2C/MockI2CRegisters.c 

OBJS += \
./Mcal/I2C/I2C.o \
./Mcal/I2C/MockI2CRegisters.o 

C_DEPS += \
./Mcal/I2C/I2C.d \
./Mcal/I2C/MockI2CRegisters.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/I2C/%.o: ../Mcal/I2C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


