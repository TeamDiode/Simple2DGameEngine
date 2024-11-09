#pragma once

#include "DMathTypes.h"
#include "DCollisionData.h"
#include "DGravity.h"
#include "DCollision.h"
#include "DList.hpp"

class DPhysicsManager {
public:
    // ������Ʈ �߰�
    void AddObject(DCollisionData* object);
    //�߷� ����, ��ġ ����
    void UpdateObjects(float deltaTime);
    // �浹 ó��
    void ResolveCollisions();

private:
    DList<DCollisionData*> objects;
    DGravity gravity; // �߷� ����
};
