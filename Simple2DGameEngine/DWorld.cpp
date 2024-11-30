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
	// �÷��̾� ��ġ �ʱ�ȭ
	player->SetLocation(200, 500);

	// �� ���� Ŭ���� ����
	WallManager* wallManager = new WallManager();
	
}

Wall::Wall() : DCollisionData(Shape::Rectangle, 1, 1)
{
	// �̹��� ������Ʈ ����
	DOSprite* skin = new DOSprite(1);
	// ������Ʈ ũ�� ����
	skin->SetScale(100, 400);
	// ���� ������Ʈ�� �߰�
	DObject::AttachObject(skin);
	// DCollisionData �߷� �Ǵ� �ӵ��� ���� X Y �� �̵� ���
	freezeX = true;
	freezeY = true;
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

Wall* WallObjectPool::GetWall()
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
		// �� �տ� �־��� �� ��ȯ
		return data;
	}
	else
	{
		// �Ǿ��� ť�� ��� �Ұ����ϴٸ�
		// 1. ť�� ��� �ְų� 
		// 2. �� ���� ť�� �����

		// �� ������Ʈ ����
		Wall* wall = new Wall();
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
		// �� ��
		Wall* wall = wop.GetWall();
		// �Ʒ� ��
		Wall* wall2 = wop.GetWall();

		// �� �ʱ�ȭ
		wall->Reset();
		wall2->Reset();

		// �������� �� ��ġ ����
		float dis = distr(gen);

		// ������ �Ÿ��� �ǵ��� �� ��, �Ʒ� ���� ���� �� ����
		wall->SetLocation(700, 125 + dis);
		wall2->SetLocation(700, 650 + dis);
		// ���� �ð��� 0���� �ʱ�ȭ
		curTime = 0;
	}

}

Player::Player()
{
	// �̹��� ������Ʈ ����
	DOSprite* skin = new DOSprite(1);
	// �̹��� ũ�� ����
	skin->SetScale(70, 70);
	// �̹��� ������Ʈ �÷��̾� ������Ʈ ������ ���
	DObject::AttachObject(skin);
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
