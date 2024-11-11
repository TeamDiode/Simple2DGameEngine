#pragma once
#include "DObject.h"
#include "DSingleton.hpp"
#include <Windows.h>

class DOCamera : public DObject , DSingleton<DOCamera>
{
public:
	DOCamera(HWND newHWnd);
	DOCamera();

	void PrintScreen();

private:
	HWND hWnd;
	RECT rect;

	void InitRect();
};