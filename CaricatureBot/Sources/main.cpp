
/* Hardware Drivers */
#include"Drivers/base.h"
#include"Drivers/TIM/TIM.h"
#include"Drivers/SPI/SPI.h"
#include"Drivers/UART/UART.h"

/* Motion Control System */
#include"NCK/Interpolator/Interpolator.h"
#include"NCK/Interpretor/Interpretor.h"



/* System Initializations  */
void initialize()
{
	//Sub-system initializations

	TIM_init();
	SPI_init();
	UART_init();

	Interpretor_init();
	Interpolator_init();
	
}


void loop()
{



}


// Main Entrypoint
/* please make sure that you never leave main */
void main(void)
{
	// Initialize all sub-systems
	initialize();
	
	// Enable Interrupts
	EnableInterrupts;

	// Loop forever
	for (;;) {

		_FEED_COP(); /* feeds the dog */
		loop();

	}

}
