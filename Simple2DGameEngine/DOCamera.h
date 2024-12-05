#pragma once
#include "DObject.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	//카메라 초기화
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect);

	//카메라 영역에 시뮬레이션 영역 렌더링
	void Rendering();

	//시뮬레이션 카메라 위치 초기화 
	void SetSimulationLocation(DVector2i newLocation);
	//시뮬레이션 카메라 위치 반환
	DVector2i GetSimulationLocation();

	//시뮬레이션 카메라 위치 이동
	void Move(DVector2i position);

private:
	//카메라 창에 대한 핸들 변수
	HWND hWnd;
	//카메라 창에 대한 DC정보를 저장할 변수
	HDC hdc;
	//실제 렌더링 될 영역
	RECT renderingRect;
	//시뮬레이션에서의 카메라 영역
	DVector2i simulationLocation;

	//렌더링 영역 그리기
	void DrawScreen();
};