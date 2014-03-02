//_Vector2.cpp
#include "_Vector2.h"
#include <math.h>


_Vector2::_Vector2(int _x,int _y)
{
	x = _x;
	y = _y;
}


_Vector2::~_Vector2(void)
{
}

	
_Vector2 _Vector2::operator- (const _Vector2 &rhs)
{
    x -= rhs.x;
	y -= rhs.y;
    return _Vector2(*this);
}


_Vector2 _Vector2::operator* (const double &rhs)
{
	x *= rhs;
	y *= rhs;

	return _Vector2(*this);
}

void _Vector2::normalize()
{
	float tmp = x*x+y*y;
	double length = sqrt(tmp);
	
	x = x/length;
	y = y/length;
}