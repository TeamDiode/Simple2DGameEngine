#pragma once

#include "DCollisionData.h"

class DCollisionDetector {
public:
    DCollisionDetector(DCollisionData* a, DCollisionData* b);

    bool detectCollision(); // 충돌 발생시 true
    void ResolveCollision(DCollisionData a, DCollisionData b);

    DVector2i getNormal() const { return normal; }
    float getPenetration() const { return penetration; }

private:
    DCollisionData* A;
    DCollisionData* B;
    DVector2i normal; // 충돌 방향
    float penetration; // 겹쳐진 부분의 길이
};


