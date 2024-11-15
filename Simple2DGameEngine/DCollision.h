#pragma once

#include "DCollisionData.h"

class DCollisionDetector {
public:
    DCollisionDetector(DCollisionData* objectA, DCollisionData* objectB);

    bool DetectCollision(); // �浹 �߻��� true
    void ResolveCollision(DCollisionData objectA, DCollisionData objectB);

    DVector2i GetNormal() const { return normal; }
    float GetPenetration() const { return penetration; }

private:
    // �浹 ���� ���� �޼���
    bool DetectAABBCollision(); // AABB-AABB
    bool DetectCircleCollision(); // circle-circle
    bool DetectCircleAABBCollision(); // AABB-circle

private:
    DCollisionData* a; // ù ��° �浹 ��ü
    DCollisionData* b; // �� ��° �浹 ��ü
    DVector2i normal; // �浹 ����; ����
    float penetration; // ������ �κ��� ����
};


