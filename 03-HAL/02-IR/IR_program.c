/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 24/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "AFIO_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

//define start flag to indicate start of the frame
volatile u8 u8SartFlag = 0;
//define counter to indicate number of bits
volatile u8 u8Counter = 0;
//define array to bits of the frame
volatile u32 u32DataFrame[50] = {0};
//define variable to indicate bits of the frame command
volatile u8 u8Command = 0;
//define array of 15 pointers to functions
static void (*IR_pvFunc[11]) (void) = {NULL};
//define ticks in us input to SysTick
u32 u32Ticksus = IR_SysTick_Clock * IR_FRAME_TIME;

void IR_voidInit(void)
{
	GPIO_voidSetPinDirection(IR_PORT,IR_PIN,INPUT_FLOATING_MODE);
	AFIO_voidEnablePortEvent(IR_PORT,IR_PIN);
	AFIO_voidSetEXTIConfiguration(IR_EXTI,IR_PORT);
	EXTI_voidSetCallback(IR_EXTI, IR_voidGetFrame);
	EXTI_voidSetMode(IR_EXTI,EXTI_FALLING_EDGE);
	STK_voidInit();
	EXTI_voidEnable(IR_EXTI);
	STK_voidEnableInterrupt();
}

static void IR_voidGetFrame (void)
{
	if(u8SartFlag == 0)
	{
		STK_voidSetInterval(u32Ticksus,1, IR_voidEstimateData);
		u8SartFlag = 1;
	}
	else
	{
		u32DataFrame[u8Counter] = STK_u32GetElapsedTime();
		STK_voidSetInterval(u32Ticksus,1, IR_voidEstimateData);
		u8Counter++;
	}
}

static void IR_voidEstimateData (void)
{
	u8Command = 0;
	//check the start of the frame
	if((u32DataFrame[0] >= (10000 * IR_SysTick_Clock)) && (u32DataFrame[0] <= (14000 * IR_SysTick_Clock)))
	{
		for(u8 i=0; i<8; i++)
		{
			//check if the bit is 1 or not
			if((u32DataFrame[17+i] >= (2000 * IR_SysTick_Clock)) && (u32DataFrame[17+i] <= (2300 * IR_SysTick_Clock)))
			{
				SET_BIT(u8Command,i);
			}
			else
			{
				CLR_BIT(u8Command,i);
			}
		}
		//invoke the function to be executed 
		switch(u8Command)
		{
			case IR_OFF: IR_pvFunc[0]();
			break;
			case IR_0: IR_pvFunc[1]();
			break;                 
			case IR_1: IR_pvFunc[2]();
			break;                 
			case IR_2: IR_pvFunc[3]();
			break;                 
			case IR_3: IR_pvFunc[4]();
			break;                 
			case IR_4: IR_pvFunc[5]();
			break;                 
			case IR_5: IR_pvFunc[6]();
			break;                 
			case IR_6: IR_pvFunc[7]();
			break;                 
			case IR_7: IR_pvFunc[8]();
			break;                 
			case IR_8: IR_pvFunc[9]();
			break;
			case IR_9: IR_pvFunc[10]();
			break;
		}
	}
	
	//Zero every variables to hold new frame
	u8Command = 0;
	u8Counter = 0;
	u8SartFlag = 0;
	u32DataFrame[0] = 0;
}

void IR_voidTakeAction (u8 Copy_u8Button, void (*Copy_pvFunc) (void))
{
	switch(Copy_u8Button)
	{
		case IR_OFF: IR_pvFunc[0] = Copy_pvFunc;
		break;
		case IR_0: IR_pvFunc[1] = Copy_pvFunc;
		break;
		case IR_1: IR_pvFunc[2] = Copy_pvFunc;
		break;
		case IR_2: IR_pvFunc[3] = Copy_pvFunc;
		break;
		case IR_3: IR_pvFunc[4] = Copy_pvFunc;
		break;
		case IR_4: IR_pvFunc[5] = Copy_pvFunc;
		break;
		case IR_5: IR_pvFunc[6] = Copy_pvFunc;
		break;
		case IR_6: IR_pvFunc[7] = Copy_pvFunc;
		break;
		case IR_7: IR_pvFunc[8] = Copy_pvFunc;
		break;
		case IR_8: IR_pvFunc[9] = Copy_pvFunc;
		break;
		case IR_9: IR_pvFunc[10] = Copy_pvFunc;
		break;
	}
}
