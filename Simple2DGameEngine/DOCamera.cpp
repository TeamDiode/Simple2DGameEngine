#include "DOCamera.h"
#include "DObject.h"

#define LEFT GetLocation().x - GetScale().x / 2
#define RIGHT GetLocation().x + GetScale().x / 2
#define TOP GetLocation().y - GetScale().y / 2
#define BOTTOM GetLocation().y + GetScale().y / 2

DOCamera::DOCamera(HWND newHWnd)
{
	hWnd = newHWnd;
	rect = { LEFT, TOP, RIGHT, BOTTOM };
}

DOCamera::DOCamera()
{
	rect = { LEFT, TOP, RIGHT, BOTTOM };
}

void DOCamera::PrintScreen()
{
	InvalidateRect(hWnd, &rect, true);
}