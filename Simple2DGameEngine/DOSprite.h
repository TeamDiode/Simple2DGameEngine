#pragma once
#include <Windows.h>
#include "math.h"
#include "DMathTypes.h"
#include "DObject.h"

class DOSprite : public DObject
{
public:
	DOSprite(int newType);

	DVector2i GetLeftTopPositionVector();
	DVector2i GetLeftBottomPositionVector();
	DVector2i GetRightTopPositionVector();
	DVector2i GetRightBottomPosiitonVector();
	
	int GetType();

private:
	int type;
	DVector2i position;
};