#pragma once

#include "DMathTypes.h"
#include "DGravity.h"
#include "DList.hpp"
#include "DCollisionData.h"
#include "DSubSystem.h"
#include <Windows.h>


class DPhysicsManager : public IDSubSystem
{
public:
    DPhysicsManager();
public:
    // 오브젝트 추가
    static void AddObject(DCollisionData* object);

    // 부모 관계 설정
    void SetParent(DCollisionData* parent, DCollisionData* child);
    // 부모 제거
    void RemoveParent(DCollisionData* child);
    // 반발 계수 설정
    void SetRestitutionForObject(DCollisionData* object, float restitutionValue) {
        object->SetRestitution(restitutionValue);
    }


    virtual void Tick(double deltaTime) override 
    {
        UpdateObjects(deltaTime);
        ResolveCollisions();
    }

private:
    static DList<DCollisionData*> objects;
    DGravity gravity; // 중력 관리
    float restitutionStrength;


    //중력 적용, 위치 갱신
    void UpdateObjects(float deltaTime);
    // 충돌 처리
    void ResolveCollisions();

};
