#include "DMathTypes.h"

DVector2i::DVector2i()
{
	x = 0;
	y = 0;
}

DVector2i::DVector2i(int x, int y)
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

DVector2i DVector2i::operator*(int value)
{
	return DVector2i(x * value, y * value);
}


float DVector2i::Distance(DVector2i value1, DVector2i value2)
{
	return std::sqrt(std::pow(value2.x - value1.x, 2) + std::pow(value2.y - value1.y, 2));
}
