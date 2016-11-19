
/* Hardware Drivers */
#include"Drivers/base.h"
#include"Drivers/TIM/TIM.h"
#include"Drivers/SPI/SPI.h"
#include"Drivers/UART/UART.h"

/* Motion Control System */
#include"NCK/Interpolator/Interpolator.h"
#include"NCK/Interpretor/Interpretor.h"

#include<hidef.h>


/* System Initializations  */
void initialize()
{
	//Sub-system initializations


	SPI_init();
	TIM_init();
	UART_init();

	Interpolator_init();
	Interpretor_init();

}


void loop()
{



}


// Main Entrypoint
/* please make sure that you never leave main */
void main(void)
{
	// Disable Interrupts for Initialization
	DisableInterrupts;

	// Initialize all sub-systems
	initialize();

	// Enable back Interrupts
	EnableInterrupts;

	// Loop forever
	for (;;)
	{

		//_FEED_COP(); /* feeds the dog */
		//COP off; RTI and COP stopped in BDM-mode

		loop();

	}

}
