#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"

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
		acceleration = 1;
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
	virtual void Update() override
	{
		currentSpeed += acceleration;
		SetLocation(GetLocation() + DVector2i(currentSpeed, 0));
	}
};

class Player : public DObject
{
public:
	Player()
	{
		DOSprite* skin = new DOSprite(1);
		skin->SetScale(100, 100);
		AttachObject(skin);
	}
	~Player()
	{
		delete skin;
	}
private:
	DOSprite* skin;
public:
	virtual void Update() override
	{
		if (DInputManager::GetKeyDown(W))
		{
			SetLocation(GetLocation() + DVector2i(0, -50));
		}
		if (DInputManager::GetKeyDown(S))
		{
			SetLocation(GetLocation() + DVector2i(0, 50));
		}
		if (DInputManager::GetKeyDown(D))
		{
			SetLocation(GetLocation() + DVector2i(50, 0));
		}
		if (DInputManager::GetKeyDown(A))
		{
			SetLocation(GetLocation() + DVector2i(-50, 0));
		}
		if (DInputManager::GetKeyDown(K))
		{
			Bullet* a = new Bullet();
			a->SetLocation(GetLocation());
		}
	}
};