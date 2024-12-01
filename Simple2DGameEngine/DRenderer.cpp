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

void DRenderer::SetCameraOptions(RECT newCameraRect)
{
    camera.InitializeCamera(hWnd, hdc, newCameraRect);
}

void DRenderer::MoveCamera(DVector2i position)
{
    camera.Move(position);
}

void DRenderer::SetCameraSimulationLocation(DVector2i newLocation)
{
    camera.SetSimulationLocation(newLocation);
}

void DRenderer::Draw()
{
    AllReset();
    for (int i = sprites.GetSize(); i > 0; i--)
    {
        sprites.Move();
        DrawBySpriteType(sprites.GetValue());
    }
    camera.Rendering();
}

void DRenderer::Tick(double deltaTime)
{
    Draw();
    Sleep(displayInterval);
}

void DRenderer::AllReset()
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
    DVector2i spritesDisplayOffset = camera.GetLocation() - camera.GetSimulationLocation();
    int left = (int)sprite->GetLeftTopPosition().x + spritesDisplayOffset.x;
    int right = (int)sprite->GetRightTopPosition().x + spritesDisplayOffset.x;
    int top = (int)sprite->GetLeftTopPosition().y + spritesDisplayOffset.y;
    int bottom = (int)sprite->GetLeftBottomPosition().y + spritesDisplayOffset.y;

    MoveToEx(hdc, left, top, NULL);
    LineTo(hdc, right, top);
    LineTo(hdc, right, bottom);
    LineTo(hdc, left, bottom);
    LineTo(hdc, left, top);
}

void DRenderer::DrawEllipse(DOSprite* sprite)
{
    DVector2i spritesDisplayOffset = camera.GetLocation() - camera.GetSimulationLocation();
    int left = (int)sprite->GetLeftTopPosition().x + spritesDisplayOffset.x;
    int right = (int)sprite->GetRightTopPosition().x + spritesDisplayOffset.x;
    int top = (int)sprite->GetLeftTopPosition().y + spritesDisplayOffset.y;
    int bottom = (int)sprite->GetLeftBottomPosition().y + spritesDisplayOffset.y;

    Ellipse(hdc, left, top, right, bottom);
}