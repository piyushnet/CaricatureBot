#include"TIM.h"

void TIM_init()
{

	/* Initialize TIM Ch 7 (TC7) for periodic interrupts every 1.000 ms */
	TSCR1 = 0x80;   // enable timer subsystem
	TIOS = 0x80;   // set channel 7 for output compare
	TSCR2 = 0x0C;   // set appropriate pre-scale factor and enable counter reset after OC7
	TIE = 0x80;   // enable TIM Ch 7 interrupt
	TC7 = 1500;   // set up channel 7 to generate 1 ms interrupt rate
	TIE_C7I = 0;    // initially disable TIM Ch 7 interrupts   

}


/*
***********************************************************************
TIM Channel 7 interrupt service routine
Initialized for 1.00 ms interrupt rate
Increment (3-digit) BCD variable "react" by one
***********************************************************************
*/

interrupt 15 void TIM_ISR(void)
{
	// clear TIM CH 7 interrupt flag
	TFLG1 = TFLG1 | 0x80;



	//react++;

}
