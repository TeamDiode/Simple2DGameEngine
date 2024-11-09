#include "DObjectManager.h"
#include "DList.hpp"


DList<DObject*> DObjectManager::objectInstances = DList<DObject*>();

DObjectManager::DObjectManager()
{
	objectInstances = DList<DObject*>(new DObject(), 5);
}

DObjectManager::~DObjectManager()
{
}

DObject* DObjectManager::CreateObject(DObject newObjectBlueprint)
{
	DObject* newObject = new DObject(newObjectBlueprint);
	objectInstances.AddNext(newObject);

	return newObject;
}

bool DObjectManager::DestroyObject(DObject* objectToDestroy)
{
	bool isSuccess = false;
	int remainLoopAmount = objectInstances.GetSize();

	while (remainLoopAmount-- && objectInstances.Move())
	{
		if (objectInstances.GetValue() == objectToDestroy)
		{
			objectInstances.RemoveHere();
			isSuccess = true;

			break;
		}
	}

	return isSuccess;
}
