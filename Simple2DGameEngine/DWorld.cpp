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
Bullet::Bullet(DVector2i pos) : DCollisionData(pos, DVector2i(50, 50), 0, Shape::Rectangle, 1, 1)
{
	// 중력 제거
	SetGravityScale(0);
	// 속도 초기화
	currentSpeed = 400;
	// 외형
	skin = new DOSprite(2);
	skin->SetScale(50, 50);
	AttachObject(skin);
	
	// 삭제 시간과 생성된 후 시간을 저장할 변수 초기화
	curTime = 0;
	delTime = 1;

	// 속도
	dir = DRenderer::GetWorldLocationInScreenPoint(DInputManager::GetMousePostion());
	dir = dir - GetLocation();
	dir.Normalize();
	dir = dir * currentSpeed;
}

void Bullet::OnCollision(DCollisionData* other)
{
	// 데미지
}

void Bullet::Update(double deltaTime)
{
	// 구한 마우스 방향으로 이동
	SetLocation(GetLocation() + (dir * deltaTime));

	curTime += deltaTime;
	// 생성된 후 일정 시간 후 스스로 파괴
	if (curTime >= delTime);
		//delete this;
}

