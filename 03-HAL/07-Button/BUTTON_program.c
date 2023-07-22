/*
 * Name: Mohamed Hussein
 * Layer: HAL
 * Version: V1.0 - 15/10/2021
 *
 */

/* Files Inclusion */

/* 1. User Defined Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* 3. MCAL Files */
#include "GPIO_interface.h"

/* 4. ECUAL Files */
#include "BUTTON_interface.h"

/* Functions Definitions */
void BUTTON_voidInit(u8 Copy_u8PortId, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	GPIO_voidSetPinDirection(Copy_u8PortId,Copy_u8Pin, Copy_u8Mode);
}

void BUTTON_voidReadvalue (u8 Copy_u8PortId, u8 Copy_u8Pin, u8 *u8Copy_Value)
{
	GPIO_voidGetPinValue(Copy_u8PortId, Copy_u8Pin, u8Copy_Value);
}
