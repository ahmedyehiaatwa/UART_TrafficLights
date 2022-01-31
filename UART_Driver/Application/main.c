/*
 * UART_Driver.c
 *
 * Author : Ahmed
 */ 

#include "../ECUAL/LED/LED.h"
#include "../MCAL/UART/UART.h"
#include <string.h>


int main(void)
{
    UART_Init();						// initialize UART comm
    TIMER0_u8Init();					// initialize TIMER0 to  use delay
    LED0_Init();					// initialize Green LED
    LED1_Init();					// initialize Red LED
    LED2_Init();					// initialize Yellow LED
    uint8_t R_Str [256] ;						// array to contain Received string
    uint8_t WAIT_Str [] = {"WAIT"}  ;			// wait string
    uint8_t AT_Str [] = {"AT"}  ;				// AT string
    uint8_t START_Str [] = {"START"}  ;			// start string
    uint8_t STOP_Str [] = {"STOP"}  ;			// stop string
    
    while(1)
    {
	    UART_RxString(R_Str);					// receive string from terminal
	    if ( strcmp (R_Str,START_Str))
	    {
		    LED0_On();
		    LED1_On();
		    LED2_On();
		    UART_TxString("Green LED is on");
		    UART_Tx(NEWLINE);
	    }
	    else if ( strcmp (R_Str,STOP_Str))
	    {
		    LED0_Off();
		    LED1_On();
		    LED2_Off();
		    UART_TxString("Red LED is on");
		    UART_Tx(NEWLINE);
	    }
	    else if ( strcmp (R_Str,WAIT_Str))
	    {
		    LED0_Off();
		    LED1_Off();
		    LED2_On();
		    UART_TxString("Yellow LED is on");
		    UART_Tx(NEWLINE);
	    }
	    else if ( strcmp (R_Str,AT_Str))
	    {
		    UART_TxString("OK");
		    UART_Tx(NEWLINE);
	    }
	    else
	    {
		    UART_TxString("Wrong Input");
		    UART_Tx(NEWLINE);
	    }
    }
    }


