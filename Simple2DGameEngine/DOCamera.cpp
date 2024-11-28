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
	DrawCamera();
    IntersectClipRect(hdc,
        this->GetLocation().x - this->GetScale().x / 2, //left
        this->GetLocation().y - this->GetScale().y / 2, //top
        this->GetLocation().x + this->GetScale().x / 2, //right
        this->GetLocation().y + this->GetScale().y / 2);//bottom
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
    }
    this->SetLocation(currentLocation);
    DrawCamera();
}


void DOCamera::DrawCamera()
{
    //cameraRect.left = this->GetLocation().x - this->GetScale().x / 2;
    //cameraRect.top = this->GetLocation().y - this->GetScale().y / 2;
    //cameraRect.right = this->GetLocation().x + this->GetScale().x / 2;
    //cameraRect.bottom = this->GetLocation().y + this->GetScale().y / 2;

	MoveToEx(hdc, this->GetLocation().x - this->GetScale().x / 2, this->GetLocation().y - this->GetScale().y / 2, NULL);
	LineTo(hdc, this->GetLocation().x + this->GetScale().x / 2, this->GetLocation().y - this->GetScale().y / 2);
	LineTo(hdc, this->GetLocation().x + this->GetScale().x / 2, this->GetLocation().y + this->GetScale().y / 2);
	LineTo(hdc, this->GetLocation().x - this->GetScale().x / 2, this->GetLocation().y + this->GetScale().y / 2);
	LineTo(hdc, this->GetLocation().x - this->GetScale().x / 2, this->GetLocation().y - this->GetScale().y / 2);
}