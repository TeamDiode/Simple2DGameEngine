#include "DOCamera.h"
#include "DObject.h"

DOCamera::DOCamera()
{
	hWnd = nullptr;
	hdc = nullptr;
	mapRect = { NULL };
}

void DOCamera::RenderBasedCamera()
{
	AllReset();
	LimitedCameraPositionInGameWorld();
	InvalidateRect(hWnd, &mapRect, TRUE);
}

void DOCamera::LimitedCameraPositionInGameWorld()
{
	float x = GetLocation().x;
	float y = GetLocation().y;

	//left 力茄
	if((int)(GetLocation().x - GetScale().x / 2) < mapRect.left)
	{ 
		x = mapRect.left + GetScale().x / 2;
		y = GetLocation().y;
	}

	//right 力茄
	if((int)(GetLocation().x + GetScale().x / 2) > mapRect.right)
	{
		x = mapRect.right - GetScale().x / 2;
		y = GetLocation().y;
	}

	//top 力茄
	if ((int)(GetLocation().y - GetScale().y / 2) < mapRect.top)
	{
		x = GetLocation().x;
		y = mapRect.top + GetScale().y / 2;
	}

	//bottom 力茄
	if ((int)(GetLocation().y + GetScale().y / 2) > mapRect.bottom)
	{
		x = GetLocation().x;
		y = mapRect.bottom - GetScale().y / 2;
	}

	SetLocation(DVector2i(x, y));
}

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