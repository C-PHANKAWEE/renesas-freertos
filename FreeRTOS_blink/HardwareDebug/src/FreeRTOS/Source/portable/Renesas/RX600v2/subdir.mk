################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/FreeRTOS/Source/portable/Renesas/RX600v2/port.c 

SRC_SRCS += \
../src/FreeRTOS/Source/portable/Renesas/RX600v2/port_asm.src 

SRC_DEPS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port_asm.d 

ASSEMBLER_OBJS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port_asm.obj 

COMPILER_OBJS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port.obj 

C_DEPS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port.d 

# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS/Source/portable/Renesas/RX600v2/%.obj: ../src/FreeRTOS/Source/portable/Renesas/RX600v2/%.c src/FreeRTOS/Source/portable/Renesas/RX600v2/Compiler.sub
	@echo 'Scanning and building file: $<'
	ccrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	ccrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\cSubCommand.tmp" "$<"


src/FreeRTOS/Source/portable/Renesas/RX600v2/%.obj: ../src/FreeRTOS/Source/portable/Renesas/RX600v2/%.src src/FreeRTOS/Source/portable/Renesas/RX600v2/Assembler.sub
	@echo 'Scanning and building file: $<'
	asrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\srcDepSubCommand.tmp" -MF="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	asrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\srcSubCommand.tmp" -output="$(@:%.d=%.obj)" "$<"


