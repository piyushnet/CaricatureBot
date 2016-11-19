#include"UART.h"

void UART_init()
{

	/* Initialize asynchronous serial port (SCI) for 9600 baud, no interrupts */
	SCIBDH = 0x00; //set baud rate to 9600
	SCIBDL = 0x9C; //24,000,000 / 16 / 156 = 9600 (approx)  
	SCICR1 = 0x00; //$9C = 156
	SCICR2 = 0x0C; //initialize SCI for program-driven operation
	DDRB = 0x10; //set PB4 for output mode
	PORTB = 0x10; //assert DTR pin on COM port

}

/*
***********************************************************************
Character I/O Library Routines for 9S12C32 (for debugging only)
***********************************************************************
Name:         inchar
Description:  inputs ASCII character from SCI serial port and returns it
Example:      char ch1 = inchar();
***********************************************************************
*/
char UART_outChar(void) {
	/* receives character from the terminal channel */
	while (!(SCISR1 & 0x20)); /* wait for input */
	return SCIDRL;
}

/*
***********************************************************************
Name:         outchar
Description:  outputs ASCII character x to SCI serial port
Example:      outchar('x');
***********************************************************************
*/
void UART_outChar(char x) {
	/* sends a character to the terminal channel */
	while (!(SCISR1 & 0x80));  /* wait for output buffer empty */
	SCIDRL = x;
}
