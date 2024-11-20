#pragma once

#include "DMathTypes.h"
#include "DGravity.h"
#include "DList.hpp"

class DPhysicsManager {
public:
    // ������Ʈ �߰�
    static void AddObject(DCollisionData* object);
    //�߷� ����, ��ġ ����
    void UpdateObjects(float deltaTime);
    // �浹 ó��
    void ResolveCollisions();

private:
    static DList<DCollisionData*> objects;
    DGravity gravity; // �߷� ����
};
