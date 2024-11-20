#pragma once

#include "DMathTypes.h"
#include "DGravity.h"
#include "DList.hpp"

class DPhysicsManager {
public:
    // 오브젝트 추가
    static void AddObject(DCollisionData* object);
    //중력 적용, 위치 갱신
    void UpdateObjects(float deltaTime);
    // 충돌 처리
    void ResolveCollisions();

private:
    static DList<DCollisionData*> objects;
    DGravity gravity; // 중력 관리
};
