#pragma once

#include "DCollisionData.h"
#include "DMathTypes.h"

class DGravity {
public:
    // 생성자: 기본 중력 값을 설정
    DGravity(float g = 9.81f);

    // 중력 적용 함수
    void ApplyGravity(DCollisionData& object, float deltaTime);

    // 중력 스케일 설정 및 반환
    //void SetGravityScale(float scale);
    //float GetGravityScale() const;

private:
    float gravity;        // 기본 중력 가속도
    float gravityScale;   // 중력 스케일 (전역 설정용)
};
