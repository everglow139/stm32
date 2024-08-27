#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "OLED.h"
void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngle(int16_t Angle)
{
	
	if(Angle < 0)
	{
		Angle = - Angle;
	}
	OLED_ShowSignedNum(1 ,1 ,(Angle * 2000 / 180) + 500,5);
	float final = (Angle * 2000 / 180) + 500;
	PWM_SetCompare2(final);
}
