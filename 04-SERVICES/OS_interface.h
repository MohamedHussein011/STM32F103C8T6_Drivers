/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: SERVICES                      ************************/
/*************             Version: V1.0 - 27/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

//Copy_u8Priority is dealed as Task ID
void OS_voidInit(void);
void OS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*Copy_pvFunc)(void), u16 Copy_u16FirstDelay);
void OS_voidSuspendTask (u8 Copy_u8Priority);
void OS_voidResumeTask  (u8 Copy_u8Priority);
void OS_voidDeleteTask  (u8 Copy_u8Priority);

#endif