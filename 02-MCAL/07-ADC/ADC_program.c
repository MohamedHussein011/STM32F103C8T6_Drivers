/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

#include "DMA_interface.h"

//global flag for ADC conversion state to make sure not to overlap 2 conversions or more
static volatile u8 u8ADC_STATE = IDLE;
/*Global flag to indicate for the group conversion is working*/
static volatile u8 u8ADC_GROUP_STATE = IDLE;
/*Global variable to carry the conversion result in the asynchronous execution*/
volatile u16 u16ADC_DATA = 0;
/*Global pointer to function to carry the notification function called by ISR*/
void (*pvADC_FUNCTION)(u16 Copy_u16Data) = NULL;

void ADC_voidInit(void)
{
	//Data alignment
#if ADC_DATA_ALIGNMENT == ADC_RIGHT_ALIGNMENT
	CLR_BIT(M_ADC->ADC_CR2, ADC_ALIGN);
#elif ADC_DATA_ALIGNMENT == ADC_LEFT_ALIGNMENT
	SET_BIT(M_ADC->ADC_CR2, ADC_ALIGN);
#endif

	//enable ADC
	SET_BIT(M_ADC->ADC_CR2, ADC_ADON);
}

void ADC_voidStartSingleConversionSynch (u8 Copy_u8Channel, u8 Copy_u8SamplingRate, u16* Copy_pu16Data)
{
	u32 Local_u32Timeout = 0;

	if(u8ADC_STATE == IDLE)
	{
		//ADC is now busy & in use
		u8ADC_STATE = BUSY;

		//sampling rate
		M_ADC->ADC_SMPR2 = (Copy_u8SamplingRate << (Copy_u8Channel * 3));

		//single conversion so the sequence length is 1
		M_ADC->ADC_SQR1 &= ADC_SQ_LENGTH_MASK;
		M_ADC->ADC_SQR1 = (ADC_SQ_LEN_1CONVERSION << 20);
		M_ADC->ADC_SQR3 = Copy_u8Channel;

		//single conversion so clear the continuous conversion bit
		CLR_BIT(M_ADC->ADC_CR2, ADC_CONT);

		//must write 1 to ADON bit while it 1 (already wrote in ADC_voidInit) to start the conversion
		SET_BIT(M_ADC->ADC_CR2, ADC_ADON);

		//polling until the conversion is complete / flag is raised
		while(!GET_BIT(M_ADC->ADC_SR, ADC_EOC) && Local_u32Timeout != ADC_TIMEOUT)
		{
			Local_u32Timeout++;
		}

		//clear the end of conversion flag
		CLR_BIT(M_ADC->ADC_SR, ADC_EOC);

		if(Local_u32Timeout != ADC_TIMEOUT)
		{
			//read the data
#if ADC_DATA_ALIGNMENT == ADC_RIGHT_ALIGNMENT
			*Copy_pu16Data = (u16) (M_ADC->ADC_DR);
#elif ADC_DATA_ALIGNMENT == ADC_LEFT_ALIGNMENT
			*Copy_pu16Data = (u16) ((M_ADC->ADC_DR) >> 4);
#endif
		}
		else
		{
			//error
		}
		//ADC is now idle & free to use
		u8ADC_STATE = IDLE;

	}
	else
	{
		//error, there is already running ADC conversion
	}
}

void ADC_voidStartSingleConversionAsynch (u8 Copy_u8Channel, u8 Copy_u8SamplingRate, void (*Copy_pvFunction)(u16 Copy_u16Data))
{
	if(u8ADC_STATE == IDLE)
	{
		//ADC is now busy & in use
		u8ADC_STATE = BUSY;
		//holds the notification function to be called after the conversion complete
		pvADC_FUNCTION = Copy_pvFunction;

		//sampling rate
		M_ADC->ADC_SMPR2 = (Copy_u8SamplingRate << (Copy_u8Channel * 3));

		//single conversion so the sequence length is 1
		M_ADC->ADC_SQR1 &= ADC_SQ_LENGTH_MASK;
		M_ADC->ADC_SQR1 = (ADC_SQ_LEN_1CONVERSION << 20);
		M_ADC->ADC_SQR3 = Copy_u8Channel;

		//single conversion so clear the continuous conversion bit
		CLR_BIT(M_ADC->ADC_CR2, ADC_CONT);

		//enable the conversion complete interrupt
		SET_BIT(M_ADC->ADC_CR1, ADC_EOCIE);

		//must write 1 to ADON bit while it 1 (already wrote in ADC_voidInit) to start the conversion
		SET_BIT(M_ADC->ADC_CR2, ADC_ADON);
	}
	else
	{
		//error, there is already running ADC conversion
	}
}

void ADC_voidStartGroupConversionSynch (ST_ADCGroupSynch_t* Copy_pstGroup)
{
	u32 Local_u32Timeout = 0;
	u8 Local_u8Itearator = 0;

	if(u8ADC_STATE == IDLE)
	{
		//ADC is now busy & in use
		u8ADC_STATE = BUSY;

		//group conversion so the sequence length is number of channels
		M_ADC->ADC_SQR1 &= ADC_SQ_LENGTH_MASK;
		M_ADC->ADC_SQR1 = ((Copy_pstGroup->ADC_NUM_CONVERSIONS - 1) << 20);

		while(Local_u8Itearator < (Copy_pstGroup->ADC_NUM_CONVERSIONS))
		{
			//sampling rate
			M_ADC->ADC_SMPR2 |= (Copy_pstGroup->ADC_SAMPLING_RATE[Local_u8Itearator] << (Copy_pstGroup->ADC_GROUP_CHANNELS[Local_u8Itearator] * 3));

			if(Local_u8Itearator <= 5)
			{
				M_ADC->ADC_SQR3 |= Copy_pstGroup->ADC_GROUP_CHANNELS[Local_u8Itearator] << (Local_u8Itearator * 5);
			}
			else if(Local_u8Itearator <= 9)
			{
				M_ADC->ADC_SQR2 |= Copy_pstGroup->ADC_GROUP_CHANNELS[Local_u8Itearator] << ((Local_u8Itearator - 6) * 5);
			}

			Local_u8Itearator++;
		}
		//set the continuous conversion bit
		SET_BIT(M_ADC->ADC_CR2, ADC_CONT);

		Local_u8Itearator = 0;

		while(Local_u8Itearator < (Copy_pstGroup->ADC_NUM_CONVERSIONS))
		{
			//must write 1 to ADON bit while it 1 (already wrote in ADC_voidInit) to start the conversion
			SET_BIT(M_ADC->ADC_CR2, ADC_ADON);

			//polling until the conversion is complete / flag is raised
			while(!GET_BIT(M_ADC->ADC_SR, ADC_EOC) && Local_u32Timeout != ADC_TIMEOUT)
			{
				Local_u32Timeout++;
			}

			//clear the end of conversion flag
			CLR_BIT(M_ADC->ADC_SR, ADC_EOC);

			if(Local_u32Timeout != ADC_TIMEOUT)
			{
				//read the data
#if ADC_DATA_ALIGNMENT == ADC_RIGHT_ALIGNMENT
				Copy_pstGroup->ADC_GROUP_RESULTS[Local_u8Itearator] = (u16) (M_ADC->ADC_DR);
#elif ADC_DATA_ALIGNMENT == ADC_LEFT_ALIGNMENT
				Copy_pstGroup->ADC_GROUP_RESULTS[Local_u8Itearator] = (u16) ((M_ADC->ADC_DR) >> 4);
#endif
			}
			else
			{
				//error
			}

			Local_u8Itearator++;
		}

		//ADC is now idle & free to use
		u8ADC_STATE = IDLE;

	}
	else
	{
		//error, there is already running ADC conversion
	}
}

void ADC_voidStartGroupConversionDMA (ST_ADCGroupDMA_t* Copy_pstGroup, u16* Copy_pu16ADCData)
{
	u8 Local_u8Itearator = 0;

	if(u8ADC_STATE == IDLE)
	{
		//ADC is now busy & in use
		u8ADC_STATE = BUSY;
		u8ADC_GROUP_STATE = BUSY;

		//group conversion so the sequence length is number of channels
		M_ADC->ADC_SQR1 &= ADC_SQ_LENGTH_MASK;
		M_ADC->ADC_SQR1 = ((Copy_pstGroup->ADC_NUM_CONVERSIONS - 1) << 20);

		while(Local_u8Itearator < (Copy_pstGroup->ADC_NUM_CONVERSIONS))
		{
			//sampling rate
			M_ADC->ADC_SMPR2 |= (Copy_pstGroup->ADC_SAMPLING_RATE[Local_u8Itearator] << (Copy_pstGroup->ADC_GROUP_CHANNELS[Local_u8Itearator] * 3));

			if(Local_u8Itearator <= 5)
			{
				M_ADC->ADC_SQR3 |= Copy_pstGroup->ADC_GROUP_CHANNELS[Local_u8Itearator] << (Local_u8Itearator * 5);
			}
			else if(Local_u8Itearator <= 9)
			{
				M_ADC->ADC_SQR2 |= Copy_pstGroup->ADC_GROUP_CHANNELS[Local_u8Itearator] << ((Local_u8Itearator - 6) * 5);
			}

			Local_u8Itearator++;
		}


		DMA_voidSetCallBack(DMA_CHANNEL1, Copy_pstGroup->ADC_pvNotificationFunc);
		DMA_voidChannelRequest(DMA_CHANNEL1, (u32*)Copy_pu16ADCData, (u32*)&(M_ADC->ADC_DR),Copy_pstGroup->ADC_NUM_CONVERSIONS);
		DMA_voidEnableInterrupt(DMA_CHANNEL1, DMA_CTCIF);
		DMA_voidEnableChannel(DMA_CHANNEL1);

		//enable scan mode
		SET_BIT(M_ADC->ADC_CR1, ADC_SCAN);
		//enable Direct memory access mode for Scan mode
		SET_BIT(M_ADC->ADC_CR2, ADC_DMA);
		//enable the conversion complete interrupt
		SET_BIT(M_ADC->ADC_CR1, ADC_EOCIE);
		//must write 1 to ADON bit while it 1 (already wrote in ADC_voidInit) to start the conversion
		SET_BIT(M_ADC->ADC_CR2, ADC_ADON);

	}
	else
	{
		//error, there is already running ADC conversion
	}

}

/******************************************** ISR **************************************************/
void ADC1_2_IRQHandler (void)
{
	if(u8ADC_GROUP_STATE == IDLE)
	{
		//clear the end of conversion flag
		CLR_BIT(M_ADC->ADC_SR, ADC_EOC);
		//read the data
#if ADC_DATA_ALIGNMENT == ADC_RIGHT_ALIGNMENT
		u16ADC_DATA = (u16) (M_ADC->ADC_DR);
#elif ADC_DATA_ALIGNMENT == ADC_LEFT_ALIGNMENT
		u16ADC_DATA = (u16) ((M_ADC->ADC_DR) >> 4);
#endif

		//disable the conversion complete interrupt
		CLR_BIT(M_ADC->ADC_CR1, ADC_EOCIE);

		//call the notification function
		pvADC_FUNCTION(u16ADC_DATA);

		//ADC is now idle & free to use
		u8ADC_STATE = IDLE;
	}
	else if(u8ADC_GROUP_STATE == BUSY)
	{
		//clear the end of conversion flag
		CLR_BIT(M_ADC->ADC_SR, ADC_EOC);

		//disable the conversion complete interrupt
		CLR_BIT(M_ADC->ADC_CR1, ADC_EOCIE);
		//ADC is now idle & free to use
		u8ADC_STATE = IDLE;
		u8ADC_GROUP_STATE = IDLE;
	}
}
