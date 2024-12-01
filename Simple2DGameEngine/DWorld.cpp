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
	// �÷��̾� ����
	Player* player = new Player();
	//player->SetLocation(200, 500);
	// �� ���� Ŭ���� ����
	WallManager* wallManager = new WallManager();
	
}

Wall::Wall(DVector2i pos) : DCollisionData(pos, DVector2i(100, 400), 0, Shape::Rectangle, 1, 1)
{
	// �̹��� ������Ʈ ����
	skin = new DOSprite(1);
	// ������Ʈ ũ�� ����
	skin->SetScale(100, 400);
	// ���� ������Ʈ�� �߰�
	DObject::AttachObject(skin);
	// DCollisionData �߷� �Ǵ� �ӵ��� ���� X Y �� �̵� ���
	SetGravityScale(0);
	// ���Ǳ� ������ �ʱ�ȭ
	isUsed = false;

	// ���� �ð��� ���� �ð��� �ʱ�ȭ
	destoryTime = 5;
	curTime = 0;
}

Wall::~Wall()
{
	// �̹��� ������Ʈ ����
	delete skin;
}

void Wall::Update(double deltaTime)
{
	// ���� ���̶�� Ȱ�� ����
	if (isUsed) return;

	// �� �̵�
	SetLocation(GetLocation() + DVector2i(deltaTime * -200, 0));

	// ���� �ð� ���
	curTime += deltaTime;
	// ���� ���� �ð��� ���� �ð����� ũ�ų� ���ٸ�
	if (curTime >= destoryTime)
	{
		// ���� �ð��� 0���� �ʱ�ȭ
		curTime = 0;
		// ���Ǿ��ٰ� ����
		isUsed = true;
	}

}

Wall* WallObjectPool::GetWall(DVector2i pos)
{
	// ���� ť�� �� ���� ��� �����ϴٸ�
	if (PossibleGetWall())
	{
		// ť�� �� ���� ��������
		Wall* data = objQueue.front();
		// ť���� �� �� ������ ����
		objQueue.pop();
		// �� �տ� �ִ� ������ �� �ڷ� ������
		objQueue.push(data);
		data->SetLocation(pos);
		// �� �տ� �־��� �� ��ȯ
		return data;
	}
	else
	{
		// �Ǿ��� ť�� ��� �Ұ����ϴٸ�
		// 1. ť�� ��� �ְų� 
		// 2. �� ���� ť�� �����

		// �� ������Ʈ ����
		Wall* wall = new Wall(pos);
		wall->SetName("Wall");
		// ť�� �� ����
		objQueue.push(wall);
		// ������ �� ��ȯ
		return wall;
	}
}

bool WallObjectPool::PossibleGetWall()
{
	// ť�� ����ִٸ� false ��ȯ
	if (objQueue.empty()) return false;
	// �� �� ť�� ��� �����ϴٸ� true ��ȯ
	return objQueue.front()->GetIsUsed();
}

void WallManager::Update(double deltaTime)
{
	// ���� �ð� ���
	curTime += deltaTime;

	if (curTime >= createWallTime)
	{
		// �� 2�� �߰�

		// �� ���� ��ġ ���
		float dis = distr(gen);
		DVector2i pos1 = DVector2i(400, -225 + dis);
		DVector2i pos2 = DVector2i(400, 300 + dis);

		// �� ��
		Wall* wall = wop.GetWall(pos1);
		// �Ʒ� ��
		Wall* wall2 = wop.GetWall(pos2);

		// �� �ʱ�ȭ
		wall->Reset();
		wall2->Reset();
	
		// ���� �ð��� 0���� �ʱ�ȭ
		curTime = 0;
	}

}

Player::Player() : DCollisionData(DVector2i(0, 0),DVector2i(70,70),0, Shape::Rectangle, 1, 1)
{
	// �̹��� ������Ʈ ����
	DOSprite*  skin = new DOSprite(1);
	// �̹��� ũ�� ����
	skin->SetScale(70, 70);
	// �̹��� ������Ʈ �÷��̾� ������Ʈ ������ ���
	DObject::AttachObject(skin);
	// �߷� �� 0���� ����
	SetGravityScale(0);

	//DEngine::LogMessageBox("Player");
}

void Player::Update(double deltaTime)
{
	// ���� space Ű�� ������ �� ĳ���� ��ġ ���� �̵�
	if (DInputManager::GetKey(space))
	{
		SetLocation(GetLocation() + DVector2i(0, deltaTime * -200));
	}
	else // �׷��� �ʴٸ�
	{
		// �Ʒ��� �̵�
		SetLocation(GetLocation() + DVector2i(0, deltaTime * 200));
	}


}

void Player::OnCollision(DCollisionData* other)
{
	if (other->GetName() == "Wall")
	{
		//DEngine::LogMessageBox("�浹!");
		
	}
}
