#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"
#include "DGravity.h"
#include "DCollisionData.h"

class DWorld
{
public:
	DWorld();
	~DWorld();

public:
	virtual void Load();
};

class Bullet : public DObject
{
public:
	Bullet()
	{
		acceleration = 1000;
		currentSpeed = 0;
		DOSprite* skin = new DOSprite(2);
		skin->SetScale(50, 50);
		AttachObject(skin);
	}

private:
	DOSprite* skin;
	float acceleration;
	float currentSpeed;

public:
	virtual void Update(double deltaTime) override
	{
		currentSpeed += deltaTime * acceleration;
		SetLocation(GetLocation() + DVector2i(deltaTime * currentSpeed, 0));
	}
};

class Player :public DCollisionData, public DGravity
{
public:
	Player() : DCollisionData(Shape::Rectangle,1,1) ,DGravity()
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

		if (DInputManager::GetKeyDown(space))
		{
			DRenderer::MoveCamera(D, deltaTime * 100);
		}
		//ApplyGravity((class Player*)(this), deltaTime);
	}
};