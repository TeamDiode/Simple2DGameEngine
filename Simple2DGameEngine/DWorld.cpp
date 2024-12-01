#include "DWorld.h"

DWorld::DWorld()
{
}

DWorld::~DWorld()
{
}

void DWorld::Load()
{
	// �÷��̾� ����
	Player* player = new Player();
	player->SetLocation(500, 500);
	player->SetScale(100, 100);

	// ���� ������ �����ϴ� EnemyManager Ŭ���� ����
	EnemyManager* em = new EnemyManager(player);
}
#include "DEngine.h"
#include <string>
Bullet::Bullet(DVector2i pos) : DCollisionData(pos, DVector2i(50, 50), 0, Shape::Rectangle, 1, 1)
{
	// �߷� ����
	SetGravityScale(0);
	// �ӵ� �ʱ�ȭ
	currentSpeed = 400;
	// ����
	skin = new DOSprite(2);
	skin->SetScale(50, 50);
	AttachObject(skin);
	
	// ���� �ð��� ������ �� �ð��� ������ ���� �ʱ�ȭ
	curTime = 0;
	delTime = 1;

	// �ӵ�
	dir = DRenderer::GetWorldLocationInScreenPoint(DInputManager::GetMousePostion());
	dir = dir - GetLocation();
	dir.Normalize();
	dir = dir * currentSpeed;
}

void Bullet::OnCollision(DCollisionData* other)
{
	// ������
}

void Bullet::Update(double deltaTime)
{
	// ���� ���콺 �������� �̵�
	SetLocation(GetLocation() + (dir * deltaTime));

	curTime += deltaTime;
	// ������ �� ���� �ð� �� ������ �ı�
	if (curTime >= delTime);
		//delete this;
}

