#include "DWorld.h"

DWorld::DWorld()
{
}

DWorld::~DWorld()
{
}

void DWorld::Load()
{
	// 플레이어 생성
	Player* player = new Player();
	player->SetLocation(500, 500);
	player->SetScale(100, 100);

	// 적을 생성을 관리하는 EnemyManager 클래스 생성
	EnemyManager* em = new EnemyManager(player);
}
#include "DEngine.h"
#include <string>
Bullet::Bullet(DVector2i pos)
{
	// 현재 위치 설정 ( 플레이어 위치 )
	SetLocation(pos);

	currentSpeed = 100;
	DOSprite* skin = new DOSprite(2);
	skin->SetScale(50, 50);
	AttachObject(skin);
	
	// 삭제 시간과 생성된 후 시간을 저장할 변수 초기화
	curTime = 0;
	delTime = 1;

	// 마우스 방향 계산
	dir = DInputManager::GetMousePostion();
	dir = dir - GetLocation();
	dir.Normalize();
}

