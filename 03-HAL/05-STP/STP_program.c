/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 01/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_voidInit(void)
{
	GPIO_voidSetPinDirection(STP_SERIAL_DATA, OUTPUT_2MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(STP_BIT_LATCH_CLOCK, OUTPUT_2MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(STP_BYTE_LATCH_CLOCK, OUTPUT_2MHZ_PUSH_PULL);
}

void STP_voidSendByteSynchronus (u8 Copy_u8Data)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter = 7; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit starting from MSb */
		Local_u8Bit = GET_BIT(Copy_u8Data,Local_s8Counter);
		GPIO_voidSetPinValue(STP_SERIAL_DATA, Local_u8Bit);
		
		/* Send Pulse for Shift Clock*/
		GPIO_voidSetPinValue(STP_BIT_LATCH_CLOCK, PIN_HIGH);
		STK_voidDelayus(1);
		GPIO_voidSetPinValue(STP_BIT_LATCH_CLOCK, PIN_LOW);
		STK_voidDelayus(1);
	}
	/* Send Pulse for Shift Clock*/
	GPIO_voidSetPinValue(STP_BYTE_LATCH_CLOCK, PIN_HIGH);
	STK_voidDelayus(1);
	GPIO_voidSetPinValue(STP_BYTE_LATCH_CLOCK, PIN_LOW);
	STK_voidDelayus(1);
	
}

void STP_voidSendHalfWordSynchronus (u16 Copy_u16Data)
{
	s16 Local_s16Counter;
	u16 Local_u16Bit;
	for(Local_s16Counter = 15; Local_s16Counter >=0; Local_s16Counter--)
	{
		/* Send bit by bit starting from MSb */
		Local_u16Bit = GET_BIT(Copy_u16Data,Local_s16Counter);
		GPIO_voidSetPinValue(STP_SERIAL_DATA, Local_u16Bit);
		
		/* Send Pulse for Shift Clock*/
		GPIO_voidSetPinValue(STP_BIT_LATCH_CLOCK, PIN_HIGH);
		STK_voidDelayus(1);
		GPIO_voidSetPinValue(STP_BIT_LATCH_CLOCK, PIN_LOW);
		STK_voidDelayus(1);
	}
	/* Send Pulse for Shift Clock*/
	GPIO_voidSetPinValue(STP_BYTE_LATCH_CLOCK, PIN_HIGH);
	STK_voidDelayus(1);
	GPIO_voidSetPinValue(STP_BYTE_LATCH_CLOCK, PIN_LOW);
	STK_voidDelayus(1);
}

void STP_voidSendWordSynchronus (u32 Copy_u32Data)
{
	s32 Local_s32Counter;
	u32 Local_u32Bit;
	for(Local_s32Counter = 31; Local_s32Counter >=0; Local_s32Counter--)
	{
		/* Send bit by bit starting from MSb */
		Local_u32Bit = GET_BIT(Copy_u32Data,Local_s32Counter);
		GPIO_voidSetPinValue(STP_SERIAL_DATA, Local_u32Bit);
		
		/* Send Pulse for Shift Clock*/
		GPIO_voidSetPinValue(STP_BIT_LATCH_CLOCK, PIN_HIGH);
		STK_voidDelayus(1);
		GPIO_voidSetPinValue(STP_BIT_LATCH_CLOCK, PIN_LOW);
		STK_voidDelayus(1);
	}
	/* Send Pulse for Shift Clock*/
	GPIO_voidSetPinValue(STP_BYTE_LATCH_CLOCK, PIN_HIGH);
	STK_voidDelayus(1);
	GPIO_voidSetPinValue(STP_BYTE_LATCH_CLOCK, PIN_LOW);
	STK_voidDelayus(1);
}
