#include "DObjectManager.h"
#include "DList.hpp"
#include "DEngine.h"
#include "DInput.h"


DList<DObject*> DObjectManager::objectInstances = DList<DObject*>();

DObjectManager::DObjectManager()
{
	//objectInstances = DList<DObject*>(new DObject(), 5);
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

bool DObjectManager::RegisterObject(DObject* newObject)
{
	objectInstances.AddNext(newObject);

	return true;
}

bool DObjectManager::CancelObject(DObject* oldObject)
{
	bool isSuccess = false;
	int remainLoopAmount = objectInstances.GetSize();

	while (remainLoopAmount-- && objectInstances.Move() && !isSuccess)
	{
		if (objectInstances.GetValue() == oldObject)
		{
			objectInstances.RemoveHere();
			isSuccess = true;
		}
	}

	return isSuccess;
}

void DObjectManager::UpdateTick()
{
	
}


void DObjectManager::Tick(double deltaTime)
{
	int objectAmount = objectInstances.GetSize();
	
	for (int i = 0; i < objectAmount; i++)
	{
		objectInstances.GetValue()->Update(deltaTime);
		objectInstances.Move();
	}
	DInputManager::Init();
}
