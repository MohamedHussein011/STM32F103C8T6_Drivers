/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef CAN_PRIVATE_H
#define CAN_PRIVATE_H


#define CAN1_BASE_ADDRESS				0x40006400

//CAN control and status registers
#define CAN1_MCR						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x00)))	//CAN master control register
#define CAN1_MSR						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x04)))	//CAN master status register
#define CAN1_TSR						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x08)))	//CAN transmit status register
#define CAN1_RF0R						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x0C)))	//CAN receive FIFO 0 register
#define CAN1_RF1R						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x10)))	//CAN receive FIFO 1 register
#define CAN1_IER						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x14)))	//CAN interrupt enable register
#define CAN1_ESR						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x18)))	//CAN error status register
#define CAN1_BTR						(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1C)))	//CAN bit timing register

//CAN mailbox registers
typedef struct
{
	volatile u32 CAN1_TX_MAILBOX[3][4];
}CAN1_TX_t;

typedef struct
{
	volatile u32 CAN1_RX_MAILBOX[2][4];
}CAN1_RX_t;


#define CAN1_TX							((volatile CAN1_TX_t*) (CAN1_BASE_ADDRESS + 0x180))
#define CAN1_RX							((volatile CAN1_RX_t*) (CAN1_BASE_ADDRESS + 0x1B0))
//#define CAN1_TI0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x180)))
//#define CAN1_TI1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x190)))
//#define CAN1_TI2R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1A0)))
//#define CAN1_TDT0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x184)))
//#define CAN1_TDT1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x194)))
//#define CAN1_TDT2R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1A4)))
//#define CAN1_TDL0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x188)))
//#define CAN1_TDL1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x198)))
//#define CAN1_TDL2R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1A8)))
//#define CAN1_TDH0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x18C)))
//#define CAN1_TDH1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x19C)))
//#define CAN1_TDH2R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1AC)))
//#define CAN1_RI0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1B0)))
//#define CAN1_RI1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1C0)))
//#define CAN1_RDT0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1B4)))
//#define CAN1_RDT1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1C4)))
//#define CAN1_RDL0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1B8)))
//#define CAN1_RDL1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1C8)))
//#define CAN1_RDH0R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1BC)))
//#define CAN1_RDH1R					(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x1CC)))

//CAN filter registers
#define CAN1_FMR		    		(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x200)))	//CAN filter master register
#define CAN1_FM1R	    			(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x204)))	//CAN filter mode register
#define CAN1_FS1R	    			(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x20C)))	//CAN filter scale register
#define CAN1_FFA1R	    			(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x214)))	//CAN filter FIFO assignment register
#define CAN1_FA1R	    			(*((volatile u32*)(CAN1_BASE_ADDRESS + 0x21C)))	//CAN filter activation register
#define CAN1_FiRx	    			((volatile u32*)(CAN1_BASE_ADDRESS + 0x240))    //Filter bank i register x
//for CAN1_FiRx, to use it in the program, ex: CAN1_FiRx[0]  --> CAN1_F0R1 , ex: CAN1_FiRx[1]  --> CAN1_F0R2 and so on

#define CAN1_DISABLE				0
#define CAN1_ENABLE					1
#define CAN1_SOFTWARE				0
#define CAN1_HARDWARE				1
#define CAN1_ID_PRIORITY			0
#define CAN1_REQ_PRIORITY			1
#define CAN1_SILM					2
#define CAN1_LBKM					1
#define CAN1_COMBINED				3

#define CAN1_TransmitMailbox0				0
#define CAN1_TransmitMailbox1				1
#define CAN1_TransmitMailbox2				2
#define CAN1_NoTransmitMailbox				3


#endif
