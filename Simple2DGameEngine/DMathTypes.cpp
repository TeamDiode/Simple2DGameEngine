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
	float v = sqrt((x*x) + (y*y));
	x = x / v;
	y = y / v;
}

float DVector2i::Dot(DVector2i value)
{
	return (x * value.x) + (y * value.y);
}

DVector2i DVector2i::Cross(DVector2i value)
{
	return DVector2i((x + value.y), (value.x + y));
}

float DVector2i::Distance(DVector2i value1, DVector2i value2)
{
	return std::sqrt(std::pow(value2.x - value1.x, 2) + std::pow(value2.y - value1.y, 2));
}
