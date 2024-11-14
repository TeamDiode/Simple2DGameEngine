#include "DMathTypes.h"
#include <cmath>


DVector2i::DVector2i()
{
	x = 0.0f;
	y = 0.0f;
}

DVector2i::DVector2i(float x, float y)
{
	this->x = x;
	this->y = y;
}

DVector2i DVector2i::operator+(DVector2i value)
{
	return DVector2i(x + value.x, y + value.y);
}

DVector2i DVector2i::operator-(DVector2i value)
{
	return DVector2i(x - value.x, y - value.y);
}

DVector2i DVector2i::operator*(float value)
{
	return DVector2i(x * value, y * value);
}

void DVector2i::Normalize()
{
	float v = sqrt(pow(x,x) + pow(y,y));
	x = x / v;
	y = y / v;
}

float DVector2i::Dot(DVector2i value)
{
	return (x * value.x) + (y * value.y);
}

float DVector2i::Cross(DVector2i value)
{
	return (x * value.y) - (value.x * y);
}
