#pragma once

#include "DCollisionData.h"

class DGravity {
public:
    DGravity(float g = 9.81f) : gravity(g), gravityScale(1.0f) {}

    // �߷� �����Ͽ� �ӵ� ����
    void ApplyGravity(DCollisionData& object, float deltaTime);

    void SetGravityScale(float scale) { gravityScale = scale; }
    float GetGravityScale() { return gravityScale; }

private:
    float gravity;  // �⺻ �߷� ���ӵ�
    float gravityScale; // ����� �߷� ���ӵ�
};

