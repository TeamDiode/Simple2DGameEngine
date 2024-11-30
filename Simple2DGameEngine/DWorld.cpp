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
	a->SetLocation(500, 500);
	a->SetScale(100, 100);
}
#include "DEngine.h"
#include <string>
Bullet::Bullet(DVector2i pos)
{
	SetLocation(pos);

	acceleration = 100;
	currentSpeed = 500;
	DOSprite* skin = new DOSprite(2);
	skin->SetScale(50, 50);
	AttachObject(skin);


	dir = DInputManager::GetMousePostion();
	dir = dir - GetLocation();
	dir.Normalize();


	
	/*std::string commend1 = "Mouse : " + std::to_string(DInputManager::GetMousePostion().x) + "," + std::to_string(DInputManager::GetMousePostion().y);
	std::string commend2 = "Player : " + std::to_string(pos.x) + "," + std::to_string(pos.y);
	std::string commend3 = "Reuslt : " + std::to_string(dir.x) + "," + std::to_string(dir.y);
	std::string temp = commend1 + "\n" + commend2 + "\n" + commend3;
	DEngine::LogMessageBox(temp.c_str());*/
}
