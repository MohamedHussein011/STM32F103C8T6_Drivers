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

/* 4. HAL Files */
#include "SEVSEG_interface.h"

/* Numbers to be printed on SSD */
static u8 u8sev_seg[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

void SEVSEG_voidInit(u8 Copy_u8PortId, u8 Copy_u8Position)
{
	GPIO_voidSetHalfPortDirection(Copy_u8PortId, Copy_u8Position, OUTPUT_2MHZ_PUSH_PULL);
}

void SEVSEG_voidSetnumber(u8 Copy_u8PortId, u8 Copy_u8Position, EN_segment_t type, u8 Copy_u8number)
{
	switch (type){
	case cathode: GPIO_voidSetHalfPortValue(Copy_u8PortId, Copy_u8Position, u8sev_seg[Copy_u8number]);   break;
	case anode:   GPIO_voidSetHalfPortValue(Copy_u8PortId, Copy_u8Position, ~u8sev_seg[Copy_u8number]);  break;
	default:   break;
	}
}

void SEVSEG_voidOFF(u8 Copy_u8PortId, EN_segment_t type, u8 Copy_u8Position)
{
	switch (type){
	case cathode: GPIO_voidSetHalfPortValue(Copy_u8PortId, Copy_u8Position, 0x00);   break;
	case anode:   GPIO_voidSetHalfPortValue(Copy_u8PortId, Copy_u8Position, 0xFF);  break;
	default:   break;
	}
}
