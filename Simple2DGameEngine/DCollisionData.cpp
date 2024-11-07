#include "DCollisionData.h"

DCollisionData::DCollisionData(const DVector2i& position, const DVector2i& s, float m, float r)
    : pos(position), size(size), mass(m), restitution(r) {
    //AABB��� ���ϱ�
    aabb.min = pos - (size * 0.5f);
    aabb.max = pos + (size * 0.5f);
}

void DCollisionData::UpdatePosition(float deltaTime) {
    // �ӵ� ��ġ ������Ʈ
    pos.x += static_cast<int>(velocity.x * deltaTime);
    pos.y += static_cast<int>(velocity.y * deltaTime);
    aabb.min = pos - (size * 0.5f);  //AABB ��ġ ����
    aabb.max = pos + (size * 0.5f);
}