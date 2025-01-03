################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/STM32_MotionSP_Library/Src/MotionSP.c 

OBJS += \
./Middlewares/STM32_MotionSP_Library/Src/MotionSP.o 

C_DEPS += \
./Middlewares/STM32_MotionSP_Library/Src/MotionSP.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_MotionSP_Library/Src/%.o Middlewares/STM32_MotionSP_Library/Src/%.su Middlewares/STM32_MotionSP_Library/Src/%.cyclo: ../Middlewares/STM32_MotionSP_Library/Src/%.c Middlewares/STM32_MotionSP_Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WL5Mxx -DSTM32WL5mxx -DFFT_DEMO -DUSE_IKS02A1 -c -I../../Core/Inc -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/Drivers/CMSIS/DSP/Include" -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Utilities/trace/adv_trace -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/lpm/tiny_lpm -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/B-WL5M-SUBG -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/Components/stts22h -I../../Drivers/BSP/Components/ilps22qs -I../../X-CUBE-MEMS1/Target -I../../Drivers/BSP/B-WL5M-SUBG1 -I../../Drivers/BSP/Components/ism330dhcx -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/STM32CubeIDE/Middlewares/STM32_MotionSP_Library/Inc" -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/STM32CubeIDE/Middlewares/STM32_MotionSP_Library/Src" -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/STM32CubeIDE/Drivers/BSP/IKS02A1" -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/STM32CubeIDE/Application/User/Core/lib" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-STM32_MotionSP_Library-2f-Src

clean-Middlewares-2f-STM32_MotionSP_Library-2f-Src:
	-$(RM) ./Middlewares/STM32_MotionSP_Library/Src/MotionSP.cyclo ./Middlewares/STM32_MotionSP_Library/Src/MotionSP.d ./Middlewares/STM32_MotionSP_Library/Src/MotionSP.o ./Middlewares/STM32_MotionSP_Library/Src/MotionSP.su

.PHONY: clean-Middlewares-2f-STM32_MotionSP_Library-2f-Src

