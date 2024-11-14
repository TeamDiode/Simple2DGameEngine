#include "DGravity.h"

void DGravity::ApplyGravity(DCollisionData& object, float deltaTime)
{
	float effectiveGravity = gravity * gravityScale; // 중력 계산

	object.velocity.y += effectiveGravity * deltaTime; // 변화량 반영
}