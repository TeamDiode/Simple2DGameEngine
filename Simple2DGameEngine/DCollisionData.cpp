#include "DCollisionData.h"
#include "DPhysicsManager.h"

DCollisionData::DCollisionData(Shape sha, float den, float r)
    : shape(sha), density(den), restitution(r) 
{
    localPosition = GetLocation();
    size = GetScale();


    //AABB경계 구하기
    aabb.min = localPosition - (size * 0.5f);
    aabb.max = localPosition + (size * 0.5f);

    mass = CalculateMass();

    DPhysicsManager::AddObject(this);
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
    SetLocation(GetLocation() + velocity * deltaTime); // DObject에 위치 반영
    aabb.min = GetLocation() - (size * 0.5f);  //AABB 위치 갱신
    aabb.max = GetLocation() + (size * 0.5f);

    
}