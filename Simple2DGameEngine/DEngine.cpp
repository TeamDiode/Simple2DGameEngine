#include "DEngine.h"


DEngine* DEngine::engineInstance = nullptr;

DEngine::DEngine()
{
	objectManager = DObjectManager();
	physicsManager = DPhysicsManager();
	renderer = DRenderer();
	engineInstance = this;
	startWorld.Load();
}

DEngine::DEngine(HDC deviceContextHandle)
{
	objectManager = DObjectManager();
	physicsManager = DPhysicsManager();
	renderer = DRenderer(deviceContextHandle);
	engineInstance = this;
	startWorld.Load();
}

DEngine::~DEngine()
{
}

DEngine* DEngine::GetInstance()
{
	return engineInstance;
}

void DEngine::ProcessTick()
{
	ProcessObject();
	ProcessPhysics();
	ProcessGameLogic();
	ProcessDisplay();
	DInputManager::Init();
}

void DEngine::ProcessObject()
{
}

void DEngine::ProcessPhysics()
{
	physicsManager.UpdateObjects(0.02f); // 임시 deltaTime
}

void DEngine::ProcessGameLogic()
{
	objectManager.UpdateTick();
}

void DEngine::ProcessDisplay()
{
	renderer.Draw();
}

DWORD WINAPI DEngine::ManageSubSystemThread(PVOID subSystemClass)
{
	// 스레드 만들어지고 동작

	return 0;
}
void DEngine::CreateSybSystemThread(DAutoPointer<DSubSystem>& subSystemClass, int threadPriority)
{
	DWORD newThreadID;
	HANDLE newThreadHandle = CreateThread(NULL, 0, ManageSubSystemThread, (PVOID)&subSystemClass, 0, &newThreadID);
	SetThreadPriority(newThreadHandle, threadPriority);
}
