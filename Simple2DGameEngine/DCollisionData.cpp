#include "DCollisionData.h"

DCollisionData::DCollisionData(const DVector2i& position, const DVector2i& s, Shape sha, float den, float r)
    : pos(position), size(size), shape(sha), density(den), restitution(r) {
    //AABB��� ���ϱ�
    aabb.min = pos - (size * 0.5f);
    aabb.max = pos + (size * 0.5f);

    mass = CalculateMass();
}

float DCollisionData::CalculateMass()
{
    if (shape == Shape::Rectangle)
    {
        float area = size.x * size.y;
        return density * area;
    }
    else if (shape == Shape::Circle)
    {
        float radius = size.x / 2.0f; // ������
        float area = 3.141592f * radius * radius * size.y;
        return density * area;
    }
    return 0.0f; // �ٸ� ����
    
}

void DCollisionData::UpdatePosition(float deltaTime) {
    // �ӵ� ��ġ ������Ʈ
    pos.x += static_cast<int>(velocity.x * deltaTime);
    pos.y += static_cast<int>(velocity.y * deltaTime);
    aabb.min = pos - (size * 0.5f);  //AABB ��ġ ����
    aabb.max = pos + (size * 0.5f);
}