#pragma once

// TODO : ������ �������� �߰�

struct DVector2i
{
public:
	DVector2i();
	DVector2i(int x, int y);

public:
	// x ����
	int x;
	// y ����
	int y;

public:
	// ���� ����
	DVector2i operator +(DVector2i value);
	// ���� ����
	DVector2i operator -(DVector2i value);
	// ��Į�� ��
	DVector2i operator *(int value);
	
};
