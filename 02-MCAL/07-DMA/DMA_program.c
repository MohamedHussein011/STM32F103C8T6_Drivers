/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

//global static pointer to function for ISR
void (*pvDMA_FUNC[7]) (void) = {NULL};

void DMA_voidChannelInit(void)
{
#if defined DMA_CHAN1
	//Disable the channel first
	CLR_BIT(M_DMA->CHANNEL[0].DMA_CCR, 0);

	M_DMA->CHANNEL[0].DMA_CCR = (0x00000000) | ( (DMA_MEM_TO_MEM_MODE1 << 14) | (DMA_CHANNEL_PRIORITY1 << 12)
			| (DMA_MEMORY_SIZE1 << 10) | (DMA_PERIPHERAL_SIZE1 << 8) | (DMA_MEM_INCREMENT_MODE1 << 7)
			| (DMA_PER_INCREMENT_MODE1  << 6) | (DMA_CIRCULAR_MODE1 << 5) | (DMA_DATA_TRANSFER1 << 4)
			| (DMA_TRANS_ERROR_INTERRUPT1 << 3) | (DMA_TRANS_HALF_INTERRUPT1 << 2)
			| (DMA_TRANS_COMP_INTERRUPT1 << 1) );
#endif

#if defined DMA_CHAN2
	//Disable the channel first
	CLR_BIT(M_DMA->CHANNEL[1].DMA_CCR, 0);

	M_DMA->CHANNEL[1].DMA_CCR = (0x00000000) | ( (DMA_MEM_TO_MEM_MODE2 << 14) | (DMA_CHANNEL_PRIORITY2 << 12)
			| (DMA_MEMORY_SIZE2 << 10) | (DMA_PERIPHERAL_SIZE2 << 8) | (DMA_MEM_INCREMENT_MODE2 << 7)
			| (DMA_PER_INCREMENT_MODE2  << 6) | (DMA_CIRCULAR_MODE2 << 5) | (DMA_DATA_TRANSFER2 << 4)
			| (DMA_TRANS_ERROR_INTERRUPT2 << 3) | (DMA_TRANS_HALF_INTERRUPT2 << 2)
			| (DMA_TRANS_COMP_INTERRUPT2 << 1) );
#endif

#if defined DMA_CHAN3
	//Disable the channel first
	CLR_BIT(M_DMA->CHANNEL[2].DMA_CCR, 0);

	M_DMA->CHANNEL[2].DMA_CCR = (0x00000000) | ( (DMA_MEM_TO_MEM_MODE3 << 14) | (DMA_CHANNEL_PRIORITY3 << 12)
			| (DMA_MEMORY_SIZE3 << 10) | (DMA_PERIPHERAL_SIZE3 << 8) | (DMA_MEM_INCREMENT_MODE3 << 7)
			| (DMA_PER_INCREMENT_MODE3  << 6) | (DMA_CIRCULAR_MODE3 << 5) | (DMA_DATA_TRANSFER3 << 4)
			| (DMA_TRANS_ERROR_INTERRUPT3 << 3) | (DMA_TRANS_HALF_INTERRUPT3 << 2)
			| (DMA_TRANS_COMP_INTERRUPT3 << 1) );
#endif

#if defined DMA_CHAN4
	//Disable the channel first
	CLR_BIT(M_DMA->CHANNEL[3].DMA_CCR, 0);

	M_DMA->CHANNEL[3].DMA_CCR = (0x00000000) | ( (DMA_MEM_TO_MEM_MODE4 << 14) | (DMA_CHANNEL_PRIORITY4 << 12)
			| (DMA_MEMORY_SIZE4 << 10) | (DMA_PERIPHERAL_SIZE4 << 8) | (DMA_MEM_INCREMENT_MODE4 << 7)
			| (DMA_PER_INCREMENT_MODE4  << 6) | (DMA_CIRCULAR_MODE4 << 5) | (DMA_DATA_TRANSFER4 << 4)
			| (DMA_TRANS_ERROR_INTERRUPT4 << 3) | (DMA_TRANS_HALF_INTERRUPT4 << 2)
			| (DMA_TRANS_COMP_INTERRUPT4 << 1) );
#endif

#if defined DMA_CHAN5
	//Disable the channel first
	CLR_BIT(M_DMA->CHANNEL[4].DMA_CCR, 0);

	M_DMA->CHANNEL[4].DMA_CCR = (0x00000000) | ( (DMA_MEM_TO_MEM_MODE5 << 14) | (DMA_CHANNEL_PRIORITY5 << 12)
			| (DMA_MEMORY_SIZE5 << 10) | (DMA_PERIPHERAL_SIZE5 << 8) | (DMA_MEM_INCREMENT_MODE5 << 7)
			| (DMA_PER_INCREMENT_MODE5  << 6) | (DMA_CIRCULAR_MODE5 << 5) | (DMA_DATA_TRANSFER5 << 4)
			| (DMA_TRANS_ERROR_INTERRUPT5 << 3) | (DMA_TRANS_HALF_INTERRUPT5 << 2)
			| (DMA_TRANS_COMP_INTERRUPT5 << 1) );
#endif

#if defined DMA_CHAN6
	//Disable the channel first
	CLR_BIT(M_DMA->CHANNEL[5].DMA_CCR, 0);

	M_DMA->CHANNEL[5].DMA_CCR = (0x00000000) | ( (DMA_MEM_TO_MEM_MODE6 << 14) | (DMA_CHANNEL_PRIORITY6 << 12)
			| (DMA_MEMORY_SIZE6 << 10) | (DMA_PERIPHERAL_SIZE6 << 8) | (DMA_MEM_INCREMENT_MODE6 << 7)
			| (DMA_PER_INCREMENT_MODE6  << 6) | (DMA_CIRCULAR_MODE6 << 5) | (DMA_DATA_TRANSFER6 << 4)
			| (DMA_TRANS_ERROR_INTERRUPT6 << 3) | (DMA_TRANS_HALF_INTERRUPT6 << 2)
			| (DMA_TRANS_COMP_INTERRUPT6 << 1) );
#endif

#if defined DMA_CHAN7
	//Disable the channel first
	CLR_BIT(M_DMA->CHANNEL[6].DMA_CCR, 0);

	M_DMA->CHANNEL[6].DMA_CCR = (0x00000000) | ( (DMA_MEM_TO_MEM_MODE7 << 14) | (DMA_CHANNEL_PRIORITY7 << 12)
			| (DMA_MEMORY_SIZE7 << 10) | (DMA_PERIPHERAL_SIZE7 << 8) | (DMA_MEM_INCREMENT_MODE7 << 7)
			| (DMA_PER_INCREMENT_MODE7  << 6) | (DMA_CIRCULAR_MODE7 << 5) | (DMA_DATA_TRANSFER7 << 4)
			| (DMA_TRANS_ERROR_INTERRUPT7 << 3) | (DMA_TRANS_HALF_INTERRUPT7 << 2)
			| (DMA_TRANS_COMP_INTERRUPT7 << 1) );
#endif

}

void DMA_voidEnableChannel (u8 Copy_u8ChannelID)
{
	/*clear all flags first*/
	DMA_voidClearFlag(Copy_u8ChannelID, DMA_CGIF);					//Channel global interrupt clear
	DMA_voidClearFlag(Copy_u8ChannelID, DMA_CTCIF);					//Channel transfer complete clear
	DMA_voidClearFlag(Copy_u8ChannelID, DMA_CHTIF);					//Channel half transfer clear
	DMA_voidClearFlag(Copy_u8ChannelID, DMA_CTEIF);					//Channel transfer error clear

	//Enable the channel
	SET_BIT(M_DMA->CHANNEL[Copy_u8ChannelID].DMA_CCR, 0);
}

void DMA_voidDisableChannel (u8 Copy_u8ChannelID)
{
	//Disable the channel
	CLR_BIT(M_DMA->CHANNEL[Copy_u8ChannelID].DMA_CCR, 0);
}

void DMA_voidChannelRequest (u8 Copy_u8ChannelID, u32* Copy_pu32MemoryAddress, u32* Copy_pu32PeripheralAddress, u16 Copy_u16BlockLength)
{
	M_DMA->CHANNEL[Copy_u8ChannelID].DMA_CNDTR = Copy_u16BlockLength;
	M_DMA->CHANNEL[Copy_u8ChannelID].DMA_CPAR = (u32) Copy_pu32PeripheralAddress;
	M_DMA->CHANNEL[Copy_u8ChannelID].DMA_CMAR = (u32) Copy_pu32MemoryAddress;
}

void DMA_voidEnableInterrupt (u8 Copy_u8ChannelID, u8 Copy_u8InterruptID)
{
	SET_BIT(M_DMA->CHANNEL[Copy_u8ChannelID].DMA_CCR, Copy_u8InterruptID);
}

void DMA_voidDisableInterrupt (u8 Copy_u8ChannelID, u8 Copy_u8InterruptID)
{
	CLR_BIT(M_DMA->CHANNEL[Copy_u8ChannelID].DMA_CCR, Copy_u8InterruptID);
}

u8 DMA_voidGetFlag (u8 Copy_u8ChannelID, u8 Copy_u8Flag)
{
	return (GET_BIT(M_DMA->DMA_IFCR, ((Copy_u8ChannelID * 4) + Copy_u8Flag)));
}

void DMA_voidClearFlag (u8 Copy_u8ChannelID, u8 Copy_u8Flag)
{
	CLR_BIT(M_DMA->DMA_IFCR, ((Copy_u8ChannelID * 4) + Copy_u8Flag));
}

void DMA_voidSetCallBack (u8 Copy_u8ChannelID, void (*pvCOPY_FUNC) (void))
{
	pvDMA_FUNC[Copy_u8ChannelID] = pvCOPY_FUNC;
}

/**************************************** ISR ***************************************************/
void DMA1_Channel1_IRQHandler (void)
{
	DMA_voidDisableChannel(DMA_CHANNEL1);
	DMA_voidClearFlag(DMA_CHANNEL1,DMA_CGIF);
	DMA_voidClearFlag(DMA_CHANNEL1,DMA_CTCIF);
	DMA_voidClearFlag(DMA_CHANNEL1,DMA_CHTIF);
	DMA_voidClearFlag(DMA_CHANNEL1,DMA_CTEIF);
	DMA_voidDisableInterrupt(DMA_CHANNEL1,DMA_CTCIF);
	DMA_voidDisableInterrupt(DMA_CHANNEL1,DMA_CHTIF);
	DMA_voidDisableInterrupt(DMA_CHANNEL1,DMA_CTEIF);
	pvDMA_FUNC[DMA_CHANNEL1]();
}

void DMA1_Channel2_IRQHandler (void)
{
	DMA_voidDisableChannel(DMA_CHANNEL2);
	DMA_voidClearFlag(DMA_CHANNEL2,DMA_CGIF);
	DMA_voidClearFlag(DMA_CHANNEL2,DMA_CTCIF);
	DMA_voidClearFlag(DMA_CHANNEL2,DMA_CHTIF);
	DMA_voidClearFlag(DMA_CHANNEL2,DMA_CTEIF);
	DMA_voidDisableInterrupt(DMA_CHANNEL2,DMA_CTCIF);
	DMA_voidDisableInterrupt(DMA_CHANNEL2,DMA_CHTIF);
	DMA_voidDisableInterrupt(DMA_CHANNEL2,DMA_CTEIF);
	pvDMA_FUNC[DMA_CHANNEL2]();
}

void DMA1_Channel3_IRQHandler (void)
{
	DMA_voidDisableChannel(DMA_CHANNEL3);
	DMA_voidClearFlag(DMA_CHANNEL3,DMA_CGIF);
	DMA_voidClearFlag(DMA_CHANNEL3,DMA_CTCIF);
	DMA_voidClearFlag(DMA_CHANNEL3,DMA_CHTIF);
	DMA_voidClearFlag(DMA_CHANNEL3,DMA_CTEIF);
	pvDMA_FUNC[DMA_CHANNEL3]();
}

void DMA1_Channel4_IRQHandler (void)
{
	DMA_voidDisableChannel(DMA_CHANNEL4);
	DMA_voidClearFlag(DMA_CHANNEL4,DMA_CGIF);
	DMA_voidClearFlag(DMA_CHANNEL4,DMA_CTCIF);
	DMA_voidClearFlag(DMA_CHANNEL4,DMA_CHTIF);
	DMA_voidClearFlag(DMA_CHANNEL4,DMA_CTEIF);
	pvDMA_FUNC[DMA_CHANNEL4]();
}

void DMA1_Channel5_IRQHandler (void)
{
	DMA_voidDisableChannel(DMA_CHANNEL5);
	DMA_voidClearFlag(DMA_CHANNEL5,DMA_CGIF);
	DMA_voidClearFlag(DMA_CHANNEL5,DMA_CTCIF);
	DMA_voidClearFlag(DMA_CHANNEL5,DMA_CHTIF);
	DMA_voidClearFlag(DMA_CHANNEL5,DMA_CTEIF);
	pvDMA_FUNC[DMA_CHANNEL5]();
}

void DMA1_Channel6_IRQHandler (void)
{
	DMA_voidDisableChannel(DMA_CHANNEL6);
	DMA_voidClearFlag(DMA_CHANNEL6,DMA_CGIF);
	DMA_voidClearFlag(DMA_CHANNEL6,DMA_CTCIF);
	DMA_voidClearFlag(DMA_CHANNEL6,DMA_CHTIF);
	DMA_voidClearFlag(DMA_CHANNEL6,DMA_CTEIF);
	pvDMA_FUNC[DMA_CHANNEL6]();
}

void DMA1_Channel7_IRQHandler (void)
{
	DMA_voidDisableChannel(DMA_CHANNEL7);
	DMA_voidClearFlag(DMA_CHANNEL7,DMA_CGIF);
	DMA_voidClearFlag(DMA_CHANNEL7,DMA_CTCIF);
	DMA_voidClearFlag(DMA_CHANNEL7,DMA_CHTIF);
	DMA_voidClearFlag(DMA_CHANNEL7,DMA_CTEIF);
	pvDMA_FUNC[DMA_CHANNEL7]();
}
