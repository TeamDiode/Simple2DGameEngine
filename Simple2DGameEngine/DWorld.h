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
// 벽 클래스
// - 오브젝트 이동
// - 일정 시간 후 비활성화
class Wall : public DCollisionData
{
public:
	Wall();
	~Wall();
private:
	DOSprite* skin;
	// 삭제를 위한 시간을 계산할 변수
	float curTime;
	float destoryTime;
	// 이용된 벽인지 확인하는 변수
	bool isUsed;
public:
	virtual void Update(double deltaTime) override;
	virtual void OnCollision(DCollisionData* other) override;
	// 이미 사용된 벽인지 확인
	bool GetIsUsed() { return isUsed; }
	// 다시 사용하기 위해 초기화
	void Reset() { isUsed = false; }
};
// 벽을 재사용하기 위한 오브젝트풀
// - 오브젝트풀 패턴 구현
class WallObjectPool
{
public:
	WallObjectPool() {}
private:
	// 벽들을 저장할 자료구조 큐
	queue<Wall*> objQueue;
public:
	// 사용할 벽을 반환하는 함수
	Wall* GetWall();
	// 현재 큐의 맨 앞에 벽이 사용가능한지 확인하는 함수
	bool PossibleGetWall();
	// 큐의 크기(== 벽의 갯수)를 확인하는 함수
	int GetSize() { return objQueue.size(); }
};

// 벽을 관리하는 클래스
// - 벽 생성 또는 벽 초기화
class WallManager : public DObject
{
public:
	WallManager() :gen(), distr(-90, 90)
	{
		createWallTime = 2;
		// 맨 처음부터 오브젝트를 생성하기 위해 초기화
		curTime = createWallTime;
	}
private:
	// 벽을 재사용 또는 초기화하는데 시간 계산하는 변수
	float curTime;
	float createWallTime;
	// 오브젝트 풀 클래스
	WallObjectPool wop;

	// 랜덤 구현을 위한 클래스
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
	// 이미지 오브젝트 해제
	~Player() { delete skin; }
private:
	DOSprite* skin;
public:
	virtual void Update(double deltaTime) override;
	virtual void OnCollision(DCollisionData* other) override;
};