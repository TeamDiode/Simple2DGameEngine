#pragma once

#include "DCollisionData.h"
#include "DMathTypes.h"

class DGravity {
public:
    // ������: �⺻ �߷� ���� ����
    DGravity(float g = 9.81f);

    // �߷� ���� �Լ�
    void ApplyGravity(DCollisionData& object, float deltaTime);

    // �߷� ������ ���� �� ��ȯ
    //void SetGravityScale(float scale);
    //float GetGravityScale() const;

private:
    float gravity;        // �⺻ �߷� ���ӵ�
    float gravityScale;   // �߷� ������ (���� ������)
};
