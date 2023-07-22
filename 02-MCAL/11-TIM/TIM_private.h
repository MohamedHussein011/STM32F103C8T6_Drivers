/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 10/11//2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef TIM_PRIVATE_H
#define TIM_PRIVATE_H

typedef struct
{
	volatile u32 CR[2];		//TIMx control register
	volatile u32 SMCR;		//TIMx slave mode control register
	volatile u32 DIER;		//TIMx DMA/Interrupt enable register
	volatile u32 SR;		//TIMx status register
	volatile u32 EGR;		//TIMx event generation register
	volatile u32 CCMR[2];	//TIMx capture/compare mode register
	volatile u32 CCER;		//TIMx capture/compare enable register
	volatile u32 CNT;		//TIMx counter
	volatile u32 PSC;		//TIMx prescaler
	volatile u32 ARR;		//TIMx auto-reload register
	volatile u32 CCR[4];	//TIMx capture/compare register
	volatile u32 DCR;		//TIMx DMA control register
	volatile u32 DMAR;		//TIMx DMA address for full transfer
}TIM_t;

#define M_TIM2				((volatile TIM_t*)0x40000000)
#define M_TIM3				((volatile TIM_t*)0x40000400)
#define M_TIM4				((volatile TIM_t*)0x40000800)

#define TIMx_ENABLE					    		1
#define TIMx_DISABLE							0

//CR1
#define TIMx_CMS_EDGE_ALIGNED				0b00
#define TIMx_CMS_CENTER_ALIGNED_MODE1		0b01
#define TIMx_CMS_CENTER_ALIGNED_MODE2		0b10
#define TIMx_CMS_CENTER_ALIGNED_MODE3		0b11
#define TIMx_DIR_UP							0
#define TIMx_DIR_DOWN						1
#define TIMx_OPM_CONTINUE					0
#define TIMx_OPM_STOP						1
#define TIMx_URS_0 							0
#define TIMx_URS_1 							1
#define TIMx_UDIS_UEV_EN					0
#define TIMx_UDIS_UEV_DIS					1

//TIMx DMA/Interrupt enable register
//#define TIMx_UIF				 			0			//Update interrupt flag

//CCMR
#define TIMx_CCxS_OUTPUT					0b00
#define TIMx_OCxM_FROZEN					0b000
#define TIMx_OCxM_SET_ACTIVE				0b001
#define TIMx_OCxM_SET_INACTIVE				0b010
#define TIMx_OCxM_TOGGLE					0b011
#define TIMx_OCxM_FORCE_INACTIVE			0b100
#define TIMx_OCxM_FORCE_ACTIVE				0b101
#define TIMx_OCxM_PWM_MODE1					0b110
#define TIMx_OCxM_PWM_MODE2					0b111

//CCER
#define TIMx_CCxP_HIGH					0
#define TIMx_CCxP_LOW					1
#define TIMx_CCxE_OFF					0
#define TIMx_CCxE_ON					1

#endif
