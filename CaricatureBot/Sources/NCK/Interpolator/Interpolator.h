/*
* INTERPOLATOR.h
* This header contains all Peripheral Driver Declarations.
*
* Author		:	Piyush Sharm
* CO-Aouth		:	____________
* Date Created	:	11/11/2016
*
*/

#ifndef _INTERPOLATOR_H
#define _INTERPOLATOR_H

#include "../../Drivers/base.h"


// Constants & Definitions

// Function Definitions
void Interpolator_init();
void LinearInterpolate(float EndX, float EndY, float EndZ, float Feed);
void CircularInterpolateCW(float EndX, float EndY, float EndZ, float i, float j, float Feed);
void CircularInterpolateCCW(float EndX, float EndY, float EndZ, float i, float j, float Feed);



#endif