/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 22/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

void LEDMRX_voidInit    (void);
void LEDMRX_voidDisplayFrame (u8* Copy_pu8Frame);
void LEDMRX_voidStop (void);

#endif