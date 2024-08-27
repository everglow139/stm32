#ifndef __MPU6050_H
#define __MPU6050_H


void MPU6050_WirteReg(uint8_t RegAddress , uint8_t Data); //指定地址写;
uint8_t MPU6050_ReadReg(uint8_t RegAddress);
void MPU6050_Init(void);
void MPU6050_GetData(int16_t *AccX ,int16_t *AccY ,int16_t *AccZ ,int16_t *GyroX ,int16_t *GyroY ,int16_t *GyroZ);


#endif
