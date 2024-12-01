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
    DrawScreen();
    IntersectClipRect(hdc, renderingRect.left, renderingRect.top,
        renderingRect.right, renderingRect.bottom);
}

void DOCamera::SetSimulationLocation(DVector2i newLocation)
{
    simulationLocation = newLocation;
}

DVector2i DOCamera::GetSimulationLocation()
{
    return simulationLocation;
}

void DOCamera::Move(DVector2i position)
{
    simulationLocation = simulationLocation + position;
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