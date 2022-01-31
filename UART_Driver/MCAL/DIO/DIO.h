/*
 * DIO.h
 *
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Library/BIT_Math.h"
#include "../../Library/Typedef.h"
#include "../../Library/Atmega32.h"

#define  DIO_PORTA    0
#define  DIO_PORTB    1
#define  DIO_PORTC    2
#define  DIO_PORTD    3

#define  DIO_PIN0     0
#define  DIO_PIN1     1
#define  DIO_PIN2     2
#define  DIO_PIN3     3
#define  DIO_PIN4     4
#define  DIO_PIN5     5
#define  DIO_PIN6     6
#define  DIO_PIN7     7

#define ERR 0
#define OK 1

#define  DIO_PORT_OUTPUT     0XFF
#define  DIO_PORT_INPUT      0X00

#define  DIO_PIN_OUTPUT      1
#define  DIO_PIN_INPUT       0

#define  DIO_PORT_HIGH     0XFF
#define  DIO_PORT_LOW      0X00

#define  DIO_PIN_HIGH       1
#define  DIO_PIN_LOW        0


typedef enum{
	DIO_ERR,
	DIO_OK
}DIO_ERR_STATE;



DIO_ERR_STATE DIO_SetPortDir(uint8_t Port, uint8_t Dir);
DIO_ERR_STATE DIO_SetPinDir(uint8_t Port , uint8_t Pin , uint8_t Dir);

DIO_ERR_STATE DIO_SetPortValue(uint8_t Port, uint8_t Vlaue);
DIO_ERR_STATE DIO_SetPinValue(uint8_t Port , uint8_t Pin , uint8_t Value);

DIO_ERR_STATE DIO_ReadPortValue(uint8_t Port, uint8_t* Value);
DIO_ERR_STATE DIO_ReadPinValue(uint8_t Port, uint8_t Pin ,uint8_t* Value);

DIO_ERR_STATE DIO_TogglePort(uint8_t Port);
DIO_ERR_STATE DIO_TogglePin(uint8_t Port, uint8_t Pin);

DIO_ERR_STATE DIO_SetPullUp(uint8_t Port, uint8_t Pin);


#endif /* DIO_H_ */