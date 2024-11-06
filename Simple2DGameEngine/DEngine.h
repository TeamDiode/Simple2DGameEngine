#pragma once

#include <Windows.h>
#include "DObjectManager.h"
#include "DRenderer.h"
#include "DSingleton.hpp"

class DEngine
{
public:
	DEngine();
	DEngine(HDC deviceContextHandle, RECT displayRectangle);
	~DEngine();

	
private:
	static DEngine* engineInstance;

	DObjectManager objectManager;
	// ���� ó��
	// ���� �ý���
	DRenderer renderer;

public:
	static DEngine* GetInstance();

	// ƽ���� ó���ϴ� ���� ���μ���
	void ProcessTick();

	// ������Ʈ ó��
	void ProcessObject();
	// ���� ó��
	void ProcessPhysics();
	// ���� ���� ó��
	void ProcessGameLogic();
	// ��� ó��
	void ProcessDisplay();

};
