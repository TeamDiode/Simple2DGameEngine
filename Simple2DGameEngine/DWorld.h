#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DInput.h"

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

// �Ѿ� Ŭ����
// - �÷��̾�� ���콺�� ���� ��� �� �̵�
// - ���� �ð� �� ����
class Bullet : public DObject
{
public:
	Bullet(DVector2i pos);
	~Bullet() { delete skin; }
private:
	DOSprite* skin;
	// �Ѿ� �ӵ�
	float currentSpeed;
	// ���ư�����(���콺 ��ġ) ������ �����ϴ� ����
	DVector2i dir;

	// �Ѿ��� ������ ���� �ð� ����
	float curTime;
	float delTime;
public:
	virtual void Update(double deltaTime) override
	{
		// ���� ���콺 �������� �̵�
		SetLocation(GetLocation() + (dir * deltaTime * currentSpeed));

		curTime += deltaTime;
		// ������ �� ���� �ð� �� ������ �ı�
		if (curTime >= delTime)
			delete this;
	}
};

// �÷��̾� Ŭ����
// - �̵� ���
// - �Ѿ� ����
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

// �� Ŭ����
// - �̵����
// ���� �浹���� �� ���� ���
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
	// �÷��̾� ��ġ�� �����ϴ� ����
	DObject* player;
	// �� HP
	int curHp;
	// �÷��̾� �ν� ����
	float cognizance;
	// �̵��ӵ�
	float moveSpeed;
public:
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

// �� ������ �����ϴ� Ŭ����
// - ���� �ð����� �� ����
class EnemyManager : public DObject
{
public:
	EnemyManager(DObject* obj) :gen(), distr(100, 600), playerObj(obj)
	{
		regenerateTime = 10;
		curTime = regenerateTime;
	}
private:
	// �÷��̾ �����ϴ� ������Ʈ
	DObject* playerObj;
	// ������ ���� �ð� ����
	float curTime; // ���� �ð�
	float regenerateTime; // ���� �ð�
	// ������ ���� Ŭ����
	random_device rd;
	mt19937 gen;
	uniform_int_distribution<int> distr;
public:
	virtual void Update(double deltaTime) override
	{
		// ���� �ð� ���
		curTime += deltaTime;

		// ���� ���� �ð��� ���� �ð��� ���ų� ũ�ٸ�
		if (curTime >= regenerateTime)
		{
			// �� ����
			CreataEnemy();
			// ���� �ð� �ʱ�ȭ
			curTime = 0;
		}
	}
	// �� ���� �Լ�
	void CreataEnemy()
	{
		// �� ����
		Enemy* e = new Enemy(playerObj);
		e->SetLocation(distr(gen), distr(gen));
	}


};
