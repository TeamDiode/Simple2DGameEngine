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
Bullet::Bullet(DVector2i pos) : DCollisionData(pos, DVector2i(30, 30), 0, Shape::Circle, 1, 1)
{
	

	// �߷� ����
	SetGravityScale(0);
	// �ӵ� �ʱ�ȭ
	currentSpeed = 400;
	// ����
	skin = new DOSprite(2);
	skin->SetScale(30, 30);
	AttachObject(skin);
	
	// ���� �ð��� ������ �� �ð��� ������ ���� �ʱ�ȭ
	curTime = 0;
	delTime = 5;

	// �ӵ�
	dir = DRenderer::GetWorldLocationInScreenPoint(DInputManager::GetMousePostion());
	dir = dir - GetLocation();
	dir.Normalize();
	dir = dir * currentSpeed;

	
}

void Bullet::OnCollision(DCollisionData* other)
{
	
	// ������
	if (other->GetName() == "Enemy")
	{
		// ���� ����
		((Enemy*)other)->Attacked();
		
		// ���� �� �Ѿ� ����
		delete this;
	}
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

