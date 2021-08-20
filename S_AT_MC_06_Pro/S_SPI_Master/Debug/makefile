################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Mcal/UART/subdir.mk
-include Mcal/SPI/subdir.mk
-include Mcal/GLOBAL_INTERRUPT/subdir.mk
-include Mcal/EXTERNAL_INTERRUPT/subdir.mk
-include Mcal/DIO/subdir.mk
-include Firmware/LED/subdir.mk
-include App/MASTER_APP/subdir.mk
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
S_SPI_Master.lss \

FLASH_IMAGE += \
S_SPI_Master.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: S_SPI_Master.elf secondary-outputs

# Tool invocations
S_SPI_Master.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,S_SPI_Master.map -mmcu=atmega16 -o "S_SPI_Master.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

S_SPI_Master.lss: S_SPI_Master.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S S_SPI_Master.elf  >"S_SPI_Master.lss"
	@echo 'Finished building: $@'
	@echo ' '

S_SPI_Master.hex: S_SPI_Master.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex S_SPI_Master.elf  "S_SPI_Master.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: S_SPI_Master.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 S_SPI_Master.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) S_SPI_Master.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
