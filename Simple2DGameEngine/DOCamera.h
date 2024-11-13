#pragma once
#include "DObject.h"
#include "DSingleton.hpp"
#include <Windows.h>

class DOCamera : public DObject , DSingleton<DOCamera>
{
public:
	DOCamera(HWND newHWnd);
	DOCamera();

	//���� ������ ũ�⸦ �޾ƿ��� �Լ�
	//���� ���� �� ī�޶� ��ġ�� ���س��� �Լ�
	//���� ���� �� ī�޶� ��ġ���� �ٸ��� �׸��� �Լ�

	void PrintScreen();

private:
	HWND hWnd;
	RECT rect;

	void InitRect();
};