/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 22/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

//calculate the delay time & ticks
#if LEDMRX_CONTROL == LEDMRX_COLUMN
static u16 LEDMRX_DELAY		 = (u16)(1000000UL / (LEDMRX_NUM_COLS * LEDMRX_FPS));
#elif LEDMRX_CONTROL == LEDMRX_ROW
static u16 LEDMRX_DELAY		 = (u16)(1000000UL / (LEDMRX_NUM_ROWS * LEDMRX_FPS));
#endif

u8 ROW_PINS[LEDMRX_NUM_ROWS] = LEDMRX_ROW_PINS;
u8 COL_PINS[LEDMRX_NUM_COLS] = LEDMRX_COL_PINS;

void LEDMRX_voidInit (void)
{

	for (u8 i = 0; i<LEDMRX_NUM_COLS; i++)
	{
		GPIO_voidSetPinDirection(LEDMRX_COL_PORT,COL_PINS[i],OUTPUT_2MHZ_PUSH_PULL);
	}

	for (u8 i = 0; i<LEDMRX_NUM_ROWS; i++)
	{
		GPIO_voidSetPinDirection(LEDMRX_ROW_PORT,ROW_PINS[i],OUTPUT_2MHZ_PUSH_PULL);
	}

}

void LEDMRX_voidDisplayFrame (u8* Copy_pu8Frame)
{
#if LEDMRX_CONNECTION == LEDMRX_CCAR
#if LEDMRX_CONTROL == LEDMRX_COLUMN
	/*define index for cols & iterator*/
	u8 LEDMRX_ColIndex = 0, Local_u8Iterator = 0;
	/* Loop for FPS */
	while(Local_u8Iterator < LEDMRX_FPS)
	{
		/*Disable all Columns*/
		DisableAllCols(LEDMRX_CCAR);
		/*set rows values*/
		SetRowsValues (Copy_pu8Frame[LEDMRX_ColIndex]);
		/*Enable Column*/
		ActivateCol(LEDMRX_ColIndex, LEDMRX_CCAR);
		/*Delay*/
		STK_voidDelayus(LEDMRX_DELAY);
		/*get the next col*/
		LEDMRX_ColIndex++;
		/*check if the LEDMRX_ColIndex is bigger than LEDMRX_NUM_COLS*/
		if(LEDMRX_ColIndex >= LEDMRX_NUM_COLS)
		{
			LEDMRX_ColIndex = 0;
		}
		Local_u8Iterator++;
	}
#elif LEDMRX_CONTROL == LEDMRX_ROW
	/*define index for rows & iterator*/
	u8 LEDMRX_RowIndex = 0, Local_u8Iterator = 0;
	/* Loop for FPS */
	while(Local_u8Iterator < LEDMRX_FPS)
	{
		/*Disable all Columns*/
		DisableAllRows(LEDMRX_CCAR);
		/*set rows values*/
		SetColsValues (Copy_pu8Frame[LEDMRX_RowIndex]);
		/*Enable Column*/
		ActivateRow(LEDMRX_RowIndex, LEDMRX_CCAR);
		/*Delay*/
		STK_voidDelayus(LEDMRX_DELAY);
		/*get the next row*/
		LEDMRX_RowIndex++;
		/*check if the LEDMRX_RowIndex is bigger than LEDMRX_NUM_ROWS*/
		if(LEDMRX_RowIndex >= LEDMRX_NUM_ROWS)
		{
			LEDMRX_RowIndex = 0;
		}
		Local_u8Iterator++;
	}
#else
#error "Wrong choice for LEDMRX control"
#endif  //end if LEDMRX control

#elif LEDMRX_CONNECTION == LEDMRX_ACCR
#if LEDMRX_CONTROL == LEDMRX_COLUMN
	/*define index for cols & iterator*/
	u8 LEDMRX_ColIndex = 0, Local_u8Iterator = 0;
	/* Loop for FPS */
	while(Local_u8Iterator < LEDMRX_FPS)
	{
		/*Disable all Columns*/
		DisableAllCols(LEDMRX_ACCR);
		/*set rows values*/
		SetRowsValues (Copy_pu8Frame[LEDMRX_ColIndex]);
		/*Enable Column*/
		ActivateCol(LEDMRX_ColIndex, LEDMRX_ACCR);
		/*Delay*/
		STK_voidDelayus(LEDMRX_DELAY);
		/*get the next col*/
		LEDMRX_ColIndex++;
		/*check if the LEDMRX_ColIndex is bigger than LEDMRX_NUM_COLS*/
		if(LEDMRX_ColIndex >= LEDMRX_NUM_COLS)
		{
			LEDMRX_ColIndex = 0;
		}
		Local_u8Iterator++;
	}
#elif LEDMRX_CONTROL == LEDMRX_ROW
	/*define index for rows & iterator*/
	u8 LEDMRX_RowIndex = 0, Local_u8Iterator = 0;
	/* Loop for FPS */
	while(Local_u8Iterator < LEDMRX_FPS)
	{
		/*Disable all Columns*/
		DisableAllRows(LEDMRX_ACCR);
		/*set rows values*/
		SetColsValues (Copy_pu8Frame[LEDMRX_RowIndex]);
		/*Enable Column*/
		ActivateRow(LEDMRX_RowIndex, LEDMRX_ACCR);
		/*Delay*/
		STK_voidDelayus(LEDMRX_DELAY);
		/*get the next row*/
		LEDMRX_RowIndex++;
		/*check if the LEDMRX_RowIndex is bigger than LEDMRX_NUM_ROWS*/
		if(LEDMRX_RowIndex >= LEDMRX_NUM_ROWS)
		{
			LEDMRX_RowIndex = 0;
		}
		Local_u8Iterator++;
	}
#else
#error "Wrong choice for LEDMRX control"
#endif  //end if LEDMRX control

#else
#error "Wrong choice for LEDMRX connection"
#endif  //end if LEDMRX connection
}

static void DisableAllCols(u8 Copy_u8Connection)
{
	switch(Copy_u8Connection)
	{
	case LEDMRX_CCAR:
		for(u8 i=0; i<LEDMRX_NUM_COLS; i++)
		{
			GPIO_voidSetPinValue(LEDMRX_COL_PORT,COL_PINS[i],PIN_HIGH);
		}
		break;

	case LEDMRX_ACCR:
		for(u8 i=0; i<LEDMRX_NUM_COLS; i++)
		{
			GPIO_voidSetPinValue(LEDMRX_COL_PORT,COL_PINS[i],PIN_LOW);
		}
		break;

	}
}

static void DisableAllRows(u8 Copy_u8Connection)
{
	switch(Copy_u8Connection)
	{
	case LEDMRX_CCAR:
		for(u8 i=0; i<LEDMRX_NUM_ROWS; i++)
		{
			GPIO_voidSetPinValue(LEDMRX_ROW_PORT,ROW_PINS[i],PIN_LOW);
		}
		break;

	case LEDMRX_ACCR:
		for(u8 i=0; i<LEDMRX_NUM_ROWS; i++)
		{
			GPIO_voidSetPinValue(LEDMRX_ROW_PORT,ROW_PINS[i],PIN_HIGH);
		}
		break;

	}
}

static void SetRowsValues (u8 Copy_u8Value)
{
	u8 Local_u8Bit[LEDMRX_NUM_ROWS];

	for(u8 i=0; i<LEDMRX_NUM_ROWS; i++)
	{
		Local_u8Bit[i] = GET_BIT(Copy_u8Value,i);
	}

	for(u8 i=0; i<LEDMRX_NUM_ROWS; i++)
	{
		GPIO_voidSetPinValue(LEDMRX_ROW_PORT,ROW_PINS[i],Local_u8Bit[i]);
	}
}

static void SetColsValues (u8 Copy_u8Value)
{
	u8 Local_u8Bit[LEDMRX_NUM_COLS];

	for(u8 i=0; i<LEDMRX_NUM_COLS; i++)
	{
		Local_u8Bit[i] = GET_BIT(Copy_u8Value,i);
	}

	for(u8 i=0; i<LEDMRX_NUM_COLS; i++)
	{
		GPIO_voidSetPinValue(LEDMRX_COL_PORT,COL_PINS[i],Local_u8Bit[i]);
	}

}

static void ActivateCol (u8 Copy_u8Index, u8 Copy_u8Connection)
{
	switch(Copy_u8Connection)
	{
	case LEDMRX_CCAR:	GPIO_voidSetPinValue(LEDMRX_COL_PORT,COL_PINS[Copy_u8Index],PIN_LOW);
	break;

	case LEDMRX_ACCR: 	GPIO_voidSetPinValue(LEDMRX_COL_PORT,COL_PINS[Copy_u8Index],PIN_HIGH);
	break;

	}	
}

static void ActivateRow   (u8 Copy_u8Index, u8 Copy_u8Connection)
{
	switch(Copy_u8Connection)
	{
	case LEDMRX_CCAR:	GPIO_voidSetPinValue(LEDMRX_ROW_PORT,ROW_PINS[Copy_u8Index],PIN_HIGH);
	break;

	case LEDMRX_ACCR: 	GPIO_voidSetPinValue(LEDMRX_ROW_PORT,ROW_PINS[Copy_u8Index],PIN_LOW);
	break;

	}

}

void LEDMRX_voidStop (void)
{
#if LEDMRX_CONNECTION == LEDMRX_CCAR
	for (u8 i = 0; i<LEDMRX_NUM_COLS; i++)
	{
		GPIO_voidSetPinValue(LEDMRX_COL_PORT,COL_PINS[i],PIN_HIGH);
	}

	for (u8 i = 0; i<LEDMRX_NUM_ROWS; i++)
	{
		GPIO_voidSetPinValue(LEDMRX_ROW_PORT,ROW_PINS[i],PIN_LOW);
	}

#elif LEDMRX_CONNECTION == LEDMRX_ACCR
	for (u8 i = 0; i<LEDMRX_NUM_COLS; i++)
	{
		GPIO_voidSetPinValue(LEDMRX_COL_PORT,COL_PINS[i],PIN_LOW);
	}

	for (u8 i = 0; i<LEDMRX_NUM_ROWS; i++)
	{
		GPIO_voidSetPinValue(LEDMRX_ROW_PORT,ROW_PINS[i],PIN_HIGH);
	}

#endif

}
