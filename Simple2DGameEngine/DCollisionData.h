#pragma once

#include "DObject.h"
#include "DMathTypes.h"

enum class Shape
{
    Rectangle, 
    Circle
};

struct AABB
{
    DVector2i min;
    DVector2i max;
};

class DCollisionData : public DObject{
public:
    DObject* linkedObject;
    DVector2i velocity; // 물체의 속도
    DVector2i size;
    float mass; // 질량. 
    float density; // 밀도
    Shape shape;
    float restitution; // 반발 계수
    AABB aabb; // 물체의 AABB 충돌 경계
    bool freezeX;
    bool freezeY;
    DCollisionData* otherObject; // 충돌한 상대 객체


    DCollisionData* parent = nullptr;
    DList<DCollisionData*> children;

    // 충돌 이벤트 등록
    void RegisterCollisionEvent(DCollisionData* other) {
        otherObject = other;
    }

    // 충돌한 상대 객체를 반환
    DCollisionData* GetOtherObject() {
        return otherObject;
    }

    void UpdateAABB();

public:
    DCollisionData(Shape sha, float den, float r, DObject* linkedObj = nullptr);
    float CalculateMass();
    void UpdatePosition(float deltaTime);

    void AddChild(DCollisionData* child);
    void RemoveChild(DCollisionData* child);

    void SetParent(DCollisionData* parent) { this->parent = parent; }
    DCollisionData* GetParent() { return parent; }  // 부모 객체를 반환하는 함수

    void SetRestitution(float restitutionValue);
    float GetRestitution() const { return restitution; }

    void SyncWithLinkedObject();

private:
    void UpdateChildren();


};
