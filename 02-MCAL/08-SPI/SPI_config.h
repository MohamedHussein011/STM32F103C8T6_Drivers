/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

//write slave port, pin in pairs - if you won't use the NSS pin & WANT to control the slave by a normal DIO pin(slave is managed by software)

/*SPI mode
*options:
*		1: SPI_MASTER
*		2: SPI_SLAVE
*/
#define SPI_MODE						SPI_MASTER

//write master & slave port, pin in pairs - SPI1 pins in portA or by AFIO can be re-mapped to portB
#if SPI_MODE == SPI_MASTER
#define SPI_MASTER_MOSI_PIN					GPIOA,GPIO_PIN7
#define SPI_MASTER_MISO_PIN					GPIOA,GPIO_PIN6
#define SPI_MASTER_CLK_PIN					GPIOA,GPIO_PIN5
#define SPI_MASTER_NSS_PIN					GPIOA,GPIO_PIN4
#define SPI_SLAVE_PIN						GPIOA,GPIO_PIN0	//write slave port, pin in pairs - if you won't use the NSS pin & WANT to control the slave by a normal DIO pin(slave is managed by software)
#endif

#if SPI_MODE == SPI_SLAVE
#define SPI_SLAVE_MOSI_PIN					GPIOA,GPIO_PIN7
#define SPI_SLAVE_MISO_PIN					GPIOA,GPIO_PIN6
#define SPI_SLAVE_CLK_PIN					GPIOA,GPIO_PIN5
#define SPI_SLAVE_NSS_PIN					GPIOA,GPIO_PIN4
#endif

/*Data frame format
*options:
*		1: SPI_8BIT_DATA
*		2: SPI_16BIT_DATA
*/
#define SPI_DATA_FRAME					SPI_8BIT_DATA

/*Software slave management
*options:
*		1: SPI_MANAGE_HARDWARE
*		2: SPI_MANAGE_SOFTWARE
*/
#define SPI_SLAVE_MANAGEMENT					SPI_MANAGE_SOFTWARE

/*frame format
*options:
*		1: SPI_MSB_FIRST
*		2: SPI_LSB_FIRST
*/
#define SPI_FRAME_FORMAT					SPI_MSB_FIRST

/*Clock phase
*options:
*		1: SPI_SAMPLE_FIRST			receive
*		2: SPI_SETUP_FIRST			send
*/
#define SPI_CLOCK_PHASE					SPI_SAMPLE_FIRST

/*Clock polarity
*options:
*		1: SPI_IDLE_LOW
*		2: SPI_IDLE_HIGH
*/
#define SPI_CLOCK_POLARITY				SPI_IDLE_HIGH

/*Baud rate control
*options:
*		1: SPI_DIV_BY2
*		2: SPI_DIV_BY4
*		3: SPI_DIV_BY8
*		4: SPI_DIV_BY16
*		5: SPI_DIV_BY32
*		6: SPI_DIV_BY64
*		7: SPI_DIV_BY128
*		8: SPI_DIV_BY256
*/
#define SPI_BAUD_RATE					SPI_DIV_BY32

/*Tx buffer empty interrupt enable, RX buffer not empty interrupt enable
*	write 0 to mask & 1 to enable
*/
#define SPI_Tx_BUFFER_EMPTY_INT						0
#define SPI_Rx_BUFFER_NOT_EMPTY_INT					0
//#define SPI_Tx_BUFFER_DMA_ENABLE					0
//#define SPI_Rx_BUFFER_DMA_ENABLE					0


#endif
