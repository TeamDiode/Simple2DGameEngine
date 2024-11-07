#pragma once

#include "DObject.h"
#include "DList.hpp"

class DObjectManager
{
public:
	DObjectManager();
	~DObjectManager();

private:
	static DList<DObject*> objectInstances;

public:
	static DObject* CreateObject(DObject newObjectBlueprint);
	static bool DestroyObject(DObject* objectToDestroy);

};
