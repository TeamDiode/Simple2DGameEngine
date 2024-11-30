#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"

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


class Bullet : public DObject
{
public:
	Bullet(DVector2i pos);
	~Bullet() { delete skin; }
private:
	DOSprite* skin;
	float currentSpeed;
	DVector2i dir;

	float curTime;
	float delTime;
public:
	virtual void Update(double deltaTime) override
	{
		//currentSpeed += deltaTime * acceleration;
		// 구한 마우스 방향으로 이동
		SetLocation(GetLocation() + (dir * deltaTime * currentSpeed));

		curTime += deltaTime;
		// 생성된 후 일정 시간 후 스스로 파괴
		if (curTime >= delTime)
			delete this;
	}
};

class Player : public DObject
{
public:
	Player()
	{
		DOSprite* skin = new DOSprite(1);
		skin->SetScale(60, 60);
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
		/*if (DInputManager::GetMouseButton(0))*/
		if (DInputManager::GetMouseButton(0))
		{
			// 총알 생성
			if (!f)
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
public:
	Enemy()
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
	DObject* player;
	int curHp;
	// 플레이어 인식 범위
	float cognizance;
	// 이동속도
	float moveSpeed;
public:
	void SetPlayer(DObject* p) { player = p; };
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

class EnemyManager : public DObject
{
public:
	EnemyManager() {}
private:
	Player* playerObj;
public:
	// 적 생성 함수
	void CreataEnemy()
	{
		// 적 생성
		Enemy* e = new Enemy();
		e->SetLocation(100, 100);
		e->SetPlayer(playerObj);
	}


};
