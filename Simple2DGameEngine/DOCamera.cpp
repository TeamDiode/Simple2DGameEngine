#include "DOCamera.h"
#include "DObject.h"
#include "EDkeyCodeEnum.h"

void DOCamera::InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect)
{
    hWnd = newhWnd;
    hdc = newHdc;
    renderingRect = cameraRect;
    objectList = NULL;

    this->SetLocation((cameraRect.left + cameraRect.right) / 2,
        (cameraRect.top + cameraRect.bottom) / 2);
    this->SetScale(cameraRect.right - cameraRect.left,
        cameraRect.bottom - cameraRect.top);
}

void DOCamera::Rendering(DList<DOSprite*> objects)
{
    SelectClipRgn(hdc, NULL);
    if (!objects.IsEmpty())
        objectList = objects;
    DrawScreen();
    IntersectClipRect(hdc, renderingRect.left, renderingRect.top,
        renderingRect.right, renderingRect.bottom);
}

void DOCamera::Move(DVector2i position)
{
    for (int i = 0; i < objectList.GetSize(); i++)
    {
        DistanceCalculation(objectList.GetValue());
        objectList.Move();
    }
    DrawScreen();
}

void DOCamera::DistanceCalculation(DOSprite* object)
{
    DVector2i cameraLocation = this->GetLocation();
    DVector2i objectLocation = object->GetLocation();
    DVector2i relativeLocation = objectLocation - cameraLocation;

    object->SetLocation(relativeLocation + cameraLocation);
}

void DOCamera::DrawScreen()
{
    MoveToEx(hdc, renderingRect.left, renderingRect.top, NULL);
    LineTo(hdc, renderingRect.right - 1, renderingRect.top);
    LineTo(hdc, renderingRect.right - 1, renderingRect.bottom - 1);
    LineTo(hdc, renderingRect.left, renderingRect.bottom - 1);
    LineTo(hdc, renderingRect.left, renderingRect.top);
}