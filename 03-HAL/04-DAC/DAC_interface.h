/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: HAL                           ************************/
/*************             Version: V1.0 - 24/11/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H

void DAC_voidInit (void);
void DAC_voidOutputAnalog(u16 Copy_u16DigitalValue);
void DAC_voidPlaySong(void);

#endif