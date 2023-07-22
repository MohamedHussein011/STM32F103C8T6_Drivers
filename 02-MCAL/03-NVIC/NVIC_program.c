/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidEnableInterrupt (u8 Copy_u8InterruptID)
{
	//interrupt range from 0 to 31
	if(Copy_u8InterruptID <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8InterruptID);
	}
	//interrupt range from 32 to 63
	else if (Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ISER1 = (1 << Copy_u8InterruptID);
	}
}

void NVIC_voidDisableInterrupt (u8 Copy_u8InterruptID)
{
	//interrupt range from 0 to 31
	if(Copy_u8InterruptID <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8InterruptID);
	}
	//interrupt range from 32 to 63
	else if (Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ICER1 = (1 << Copy_u8InterruptID);
	}
}

void NVIC_voidSetPendingFlag (u8 Copy_u8InterruptID)
{
	//interrupt range from 0 to 31
	if(Copy_u8InterruptID <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptID);
	}
	//interrupt range from 32 to 63
	else if (Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ISPR1 = (1 << Copy_u8InterruptID);
	}
}

void NVIC_voidClearPendingFlag (u8 Copy_u8InterruptID)
{
	//interrupt range from 0 to 31
	if(Copy_u8InterruptID <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8InterruptID);
	}
	//interrupt range from 32 to 63
	else if (Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ICPR1 = (1 << Copy_u8InterruptID);
	}
}

void NVIC_voidGetActiveFlag    (u8 Copy_u8InterruptID, u8* Copy_u8Value)
{
	//interrupt range from 0 to 31
	if(Copy_u8InterruptID <= 31)
	{
		*Copy_u8Value = GET_BIT(NVIC_IABR0, Copy_u8InterruptID);
	}
	//interrupt range from 32 to 63
	else if (Copy_u8InterruptID <= 59)
	{
		Copy_u8InterruptID -= 32;
		*Copy_u8Value = GET_BIT(NVIC_IABR1, Copy_u8InterruptID);
	}
}

void NVIC_voidSetPriority      (u8 Copy_u8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
#if NVIC_PRIORITY_GROUP == GROUP_4BITS_SUB_0BITS
	if(Copy_u8GroupPriority <= Group_Priority15)
	{
		NVIC_IPRx[Copy_u8InterruptID] = Copy_u8GroupPriority << 4;
	}
	else
	{
		/*error*/
	}
#elif NVIC_PRIORITY_GROUP == GROUP_3BITS_SUB_1BITS
	if((Copy_u8GroupPriority <= Group_Priority7) && (Copy_u8SubPriority <= Sub_Priority1))
	{
		NVIC_IPRx[Copy_u8InterruptID] = ((Copy_u8GroupPriority << 5) | (Copy_u8SubPriority << 4));
	}
	else
	{
		/*error*/
	}
#elif NVIC_PRIORITY_GROUP == GROUP_2BITS_SUB_2BITS
	if((Copy_u8GroupPriority <= Group_Priority3) && (Copy_u8SubPriority <= Sub_Priority3))
	{
		NVIC_IPRx[Copy_u8InterruptID] = ((Copy_u8GroupPriority << 6) | (Copy_u8SubPriority << 4));
	}
	else
	{
		/*error*/
	}
#elif NVIC_PRIORITY_GROUP == GROUP_1BITS_SUB_3BITS
	if((Copy_u8GroupPriority <= Group_Priority1) && (Copy_u8SubPriority <= Sub_Priority7))
	{
		NVIC_IPRx[Copy_u8InterruptID] = ((Copy_u8GroupPriority << 7) | (Copy_u8SubPriority << 4));
	}
	else
	{
		/*error*/
	}
#elif NVIC_PRIORITY_GROUP == GROUP_0BITS_SUB_4BITS
	if(Copy_u8SubPriority <= Sub_Priority15)
	{
		NVIC_IPRx[Copy_u8InterruptID] = Copy_u8SubPriority << 4;
	}
	else
	{
		/*error*/
	}
#else
#error "Wrong Group priority choice"
#endif

	SCB_AIRCR = NVIC_PRIORITY_GROUP;
}

void NVIC_voidSoftwareTrigger (u8 Copy_u8InterruptID)
{
	NVIC_STIR &= ~0x1FF;
	NVIC_STIR  = Copy_u8InterruptID;
}
