#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"


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
		DObject* skin = DObjectManager::CreateObject(DOSprite(1));
		skin->SetScale(100, 100);
		AttachObject(skin);
	}

	~TestPlayer()
	{

	}

private:

public:
	virtual void Update() override;
	

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
