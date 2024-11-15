#pragma once

#include "DCollisionData.h"

class DGravity {
public:
    DGravity(float g = 9.81f) : gravity(g), gravityScale(1.0f) {}

    // 중력 적용하여 속도 변경
    void ApplyGravity(DCollisionData& object, float deltaTime);

    void SetGravityScale(float scale) { gravityScale = scale; }
    float GetGravityScale() { return gravityScale; }

private:
    float gravity;  // 기본 중력 가속도
    float gravityScale; // 사용자 중력 가속도
};

