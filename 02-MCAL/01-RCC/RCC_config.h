/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 03/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* RCC clock type
   Options: 
		1: RCC_HSI
		2: RCC_HSE_CRYSTAL
		3: RCC_HSE_RC
		4: RCC_PLL
*/
#define RCC_CLOCK_TYPE        RCC_HSI
 
/* RCC clock security system enable
   Options: 
		1: RCC_CSS_ENABLE
		2: RCC_CSS_DISABLE
*/
#define RCC_CLOCK_SECURITY        RCC_CSS_DISABLE

/* RCC AHB clock prescaler
   Options: 
		1: RCC_AHB_NOT_DIVIDED
		2: RCC_AHB_DIV_BY_2
		3: RCC_AHB_DIV_BY_4
		4: RCC_AHB_DIV_BY_8
		5: RCC_AHB_DIV_BY_16
		6: RCC_AHB_DIV_BY_64
		7: RCC_AHB_DIV_BY_128
		8: RCC_AHB_DIV_BY_256
		9: RCC_AHB_DIV_BY_512
*/
#define RCC_AHB_PRESCALER        RCC_AHB_NOT_DIVIDED

/* RCC APB1 clock prescaler
   Options: 
		1: RCC_APB1_NOT_DIVIDED
		2: RCC_APB1_DIV_BY_2
		3: RCC_APB1_DIV_BY_4
		4: RCC_APB1_DIV_BY_8
		5: RCC_APB1_DIV_BY_16
*/
#define RCC_APB1_PRESCALER        RCC_APB1_NOT_DIVIDED

/* RCC APB2 clock prescaler
   Options: 
		1: RCC_APB2_NOT_DIVIDED
		2: RCC_APB2_DIV_BY_2
		3: RCC_APB2_DIV_BY_4
		4: RCC_APB2_DIV_BY_8
		5: RCC_APB2_DIV_BY_16
*/
#define RCC_APB2_PRESCALER        RCC_APB2_NOT_DIVIDED

/* RCC ADC clock prescaler
   Options: 
		1: RCC_ADC_DIV_BY_2
		2: RCC_ADC_DIV_BY_4
		3: RCC_ADC_DIV_BY_6
		4: RCC_ADC_DIV_BY_8
*/
#define RCC_ADC_PRESCALER        RCC_ADC_DIV_BY_6

/* RCC PLL entry clock source
   Options: 
		1: RCC_PLL_IN_HSI_DIV_BY_2
		2: RCC_PLL_IN_HSE_DIV_BY_2
		3: RCC_PLL_IN_HSE
*/
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_IN_CLOCK       RCC_PLL_IN_HSE_DIV_BY_2
#endif

/* RCC PLL multiplication factor
   Options: 
		1:  RCC_PLL_MUL_BY_2
		2:  RCC_PLL_MUL_BY_3
		3:  RCC_PLL_MUL_BY_4
		4:  RCC_PLL_MUL_BY_5
		5:  RCC_PLL_MUL_BY_6
		6:  RCC_PLL_MUL_BY_7
		7:  RCC_PLL_MUL_BY_8
		8:  RCC_PLL_MUL_BY_9
		9:  RCC_PLL_MUL_BY_10
		10: RCC_PLL_MUL_BY_11
		11: RCC_PLL_MUL_BY_12
		12: RCC_PLL_MUL_BY_13
		13: RCC_PLL_MUL_BY_14
		14: RCC_PLL_MUL_BY_15
		15: RCC_PLL_MUL_BY_16
*/
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL        RCC_PLL_MUL_BY_8
#endif

#endif
