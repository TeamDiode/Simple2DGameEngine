#pragma once
#include "DObject.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect);

	void Rendering();
	void Move(DVector2i currentLocation);
	void Move(float x, float y);

private:
	HWND hWnd;
	HDC hdc;
	RECT rt;

	void DrawCamera();
};