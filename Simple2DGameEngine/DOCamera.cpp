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

void DOCamera::Move(int type, int moveScale)
{
    DVector2i currentLocation = this->GetLocation();

    switch (type)
    {
    case W:
        currentLocation.y -= moveScale;
        break;
    case A:
        currentLocation.x -= moveScale;
        break;
    case S:
        currentLocation.y += moveScale;
        break;
    case D:
        currentLocation.x += moveScale;
        break;
    default:
        return;
    }
    this->SetLocation(currentLocation);
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