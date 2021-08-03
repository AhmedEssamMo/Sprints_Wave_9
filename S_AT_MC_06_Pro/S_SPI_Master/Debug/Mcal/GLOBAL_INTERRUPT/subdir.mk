################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/GLOBAL_INTERRUPT/globalInterrupt.c 

OBJS += \
./Mcal/GLOBAL_INTERRUPT/globalInterrupt.o 

C_DEPS += \
./Mcal/GLOBAL_INTERRUPT/globalInterrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/GLOBAL_INTERRUPT/%.o: ../Mcal/GLOBAL_INTERRUPT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


