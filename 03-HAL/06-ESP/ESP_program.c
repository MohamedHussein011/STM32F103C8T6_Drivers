/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 11/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "UART_interface.h"
#include "STK_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;

	//first check that ESP is ready or not
	while(Local_u8Result != 1)
	{
		UART_voidTransmitDataSynch((u8*)"AT");
		UART_voidTransmitDataSynch((u8*)"\r\n");
		Local_u8Result = ESP_voidValidateCMD();
	}

	Local_u8Result = 0;
	//disable ECHO
	while(Local_u8Result != 1)
	{
		UART_voidTransmitDataSynch((u8*)"ATE0\r\n");
		Local_u8Result = ESP_voidValidateCMD();
	}

	Local_u8Result = 0;
	while(Local_u8Result != 1)
	{
		//choose the mode of ESP is station mode
		UART_voidTransmitDataSynch((u8*)"AT+CWMODE=1\r\n");
		Local_u8Result = ESP_voidValidateCMD();
	}
}

void ESP_voidConnectToNetwork(u8* Copy_pu8Name, u8* Copy_pu8Password)
{
	u8 Local_u8Result = 0;

	//send name & password of the network
	while(Local_u8Result != 1)
	{
		UART_voidTransmitDataSynch((u8*)"AT+CWJAP_CUR=\"");
		UART_voidTransmitDataSynch(Copy_pu8Name);
		UART_voidTransmitDataSynch((u8*)"\",\"");
		UART_voidTransmitDataSynch(Copy_pu8Password);
		UART_voidTransmitDataSynch((u8*)"\"\r\n");
		Local_u8Result = ESP_voidValidateCMD();
	}
}

void ESP_voidConnectToServerTCP (u8* Copy_pu8IPAddress, u8 Copy_u8Port)
{
	u8 Local_u8Result = 0;

	//send IP & port number of the network
	while(Local_u8Result != 1 || Local_u8Result != 2)
	{
		UART_voidTransmitDataSynch((u8*)"AT+CIPSTART=\"TCP\",\"");
		UART_voidTransmitDataSynch(Copy_pu8IPAddress);
		UART_voidTransmitDataSynch((u8*)"\",");
		UART_voidTransmitByte(Copy_u8Port);
		UART_voidTransmitDataSynch((u8*)"\r\n");
		Local_u8Result = ESP_voidValidateCMD();
	}
}

u8   ESP_u8ReceiveHttpRequest(u8* Copy_pu8HTTP)
{
	u8 Local_u8Result = 0, Local_u8Dummy = 0, Local_u8Data[50], Local_u8Iterator=0, Local_u8Length = 0;

	Local_u8Length = StringLength(Copy_pu8HTTP);

	//send HTTP & Lentgh of data
	while(Local_u8Result != 3)
	{
		UART_voidTransmitDataSynch((u8*)"AT+CIPSEND=");
		UART_voidTransmitByte(Local_u8Length);
		UART_voidTransmitDataSynch((u8*)"\r\n");

		Local_u8Result = ESP_voidValidateCMD();
	}

	Local_u8Result = 0;

	UART_voidTransmitDataSynch((u8*)"GET ");
	UART_voidTransmitDataSynch(Copy_pu8HTTP);
	UART_voidTransmitDataSynch((u8*)"\r\n");

	while(Local_u8Dummy != 255)
	{
		UART_voidReceiveByte(&Local_u8Dummy);
		Local_u8Data[Local_u8Iterator] = Local_u8Dummy;
		Local_u8Iterator++;
	}
	Local_u8Iterator=0;

	while(Local_u8Data[Local_u8Iterator] != ':')
	{
		Local_u8Iterator++;
	}

	Local_u8Result = Local_u8Data[++Local_u8Iterator];

	return Local_u8Result;

}

static u8 ESP_voidValidateCMD(void)
{
	u8 Local_u8Response[100] = {0};
	u8 Local_u8Iterator = 0, Local_u8Dummy = 0, Local_u8ResponseStatus = 0;

	while(Local_u8Dummy != 255)
	{
		UART_voidReceiveByte(&Local_u8Dummy);
		Local_u8Response[Local_u8Iterator] = Local_u8Dummy;
		Local_u8Iterator++;
	}

	Local_u8Iterator = 0;

	while(Local_u8Response[Local_u8Iterator] != 'O'){	Local_u8Iterator++;	}

	if(Local_u8Response[Local_u8Iterator] == 'O' && Local_u8Response[++Local_u8Iterator] == 'K')
	{
		Local_u8ResponseStatus = 1;
	}

	//	if(Local_u8Response[0] == 'A' && Local_u8Response[1] == 'L' && Local_u8Response[2] == 'R'
	//			&& Local_u8Response[3] == 'E' && Local_u8Response[4] == 'A' && Local_u8Response[5] == 'D'
	//					&& Local_u8Response[6] == 'Y')
	//	{
	//		Local_u8ResponseStatus = 2;
	//	}

	if(Local_u8Response[Local_u8Iterator] == 'O' && Local_u8Response[Local_u8Iterator + 1] == 'K'
			&& (Local_u8Response[Local_u8Iterator + 2] == '>' || Local_u8Response[Local_u8Iterator + 3] == '>'))
	{
		Local_u8ResponseStatus = 3;
	}

	return Local_u8ResponseStatus;
}

static u8 StringLength(const u8* Copy_pu8String)
{
	u16 u16LocalCounter = 0;
	while (*Copy_pu8String != 0 || *Copy_pu8String != '\0')
	{
		u16LocalCounter++;
		Copy_pu8String++;
	}

	return u16LocalCounter;
}
