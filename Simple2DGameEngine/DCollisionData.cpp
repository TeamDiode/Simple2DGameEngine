#include "DCollisionData.h"

DCollisionData::DCollisionData(Shape sha, float den, float r)
    : shape(sha), density(den), restitution(r) 
{
    localPosition = GetLocation();
    size = GetScale();


    //AABB��� ���ϱ�
    aabb.min = localPosition - (size * 0.5f);
    aabb.max = localPosition + (size * 0.5f);

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
    localPosition.x += static_cast<int>(velocity.x * deltaTime);
    localPosition.y += static_cast<int>(velocity.y * deltaTime);
    aabb.min = localPosition - (size * 0.5f);  //AABB ��ġ ����
    aabb.max = localPosition + (size * 0.5f);

    SetLocation(localPosition); // DObject�� ��ġ �ݿ�
}