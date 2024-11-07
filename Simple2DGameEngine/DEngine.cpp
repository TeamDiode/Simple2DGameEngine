#include "DEngine.h"
#include "SimpleMapTool.h"

DEngine* DEngine::engineInstance = nullptr;

DEngine::DEngine()
{
	objectManager = DObjectManager();
	renderer = DRenderer();
	engineInstance = this;
}

DEngine::DEngine(HDC deviceContextHandle, RECT displayRectangle)
{
	objectManager = DObjectManager();
	renderer = DRenderer(deviceContextHandle, displayRectangle);
	engineInstance = this;
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
}

void DEngine::ProcessGameLogic()
{
	objectManager.UpdateTick();
}

void DEngine::ProcessDisplay()
{
	renderer.Draw();
}
