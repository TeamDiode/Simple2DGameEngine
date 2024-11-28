#pragma once
#include "DOSprite.h"
#include "DList.hpp"
#include "DOCamera.h"
#include "DSingleton.hpp"
#include "DSubSystem.h"
#include <Windows.h>

class DRenderer : public DSingleton<DRenderer>, public DSubSystem
{
public:
    DRenderer(HDC newHdc, HWND newhWnd);

    static void RegisterSprite(DOSprite* sprite);
    //screenRect�� 1920 * 1080���� ��ü ũ��
    //cameraRect�� ���� ������ ��ų ī�޶� ũ��
    void SetCameraOptions(RECT screenRect, RECT cameraRect);
    void MoveCamera(int type, int moveScale);
    void Draw();

    void Tick(double deltaTime) override;

private:
    HDC hdc;
    HWND hWnd;
    DOCamera camera;

    static DList<DOSprite*> sprites;

    void DrawBySpriteType(DOSprite* sprite);
    void DrawRectangel(DOSprite* sprite);
    void DrawEllipse(DOSprite* sprite);
};
