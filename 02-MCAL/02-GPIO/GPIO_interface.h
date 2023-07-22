/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             Layer: MCAL                          ************************/
/*************             Version: V1.0 - 08/10/2022           ************************/
/*************             MC: STM32F103C8T6 | ARM Cortex M3    ************************/
/***************************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*Registers*/
#define GPIOA           0
#define GPIOB           1
#define GPIOC           2

/*pins*/
#define GPIO_PIN0            0
#define GPIO_PIN1            1
#define GPIO_PIN2            2
#define GPIO_PIN3            3
#define GPIO_PIN4            4
#define GPIO_PIN5            5
#define GPIO_PIN6            6
#define GPIO_PIN7            7
#define GPIO_PIN8            8
#define GPIO_PIN9            9
#define GPIO_PIN10           10
#define GPIO_PIN11           11
#define GPIO_PIN12           12
#define GPIO_PIN13           13
#define GPIO_PIN14           14
#define GPIO_PIN15           15

/*Input modes*/
#define INPUT_ANALOG_MODE                   0b0000
#define INPUT_FLOATING_MODE                 0b0100
#define INPUT_PULLUP_MODE                   0x11
#define INPUT_PULLDOWN_MODE                 0x22

/*Output modes*/
/*speed 10 MHz*/
#define OUTPUT_10MHZ_PUSH_PULL               0b0001
#define OUTPUT_10MHZ_OPEN_DRAIN              0b0101
#define OUTPUT_10MHZ_AF_PUSH_PULL            0b1001       //alternate function
#define OUTPUT_10MHZ_AF_OPEN_DRAIN           0b1101       //alternate function

/*speed 2 MHz*/
#define OUTPUT_2MHZ_PUSH_PULL               0b0010
#define OUTPUT_2MHZ_OPEN_DRAIN              0b0110
#define OUTPUT_2MHZ_AF_PUSH_PULL            0b1010           //alternate function 
#define OUTPUT_2MHZ_AF_OPEN_DRAIN           0b1110           //alternate function 

/*speed 50 MHz*/
#define OUTPUT_50MHZ_PUSH_PULL               0b0011
#define OUTPUT_50MHZ_OPEN_DRAIN              0b0111
#define OUTPUT_50MHZ_AF_PUSH_PULL            0b1011         //alternate function
#define OUTPUT_50MHZ_AF_OPEN_DRAIN           0b1111         //alternate function

/*Value*/
#define PIN_LOW          0
#define PIN_HIGH         1

/*position*/
#define PORT_LOW           0
#define PORT_HIGH          1

/*Pin Functions*/
void GPIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode );
void GPIO_voidSetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void GPIO_voidGetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);
void GPIO_voidTogglePin       (u8 Copy_u8Port, u8 Copy_u8Pin);

/*Port Functions*/
/*Copy_u8Position --> PORT_HIGH for upper 8 bits, PORT_LOW for lower 8 bits*/
void GPIO_voidSetHalfPortDirection (u8 Copy_u8Port, u8 Copy_u8Position, u8 Copy_u8Mode );
void GPIO_voidSetHalfPortValue     (u8 Copy_u8Port, u8 Copy_u8Position, u16 Copy_u16Value);
void GPIO_voidGetHalfPortValue     (u8 Copy_u8Port, u8 Copy_u8Position, u16* Copy_pu16Value);

void GPIO_voidSetPortDirection (u8 Copy_u8Port, u8 Copy_u8Mode );
void GPIO_voidSetPortValue     (u8 Copy_u8Port, u16 Copy_u16Value);
void GPIO_voidGetPortValue     (u8 Copy_u8Port, u16* Copy_pu16Value);


#endif
