#include "SPI.h"

void SPI_init()
{
	/* Initialize SPI */

	SPIBR = 0x51; // 1Mbps

	SPICR1 = 0x52; // Master, MSB First, Slave 
	SPICR2 = 0x10; // SS' Enables
}



void SPI_TX(int data[], int size)
{
	unsigned char* buff = (unsigned char*)data;

	// Start of Tx
	shiftByteOut(SOT_Preamble);
	shiftByteOut(SOT_Preamble);

	int i = 0;
	while (size > 0) {

		int i;
		for (i = 0; i < sizeof(int); i++) {
			shiftByteOut(*(buff++));
		}
		
		size--;
	}

	// End of Tx
	shiftByteOut(EOT_Preamble);

}



void shiftByteOut(unsigned char byte)
{
	//Wait for Previous Data to be transmitted
	while (SPISR_SPTEF == 0);
	SPIDR = byte;
}







