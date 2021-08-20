################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Mcal/UART/subdir.mk
-include Mcal/DIO/subdir.mk
-include Firmware/LED/subdir.mk
-include App/TrafficLight/subdir.mk
-include App/EchoSystem/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
S_UART.lss \

FLASH_IMAGE += \
S_UART.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: S_UART.elf secondary-outputs

# Tool invocations
S_UART.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,S_UART.map -mmcu=atmega32 -o "S_UART.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

S_UART.lss: S_UART.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S S_UART.elf  >"S_UART.lss"
	@echo 'Finished building: $@'
	@echo ' '

S_UART.hex: S_UART.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex S_UART.elf  "S_UART.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: S_UART.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 S_UART.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) S_UART.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
