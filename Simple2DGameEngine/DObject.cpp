#include "DObject.h"
#include "DObjectManager.h"


DObject::DObject()
{
	// ���ؽ� ����
	mutexHandle = CreateMutex(NULL, false, NULL);
	// ������Ʈ ���� �ʱ�ȭ
	location = DVector2i();
	localLocation = DVector2i();
	angle = 0.f;
	scale = DVector2i();
	// ���� ������Ʈ �ʱ�ȭ
	upperObject = nullptr;

	// �Ŵ����� ���
	DObjectManager::RegisterObject(this);
}

DObject::~DObject()
{
	// ���ؽ� ����
	CloseHandle(mutexHandle);
	// �Ŵ����� Ż��
	DObjectManager::CancelObject(this);
}

DVector2i DObject::GetLocation()
{
	return location;
}

void DObject::SetLocation(DVector2i newLocation)
{
	DWORD result = WaitForSingleObject(mutexHandle, INFINITE);

	// ���� ��ǥ��ŭ ����� ��ġ�� ����
	location = newLocation + localLocation;
	for (int i = lowerObjectAttachments.GetSize(); i > 0; i--)
	{
		lowerObjectAttachments.GetValue()->SetLocation(location);
	}
	ReleaseMutex(mutexHandle);
}

void DObject::SetLocation(int newLocationX, int newLocationY)
{
	SetLocation(DVector2i(newLocationX, newLocationY));
}

void DObject::SetLocalLocation(DVector2i newLocalLocation)
{
	DWORD result = WaitForSingleObject(mutexHandle, INFINITE);

	localLocation = newLocalLocation;
	ReleaseMutex(mutexHandle);
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
	DWORD result = WaitForSingleObject(mutexHandle, INFINITE);

	angle = degree;
	ReleaseMutex(mutexHandle);
}

void DObject::SetAngleByRadian(float radian)
{
	// ���𿡼� ���� ��ȯ�� �� �ޱ� �ʱ�ȭ
	SetAngle(radian * 3.1415 / 180);
}

DVector2i DObject::GetScale()
{
	return scale;
}

void DObject::SetScale(DVector2i newScale)
{
	DWORD result = WaitForSingleObject(mutexHandle, INFINITE);

	scale = newScale;
	ReleaseMutex(mutexHandle);
}

void DObject::SetScale(int newScaleX, int newScaleY)
{
	SetScale(DVector2i(newScaleX, newScaleY));
}

void DObject::SetUpperObject(DObject* newUpperObject)
{
	upperObject = upperObject;
}

void DObject::AttachObject(DObject* newLowerObject)
{
	// ���� ����� ���� ������Ʈ�� �ڽ����� ����
	newLowerObject->SetUpperObject(this);
	// ���� ������Ʈ�� ����� �߰�
	lowerObjectAttachments.AddNext(newLowerObject);
}

void DObject::Update(double deltaTime)
{
}
