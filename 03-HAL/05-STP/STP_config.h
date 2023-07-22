/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 01/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef STP_CONFIG_H
#define STP_CONFIG_H

//write the pins in pairs port,pin
#define STP_SERIAL_DATA						GPIOA,GPIO_PIN0
#define STP_BIT_LATCH_CLOCK					GPIOA,GPIO_PIN1			//shift register / SRCLK
#define STP_BYTE_LATCH_CLOCK				GPIOA,GPIO_PIN2			//storage register / RCLK

#endif
