/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

//NOTE: ADC pins must be configured as Input Analog Mode
//ADC Pins are PA0 to PA9

//ADC channels available on this Microcontroller
#define ADC_CHANNEL0							0
#define ADC_CHANNEL1							1
#define ADC_CHANNEL2							2
#define ADC_CHANNEL3							3
#define ADC_CHANNEL4							4
#define ADC_CHANNEL5							5
#define ADC_CHANNEL6							6
#define ADC_CHANNEL7							7
#define ADC_CHANNEL8							8
#define ADC_CHANNEL9							9

//ADC sample time
#define ADC_SMP_1andHalfCycles						0b000
#define ADC_SMP_7andHalfCycles						0b001
#define ADC_SMP_13andHalfCycles						0b010
#define ADC_SMP_28andHalfCycles						0b011
#define ADC_SMP_41andHalfCycles						0b100
#define ADC_SMP_55andHalfCycles						0b101
#define ADC_SMP_71andHalfCycles						0b110
#define ADC_SMP_239andHalfCycles					0b111

//at the beginning it's idle state (free to use) --> in the notification function of ADC_voidStartGroupConversionDMA
//must set to idle again
//volatile u8 u8ADC_DMA_STATE = IDLE;

typedef struct
{
	u8 ADC_NUM_CONVERSIONS;
	u8* ADC_GROUP_CHANNELS;				//array of channels
	u8* ADC_SAMPLING_RATE;				//array of sampling rates
	u16* ADC_GROUP_RESULTS;				//array of results
}ST_ADCGroupSynch_t;

typedef struct
{
	void (*ADC_pvNotificationFunc) (void);
	u8 ADC_NUM_CONVERSIONS;
	u8* ADC_GROUP_CHANNELS;				//array of channels
	u8* ADC_SAMPLING_RATE;				//array of sampling rates
}ST_ADCGroupDMA_t;

//ADC1
void ADC_voidInit(void);

void ADC_voidStartSingleConversionSynch (u8 Copy_u8Channel, u8 Copy_u8SamplingRate, u16* Copy_pu16Data);
void ADC_voidStartSingleConversionAsynch (u8 Copy_u8Channel, u8 Copy_u8SamplingRate, void (*Copy_pvFunction)(u16 Copy_u16Data));

void ADC_voidStartGroupConversionSynch (ST_ADCGroupSynch_t* Copy_pstGroup);

//DMA Channel 1 configured with {memory to peripheral mode, memory size is 16 bits, peripheral size is 16 bits
//		memory increment mode, data transfer is read from peripheral, transfer complete enable, Circular mode)
//Copy_pu16ADCData is a pointer to an array
//ADC & DMA channel 1 interrupts must be enabled
void ADC_voidStartGroupConversionDMA (ST_ADCGroupDMA_t* Copy_pstGroup, u16* Copy_pu16ADCData);			//Asynchronous function

#endif
