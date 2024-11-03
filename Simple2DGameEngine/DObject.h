#pragma once

#include "DMathTypes.h"


class DObject
{
public:
	DObject();
	~DObject();

private:
	// ��ġ
	DVector2i location;
	// ����. ������ ��(degree)
	float angle;
	// ũ��. ���԰��� (1, 1)
	DVector2i scale;
	
public:
	/* ������Ʈ ���� ������Ƽ */

	// ��ġ�� ��ȯ
	DVector2i GetLocation();
	// ��ġ�� ���ͷ� ����
	void SetLocation(DVector2i newLocation);
	// ��ġ�� ���ҷ� ����
	void SetLocation(int newLocationX, int newLocationY);

	// ������ ��ȯ
	float GetAngle();
	// ������ ���� ����
	void SetAngle(float degree);
	// ������ �������� ����
	void SetAngleByRadian(float radian);

	// ũ�⸦ ��ȯ
	DVector2i GetScale();
	// ũ�⸦ ���ͷ� ����
	void SetScale(DVector2i newScale);
	// ũ�⸦ ���ҷ� ����
	void SetScale(int newScaleX, int newScaleY);
};

