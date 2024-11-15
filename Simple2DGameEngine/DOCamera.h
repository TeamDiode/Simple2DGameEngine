#pragma once
#include "DObject.h"
#include "DSingleton.hpp"
#include <Windows.h>

class DOCamera : public DObject , DSingleton<DOCamera>
{
public:
	// ī�޶� ũ�� ���ϱ�
	DOCamera();
	DOCamera();

	void RenderBasedCamera();
	void RetrieveGameWorld(DObject* newMap);
	//���� �� �޾ƿ���

private:
	HWND hWnd;
	HDC hdc;
	RECT mapRect;

	void LimitedCameraPositionInGameWorld();
	void AllReset();
};