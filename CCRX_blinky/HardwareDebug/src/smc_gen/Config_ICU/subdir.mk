################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_ICU/Config_ICU.c \
../src/smc_gen/Config_ICU/Config_ICU_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_ICU/Config_ICU.obj \
src/smc_gen/Config_ICU/Config_ICU_user.obj 

C_DEPS += \
src/smc_gen/Config_ICU/Config_ICU.d \
src/smc_gen/Config_ICU/Config_ICU_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_ICU/%.obj: ../src/smc_gen/Config_ICU/%.c 
	@echo 'Scanning and building file: $<'
	ccrx -subcommand="src\smc_gen\Config_ICU\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	ccrx -subcommand="src\smc_gen\Config_ICU\cSubCommand.tmp" "$<"


