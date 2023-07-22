/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS	        0xE000E100

/*Interrupt set-enable registers*/
#define NVIC_ISER0            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x000)))
#define NVIC_ISER1            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x004)))

/*Interrupt clear-enable registers*/
#define NVIC_ICER0            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x080)))
#define NVIC_ICER1            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x084)))

/*Interrupt set-pending registers*/
#define NVIC_ISPR0            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x100)))
#define NVIC_ISPR1            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x104)))

/*Interrupt clear-pending registers*/
#define NVIC_ICPR0            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x180)))
#define NVIC_ICPR1            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x184)))

/*Interrupt active bit registers*/
#define NVIC_IABR0            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x200)))
#define NVIC_IABR1            (*((volatile u32*) (NVIC_BASE_ADDRESS + 0x204)))

/*Interrupt priority registers*/
#define NVIC_IPRx             ((volatile u8*) (NVIC_BASE_ADDRESS + 0x300))		//IPR0

/*Software trigger interrupt register*/
#define NVIC_STIR             (*((volatile u32*) (NVIC_BASE_ADDRESS + 0xE00)))

/*Application interrupt and reset control register*/
#define SCB_AIRCR             (*((volatile u32*) 0xE000ED0C))

/* NVIC_PRIORITY_GROUP
   Options: 
		1: GROUP_4BITS_SUB_0BITS
		2: GROUP_3BITS_SUB_1BITS
		3: GROUP_2BITS_SUB_2BITS
		4: GROUP_1BITS_SUB_3BITS
		5: GROUP_0BITS_SUB_4BITS
*/
#define GROUP_4BITS_SUB_0BITS               0x05FA0300
#define GROUP_3BITS_SUB_1BITS               0x05FA0400
#define GROUP_2BITS_SUB_2BITS               0x05FA0500
#define GROUP_1BITS_SUB_3BITS               0x05FA0600
#define GROUP_0BITS_SUB_4BITS               0x05FA0700


#endif
