#pragma once
#include "DObject.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect);

	void Rendering();

	void SetSimulationLocation(DVector2i newLocation);
	DVector2i GetSimulationLocation();

	void Move(DVector2i position);

private:
	HWND hWnd;
	HDC hdc;
	RECT renderingRect;
	DVector2i simulationLocation;

	void DrawScreen();
};