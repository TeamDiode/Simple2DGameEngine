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

    //�׸� �̹��� �޾ƿ���
    static void RegisterSprite(DOSprite* sprite);
    static void CancelSprite(DOSprite* sprite);

    //ī�޶� �ɼ� ����
    void SetCameraOptions();
    //ī�޶� �ɼ� ����
    void SetCameraOptions(RECT newCameraRect);
    //�ùķ��̼� ���迡�� ī�޶� ��ġ ����
    static void SetCameraSimulationLocation(DVector2i newLocation);
    //�ùķ��̼� ������ ī�޶� �̵�
    static void MoveCamera(DVector2i position);
    
    //��ü���� ��� �׸���
    void Draw();
    //����ȭ �Լ�
    virtual void Tick(double deltaTime) override;

private:
    //��ü ������ ȭ�� DC������ ������ ����
    HDC hdc;
    //��ü ������ ȭ�� â�� ���� �ڵ� ����
    HWND hWnd;
    //��ü ������ ȭ�鿡 ���� ũ�� ����
    RECT rect;
    //ī�޶� ũ�� ����
    RECT cameraRect = { 50,50,700,700 };
    //������ ����
    const int displayInterval = 1000 / FRAMELATE;
    //ī�޶� ����
    static DOCamera camera;
    //ȭ�鿡 �׷��� �̹��� ���� ����Ʈ
    static DList<DOSprite*> sprites;

    //ȭ�� ��ü�� �ʱ�ȭ 
    void AllReset();
    //������Ʈ�� ���¿� ���� �̹��� �׸���
    void DrawBySpriteType(DOSprite* sprite);
    //�簢�� �׸���
    void DrawRectangel(DOSprite* sprite);
    //�� �׸���
    void DrawEllipse(DOSprite* sprite);
};
