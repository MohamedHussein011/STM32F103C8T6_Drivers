/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

//note: every number at the end of macro indicate for channel number :)
//to choose (enable) channels write the following without values	-->		#define DMA_CHAN1 	, and so on
#define DMA_CHAN1

/* Memory to memory mode
* options:
*			write 0 to disable for memory to peripheral & vice versa  & 1 to enable	for Memory to memory
*/
#define DMA_MEM_TO_MEM_MODE1		0
#define DMA_MEM_TO_MEM_MODE2		0
#define DMA_MEM_TO_MEM_MODE3		0
#define DMA_MEM_TO_MEM_MODE4		0
#define DMA_MEM_TO_MEM_MODE5		0
#define DMA_MEM_TO_MEM_MODE6		0
#define DMA_MEM_TO_MEM_MODE7		0

/* Channel priority level
* options:
*			1: DMA_PRIORITY_LOW				write 0b00
*			2: DMA_PRIORITY_MEDIUM          write 0b01
*			3: DMA_PRIORITY_HIGH            write 0b10
*			4: DMA_PRIORITY_VERY_HIGH       write 0b11
*/
#define DMA_CHANNEL_PRIORITY1			0b11
#define DMA_CHANNEL_PRIORITY2			0b11
#define DMA_CHANNEL_PRIORITY3			0b11
#define DMA_CHANNEL_PRIORITY4			0b11
#define DMA_CHANNEL_PRIORITY5			0b11
#define DMA_CHANNEL_PRIORITY6			0b11
#define DMA_CHANNEL_PRIORITY7			0b11

/* Memory size, Peripheral size
* options:
*			1: 8 Bits                 write 0b00
*			2: 16 Bits                write 0b01
*			3: 32 Bits                write 0b10
*/
#define DMA_MEMORY_SIZE1				0b01
#define DMA_MEMORY_SIZE2				0b00
#define DMA_MEMORY_SIZE3				0b00
#define DMA_MEMORY_SIZE4				0b00
#define DMA_MEMORY_SIZE5				0b00
#define DMA_MEMORY_SIZE6				0b00
#define DMA_MEMORY_SIZE7				0b00

#define DMA_PERIPHERAL_SIZE1			0b01
#define DMA_PERIPHERAL_SIZE2			0b00
#define DMA_PERIPHERAL_SIZE3			0b00
#define DMA_PERIPHERAL_SIZE4			0b00
#define DMA_PERIPHERAL_SIZE5			0b00
#define DMA_PERIPHERAL_SIZE6			0b00
#define DMA_PERIPHERAL_SIZE7			0b00

/* Memory & Peripheral increment mode
* options:
*			write 0 to disable & 1 to enable	
*/
#define DMA_MEM_INCREMENT_MODE1			1
#define DMA_MEM_INCREMENT_MODE2			0
#define DMA_MEM_INCREMENT_MODE3			0
#define DMA_MEM_INCREMENT_MODE4			0
#define DMA_MEM_INCREMENT_MODE5			0
#define DMA_MEM_INCREMENT_MODE6			0
#define DMA_MEM_INCREMENT_MODE7			0

#define DMA_PER_INCREMENT_MODE1			0
#define DMA_PER_INCREMENT_MODE2			0
#define DMA_PER_INCREMENT_MODE3			0
#define DMA_PER_INCREMENT_MODE4			0
#define DMA_PER_INCREMENT_MODE5			0
#define DMA_PER_INCREMENT_MODE6			0
#define DMA_PER_INCREMENT_MODE7			0

/* Circular mode
* options:
*			write 0 to disable & 1 to enable	
*/
#define DMA_CIRCULAR_MODE1			1
#define DMA_CIRCULAR_MODE2			0
#define DMA_CIRCULAR_MODE3			0
#define DMA_CIRCULAR_MODE4			0
#define DMA_CIRCULAR_MODE5			0
#define DMA_CIRCULAR_MODE6			0
#define DMA_CIRCULAR_MODE7			0

/* Data transfer direction
* options:
*			1: DMA_READ_FROM_PERIPHERAL			write 0			so it's the source
*			2: DMA_READ_FROM_MEMORY				write 1			so it's the source
*/
#define DMA_DATA_TRANSFER1			0
#define DMA_DATA_TRANSFER2			0
#define DMA_DATA_TRANSFER3			0
#define DMA_DATA_TRANSFER4			0
#define DMA_DATA_TRANSFER5			0
#define DMA_DATA_TRANSFER6			0
#define DMA_DATA_TRANSFER7			0

/* Transfer error / Half / Complete interrupt enable
* options:
*			write 0 to disable & 1 to enable	
*/
#define DMA_TRANS_ERROR_INTERRUPT1			0
#define DMA_TRANS_ERROR_INTERRUPT2			0
#define DMA_TRANS_ERROR_INTERRUPT3			0
#define DMA_TRANS_ERROR_INTERRUPT4			0
#define DMA_TRANS_ERROR_INTERRUPT5			0
#define DMA_TRANS_ERROR_INTERRUPT6			0
#define DMA_TRANS_ERROR_INTERRUPT7			0

#define DMA_TRANS_HALF_INTERRUPT1			0
#define DMA_TRANS_HALF_INTERRUPT2			0
#define DMA_TRANS_HALF_INTERRUPT3			0
#define DMA_TRANS_HALF_INTERRUPT4			0
#define DMA_TRANS_HALF_INTERRUPT5			0
#define DMA_TRANS_HALF_INTERRUPT6			0
#define DMA_TRANS_HALF_INTERRUPT7			0

#define DMA_TRANS_COMP_INTERRUPT1			1
#define DMA_TRANS_COMP_INTERRUPT2			0
#define DMA_TRANS_COMP_INTERRUPT3			0
#define DMA_TRANS_COMP_INTERRUPT4			0
#define DMA_TRANS_COMP_INTERRUPT5			0
#define DMA_TRANS_COMP_INTERRUPT6			0
#define DMA_TRANS_COMP_INTERRUPT7			0


#endif
