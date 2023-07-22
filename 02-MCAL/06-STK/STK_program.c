/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/*global callback function for notification function*/
static void (*STK_Callback) (void) = NULL;
/*global variable to hold number of periods*/
static u8 STK_NumOfPeriods;
//flag to indicate periodic ISR
static u8 u8PERIODIC = STK_SINGLE;

void STK_voidInit(void)
{
#if STK_CLKSOURCE == STK_AHB_CLK
	SET_BIT(M_STK->STK_CTRL,2);
#elif STK_CLKSOURCE == STK_AHB_DIVBY8_CLK
	CLR_BIT(M_STK->STK_CTRL,2);
#else
#error  "wrong STK clock source"
#endif

	/*Disable STK interrupt*/
	CLR_BIT(M_STK->STK_CTRL,1);

	/*Enable STK counter*/
	SET_BIT(M_STK->STK_CTRL,0);
}

void STK_voidEnableInterrupt(void)
{
	/*Enable STK interrupt*/
	SET_BIT(M_STK->STK_CTRL,1);
}
void STK_voidDisableInterrupt(void)
{
	/*Disable STK interrupt*/
	CLR_BIT(M_STK->STK_CTRL,1);
}

void STK_voidDelayus(u32 Copy_u32Valueus)
{
	M_STK->STK_VAL = 0;
	
	#if STK_CLKSOURCE == STK_AHB_DIVBY8_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valueus * (STK_RCC_AHB_CLK / 8);
	#elif STK_CLKSOURCE == STK_AHB_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valueus * STK_RCC_AHB_CLK;
	#else
		#error "Wrong SysTick clock source"
	#endif
	
	/*Enable STK counter*/
	SET_BIT(M_STK->STK_CTRL,0);

	/*Busy wait (polling) until the count is over (count flag is raised)*/
	while(GET_BIT(M_STK->STK_CTRL,16) == 0);

	/*Disable STK*/
	CLR_BIT(M_STK->STK_CTRL,0);

	M_STK->STK_LOAD = 0;
	M_STK->STK_VAL = 0;
}

void STK_voidDelayms(u32 Copy_u32Valuems)
{
	M_STK->STK_VAL = 0;
	
	#if STK_CLKSOURCE == STK_AHB_DIVBY8_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valuems * 1000 * (STK_RCC_AHB_CLK / 8);
	#elif STK_CLKSOURCE == STK_AHB_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valuems * 1000 * STK_RCC_AHB_CLK;
	#else
		#error "Wrong SysTick clock source"
	#endif
	
	/*Enable STK counter*/
	SET_BIT(M_STK->STK_CTRL,0);

	/*Busy wait (polling) until the count is over (count flag is raised)*/
	while(GET_BIT(M_STK->STK_CTRL,16) == 0);

	/*Disable STK*/
	CLR_BIT(M_STK->STK_CTRL,0);

	M_STK->STK_LOAD = 0;
	M_STK->STK_VAL = 0;
}

void STK_voidSetInterval(u32 Copy_u32Valueus,u8 Copy_u8NumOfPeriods, void(*Copy_pu8NotificationFunc))
{
	/*Disable STK*/
	CLR_BIT(M_STK->STK_CTRL,0);
	M_STK->STK_VAL = 0;

	/*copy notification function & Number of periods*/
	STK_Callback = Copy_pu8NotificationFunc;
	STK_NumOfPeriods = Copy_u8NumOfPeriods;
	u8PERIODIC = STK_SINGLE;

	#if STK_CLKSOURCE == STK_AHB_DIVBY8_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valueus * (STK_RCC_AHB_CLK / 8);
	#elif STK_CLKSOURCE == STK_AHB_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valueus * STK_RCC_AHB_CLK;
	#else
		#error "Wrong SysTick clock source"
	#endif

	/*Enable STK counter*/
	SET_BIT(M_STK->STK_CTRL,0);

	/*Enable STK interrupt*/
	SET_BIT(M_STK->STK_CTRL,1);
}

void STK_voidSetIntervalPeriodic(u32 Copy_u32Valueus, void(*Copy_pu8NotificationFunc))
{
	/*Disable STK*/
	CLR_BIT(M_STK->STK_CTRL,0);
	M_STK->STK_VAL = 0;

	/*copy notification function & Number of periods*/
	STK_Callback = Copy_pu8NotificationFunc;
	u8PERIODIC = STK_PERIODIC;

	#if STK_CLKSOURCE == STK_AHB_DIVBY8_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valueus * (STK_RCC_AHB_CLK / 8);
	#elif STK_CLKSOURCE == STK_AHB_CLK
	/*load the value (ticks) in load register*/
	M_STK->STK_LOAD = Copy_u32Valueus * STK_RCC_AHB_CLK;
	#else
		#error "Wrong SysTick clock source"
	#endif

	/*Enable STK counter*/
	SET_BIT(M_STK->STK_CTRL,0);

	/*Enable STK interrupt*/
	SET_BIT(M_STK->STK_CTRL,1);
}

u32  STK_u32GetElapsedTime(void)
{
	return (M_STK->STK_LOAD - M_STK->STK_VAL);
}

u32  STK_u32GetRemainingTime(void)
{
	return M_STK->STK_VAL;
}

void STK_voidStopInterval(void)
{
	/*Disable STK interrupt*/
	CLR_BIT(M_STK->STK_CTRL,1);

	/*Disable STK*/
	CLR_BIT(M_STK->STK_CTRL,0);

	M_STK->STK_LOAD = 0;
	M_STK->STK_VAL = 0;
}

void SysTick_Handler (void)
{	
	if(u8PERIODIC == STK_PERIODIC)
	{
		/*invoke the notification function*/
		STK_Callback();
	}
	else if(u8PERIODIC == STK_SINGLE)
	{
		/*decrement the STK_NumOfPeriods
		* if it's equal to zero --> invoke the notification function
		* else do nothing
		*/
		/*invoke the notification function*/
		STK_Callback();
	
		/*decrement the STK_NumOfPeriods*/
		STK_NumOfPeriods--;
	
		/*if it's equal to zero --> stop timer*/
		if(STK_NumOfPeriods == 0)
		{
			STK_voidStopInterval();
		}
	}

}
