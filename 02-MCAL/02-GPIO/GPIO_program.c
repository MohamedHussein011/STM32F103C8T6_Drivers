/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 08/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode )
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Pin <= 7)
		{
			if(Copy_u8Mode == INPUT_PULLUP_MODE)
			{
				M_GPIOA->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOA->CRL |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				SET_BIT(M_GPIOA->ODR,Copy_u8Pin);
			}
			else if(Copy_u8Mode == INPUT_PULLDOWN_MODE)
			{
				M_GPIOA->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOA->CRL |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				CLR_BIT(M_GPIOA->ODR,Copy_u8Pin);
			}
			else
			{
				M_GPIOA->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOA->CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
			}
		}
		else if (Copy_u8Pin <= 15)
		{
			Copy_u8Pin -= 8;
			if(Copy_u8Mode == INPUT_PULLUP_MODE)
			{
				M_GPIOA->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOA->CRH |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				SET_BIT(M_GPIOA->ODR,Copy_u8Pin);
			}
			else if(Copy_u8Mode == INPUT_PULLDOWN_MODE)
			{
				M_GPIOA->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOA->CRH |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				CLR_BIT(M_GPIOA->ODR,Copy_u8Pin);
			}
			else
			{
				M_GPIOA->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOA->CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
			}
		}
		break;

	case GPIOB:
		if(Copy_u8Pin <= 7)
		{
			if(Copy_u8Mode == INPUT_PULLUP_MODE)
			{
				M_GPIOB->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOB->CRL |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				SET_BIT(M_GPIOB->ODR,Copy_u8Pin);
			}
			else if(Copy_u8Mode == INPUT_PULLDOWN_MODE)
			{
				M_GPIOB->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOB->CRL |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				CLR_BIT(M_GPIOB->ODR,Copy_u8Pin);
			}
			else
			{
				M_GPIOB->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOB->CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
			}
		}
		else if (Copy_u8Pin <= 15)
		{
			Copy_u8Pin -= 8;
			if(Copy_u8Mode == INPUT_PULLUP_MODE)
			{
				M_GPIOB->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOB->CRH |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				SET_BIT(M_GPIOB->ODR,Copy_u8Pin);
			}
			else if(Copy_u8Mode == INPUT_PULLDOWN_MODE)
			{
				M_GPIOB->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOB->CRH |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				CLR_BIT(M_GPIOB->ODR,Copy_u8Pin);
			}
			else
			{
				M_GPIOB->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOB->CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
			}
		}
		break;

	case GPIOC:
		if(Copy_u8Pin <= 7)
		{
			if(Copy_u8Mode == INPUT_PULLUP_MODE)
			{
				M_GPIOC->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOC->CRL |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				SET_BIT(M_GPIOC->ODR,Copy_u8Pin);
			}
			else if(Copy_u8Mode == INPUT_PULLDOWN_MODE)
			{
				M_GPIOC->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOC->CRL |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				CLR_BIT(M_GPIOC->ODR,Copy_u8Pin);
			}
			else
			{
				M_GPIOC->CRL &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOC->CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
			}
		}
		else if (Copy_u8Pin <= 15)
		{
			Copy_u8Pin -= 8;
			if(Copy_u8Mode == INPUT_PULLUP_MODE)
			{
				M_GPIOC->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOC->CRH |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				SET_BIT(M_GPIOC->ODR,Copy_u8Pin);
			}
			else if(Copy_u8Mode == INPUT_PULLDOWN_MODE)
			{
				M_GPIOC->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOC->CRH |= (INPUT_PULLUP_PULLDOWN_MODE << (Copy_u8Pin * 4));
				CLR_BIT(M_GPIOC->ODR,Copy_u8Pin);
			}
			else
			{
				M_GPIOC->CRH &= ~(0b1111 << (Copy_u8Pin * 4));       //reset the corresponding 4 bits
				M_GPIOC->CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
			}
		}
		break;
	}
}

void GPIO_voidSetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Value == PIN_HIGH)
		{
			M_GPIOA->BSRR = (1<<Copy_u8Pin);
		}
		else if(Copy_u8Value == PIN_LOW)
		{
			M_GPIOA->BRR = (1<<Copy_u8Pin);
		}
		break;

	case GPIOB:
		if(Copy_u8Value == PIN_HIGH)
		{
			M_GPIOB->BSRR = (1<<Copy_u8Pin);
		}
		else if(Copy_u8Value == PIN_LOW)
		{
			M_GPIOB->BRR = (1<<Copy_u8Pin);
		}
		break;

	case GPIOC:
		if(Copy_u8Value == PIN_HIGH)
		{
			M_GPIOC->BSRR = (1<<Copy_u8Pin);
		}
		else if(Copy_u8Value == PIN_LOW)
		{
			M_GPIOC->BRR = (1<<Copy_u8Pin);
		}
		break;
	}
}

void GPIO_voidGetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		*Copy_pu8Value = GET_BIT(M_GPIOA->IDR, Copy_u8Pin);
		break;

	case GPIOB:
		*Copy_pu8Value = GET_BIT(M_GPIOB->IDR, Copy_u8Pin);
		break;

	case GPIOC:
		*Copy_pu8Value = GET_BIT(M_GPIOC->IDR, Copy_u8Pin);
		break;
	}
}

void GPIO_voidTogglePin       (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		TOG_BIT(M_GPIOA->ODR, Copy_u8Pin);
		break;

	case GPIOB:
		TOG_BIT(M_GPIOB->ODR, Copy_u8Pin);
		break;

	case GPIOC:
		TOG_BIT(M_GPIOC->ODR, Copy_u8Pin);
		break;
	}
}

void GPIO_voidSetHalfPortDirection (u8 Copy_u8Port, u8 Copy_u8Position, u8 Copy_u8Mode )
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if 		(Copy_u8Position == PORT_LOW ) {M_GPIOA->CRL = (0x11111111 * Copy_u8Mode); }
		else if (Copy_u8Position == PORT_HIGH) {M_GPIOA->CRH = (0x11111111 * Copy_u8Mode); }

		break;

	case GPIOB:
		if 		(Copy_u8Position == PORT_LOW ) {M_GPIOB->CRL = (0x11111111 * Copy_u8Mode); }
		else if (Copy_u8Position == PORT_HIGH) {M_GPIOB->CRH = (0x11111111 * Copy_u8Mode); }

		break;

	case GPIOC:
		if 		(Copy_u8Position == PORT_LOW ) {M_GPIOC->CRL = (0x11111111 * Copy_u8Mode); }
		else if (Copy_u8Position == PORT_HIGH) {M_GPIOC->CRH = (0x11111111 * Copy_u8Mode); }

		break;
	}

}

void GPIO_voidSetHalfPortValue    (u8 Copy_u8Port, u8 Copy_u8Position, u16 Copy_u16Value)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		if 		(Copy_u8Position == PORT_LOW ) {M_GPIOA->ODR = ((M_GPIOA->ODR) & 0xFF00) | ((u8)Copy_u16Value); }
		else if (Copy_u8Position == PORT_HIGH) {M_GPIOA->ODR = ((M_GPIOA->ODR) & 0x00FF) | (     Copy_u16Value); }

		break;

	case GPIOB:
		if 		(Copy_u8Position == PORT_LOW ) {M_GPIOB->ODR = ((M_GPIOB->ODR) & 0xFF00) | ((u8)Copy_u16Value); }
		else if (Copy_u8Position == PORT_HIGH) {M_GPIOB->ODR = ((M_GPIOB->ODR) & 0x00FF) | (     Copy_u16Value); }

		break;

	case GPIOC:
		if 		(Copy_u8Position == PORT_LOW ) {M_GPIOC->ODR = ((M_GPIOC->ODR) & 0xFF00) | ((u8)Copy_u16Value); }
		else if (Copy_u8Position == PORT_HIGH) {M_GPIOC->ODR = ((M_GPIOC->ODR) & 0x00FF) | (     Copy_u16Value); }

		break;
	}
}

void GPIO_voidGetHlafPortValue     (u8 Copy_u8Port, u8 Copy_u8Position, u16* Copy_pu16Value)
{

	switch(Copy_u8Port)
	{
	case GPIOA:
		*Copy_pu16Value = M_GPIOA->IDR;
		if 		(Copy_u8Position == PORT_LOW ) {*Copy_pu16Value &= 0x00FF; }
		else if (Copy_u8Position == PORT_HIGH) {*Copy_pu16Value &= 0xFF00; }

		break;

	case GPIOB:
		*Copy_pu16Value = M_GPIOB->IDR;
		if 		(Copy_u8Position == PORT_LOW ) {*Copy_pu16Value &= 0x00FF; }
		else if (Copy_u8Position == PORT_HIGH) {*Copy_pu16Value &= 0xFF00; }

		break;

	case GPIOC:
		*Copy_pu16Value = M_GPIOC->IDR;
		if 		(Copy_u8Position == PORT_LOW ) {*Copy_pu16Value &= 0x00FF; }
		else if (Copy_u8Position == PORT_HIGH) {*Copy_pu16Value &= 0xFF00; }

		break;
	}
}

void GPIO_voidSetPortDirection (u8 Copy_u8Port, u8 Copy_u8Mode )
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		M_GPIOA->CRL = (0x11111111 * Copy_u8Mode);
		M_GPIOA->CRH = (0x11111111 * Copy_u8Mode);
		break;

	case GPIOB:
		M_GPIOB->CRL = (0x11111111 * Copy_u8Mode);
		M_GPIOB->CRH = (0x11111111 * Copy_u8Mode);
		break;

	case GPIOC:
		M_GPIOC->CRL = (0x11111111 * Copy_u8Mode);
		M_GPIOC->CRH = (0x11111111 * Copy_u8Mode);
		break;
	}
}
void GPIO_voidSetPortValue     (u8 Copy_u8Port, u16 Copy_u16Value)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		M_GPIOA->ODR = Copy_u16Value;
		break;

	case GPIOB:
		M_GPIOB->ODR = Copy_u16Value;
		break;

	case GPIOC:
		M_GPIOC->ODR = Copy_u16Value;
		break;
	}
}
void GPIO_voidGetPortValue     (u8 Copy_u8Port, u16* Copy_pu16Value)
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		*Copy_pu16Value = M_GPIOA->IDR;

		break;

	case GPIOB:
		*Copy_pu16Value = M_GPIOB->IDR;

		break;

	case GPIOC:
		*Copy_pu16Value = M_GPIOC->IDR;

		break;
	}
}
