/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*Interrupts ID*/
#define NVIC_RCC_ID                 5
#define NVIC_EXTI0_ID               6
#define NVIC_EXTI1_ID               7
#define NVIC_EXTI2_ID               8
#define NVIC_EXTI3_ID               9
#define NVIC_EXTI4_ID               10
#define NVIC_DMA_CHANNEL1_ID        11
#define NVIC_DMA_CHANNEL2_ID        12
#define NVIC_DMA_CHANNEL3_ID        13
#define NVIC_DMA_CHANNEL4_ID        14
#define NVIC_DMA_CHANNEL5_ID        15
#define NVIC_DMA_CHANNEL6_ID        16
#define NVIC_DMA_CHANNEL7_ID        17
#define NVIC_ADC1_2_ID				18
#define NVIC_EXTI5_9_ID             23
#define NVIC_TIM2_ID                28
#define NVIC_TIM3_ID                29
#define NVIC_TIM4_ID                30
#define NVIC_SPI1_ID       	        35
#define NVIC_UART1_ID               37
#define NVIC_EXTI10_15_ID           40

/*Group & Sub  priorities*/
#define Group_Priority0             0x00
#define Group_Priority1             0x01
#define Group_Priority2             0x02
#define Group_Priority3             0x03
#define Group_Priority4             0x04
#define Group_Priority5             0x05
#define Group_Priority6             0x06
#define Group_Priority7             0x07
#define Group_Priority8             0x08
#define Group_Priority9             0x09
#define Group_Priority10            0x0A
#define Group_Priority11            0x0B
#define Group_Priority12            0x0C
#define Group_Priority13            0x0D
#define Group_Priority14            0x0E
#define Group_Priority15            0x0F

#define Sub_Priority0               0x00
#define Sub_Priority1               0x01
#define Sub_Priority2               0x02
#define Sub_Priority3               0x03
#define Sub_Priority4               0x04
#define Sub_Priority5               0x05
#define Sub_Priority6               0x06
#define Sub_Priority7               0x07
#define Sub_Priority8               0x08
#define Sub_Priority9               0x09
#define Sub_Priority10              0x0A
#define Sub_Priority11              0x0B
#define Sub_Priority12              0x0C
#define Sub_Priority13              0x0D
#define Sub_Priority14              0x0E
#define Sub_Priority15              0x0F


void NVIC_voidEnableInterrupt  (u8 Copy_u8InterruptID);
void NVIC_voidDisableInterrupt (u8 Copy_u8InterruptID);
void NVIC_voidSetPendingFlag   (u8 Copy_u8InterruptID);
void NVIC_voidClearPendingFlag (u8 Copy_u8InterruptID);
void NVIC_voidGetActiveFlag    (u8 Copy_u8InterruptID, u8* Copy_u8Value);
/*Max group priority ---> 16
 * Max Sub priority ---> 16
 * options: Group_Priority0  ---> Group_Priority15
 * options: Sub_Priority0    ---> Sub_Priority15
 */
void NVIC_voidSetPriority      (u8 Copy_u8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);
void NVIC_voidSoftwareTrigger (u8 Copy_u8InterruptID);

#endif
