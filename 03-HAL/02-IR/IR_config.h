/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 24/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef IR_CONFIG_H
#define IR_CONFIG_H

//define input port,pin from IR receiver & external interrupt line
#define IR_PORT				GPIOA
#define IR_PIN				GPIO_PIN0
#define IR_EXTI             EXTI_LINE0

/*define SysTick clock MHz*/
#define IR_SysTick_Clock			8

/*define Time for frame*/
#define IR_FRAME_TIME			300000UL

#endif
