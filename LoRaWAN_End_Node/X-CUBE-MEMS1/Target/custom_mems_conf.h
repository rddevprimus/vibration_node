/**
  ******************************************************************************
  * @file    custom_mems_conf.h
  * @author  MEMS Software Solutions Team
  * @brief   This file contains definitions of the MEMS components bus interfaces for custom boards
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUSTOM_MEMS_CONF_H
#define CUSTOM_MEMS_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wlxx_hal.h"
#include "b_wl5m_subg1_bus.h"
#include "b_wl5m_subg1_errno.h"

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

#define USE_CUSTOM_MOTION_SENSOR_ISM330DHCX_0     0U

#define CUSTOM_ISM330DHCX_0_I2C_Init BSP_I2C2_Init
#define CUSTOM_ISM330DHCX_0_I2C_DeInit BSP_I2C2_DeInit
#define CUSTOM_ISM330DHCX_0_I2C_ReadReg BSP_I2C2_ReadReg
#define CUSTOM_ISM330DHCX_0_I2C_WriteReg BSP_I2C2_WriteReg

#ifdef __cplusplus
}
#endif

#endif /* CUSTOM_MEMS_CONF_H*/
