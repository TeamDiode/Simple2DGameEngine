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
}

DRenderer::DRenderer(HDC newHdc)
{
    hdc = newHdc;
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
    MoveToEx(hdc, (int)sprite->GetLeftTopPosition().x, (int)sprite->GetLeftTopPosition().y, NULL);
    LineTo(hdc, (int)sprite->GetRightTopPosition().x, (int)sprite->GetRightTopPosition().y);
    LineTo(hdc, (int)sprite->GetRightBottomPosiiton().x, (int)sprite->GetRightBottomPosiiton().y);
    LineTo(hdc, (int)sprite->GetLeftBottomPosition().x, (int)sprite->GetLeftBottomPosition().y);
    LineTo(hdc, (int)sprite->GetLeftTopPosition().x, (int)sprite->GetLeftTopPosition().y);
}

void DRenderer::DrawEllipse(DOSprite* sprite)
{
    Ellipse(hdc, (int)sprite->GetLeftTopPosition().x, (int)sprite->GetLeftTopPosition().y,
        (int)sprite->GetRightBottomPosiiton().x, (int)sprite->GetRightBottomPosiiton().y);
}