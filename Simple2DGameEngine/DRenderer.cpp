#include "DRenderer.h"
#include "math.h"
#include <Windows.h>
#include "DList.hpp"
#include "DOCamera.h"

#define RECTANGEL 1
#define EllIPSE 2

DList<DOSprite*> DRenderer::sprites = DList<DOSprite*>();
DOCamera DRenderer::camera = DOCamera();

DRenderer::DRenderer()
{
    hdc = nullptr;
    hWnd = nullptr;
}

DRenderer::DRenderer(HDC newHdc, HWND newhWnd)
{
    hdc = newHdc;
    hWnd = newhWnd;
    SetCameraOptions();
}

void DRenderer::RegisterSprite(DOSprite* sprite)
{
    sprites.AddNext(sprite);
}

void DRenderer::SetCameraOptions()
{
    camera.InitializeCamera(hWnd, hdc, cameraRect);
}

void DRenderer::MoveCamera(DVector2i location)
{
    camera.Move(location);
}

void DRenderer::MoveCamera(float x, float y)
{
    camera.Move(x, y);
}

void DRenderer::Draw()
{
    AllReset();
    camera.Rendering();
    for (int i = sprites.GetSize(); i > 0; i--)
    {
        sprites.Move();
        DrawBySpriteType(sprites.GetValue());
    }
}

void DRenderer::Tick(double deltaTime)
{
    Draw();
    Sleep(displayInterval);
}

void DRenderer::AllReset()
{
    GetClientRect(WindowFromDC(hdc), &rt);
    FillRect(hdc, &rt, (HBRUSH)(COLOR_WINDOW + 1));
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