/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 29/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

//time out for the conversion
#define ADC_TIMEOUT					50000

/*Options:
 * 			1: ADC_RIGHT_ALIGNMENT
 * 			2: ADC_LEFT_ALIGNMENT
 */
#define ADC_DATA_ALIGNMENT 			ADC_RIGHT_ALIGNMENT

///*Options:
// * 			1: ADC_EXTSEL_TIMER1_CC1
// * 			2: ADC_EXTSEL_TIMER1_CC2
// * 			3: ADC_EXTSEL_TIMER1_CC3
// * 			4: ADC_EXTSEL_TIMER2_CC2
// * 			5: ADC_EXTSEL_TIMER3_TRGO
// * 			6: ADC_EXTSEL_TIMER4_CC4
// * 			7: ADC_EXTSEL_EXTIL11
// * 			8: ADC_EXTSEL_SWSTART
// */
//#define ADC_EXTERNAL_TRIGGER				ADC_EXTSEL_SWSTART

#endif
