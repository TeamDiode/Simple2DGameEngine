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
	// ���� ��ġ
	DVector2i location;
	// ���� ������Ʈ�� ������� ���� ��ġ
	DVector2i localLocation;
	// ����. ������ ��(degree)
	float angle;
	// ũ��. ���԰��� (1, 1)
	DVector2i scale;

	// �ͼӵ� ���� ������Ʈ
	DObject* upperObject;
	// ������ ���� ������Ʈ
	DList<DObject*> lowerObjectAttachments;
	
public:
	/* ������Ʈ ���� ������Ƽ */

	// ��ġ�� ��ȯ
	DVector2i GetLocation();
	// ���� ��ġ�� ���ͷ� ����
	void SetLocation(DVector2i newLocation);
	// ���� ��ġ�� ���ҷ� ����
	void SetLocation(int newLocationX, int newLocationY);
	// ���� ��ġ�� ���ͷ� ����
	void SetLocalLocation(DVector2i newLocalLocation);
	// ���� ��ġ�� ���ҷ� ����
	void SetLocalLocation(int newLocalLocationX, int newLocalLocationY);

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

	// ���� ������Ʈ�� ����
	void SetUpperObject(DObject* newUpperObject);
	// ���� ������Ʈ�� ����
	void AttachObject(DObject* lowerObjectToAttach);

	// �� ƽ���� ȣ��Ǵ� �Լ�
	virtual void Update();

};

