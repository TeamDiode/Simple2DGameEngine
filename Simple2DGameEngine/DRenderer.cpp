#include "DRenderer.h"
#include <Windows.h>

#define RECTANGEL 1
#define EllIPSE 2

DRenderer::DRenderer(HDC newHdc, RECT newRect, DORender* newObject)
{
    hdc = newHdc;
    rect = newRect;
    object = newObject;
}

void DRenderer::Initialize(HDC newHdc, RECT newRect, DORender* newObject)
{
    hdc = newHdc;
    rect = newRect;
    object = newObject;
}

void DRenderer::Draw()
{
    switch (object->GetObjectType())
    {
    case RECTANGEL:
        DrawRectangel();
        break;
    case EllIPSE:
        DrawEllipse();
        break;
    }
}

void DRenderer::Reset()
{
    GetClientRect(WindowFromDC(hdc), &rect); 
    FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DRenderer::DrawRectangel()
{
    Reset();
    Rectangle(hdc, object->GetLeft(), object->GetTop(), object->GetRight(), object->GetBottom());
}

void DRenderer::DrawEllipse() 
{
    Reset();
    Ellipse(hdc, object->GetLeft(), object->GetTop(), object->GetRight(), object->GetBottom());
}