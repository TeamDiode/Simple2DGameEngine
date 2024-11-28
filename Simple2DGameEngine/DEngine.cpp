#include "DEngine.h"


DEngine* DEngine::engineInstance = nullptr;
HWND DEngine::currentWindowHandle = NULL;

DEngine::DEngine()
{
	objectManager = DObjectManager();
	physicsManager = DPhysicsManager();
	renderer = DRenderer();
	engineInstance = this;
	startWorld.Load();
}

DEngine::DEngine(HWND windowHandle)
{
	currentWindowHandle = windowHandle;
	objectManager = DObjectManager();
	physicsManager = DPhysicsManager();
	renderer = DRenderer(GetDC(windowHandle), windowHandle);
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

void DEngine::LogMessageBox(LPCSTR log)
{
	if(currentWindowHandle) MessageBoxA(currentWindowHandle, log, NULL, MB_OK);
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

void DEngine::CreateSybSystemThread(DAutoPointer<DSubSystem> subSystemClass, int threadPriority)
{
	DWORD newThreadID;
	HANDLE newThreadHandle = CreateThread(NULL, 0, ManageSubSystemThread, (PVOID)&subSystemClass, 0, &newThreadID);
	if(newThreadHandle != NULL) SetThreadPriority(newThreadHandle, threadPriority);
}
