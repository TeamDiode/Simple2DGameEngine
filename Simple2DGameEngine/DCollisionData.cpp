#include "DCollisionData.h"
#include "DPhysicsManager.h"
#include "DEngine.h"
#include <string>


DCollisionData::DCollisionData(Shape sha, float den, float r)
    : shape(sha), density(den), restitution(r) {

    UpdateAABB();

    mass = CalculateMass();

    DPhysicsManager::AddObject(this);
}

void DCollisionData::UpdateAABB() {
    aabb.min = GetLocation() - (GetScale() * 0.5f);
    aabb.max = GetLocation() + (GetScale() * 0.5f);
}

float DCollisionData::CalculateMass()
{
    if (shape == Shape::Rectangle)
    {
        float area = GetScale().x * GetScale().y;
        return density * area;
    }
    else if (shape == Shape::Circle)
    {
        float radius = GetScale().x / 2.0f; // 반지름
        float area = 3.141592f * radius * radius * GetScale().y;
        return density * area;
    }
    return 0.0f; // 다른 형태
    
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
        child->SetLocation(GetLocation()); // 부모의 위치로 동기화
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

void DCollisionData::OnCollision(DCollisionData* other)
{

}


