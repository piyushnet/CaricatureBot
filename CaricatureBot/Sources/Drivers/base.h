/*
* BASE.h
* This header contains all Peripheral Driver Declarations.
*
* Author		:	Piyush Sharm
* CO-Aouth		:	____________
* Date Created	:	11/11/2016
*
*/

#ifndef __HC12__
#define __HC12__
#endif
#ifndef _BASE_H
#define _BASE_H


#include<hidef.h>				/* Common Defines and Macros */
#include"../derivative.h"


#define AxisCount 5

// Definitions



// Function Definitions
void BASE_init();
void delay(int msdelay_time);


#endif
