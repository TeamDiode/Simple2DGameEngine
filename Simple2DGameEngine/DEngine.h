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
	template<class SubSystemClass>
	static DWORD WINAPI ProcessSubSystemThread(LPVOID subSystemClass)
	{
		clock_t currentTime = clock();
		double daltatime = 0;
		IDSubSystem* subSystemInstance = dynamic_cast<IDSubSystem*>((SubSystemClass*)subSystemClass);

		if (subSystemClass == nullptr)
		{
			DEngine::LogMessageBox("스레드 생성 실패");
			return 0;
		}

		while (true)
		{
			daltatime = (clock() - currentTime) / (double)CLOCKS_PER_SEC;
			currentTime = clock();
			subSystemInstance->Tick(daltatime);
		}

		return 0;
	}

	template<class SubSystemClass>
	void CreateSubSystemThread(IDSubSystem* subSystemClass, int threadPriority)
	{
		DWORD newThreadID;
		HANDLE newThreadHandle = CreateThread(NULL, 0, ProcessSubSystemThread<SubSystemClass>, subSystemClass, 0, &newThreadID);
		if (newThreadHandle != NULL) SetThreadPriority(newThreadHandle, threadPriority);

	}
};
