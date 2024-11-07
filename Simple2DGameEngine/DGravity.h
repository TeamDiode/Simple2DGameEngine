#pragma once

#include "DCollisionData.h"

class DGravity {
public:
    DGravity(float g = 9.81f) : gravity(g) {}

    // �߷� �����Ͽ� �ӵ� ����
    void ApplyGravity(DCollisionData& object, float deltaTime);

private:
    float gravity;  // �߷� ���ӵ�
};

