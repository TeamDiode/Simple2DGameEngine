#include "DEngine.h"


DEngine* DEngine::engineInstance = nullptr;
HWND DEngine::currentWindowHandle = NULL;

DEngine::DEngine()
{
	//objectManager = DObjectManager();
	physicsManager = DPhysicsManager();
	//renderer = DRenderer();
	engineInstance = this;
	startWorld.Load();
}

DEngine::DEngine(HWND windowHandle)
{
	currentWindowHandle = windowHandle;
	CreateSubSystemThread<DObjectManager>(new DObjectManager(), THREAD_PRIORITY_LOWEST);
	physicsManager = DPhysicsManager();
	CreateSubSystemThread<DRenderer>(new DRenderer(GetDC(windowHandle), windowHandle), THREAD_PRIORITY_LOWEST);
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
}

void DEngine::ProcessDisplay()
{
	//renderer.Draw();
}

void DEngine::LogMessageBox(LPCSTR log)
{
	if(currentWindowHandle) MessageBoxA(currentWindowHandle, log, NULL, MB_OK);
}
