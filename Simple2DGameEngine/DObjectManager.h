#pragma once

#include "DObject.h"
#include "DArray.hpp"
#include "DList.hpp"

class DObjectManager
{
public:
	DObjectManager();
	~DObjectManager();

private:
	DList<DObject*> objectInstances;

public:
	DObject* CreateObject(DObject newObjectBlueprint);
	bool DestroyObject(DObject* objectToDestroy);

};
