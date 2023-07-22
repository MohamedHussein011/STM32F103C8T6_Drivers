/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* External Interrupt Line select*/
#define EXTI_LINE0                        0
#define EXTI_LINE1                        1
#define EXTI_LINE2                        2
#define EXTI_LINE3                        3
#define EXTI_LINE4                        4
#define EXTI_LINE5                        5
#define EXTI_LINE6                        6
#define EXTI_LINE7                        7
#define EXTI_LINE8                        8
#define EXTI_LINE9                        9
#define EXTI_LINE10                       10
#define EXTI_LINE11                       11
#define EXTI_LINE12                       12
#define EXTI_LINE13                       13
#define EXTI_LINE14                       14
#define EXTI_LINE15                       15

/* External Interrupt Mode select*/ 
#define   EXTI_RISING_EDGE                0
#define   EXTI_FALLING_EDGE               1
#define   EXTI_ON_CHANGE                  2

void EXTI_voidEnable (u8 Copy_u8Line);
void EXTI_voidDisable (u8 Copy_u8Line);
void EXTI_voidSoftwareTrigger (u8 Copy_u8Line);
void EXTI_voidSetMode (u8 Copy_u8Line, u8 Copy_u8Mode);
void EXTI_voidSetCallback (u8 Copy_u8Line, void (*Copy_pvFunc)(void));

#endif
