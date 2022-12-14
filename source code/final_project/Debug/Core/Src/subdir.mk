################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/auto_fsm.c \
../Core/Src/global.c \
../Core/Src/hardware_layer.c \
../Core/Src/input_reading.c \
../Core/Src/main.c \
../Core/Src/manual_fsm.c \
../Core/Src/pedes_fsm.c \
../Core/Src/setting_fsm.c \
../Core/Src/software_timer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/auto_fsm.o \
./Core/Src/global.o \
./Core/Src/hardware_layer.o \
./Core/Src/input_reading.o \
./Core/Src/main.o \
./Core/Src/manual_fsm.o \
./Core/Src/pedes_fsm.o \
./Core/Src/setting_fsm.o \
./Core/Src/software_timer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/auto_fsm.d \
./Core/Src/global.d \
./Core/Src/hardware_layer.d \
./Core/Src/input_reading.d \
./Core/Src/main.d \
./Core/Src/manual_fsm.d \
./Core/Src/pedes_fsm.d \
./Core/Src/setting_fsm.d \
./Core/Src/software_timer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/auto_fsm.d ./Core/Src/auto_fsm.o ./Core/Src/auto_fsm.su ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/hardware_layer.d ./Core/Src/hardware_layer.o ./Core/Src/hardware_layer.su ./Core/Src/input_reading.d ./Core/Src/input_reading.o ./Core/Src/input_reading.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/manual_fsm.d ./Core/Src/manual_fsm.o ./Core/Src/manual_fsm.su ./Core/Src/pedes_fsm.d ./Core/Src/pedes_fsm.o ./Core/Src/pedes_fsm.su ./Core/Src/setting_fsm.d ./Core/Src/setting_fsm.o ./Core/Src/setting_fsm.su ./Core/Src/software_timer.d ./Core/Src/software_timer.o ./Core/Src/software_timer.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

