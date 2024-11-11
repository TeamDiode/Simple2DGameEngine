#include "DRenderer.h"
#include "math.h"
#include <Windows.h>
#include "DList.hpp"

#define RECTANGEL 1
#define EllIPSE 2


DList<DOSprite*> DRenderer::sprites = DList<DOSprite*>();

DRenderer::DRenderer()
{
    hdc = NULL;
    rect = RECT();
}

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
    for (int i = sprites.GetSize(); i > 0; i--)
    {
        sprites.Move();
        DrawBySpriteType(sprites.GetValue());
    }
        
}

void DRenderer::Reset()
{
    GetClientRect(WindowFromDC(hdc), &rect);
    FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DRenderer::DrawBySpriteType(DOSprite* sprite)
{
    switch (sprite->GetType())
    {
    case RECTANGEL:
        DrawRectangel(sprite);
        break;
    case EllIPSE:
        DrawEllipse(sprite);
        break;
    }
}

void DRenderer::DrawRectangel(DOSprite* sprite)
{
    Reset();
    MoveToEx(hdc, (int)sprite->GetLeftTopPosition().x, (int)sprite->GetLeftTopPosition().y, NULL);
    LineTo(hdc, (int)sprite->GetRightTopPosition().x, (int)sprite->GetRightTopPosition().y);
    LineTo(hdc, (int)sprite->GetRightBottomPosiiton().x, (int)sprite->GetRightBottomPosiiton().y);
    LineTo(hdc, (int)sprite->GetLeftBottomPosition().x, (int)sprite->GetLeftBottomPosition().y);
    LineTo(hdc, (int)sprite->GetLeftTopPosition().x, (int)sprite->GetLeftTopPosition().y);
}

void DRenderer::DrawEllipse(DOSprite* sprite)
{
    Reset();
    Ellipse(hdc, (int)sprite->GetLeftTopPosition().x, (int)sprite->GetLeftTopPosition().y,
        (int)sprite->GetRightBottomPosiiton().x, (int)sprite->GetRightBottomPosiiton().y);
}