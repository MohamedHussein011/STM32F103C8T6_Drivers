/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 03/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

typedef struct 
{
	volatile u32 CR;               //Clock control register
	volatile u32 CFGR;             //Clock configuration register
	volatile u32 CIR;              //Clock interrupt register
	volatile u32 APB2RSTR;         //APB2 peripheral reset register
	volatile u32 APB1RSTR;         //APB1 peripheral reset register
	volatile u32 AHBENR ;          //AHB peripheral clock enable register
	volatile u32 APB2ENR;          //APB2 peripheral clock enable register
	volatile u32 APB1ENR;          //APB1 peripheral clock enable register
	volatile u32 BDCR   ;          //Backup domain control register
	volatile u32 CSR    ;          //Control/status register
}RCC_t;

/*Register Definition*/
#define M_RCC    			((volatile RCC_t*) 0x40021000)       //M for MCAL


/*RCC clock type*/
#define RCC_HSI            0
#define RCC_HSE_CRYSTAL    1
#define RCC_HSE_RC         2
#define RCC_PLL            3

/* RCC clock security system enable*/
#define RCC_CSS_ENABLE        0
#define RCC_CSS_DISABLE       1

/* RCC AHB clock prescaler*/
#define RCC_AHB_PRESCALER_MASK       0xFFFFFF0F
#define RCC_AHB_NOT_DIVIDED          0b0000
#define RCC_AHB_DIV_BY_2             0b1000
#define RCC_AHB_DIV_BY_4             0b1001
#define RCC_AHB_DIV_BY_8             0b1010
#define RCC_AHB_DIV_BY_16            0b1011
#define RCC_AHB_DIV_BY_64            0b1100
#define RCC_AHB_DIV_BY_128           0b1101
#define RCC_AHB_DIV_BY_256           0b1110
#define RCC_AHB_DIV_BY_512           0b1111

/* RCC APB1 clock prescaler*/
#define RCC_APB1_PRESCALER_MASK       0xFFFFF8FF
#define RCC_APB1_NOT_DIVIDED          0b000
#define RCC_APB1_DIV_BY_2             0b100
#define RCC_APB1_DIV_BY_4             0b101
#define RCC_APB1_DIV_BY_8             0b110
#define RCC_APB1_DIV_BY_16            0b111

/* RCC APB2 clock prescaler*/
#define RCC_APB2_PRESCALER_MASK       0xFFFFC7FF
#define RCC_APB2_NOT_DIVIDED          0b000
#define RCC_APB2_DIV_BY_2             0b100
#define RCC_APB2_DIV_BY_4             0b101
#define RCC_APB2_DIV_BY_8             0b110
#define RCC_APB2_DIV_BY_16            0b111

/* RCC ADC clock prescaler*/
#define RCC_ADC_PRESCALER_MASK       0xFFFF3FFF
#define RCC_ADC_DIV_BY_2             0b00
#define RCC_ADC_DIV_BY_4             0b01
#define RCC_ADC_DIV_BY_6             0b10
#define RCC_ADC_DIV_BY_8             0b11

/* RCC PLL entry clock source*/

#define RCC_PLL_IN_HSI_DIV_BY_2             0
#define RCC_PLL_IN_HSE_DIV_BY_2             1
#define RCC_PLL_IN_HSE                      2

/* RCC PLL multiplication factor*/
#define RCC_PLL_MUL_MASK               0xFFC3FFFF
#define RCC_PLL_MUL_BY_2               0b0000
#define RCC_PLL_MUL_BY_3               0b0001
#define RCC_PLL_MUL_BY_4               0b0010
#define RCC_PLL_MUL_BY_5               0b0011
#define RCC_PLL_MUL_BY_6               0b0100
#define RCC_PLL_MUL_BY_7               0b0101
#define RCC_PLL_MUL_BY_8               0b0110
#define RCC_PLL_MUL_BY_9               0b0111
#define RCC_PLL_MUL_BY_10              0b1000
#define RCC_PLL_MUL_BY_11              0b1001
#define RCC_PLL_MUL_BY_12              0b1010
#define RCC_PLL_MUL_BY_13              0b1011
#define RCC_PLL_MUL_BY_14              0b1100
#define RCC_PLL_MUL_BY_15              0b1101
#define RCC_PLL_MUL_BY_16              0b1110


#endif