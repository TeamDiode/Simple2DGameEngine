#include "DRenderer.h"
#include <Windows.h>

#define RECTANGEL 1
#define EllIPSE 2

void DRenderer::Draw(HDC hdc, RECT rect, DORender* object)
{
    switch (object->GetObjectType())
    {
    case RECTANGEL:
        DrawRectangel(hdc, rect ,object);
        break;
    case EllIPSE:
        DrawEllipse(hdc, rect, object);
        break;
    }
}

void DRenderer::Reset(HDC hdc, RECT rect)
{
    GetClientRect(WindowFromDC(hdc), &rect); 
    FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DRenderer::DrawRectangel(HDC hdc, RECT rect, DORender* object)
{
    Reset(hdc, rect);
    Rectangle(hdc, object->GetLeft(), object->GetTop(), object->GetRight(), object->GetBottom());
}

void DRenderer::DrawEllipse(HDC hdc, RECT rect, DORender* object)
{
    Reset(hdc, rect);
    Ellipse(hdc, object->GetLeft(), object->GetTop(), object->GetRight(), object->GetBottom());
}