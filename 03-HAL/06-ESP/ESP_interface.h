/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 11/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_voidInit(void);

void ESP_voidConnectToNetwork(u8* Copy_pu8Name, u8* Copy_pu8Password);
void ESP_voidConnectToServerTCP (u8* Copy_pu8IPAddress, u8 Copy_u8Port);
u8   ESP_u8ReceiveHttpRequest(u8* Copy_pu8HTTP);

#endif
