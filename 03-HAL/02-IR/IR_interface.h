/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 24/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

//buttons values on my remote
#define IR_OFF 				69
#define IR_0 				22
#define IR_1				12
#define IR_2 				24
#define IR_3				94
#define IR_4				8
#define IR_5 				28
#define IR_6 				90
#define IR_7				66
#define IR_8				82
#define IR_9				74



void IR_voidInit(void);
void IR_voidTakeAction (u8 Copy_u8Button, void (*Copy_pvFunc) (void));

#endif