#include "DObject.h"


// TODO : 라디언 단위로 각도 수정하는 부분 개선

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
	return location;
}

void DObject::SetLocation(DVector2i newLocation)
{
	location = newLocation;
}

void DObject::SetLocation(int newLocationX, int newLocationY)
{
	location = DVector2i(newLocationX, newLocationY);
}

float DObject::GetAngle()
{
	return angle;
}

void DObject::SetAngle(float degree)
{
	angle = degree;
}

void DObject::SetAngleByRadian(float radian)
{
	angle = radian * 3.1415 / 180; // 수학 부분에서 추가 구현 후 수정
}

DVector2i DObject::GetScale()
{
	return scale;
}

void DObject::SetScale(DVector2i newScale)
{
	scale = newScale;
}

void DObject::SetScale(int newScaleX, int newScaleY)
{
	scale = DVector2i(newScaleX, newScaleY);
}
