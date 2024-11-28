#include "DCollisionData.h"
#include "DPhysicsManager.h"

DCollisionData::DCollisionData(Shape sha, float den, float r)
    : shape(sha), density(den), restitution(r) 
{
    localPosition = GetLocation();
    size = GetScale();


    //AABB��� ���ϱ�
    aabb.min = localPosition - (size * 0.5f);
    aabb.max = localPosition + (size * 0.5f);

    mass = CalculateMass();

    DPhysicsManager::AddObject(this);
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
    if(!freezeX)
        localPosition.x += static_cast<int>(velocity.x * deltaTime);
    if (!freezeY)
        localPosition.y += static_cast<int>(velocity.y * deltaTime);
    
    // �ӵ� ��ġ ������Ʈ
    aabb.min = localPosition - (size * 0.5f);
    aabb.max = localPosition + (size * 0.5f);
    SetLocation(localPosition);

    UpdateChildren();
}


void DCollisionData::AddChild(DCollisionData* child)
{
    if (child)
    {
        children.AddNext(child);
        child->SetLocation(localPosition); // �θ��� ��ġ�� ����ȭ
    }
}

void DCollisionData::RemoveChild(DCollisionData* child)
{
    if (children.IsEmpty()) return;

    int listSize = children.GetSize();
    for (int i = 0; i < listSize; i++)
    {
        if (children.GetValue() == child)
        {
            children.RemoveHere();
            break;
        }
        children.Move();
    }
}


void DCollisionData::UpdateChildren()
{
    if (children.IsEmpty()) return;

    int listSize = children.GetSize();
    for (int i = 0; i < listSize; i++)
    {
        DCollisionData* child = children.GetValue();
        if (child)
        {
            DVector2i offset = child->localPosition;
            child->SetLocation(localPosition + offset);
        }
        children.Move();
    }
}

void DCollisionData::SetRestitution(float restitutionValue)
{
    restitution = restitutionValue;
}