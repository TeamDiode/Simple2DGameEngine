#include "DOCamera.h"
#include "DObject.h"
#include "EDkeyCodeEnum.h"

void DOCamera::InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect)
{
    hWnd = newhWnd;
    hdc = newHdc;
    renderingRect = cameraRect;

    this->SetLocation((cameraRect.left + cameraRect.right) / 2,
        (cameraRect.top + cameraRect.bottom) / 2);
    this->SetScale(cameraRect.right - cameraRect.left,
        cameraRect.bottom - cameraRect.top);
}

void DOCamera::Rendering()
{
    SelectClipRgn(hdc, NULL);

    IntersectClipRect(hdc, renderingRect.left, renderingRect.top,
        renderingRect.right, renderingRect.bottom);

    CopyToRenderingRect();
    
    DrawScreen();
}

void DOCamera::Move(int type, double moveScale)
{
    DVector2i moveOffset;

    switch (type)
    {
    case W:
        moveOffset = DVector2i(0, -moveScale);
        break;
    case A:
        moveOffset = DVector2i(-moveScale, 0);
        break;
    case S:
        moveOffset = DVector2i(0, moveScale);
        break;
    case D:
        moveOffset = DVector2i(moveScale, 0);
        break;
    }

    this->SetLocation(this->GetLocation() + moveOffset);
    CopyToRenderingRect();
    DrawScreen();
}

void DOCamera::Move(DVector2i position)
{
    this->SetLocation(position);
    CopyToRenderingRect();
    DrawScreen();
}

void DOCamera::Move(DObject* object)
{
    DVector2i position = object->GetLocation();
    this->SetLocation(position);
    CopyToRenderingRect();
    DrawScreen();
}

void DOCamera::DrawScreen()
{
    MoveToEx(hdc, renderingRect.left, renderingRect.top, NULL);
    LineTo(hdc, renderingRect.right - 1, renderingRect.top);
    LineTo(hdc, renderingRect.right - 1, renderingRect.bottom - 1);
    LineTo(hdc, renderingRect.left, renderingRect.bottom - 1);
    LineTo(hdc, renderingRect.left, renderingRect.top);
}

void DOCamera::CopyToRenderingRect()
{
    int left = this->GetLocation().x - this->GetScale().x / 2;
    int top = this->GetLocation().y - this->GetScale().y / 2;


    BitBlt(hdc, renderingRect.left , renderingRect.top,
        this->GetScale().x,
        this->GetScale().y,
        hdc, left, top, SRCCOPY);
}