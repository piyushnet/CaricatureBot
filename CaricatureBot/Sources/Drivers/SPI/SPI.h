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


// Function Definitions
void SPI_init();
void SPI_RX();
void SPI_Tx();

void shiftByteOut(char byte);
void delay(int msdelay_time);

#endif