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
	virtual void Update(double deltaTime) override
	{
		
		if (DInputManager::GetKey(W))
		{
			SetLocation(GetLocation() + DVector2i(0, deltaTime * -200));
		}
		if (DInputManager::GetKey(S))
		{
			SetLocation(GetLocation() + DVector2i(0, deltaTime * 200));
		}
		if (DInputManager::GetKey(D))
		{
			SetLocation(GetLocation() + DVector2i(deltaTime * 200, 0));
		}
		if (DInputManager::GetKey(A))
		{
			SetLocation(GetLocation() + DVector2i(deltaTime * -200, 0));
		}
		if (DInputManager::GetKey(K))
		{
			Bullet* a = new Bullet();
			a->SetLocation(GetLocation());
		}

		if (DInputManager::GetKeyDown(Q))
		{
			DVector2i pos(100, 0);
			DRenderer::MoveCamera(pos);//deltaTime * 100);
		}

		if (DInputManager::GetKeyDown(E))
		{
			DVector2i pos(-100, 0);
			DRenderer::MoveCamera(pos);//deltaTime * 100);
		}
		if (DInputManager::GetKeyDown(T))
		{
			DRenderer::SetCameraSimulationLocation(GetLocation());
		}
		if (DInputManager::GetKeyDown(R))
		{
			DRenderer::SetCameraSimulationLocation(GetLocation() + DVector2i(100, 100));
		}
	}
};