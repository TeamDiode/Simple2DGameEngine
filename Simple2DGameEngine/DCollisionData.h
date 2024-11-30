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
    DCollisionData* otherObject; // �浹�� ��� ��ü


    DCollisionData* parent = nullptr;
    DList<DCollisionData*> children;

    // �浹 �̺�Ʈ ���
    void RegisterCollisionEvent(DCollisionData* other) {
        otherObject = other;
    }

    // �浹�� ��� ��ü�� ��ȯ
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
    DCollisionData* GetParent() { return parent; }  // �θ� ��ü�� ��ȯ�ϴ� �Լ�

    void SetRestitution(float restitutionValue);
    float GetRestitution() const { return restitution; }

    void SyncWithLinkedObject();

private:
    void UpdateChildren();


};
