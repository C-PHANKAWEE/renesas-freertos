################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/r_gpio_rx/src/r_gpio_rx.c 

COMPILER_OBJS += \
src/smc_gen/r_gpio_rx/src/r_gpio_rx.obj 

C_DEPS += \
src/smc_gen/r_gpio_rx/src/r_gpio_rx.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/r_gpio_rx/src/%.obj: ../src/smc_gen/r_gpio_rx/src/%.c src/smc_gen/r_gpio_rx/src/Compiler.sub
	@echo 'Scanning and building file: $<'
	ccrx -subcommand="src\smc_gen\r_gpio_rx\src\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	ccrx -subcommand="src\smc_gen\r_gpio_rx\src\cSubCommand.tmp" "$<"


