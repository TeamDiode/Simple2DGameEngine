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
	Bullet(DVector2i pos);

private:
	DOSprite* skin;
	float acceleration;
	float currentSpeed;
	DVector2i dir;
public:
	virtual void Update(double deltaTime) override
	{
		//currentSpeed += deltaTime * acceleration;

		SetLocation(GetLocation() + (dir * deltaTime * currentSpeed));
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
		f = false;
	}
	~Player()
	{
		delete skin;
	}
private:
	DOSprite* skin;
	bool f;
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
		/*if (DInputManager::GetMouseButton(0))*/
		if (DInputManager::GetMouseButton(0))
		{
			if(!f)
			Bullet* a = new Bullet(GetLocation());
			f = true;
			//SetLocation(DInputManager::GetMousePostion());
		}
		if (DInputManager::GetMouseButton(1))
		{
			f = false;
		}
	}
};

class Enemy : public DObject
{

};