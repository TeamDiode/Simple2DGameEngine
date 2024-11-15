#pragma once

#include "DMathTypes.h"
#include "DList.hpp"
#include "DObjectManager.h"


class DObject
{
public:
	DObject();
	~DObject();

private:
	// 월드 위치
	DVector2i location;
	// 상위 오브젝트에 상대적인 로컬 위치
	DVector2i localLocation;
	// 각도. 단위는 도(degree)
	float angle;
	// 크기. 정규값은 (1, 1)
	DVector2i scale;

	// 귀속된 상위 오브젝트
	DObject* upperObject;
	// 부착된 하위 오브젝트
	DList<DObject*> lowerObjectAttachments;
	
public:
	/* 오브젝트 상태 프로퍼티 */

	// 위치을 반환
	DVector2i GetLocation();
	// 월드 위치를 벡터로 수정
	void SetLocation(DVector2i newLocation);
	// 월드 위치를 원소로 수정
	void SetLocation(int newLocationX, int newLocationY);
	// 로컬 위치를 벡터로 수정
	void SetLocalLocation(DVector2i newLocalLocation);
	// 로컬 위치를 원소로 수정
	void SetLocalLocation(int newLocalLocationX, int newLocalLocationY);

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

	// 상위 오브젝트를 지정
	void SetUpperObject(DObject* newUpperObject);
	// 하위 오브젝트를 부착
	void AttachObject(DObject* lowerObjectToAttach);

	// 매 틱마다 호출되는 함수
	virtual void Update();

};

