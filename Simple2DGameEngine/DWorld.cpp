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
Bullet::Bullet(DVector2i pos)
{
	// ���� ��ġ ���� ( �÷��̾� ��ġ )
	SetLocation(pos);

	currentSpeed = 100;
	DOSprite* skin = new DOSprite(2);
	skin->SetScale(50, 50);
	AttachObject(skin);
	
	// ���� �ð��� ������ �� �ð��� ������ ���� �ʱ�ȭ
	curTime = 0;
	delTime = 1;

	// ���콺 ���� ���
	dir = DInputManager::GetMousePostion();
	dir = dir - GetLocation();
	dir.Normalize();
}

