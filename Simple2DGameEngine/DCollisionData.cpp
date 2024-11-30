#include "DCollisionData.h"
#include "DPhysicsManager.h"
#include "DEngine.h"
#include <string>


DCollisionData::DCollisionData(Shape sha, float den, float r, DObject* linkedObj)
    : shape(sha), density(den), restitution(r), linkedObject(linkedObj), otherObject(nullptr) {
    if (linkedObject) {
        size = linkedObject->GetScale();
        SetLocation(linkedObject->GetLocation());
    }
    else {
        size = GetScale();
    }

    UpdateAABB();

    mass = CalculateMass();

    DPhysicsManager::AddObject(this);
}

void DCollisionData::UpdateAABB() {
    aabb.min = GetLocation() - (size * 0.5f);
    aabb.max = GetLocation() + (size * 0.5f);

    
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

    UpdateAABB();

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

void DCollisionData::SyncWithLinkedObject() {
    if (linkedObject) {
        // linkedObject�� ������ ����ȭ
        SetLocation(linkedObject->GetLocation());
        size = linkedObject->GetScale();
        UpdateAABB();
    }
}



