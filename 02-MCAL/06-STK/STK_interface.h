/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_voidInit(void);
void STK_voidEnableInterrupt(void);
void STK_voidDisableInterrupt(void);
void STK_voidDelayms(u32 Copy_u32Valuems);
void STK_voidDelayus(u32 Copy_u32Valueus);
void STK_voidSetInterval(u32 Copy_u32Valueus,u8 Copy_u8NumOfPeriods, void(*Copy_pu8NotificationFunc));
void STK_voidSetIntervalPeriodic(u32 Copy_u32Valueus, void(*Copy_pu8NotificationFunc));
u32  STK_u32GetElapsedTime(void);
u32  STK_u32GetRemainingTime(void);
void STK_voidStopInterval(void);


#endif
