/*
 * Name: Mohamed Hussein
 * Layer: HAL
 * Version: V1.0 - 15/10/2021
 *
 */

#ifndef _BUTTON_INTERFACE_H
#define _BUTTON_INTERFACE_H


/* Fucntions Prototype */

void BUTTON_voidInit(u8 Copy_u8PortId, u8 Copy_u8Pin, u8 Copy_u8Mode);
void BUTTON_voidReadvalue (u8 Copy_u8PortId, u8 Copy_u8Pin, u8 *u8Copy_Value);

#endif
