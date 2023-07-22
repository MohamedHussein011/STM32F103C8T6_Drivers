/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

//define global callback pointer to function
void (*SPI_Callback)(u16) = NULL;

void SPI_voidInit(void)
{

#if SPI_DATA_FRAME == SPI_8BIT_DATA
	CLR_BIT(SPI_CR1,11);
#elif SPI_DATA_FRAME == SPI_16BIT_DATA
	SET_BIT(SPI_CR1,11);
#else
#error "wrong choice"
#endif

#if SPI_FRAME_FORMAT == SPI_MSB_FIRST
	CLR_BIT(SPI_CR1,7);
#elif SPI_FRAME_FORMAT == SPI_LSB_FIRST
	SET_BIT(SPI_CR1,7);
#else
#error "wrong choice"
#endif

#if SPI_CLOCK_PHASE == SPI_SAMPLE_FIRST
	CLR_BIT(SPI_CR1,0);
#elif SPI_CLOCK_PHASE == SPI_SETUP_FIRST
	SET_BIT(SPI_CR1,0);
#else
#error "wrong choice"
#endif

#if SPI_CLOCK_POLARITY == SPI_IDLE_LOW
	CLR_BIT(SPI_CR1,1);
#elif SPI_CLOCK_POLARITY == SPI_IDLE_HIGH
	SET_BIT(SPI_CR1,1);
#else
#error "wrong choice"
#endif

#if SPI_MODE == SPI_MASTER
	//configure the pins
	GPIO_voidSetPinDirection(SPI_MASTER_MOSI_PIN,OUTPUT_2MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(SPI_MASTER_MISO_PIN,INPUT_FLOATING_MODE);
	GPIO_voidSetPinDirection(SPI_MASTER_CLK_PIN,OUTPUT_2MHZ_PUSH_PULL);

#if SPI_SLAVE_MANAGEMENT == SPI_MANAGE_HARDWARE
	CLR_BIT(SPI_CR1,9);			//SSM
	SET_BIT(SPI_CR2,2);			//SSOE
	GPIO_voidSetPinDirection(SPI_MASTER_NSS_PIN,OUTPUT_2MHZ_PUSH_PULL);
#elif SPI_SLAVE_MANAGEMENT == SPI_MANAGE_SOFTWARE
	SET_BIT(SPI_CR1,9);			//SSM
	SET_BIT(SPI_CR1,8);			//SSI
	GPIO_voidSetPinDirection(SPI_SLAVE_PIN,OUTPUT_2MHZ_PUSH_PULL);
#else
#error "wrong choice"
#endif

	//Baud Rate
	SPI_CR1 &= ~SPI_BAUD_RATE_MASK;
	SPI_CR1 |= (SPI_BAUD_RATE << 3);

	//Master Mode
	SET_BIT(SPI_CR1,2);

#elif SPI_MODE == SPI_SLAVE
	//configure the pins
	GPIO_voidSetPinDirection(SPI_SLAVE_MISO_PIN,OUTPUT_2MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(SPI_SLAVE_MOSI_PIN,INPUT_FLOATING_MODE);
	GPIO_voidSetPinDirection(SPI_SLAVE_CLK_PIN,INPUT_FLOATING_MODE);

#if SPI_SLAVE_MANAGEMENT == SPI_MANAGE_HARDWARE
	CLR_BIT(SPI_CR1,9);			//SSM
	GPIO_voidSetPinDirection(SPI_SLAVE_NSS_PIN,INPUT_FLOATING_MODE);
#elif SPI_SLAVE_MANAGEMENT == SPI_MANAGE_SOFTWARE
	SET_BIT(SPI_CR1,9);			//SSM
	CLR_BIT(SPI_CR1,8);			//SSI
#else
#error "wrong choice"
#endif

	//SLAVE Mode
	CLR_BIT(SPI_CR1,2);

#endif

	SPI_CR2 = (0x0000) | ((SPI_Tx_BUFFER_EMPTY_INT << 7) | (SPI_Rx_BUFFER_NOT_EMPTY_INT << 6));

	//			| (SPI_Tx_BUFFER_DMA_ENABLE << 1) | (SPI_Rx_BUFFER_DMA_ENABLE));

	//enable SPI
	SET_BIT(SPI_CR1,6);

}

void SPI_voidSendReceiveSynch (u16 Copy_u16DataToSend, u16* Copy_u16DataToReceive)
{
	//Activate the slave
#if SPI_SLAVE_MANAGEMENT == SPI_MANAGE_SOFTWARE && SPI_MODE == SPI_MASTER
	GPIO_voidSetPinValue(SPI_SLAVE_PIN, PIN_LOW);
#endif

	//send data
#if SPI_DATA_FRAME == SPI_8BIT_DATA
	SPI_DR = (u8)Copy_u16DataToSend;
#elif SPI_DATA_FRAME == SPI_16BIT_DATA
	SPI_DR = Copy_u16DataToSend;
#endif

	//polling until data is exchanged with slave
	while(GET_BIT(SPI_SR, SPI_BSY_FLAG) == 1);

	//receive data
#if SPI_DATA_FRAME == SPI_8BIT_DATA
	*Copy_u16DataToReceive = (u8)SPI_DR;
#elif SPI_DATA_FRAME == SPI_16BIT_DATA
	*Copy_u16DataToReceive = SPI_DR;
#endif

	//Deactivate the slave
#if SPI_SLAVE_MANAGEMENT == SPI_MANAGE_SOFTWARE && SPI_MODE == SPI_MASTER
	GPIO_voidSetPinValue(SPI_SLAVE_PIN, PIN_HIGH);
#endif
}

void SPI_voidSendReceiveAsynch (u16 Copy_u16DataToSend, void(*Copy_pvFunc)(u16))
{
	//load the callback function
	SPI_Callback = Copy_pvFunc;

	//Activate the slave
#if SPI_SLAVE_MANAGEMENT == SPI_MANAGE_SOFTWARE && SPI_MODE == SPI_MASTER
	GPIO_voidSetPinValue(SPI_SLAVE_PIN, PIN_LOW);
#endif

	//send data
#if SPI_DATA_FRAME == SPI_8BIT_DATA
	SPI_DR = (u8)Copy_u16DataToSend;
#elif SPI_DATA_FRAME == SPI_16BIT_DATA
	SPI_DR = Copy_u16DataToSend;
#endif

	//enable the RX buffer not empty interrupt
	SET_BIT(SPI_CR2, 6);
}

void SPI1_IRQHandler (void)
{
	//RX buffer not empty flag
	if(GET_BIT(SPI_SR, SPI_RXNE_FLAG) == 1)
	{
		//clear the flag
		CLR_BIT(SPI_SR, SPI_RXNE_FLAG);

		//call the callback with the data received
#if SPI_DATA_FRAME == SPI_8BIT_DATA
		SPI_Callback((u8)SPI_DR);
#elif SPI_DATA_FRAME == SPI_16BIT_DATA
		SPI_Callback(SPI_DR);
#endif

		//Deactivate the slave
#if SPI_SLAVE_MANAGEMENT == SPI_MANAGE_SOFTWARE && SPI_MODE == SPI_MASTER
		GPIO_voidSetPinValue(SPI_SLAVE_PIN, PIN_HIGH);
#endif

		//disable the RX buffer not empty interrupt
		CLR_BIT(SPI_CR2, 6);
	}
}
