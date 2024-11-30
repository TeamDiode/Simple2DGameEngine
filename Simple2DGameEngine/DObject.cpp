#include "DObject.h"
#include "DObjectManager.h"


DObject::DObject()
{
	// 뮤텍스 생성
	mutexHandle = CreateMutex(NULL, false, NULL);
	// 오브젝트 상태 초기화
	location = DVector2i();
	localLocation = DVector2i();
	angle = 0.f;
	scale = DVector2i();
	// 상위 오브젝트 초기화
	upperObject = nullptr;

	// 매니저에 등록
	DObjectManager::RegisterObject(this);
}

DObject::~DObject()
{
	// 뮤텍스 제거
	CloseHandle(mutexHandle);
	// 매니저에 탈퇴
	DObjectManager::CancelObject(this);
}

DVector2i DObject::GetLocation()
{
	return location;
}

void DObject::SetLocation(DVector2i newLocation)
{
	DWORD result = WaitForSingleObject(mutexHandle, INFINITE);

	// 로컬 좌표만큼 변경된 위치로 조정
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
	// 라디언에서 도로 변환한 뒤 앵글 초기화
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
	// 부착 대상의 상위 오브젝트를 자신으로 설정
	newLowerObject->SetUpperObject(this);
	// 하위 오브젝트에 대상을 추가
	lowerObjectAttachments.AddNext(newLowerObject);
}

void DObject::Update(double deltaTime)
{
}
