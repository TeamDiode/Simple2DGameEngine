#include "DPhysicsManager.h"

void DPhysicsManager::AddObject(DCollisionData* object) {
    objects.AddNext(object); // 객체 추가
}

void DPhysicsManager::UpdateObjects(float deltaTime) {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* obj = objects.GetValue();
        gravity.ApplyGravity(*obj, deltaTime); // 중력 적용
        obj->UpdatePosition(deltaTime); // 위치 업데이트
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
                detector.ResolveCollision(*objA, *objB); // 충돌 해결
            }
            objects.Move();
        }
        objects.Move();
    }
}