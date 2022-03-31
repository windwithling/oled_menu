#ifndef __EXTI_H
#define	__EXTI_H

#include "stm32f4xx.h"

//Òý½Å¶¨Òå
/*******************************************************/
#define KEY1_INT_GPIO_PORT                GPIOD
#define KEY1_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define KEY1_INT_GPIO_PIN                 GPIO_Pin_1
#define KEY1_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOD
#define KEY1_INT_EXTI_PINSOURCE           EXTI_PinSource1
#define KEY1_INT_EXTI_LINE                EXTI_Line1
#define KEY1_INT_EXTI_IRQ                 EXTI1_IRQn
#define KEY1_IRQHandler                   EXTI1_IRQHandler
/*******************************************************/
#define KEY2_INT_GPIO_PORT                GPIOD
#define KEY2_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define KEY2_INT_GPIO_PIN                 GPIO_Pin_2
#define KEY2_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOD
#define KEY2_INT_EXTI_PINSOURCE           EXTI_PinSource2
#define KEY2_INT_EXTI_LINE                EXTI_Line2
#define KEY2_INT_EXTI_IRQ                 EXTI2_IRQn
#define KEY2_IRQHandler                   EXTI2_IRQHandler
/*******************************************************/
#define KEY3_INT_GPIO_PORT                GPIOD
#define KEY3_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define KEY3_INT_GPIO_PIN                 GPIO_Pin_3
#define KEY3_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOD
#define KEY3_INT_EXTI_PINSOURCE           EXTI_PinSource3
#define KEY3_INT_EXTI_LINE                EXTI_Line3
#define KEY3_INT_EXTI_IRQ                 EXTI3_IRQn
#define KEY3_IRQHandler                   EXTI3_IRQHandler
/*******************************************************/
#define KEY4_INT_GPIO_PORT                GPIOD
#define KEY4_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define KEY4_INT_GPIO_PIN                 GPIO_Pin_4
#define KEY4_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOD
#define KEY4_INT_EXTI_PINSOURCE           EXTI_PinSource4
#define KEY4_INT_EXTI_LINE                EXTI_Line4
#define KEY4_INT_EXTI_IRQ                 EXTI4_IRQn
#define KEY4_IRQHandler                   EXTI4_IRQHandler

/*******************************************************/


void EXTI_Key_Config(void);

#endif /* __EXTI_H */
