#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"
#include "DPhysicsManager.h"
#include "DCollisionData.h"

#include <iostream>
#include <queue>
using namespace std;

class DWorld
{
public:
	DWorld();
	~DWorld();

public:
	virtual void Load();
};

class Wall : public DCollisionData
{
public:
	Wall();
	~Wall();
private:
	DOSprite* skin;
	float curTime;
	float destoryTime;
	bool isUsed;
public:
	virtual void Update(double deltaTime) override;
	bool GetIsUsed() { return isUsed; }
	void Reset() { isUsed = false; }
};
class WallObjectPool
{
public:
	WallObjectPool() {}
private:
	queue<Wall*> objQueue;
public:
	Wall* GetWall();
	bool PossibleGetWall();
	int GetSize() { return objQueue.size(); }
};
#include <random>
class WallManager : public DObject
{
public:
	WallManager() :gen(), distr(-90, 90)
	{
		createWallTime = 2;
		curTime = createWallTime;
	}
private:
	float curTime;
	float createWallTime;
	WallObjectPool wop;

	random_device rd;
	mt19937 gen;
	uniform_int_distribution<int> distr;
public:
	virtual void Update(double deltaTime) override;
};


class Player :public DObject
{
public:
	Player() /*: DCollisionData(Shape::Rectangle,1,1)*/;
	~Player()
	{
		delete skin;
	}
private:
	DOSprite* skin;
public:
	virtual void Update(double deltaTime) override;
};