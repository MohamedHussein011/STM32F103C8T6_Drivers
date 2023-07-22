/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: SERVICES                      ************************/
/*************             Version: V1.0 - 27/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

//create array of number of tasks deined in config file
static OS_TASK_t Task_Array[OS_NUM_TASKS] = {{NULL}};

void OS_voidInit(void)
{
	STK_voidInit();
	//config STK tick time to 1 ms
	STK_voidSetIntervalPeriodic(OS_TICK,SECHEDULER);
}

void OS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*Copy_pvFunc)(void), u16 Copy_u16FirstDelay)
{
	if(Task_Array[Copy_u8Priority].pvFUNC == NULL)
	{
		Task_Array[Copy_u8Priority].u16PERIODICITY = Copy_u16Periodicity;
		Task_Array[Copy_u8Priority].pvFUNC = Copy_pvFunc;
		Task_Array[Copy_u8Priority].u16FIRST_DELAY = Copy_u16FirstDelay;
		Task_Array[Copy_u8Priority].u8STATE = TASK_RESUMED;
	}
	else
	{
		/*do nothing*/
	}
}

static void SECHEDULER(void)
{
	u8 u8Local_counter = 0;

	for(u8Local_counter = 0; u8Local_counter<OS_NUM_TASKS; u8Local_counter++)
	{
		if((Task_Array[u8Local_counter].pvFUNC != NULL) && (Task_Array[u8Local_counter].u8STATE == TASK_RESUMED))
		{
			if(Task_Array[u8Local_counter].u16FIRST_DELAY == 0)
			{
				Task_Array[u8Local_counter].u16FIRST_DELAY = Task_Array[u8Local_counter].u16PERIODICITY - 1;
				Task_Array[u8Local_counter].pvFUNC();
			}
			else
			{
				Task_Array[u8Local_counter].u16FIRST_DELAY--;
			}
		}
	}
}

void OS_voidSuspendTask (u8 Copy_u8Priority)
{
	Task_Array[Copy_u8Priority].u8STATE = TASK_SUSPENDED;
}
void OS_voidResumeTask  (u8 Copy_u8Priority)
{
	Task_Array[Copy_u8Priority].u8STATE = TASK_RESUMED;
}
void OS_voidDeleteTask  (u8 Copy_u8Priority)
{
	Task_Array[Copy_u8Priority].pvFUNC = NULL;
}
