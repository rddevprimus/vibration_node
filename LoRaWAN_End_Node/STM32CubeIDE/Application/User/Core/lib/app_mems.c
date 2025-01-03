/*
 * app_mems.c
 *
 *  Created on: May 18, 2024
 *      Author: Nakor
 */

#include "app_mems.h"
//#include "main.h"
#include <stdio.h>
#include "utilities_def.h"
#include "sys_app.h"

//#include "iks02a1_mems_control.h"
//#include "iks02a1_mems_control_ex.h"


/* Enable sensor masks */
#define PRESSURE_SENSOR       0x00000001U
#define TEMPERATURE_SENSOR    0x00000002U
#define HUMIDITY_SENSOR       0x00000004U
#define UV_SENSOR             0x00000008U /* for future use */
#define ACCELEROMETER_SENSOR  0x00000010U
#define GYROSCOPE_SENSOR      0x00000020U
#define MAGNETIC_SENSOR       0x00000040U
#define GAS_SENSOR            0x00000080U

#define DWT_LAR_KEY  0xC5ACCE55 /* DWT register unlock key */
//#define ALGO_FREQ  1536U /* Algorithm frequency 100Hz */
#define ACC_ODR  1024U		// Freq 1024 Hz//
#define ACC_FS  4 /* FS = <-4g, 4g> */
#define GRAVITATIONAL_ACCELERATION	9.80665f

#define OFFLINE_DATA_SIZE  8
#define NOISE_THRESHOLD 0.01f // Threshold to consider as noise

static MOTION_SENSOR_Axes_t AccValue;
static MOTION_SENSOR_Axes_t GyrValue;
type_acc acc_mems;


uint8_t UseOfflineData = 0;
////offline_data_t OfflineData[OFFLINE_DATA_SIZE];
//int OfflineDataReadIndex = 0;
//int OfflineDataWriteIndex = 0;
//int OfflineDataCount = 0;

#define FFT_INVERSE_FLAG        ((uint8_t)0)
#define FFT_Normal_OUTPUT_FLAG  ((uint8_t)1)
//volatile arm_cfft_instance_f32  FFThandler;

arm_cfft_radix4_instance_f32	FFThandler;

void MX_mem_sensor(void)
{
	char acc_orientation[4];
	char gyro_orientation[4];
	BSP_SENSOR_ACC_GetOrientation(acc_orientation);
	BSP_SENSOR_GYR_GetOrientation(gyro_orientation);

}

void Accelero_Sensor_Handler()
{
    if (UseOfflineData == 1)
    {
//      AccValue.x = OfflineData[OfflineDataReadIndex].acceleration_x_mg;
//      AccValue.y = OfflineData[OfflineDataReadIndex].acceleration_y_mg;
//      AccValue.z = OfflineData[OfflineDataReadIndex].acceleration_z_mg;
    }
    else
    {
      BSP_SENSOR_ACC_GetAxes(&AccValue);
    }

}

void Gyro_Sensor_Handler()
{

    if (UseOfflineData == 1)
    {
//      GyrValue.x = OfflineData[OfflineDataReadIndex].angular_rate_x_mdps;
//      GyrValue.y = OfflineData[OfflineDataReadIndex].angular_rate_y_mdps;
//      GyrValue.z = OfflineData[OfflineDataReadIndex].angular_rate_z_mdps;
    }
    else
    {
      BSP_SENSOR_GYR_GetAxes(&GyrValue);
    }

}


void Init_Sensors(void)
{
	acc_mems.status = ARM_MATH_SUCCESS;
	arm_cfft_radix4_init_f32(&FFThandler, FFT_BUFFER_SIZE/2, FFT_INVERSE_FLAG, FFT_Normal_OUTPUT_FLAG);
	//arm_cfft_radix4_init_f32(&FFThandler, FFT_LENGTH, FFT_INVERSE_FLAG, FFT_Normal_OUTPUT_FLAG);

	(void)IKS02A1_MOTION_SENSOR_Init(IKS02A1_ISM330DHCX_0, MOTION_ACCELERO);
//	(void)IKS02A1_MOTION_SENSOR_Init(IKS02A1_ISM330DHCX_0, MOTION_GYRO);

	(void)IKS02A1_MOTION_SENSOR_SetOutputDataRate(IKS02A1_ISM330DHCX_0, MOTION_ACCELERO, ACC_ODR);
	(void)IKS02A1_MOTION_SENSOR_SetFullScale(IKS02A1_ISM330DHCX_0, MOTION_ACCELERO, ACC_FS);
	Accelero_Sensor_Handler();
	acc_mems.index_afft=0;

//	arm_rfft_fast_init_f32(&FFThandler, Acc_bufffer_size);
}

void Mems_Start_req()
{
	if(acc_mems.req_cmd)
		return;
	acc_mems.req_cmd=1;
	acc_mems.index_buff=0;
	acc_mems.index=0;
}

void calculateMagnitude(const float32_t *complexSignal, float32_t *magnitude, uint32_t length) {
    // Calculate the magnitude of the complex signal
    for (uint32_t i = 0; i < length; i++) {
        float32_t real = complexSignal[2 * i];
        float32_t imag = complexSignal[2 * i + 1];
        magnitude[i] = sqrtf(real * real + imag * imag);
    }
}

void Mems_get_sampling_handler()
{
	if(!acc_mems.req_cmd)
		return;
	Accelero_Sensor_Handler();
//	Gyro_Sensor_Handler();
	if(acc_mems.index<3)
		{
		acc_mems.index++;
		return;
		}

	if(acc_mems.index_buff<Acc_bufffer_size)
	{
		acc_mems.AccValue[acc_mems.index_buff].x=AccValue.x;
		acc_mems.AccValue[acc_mems.index_buff].y=AccValue.y;
		acc_mems.AccValue[acc_mems.index_buff].z=AccValue.z;

//		acc_mems.GyrValue[acc_mems.index_buff].x=GyrValue.x;
//		acc_mems.GyrValue[acc_mems.index_buff].y=GyrValue.y;
//		acc_mems.GyrValue[acc_mems.index_buff].z=GyrValue.z;
		acc_mems.index_buff+=1;
//		acc_mems.index_afft+=2;
	}
	else
	{
//		acc_mems.index_afft=0;
		Cal_Rms_value(&acc_mems.rms_acc,acc_mems.AccValue,acc_mems.index_buff);
//		Cal_Rms_value(&acc_mems.rms_gyr,acc_mems.GyrValue,acc_mems.index_buff);
		Cal_Rms_velocity(&acc_mems.rms_vel, acc_mems.AccValue, acc_mems.index_buff);

		Process_FFT_Input_buffer(&acc_mems,acc_mems.AccValue,2);
		arm_cfft_radix4_f32(&FFThandler, acc_mems.aFFT_Input_f32);
		calculateMagnitude(acc_mems.aFFT_Input_f32, acc_mems.aFFT_Output_f32, FFT_LENGTH);
		acc_mems.aFFT_Output_f32[0]=0;
		arm_max_f32(acc_mems.aFFT_Output_f32, FFT_LENGTH, &acc_mems.maxValue, &acc_mems.maxIndex);
		// dfreq = (sample_rate/2)/FFT_Length
		//	FFT_Length=Acc_Buffer_size/2
		// dfreq =1.3333		Note Sample_rate from test is 682.66667 Hz

		acc_mems.maxValue=0;
		acc_mems.req_cmd=0;
//		acc_mems.index_buff=512;
	}
}

void Process_FFT_Input_buffer(type_acc *mems,MOTION_SENSOR_Axes_t *axes, uint8_t axis)
{
	uint16_t index_fft;
	for(index_fft=0;index_fft<FFT_BUFFER_SIZE;index_fft+=2)
	{
		switch(axis)
		{
		case 0: //x
			mems->aFFT_Input_f32[index_fft]=(float32_t)(axes)->x/1000;
			break;
		case 1: //y
			mems->aFFT_Input_f32[index_fft]=(float32_t)(axes)->y/1000;
			break;
		default:
		case 2: //z
			mems->aFFT_Input_f32[index_fft]=(float32_t)(axes)->z/1000;
			break;
		}
		mems->aFFT_Input_f32[index_fft+1]=0;
		axes++;
	}

}

void Cal_Rms_value(type_rms *dataRms,MOTION_SENSOR_Axes_t *axes,int16_t sample_size)
{
	int inx=0;
	float axis_x=0,axis_y=0,axis_z=0;
	dataRms->Sum_sqrt_X=0;
	dataRms->Sum_sqrt_Y=0;
	dataRms->Sum_sqrt_Z=0;
	for(inx=0;inx<sample_size;inx++)
	{
		axis_x=(float)(axes+inx)->x/1000;
		axis_y=(float)(axes+inx)->y/1000;
		axis_z=(float)(axes+inx)->z/1000;
		dataRms->Sum_sqrt_X+=axis_x*axis_x;
		dataRms->Sum_sqrt_Y+=axis_y*axis_y;
		dataRms->Sum_sqrt_Z+=axis_z*axis_z;
	}
	dataRms->x=sqrt(dataRms->Sum_sqrt_X/sample_size);
	dataRms->y=sqrt(dataRms->Sum_sqrt_Y/sample_size);
	dataRms->z=sqrt(dataRms->Sum_sqrt_Z/sample_size);

}

void Cal_Rms_velocity(type_rms *dataRms, MOTION_SENSOR_Axes_t *axes, int16_t sample_size) {
    int inx;
    float velocity_x = 0, velocity_y = 0, velocity_z = 0;
    float prev_velocity_x = 0, prev_velocity_y = 0, prev_velocity_z = 0;
//    float axis_x, axis_y, axis_z;
    float delta_acc_x, delta_acc_y, delta_acc_z;
    //float time_interval = 1.0f / ACC_ODR; // Time interval between samples
    float time_interval = 1.0f / 1365.33334; // Time interval between samples
    dataRms->Sum_sqrt_X = 0;
    dataRms->Sum_sqrt_Y = 0;
    dataRms->Sum_sqrt_Z = 0;

    for (inx = 1; inx < sample_size; inx++) {
        // Calculate change in acceleration (delta acceleration)
        delta_acc_x = (axes+inx)->x - (axes+inx-1)->x;
        delta_acc_y = (axes+inx)->y - (axes+inx-1)->y;
        delta_acc_z = (axes+inx)->z - (axes+inx-1)->z;
        delta_acc_x /=1000.0f;
        delta_acc_y /=1000.0f;
        delta_acc_z /=1000.0f;
        delta_acc_x *= GRAVITATIONAL_ACCELERATION;
        delta_acc_y *= GRAVITATIONAL_ACCELERATION;
        delta_acc_z *= GRAVITATIONAL_ACCELERATION;
//        delta_acc_x = ((float)axes[inx].x - (float)axes[inx - 1].x) / 1000.0f * GRAVITATIONAL_ACCELERATION;
//        delta_acc_y = ((float)axes[inx].y - (float)axes[inx - 1].y) / 1000.0f * GRAVITATIONAL_ACCELERATION;
//        delta_acc_z = ((float)axes[inx].z - (float)axes[inx - 1].z) / 1000.0f * GRAVITATIONAL_ACCELERATION;


        // Apply noise threshold to avoid integrating small noise values
        if (fabs(delta_acc_x) > NOISE_THRESHOLD) {
            velocity_x = prev_velocity_x + delta_acc_x * time_interval;
            prev_velocity_x = velocity_x;
        }
        if (fabs(delta_acc_y) > NOISE_THRESHOLD) {
            velocity_y = prev_velocity_y + delta_acc_y * time_interval;
            prev_velocity_y = velocity_y;
        }
        if (fabs(delta_acc_z) > NOISE_THRESHOLD) {
            velocity_z = prev_velocity_z + delta_acc_z * time_interval;
            prev_velocity_z = velocity_z;
        }

        // Sum of squares for RMS calculation
        dataRms->Sum_sqrt_X += velocity_x * velocity_x;
        dataRms->Sum_sqrt_Y += velocity_y * velocity_y;
        dataRms->Sum_sqrt_Z += velocity_z * velocity_z;
    }

    // Calculate RMS velocity
    dataRms->x = sqrt(dataRms->Sum_sqrt_X / (sample_size - 1));
    dataRms->y = sqrt(dataRms->Sum_sqrt_Y / (sample_size - 1));
    dataRms->z = sqrt(dataRms->Sum_sqrt_Z / (sample_size - 1));
}
