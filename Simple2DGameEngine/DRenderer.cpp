#include "DRenderer.h"
#include "math.h"
#include <Windows.h>

#define RECTANGEL 1
#define EllIPSE 2

DRenderer::DRenderer(HDC newHdc, RECT newRect)
{
    hdc = newHdc;
    rect = newRect;
}

void DRenderer::Initialize(HDC newHdc, RECT newRect)
{
    hdc = newHdc;
    rect = newRect;
}

void DRenderer::Draw(DORender* object)
{
    const float PI = 3.14;

    switch (object->GetObjectType())
    {
    case RECTANGEL:
        DrawRectangel(object ,PI);
        break;
    case EllIPSE:
        DrawEllipse(object, PI);
        break;
    }
}

void DRenderer::Reset()
{
    GetClientRect(WindowFromDC(hdc), &rect); 
    FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DRenderer::DrawRectangel(DORender* object, float PI)
{
    Reset();

    
    int left =
        (int)(object->GetLeft() * cos(object->GetAngle() * PI / 360)
            - object->GetTop() * sin(object->GetAngle() * PI / 360));
    int right;
    int top;
    int bottom;
    Rectangle(hdc, object->GetLeft(), object->GetTop(), object->GetRight(), object->GetBottom());
}

void DRenderer::DrawEllipse(DORender* object, float PI)
{
    Reset();
    Ellipse(hdc, object->GetLeft(), object->GetTop(), object->GetRight(), object->GetBottom());
}