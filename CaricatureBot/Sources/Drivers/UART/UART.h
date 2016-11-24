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

// Constants & Definitions
#define XON  0x11
#define XOFF 0x13
#define LF   0x0A
#define CR   0x0D

#define TX_BUFFER_SIZE 512
#define RX_BUFFER_SIZE 512

// UART Recieve Buffer
extern char buf[RX_BUFFER_SIZE];

extern int rin;  //where to write into next
extern int rout; //where to read from next
extern int rin_trip;
extern int rout_trip;

extern unsigned char str_rec; //flag that string is received      

// Function Definitions
void UART_init();

void UART_outChar(char x);
char UART_inChar(void);

#endif