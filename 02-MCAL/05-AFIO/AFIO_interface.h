/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/* Event output*/
#define  AFIO_EventPort_A            0b000
#define  AFIO_EventPort_B            0b001
#define  AFIO_EventPort_C            0b010

#define AFIO_EventPin_0                        0b0000
#define AFIO_EventPin_1                        0b0001
#define AFIO_EventPin_2                        0b0010
#define AFIO_EventPin_3                        0b0011
#define AFIO_EventPin_4                        0b0100
#define AFIO_EventPin_5                        0b0101
#define AFIO_EventPin_6                        0b0110
#define AFIO_EventPin_7                        0b0111
#define AFIO_EventPin_8                        0b1000
#define AFIO_EventPin_9                        0b1001
#define AFIO_EventPin_10                       0b1010
#define AFIO_EventPin_11                       0b1011
#define AFIO_EventPin_12                       0b1100
#define AFIO_EventPin_13                       0b1101
#define AFIO_EventPin_14                       0b1110
#define AFIO_EventPin_15                       0b1111

void AFIO_voidEnablePortEvent  (u8 Copy_u8Port, u8 Copy_u8Pin);
void AFIO_voidDisablePortEvent (void);

/* External Interrupt Line select*/
#define AFIO_EXTI_LINE0                        0
#define AFIO_EXTI_LINE1                        1
#define AFIO_EXTI_LINE2                        2
#define AFIO_EXTI_LINE3                        3
#define AFIO_EXTI_LINE4                        4
#define AFIO_EXTI_LINE5                        5
#define AFIO_EXTI_LINE6                        6
#define AFIO_EXTI_LINE7                        7
#define AFIO_EXTI_LINE8                        8
#define AFIO_EXTI_LINE9                        9
#define AFIO_EXTI_LINE10                       10
#define AFIO_EXTI_LINE11                       11
#define AFIO_EXTI_LINE12                       12
#define AFIO_EXTI_LINE13                       13
#define AFIO_EXTI_LINE14                       14
#define AFIO_EXTI_LINE15                       15

/* External Interrupt Port select*/ 
#define AFIO_EXTI_PA            0b0000
#define AFIO_EXTI_PB            0b0001
#define AFIO_EXTI_PC            0b0010

void AFIO_voidSetEXTIConfiguration (u8 Copy_u8Line, u8 Copy_u8Port);

//Peripherals
#define AFIO_CAN					13
#define AFIO_TIM4					12
#define AFIO_TIM3					10
#define AFIO_TIM2					8
#define AFIO_TIM1					6
#define AFIO_UART1					2
#define AFIO_I2C1					1
#define AFIO_SPI1					0

#define AFIO_CAN_NO_REMAP			0b00			//CAN_TX A12 - CAN_RX A11
#define AFIO_CAN_REMAP				0b10			//CAN_TX B9 - CAN_RX B8
#define AFIO_TIM4_NO_REMAP			0				//(TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9)
#define AFIO_TIM4_REMAP				1				//(TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15
#define AFIO_TIM3_NO_REMAP			0b00			//(CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1
#define AFIO_TIM3_REMAP				0b10			//CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1
#define AFIO_TIM2_NO_REMAP			0b00			//CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3
#define AFIO_TIM2_REMAP0			0b01			//CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3
#define AFIO_TIM2_REMAP1			0b10			//CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11
#define AFIO_TIM2_REMAP2			0b11			//CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11
#define AFIO_TIM1_NO_REMAP			0b00			//ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12,CH1N/PB13, CH2N/PB14, CH3N/PB15
#define AFIO_TIM1_REMAP				0b01			//(ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6,CH1N/PA7, CH2N/PB0, CH3N/PB1
#define AFIO_UART1_NO_REMAP			0				//TX/PA9, RX/PA10
#define AFIO_UART1_REMAP			1				//(TX/PB6, RX/PB7
#define AFIO_I2C1_NO_REMAP			0				//SCL/PB6, SDA/PB7
#define AFIO_I2C1_REMAP				1				//SCL/PB8, SDA/PB9
#define AFIO_SPI1_NO_REMAP			0				//NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7
#define AFIO_SPI1_REMAP				1				//NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5

void AFIO_voidREMAP (u8 Copy_u8Peripheral, u8 Copy_u8REMAP);

#endif
