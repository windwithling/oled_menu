#ifndef __LED_H
#define	__LED_H

#include "stm32f4xx.h"

#define LED1_PIN                  GPIO_Pin_13                 
#define LED1_GPIO_PORT            GPIOC                      
#define LED1_GPIO_CLK             RCC_AHB1Periph_GPIOC


/*led on when output=0*/
#define ON  0
#define OFF 1


#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_PIN)

#define	digitalHi(p,i)			 {p->BSRRL=i;}		//set to be high
#define digitalLo(p,i)			 {p->BSRRH=i;}		//set to be low
#define digitalToggle(p,i)	     {p->ODR ^=i;}		//reverse

/*io control define*/
#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF			digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON				digitalLo(LED1_GPIO_PORT,LED1_PIN)


void LED_GPIO_Config(void);

#endif /* __LED_H */
