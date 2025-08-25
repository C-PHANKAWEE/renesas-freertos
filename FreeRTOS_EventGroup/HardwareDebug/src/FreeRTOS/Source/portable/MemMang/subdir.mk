################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/FreeRTOS/Source/portable/MemMang/heap_4.c 

COMPILER_OBJS += \
src/FreeRTOS/Source/portable/MemMang/heap_4.obj 

C_DEPS += \
src/FreeRTOS/Source/portable/MemMang/heap_4.d 

# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS/Source/portable/MemMang/%.obj: ../src/FreeRTOS/Source/portable/MemMang/%.c 
	@echo 'Scanning and building file: $<'
	ccrx -subcommand="src\FreeRTOS\Source\portable\MemMang\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	ccrx -subcommand="src\FreeRTOS\Source\portable\MemMang\cSubCommand.tmp" "$<"


