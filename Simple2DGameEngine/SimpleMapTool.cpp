#include "SimpleMapTool.h"


SimpleMapTool::SimpleMapTool()
{
	// 여기서 맵 초기화 작업 진행
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
