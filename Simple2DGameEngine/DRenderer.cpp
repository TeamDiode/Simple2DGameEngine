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
    MoveToEx(hdc, sprite->GetLeftTopPosition().x, sprite->GetLeftTopPosition().y, NULL);
    LineTo(hdc, sprite->GetRightTopPosition().x, sprite->GetRightTopPosition().y);
    LineTo(hdc, sprite->GetRightBottomPosiiton().x, sprite->GetRightBottomPosiiton().y);
    LineTo(hdc, sprite->GetLeftBottomPosition().x, sprite->GetLeftBottomPosition().y);
    LineTo(hdc, sprite->GetLeftTopPosition().x, sprite->GetLeftTopPosition().y);
}

void DRenderer::DrawEllipse(DOSprite* sprite)
{
    Reset();
    Ellipse(hdc, sprite->GetLeftTopPosition().x, sprite->GetLeftTopPosition().y, 
        sprite->GetRightBottomPosiiton().x, sprite->GetRightBottomPosiiton().y);
}