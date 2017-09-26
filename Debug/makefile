################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/energia-0101E0014/hardware/tools/msp430

ORDERED_OBJS += \
"./Enrf24.o" \
"./RF_Light_Remote_Base.o" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-l"lpmsp430g2553_SPI" \
-l"lpmsp430g2553_core" \
-l"m" \
-Wl,--end-group \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
RF_Light_Remote_Base.out \

EXE_OUTPUTS__QUOTED += \
"RF_Light_Remote_Base.out" \

BIN_OUTPUTS += \
RF_Light_Remote_Base.hex \

BIN_OUTPUTS__QUOTED += \
"RF_Light_Remote_Base.hex" \


# All Target
all: RF_Light_Remote_Base.out

dependents:
	-cd E:/OneDrive/CCS/lpmsp430g2553_core/Debug && $(MAKE) all
	-cd E:/OneDrive/CCS/lpmsp430g2553_SPI/Debug && $(MAKE) all

# Tool invocations
RF_Light_Remote_Base.out: $(OBJS) $(GEN_CMDS) E:/OneDrive/CCS/lpmsp430g2553_core/Debug/liblpmsp430g2553_core.a E:/OneDrive/CCS/lpmsp430g2553_SPI/Debug/liblpmsp430g2553_SPI.a
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Linker'
	"E:/energia-0101E0014/hardware/tools/msp430/bin/msp430-gcc.exe" -mmcu=msp430g2553 -DF_CPU=16000000L -DARDUINO=101 -DENERGIA=12 -Os -ffunction-sections -fdata-sections -g -gstrict-dwarf -Wall -Wl,-Map,"RF_Light_Remote_Base.map" -Wl,--gc-sections -L"E:/OneDrive/CCS/lpmsp430g2553_core/Debug" -L"E:/OneDrive/CCS/lpmsp430g2553_SPI/Debug" -Wl,--undefined,main -o"RF_Light_Remote_Base.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

RF_Light_Remote_Base.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: GNU Objcopy Utility'
	"E:/energia-0101E0014/hardware/tools/msp430/bin/msp430-objcopy.exe"  $(EXE_OUTPUTS__QUOTED) "RF_Light_Remote_Base.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "Enrf24.d" "RF_Light_Remote_Base.d" 
	-$(RM) "Enrf24.o" "RF_Light_Remote_Base.o" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-E:/energia-0101E0014/hardware/tools/msp430/bin/msp430-objcopy -O ihex -R .eeprom RF_Light_Remote_Base.out RF_Light_Remote_Base.hex
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
E:/OneDrive/CCS/lpmsp430g2553_core/Debug/liblpmsp430g2553_core.a:
E:/OneDrive/CCS/lpmsp430g2553_SPI/Debug/liblpmsp430g2553_SPI.a:

-include ../makefile.targets

