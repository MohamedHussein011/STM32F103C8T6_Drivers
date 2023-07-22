/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* UART enable & Transmitter enable & Receiver enable
*options:
*		1: UART_EN
*		2: UART_DIS
*/
#define UART_TX_ENABLE				 UART_EN
#define UART_RX_ENABLE				 UART_EN

/*UART pins in pair port,pin*/
#define UART_TX_PIN				GPIOA,GPIO_PIN9
#define UART_RX_PIN				GPIOA,GPIO_PIN10

/* RCC clock for UART1 peripheral*/
#define UART_RCC_CLOCK					8000000UL

/* UART Baud Rate - type for ex: 9600UL
*/
#define UART_BAUD_RATE				9600UL

//define UART timeout
#define UART_TIMEOUT				10000
	
/* Word length
*options:
*		1: UART_1START_8DATA
*		2: UART_1START_9DATA
*/
#define UART_WORD_LENGTH			 UART_1START_8DATA	
	
/* Parity control enable & Parity selection
*options:
*		1: UART_EN
*		2: UART_DIS
*		3: UART_EVEN
*		4: UART_ODD
*/
#define UART_PARITY_MODE			 UART_DIS
#if UART_PARITY_MODE == UART_EN
#define UART_PARITY						UART_EVEN
#endif

/* STOP bits
*options:
*		1: UART_1STOP
*		2: UART_2STOP
*/
#define UART_STOP_BITS			 UART_1STOP

/* DMA enable transmitter & DMA enable receiver
*options:
*		1: UART_EN
*		2: UART_DIS
*/
#define UART_DMA_TRANS			 UART_DIS
#define UART_DMA_REC			 UART_DIS

#endif
