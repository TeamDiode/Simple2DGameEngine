#include "SimpleMapTool.h"


SimpleMapTool::SimpleMapTool()
{
	// ���⼭ �� �ʱ�ȭ �۾� ����
}

void SimpleMapTool::Activated()
{
	DObject* a = DObjectManager::CreateObject(TestPlayer());
	a->SetLocation(500, 500);
	a->SetScale(100, 100);
}

void TestPlayer::Update()
{
	if (DInputManager::GetKeyDown(D))
	{
		SetLocation(GetLocation() + DVector2i(0, 10));
	}
}
