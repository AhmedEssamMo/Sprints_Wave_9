################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Mcal/UART/subdir.mk
-include Mcal/TWI/subdir.mk
-include Mcal/I2C/subdir.mk
-include Mcal/GLOBAL_INTERRUPT/subdir.mk
-include Mcal/EXTERNAL_INTERRUPT/subdir.mk
-include Mcal/DIO/subdir.mk
-include Mcal/ADC/subdir.mk
-include Firmware/TEMP/subdir.mk
-include Firmware/Motor/subdir.mk
-include Firmware/LCD/subdir.mk
-include Firmware/KEYPAD/subdir.mk
-include App/THERMOSTAT/subdir.mk
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
S_Thermostat.lss \

FLASH_IMAGE += \
S_Thermostat.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: S_Thermostat.elf secondary-outputs

# Tool invocations
S_Thermostat.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,S_Thermostat.map -mmcu=atmega16 -o "S_Thermostat.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

S_Thermostat.lss: S_Thermostat.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S S_Thermostat.elf  >"S_Thermostat.lss"
	@echo 'Finished building: $@'
	@echo ' '

S_Thermostat.hex: S_Thermostat.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex S_Thermostat.elf  "S_Thermostat.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: S_Thermostat.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 S_Thermostat.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) S_Thermostat.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
