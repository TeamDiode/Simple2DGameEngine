#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"
#include "DPhysicsManager.h"
#include "DCollisionData.h"

#include <iostream>
#include <random>
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
// �� Ŭ����
// - ������Ʈ �̵�
// - ���� �ð� �� ��Ȱ��ȭ
class Wall : public DCollisionData
{
public:
	Wall();
	~Wall();
private:
	DOSprite* skin;
	// ������ ���� �ð��� ����� ����
	float curTime;
	float destoryTime;
	// �̿�� ������ Ȯ���ϴ� ����
	bool isUsed;
public:
	virtual void Update(double deltaTime) override;
	virtual void OnCollision(DCollisionData* other) override;
	// �̹� ���� ������ Ȯ��
	bool GetIsUsed() { return isUsed; }
	// �ٽ� ����ϱ� ���� �ʱ�ȭ
	void Reset() { isUsed = false; }
};
// ���� �����ϱ� ���� ������ƮǮ
// - ������ƮǮ ���� ����
class WallObjectPool
{
public:
	WallObjectPool() {}
private:
	// ������ ������ �ڷᱸ�� ť
	queue<Wall*> objQueue;
public:
	// ����� ���� ��ȯ�ϴ� �Լ�
	Wall* GetWall();
	// ���� ť�� �� �տ� ���� ��밡������ Ȯ���ϴ� �Լ�
	bool PossibleGetWall();
	// ť�� ũ��(== ���� ����)�� Ȯ���ϴ� �Լ�
	int GetSize() { return objQueue.size(); }
};

// ���� �����ϴ� Ŭ����
// - �� ���� �Ǵ� �� �ʱ�ȭ
class WallManager : public DObject
{
public:
	WallManager() :gen(), distr(-90, 90)
	{
		createWallTime = 2;
		// �� ó������ ������Ʈ�� �����ϱ� ���� �ʱ�ȭ
		curTime = createWallTime;
	}
private:
	// ���� ���� �Ǵ� �ʱ�ȭ�ϴµ� �ð� ����ϴ� ����
	float curTime;
	float createWallTime;
	// ������Ʈ Ǯ Ŭ����
	WallObjectPool wop;

	// ���� ������ ���� Ŭ����
	random_device rd;
	mt19937 gen;
	uniform_int_distribution<int> distr;
public:
	virtual void Update(double deltaTime) override;
};


class Player : public DCollisionData
{
public:
	Player();
	// �̹��� ������Ʈ ����
	~Player() { delete skin; }
private:
	DOSprite* skin;
public:
	virtual void Update(double deltaTime) override;
	virtual void OnCollision(DCollisionData* other) override;
};