#include "DCollisionData.h"

DCollisionData::DCollisionData(const DVector2i& position, const DVector2i& s, Shape sha, float den, float r)
    : pos(position), size(size), shape(sha), density(den), restitution(r) {
    //AABB경계 구하기
    aabb.min = pos - (size * 0.5f);
    aabb.max = pos + (size * 0.5f);

    mass = CalculateMass();
}

float DCollisionData::CalculateMass()
{
    if (shape == Shape::Rectangle)
    {
        float area = size.x * size.y;
        return density * area;
    }
    else if (shape == Shape::Circle)
    {
        float radius = size.x / 2.0f; // 반지름
        float area = 3.141592f * radius * radius * size.y;
        return density * area;
    }
    return 0.0f; // 다른 형태
    
}

void DCollisionData::UpdatePosition(float deltaTime) {
    // 속도 위치 업데이트
    pos.x += static_cast<int>(velocity.x * deltaTime);
    pos.y += static_cast<int>(velocity.y * deltaTime);
    aabb.min = pos - (size * 0.5f);  //AABB 위치 갱신
    aabb.max = pos + (size * 0.5f);
}