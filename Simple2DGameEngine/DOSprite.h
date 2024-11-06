#pragma once
#include <Windows.h>
#include "math.h"
#include "DObject.h"

class DOSprite : public DObject
{
public:
	DOSprite();
	DOSprite(int newType);
	~DOSprite();

	//각도값 적용안됨, 위치와 크기값에 대한 처리만 적용됨
	int GetLeft();
	int GetRight();
	int GetTop();
	int GetBottom();
	int GetType();

private:
	int type;
};