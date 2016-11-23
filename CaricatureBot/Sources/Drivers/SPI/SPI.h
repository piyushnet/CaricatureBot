/*
* SPI.h
* This header contains all Peripheral Driver Declarations.
*
* Author		:	Piyush Sharm
* CO-Aouth		:	____________
* Date Created	:	11/11/2016
*
*/

#ifndef _SPI_H
#define _SPI_H

#include "../base.h"


// Constants & Definitions
#define SOT_Preamble 0b10101010
#define EOT_Preamble 0b10101011

// Function Definitions
void SPI_init();
void SPI_RX(int data[], int size);
void SPI_TX(int data[], int size);

void shiftByteOut(unsigned char byte);


#endif