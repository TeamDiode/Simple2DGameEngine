#pragma once

#include "DMathTypes.h"
#include "DGravity.h"
#include "DList.hpp"
#include "DCollisionData.h"

class DPhysicsManager {
public:
    // ������Ʈ �߰�
    static void AddObject(DCollisionData* object);
    //�߷� ����, ��ġ ����
    void UpdateObjects(float deltaTime);
    // �浹 ó��
    void ResolveCollisions();

    // �θ� ���� ����
    void SetParent(DCollisionData* parent, DCollisionData* child);
    // �θ� ����
    void RemoveParent(DCollisionData* child);
    // �ݹ� ��� ����
    void SetRestitutionForObject(DCollisionData* object, float restitutionValue) {
        object->SetRestitution(restitutionValue);
    }

private:
    static DList<DCollisionData*> objects;
    DGravity gravity; // �߷� ����
    float restitutionStrength;
};
