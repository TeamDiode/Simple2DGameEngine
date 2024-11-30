#pragma once
#include <iostream>
#include <cmath>

struct DVector2i
{
public:
	DVector2i();
	DVector2i(float x, float y);

public:
	// x ����
	float x;
	// y ����
	float y;

public:
	// ���� ����
	DVector2i operator +(DVector2i value);
	// ���� ����
	DVector2i operator -(DVector2i value);
	// ��Į�� ��
	DVector2i operator *(float value);
	/// <summary>
	/// �� ���Ͱ� �Ÿ��� ���մϴ�.
	/// </summary>
	static float Distance(DVector2i value1, DVector2i value2);
	
	// ���� ����ȭ
	void Normalize();

	// ���� ����
	float Dot(DVector2i value);
	// ���� ����
	DVector2i Cross(DVector2i value);
};