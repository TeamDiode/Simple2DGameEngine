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

public:
    DCollisionData(Shape sha, float den, float r);
    float CalculateMass();
    void UpdatePosition(float deltaTime);

};
