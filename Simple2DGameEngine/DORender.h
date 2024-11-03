#pragma once
#include <Windows.h>
#include "DObject.h"

class DORender : public DObject
{
public:
	DORender(int newType);
	~DORender();

	int GetObjectType();
	int GetLeft();
	int GetRight();
	int GetTop();
	int GetBottom();

private:
	int type;
};