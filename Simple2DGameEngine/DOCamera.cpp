#include "DOCamera.h"
#include "DObject.h"
#include "EDkeyCodeEnum.h"

void DOCamera::InitializeCamera(HWND newhWnd, HDC newHdc, RECT newScreenRect, RECT newCameraRect)
{
	hWnd = newhWnd;
	hdc = newHdc;
	screenRect = newScreenRect;
	cameraRect = newCameraRect;

	this->SetLocation((newCameraRect.left + newCameraRect.right) / 2, (newCameraRect.top + newCameraRect.bottom) / 2);
	this->SetScale(newCameraRect.right - newCameraRect.left, newCameraRect.bottom - newCameraRect.top);
}

void DOCamera::Rendering()
{
	AllReset();
	DrawCamera();
	InvalidateRect(hWnd, &cameraRect, TRUE);
}

void DOCamera::Move(int type ,int moveScale)
{
	LimitedMove();
	
	switch (type)
	{
	case W:
		this->GetLocation().y - moveScale;
		break;
	case A:
		this->GetLocation().x - moveScale;
		break;
	case S:
		this->GetLocation().y + moveScale;
		break;
	case D:
		this->GetLocation().y - moveScale;
		break;
	}
}

void DOCamera::DrawCamera()
{
	cameraRect.left = this->GetLocation().x - this->GetScale().x / 2;
	cameraRect.top = this->GetLocation().y - this->GetScale().y / 2;
	cameraRect.right = this->GetLocation().x + this->GetScale().x / 2;
	cameraRect.bottom = this->GetLocation().y + this->GetScale().y / 2;

	Rectangle(hdc, cameraRect.left, cameraRect.top, cameraRect.right, cameraRect.bottom);
}

void DOCamera::AllReset()
{
	GetClientRect(WindowFromDC(hdc), &screenRect);
	FillRect(hdc, &screenRect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DOCamera::LimitedMove()
{
	DVector2i pos(GetLocation().x, GetLocation().y);

	if (cameraRect.left < screenRect.left)
		pos.x = screenRect.left + this->GetScale().x / 2;

	if (cameraRect.right > screenRect.right)
		pos.x = screenRect.right - this->GetScale().x / 2;

	if (cameraRect.top < screenRect.top)
		pos.y = screenRect.top + this->GetScale().y / 2;

	if (cameraRect.bottom > screenRect.bottom)
		pos.y = screenRect.bottom - this->GetScale().y / 2;

	this->SetLocation(pos);
}