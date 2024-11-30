#include "DOCamera.h"
#include "DObject.h"
#include "EDkeyCodeEnum.h"

void DOCamera::InitializeCamera(HWND newhWnd, HDC newHdc, RECT newCameraRect)
{
	hWnd = newhWnd;
	hdc = newHdc;

	this->SetLocation((newCameraRect.left + newCameraRect.right) / 2,
        (newCameraRect.top + newCameraRect.bottom) / 2);
	this->SetScale(newCameraRect.right - newCameraRect.left, 
        newCameraRect.bottom - newCameraRect.top);
}

void DOCamera::Rendering()
{
    SelectClipRgn(hdc, NULL); 
    IntersectClipRect(hdc,
        this->GetLocation().x - this->GetScale().x / 2, // left
        this->GetLocation().y - this->GetScale().y / 2, // top
        this->GetLocation().x + this->GetScale().x / 2, // right
        this->GetLocation().y + this->GetScale().y / 2  // bottom
    );
    DrawCamera();
}

void DOCamera::Move(DVector2i location)
{
    this->SetLocation(location);
    DrawCamera();
}

void DOCamera::Move(float x, float y)
{
    DVector2i location(x, y);
    this->SetLocation(location);
    DrawCamera();
}

void DOCamera::DrawCamera()
{
    int left = this->GetLocation().x - this->GetScale().x / 2;
    int top = this->GetLocation().y - this->GetScale().y / 2;
    int right = this->GetLocation().x + this->GetScale().x / 2;
    int bottom = this->GetLocation().y + this->GetScale().y / 2;

    // 카메라 사각형을 정확히 그림
    MoveToEx(hdc, left + 1, top + 1, NULL);
    LineTo(hdc, right - 1, top + 1);
    LineTo(hdc, right - 1, bottom- 1);
    LineTo(hdc, left + 1, bottom - 1);
    LineTo(hdc, left + 1, top + 1);
}