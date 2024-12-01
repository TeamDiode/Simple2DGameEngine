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
    DVector2i velocity; // ��ü�� �ӵ�
    DVector2i size;
    float mass; // ����. 
    float density; // �е�
    Shape shape;
    float restitution; // �ݹ� ���
    AABB aabb; // ��ü�� AABB �浹 ���
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
    DCollisionData* GetParent() { return parent; }  // �θ� ��ü�� ��ȯ�ϴ� �Լ�

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
