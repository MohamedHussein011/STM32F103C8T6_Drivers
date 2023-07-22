/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef TIM_INTERFACE_H
#define TIM_INTERFACE_H

/* General-purpose timers TIM2/3/4 - Pins configuration
 * Input capture channel x ----> Input floating
 * Output compare channel x ----> Alternate function push-pull
 * NO REMAP
 * TIM4_CH1 --> PB6	,	TIM4_CH2 --> PB7 ,	TIM4_CH3 --> PB8 , 	TIM4_CH4 --> PB9
 * TIM3_CH1 --> PA6	,	TIM3_CH2 --> PA7 ,	TIM3_CH3 --> PB0 , 	TIM3_CH4 --> PB1
 * TIM2_CH1_ETR --> PA0	,	TIM2_CH2 --> PA1 ,	TIM2_CH3 --> PA2 , 	TIM2_CH4 --> PA3
 * */

//Interrupt source & events & channels
#define TIMx_UIE			0 			//Update
#define TIMx_CC1IE			1 			//Capture/Compare 1
#define TIMx_CC2IE			2 			//Capture/Compare 2
#define TIMx_CC3IE			3 			//Capture/Compare 3
#define TIMx_CC4IE			4 			//Capture/Compare 4

void TIM2_voidInit (void);
void TIM2_voidSetPreloadValue (u16 Copy_u16Value);
void TIM2_voidSetCompareValue (u8 Copy_u8Channel, u16 Copy_u16Value);

void TIM2_voidSetValue (u16 Copy_u16Value);
u16 TIM2_voidRetValue (void);

void TIM2_voidGenerateEvent (u8 Copy_u8EventID);

void TIM2_voidGeneratePWM (void);


void TIM2_voidEnableInterrupt (u8 Copy_u8InterruptID);
void TIM2_voidDisableInterrupt (u8 Copy_u8InterruptID);
void TIM2_voidSetCallBack (u8 Copy_u8InterruptID, void (*TIM2_pvFUNC) (void));

#endif
