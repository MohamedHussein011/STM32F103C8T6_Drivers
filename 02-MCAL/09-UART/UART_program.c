/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

//define global pointer to hold data to be sent & received
u8* UART_DATA_TRANSMITTED = NULL;
u8* UART_DATA_RECEIVED = NULL;
//define global function pointer
void (*UART_FUNC_TRANSMITTED)(void) = NULL;
void (*UART_FUNC_RECEIVED)(void) = NULL;
//counter
u8 UART_COUNTER_TRANSMITTER = 0;
u8 UART_COUNTER_RECEIVER = 0;
////define variable for buffer size
u8 UART_BUFFERSIZE = 0;
//flag
u8 UART_TRANSMITTER_FLAG = IDLE;
u8 UART_RECEIVER_FLAG = 0;

//calculate the Baud Rate
u8 UART_FRACTION = (u8)(((((UART_RCC_CLOCK * 100UL) / (16UL * UART_BAUD_RATE)) % 100UL) * 16UL) / 100UL);
u16 UART_MANTISSA = (u16)(UART_RCC_CLOCK / (16UL * UART_BAUD_RATE));

void UART_voidInit(void)
{
	GPIO_voidSetPinDirection(UART_RX_PIN,INPUT_FLOATING_MODE);    //rx
	GPIO_voidSetPinDirection(UART_TX_PIN,OUTPUT_2MHZ_PUSH_PULL);	//tx

#if UART_WORD_LENGTH == UART_1START_8DATA
	CLR_BIT(M_UART->CR[0], 12);
#elif UART_WORD_LENGTH == UART_1START_9DATA
	SET_BIT(M_UART->CR[0], 12);
#endif  //word length

#if UART_PARITY_MODE == UART_EN
	SET_BIT(M_UART->CR[0], 10);

#if UART_PARITY == UART_EVEN
	CLR_BIT(M_UART->CR[0], 9);
#elif UART_PARITY == UART_ODD
	SET_BIT(M_UART->CR[0], 9);
#endif //parity odd or even

#elif UART_PARITY_MODE == UART_DIS
	CLR_BIT(M_UART->CR[0], 10);
#endif //parity

#if UART_STOP_BITS == UART_1STOP
	CLR_BIT(M_UART->CR[1], 12);
	CLR_BIT(M_UART->CR[1], 13);
#elif UART_STOP_BITS == UART_2STOP
	CLR_BIT(M_UART->CR[1], 12);
	SET_BIT(M_UART->CR[1], 13);
#endif //STOP bits

#if UART_DMA_TRANS == UART_EN
	SET_BIT(M_UART->CR[2], 7);
#elif UART_DMA_TRANS == UART_DIS
	CLR_BIT(M_UART->CR[2], 7);
#endif //DMA enable transmitter

#if UART_DMA_REC == UART_EN
	SET_BIT(M_UART->CR[2], 6);
#elif UART_DMA_REC == UART_DIS
	CLR_BIT(M_UART->CR[2], 6);
#endif //DMA enable receiver

	//Baud Rate
	if(UART_FRACTION > 15)
		UART_MANTISSA++;
	M_UART->BRR = (UART_FRACTION & 0x0F) | ((UART_MANTISSA & 0x0FFF) << 4);

#if UART_TX_ENABLE == UART_EN
	SET_BIT(M_UART->CR[0], 3);
#elif UART_TX_ENABLE == UART_DIS
	CLR_BIT(M_UART->CR[0], 3);
#endif //Transmitter enable

#if UART_RX_ENABLE == UART_EN
	SET_BIT(M_UART->CR[0], 2);
#elif UART_RX_ENABLE == UART_DIS
	CLR_BIT(M_UART->CR[0], 2);
#endif //Receiver enable

	//zeros all flags
	M_UART->SR = 0;

	//enable UART
	SET_BIT(M_UART->CR[0], 13);
}

void UART_voidTransmitByte(u8 Copy_pchData)
{
	M_UART->DR = Copy_pchData;
	//polling until transmission is complete
	while(GET_BIT(M_UART->SR,UART_TC) == 0);
	CLR_BIT(M_UART->SR, UART_TC);		//clear the transmission complete flag
}

void UART_voidReceiveByte(u8* Copy_pu8Data)
{
	u32 Local_u32Timeout = 0;

	//polling until reception is complete
	while(GET_BIT(M_UART->SR,UART_RXNE) == 0)
	{
		Local_u32Timeout++;
		if(Local_u32Timeout == UART_TIMEOUT)
		{
			break;
		}
	}

	if(Local_u32Timeout == UART_TIMEOUT)
	{
		*Copy_pu8Data = 255;		//garbage value
	}
	else
	{
		CLR_BIT(M_UART->SR,UART_RXNE);		//clear the Read data register not empty flag
		*Copy_pu8Data = (0xFF & (M_UART->DR));
	}

}

void UART_voidTransmitDataSynch(u8* Copy_pchData)
{
	u8 i = 0;
	while(Copy_pchData[i] != '\0')
	{
		M_UART->DR = Copy_pchData[i];
		//polling until transmission is complete
		while(GET_BIT(M_UART->SR,UART_TC) == 0);
		CLR_BIT(M_UART->SR, UART_TC);		//clear the transmission complete flag
		//get next iterator
		i++;
	}
}

void UART_voidReceiveDataBufferSynch(u8* Copy_pchData, u8 Copy_u8BufferSize)
{
	u8 Local_u8Counter = 0;

	while(Local_u8Counter < (Copy_u8BufferSize - 1))
	{
		//polling until reception is complete
		while(GET_BIT(M_UART->SR,UART_RXNE) == 0);
		CLR_BIT(M_UART->SR,UART_RXNE);		//clear the Read data register not empty flag
		Copy_pchData[Local_u8Counter] = (0xFF & (M_UART->DR));

		Local_u8Counter++;
	}

	Copy_pchData[Local_u8Counter] = '\0';

}

void UART_voidTransmitDataAsynch(u8* Copy_pchData, void(*Copy_Func)(void))
{
	if(UART_TRANSMITTER_FLAG == IDLE)
	{
		UART_DATA_TRANSMITTED = Copy_pchData;
		UART_FUNC_TRANSMITTED = Copy_Func;
		UART_TRANSMITTER_FLAG = BUSY;

		//send first element of the array
		M_UART->DR = Copy_pchData[UART_COUNTER_TRANSMITTER];

		//enable Transmission complete interrupt
		SET_BIT(M_UART->CR[0], UART_TC);
	}
}

void UART_voidReceiveDataBufferAsynch(u8* Copy_pchData, u8 Copy_u8BufferSize, void(*Copy_Func)(void))
{
	if(UART_RECEIVER_FLAG == IDLE)
	{
		UART_BUFFERSIZE = Copy_u8BufferSize;
		UART_DATA_RECEIVED = Copy_pchData;
		UART_FUNC_RECEIVED = Copy_Func;
		UART_RECEIVER_FLAG = BUSY;

		//clear the flag
		CLR_BIT(M_UART->SR, UART_RXNE);
		//enable Receiver buffer complete interrupt
		SET_BIT(M_UART->CR[0], UART_RXNE);
	}
}

void UART_voidReceiveStringSynch(u8* Copy_pchData)
{
	u16 Local_u16StringSize = 1000;
	u16 Local_u16Counter = 0;
	while(Local_u16Counter < Local_u16StringSize)
	{
		//polling until reception is complete
		while(GET_BIT(M_UART->SR,UART_RXNE) == 0);
		Copy_pchData[Local_u16Counter] = (0xFF & (M_UART->DR));

		if(Copy_pchData[Local_u16Counter] == 9)
		{
			Copy_pchData[Local_u16Counter] = '\0';
			break;
		}
		Local_u16Counter++;
	}

}


/************************************* ISR *****************************************/
void USART1_IRQHandler (void)
{
	//Transmit complete flag
	if(GET_BIT(M_UART->SR, UART_TC) == 1 && GET_BIT(M_UART->CR[0], UART_TC) == 1)
	{
		//clear the flag
		CLR_BIT(M_UART->SR, UART_TC);
		UART_COUNTER_TRANSMITTER++;

		if(UART_DATA_TRANSMITTED[UART_COUNTER_TRANSMITTER] == '\0')
		{
			//clear the flag
			CLR_BIT(M_UART->SR, UART_TC);
			//disable transmitter interrupt
			CLR_BIT(M_UART->CR[0], UART_TC);
			//zero counter
			UART_COUNTER_TRANSMITTER = 0;
			//reset the flag
			UART_TRANSMITTER_FLAG = IDLE;
			//invoke the function
			UART_FUNC_TRANSMITTED();
		}
		else
		{
			//send data
			M_UART->DR = UART_DATA_TRANSMITTED[UART_COUNTER_TRANSMITTER];
		}
	}

	//Receive complete flag
	if(GET_BIT(M_UART->SR, UART_RXNE) == 1 && GET_BIT(M_UART->CR[0], UART_RXNE) == 1)
	{
		//clear the flag
		CLR_BIT(M_UART->SR, UART_RXNE);
		UART_DATA_RECEIVED[UART_COUNTER_RECEIVER] = (0xFF & (M_UART->DR));

		UART_COUNTER_RECEIVER++;

		if(UART_COUNTER_RECEIVER >= (UART_BUFFERSIZE - 1))
		{
			UART_DATA_RECEIVED[UART_COUNTER_RECEIVER] = '\0';
			//clear the flag
			CLR_BIT(M_UART->SR, UART_RXNE);
			//disable receiver interrupt
			CLR_BIT(M_UART->CR[0], UART_RXNE);
			//zero counter
			UART_COUNTER_RECEIVER = 0;
			//reset the flag
			UART_RECEIVER_FLAG = IDLE;
			//invoke the function
			UART_FUNC_RECEIVED();
		}
	}

	M_UART->SR = 0;
}
