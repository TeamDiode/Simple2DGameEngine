#pragma once
#include "DORender.h"
#include "DObject.h"
#include "DMathTypes.h"
#include <Windows.h>

class DRenderer
{
public:
	DRenderer(HDC newHdc, RECT newRect);

	void Initialize(HDC newHdc, RECT newRect);
	void Draw(DORender* object);
private:
	HDC hdc;
	RECT rect;
	DVector2i vetor[4];

	void Reset();

	void DrawRectangel(DORender* object, float PI);
	void DrawEllipse(DORender* object, float PI);
};