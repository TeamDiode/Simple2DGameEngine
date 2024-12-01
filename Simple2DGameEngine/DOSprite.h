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

	//그릴 이미지의 left, top정보를 리턴
	DVector2i GetLeftTopPosition();
	//그릴 이미지의 left, bottom정보를 리턴
	DVector2i GetLeftBottomPosition();
	//그릴 이미지의 right, top정보를 리턴
	DVector2i GetRightTopPosition();
	//그릴 이미지의 right, bottom정보를 리턴
	DVector2i GetRightBottomPosiiton();
	
	//그릴 이미지의 타입 리턴
	int GetType();

private:
	//그릴 이미지의 타입
	int type;
	//그링 이미지의 라디언값
	float angleInRadian;

private:
	//회전값 적용
	DVector2i GetRotatedPosition(float x, float y);
};