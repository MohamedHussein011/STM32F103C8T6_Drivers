/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 22/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef LEDMRX_PRIVATE_H
#define LEDMRX_PRIVATE_H

/*LEDMRX connection
* options:
*		1: LEDMRX_CCAR     	-- cathode column anode row
*		2: LEDMRX_ACCR     	-- anode column cathode row
*/
#define LEDMRX_CCAR  			0
#define LEDMRX_ACCR  			1

/*LEDMRX control
* options:
*		1: LEDMRX_COLUMN  
*		2: LEDMRX_ROW	  
*/
#define LEDMRX_COLUMN  				0
#define LEDMRX_ROW   				1

static void DisableAllCols(u8 Copy_u8Connection);
static void DisableAllRows(u8 Copy_u8Connection);
static void SetRowsValues (u8 Copy_u8Value);
static void SetColsValues (u8 Copy_u8Value);
static void ActivateCol   (u8 Copy_u8Index,u8 Copy_u8Connection);
static void ActivateRow   (u8 Copy_u8Index,u8 Copy_u8Connection);


#endif