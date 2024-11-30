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
		// ���� ���콺 �������� �̵�
		SetLocation(GetLocation() + (dir * deltaTime * currentSpeed));

		curTime += deltaTime;
		// ������ �� ���� �ð� �� ������ �ı�
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
		// �̵� �Է�
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
			// �Ѿ� ����
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
	// �÷��̾� �ν� ����
	float cognizance;
	// �̵��ӵ�
	float moveSpeed;
public:
	void SetPlayer(DObject* p) { player = p; };
	virtual void Update(double deltaTime) override
	{
		if (player == nullptr) return;
		// �÷��̾� ������Ʈ �Ÿ��� �ڽŰ��� ������Ʈ �Ÿ� ���
		// �νĹ��� ���̶��
		if (DVector2i::Distance(player->GetLocation(), GetLocation()) < cognizance)
		{
			// �÷��̾���� ���⺤�� ���
			DVector2i dir = player->GetLocation() - GetLocation();
			dir.Normalize();

			// �÷��̾� ������ �̵�
			SetLocation(GetLocation() + (dir * deltaTime * moveSpeed));
		}
	}
	// �浹 ���� �� hp
}; 

class EnemyManager : public DObject
{
public:
	EnemyManager() {}
private:
	Player* playerObj;
public:
	// �� ���� �Լ�
	void CreataEnemy()
	{
		// �� ����
		Enemy* e = new Enemy();
		e->SetLocation(100, 100);
		e->SetPlayer(playerObj);
	}


};
