#pragma once

#include "DObject.h"

class DObjectManager
{
public:
	DObjectManager();
	~DObjectManager();

private:
	
public:
	static DObject* CreateObject();
	static bool DestroyObject(DObject* objectToDestroy);

};
