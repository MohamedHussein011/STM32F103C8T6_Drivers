/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

//SPI 1 address on APB2 bus
#define SPI_BASE_ADDRESS				0x40013000

#define SPI_CR1					*((volatile u32*) (SPI_BASE_ADDRESS + 0x00))
#define SPI_CR2					*((volatile u32*) (SPI_BASE_ADDRESS + 0x04))
#define SPI_SR					*((volatile u32*) (SPI_BASE_ADDRESS + 0x08))
#define SPI_DR					*((volatile u32*) (SPI_BASE_ADDRESS + 0x0C))


#define SPI_MASTER							0
#define SPI_SLAVE							1

#define SPI_8BIT_DATA					0
#define SPI_16BIT_DATA					1

#define SPI_MANAGE_HARDWARE					0
#define SPI_MANAGE_SOFTWARE					1

#define SPI_MSB_FIRST						0
#define SPI_LSB_FIRST						1

#define SPI_SAMPLE_FIRST				0
#define SPI_SETUP_FIRST					1

#define SPI_IDLE_LOW				0
#define SPI_IDLE_HIGH				1

//Baud rate mask
#define SPI_BAUD_RATE_MASK			0x38
#define SPI_DIV_BY2		            0b000
#define SPI_DIV_BY4                 0b001
#define SPI_DIV_BY8                 0b010
#define SPI_DIV_BY16                0b011
#define SPI_DIV_BY32                0b100
#define SPI_DIV_BY64                0b101
#define SPI_DIV_BY128               0b110
#define SPI_DIV_BY256               0b111

//flags
#define SPI_BSY_FLAG				7			//Busy flag
#define SPI_TXE_FLAG				1			//Transmit buffer empty
#define SPI_RXNE_FLAG				0			//Receive buffer not empty

#endif
