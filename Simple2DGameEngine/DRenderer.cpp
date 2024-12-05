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

void DRenderer::CancelSprite(DOSprite* sprite)
{
    int remainLoopAmount = sprites.GetSize();

    while (remainLoopAmount-- && sprites.Move())
    {
        if (sprites.GetValue() == sprite)
        {
            sprites.RemoveHere();
            
            break;
        }
    }
}

void DRenderer::SetCameraOptions()
{
    //카메라 초기화
    camera.InitializeCamera(hWnd, hdc, cameraRect);
}

void DRenderer::SetCameraOptions(RECT newCameraRect)
{
    //카메라 초기화
    camera.InitializeCamera(hWnd, hdc, newCameraRect);
}

void DRenderer::MoveCamera(DVector2i position)
{
    //카메라 이동
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
    //전체 화면의 정보 받아오기
    GetClientRect(WindowFromDC(hdc), &rect);
    //전체 화면을 하얀색으로 초기화
    FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DRenderer::DrawBySpriteType(DOSprite* sprite)
{
    //이미지별 타입에 따라 분류
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
    //시뮬레이션 세계에서의 위치 적용
    DVector2i spritesDisplayOffset = camera.GetLocation() - camera.GetSimulationLocation();
    int left = (int)sprite->GetLeftTopPosition().x + spritesDisplayOffset.x;
    int right = (int)sprite->GetRightTopPosition().x + spritesDisplayOffset.x;
    int top = (int)sprite->GetLeftTopPosition().y + spritesDisplayOffset.y;
    int bottom = (int)sprite->GetLeftBottomPosition().y + spritesDisplayOffset.y;

    //사각형 그리기
    MoveToEx(hdc, left, top, NULL);
    LineTo(hdc, right, top);
    LineTo(hdc, right, bottom);
    LineTo(hdc, left, bottom);
    LineTo(hdc, left, top);
}

void DRenderer::DrawEllipse(DOSprite* sprite)
{
    //시뮬레이션 세게에서의 위치 적용
    DVector2i spritesDisplayOffset = camera.GetLocation() - camera.GetSimulationLocation();
    int left = (int)sprite->GetLeftTopPosition().x + spritesDisplayOffset.x;
    int right = (int)sprite->GetRightTopPosition().x + spritesDisplayOffset.x;
    int top = (int)sprite->GetLeftTopPosition().y + spritesDisplayOffset.y;
    int bottom = (int)sprite->GetLeftBottomPosition().y + spritesDisplayOffset.y;

    //원 그리기
    Ellipse(hdc, left, top, right, bottom);
}