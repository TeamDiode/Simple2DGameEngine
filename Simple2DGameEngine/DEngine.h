#pragma once

#include <Windows.h>
#include "DObjectManager.h"
#include "DRenderer.h"
#include "DSingleton.hpp"
#include "DInput.h"
#include "DWorld.h"
#include "DPhysicsManager.h"

class DEngine
{
public:
	DEngine();
	DEngine(HDC deviceContextHandle);
	~DEngine();

	
private:
	static DEngine* engineInstance;

	DObjectManager objectManager;
	DPhysicsManager physicsManager;
	// ���� �ý���
	DRenderer renderer;

	DWorld startWorld;

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
