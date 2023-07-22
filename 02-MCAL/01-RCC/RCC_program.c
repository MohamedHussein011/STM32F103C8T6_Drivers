/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 03/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	u32 Local_u32Timeout = 0;

#if RCC_CLOCK_TYPE == RCC_HSI
	/*choose HSI as system clock*/
	CLR_BIT(M_RCC->CFGR, 0);
	CLR_BIT(M_RCC->CFGR, 1);
	/*Enable HSI + default Trimming = 16*/
	SET_BIT(M_RCC->CR, 0);
	SET_BIT(M_RCC->CR, 7);
	/*check if HSI clock is stable or not*/
	while( (GET_BIT(M_RCC->CR, 1) == 0) && (Local_u32Timeout < 10000) )
	{
		Local_u32Timeout++;
	}

	if(Local_u32Timeout >= 10000)
	{
		/*Timeout*/
	}
#elif RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	/*choose HSE as system clock*/
	SET_BIT(M_RCC->CFGR, 0);
	CLR_BIT(M_RCC->CFGR, 1);
	/*Enable HSE with no bypass */
	SET_BIT(M_RCC->CR, 16);
	CLR_BIT(M_RCC->CR, 18);
	while( (GET_BIT(M_RCC->CR, 17) == 0) && (Local_u32Timeout < 10000) )
	{
		Local_u32Timeout++;
	}
	if(Local_u32Timeout >= 10000)
	{
		/*Timeout*/
	}
#elif RCC_CLOCK_TYPE == RCC_HSE_RC
	/*to choose bypass, HSE must be disabled first so it can be written*/
	CLR_BIT(M_RCC->CR, 16);
	/*choose bypass */
	SET_BIT(M_RCC->CR, 18);
	/*choose HSE as system clock*/
	SET_BIT(M_RCC->CFGR, 0);
	CLR_BIT(M_RCC->CFGR, 1);
	/*Enable HSE*/
	SET_BIT(M_RCC->CR, 16);
	while( (GET_BIT(M_RCC->CR, 17) == 0) && (Local_u32Timeout < 10000) )
	{
		Local_u32Timeout++;
	}
	if(Local_u32Timeout >= 10000)
	{
		/*Timeout*/
	}
#elif RCC_CLOCK_TYPE == RCC_PLL
	/*choose PLL as system clock*/
	CLR_BIT(M_RCC->CFGR, 0);
	SET_BIT(M_RCC->CFGR, 1);

	/* Choosing The Multiplication Factor For PLL */
#if (RCC_PLL_MUL_VAL >= RCC_PLL_MUL_BY_2) && (RCC_PLL_MUL_VAL <= RCC_PLL_MUL_BY_16)
	M_RCC->CFGR &= RCC_PLL_MUL_MASK;
	M_RCC->CFGR |= (RCC_PLL_MUL_VAL << 18);
#else
#error ("Wrong Multiplication Factor For PLL.")
#endif  //end if for PLL clock

	/*choose HSI or HSE as PLL input source*/
#if RCC_PLL_IN_CLOCK == RCC_PLL_IN_HSI_DIV_BY_2
	/*Enable HSI*/
	SET_BIT(M_RCC->CR, 0);
	/* PLL Entery Clock Source Is HSI Divided By 2 */
	CLR_BIT(M_RCC->CFGR, 16);
#elif RCC_PLL_IN_CLOCK == RCC_PLL_IN_HSE_DIV_BY_2
	/*Enable HSE*/
	SET_BIT(M_RCC->CR, 16);
	/*HSE is divided by 2*/
	SET_BIT(M_RCC->CFGR, 17);
	/* PLL Entery Clock Source Is HSE*/
	SET_BIT(M_RCC->CFGR, 16);
#elif RCC_PLL_IN_CLOCK == RCC_PLL_IN_HSE
	/*Enable HSE*/
	SET_BIT(M_RCC->CR, 16);
	/*HSE is divided by 2*/
	CLR_BIT(M_RCC->CFGR, 17);
	/* PLL Entery Clock Source Is HSE*/
	SET_BIT(M_RCC->CFGR, 16);
#else
#error ("Wrong PLL input source.")
#endif //end if for PLL input source

	/*Enable PLL*/
	SET_BIT(M_RCC->CR, 24);
	while( (GET_BIT(M_RCC->CR, 25) == 0) && (Local_u32Timeout < 10000) )
	{
		Local_u32Timeout++;
	}
	if(Local_u32Timeout >= 10000)
	{
		/*Timeout*/
	}

#else
#error ("Wrong System Clock choice.")
#endif     //end if for RCC clock type

	/*for Clock security system*/
#if RCC_CLOCK_SECURITY == RCC_CSS_DISABLE
	CLR_BIT(M_RCC->CR, 19);
#elif RCC_CLOCK_SECURITY == RCC_CSS_ENABLE
	SET_BIT(M_RCC->CR, 19);
#else
#error ("Wrong Clock security system choice.")
#endif

	/*for AHB prescaler*/
#if (RCC_AHB_PRESCALER >= RCC_AHB_NOT_DIVIDED) &&  (RCC_AHB_PRESCALER <= RCC_AHB_DIV_BY_512)
	M_RCC->CFGR &= RCC_AHB_PRESCALER_MASK;
	M_RCC->CFGR |= (RCC_AHB_PRESCALER << 4);
#else
#error ("Wrong AHB prescaler choice.")
#endif

	/*for APB1 prescaler*/
#if (RCC_APB1_PRESCALER >= RCC_APB1_NOT_DIVIDED) &&  (RCC_APB1_PRESCALER <= RCC_APB1_DIV_BY_16)
	M_RCC->CFGR &= RCC_APB1_PRESCALER_MASK;
	M_RCC->CFGR |= (RCC_APB1_PRESCALER << 8);
#else
#error ("Wrong APB1 prescaler choice.")
#endif

	/*for APB2 prescaler*/
#if (RCC_APB2_PRESCALER >= RCC_APB2_NOT_DIVIDED) &&  (RCC_APB2_PRESCALER <= RCC_APB2_DIV_BY_16)
	M_RCC->CFGR &= RCC_APB2_PRESCALER_MASK;
	M_RCC->CFGR |= (RCC_APB2_PRESCALER << 11);
#else
#error ("Wrong APB2 prescaler choice.")
#endif

	/*for ADC prescaler*/
#if (RCC_ADC_PRESCALER >= RCC_ADC_DIV_BY_2) &&  (RCC_ADC_PRESCALER <= RCC_ADC_DIV_BY_8)
	M_RCC->CFGR &= RCC_ADC_PRESCALER_MASK;
	M_RCC->CFGR |= (RCC_ADC_PRESCALER << 14);
#else
#error ("Wrong APB1 prescaler choice.")
#endif
}

void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB : SET_BIT(M_RCC->AHBENR , Copy_u8PerId);     break;
		case RCC_APB1: SET_BIT(M_RCC->APB1ENR, Copy_u8PerId);     break;
		case RCC_APB2: SET_BIT(M_RCC->APB2ENR, Copy_u8PerId);     break;
		}
	}
	else
	{
		/*return error*/
	}
}

void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB : CLR_BIT(M_RCC->AHBENR , Copy_u8PerId);     break;
		case RCC_APB1: CLR_BIT(M_RCC->APB1ENR, Copy_u8PerId);     break;
		case RCC_APB2: CLR_BIT(M_RCC->APB2ENR, Copy_u8PerId);     break;
		}
	}
	else
	{
		/*return error*/
	}
}

void RCC_voidResetPeripheral (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_APB1: SET_BIT(M_RCC->APB1RSTR,Copy_u8PerId);     break;
		case RCC_APB2: SET_BIT(M_RCC->APB2RSTR,Copy_u8PerId);     break;
		}
	}
	else
	{
		/*error*/
	}
}
