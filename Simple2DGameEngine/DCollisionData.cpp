#include "DCollisionData.h"

DCollisionData::DCollisionData(const DVector2i& position, const DVector2i& s, float m, float r)
    : pos(position), size(size), mass(m), restitution(r) {
    //AABB경계 구하기
    aabb.min = pos - (size * 0.5f);
    aabb.max = pos + (size * 0.5f);
}

void DCollisionData::UpdatePosition(float deltaTime) {
    // 속도 위치 업데이트
    pos.x += static_cast<int>(velocity.x * deltaTime);
    pos.y += static_cast<int>(velocity.y * deltaTime);
    aabb.min = pos - (size * 0.5f);  //AABB 위치 갱신
    aabb.max = pos + (size * 0.5f);
}