/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}UART_t;

#define M_UART				((volatile UART_t*) 0x40013800)

#define UART_EN					0
#define UART_DIS				1

#define UART_EVEN				0
#define UART_ODD				1

#define UART_1STOP				0
#define UART_2STOP				1

#define UART_IDLE_LOW				0
#define UART_IDLE_HIGH				1

#define UART_SAMPLE_FIRST				0
#define UART_SETUP_FIRST				1

#define UART_1START_8DATA				0
#define UART_1START_9DATA				1

//Flags in UART_SR
#define UART_TXE					7		//transmit data register empty
#define UART_TC			    		6		//Transmission complete
#define UART_RXNE					5		//Read data register not empty

#endif
