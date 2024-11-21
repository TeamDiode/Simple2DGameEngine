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
	physicsManager.UpdateObjects(0.02f); // �ӽ� deltaTime
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
	// deltaTime, Clock
	clock_t s;
	double daltatime = 0;
	DSubSystem subSystemInstance = *((DAutoPointer<DSubSystem>*)subSystemClass)->GetValue();

	while (true)
	{
		s = clock();
		subSystemInstance.Tick(daltatime);
		daltatime = s - clock();
	}
	
}

void DEngine::CreateSybSystemThread(DAutoPointer<DSubSystem>& subSystemClass, int threadPriority)
{
	DWORD newThreadID;
	HANDLE newThreadHandle = CreateThread(NULL, 0, ManageSubSystemThread, (PVOID)&subSystemClass, 0, &newThreadID);
	SetThreadPriority(newThreadHandle, threadPriority);
}
