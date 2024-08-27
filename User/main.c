#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "time.h"
#include "math.h"
#include "MPU6050.h"
#include "Servo.h"


int16_t AX , AY , AZ , GX , GY , GZ;
int16_t Yaw , Pitch , Roll;
int16_t accAngleX , accAngleY , gyroAngleX , gyroAngleY , gyroAngleZ;


void CalculateYRP(int16_t AccX ,int16_t AccY ,int16_t AccZ ,int16_t GyroX ,int16_t GyroY ,int16_t GyroZ)
{
	AccX = AccX / 16384;
	AccY = AccY / 16384;
	AccZ = AccZ / 16384;
	GyroX /= 1310;
	GyroY /= 1310;
	GyroZ /= 1310;
	
	Yaw = Yaw + GyroZ;
	Roll = Roll + GyroX;
	Pitch = Pitch + GyroY;
	
}
int main(void)
{
	OLED_Init();
	MPU6050_Init();
	Servo_Init();
	
	//MPU6050_WirteReg(0x6B , 0x00); //解除睡眠才能写入
	
	while(1)
	{

		MPU6050_GetData(&AX , &AY , &AZ , &GX , &GY , &GZ);
		CalculateYRP(AX , AY , AZ , GX , GY , GZ);
		OLED_ShowSignedNum(2 , 1 , Roll , 5);
		OLED_ShowSignedNum(3 , 1 , Pitch , 5);
		OLED_ShowSignedNum(4 , 1 , Yaw , 5);
		OLED_ShowSignedNum(2 , 8 , GX , 5);
		OLED_ShowSignedNum(3 , 8 , GY , 5);
		OLED_ShowSignedNum(4 , 8 , GZ , 5);
		
		Servo_SetAngle(Yaw);
		
		Delay_ms(100);
	}
}
