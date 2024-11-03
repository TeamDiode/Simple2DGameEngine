#pragma once

#include "DMathTypes.h"


class DObject
{
public:
	DObject();
	~DObject();

private:
	// 위치
	DVector2i location;
	// 각도. 단위는 도(degree)
	float angle;
	// 크기. 정규값은 (1, 1)
	DVector2i scale;
	
public:
	/* 오브젝트 상태 프로퍼티 */

	// 위치을 반환
	DVector2i GetLocation();
	// 위치를 벡터로 수정
	void SetLocation(DVector2i newLocation);
	// 위치를 원소로 수정
	void SetLocation(int newLocationX, int newLocationY);

	// 각도를 반환
	float GetAngle();
	// 각도를 도로 수정
	void SetAngle(float degree);
	// 각도를 라디언으로 수정
	void SetAngleByRadian(float radian);

	// 크기를 반환
	DVector2i GetScale();
	// 크기를 벡터로 수정
	void SetScale(DVector2i newScale);
	// 크기를 원소로 수정
	void SetScale(int newScaleX, int newScaleY);
};

