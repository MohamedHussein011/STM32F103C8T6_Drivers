/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 02/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"

u16 Data[100] = {0};
u32 Address = 0;

u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Temp = 0;
	if( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Temp = Copy_u8Asci - 48;
	}
	else
	{
		Temp = Copy_u8Asci - 55;
	}
	
	return Temp;
}

//to know if the record if data or address
void Parser_voidParseRecord (u8* Copy_pu8Data)
{
	switch(Copy_pu8Data[8])
	{
		//data
		case '0':  Parser_voidParseData (Copy_pu8Data);    break;
		
		//address
		case '4':  Parser_voidParseAddress (Copy_pu8Data);    break;
	}
}

void Parser_voidParseData (u8* Copy_pu8Data)
{
	u8 DigitC1, DigitC0, CC;
	u8 AddressDigit3, AddressDigit2, AddressDigit1, AddressDigit0;
	u8 DataDigit3, DataDigit2, DataDigit1, DataDigit0;
	u8 DataCounter = 0, i;
	
	/* Get Character Count */
	DigitC1 = AsciToHex(Copy_pu8Data[1]);
	DigitC0 = AsciToHex(Copy_pu8Data[2]);
	CC = (DigitC1 << 4) | DigitC0;
	
	/* Get Address */
	AddressDigit3 = AsciToHex(Copy_pu8Data[3]);
	AddressDigit2 = AsciToHex(Copy_pu8Data[4]);
	AddressDigit1 = AsciToHex(Copy_pu8Data[5]);
	AddressDigit0 = AsciToHex(Copy_pu8Data[6]);
	
	Address = Address & 0xFFFF0000;
	Address = Address | (AddressDigit3 << 12) | (AddressDigit2 << 8) | (AddressDigit1 << 4) | (AddressDigit0);
	
	for(i = 0; i < CC/2; i++)
	{
		/* Get Data */
		DataDigit3 = AsciToHex(Copy_pu8Data[4*i+9]);
		DataDigit2 = AsciToHex(Copy_pu8Data[4*i+10]);
		DataDigit1 = AsciToHex(Copy_pu8Data[4*i+11]);
		DataDigit0 = AsciToHex(Copy_pu8Data[4*i+12]);
		
		Data[DataCounter] = (DataDigit3 << 12) | (DataDigit2 << 8) | (DataDigit1 << 4) | (DataDigit0); 
		DataCounter++;
	}
	
	
	FPEC_voidFlashWriteHalfWord(Address, Data, CC/2);
	
}

void Parser_voidParseAddress (u8* Copy_pu8Data)
{
	u8 AddressDigit3, AddressDigit2, AddressDigit1, AddressDigit0;
	
	/* Get Address */
	AddressDigit3 = AsciToHex(Copy_pu8Data[9]);
	AddressDigit2 = AsciToHex(Copy_pu8Data[10]);
	AddressDigit1 = AsciToHex(Copy_pu8Data[11]);
	AddressDigit0 = AsciToHex(Copy_pu8Data[12]);
	
	Address = Address & 0x0000FFFF;
	Address = Address | (AddressDigit3 << 28) | (AddressDigit2 << 24) | (AddressDigit1 << 20) | (AddressDigit0 < 16);
	
}