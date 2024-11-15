#include "DOCamera.h"
#include "DObject.h"

DOCamera::DOCamera()
{

}

DOCamera::DOCamera()
{
	hWnd = nullptr;
	hdc = nullptr;
	mapRect = { NULL };
}

/// <summary>
/// 게임 세상 속 카메라 위치마다 다르게 그리는 함수
/// </summary>
void DOCamera::RenderBasedCamera()
{
	AllReset();
	LimitedCameraPositionInGameWorld();
	InvalidateRect(hWnd, &mapRect, TRUE);
}

/// <summary>
/// 게임 세상 속 카메라 위치를 제한하는 함수
/// </summary>
void DOCamera::LimitedCameraPositionInGameWorld()
{
	//left 제한
	if((int)(GetLocation().x - GetScale().x / 2) < mapRect.left)
	{ }

	//right 제한
	if((int)(GetLocation().x + GetScale().x / 2) > mapRect.right)
	{ }

	//top 제한
	if ((int)(GetLocation().y - GetScale().y / 2) < mapRect.top)
	{ }

	//bottom 제한
	if ((int)(GetLocation().y + GetScale().y / 2) > mapRect.bottom)
	{ }
}

/// <summary>
/// 게임 세상의 크기를 받아오는 함수
/// </summary>
void DOCamera::RetrieveGameWorld(DObject* newMap)
{
	int left = (int)(newMap->GetLocation().x - newMap->GetScale().x / 2);
	int right = (int)(newMap->GetLocation().x + newMap->GetScale().x / 2);
	int top = (int)(newMap->GetLocation().y - newMap->GetScale().y / 2);
	int bottom = (int)(newMap->GetLocation().y + newMap->GetScale().y / 2);

	mapRect = { left,top,right,bottom };
}

void DOCamera::AllReset()
{
	GetClientRect(WindowFromDC(hdc), &mapRect);
	FillRect(hdc, &mapRect, (HBRUSH)(COLOR_WINDOW + 1));
}