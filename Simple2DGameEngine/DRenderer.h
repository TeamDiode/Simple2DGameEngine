#pragma once
#include "DORender.h"
#include "DObject.h"
#include <Windows.h>

class DRenderer
{
public:
	void Draw(HDC hdc, RECT rect, DORender* object);
private:
	void Reset(HDC hdc, RECT rect);

	void DrawRectangel(HDC hdc, RECT rect, DORender* object);
	void DrawEllipse(HDC hdc, RECT rect, DORender* object);
};