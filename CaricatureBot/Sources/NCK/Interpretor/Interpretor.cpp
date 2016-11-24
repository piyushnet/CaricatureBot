#include"Interpretor.h"
#include"../Interpolator/Interpolator.h"

// New G Command
float _X, _Y, _Z, _i, _j, _F;
unsigned char _G;

void Interpretor_init()
{
	_G = 0;
	_X = _Y = _Z = 0;
	_i = _j = 0;
	_F = 0;
}

void Interpretor_parse(const char* str)
{

	// Parse the String


	// Call appropriate Interpolator Function
	if (_G == 1)
	{
		LinearInterpolate(_X, _Y, _Z, _F);
	}
	else if (_G == 2)
	{
		CircularInterpolateCW(_X, _Y, _Z, _i, _j, _F);
	}
	else if (_G == 3)
	{
		CircularInterpolateCCW(_X, _Y, _Z, _i, _j, _F);
	}


}

