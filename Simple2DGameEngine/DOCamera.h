#pragma once
#include "DObject.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect);

	void Rendering();
	void Move(int type, int moveScale);

private:
	HWND hWnd;
	HDC hdc;

	void DrawCamera();
};