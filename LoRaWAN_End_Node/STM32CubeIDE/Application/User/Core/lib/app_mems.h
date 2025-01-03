/*
 * app_mems.h
 *
 *  Created on: May 18, 2024
 *      Author: Nakor
 */

#ifndef APPLICATION_USER_CORE_INC_APP_MEMS_H_
#define APPLICATION_USER_CORE_INC_APP_MEMS_H_

#include "main.h"
#include "iks02a1_mems_control.h"
#include "iks02a1_mems_control_ex.h"

//#define ARM_MATH_CM4
#define ARM_MATH_CM4
#include "arm_math.h"

typedef struct
{
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
  uint8_t subsec;
  float pressure;
  float humidity;
  float temperature;
  int32_t acceleration_x_mg;
  int32_t acceleration_y_mg;
  int32_t acceleration_z_mg;
  int32_t angular_rate_x_mdps;
  int32_t angular_rate_y_mdps;
  int32_t angular_rate_z_mdps;
  int32_t magnetic_field_x_mgauss;
  int32_t magnetic_field_y_mgauss;
  int32_t magnetic_field_z_mgauss;
} offline_data_t;

#define Acc_bufffer_size 512
#define FFT_BUFFER_SIZE	Acc_bufffer_size
#define FFT_LENGTH FFT_BUFFER_SIZE/2

typedef struct{
	float 	Sum_sqrt_X;
	float 	Sum_sqrt_Y;
	float	Sum_sqrt_Z;

	float 	x;
	float 	y;
	float 	z;
	int16_t		sample_size;
	uint16_t	index;
}type_rms;


typedef struct {
	MOTION_SENSOR_Axes_t AccValue[Acc_bufffer_size];
	//MOTION_SENSOR_Axes_t GyrValue[Acc_bufffer_size];

	float32_t aFFT_Input_f32[FFT_BUFFER_SIZE];
	float32_t aFFT_Output_f32[FFT_BUFFER_SIZE];
//	float32_t magnitude[FFT_LENGTH / 2];
	arm_status status;

	float32_t maxValue;    /* Max FFT value is stored here */
	uint32_t maxIndex;    /* Index in Output array where max value is */
	//	Calculate RMS
	type_rms rms_acc;
	type_rms rms_gyr;
	type_rms rms_vel;

	uint16_t index;
	uint16_t index_buff;
	uint16_t index_afft;
	uint8_t req_cmd;
}type_acc;

extern type_acc acc_mems;
extern void Init_Sensors(void);
extern void MX_mem_sensor(void);
extern void Accelero_Sensor_Handler();
extern void Gyro_Sensor_Handler();
extern void Mems_Start_req();
extern void Mems_get_sampling_handler();
extern void Cal_Rms_value(type_rms *dataRms,MOTION_SENSOR_Axes_t *axes,int16_t sample_size);
extern void Cal_Rms_velocity(type_rms *dataRms, MOTION_SENSOR_Axes_t *axes, int16_t sample_size);
extern void Process_FFT_Input_buffer(type_acc *mems,MOTION_SENSOR_Axes_t *axes, uint8_t axis);

#endif /* APPLICATION_USER_CORE_INC_APP_MEMS_H_ */
