#pragma once
#include "DObject.h"
#include "DOSprite.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect);

	void Rendering(DList<DOSprite*> objects);
	void Move(DVector2i position);

	DVector2i GetSimulationLocation();
	void SetSimulationLocation(DVector2i newLocation);

private:
	HWND hWnd;
	HDC hdc;
	RECT renderingRect;
	DList<DOSprite*> objectList;

	DVector2i simulationLocation;

	void DrawScreen();
	void DistanceCalculation(DOSprite* object);
};