/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11//2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct
{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL ;
	volatile u32 STK_CALIB;
}STK_t;

#define M_STK          ((volatile STK_t*) 0xE000E010)

/* options:
* 1: STK_AHB_CLK
* 2: STK_AHB_DIVBY8_CLK
*/
#define STK_AHB_CLK                      0
#define STK_AHB_DIVBY8_CLK               1

#define STK_SINGLE					0
#define STK_PERIODIC				1


#endif