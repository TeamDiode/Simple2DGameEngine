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
/// ���� ���� �� ī�޶� ��ġ���� �ٸ��� �׸��� �Լ�
/// </summary>
void DOCamera::RenderBasedCamera()
{
	AllReset();
	LimitedCameraPositionInGameWorld();
	InvalidateRect(hWnd, &mapRect, TRUE);
}

/// <summary>
/// ���� ���� �� ī�޶� ��ġ�� �����ϴ� �Լ�
/// </summary>
void DOCamera::LimitedCameraPositionInGameWorld()
{
	//left ����
	if((int)(GetLocation().x - GetScale().x / 2) < mapRect.left)
	{ }

	//right ����
	if((int)(GetLocation().x + GetScale().x / 2) > mapRect.right)
	{ }

	//top ����
	if ((int)(GetLocation().y - GetScale().y / 2) < mapRect.top)
	{ }

	//bottom ����
	if ((int)(GetLocation().y + GetScale().y / 2) > mapRect.bottom)
	{ }
}

/// <summary>
/// ���� ������ ũ�⸦ �޾ƿ��� �Լ�
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