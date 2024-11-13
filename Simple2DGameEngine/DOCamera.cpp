#include "DOCamera.h"
#include "DObject.h"

DOCamera::DOCamera(HWND newHWnd)
{
	hWnd = newHWnd;
	InitRect();
}

DOCamera::DOCamera()
{
	InitRect();
}

void DOCamera::PrintScreen()
{
	InvalidateRect(hWnd, &rect, true);
}

void DOCamera::InitRect()
{
	int left = (int)(GetLocation().x - GetScale().x / 2);
	int right = (int)(GetLocation().x + GetScale().x / 2);
	int top = (int)(GetLocation().y - GetScale().y / 2);
	int bottom = (int)(GetLocation().y + GetScale().y / 2);

	rect = { left, top, right, bottom };
}