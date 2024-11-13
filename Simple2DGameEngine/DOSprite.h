#pragma once
#include <Windows.h>
#include "math.h"
#include "DMathTypes.h"
#include "DObject.h"

class DOSprite : public DObject
{
public:
	DOSprite();
	DOSprite(int newType);

	DVector2i GetLeftTopPosition();
	DVector2i GetLeftBottomPosition();
	DVector2i GetRightTopPosition();
	DVector2i GetRightBottomPosiiton();
	
	int GetType();

private:
	int type;
	float angleInRadian;
	DVector2i position;

private:
	DVector2i GetRotatedPosition(float x, float y);
};