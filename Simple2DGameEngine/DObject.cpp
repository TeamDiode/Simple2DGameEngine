#include "DObject.h"

DObject::DObject()
{
	location = DVector2i();
	angle = 0.f;
	scale = DVector2i();
}

DObject::~DObject()
{
}

DVector2i DObject::GetLocation()
{
	return DVector2i();
}

void DObject::SetLocation(DVector2i newLocation)
{
}

void DObject::SetLocation(int newLocationX, int newLocationY)
{
}

float DObject::GetAngle()
{
	return 0.0f;
}

void DObject::SetAngle(float degree)
{
}

void DObject::SetAngleByRadian(float radian)
{
}

DVector2i DObject::GetScale()
{
	return DVector2i();
}

void DObject::SetScale(DVector2i newScale)
{
}

void DObject::SetScale(int newScaleX, int newScaleY)
{
}
