#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"
#include "DPhysicsManager.h"
#include "DCollisionData.h"

class DWorld
{
public:
	DWorld();
	~DWorld();

public:
	virtual void Load();
};

class Player :public DObject
{
public:
	Player() /*: DCollisionData(Shape::Rectangle,1,1)*/
	{ 
		DOSprite* skin = new DOSprite(1);
		skin->SetScale(100, 100);
		DObject::AttachObject(skin);
		
	}
	~Player()
	{
		delete skin;
	}
private:
	DOSprite* skin;
public:
	virtual void Update(double deltaTime) override
	{
		if (DInputManager::GetKey(W))
		{
			SetLocation(GetLocation() + DVector2i(0, deltaTime * -200));
		}
		else
		{
			SetLocation(GetLocation() + DVector2i(0, deltaTime * 200));
		}
		
	}
};