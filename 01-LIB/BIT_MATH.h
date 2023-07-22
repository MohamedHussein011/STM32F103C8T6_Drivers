/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: Library                       ************************/
/*************             Version: V1.0 - 03/10/2022           ************************/
/***************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)		(VAR |= (1 << (BIT)))
#define CLR_BIT(VAR,BIT)		(VAR &= ~(1 << (BIT)))
#define GET_BIT(VAR,BIT)		( (VAR >> BIT) & 0x01 )
#define TOG_BIT(VAR,BIT)		(VAR ^= (1 << (BIT)))

#endif