#include "SimpleMapTool.h"


SimpleMapTool::SimpleMapTool()
{
	// ���⼭ �� �ʱ�ȭ �۾� ����
}

void SimpleMapTool::Activated()
{
	DObject* a = DObjectManager::CreateObject(TestPlayer());
	a->SetLocation(500, 500);
}
