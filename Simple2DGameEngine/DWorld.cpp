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
	Player* a = new Player();
	a->SetLocation(500, 500);
	a->SetScale(100, 100);

	
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

