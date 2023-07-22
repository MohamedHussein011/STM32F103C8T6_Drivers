/*
 * Name: Mohamed Hussein
 * Layer: HAL
 * Version: V1.0 - 15/10/2021
 *
 */

#ifndef _SEVSEG_INTERFACE_H
#define _SEVSEG_INTERFACE_H


typedef enum {
	cathode,
	anode
}EN_segment_t;

/* Fucntions Prototype */
void SEVSEG_voidInit(u8 Copy_u8PortId, u8 Copy_u8Position);

void SEVSEG_voidSetnumber(u8 Copy_u8PortId, u8 Copy_u8Position, EN_segment_t type, u8 Copy_u8number);

void SEVSEG_voidOFF(u8 Copy_u8PortId, EN_segment_t type, u8 Copy_u8Position);

#endif
