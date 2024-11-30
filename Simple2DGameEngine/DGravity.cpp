#include "DGravity.h"


DGravity::DGravity(float g) : gravity(g) {}

void DGravity::ApplyGravity(DCollisionData& object, float deltaTime) {
    float adjustedGravity = gravity * object.GetGravityScale();

    // 객체의 현재 속도
    DVector2i velocity = object.GetVelocity();
    velocity.y += adjustedGravity * deltaTime;  // Y축 중력 적용

    // 새로운 속도 설정
    object.SetVelocity(velocity);
}