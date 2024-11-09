#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"


class SimpleMapTool
{
public:
	SimpleMapTool();

private:
	

public:
	void Activated();
};

class TestPlayer : public DObject
{
public:
	TestPlayer()
	{
		DOSprite* skin = new DOSprite(1);
		skin->SetScale(100, 100);
		AttachObject(skin);
	}

private:
	

};


class Bullet : public DObject
{
public:
	Bullet()
	{

	}

public:
	void Activate()
	{

	}
};