/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 25/12/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RES;
	volatile u32 OBR;
	volatile u32 WRPR;
}FPEC_t;


#define M_FPEC				((volatile FPEC_t*) 0x40022000)

#endif