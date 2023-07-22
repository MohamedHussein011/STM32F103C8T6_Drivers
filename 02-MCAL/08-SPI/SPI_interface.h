/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

//FOR SPI1
void SPI_voidInit(void);

void SPI_voidSendReceiveSynch (u16 Copy_u16DataToSend, u16* Copy_u16DataToReceive);
void SPI_voidSendReceiveAsynch (u16 Copy_u16DataToSend, void(*Copy_pvFunc)(u16));

#endif
