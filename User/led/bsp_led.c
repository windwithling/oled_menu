
  
#include "bsp_led.h"  

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void){
	
	GPIO_InitTypeDef GPIO_InitStructure;
		
	RCC_AHB1PeriphClockCmd ( LED1_GPIO_CLK, ENABLE); 
															   
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 

	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
   		
	LED1_OFF;		
}


/*********************************************END OF FILE**********************/
