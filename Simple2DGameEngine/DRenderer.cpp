#include "DRenderer.h"
#include "math.h"
#include <Windows.h>
#include "DList.hpp"
#include "DOCamera.h"

#define RECTANGEL 1
#define EllIPSE 2

DList<DOSprite*> DRenderer::sprites = DList<DOSprite*>();
CRITICAL_SECTION DRenderer::spritesCriticalSection; 

DRenderer::DRenderer(HDC newHdc, HWND newhWnd)
{
    hdc = newHdc;
    hWnd = newhWnd;
    InitializeSection();
}

DRenderer::~DRenderer()
{
    DestroySection();
}

void DRenderer::InitializeSection()
{
    InitializeCriticalSection(&spritesCriticalSection);
}

void DRenderer::DestroySection()
{
    DeleteCriticalSection(&spritesCriticalSection);
}

void DRenderer::RegisterSprite(DOSprite* sprite)
{
    EnterCriticalSection(&spritesCriticalSection); 
    sprites.AddNext(sprite);
    LeaveCriticalSection(&spritesCriticalSection); 
}

void DRenderer::SetCameraOptions(RECT screenRect, RECT cameraRect)
{
    camera.InitializeCamera(hWnd, hdc, screenRect, cameraRect);
}

void DRenderer::MoveCamera(int type, int moveScale)
{
    camera.Move(type, moveScale);
}

void DRenderer::Draw()
{
    EnterCriticalSection(&spritesCriticalSection); 
    for (int i = sprites.GetSize(); i > 0; i--)
    {
        sprites.Move();
        DrawBySpriteType(sprites.GetValue());
    }
    LeaveCriticalSection(&spritesCriticalSection);
    camera.Rendering();
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