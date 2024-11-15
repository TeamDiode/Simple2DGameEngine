#include "DGravity.h"

void DGravity::ApplyGravity(DCollisionData& object, float deltaTime)
{
	float effectiveGravity = gravity * gravityScale; // �߷� ���

	object.velocity.y += effectiveGravity * deltaTime; // ��ȭ�� �ݿ�
}