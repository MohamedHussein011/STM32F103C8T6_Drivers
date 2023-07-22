/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef CAN_CONFIG_H
#define CAN_CONFIG_H

//options:		1: CAN1_ENABLE				2: CAN1_DISABLE
/*Debug freeze  - 	CAN working during debug or frozen */
#define CAN1_DBF						CAN1_ENABLE

//Time triggered communication mode
#define CAN1_TTCM						CAN1_DISABLE

//No automatic retransmission
#define CAN1_NART						CAN1_ENABLE

// Receive FIFO locked mode
#define CAN1_RFLM						CAN1_ENABLE

/*Automatic bus-off management
 * options:	1: CAN1_SOFTWARE				2: CAN1_HARDWARE
 * */
#define CAN1_ABOM						CAN1_HARDWARE

/*Automatic wakeup mode
 * options:	1: CAN1_SOFTWARE				2: CAN1_HARDWARE
 * */
#define CAN1_AWUM						CAN1_HARDWARE

/*Transmit FIFO priority
 * options:	1: CAN1_ID_PRIORITY	(identifier)			2: CAN1_REQ_PRIORITY	(transmit request order)
 * */
#define CAN1_TXFP						CAN1_ID_PRIORITY

/*Silent mode & Loop back mode(debug)
 * options:		1: CAN1_SILM			2: CAN1_LBKM			3: CAN1_COMBINED			4: CAN1_DISABLE
 * */
#define CAN1_DBG_MODE					CAN1_DISABLE

//Resynchronization jump width
#define CAN1_SJW						1

//Time segment 2
#define CAN1_TS2						0

//Time segment 1
#define CAN1_TS1						0

//Baud rate prescaler
#define CAN1_BRP						0

#endif
