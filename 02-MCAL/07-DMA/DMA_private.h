/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 DMA_CCR;
	volatile u32 DMA_CNDTR;
	volatile u32 DMA_CPAR;
	volatile u32 DMA_CMAR;
	volatile u32 reserved;
}DMA_CHANNEL_t;

typedef struct
{
	volatile u32 DMA_ISR;
	volatile u32 DMA_IFCR;
	DMA_CHANNEL_t CHANNEL[7];
}DMA_t;

#define M_DMA				((volatile DMA_t*) 0x40020000)		//DMA1


#endif