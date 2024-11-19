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

DEngine::DEngine(HDC deviceContextHandle, RECT displayRectangle)
{
	objectManager = DObjectManager();
	physicsManager = DPhysicsManager();
	renderer = DRenderer(deviceContextHandle, displayRectangle);
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
	physicsManager.UpdateObjects(0.02f); // юс╫ц deltaTime
}

void DEngine::ProcessGameLogic()
{
	objectManager.UpdateTick();
}

void DEngine::ProcessDisplay()
{
	renderer.Draw();
}
