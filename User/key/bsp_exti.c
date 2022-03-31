
  
#include "./key/bsp_exti.h"

 /**
  * @brief  ����Ƕ�������жϿ�����NVIC
  * @param  ��
  * @retval ��
  */
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* ����NVICΪ���ȼ���1 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* �����ж�Դ������1 */
  NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
  /* ������ռ���ȼ���1 */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* ���������ȼ���1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ʹ���ж�ͨ�� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /* �����ж�Դ������2������ʹ������������� */  
  NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
  NVIC_Init(&NVIC_InitStructure);
	
  NVIC_InitStructure.NVIC_IRQChannel = KEY3_INT_EXTI_IRQ;
  NVIC_Init(&NVIC_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = KEY4_INT_EXTI_IRQ;
  NVIC_Init(&NVIC_InitStructure);
}

 /**
  * @brief  ���� PA0 Ϊ���жϿڣ��������ж����ȼ�
  * @param  ��
  * @retval ��
  */
void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;
  
	RCC_AHB1PeriphClockCmd(KEY1_INT_GPIO_CLK|KEY2_INT_GPIO_CLK|KEY3_INT_GPIO_CLK|KEY4_INT_GPIO_CLK ,ENABLE);
  
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);/* ʹ�� SYSCFG ʱ�� ��ʹ��GPIO�ⲿ�ж�ʱ����ʹ��SYSCFGʱ��*/

	NVIC_Configuration();
	
	/* ����1*/ 
	GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	    		
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure); 
	
	SYSCFG_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,KEY1_INT_EXTI_PINSOURCE);/* ���� EXTI �ж�Դ ��key1���� */
	
	EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;/* ѡ�� EXTI �ж�Դ */	
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;/* �ж�ģʽ */
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	  
	/* ����2*/ 
	GPIO_InitStructure.GPIO_Pin = KEY2_INT_GPIO_PIN;  
	GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);      

	SYSCFG_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE,KEY2_INT_EXTI_PINSOURCE);

	EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/* ����3*/ 
	GPIO_InitStructure.GPIO_Pin = KEY3_INT_GPIO_PIN;  
	GPIO_Init(KEY3_INT_GPIO_PORT, &GPIO_InitStructure);      

	SYSCFG_EXTILineConfig(KEY3_INT_EXTI_PORTSOURCE,KEY3_INT_EXTI_PINSOURCE);

	EXTI_InitStructure.EXTI_Line = KEY3_INT_EXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/* ����4*/ 
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
