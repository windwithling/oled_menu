#ifndef __OLED_H
#define __OLED_H 

#include "stm32f4xx.h"
#include "stdlib.h"	


#define u8 unsigned char
#define u32 unsigned int
	
/*状态变量定义*/
extern u8 CHOOSE_STATE;
extern u8 MENU_FLAG;
extern u8 CONFIRM_FLAG;
extern u8 RETURN_FLAG;
extern u8 STATE;


#define STATE_MPU_INIT 0  //正在初始化
#define STATE_MPU_ERROR 1 //初始化失败
#define STATE_MPU_SUCCESS 2 //初始化成功
#define STATE_MPU_SHOW 3 //显示数据

/*显示内容声明*/
extern unsigned char string1[];
extern unsigned char string2[];


//-----------------OLED端口定义----------------

#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOC,GPIO_Pin_4)//SCL
#define OLED_SCLK_Set() GPIO_SetBits(GPIOC,GPIO_Pin_4)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOC,GPIO_Pin_5)//DIN
#define OLED_SDIN_Set() GPIO_SetBits(GPIOC,GPIO_Pin_5)



#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void OLED_WR_Byte(u8 dat,u8 cmd);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);

void OLED_Clear(void);
void OLED_Clear_diy(int speed);

void OLED_DrawPoint(u8 x,u8 y);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1);
void OLED_ScrollDisplay(u8 num,u8 space);
void OLED_WR_BP(u8 x,u8 y);
void OLED_ShowPicture(u8 x0,u8 y0,u8 x1,u8 y1,u8 BMP[]);
void OLED_Init(void);
void Show_GUI(void);
void Show_Arrow(u8 x,u8 y);
void Show_MENU(void);

#endif


