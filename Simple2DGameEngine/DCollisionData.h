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


    DCollisionData* parent = nullptr;
    DList<DCollisionData*> children;

    
    virtual void OnCollision(DCollisionData* other);

    

public:
    DCollisionData(Shape sha, float den, float r);
    DCollisionData(DVector2i defaultLocation, DVector2i defaultScale, float defaultAngle, Shape sha, float den, float r);
    float CalculateMass();
    void UpdatePosition(float deltaTime);

    void AddChild(DCollisionData* child);
    void RemoveChild(DCollisionData* child);

    void SetParent(DCollisionData* parent) { this->parent = parent; }
    DCollisionData* GetParent() { return parent; }  // 부모 객체를 반환하는 함수

    void SetRestitution(float restitutionValue);
    float GetRestitution() const { return restitution; }


    void UpdateAABB();


    DVector2i GetVelocity() const { return velocity; } 
    void SetVelocity(const DVector2i& newVelocity) { velocity = newVelocity; }
    float GetGravityScale() const { return gravityScale; }  
    void SetGravityScale(float scale) { gravityScale = scale; } 


private:
    void UpdateChildren();

    float gravityScale = 1.0f;


};
