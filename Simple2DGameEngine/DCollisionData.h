#pragma once

#include "DMathTypes.h"

enum class Shape
{
    Rectangle, 
    Circle
};

class DCollisionData {
public:
    DVector2i pos;      // 물체의 위치
    DVector2i velocity; // 물체의 속도
    DVector2i size;
    float mass; // 질량. 
    float density; // 밀도
    Shape shape;
    float restitution; // 반발 계수
    AABB aabb; // 물체의 AABB 충돌 경계

public:
    DCollisionData(const DVector2i& position, const DVector2i& size, Shape sha, float den, float r);
    float CalculateMass();
    void UpdatePosition(float deltaTime);

};

struct AABB
{
    DVector2i min;
    DVector2i max;
};
