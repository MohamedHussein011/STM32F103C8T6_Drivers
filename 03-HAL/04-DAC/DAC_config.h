/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 24/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef DAC_CONFIG_H
#define DAC_CONFIG_H

//for output analog signal
//write number of bits
#define DAC_BITS			8
//write port & pins 
#define DAC_PORT			GPIOA
#define DAC_PINS			{GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7}

//for song
#define DAC_SONG_PORT			        GPIOA
#define DAC_SONG_PORT_POSITION			PORT_LOW
#define DAC_SONG_LEN					86511
//write the Frequency Hz
#define DAC_FREQ			8000

#endif
