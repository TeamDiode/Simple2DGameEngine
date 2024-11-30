#include "DGravity.h"


DGravity::DGravity(float g) : gravity(g) {}

void DGravity::ApplyGravity(DCollisionData& object, float deltaTime) {
    float adjustedGravity = gravity * object.GetGravityScale();

    // ��ü�� ���� �ӵ�
    DVector2i velocity = object.GetVelocity();
    velocity.y += adjustedGravity * deltaTime;  // Y�� �߷� ����

    // ���ο� �ӵ� ����
    object.SetVelocity(velocity);
}