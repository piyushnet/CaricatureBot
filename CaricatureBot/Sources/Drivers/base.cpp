#include"base.h"

void BASE_init()
{

	/* Set the PLL speed (bus clock = 24 MHz) */
	CLKSEL = CLKSEL & 0x80; //; disengage PLL from system
	PLLCTL = PLLCTL | 0x40; //; turn on PLL
	SYNR = 0x02;            //; set PLL multiplier
	REFDV = 0;              //; set PLL divider
	while (!(CRGFLG & 0x08)) {}
	CLKSEL = CLKSEL | 0x80; //; engage PLL


	/* Disable watchdog timer (COPCTL register) */
	COPCTL = 0x40; //COP off; RTI and COP stopped in BDM-mode

}