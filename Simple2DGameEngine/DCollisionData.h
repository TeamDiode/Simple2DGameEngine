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
    //DVector2i pos;      // ��ü�� ��ġ
    DVector2i velocity; // ��ü�� �ӵ�
    DVector2i size;
    float mass; // ����. 
    float density; // �е�
    Shape shape;
    float restitution; // �ݹ� ���
    AABB aabb; // ��ü�� AABB �浹 ���
    DVector2i localPosition; // �̵��� ��
    bool freezeX;
    bool freezeY;

    DCollisionData* parent = nullptr;
    DList<DCollisionData*> children;


    

public:
    DCollisionData(Shape sha, float den, float r);
    float CalculateMass();
    void UpdatePosition(float deltaTime);

    void AddChild(DCollisionData* child);
    void RemoveChild(DCollisionData* child);

    void SetParent(DCollisionData* parent) { this->parent = parent; }
    DCollisionData* GetParent() { return parent; }  // �θ� ��ü�� ��ȯ�ϴ� �Լ�

    void SetRestitution(float restitutionValue);
    float GetRestitution() const { return restitution; }

private:
    void UpdateChildren();


};
