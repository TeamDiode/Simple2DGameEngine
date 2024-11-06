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

	//������ ����ȵ�, ��ġ�� ũ�Ⱚ�� ���� ó���� �����
	int GetLeft();
	int GetRight();
	int GetTop();
	int GetBottom();
	int GetType();

private:
	int type;
};