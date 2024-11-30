#include "DWorld.h"

DWorld::DWorld()
{
}

DWorld::~DWorld()
{
}

void DWorld::Load()
{
	Player* a = new Player();
	a->SetLocation(200, 500);

	WallManager* wallManager = new WallManager();
	
}

Wall::Wall() : DCollisionData(Shape::Rectangle, 1, 1)
{
	DOSprite* skin = new DOSprite(1);
	skin->SetScale(100, 400);
	DObject::AttachObject(skin);
	freezeX = true;
	freezeY = true;
	isUsed = false;

	destoryTime = 5;
	curTime = 0;
}

Wall::~Wall()
{
	delete skin;
}

void Wall::Update(double deltaTime)
{
	if (isUsed) return;


	SetLocation(GetLocation() + DVector2i(deltaTime * -200, 0));

	curTime += deltaTime;
	if (curTime >= destoryTime)
	{
		curTime = 0;
		isUsed = true;
	}

}

Wall* WallObjectPool::GetWall()
{
	{
		if (PossibleGetWall())
		{
			Wall* data = objQueue.front();
			objQueue.pop();
			objQueue.push(data);
			return data;
		}
		else
		{
			Wall* wall = new Wall();
			objQueue.push(wall);
			return wall;
		}
	}
}

bool WallObjectPool::PossibleGetWall()
{
	if (objQueue.empty()) return false;
	return objQueue.front()->GetIsUsed();
}

void WallManager::Update(double deltaTime)
{
	curTime += deltaTime;
	if (curTime >= createWallTime)
	{
		Wall* wall = wop.GetWall();
		Wall* wall2 = wop.GetWall();


		wall->Reset();
		wall2->Reset();

		float dis = distr(gen);

		wall->SetLocation(700, 125 + dis);
		wall2->SetLocation(700, 650 + dis);
		curTime = 0;
	}

}

Player::Player()
{
	DOSprite* skin = new DOSprite(1);
	skin->SetScale(70, 70);
	DObject::AttachObject(skin);
}

void Player::Update(double deltaTime)
{
	if (DInputManager::GetKey(space))
	{
		SetLocation(GetLocation() + DVector2i(0, deltaTime * -200));
	}
	else
	{
		SetLocation(GetLocation() + DVector2i(0, deltaTime * 200));
	}


}
