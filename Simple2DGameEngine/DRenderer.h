#pragma once
#include "DORender.h"
#include "DObject.h"
#include <Windows.h>

class DRenderer
{
public:
	DRenderer(HDC newHdc, RECT newRect, DORender* newObject);

	void Initialize(HDC newHdc, RECT newRect, DORender* newObject);
	void Draw();
private:
	HDC hdc;
	RECT rect;
	DORender* object;

	void Reset();

	void DrawRectangel();
	void DrawEllipse();
};