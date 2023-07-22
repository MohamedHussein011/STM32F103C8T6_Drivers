/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*define array of 15 pointers to function to hold the callback function*/
static void (*EXTI_Callback[15]) (void) = {NULL};

void EXTI_voidEnable (u8 Copy_u8Line)
{
	if(Copy_u8Line <= EXTI_LINE15)
	{
		SET_BIT(M_EXTI->EXTI_IMR, Copy_u8Line);
	}

}

void EXTI_voidDisable (u8 Copy_u8Line)
{
	if(Copy_u8Line <= EXTI_LINE15)
	{
		CLR_BIT(M_EXTI->EXTI_IMR, Copy_u8Line);
	}

}

void EXTI_voidSoftwareTrigger (u8 Copy_u8Line)
{
	if(Copy_u8Line <= EXTI_LINE15)
	{
		SET_BIT(M_EXTI->EXTI_IMR, Copy_u8Line);
		SET_BIT(M_EXTI->EXTI_SWIER, Copy_u8Line);
	}

}

void EXTI_voidSetMode (u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
	case EXTI_RISING_EDGE :  SET_BIT(M_EXTI->EXTI_RTSR, Copy_u8Line);   break;
	case EXTI_FALLING_EDGE:  SET_BIT(M_EXTI->EXTI_FTSR, Copy_u8Line);   break;
	case EXTI_ON_CHANGE :    SET_BIT(M_EXTI->EXTI_RTSR, Copy_u8Line);
	SET_BIT(M_EXTI->EXTI_FTSR, Copy_u8Line);   break;

	}
}

void EXTI_voidSetCallback (u8 Copy_u8Line, void (*Copy_pvFunc)(void))
{
	EXTI_Callback[Copy_u8Line] = Copy_pvFunc;
}

/*****************************************		ISR			*************************************************/
//ISR for External Interrupt Line 0
void EXTI0_IRQHandler (void)
{
	/*Invoke the function*/
	EXTI_Callback[EXTI_LINE0]();

	/*clear the pending flag*/
	SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE0);
}

//ISR for External Interrupt Line 1
void EXTI1_IRQHandler (void)
{
	/*Invoke the function*/
	EXTI_Callback[EXTI_LINE1]();

	/*clear the pending flag*/
	SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE1);
}

//ISR for External Interrupt Line 2
void EXTI2_IRQHandler (void)
{
	/*Invoke the function*/
	EXTI_Callback[EXTI_LINE2]();

	/*clear the pending flag*/
	SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE2);
}

//ISR for External Interrupt Line 3
void EXTI3_IRQHandler (void)
{
	/*Invoke the function*/
	EXTI_Callback[EXTI_LINE3]();

	/*clear the pending flag*/
	SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE3);
}

//ISR for External Interrupt Line 4
void EXTI4_IRQHandler (void)
{
	/*Invoke the function*/
	EXTI_Callback[EXTI_LINE4]();

	/*clear the pending flag*/
	SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE4);
}

//ISR for External Interrupt Line 5 to 9
void EXTI9_5_IRQHandler (void)
{
	if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE5) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE5]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE5);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE6) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE6]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE6);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE7) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE7]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE7);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE8) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE8]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE8);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE9) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE9]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE9);
	}
}

//ISR for External Interrupt Line 10 to 15
void EXTI15_10_IRQHandler (void)
{
	if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE10) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE10]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE10);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE11) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE11]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE11);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE12) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE12]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE12);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE13) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE13]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE13);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE14) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE14]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE14);
	}
	else if(GET_BIT(M_EXTI->EXTI_PR,EXTI_LINE15) == 1)
	{
		/*Invoke the function*/
		EXTI_Callback[EXTI_LINE15]();

		/*clear the pending flag*/
		SET_BIT(M_EXTI->EXTI_PR,EXTI_LINE15);
	}
}
