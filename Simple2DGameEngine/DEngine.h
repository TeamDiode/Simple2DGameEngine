#pragma once

#include <Windows.h>
#include <ctime>
#include "DObjectManager.h"
#include "DRenderer.h"
#include "DSingleton.hpp"
#include "DInput.h"
#include "DWorld.h"
#include "DPhysicsManager.h"
#include "DSubSystem.h"
#include "DAutoPointer.hpp"

class DEngine
{
public:
	DEngine();
	DEngine(HWND windowHandle);
	~DEngine();

	
private:
	static DEngine* engineInstance;
	
	static HWND currentWindowHandle;

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

	static void LogMessageBox(LPCSTR log);

private:
	void CreateSybSystemThread(DAutoPointer<DSubSystem> subSystemClass, int threadPriority);
	static DWORD WINAPI ManageSubSystemThread(PVOID subSystemClass);
	
};
