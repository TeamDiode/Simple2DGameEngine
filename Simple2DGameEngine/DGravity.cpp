#include "DGravity.h"

void DGravity::ApplyGravity(DCollisionData& object, float deltaTime)
{
	object.velocity.y += gravity * deltaTime;  // Y축에 중력 가속도 적용
}