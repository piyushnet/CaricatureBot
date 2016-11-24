/*
* INTERPRETOR.h
* This header contains all Peripheral Driver Declarations.
*
* Author		:	Piyush Sharm
* CO-Aouth		:	____________
* Date Created	:	11/11/2016
*
*/

#ifndef _INTERPRETOR_H
#define _INTERPRETOR_H

#include "../../Drivers/base.h"


// Constants & Definitions
//char *TestStr = "G02 X92.467267 Y106.403365 Z-1.000000 I22.622677 J17.433131 ";

// Function Definitions
void Interpretor_init();
void Interpretor_parse(const char* str);

#endif