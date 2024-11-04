#include "DObjectManager.h"

DObjectManager::DObjectManager()
{
}

DObjectManager::~DObjectManager()
{
}

DObject* DObjectManager::CreateObject(DObject newObjectBlueprint)
{
	DObject* newObject = new DObject(newObjectBlueprint);
	objectInstances.Add(newObject);

	return newObject;
}

bool DObjectManager::DestroyObject(DObject* objectToDestroy)
{
	return false;
}
