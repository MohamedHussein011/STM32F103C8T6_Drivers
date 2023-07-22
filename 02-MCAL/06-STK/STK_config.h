/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/* options:
* 1: STK_AHB_CLK
* 2: STK_AHB_DIVBY8_CLK
*/
#define STK_CLKSOURCE        STK_AHB_CLK 

//write RCC AHB clock
#define STK_RCC_AHB_CLK            8

#endif