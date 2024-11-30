#pragma once
#include "DObject.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect);

	void Rendering();
	void Move(int type, double moveScale);
	void Move(DVector2i position);
	void Move(DObject* object);

private:
	HWND hWnd;
	HDC hdc;
	RECT rt;
	RECT renderingRect;

	void DrawScreen();
	void CopyToRenderingRect();
};