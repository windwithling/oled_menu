
  
#include "./key/bsp_exti.h"

 /**
  * @brief  配置嵌套向量中断控制器NVIC
  * @param  无
  * @retval 无
  */
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* 配置NVIC为优先级组1 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* 配置中断源：按键1 */
  NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
  /* 配置抢占优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 配置子优先级：1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* 使能中断通道 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /* 配置中断源：按键2，其他使用上面相关配置 */  
  NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
  NVIC_Init(&NVIC_InitStructure);
	
  NVIC_InitStructure.NVIC_IRQChannel = KEY3_INT_EXTI_IRQ;
  NVIC_Init(&NVIC_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = KEY4_INT_EXTI_IRQ;
  NVIC_Init(&NVIC_InitStructure);
}

 /**
  * @brief  配置 PA0 为线中断口，并设置中断优先级
  * @param  无
  * @retval 无
  */
void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;
  
	RCC_AHB1PeriphClockCmd(KEY1_INT_GPIO_CLK|KEY2_INT_GPIO_CLK|KEY3_INT_GPIO_CLK|KEY4_INT_GPIO_CLK ,ENABLE);
  
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);/* 使能 SYSCFG 时钟 ，使用GPIO外部中断时必须使能SYSCFG时钟*/

	NVIC_Configuration();
	
	/* 按键1*/ 
	GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	    		
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure); 
	
	SYSCFG_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,KEY1_INT_EXTI_PINSOURCE);/* 连接 EXTI 中断源 到key1引脚 */
	
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;/* 选择 EXTI 中断源 */	
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;/* 中断模式 */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	  
	/* 按键2*/ 
	GPIO_InitStructure.GPIO_Pin = KEY2_INT_GPIO_PIN;  
	GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);      

	SYSCFG_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE,KEY2_INT_EXTI_PINSOURCE);

	EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/* 按键3*/ 
	GPIO_InitStructure.GPIO_Pin = KEY3_INT_GPIO_PIN;  
	GPIO_Init(KEY3_INT_GPIO_PORT, &GPIO_InitStructure);      

	SYSCFG_EXTILineConfig(KEY3_INT_EXTI_PORTSOURCE,KEY3_INT_EXTI_PINSOURCE);

	EXTI_InitStructure.EXTI_Line = KEY3_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/* 按键4*/ 
	GPIO_InitStructure.GPIO_Pin = KEY4_INT_GPIO_PIN;  
	GPIO_Init(KEY4_INT_GPIO_PORT, &GPIO_InitStructure);      

	SYSCFG_EXTILineConfig(KEY4_INT_EXTI_PORTSOURCE,KEY4_INT_EXTI_PINSOURCE);

	EXTI_InitStructure.EXTI_Line = KEY4_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	
 
}
/*********************************************END OF FILE**********************/
