#pragma once
#include "DOSprite.h"
#include "DList.hpp"
#include "DSingleton.hpp"
#include <Windows.h>

class DRenderer : public DSingleton<DRenderer>
{
public:
	DRenderer(HDC newHdc, RECT newRect);

	void Initialize(HDC newHdc, RECT newRect);
	void RegisterSprite(DOSprite* sprite);
	void Draw();
	
private:
	HDC hdc;
	RECT rect;
	DList<DOSprite*> sprites;

	void Reset();

	void DrawBySpriteType(DOSprite* sptrite);
	void DrawRectangel(DOSprite* sptrite);
	void DrawEllipse(DOSprite* sptrite);
};