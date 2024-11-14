#pragma once

#include "DCollisionData.h"

class DCollisionDetector {
public:
    DCollisionDetector(DCollisionData* objectA, DCollisionData* objectB);

    bool DetectCollision(); // 충돌 발생시 true
    void ResolveCollision(DCollisionData objectA, DCollisionData objectB);

    DVector2i GetNormal() const { return normal; }
    float GetPenetration() const { return penetration; }

private:
    // 충돌 감지 세부 메서드
    bool DetectAABBCollision(); // AABB-AABB
    bool DetectCircleCollision(); // circle-circle
    bool DetectCircleAABBCollision(); // AABB-circle

private:
    DCollisionData* a; // 첫 번째 충돌 객체
    DCollisionData* b; // 두 번째 충돌 객체
    DVector2i normal; // 충돌 방향; 법선
    float penetration; // 겹쳐진 부분의 길이
};


