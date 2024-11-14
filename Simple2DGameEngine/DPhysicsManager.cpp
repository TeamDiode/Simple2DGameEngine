#include "DPhysicsManager.h"

void DPhysicsManager::AddObject(DCollisionData* object) {
    objects.AddNext(object); // ��ü �߰�
}

void DPhysicsManager::UpdateObjects(float deltaTime) {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* obj = objects.GetValue();
        gravity.ApplyGravity(*obj, deltaTime); // �߷� ����
        obj->UpdatePosition(deltaTime); // ��ġ ������Ʈ
        objects.Move();
    }
}

void DPhysicsManager::ResolveCollisions() {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* objA = objects.GetValue();
        for (int j = i + 1; j < objects.GetSize(); j++) {
            DCollisionData* objB = objects.GetValue();
            DCollisionDetector detector(objA, objB);
            if (detector.DetectCollision()) {
                detector.ResolveCollision(*objA, *objB); // �浹 �ذ�
            }
            objects.Move();
        }
        objects.Move();
    }
}