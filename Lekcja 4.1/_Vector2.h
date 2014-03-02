//_Vector2.h
#pragma once
class _Vector2
{
public:
	_Vector2(void);
	~_Vector2(void);

	float x,y;
	_Vector2(int _x,int _y);
	
	_Vector2 _Vector2::operator- 
		(const _Vector2 &rhs);
	_Vector2 _Vector2::operator* 
		(const double &rhs);

	void _Vector2::normalize();
};

