#pragma once
#include "DObject.h"
#include "DSingleton.hpp"
#include <Windows.h>

class DOCamera : public DObject , DSingleton<DOCamera>
{
public:
	// 카메라 크기 정하기
	DOCamera();
	DOCamera();

	void RenderBasedCamera();
	void RetrieveGameWorld(DObject* newMap);
	//게임 맵 받아오기

private:
	HWND hWnd;
	HDC hdc;
	RECT mapRect;

	void LimitedCameraPositionInGameWorld();
	void AllReset();
};