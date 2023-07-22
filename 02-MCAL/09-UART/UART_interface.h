/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

//UART1
void UART_voidInit(void);

void UART_voidTransmitByte(u8 Copy_pchData);
void UART_voidTransmitDataSynch(u8* Copy_pchData);
void UART_voidTransmitDataAsynch(u8* Copy_pchData, void(*Copy_Func)(void));

void UART_voidReceiveByte(u8* Copy_pu8Data);
void UART_voidReceiveDataBufferSynch(u8* Copy_pchData, u8 Copy_u8BufferSize);
void UART_voidReceiveDataBufferAsynch(u8* Copy_pchData, u8 Copy_u8BufferSize, void(*Copy_Func)(void));
//press tab button to send string
void UART_voidReceiveStringSynch(u8* Copy_pchData);

#endif
