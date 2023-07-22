/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"

void FPEC_voidEraseAppArea (void)
{
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = FPEC_BOOTLOADER_SIZE; Local_u8Counter < FPEC_FLASH_SIZE; Local_u8Counter++)
	{
		FPEC_voidFlashPageErase(Local_u8Counter);
	}
}

void FPEC_voidFlashPageErase (u8 Copy_u8PageNumber)
{
	/* Polling on BSY bit in SR to make sure no operation is going on */
	while(GET_BIT(M_FPEC->SR, 0) == 1);
	
	/* check if the flash is locked or no*/
	if(GET_BIT(M_FPEC->CR, 7) == 1)
	{
		//unlock
		M_FPEC->KEYR = 0x45670123;
		M_FPEC->KEYR = 0xCDEF89AB;
	}
	
	/*set Page erase bit*/
	SET_BIT(M_FPEC->CR, 1);
	
	/*write page address*/
	M_FPEC->AR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000;
	
	/*start the operation*/
	SET_BIT(M_FPEC->CR, 6);
	
	/* Polling on BSY bit in SR to make sure no operation is going on */
	while(GET_BIT(M_FPEC->SR, 0) == 1);
	
	/*clear flag for end of operation & clear bit for the page erase*/
	SET_BIT(M_FPEC->SR, 5);
	CLR_BIT(M_FPEC->CR, 1);
}

void FPEC_voidFlashWriteHalfWord (u32 Copy_u32Address, u16* Copy_pu16Data, u8 Copy_u8Length)
{
	u8 Local_u8Counter = 0;
	
	/* Polling on BSY bit in SR to make sure no operation is going on */
	while(GET_BIT(M_FPEC->SR, 0) == 1);
	
	/* check if the flash is locked or no*/
	if(GET_BIT(M_FPEC->CR, 7) == 1)
	{
		//unlock
		M_FPEC->KEYR = 0x45670123;
		M_FPEC->KEYR = 0xCDEF89AB;
	}
	
	for(Local_u8Counter = 0; Local_u8Counter < Copy_u8Length; Local_u8Counter++)
	{
		/*set programming bit*/
		SET_BIT(M_FPEC->CR, 0);
		
		/*write half word*/
		*((volatile u16*)Copy_u32Address) = Copy_pu16Data[Local_u8Counter];
		Copy_u32Address+=2;
		
		/* Polling on BSY bit in SR to make sure no operation is going on */
		while(GET_BIT(M_FPEC->SR, 0) == 1);
		
		/*clear flag for end of operation & clear bit for the page erase*/
		SET_BIT(M_FPEC->SR, 5);
		CLR_BIT(M_FPEC->CR, 0);
	}
	
}