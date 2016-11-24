#include"UART.h"

char buf[RX_BUFFER_SIZE] = { 0 };
int rin = 0;  //where to write into next
int rout = 0; //where to read from next
int rin_trip = 0;
int rout_trip = 0;
unsigned char str_rec = 0;

void UART_init()
{

	/* Initialize asynchronous serial port (SCI) for 9600 baud, no interrupts */
	SCIBDH = 0x00; //set baud rate to 9600
	SCIBDL = 0x0D; //24,000,000 / 16 / 156(9C) = 9600 (approx)  or //24,000,000 / 16 / 13(0D) = 115200 (approx)

	SCICR1 = 0x00; 
	SCICR2 = 0x2C; //initialize SCI for RX_Int
	
	DDRB =  0x10; //set PB4 for output mode
	PORTB = 0x10; //assert DTR pin on COM port


	// Buffer Initializations
	rin = 0;  //where to write into next
	rout = 0; //where to read from next
	rin_trip = 0;
	rout_trip = 0;
	str_rec = 0;

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
char UART_inChar(void) {
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


/*
***********************************************************************
SCI (transmit section) interrupt service routine, fired when a
character is received
***********************************************************************
*/
interrupt 20 void SCI_ISR(void)
{
	if ((rin + rin_trip*RX_BUFFER_SIZE) > (rout + rout_trip*RX_BUFFER_SIZE + RX_BUFFER_SIZE - 2)) {
		UART_outChar(XOFF);
	}

	buf[rin] = UART_inChar();
	UART_outChar(buf[rin]);

	
	if (rin == RX_BUFFER_SIZE) {
		rin_trip++;
	}

	rin = (rin + 1) % (RX_BUFFER_SIZE);   //incrementing rin 


	if (buf[rin] == LF) { //'|' terminating cahracter
		str_rec = 1;
	}

}