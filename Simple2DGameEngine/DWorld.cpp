#include "DWorld.h"
#include "DEngine.h"
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
	//player->SetLocation(200, 500);
	// 벽 관리 클래스 생성
	WallManager* wallManager = new WallManager();
	
}

Wall::Wall(DVector2i pos) : DCollisionData(pos, DVector2i(100, 400), 0, Shape::Rectangle, 1, 1)
{
	// 이미지 오브젝트 생성
	skin = new DOSprite(1);
	// 오브젝트 크기 설정
	skin->SetScale(100, 400);
	// 하위 오브젝트에 추가
	DObject::AttachObject(skin);
	// DCollisionData 중력 또는 속도로 인한 X Y 축 이동 잠금
	SetGravityScale(0);
	// 사용되기 전으로 초기화
	isUsed = false;

	// 삭제 시간과 현재 시간을 초기화
	destoryTime = 5;
	curTime = 0;
}

Wall::~Wall()
{
	// 이미지 오브젝트 해제
	delete skin;
}

void Wall::Update(double deltaTime)
{
	// 사용된 벽이라면 활동 중지
	if (isUsed) return;

	// 벽 이동
	SetLocation(GetLocation() + DVector2i(deltaTime * -200, 0));

	// 현재 시간 계산
	curTime += deltaTime;
	// 만약 현재 시간이 삭제 시간보다 크거나 같다면
	if (curTime >= destoryTime)
	{
		// 현재 시간을 0으로 초기화
		curTime = 0;
		// 사용되었다고 설정
		isUsed = true;
	}

}

Wall* WallObjectPool::GetWall(DVector2i pos)
{
	// 만약 큐의 맨 앞이 사용 가능하다면
	if (PossibleGetWall())
	{
		// 큐의 맨 앞을 가져오기
		Wall* data = objQueue.front();
		// 큐에서 맨 앞 데이터 삭제
		objQueue.pop();
		// 맨 앞에 있던 데이터 맨 뒤로 보내기
		objQueue.push(data);
		data->SetLocation(pos);
		// 맨 앞에 있었던 벽 반환
		return data;
	}
	else
	{
		// 맨앞의 큐가 사용 불가능하다면
		// 1. 큐가 비어 있거나 
		// 2. 맨 앞의 큐가 사용중

		// 벽 오브젝트 생성
		Wall* wall = new Wall(pos);
		wall->SetName("Wall");
		// 큐에 벽 저장
		objQueue.push(wall);
		// 생성된 벽 반환
		return wall;
	}
}

bool WallObjectPool::PossibleGetWall()
{
	// 큐가 비어있다면 false 반환
	if (objQueue.empty()) return false;
	// 맨 앞 큐가 사용 가능하다면 true 반환
	return objQueue.front()->GetIsUsed();
}

void WallManager::Update(double deltaTime)
{
	// 현재 시간 계산
	curTime += deltaTime;

	if (curTime >= createWallTime)
	{
		// 벽 2개 추가

		// 벽 랜덤 위치 계산
		float dis = distr(gen);
		DVector2i pos1 = DVector2i(400, -225 + dis);
		DVector2i pos2 = DVector2i(400, 300 + dis);

		// 위 벽
		Wall* wall = wop.GetWall(pos1);
		// 아랫 벽
		Wall* wall2 = wop.GetWall(pos2);

		// 벽 초기화
		wall->Reset();
		wall2->Reset();
	
		// 현재 시간을 0으로 초기화
		curTime = 0;
	}

}

Player::Player() : DCollisionData(DVector2i(0, 0),DVector2i(70,70),0, Shape::Rectangle, 1, 1)
{
	// 이미지 오브젝트 생성
	DOSprite*  skin = new DOSprite(1);
	// 이미지 크기 설정
	skin->SetScale(70, 70);
	// 이미지 오브젝트 플레이어 오브젝트 하위에 상속
	DObject::AttachObject(skin);
	// 중력 값 0으로 설정
	SetGravityScale(0);

	//DEngine::LogMessageBox("Player");
}

void Player::Update(double deltaTime)
{
	// 만약 space 키를 눌렀을 때 캐릭터 위치 위로 이동
	if (DInputManager::GetKey(space))
	{
		SetLocation(GetLocation() + DVector2i(0, deltaTime * -200));
	}
	else // 그렇지 않다면
	{
		// 아래로 이동
		SetLocation(GetLocation() + DVector2i(0, deltaTime * 200));
	}


}

void Player::OnCollision(DCollisionData* other)
{
	if (other->GetName() == "Wall")
	{
		//DEngine::LogMessageBox("충돌!");
		
	}
}
