
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

	BASE_init();
	SPI_init();
	TIM_init();
	UART_init();

	Interpolator_init();
	Interpretor_init();

}


void loop()
{
	// Test  UART
	//UART_outChar('H');

	int Theta[4] = { 100,200,300,400 };

	SPI_TX(Theta, 4);

	delay(200);

	//int i = 0;
	//for (i = 0; i < 256; i++)
	//{
	//	delay(50);
	//}


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
