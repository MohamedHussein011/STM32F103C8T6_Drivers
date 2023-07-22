/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"

void (*TIM2_CallBack[5]) (void) = {NULL};

void TIM2_voidInit (void)
{
	//Direction
#if TIM2_CMS == TIMx_CMS_EDGE_ALIGNED
#if TIM2_DIR == TIMx_DIR_UP
	CLR_BIT(M_TIM2->CR[0],4);		//DIR
#elif TIM2_DIR == TIMx_DIR_DOWN
	SET_BIT(M_TIM2->CR[0],4);		//DIR
#endif
#endif

	//Prescaler
	M_TIM2->PSC = TIM2_PRESCALER - 1;

	//CR1
	M_TIM2->CR[0] |= ((TIM2_ARPE << 7) | (TIM2_CMS << 5)| (TIM2_OPM << 3) | (TIM2_URS << 2) | (TIM2_UDIS << 1));

	//CHANNEL 1
	M_TIM2->CCMR[0] |= ((TIM2_OC1CE << 7) | (TIM2_OC1M << 4) | (TIM2_OC1PE << 3) | (TIM2_OC1FE << 2)
			| (TIM2_CC1S));
	M_TIM2->CCER |= ((TIM2_CC1P << 1) | (TIM2_CC1E));

	//CHANNEL 2
	M_TIM2->CCMR[0] |= ((TIM2_OC2CE << 15) | (TIM2_OC2M << 12) | (TIM2_OC2PE << 11) | (TIM2_OC2FE << 10)
			| (TIM2_CC2S  << 8));
	M_TIM2->CCER |= ((TIM2_CC2P << 5) | (TIM2_CC2E << 4));

	//CHANNEL 3
	M_TIM2->CCMR[1] |= ((TIM2_OC3CE << 7) | (TIM2_OC3M << 4) | (TIM2_OC3PE << 3) | (TIM2_OC3FE << 2)
			| (TIM2_CC3S));
	M_TIM2->CCER |= ((TIM2_CC3P << 9) | (TIM2_CC3E << 8));

	//CHANNEL 4
	M_TIM2->CCMR[1] |= ((TIM2_OC4CE << 15) | (TIM2_OC4M << 12) | (TIM2_OC4PE << 11) | (TIM2_OC4FE << 10)
			| (TIM2_CC4S  << 8));
	M_TIM2->CCER |= ((TIM2_CC4P << 13) | (TIM2_CC4E << 12));

	M_TIM2->CNT = 0;

	//enable the counter
	SET_BIT(M_TIM2->CR[0],0);
}

void TIM2_voidSetPreloadValue (u16 Copy_u16Value)
{
	M_TIM2->ARR = Copy_u16Value;
}

void TIM2_voidSetCompareValue (u8 Copy_u8Channel, u16 Copy_u16Value)
{
	M_TIM2->CCR[Copy_u8Channel - 1] = Copy_u16Value;
}

void TIM2_voidSetValue (u16 Copy_u16Value)
{
	M_TIM2->CNT = Copy_u16Value;
}

u16 TIM2_voidRetValue (void)
{
	return M_TIM2->CNT;
}

void TIM2_voidGenerateEvent (u8 Copy_u8EventID)
{
	SET_BIT(M_TIM2->EGR, Copy_u8EventID);
}

void TIM2_voidGeneratePWM (void)
{
	CLR_BIT(M_TIM2->CR[0], 5);
	CLR_BIT(M_TIM2->CR[0], 6);
	SET_BIT(M_TIM2->CR[0], 4);


}

void TIM2_voidEnableInterrupt (u8 Copy_u8InterruptID)
{
	SET_BIT(M_TIM2->DIER, Copy_u8InterruptID);
}

void TIM2_voidDisableInterrupt (u8 Copy_u8InterruptID)
{
	CLR_BIT(M_TIM2->DIER, Copy_u8InterruptID);
}

void TIM2_voidSetCallBack (u8 Copy_u8InterruptID, void (*TIM2_pvFUNC) (void))
{
	TIM2_CallBack[Copy_u8InterruptID] = TIM2_pvFUNC;
}

/******************************************** ISR **********************************************/
void TIM1_BRK_IRQHandler (void)	//TIM1 Break interrupt
{

}

void TIM1_UP_IRQHandler (void)	//TIM1 Update interrupt
{

}

void TIM1_TRG_COM_IRQHandler (void)		//TIM1 Trigger and Commutation interrupts
{

}

void TIM1_CC_IRQHandler (void)		//TIM1 Capture Compare interrupt
{

}

void TIM2_IRQHandler (void)		//TIM2 global interrupt
{
	if(GET_BIT(M_TIM2->DIER, TIMx_UIE) == 1 && GET_BIT(M_TIM2->SR, TIMx_UIE) == 1)	//Update interrupt
	{
		TIM2_CallBack[TIMx_UIE]();
	}

	if(GET_BIT(M_TIM2->DIER, TIMx_CC1IE) == 1 && GET_BIT(M_TIM2->SR, TIMx_CC1IE) == 1)	//Capture/Compare 1 interrupt
	{
		TIM2_CallBack[TIMx_CC1IE]();
	}

	if(GET_BIT(M_TIM2->DIER, TIMx_CC2IE) == 1 && GET_BIT(M_TIM2->SR, TIMx_CC2IE) == 1)	//Capture/Compare 2 interrupt
	{
		TIM2_CallBack[TIMx_CC2IE]();
	}

	if(GET_BIT(M_TIM2->DIER, TIMx_CC3IE) == 1 && GET_BIT(M_TIM2->SR, TIMx_CC3IE) == 1)	//Capture/Compare 3 interrupt
	{
		TIM2_CallBack[TIMx_CC3IE]();
	}

	if(GET_BIT(M_TIM2->DIER, TIMx_CC4IE) == 1 && GET_BIT(M_TIM2->SR, TIMx_CC4IE) == 1)	//Capture/Compare 4 interrupt
	{
		TIM2_CallBack[TIMx_CC4IE]();
	}

	M_TIM2->SR = 0;
}

void TIM3_IRQHandler (void)		//TIM3 global interrupt
{

}

void TIM4_IRQHandler (void)		//TIM4 global interrupt
{

}
