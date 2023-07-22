/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 08/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

typedef struct
{
	volatile u32 CRL;       //Port configuration register low 
	volatile u32 CRH ;      //Port configuration register high
	volatile u32 IDR ;      //Port input data register
	volatile u32 ODR ;      //Port output data register
	volatile u32 BSRR;      //Port bit set/reset register
	volatile u32 BRR ;      //Port bit reset register
	volatile u32 LCKR;	    //Port configuration lock register
}GPIO_t;

/*Registers Definitions*/
#define M_GPIOA       ((volatile GPIO_t*) 0x40010800)       //PORT A
#define M_GPIOB       ((volatile GPIO_t*) 0x40010C00)       //PORT B
#define M_GPIOC       ((volatile GPIO_t*) 0x40011000)       //PORT C
 
#define INPUT_PULLUP_PULLDOWN_MODE          0b1000

#endif