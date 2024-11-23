#pragma once
#include "DObject.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT newScreenRect, RECT newCameraRect);

	void Rendering();
	void Move(int type, int moveScale);

private:
	HWND hWnd;
	HDC hdc;
	RECT screenRect;
	RECT cameraRect;

	void DrawCamera();
	void AllReset();
	void LimitedMove();
};