/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void AFIO_voidEnablePortEvent (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	M_AFIO->AFIO_EVCR &= ~(0x7F);   //zero all first 7 bits
	M_AFIO->AFIO_EVCR |= ((Copy_u8Port<<4) | Copy_u8Pin);
	
	SET_BIT(M_AFIO->AFIO_EVCR, EVCR_EVOE);
}

void AFIO_voidDisablePortEvent (void)
{
	CLR_BIT(M_AFIO->AFIO_EVCR, EVCR_EVOE);
}

void AFIO_voidSetEXTIConfiguration (u8 Copy_u8Line, u8 Copy_u8Port)
{
	u8 Local_u8RegisterIndex = 0;
	Local_u8RegisterIndex = Copy_u8Line / 4;
	Copy_u8Line %= 4;
	
	M_AFIO->AFIO_EXTICR[Local_u8RegisterIndex] &= ~(0b1111 << (Copy_u8Line * 4));
	M_AFIO->AFIO_EXTICR[Local_u8RegisterIndex] |= (Copy_u8Port << (Copy_u8Line * 4));
	
}

void AFIO_voidREMAP (u8 Copy_u8Peripheral, u8 Copy_u8REMAP)
{
	M_AFIO->AFIO_MAPR |= (Copy_u8REMAP << Copy_u8Peripheral);
}
