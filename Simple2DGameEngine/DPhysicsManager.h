#pragma once

#include "DMathTypes.h"
#include "DCollisionData.h"
#include "DGravity.h"
#include "DCollision.h"
#include "DList.hpp"

class DPhysicsManager {
public:
    // 오브젝트 추가
    void AddObject(DCollisionData* object);
    //중력 적용, 위치 갱신
    void UpdateObjects(float deltaTime);
    // 충돌 처리
    void ResolveCollisions();

private:
    DList<DCollisionData*> objects;
    DGravity gravity; // 중력 관리
};
