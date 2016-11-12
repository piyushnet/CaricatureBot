#include "SPI.h"

void SPI_init()
{
	/* Initialize SPI for baud rate of 6 Mbs */
	SPIBR = 0x01;
	SPICR1 = 0x50;
	SPICR2 = 0x00;
	
}

