#pragma once

#include "DMathTypes.h"

class DCollisionData {
public:
    DVector2i pos;      // ��ü�� ��ġ
    DVector2i velocity; // ��ü�� �ӵ�
    DVector2i size;
    float mass; // ����. (�ϴ� �־������ ����� ����.)
    float restitution; // �ݹ� ���
    AABB aabb; // ��ü�� AABB �浹 ���

public:
    DCollisionData(const DVector2i& position, const DVector2i& size, float m, float r);
    void UpdatePosition(float deltaTime);
};

struct AABB
{
    DVector2i min;
    DVector2i max;
};
