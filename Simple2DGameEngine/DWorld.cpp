#include "DWorld.h"

DWorld::DWorld()
{
}

DWorld::~DWorld()
{
}

void DWorld::Load()
{
	Player* a = new Player();
	a->SetLocation(500, 500);
	a->SetScale(100, 100);
	DObjectManager::RegisterObject(a);
}
