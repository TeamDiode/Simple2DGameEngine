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

void DRenderer::RegisterSprite(DOSprite* sprite)
{
    sprites.AddNext(sprite);
}

void DRenderer::Draw()
{
    while (sprites.Move())
        DrawBySpriteType(sprites.GetValue());
}

void DRenderer::Reset()
{
    GetClientRect(WindowFromDC(hdc), &rect);
    FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DRenderer::DrawBySpriteType(DOSprite* sptrite)
{
    switch (sptrite->GetType())
    {
    case RECTANGEL:
        DrawRectangel(sptrite);
        break;
    case EllIPSE:
        DrawEllipse(sptrite);
        break;
    }
}

void DRenderer::DrawRectangel(DOSprite* sptrite)
{
    Reset();
    Rectangle(hdc, sptrite->GetLeft(), sptrite->GetTop(), sptrite->GetRight(), sptrite->GetBottom());
}

void DRenderer::DrawEllipse(DOSprite* sptrite)
{
    Reset();
    Ellipse(hdc, sptrite->GetLeft(), sptrite->GetTop(), sptrite->GetRight(), sptrite->GetBottom());
}