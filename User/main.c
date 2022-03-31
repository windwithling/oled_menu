#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "bsp_oled.h"
#include "usart1.h"
#include "mpu6050.h"
#include "inv_mpu.h"


void Delay(__IO u32 nCount); 


int main(void)
{
	
	OLED_Init();

	LED_GPIO_Config();

	EXTI_Key_Config(); 
	USART1_Config();

	while(1)		
	{
		//Show_Arrow(100,20);
		Show_GUI();
	}
}

/*********************************************END OF FILE**********************/

