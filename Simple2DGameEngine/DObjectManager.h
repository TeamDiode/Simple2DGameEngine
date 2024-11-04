#pragma once

#include "DObject.h"
#include "DArray.hpp"

class DObjectManager
{
public:
	DObjectManager();
	~DObjectManager();

private:
	DArray<DObject*> objectInstances;

public:
	DObject* CreateObject(DObject newObjectBlueprint);
	bool DestroyObject(DObject* objectToDestroy);

};
