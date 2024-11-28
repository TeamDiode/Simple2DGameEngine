#pragma once
#include "DOSprite.h"
#include "DList.hpp"
#include "DOCamera.h"
#include "DSingleton.hpp"
#include <Windows.h>

class DRenderer : public DSingleton<DRenderer>
{
public:
    DRenderer(HDC newHdc, HWND newhWnd) : hdc(newHdc), hWnd(newhWnd) {}

    static void Initialize();
    static void Destroy();

    static void RegisterSprite(DOSprite* sprite);
    //screenRect는 1920 * 1080같이 전체 크기
    //cameraRect는 실제 렌더링 시킬 카메라 크기
    void SetCameraOptions(RECT screenRect, RECT cameraRect);
    void MoveCamera(int type, int moveScale);
    void Draw();

private:
    HDC hdc;
    HWND hWnd;
    DOCamera camera;

    static DList<DOSprite*> sprites;
    static CRITICAL_SECTION spritesCriticalSection;

    void DrawBySpriteType(DOSprite* sprite);
    void DrawRectangel(DOSprite* sprite);
    void DrawEllipse(DOSprite* sprite);
};
