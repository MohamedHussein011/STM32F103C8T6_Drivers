/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

//ADC1
typedef struct
{
	volatile u32 ADC_SR;
	volatile u32 ADC_CR1;
	volatile u32 ADC_CR2;
	volatile u32 ADC_SMPR1;
	volatile u32 ADC_SMPR2;
	volatile u32 ADC_JOFR1;
	volatile u32 ADC_JOFR2;
	volatile u32 ADC_JOFR3;
	volatile u32 ADC_JOFR4;
	volatile u32 ADC_HTR;
	volatile u32 ADC_LTR;
	volatile u32 ADC_SQR1;
	volatile u32 ADC_SQR2;
	volatile u32 ADC_SQR3;
	volatile u32 ADC_JSQR;
	volatile u32 ADC_JDR1;
	volatile u32 ADC_JDR2;
	volatile u32 ADC_JDR3;
	volatile u32 ADC_JDR4;
	volatile u32 ADC_DR;
}ADC_t;

#define M_ADC		((volatile ADC_t*) 0x40012400)			//ADC1

//ADC_SR
#define ADC_STRT					4		//regular channel start flag
#define ADC_EOC						1		//end of conversion flag

//ADC_CR1
#define ADC_SCAN					8		//Scan mode
#define ADC_EOCIE					5		//Interrupt enable for EOC

//ADC_CR2
//#define ADC_SWSTART					22		//Start conversion of regular channels
//#define ADC_EXTTRIG					20		//External trigger conversion mode for regular channels
//#define ADC_EXTSEL_MASK				0xFFF1FFFF
//#define ADC_EXTSEL_TIMER1_CC1			0b000
//#define ADC_EXTSEL_TIMER1_CC2			0b001
//#define ADC_EXTSEL_TIMER1_CC3			0b010
//#define ADC_EXTSEL_TIMER2_CC2			0b011
//#define ADC_EXTSEL_TIMER3_TRGO			0b100
//#define ADC_EXTSEL_TIMER4_CC4			0b101
//#define ADC_EXTSEL_EXTIL11				0b110
//#define ADC_EXTSEL_SWSTART				0b111
#define ADC_ALIGN					11		//Data alignment
#define ADC_DMA 					8		//Direct memory access mode
#define ADC_CONT					1		//Continuous conversion
#define ADC_ADON					0		//A/D converter ON / OFF

//ADC_SQR1
#define ADC_SQ_LENGTH_MASK					0xFF0FFFFF		//Regular channel sequence length
#define ADC_SQ_LEN_1CONVERSION				0b0000
#define ADC_SQ_LEN_2CONVERSION				0b0001
#define ADC_SQ_LEN_3CONVERSION				0b0010
#define ADC_SQ_LEN_4CONVERSION				0b0011
#define ADC_SQ_LEN_5CONVERSION				0b0100
#define ADC_SQ_LEN_6CONVERSION				0b0101
#define ADC_SQ_LEN_7CONVERSION				0b0110
#define ADC_SQ_LEN_8CONVERSION				0b0111
#define ADC_SQ_LEN_9CONVERSION				0b1000
#define ADC_SQ_LEN_10CONVERSION				0b1001
#define ADC_SQ_LEN_11CONVERSION				0b1010
#define ADC_SQ_LEN_12CONVERSION				0b1011
#define ADC_SQ_LEN_13CONVERSION				0b1100
#define ADC_SQ_LEN_14CONVERSION				0b1101
#define ADC_SQ_LEN_15CONVERSION				0b1110
#define ADC_SQ_LEN_16CONVERSION				0b1111

#define ADC_ENABLE							0
#define ADC_DISABLE							1

#define ADC_RIGHT_ALIGNMENT					0
#define ADC_LEFT_ALIGNMENT					1

#endif
