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
    //screenRect�� 1920 * 1080���� ��ü ũ��
    //cameraRect�� ���� ������ ��ų ī�޶� ũ��
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
