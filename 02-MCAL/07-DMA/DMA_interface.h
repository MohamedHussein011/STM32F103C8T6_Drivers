/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

//channels for DMA1
#define DMA_CHANNEL1			0
#define DMA_CHANNEL2			1
#define DMA_CHANNEL3			2
#define DMA_CHANNEL4			3
#define DMA_CHANNEL5			4
#define DMA_CHANNEL6			5
#define DMA_CHANNEL7			6

//interrupts flags
#define DMA_CGIF				0			// Channel x global interrupt flag
#define DMA_CTCIF				1			// Channel x transfer complete flag
#define DMA_CHTIF				2			//Channel x half transfer flag
#define DMA_CTEIF				3			//Channel x transfer error flag

void DMA_voidChannelInit(void);

void DMA_voidEnableChannel (u8 Copy_u8ChannelID);
void DMA_voidDisableChannel (u8 Copy_u8ChannelID);

void DMA_voidChannelRequest (u8 Copy_u8ChannelID, u32* Copy_pu32MemoryAddress, u32* Copy_pu32PeripheralAddress, u16 Copy_u16BlockLength);

void DMA_voidEnableInterrupt (u8 Copy_u8ChannelID, u8 Copy_u8InterruptID);
void DMA_voidDisableInterrupt (u8 Copy_u8ChannelID, u8 Copy_u8InterruptID);

u8 DMA_voidGetFlag (u8 Copy_u8ChannelID, u8 Copy_u8Flag);
void DMA_voidClearFlag (u8 Copy_u8ChannelID, u8 Copy_u8Flag);

void DMA_voidSetCallBack (u8 Copy_u8ChannelID, void (*pvCOPY_FUNC) (void));

#endif
