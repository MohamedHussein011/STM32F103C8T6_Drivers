/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct
{
	volatile u32 AFIO_EVCR;                //Event control register
	volatile u32 AFIO_MAPR;                //AF remap and debug I/O configuration register
	volatile u32 AFIO_EXTICR[4];           //External interrupt configuration register 1-4
	volatile u32 AFIO_MAPR2;               //AF remap and debug I/O configuration register2
}AFIO_t;
#define M_AFIO         ((volatile AFIO_t*) 0x40010000)

//Event control register - Event output enable
#define EVCR_EVOE             7

#endif