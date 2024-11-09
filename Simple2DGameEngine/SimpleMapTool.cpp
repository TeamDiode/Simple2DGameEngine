#include "SimpleMapTool.h"


SimpleMapTool::SimpleMapTool()
{
	// 여기서 맵 초기화 작업 진행
}

void SimpleMapTool::Activated()
{
	DObject* a = DObjectManager::CreateObject(TestPlayer());
	a->SetLocation(500, 500);
}
