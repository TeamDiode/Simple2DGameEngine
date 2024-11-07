#pragma once

#include "DCollisionData.h"

class DGravity {
public:
    DGravity(float g = 9.81f) : gravity(g) {}

    // 중력 적용하여 속도 변경
    void ApplyGravity(DCollisionData& object, float deltaTime);

private:
    float gravity;  // 중력 가속도
};

