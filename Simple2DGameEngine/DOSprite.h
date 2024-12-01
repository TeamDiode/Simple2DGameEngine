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

	//�׸� �̹����� left, top������ ����
	DVector2i GetLeftTopPosition();
	//�׸� �̹����� left, bottom������ ����
	DVector2i GetLeftBottomPosition();
	//�׸� �̹����� right, top������ ����
	DVector2i GetRightTopPosition();
	//�׸� �̹����� right, bottom������ ����
	DVector2i GetRightBottomPosiiton();
	
	//�׸� �̹����� Ÿ�� ����
	int GetType();

private:
	//�׸� �̹����� Ÿ��
	int type;
	//�׸� �̹����� ����
	float angleInRadian;

private:
	//ȸ���� ����
	DVector2i GetRotatedPosition(float x, float y);
};