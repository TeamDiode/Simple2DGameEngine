#include "DCollisionData.h"
#include "DPhysicsManager.h"

DCollisionData::DCollisionData(Shape sha, float den, float r)
    : shape(sha), density(den), restitution(r) 
{
    size = GetScale();


    //AABB��� ���ϱ�
    aabb.min = GetLocation() - (size * 0.5f);
    aabb.max = GetLocation() + (size * 0.5f);

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
    if (freezeX)
        velocity.x = 0;
    if (freezeY)
        velocity.y = 0;

    SetLocation(GetLocation() + velocity * deltaTime);
    
    
    // �ӵ� ��ġ ������Ʈ
    aabb.min = GetLocation() - (size * 0.5f);
    aabb.max = GetLocation() + (size * 0.5f);

    UpdateChildren();
}


void DCollisionData::AddChild(DCollisionData* child)
{
    if (child)
    {
        children.AddNext(child);
        child->SetLocation(GetLocation()); // �θ��� ��ġ�� ����ȭ
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
            DVector2i offset = child->GetLocation();
            child->SetLocation(GetLocation() + offset);
        }
        children.Move();
    }
}

void DCollisionData::SetRestitution(float restitutionValue)
{
    restitution = restitutionValue;
}