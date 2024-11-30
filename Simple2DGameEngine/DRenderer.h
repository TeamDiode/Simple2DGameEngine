#pragma once
#include "DOSprite.h"
#include "DList.hpp"
#include "DOCamera.h"
#include "DSingleton.hpp"
#include "DSubSystem.h"
#include <Windows.h>

#define FRAMELATE 60

class DRenderer : public DSingleton<DRenderer>, public IDSubSystem
{
public:
    DRenderer();
    DRenderer(HDC newHdc, HWND newhWnd);

    static void RegisterSprite(DOSprite* sprite);
    void SetCameraOptions();
    static void MoveCamera(int type, double moveScale);
    void Draw();

    virtual void Tick(double deltaTime) override;

private:
    HDC hdc;
    HWND hWnd;
    RECT rt;
    RECT cameraRect = { 50,50,700,700 };
    const int displayInterval = 1000 / FRAMELATE;
    static DOCamera camera;
    static DList<DOSprite*> sprites;

    void AllReset();
    void DrawBySpriteType(DOSprite* sprite);
    void DrawRectangel(DOSprite* sprite);
    void DrawEllipse(DOSprite* sprite);
};
