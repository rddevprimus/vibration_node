################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../MDK-ARM/startup_stm32wl55xx_cm4.s 

OBJS += \
./MDK-ARM/startup_stm32wl55xx_cm4.o 

S_DEPS += \
./MDK-ARM/startup_stm32wl55xx_cm4.d 


# Each subdirectory must supply rules for building sources it contributes
MDK-ARM/%.o: ../MDK-ARM/%.s MDK-ARM/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-MDK-2d-ARM

clean-MDK-2d-ARM:
	-$(RM) ./MDK-ARM/startup_stm32wl55xx_cm4.d ./MDK-ARM/startup_stm32wl55xx_cm4.o

.PHONY: clean-MDK-2d-ARM
