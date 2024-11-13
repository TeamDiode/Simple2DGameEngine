#pragma once
#include "DObject.h"
#include "DSingleton.hpp"
#include <Windows.h>

class DOCamera : public DObject , DSingleton<DOCamera>
{
public:
	DOCamera(HWND newHWnd);
	DOCamera();

	//게임 세상의 크기를 받아오는 함수
	//게임 세상 속 카메라 위치를 정해놓는 함수
	//게임 세상 속 카메라 위치마다 다르게 그리는 함수

	void PrintScreen();

private:
	HWND hWnd;
	RECT rect;

	void InitRect();
};