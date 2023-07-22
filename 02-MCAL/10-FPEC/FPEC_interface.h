/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 25/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

void FPEC_voidEraseAppArea (void);
void FPEC_voidFlashPageErase (u8 Copy_u8PageNumber);
void FPEC_voidFlashWriteHalfWord (u32 Copy_u32Address, u16* Copy_pu16Data, u8 Copy_u8Length);

#endif
