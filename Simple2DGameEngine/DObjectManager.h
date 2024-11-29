#pragma once

#include "DObject.h"
#include "DList.hpp"
#include "DSubSystem.h"

class DObjectManager : public IDSubSystem
{
public:
	DObjectManager();
	~DObjectManager();

private:
	static DList<DObject*> objectInstances;

public:
	static DObject* CreateObject(DObject newObjectBlueprint);
	static bool DestroyObject(DObject* objectToDestroy);

	static bool RegisterObject(DObject* newObject);
	static bool CancelObject(DObject* oldObject);

	void UpdateTick();

	virtual void Tick(double deltaTime) override;

};
