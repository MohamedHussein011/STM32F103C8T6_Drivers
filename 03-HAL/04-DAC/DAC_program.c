/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 24/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

#include "file.h"

//array of DAC pins
static u8 u8DAC_Array[DAC_BITS] = DAC_PINS;
//define counter for samples
volatile u32 u32Counter = 0;
//calc ticks for STK
u16 u16TICKS = (1000000UL / DAC_FREQ);

void DAC_voidInit (void)
{
	for(u8 i=0; i<DAC_BITS; i++)
	{
		GPIO_voidSetPinDirection(DAC_PORT, u8DAC_Array[i], OUTPUT_2MHZ_PUSH_PULL);
	}
}
void DAC_voidOutputAnalog(u16 Copy_u16DigitalValue)
{
	u8 Local_u8Bits[DAC_BITS] = {0};
	
	for(u8 i=0; i<DAC_BITS; i++)
	{
		if(Copy_u16DigitalValue % 2 == 0)
		{
			Local_u8Bits[i] = 0;
		}
		else if(Copy_u16DigitalValue % 2 == 1)
		{
			Local_u8Bits[i] = 1;
		}
		Copy_u16DigitalValue /= 2;
	}
	
	for(u8 i=0; i<DAC_BITS; i++)
	{
		GPIO_voidSetPinValue(DAC_PORT, u8DAC_Array[i], Local_u8Bits[i]);
	}
}

void DAC_voidPlaySong(void)
{
	GPIO_voidSetHalfPortDirection(DAC_SONG_PORT, DAC_SONG_PORT_POSITION, OUTPUT_2MHZ_PUSH_PULL);
	STK_voidInit();
	STK_voidSetIntervalPeriodic(u16TICKS, DAC_voidSongCallback);
}

void DAC_voidSongCallback(void)
{
	GPIO_voidSetHalfPortValue(DAC_SONG_PORT, DAC_SONG_PORT_POSITION, stan_raw[u32Counter]);
	u32Counter++;
	if(u32Counter > DAC_SONG_LEN)
	{
		u32Counter = 0;
	}
}