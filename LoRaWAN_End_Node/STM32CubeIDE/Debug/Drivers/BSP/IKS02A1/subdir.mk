################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/IKS02A1/iks02a1_mems_control.c \
../Drivers/BSP/IKS02A1/iks02a1_mems_control_ex.c \
../Drivers/BSP/IKS02A1/iks02a1_motion_sensors.c \
../Drivers/BSP/IKS02A1/iks02a1_motion_sensors_ex.c 

OBJS += \
./Drivers/BSP/IKS02A1/iks02a1_mems_control.o \
./Drivers/BSP/IKS02A1/iks02a1_mems_control_ex.o \
./Drivers/BSP/IKS02A1/iks02a1_motion_sensors.o \
./Drivers/BSP/IKS02A1/iks02a1_motion_sensors_ex.o 

C_DEPS += \
./Drivers/BSP/IKS02A1/iks02a1_mems_control.d \
./Drivers/BSP/IKS02A1/iks02a1_mems_control_ex.d \
./Drivers/BSP/IKS02A1/iks02a1_motion_sensors.d \
./Drivers/BSP/IKS02A1/iks02a1_motion_sensors_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/IKS02A1/%.o Drivers/BSP/IKS02A1/%.su Drivers/BSP/IKS02A1/%.cyclo: ../Drivers/BSP/IKS02A1/%.c Drivers/BSP/IKS02A1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WL5Mxx -DSTM32WL5mxx -DFFT_DEMO -c -I../../Core/Inc -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/Drivers/CMSIS/DSP/Include" -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Utilities/trace/adv_trace -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/lpm/tiny_lpm -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/B-WL5M-SUBG -I../../Drivers/BSP/Components/Common -I../../Drivers/BSP/Components/stts22h -I../../Drivers/BSP/Components/ilps22qs -I../../X-CUBE-MEMS1/Target -I../../Drivers/BSP/B-WL5M-SUBG1 -I../../Drivers/BSP/Components/ism330dhcx -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/STM32CubeIDE/Drivers/BSP/IKS02A1" -I"C:/Users/Nakor/STM32Cube/Example/LoRaWAN_End_Node/STM32CubeIDE/Application/User/Core/lib" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-IKS02A1

clean-Drivers-2f-BSP-2f-IKS02A1:
	-$(RM) ./Drivers/BSP/IKS02A1/iks02a1_mems_control.cyclo ./Drivers/BSP/IKS02A1/iks02a1_mems_control.d ./Drivers/BSP/IKS02A1/iks02a1_mems_control.o ./Drivers/BSP/IKS02A1/iks02a1_mems_control.su ./Drivers/BSP/IKS02A1/iks02a1_mems_control_ex.cyclo ./Drivers/BSP/IKS02A1/iks02a1_mems_control_ex.d ./Drivers/BSP/IKS02A1/iks02a1_mems_control_ex.o ./Drivers/BSP/IKS02A1/iks02a1_mems_control_ex.su ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors.cyclo ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors.d ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors.o ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors.su ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors_ex.cyclo ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors_ex.d ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors_ex.o ./Drivers/BSP/IKS02A1/iks02a1_motion_sensors_ex.su

.PHONY: clean-Drivers-2f-BSP-2f-IKS02A1

