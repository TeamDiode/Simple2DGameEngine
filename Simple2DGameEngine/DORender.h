#pragma once
#include <Windows.h>
#include "DObject.h"
#include "DRenderer.h"

class DORender : public DObject
{
public:
	DORender(int newType);
	~DORender();

	int GetObjectType();
	int GetLeft();
	int GetRight();
	int GetTop();
	int GetBottom();

	void DrawSelf(HDC hdc, RECT rect, DRenderer* renderer);

private:
	int type;
};