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

    //그릴 이미지 받아오기
    static void RegisterSprite(DOSprite* sprite);
    static void CancelSprite(DOSprite* sprite);

    //카메라 옵션 설정
    void SetCameraOptions();
    //카메라 옵션 설정
    void SetCameraOptions(RECT newCameraRect);
    //시뮬레이션 세계에서 카메라 위치 설정
    static void SetCameraSimulationLocation(DVector2i newLocation);
    //시뮬레이션 세계의 카메라 이동
    static void MoveCamera(DVector2i position);
    
    //전체적인 모습 그리기
    void Draw();
    //동기화 함수
    virtual void Tick(double deltaTime) override;

private:
    //전체 윈도우 화면 DC정보를 저장할 변수
    HDC hdc;
    //전체 윈도우 화면 창에 대한 핸들 변수
    HWND hWnd;
    //전체 윈도우 화면에 대한 크기 변수
    RECT rect;
    //카메라 크기 변수
    RECT cameraRect = { 50,50,700,700 };
    //딜레이 변수
    const int displayInterval = 1000 / FRAMELATE;
    //카메라 변수
    static DOCamera camera;
    //화면에 그려질 이미지 변수 리스트
    static DList<DOSprite*> sprites;

    //화면 전체를 초기화 
    void AllReset();
    //오브젝트의 형태에 따라 이미지 그리기
    void DrawBySpriteType(DOSprite* sprite);
    //사각형 그리기
    void DrawRectangel(DOSprite* sprite);
    //원 그리기
    void DrawEllipse(DOSprite* sprite);
};
