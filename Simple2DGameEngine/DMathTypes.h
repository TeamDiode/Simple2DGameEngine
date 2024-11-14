#pragma once

// TODO : ������ �������� �߰�

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
	
	// ���� ����ȭ
	void Normalize();

	// ���� ����
	float Dot(DVector2i value);
	// ���� ����
	float Cross(DVector2i value);
};