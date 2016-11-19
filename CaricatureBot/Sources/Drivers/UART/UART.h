/*
* UART.h
* This header contains all Peripheral Driver Declarations.
*
* Author		:	Piyush Sharm
* CO-Aouth		:	____________
* Date Created	:	11/11/2016
*
*/

#ifndef _UART_H
#define _UART_H

#include "../base.h"


#define TX_BUFFER_SIZE 1024
#define RX_BUFFER_SIZE 1024

// Constants & Definitions


// Function Definitions
void UART_init();

void UART_outChar(char x);
char UART_inChar(void);

#endif