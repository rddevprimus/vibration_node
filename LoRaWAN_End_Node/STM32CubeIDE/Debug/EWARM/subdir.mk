################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../EWARM/startup_stm32wl55xx_cm4.s 

OBJS += \
./EWARM/startup_stm32wl55xx_cm4.o 

S_DEPS += \
./EWARM/startup_stm32wl55xx_cm4.d 


# Each subdirectory must supply rules for building sources it contributes
EWARM/%.o: ../EWARM/%.s EWARM/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-EWARM

clean-EWARM:
	-$(RM) ./EWARM/startup_stm32wl55xx_cm4.d ./EWARM/startup_stm32wl55xx_cm4.o

.PHONY: clean-EWARM

