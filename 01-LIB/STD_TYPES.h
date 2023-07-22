/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: Library                       ************************/
/*************             Version: V1.0 - 03/10/2022           ************************/
/***************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#define NULL ( (void *)0 )

typedef unsigned char        u8;            /*           0 .. 255             */
typedef unsigned short int   u16;           /*           0 .. 65535           */
typedef unsigned long  int   u32;           /*           0 .. 4294967295      */

typedef signed char          s8;            /*        -128 .. +127            */
typedef signed short int     s16;           /*      -32768 .. +32767          */
typedef signed long  int     s32;           /* -2147483648 .. +2147483647     */

#define IDLE					0
#define BUSY					1

#endif
