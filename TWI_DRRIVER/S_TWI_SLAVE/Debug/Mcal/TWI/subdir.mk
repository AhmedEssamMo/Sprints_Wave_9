################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/TWI/twi.c \
../Mcal/TWI/twiMockReg.c 

OBJS += \
./Mcal/TWI/twi.o \
./Mcal/TWI/twiMockReg.o 

C_DEPS += \
./Mcal/TWI/twi.d \
./Mcal/TWI/twiMockReg.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/TWI/%.o: ../Mcal/TWI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


