/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 30/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/* NVIC_PRIORITY_GROUP
   Options: 
		1: GROUP_4BITS_SUB_0BITS			(Group_Priority0 to Group_Priority15) & no sub priority
		2: GROUP_3BITS_SUB_1BITS			(Group_Priority0 to Group_Priority7) & (Sub_Priority0 to Sub_Priority1)
		3: GROUP_2BITS_SUB_2BITS			(Group_Priority0 to Group_Priority3) & (Sub_Priority0 to Sub_Priority3)
		4: GROUP_1BITS_SUB_3BITS			(Group_Priority0 to Group_Priority1) & (Sub_Priority0 to Sub_Priority7)
		5: GROUP_0BITS_SUB_4BITS			no group priority & (Sub_Priority0 to Sub_Priority15)
*/
#define NVIC_PRIORITY_GROUP       GROUP_4BITS_SUB_0BITS

#endif
