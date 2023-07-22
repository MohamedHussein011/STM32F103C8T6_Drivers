/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 01/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

void STP_voidInit(void);
void STP_voidSendByteSynchronus (u8 Copy_u8Data);
void STP_voidSendHalfWordSynchronus (u16 Copy_u16Data);
void STP_voidSendWordSynchronus (u32 Copy_u32Data);

#endif