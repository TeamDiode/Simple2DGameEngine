#include "DGravity.h"

void DGravity::ApplyGravity(DCollisionData& object, float deltaTime)
{
	object.velocity.y += gravity * deltaTime;  // Y�࿡ �߷� ���ӵ� ����
}