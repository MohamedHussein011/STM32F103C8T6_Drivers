/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef CAN_INTERFACE_H
#define CAN_INTERFACE_H

/*	CAN1 Pins configuration		- connected to APB1
 *
 *  Output pin (CAN_TX)		-->  Alternate function push-pull
 *  Input pin  (CAN_RX)		-->  Input floating / Input pull-up
 *  NO REMAP
*	CAN1_RX		---->>  	PA11			/ if re-mapped 	--->>	PB8
 *	CAN1_TX		---->>  	PA12			/ if re-mapped 	--->>	PB9
 */

typedef struct
{
	u32 EXTID;				//extended message ID		0 to 0x1FFFFFFF
	u16 STID;				//standard message ID		0 to 0x7FF
	u8  IDE;				//ID extension	(CAN1_STID 	or 	CAN1_EXTID)
	u8  RTR;				// Remote transmission request	(CAN1_DATA 	or 	CAN1_REMOTE)
	u8  DLC;				//data length code			0 to 8
	u8  MSG[8];				//message
}CAN1_TX_MSG_t;

typedef struct
{
	u32 EXTID;				//extended message ID		0 to 0x1FFFFFFF
	u16 STID;				//standard message ID		0 to 0x7FF
	u8  IDE;				//ID extension	(CAN1_STID 	or 	CAN1_EXTID)
	u8  RTR;				// Remote transmission request	(CAN1_DATA 	or 	CAN1_REMOTE)
	u8  DLC;				//data length code			0 to 8
	u8  MSG[8];				//message
	u8  FMI;				//Filter match index
}CAN1_RX_MSG_t;

#define CAN1_STID				0		//standard message ID
#define CAN1_EXTID				1		//extended message ID
#define CAN1_DATA				0		//Data frame
#define CAN1_REMOTE				1		//Remote frame

typedef struct
{
	u32 ID;				//Identifier - NOTE: if you want to add 2 * 16 BITs ID, just OR them together (ID1 | (ID2 << 16))
	u32 MASK;			//Identifier Mask - NOTE: if not to use MASK, you can use it as another ID
	u8  FILTER_NUM;		//filter number (CAN1_FILTER0 to CAN1_FILTER13)
	u8  FIFO_NUM;		//FIFO number (CAN1_FIFO0 or CAN1_FIFO1)
	u8  SCALE;			//CAN1_DUAL_16BIT or CAN1_SINGLE_32BIT
	u8  MODE;			//Identifier Mask mode or Identifier List mode
}CAN1_FILTER_t;

#define CAN1_MASK_MODE					0			//Identifier Mask mode
#define CAN1_LIST_MODE					1			//Identifier List mode
#define CAN1_DUAL_16BIT					0			//Dual 16-bit scale configuration
#define CAN1_SINGLE_32BIT				1			//Single 32-bit scale configuration
#define CAN1_FIFO0						0			//Filter assigned to FIFO 0
#define CAN1_FIFO1						1			//Filter assigned to FIFO 1
#define CAN1_FILTER0					0			//filter 0
#define CAN1_FILTER1					1			//filter 1
#define CAN1_FILTER2					2			//filter 2
#define CAN1_FILTER3					3			//filter 3
#define CAN1_FILTER4					4			//filter 4
#define CAN1_FILTER5					5			//filter 5
#define CAN1_FILTER6					6			//filter 6
#define CAN1_FILTER7					7			//filter 7
#define CAN1_FILTER8					8			//filter 8
#define CAN1_FILTER9					9			//filter 9
#define CAN1_FILTER10					10			//filter 10
#define CAN1_FILTER11					11			//filter 11
#define CAN1_FILTER12					12			//filter 12
#define CAN1_FILTER13					13			//filter 13


void CAN1_voidInit (void);
void CAN1_voidFilterInit (CAN1_FILTER_t* Copy_stFilter);

void CAN1_voidTransmit (CAN1_TX_MSG_t* Copy_stMessage);
void CAN1_voidReceive  (CAN1_RX_MSG_t* Copy_stMessage, u8 Copy_u8FIFOnumber);

#endif
