#pragma once
#include "DOSprite.h"
#include "DList.hpp"
#include "DSingleton.hpp"
#include <Windows.h>

class DRenderer
{
public:
	DRenderer();
	DRenderer(HDC newHdc, RECT newRect);

	void Initialize(HDC newHdc, RECT newRect);
	static void RegisterSprite(DOSprite* sprite);
	void Draw();
	
private:
	HDC hdc;
	RECT rect;
	static DList<DOSprite*> sprites;

	void Reset();

	void DrawBySpriteType(DOSprite* sprite);
	void DrawRectangel(DOSprite* sprite);
	void DrawEllipse(DOSprite* sprite);
};
