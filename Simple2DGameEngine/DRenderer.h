#pragma once
#include "DOSprite.h"
#include "DList.hpp"
#include "DSingleton.hpp"
#include <Windows.h>

class DRenderer
{
public:
	DRenderer();
	DRenderer(HDC newHdc);

	static void RegisterSprite(DOSprite* sprite);
	void Draw();
	
private:
	HDC hdc;
	static DList<DOSprite*> sprites;

	void DrawBySpriteType(DOSprite* sprite);
	void DrawRectangel(DOSprite* sprite);
	void DrawEllipse(DOSprite* sprite);
};
