/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 22/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H

//write number of cols & rows
#define LEDMRX_NUM_COLS			8
#define LEDMRX_NUM_ROWS			8

//write the frequency Hz
#define LEDMRX_FPS            50

//write the AHB clock MHz
#define LEDMRX_AHB_CLOCK            8

/*LEDMRX connection
* options:
*		1: LEDMRX_CCAR     	-- cathode column anode row
*		2: LEDMRX_ACCR     	-- anode column cathode row
*/
#define LEDMRX_CONNECTION         LEDMRX_CCAR  

/*LEDMRX control
* options:
*		1: LEDMRX_COLUMN  
*		2: LEDMRX_ROW	  
*/
#define LEDMRX_CONTROL         LEDMRX_COLUMN  

//LEDMRX PORT,PIN
#define LEDMRX_ROW_PORT			   GPIOA
#define LEDMRX_COL_PORT            GPIOB

#define LEDMRX_ROW_PINS            {GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7}
#define LEDMRX_COL_PINS            {GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,GPIO_PIN8,GPIO_PIN9}


#endif
