/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 24/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H

/*define SysTick clock
*options:
*		1: IR_SysTick_AHB
*		2: IR_SysTick_AHB_DivBy8
*/
#define IR_SysTick_AHB					0
#define IR_SysTick_AHB_DivBy8			1


static void IR_voidGetFrame (void);
static void IR_voidEstimateData (void);

#endif
