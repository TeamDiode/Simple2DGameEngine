#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"
#include "DPhysicsManager.h"

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

// 총알 클래스
// - 플레이어와 마우스의 뱡향 계산 후 이동
// - 일정 시간 후 삭제
class Bullet : public DCollisionData
{
public:
	Bullet(DVector2i pos);
	~Bullet() { delete skin; }
private:
	DOSprite* skin;
	// 총알 속도
	float currentSpeed;
	// 나아가야할(마우스 위치) 방향을 저장하는 벡터
	DVector2i dir;

	// 총알을 삭제를 위한 시간 변수
	float curTime;
	float delTime;
public:
	virtual void OnCollision(DCollisionData* other) override;
	virtual void Update(double deltaTime) override;
};

// 플래이어 클래스
// - 이동 기능
// - 총알 생성
class Player : public DObject
{
public:
	Player()
	{
		skin = new DOSprite(1);
		skin->SetScale(60, 60);
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
		// 이동 입력
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
		DRenderer::SetCameraSimulationLocation(GetLocation());

		if (DInputManager::GetMouseButtonDown(0))
		{
			Bullet* a = new Bullet(GetLocation());
		}
	}
};

// 적 클래스
// - 이동기능
// 이후 충돌판정 후 삭제 기능
class Enemy : public DObject
{
public:
	Enemy(DObject* obj) : player(obj)
	{
		DOSprite* skin = new DOSprite(1);
		skin->SetScale(70, 70);
		AttachObject(skin);

		curHp = 2;

		cognizance = 300;

		moveSpeed = 100;
	}
	~Enemy()
	{
		delete skin;
	}
private:
	DOSprite* skin;
	// 플레이어 위치를 저장하는 변수
	DObject* player;
	// 적 HP
	int curHp;
	// 플레이어 인식 범위
	float cognizance;
	// 이동속도
	float moveSpeed;
public:
	virtual void Update(double deltaTime) override
	{
		if (player == nullptr) return;
		// 플레이어 오브젝트 거리와 자신과의 오브젝트 거리 계산
		// 인식범위 안이라면
		if (DVector2i::Distance(player->GetLocation(), GetLocation()) < cognizance)
		{
			// 플레이어와의 방향벡터 계산
			DVector2i dir = player->GetLocation() - GetLocation();
			dir.Normalize();

			// 플레이어 쪽으로 이동
			SetLocation(GetLocation() + (dir * deltaTime * moveSpeed));
		}
	}
	// 충돌 판정 후 hp
}; 

// 적 생성을 관리하는 클래스
// - 일정 시간마다 적 생성
class EnemyManager : public DObject
{
public:
	EnemyManager(DObject* obj) :gen(), distr(100, 600), playerObj(obj)
	{
		regenerateTime = 10;
		curTime = regenerateTime;
	}
private:
	// 플레이어를 저장하는 오브젝트
	DObject* playerObj;
	// 리젠을 위한 시간 변수
	float curTime; // 현재 시간
	float regenerateTime; // 리젠 시간
	// 랜덤을 위한 클래스
	random_device rd;
	mt19937 gen;
	uniform_int_distribution<int> distr;
public:
	virtual void Update(double deltaTime) override
	{
		// 현재 시간 계산
		curTime += deltaTime;

		// 만약 현재 시간이 리젠 시간과 같거나 크다면
		if (curTime >= regenerateTime)
		{
			// 적 생성
			CreataEnemy();
			// 현재 시간 초기화
			curTime = 0;
		}
	}
	// 적 생성 함수
	void CreataEnemy()
	{
		// 적 생성
		Enemy* e = new Enemy(playerObj);
		e->SetLocation(distr(gen), distr(gen));
	}


};
