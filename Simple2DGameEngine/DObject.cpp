#include "DObject.h"


// TODO : ���� ������ ���� �����ϴ� �κ� ����. ���� ������Ʈ���� �����͸� ��� ����Ʈ �ʱ�ȭ���� ���� ���� �ذ�

DObject::DObject()
{
	location = DVector2i();
	localLocation = DVector2i();
	angle = 0.f;
	scale = DVector2i();
	upperObject = nullptr;
}

DObject::~DObject()
{
	// ���� ������Ʈ�� �޸� ����
}

DVector2i DObject::GetLocation()
{
	return location;
}

void DObject::SetLocation(DVector2i newLocation)
{
	location = newLocation + localLocation;
	for (int i = lowerObjectAttachments.GetSize(); i > 0; i--)
	{
		lowerObjectAttachments.GetValue()->SetLocation(location);
	}
}

void DObject::SetLocation(int newLocationX, int newLocationY)
{
	SetLocation(DVector2i(newLocationX, newLocationY));
}

void DObject::SetLocalLocation(DVector2i newLocalLocation)
{
	localLocation = newLocalLocation;
}

void DObject::SetLocalLocation(int newLocalLocationX, int newLocalLocationY)
{
	SetLocalLocation(DVector2i(newLocalLocationX, newLocalLocationY));
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
	angle = radian * 3.1415 / 180; // ���� �κп��� �߰� ���� �� ����
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

void DObject::SetUpperObject(DObject* newUpperObject)
{
	upperObject = upperObject;
}

void DObject::AttachObject(DObject* newLowerObject)
{
	newLowerObject->SetUpperObject(this);
	lowerObjectAttachments.AddNext(newLowerObject);
}

void DObject::Update()
{
}
