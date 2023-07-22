/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "CAN_interface.h"
#include "CAN_private.h"
#include "CAN_config.h"

void CAN1_voidInit (void)
{
	//first exit SLEEP mode by clearing SLEEP bit in MCR
	CLR_BIT(CAN1_MCR, 1);
	//loop until it exits
	while(GET_BIT(CAN1_MSR, 1) != 0);

	//enter INIT mode by setting INRQ bit in MCR
	SET_BIT(CAN1_MCR, 0);
	//loop until INIT ACK
	while(GET_BIT(CAN1_MSR, 0) != 1);

#if CAN1_DBF == CAN1_DISABLE
	CLR_BIT(CAN1_MCR, 16);
#elif CAN1_DBF == CAN1_ENABLE
	SET_BIT(CAN1_MCR, 16);
#endif

#if CAN1_TTCM == CAN1_DISABLE
	CLR_BIT(CAN1_MCR, 7);
#elif CAN1_TTCM == CAN1_ENABLE
	SET_BIT(CAN1_MCR, 7);
#endif

#if CAN1_ABOM == CAN1_SOFTWARE
	CLR_BIT(CAN1_MCR, 6);
#elif CAN1_ABOM == CAN1_HARDWARE
	SET_BIT(CAN1_MCR, 6);
#endif

#if CAN1_AWUM == CAN1_SOFTWARE
	CLR_BIT(CAN1_MCR, 5);
#elif CAN1_AWUM == CAN1_HARDWARE
	SET_BIT(CAN1_MCR, 5);
#endif

#if CAN1_NART == CAN1_DISABLE
	CLR_BIT(CAN1_MCR, 4);
#elif CAN1_NART == CAN1_ENABLE
	SET_BIT(CAN1_MCR, 4);
#endif

#if CAN1_RFLM == CAN1_DISABLE
	CLR_BIT(CAN1_MCR, 3);
#elif CAN1_RFLM == CAN1_ENABLE
	SET_BIT(CAN1_MCR, 3);
#endif

#if CAN1_TXFP == CAN1_ID_PRIORITY
	CLR_BIT(CAN1_MCR, 2);
#elif CAN1_TXFP == CAN1_REQ_PRIORITY
	SET_BIT(CAN1_MCR, 2);
#endif

	CAN1_BTR |= (CAN1_DBG_MODE << 30) | (CAN1_SJW << 24) | (CAN1_TS2 << 20) | (CAN1_TS1 << 16) | (CAN1_BRP);

	//clear INRQ bit in MCR to enter NORMAL mode
	CLR_BIT(CAN1_MCR, 0);
	//loop until INAK bit is cleared in MSR
	while(GET_BIT(CAN1_MSR, 0) != 0);

}

void CAN1_voidFilterInit (CAN1_FILTER_t* Copy_stFilter)
{
	//first enter the initialization mode
	SET_BIT(CAN1_FMR, 0);
	//must de-activate the filter
	CLR_BIT(CAN1_FA1R, Copy_stFilter->FILTER_NUM);

	//CAN filter mode
	CAN1_FM1R |= (Copy_stFilter->MODE << Copy_stFilter->FILTER_NUM);

	//CAN filter scale
	CAN1_FS1R |= (Copy_stFilter->SCALE << Copy_stFilter->FILTER_NUM);

	//CAN filter FIFO assignment
	CAN1_FFA1R |= (Copy_stFilter->FIFO_NUM << Copy_stFilter->FILTER_NUM);

	if(Copy_stFilter->SCALE == CAN1_SINGLE_32BIT)		//Single 32-bit scale configuration
	{
		CAN1_FiRx[Copy_stFilter->FILTER_NUM] = Copy_stFilter->ID;
		CAN1_FiRx[Copy_stFilter->FILTER_NUM + 1] = Copy_stFilter->MASK;
	}
	else if(Copy_stFilter->SCALE == CAN1_DUAL_16BIT)		//Dual 16-bit scale configuration
	{
		CAN1_FiRx[Copy_stFilter->FILTER_NUM] = (((u16)Copy_stFilter->ID) | (Copy_stFilter->MASK << 16));
		CAN1_FiRx[Copy_stFilter->FILTER_NUM + 1] = ((Copy_stFilter->ID >> 16) | (0xFFFF0000 * Copy_stFilter->MASK));
	}

	//activate the filter
	SET_BIT(CAN1_FA1R, Copy_stFilter->FILTER_NUM);
	//finally exit the initialization mode
	CLR_BIT(CAN1_FMR, 0);
}

void CAN1_voidTransmit (CAN1_TX_MSG_t* Copy_stMessage)
{
	u8 Local_u8TransmitMailbox = CAN1_NoTransmitMailbox;

	if (Copy_stMessage != NULL)
	{
		if(GET_BIT(CAN1_TSR, 26) == 1)		//means Transmit mailbox 0 empty
		{
			Local_u8TransmitMailbox = CAN1_TransmitMailbox0;
		}
		else if(GET_BIT(CAN1_TSR, 27) == 1)		//means Transmit mailbox 1 empty
		{
			Local_u8TransmitMailbox = CAN1_TransmitMailbox1;
		}
		else if(GET_BIT(CAN1_TSR, 28) == 1)		//means Transmit mailbox 2 empty
		{
			Local_u8TransmitMailbox = CAN1_TransmitMailbox2;
		}
		else
		{
			Local_u8TransmitMailbox = CAN1_NoTransmitMailbox;
		}

		if(Local_u8TransmitMailbox != CAN1_NoTransmitMailbox)
		{
			if(Copy_stMessage->IDE == CAN1_STID)
			{
				CLR_BIT(CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0], 2);
				CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0] &= ~(Copy_stMessage->STID << 21);
				CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0] |= (Copy_stMessage->STID << 21);
			}
			else if(Copy_stMessage->IDE == CAN1_EXTID)
			{
				SET_BIT(CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0], 2);
				CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0] &= ~(Copy_stMessage->EXTID << 3);
				CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0] |= (Copy_stMessage->EXTID << 3);
			}

			if(Copy_stMessage->RTR == CAN1_DATA)
			{
				CLR_BIT(CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0], 1);
			}
			else if(Copy_stMessage->RTR == CAN1_REMOTE)
			{
				SET_BIT(CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0], 1);
			}

			CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][1] &= ~(Copy_stMessage->DLC);
			CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][1] |= (Copy_stMessage->DLC);

			CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][2] |= (Copy_stMessage->MSG[0] | Copy_stMessage->MSG[1] << 8 |
					Copy_stMessage->MSG[2] << 16 | Copy_stMessage->MSG[3] << 24);
			CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][3] |= (Copy_stMessage->MSG[4] | Copy_stMessage->MSG[5] << 8 |
					Copy_stMessage->MSG[6] << 16 | Copy_stMessage->MSG[7] << 24);


			//start transmission
			SET_BIT(CAN1_TX->CAN1_TX_MAILBOX[Local_u8TransmitMailbox][0], 0);
		}

	}
}

void CAN1_voidReceive  (CAN1_RX_MSG_t* Copy_stMessage, u8 Copy_u8FIFOnumber)
{
	if(Copy_stMessage != NULL)
	{
		Copy_stMessage->IDE = (u8)(0x1 & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][0] >> 2));
		if(Copy_stMessage->IDE == CAN1_STID)
		{
			Copy_stMessage->STID = (u16)(0x7FF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][0] >> 21));
		}
		else if(Copy_stMessage->IDE == CAN1_EXTID)
		{
			Copy_stMessage->EXTID = (u32)(0x1FFFFFFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][0] >> 3));
		}

		Copy_stMessage->RTR = (u8)(0x1 & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][0] >> 1));
		Copy_stMessage->DLC = (u8)(0xF & CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][1]);
		Copy_stMessage->FMI = (u8)(0xFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][1] >> 8));

		Copy_stMessage->MSG[0] = (u8)(0xFF & CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][2]);
		Copy_stMessage->MSG[1] = (u8)(0xFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][2] >> 8));
		Copy_stMessage->MSG[2] = (u8)(0xFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][2] >> 16));
		Copy_stMessage->MSG[3] = (u8)(0xFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][2] >> 24));
		Copy_stMessage->MSG[4] = (u8)(0xFF & CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][3]);
		Copy_stMessage->MSG[5] = (u8)(0xFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][3] >> 8));
		Copy_stMessage->MSG[6] = (u8)(0xFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][3] >> 16));
		Copy_stMessage->MSG[7] = (u8)(0xFF & (CAN1_RX->CAN1_RX_MAILBOX[Copy_u8FIFOnumber][3] >> 24));

		//release FIFO
		if(Copy_u8FIFOnumber == CAN1_FIFO0)
		{
			SET_BIT(CAN1_RF0R, 5);
		}
		else if(Copy_u8FIFOnumber == CAN1_FIFO1)
		{
			SET_BIT(CAN1_RF1R, 5);
		}
	}
}
