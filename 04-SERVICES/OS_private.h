/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: SERVICES                      ************************/
/*************             Version: V1.0 - 27/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
	u8 u8PRIORITY;
	u16 u16PERIODICITY;
	void (*pvFUNC) (void);
	u16 u16FIRST_DELAY;
	u8 u8STATE;
}OS_TASK_t;

#define TASK_SUSPENDED			0
#define TASK_RESUMED			1

static void SECHEDULER(void);


#endif