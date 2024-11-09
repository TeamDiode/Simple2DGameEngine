#pragma once

#include "DCollisionData.h"

class DCollisionDetector {
public:
    DCollisionDetector(DCollisionData* a, DCollisionData* b);

    bool detectCollision(); // �浹 �߻��� true
    void ResolveCollision(DCollisionData a, DCollisionData b);

    DVector2i getNormal() const { return normal; }
    float getPenetration() const { return penetration; }

private:
    DCollisionData* A;
    DCollisionData* B;
    DVector2i normal; // �浹 ����
    float penetration; // ������ �κ��� ����
};


