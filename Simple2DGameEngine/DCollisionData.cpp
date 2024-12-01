#include "DCollisionData.h"
#include "DPhysicsManager.h"
#include "DEngine.h"
#include <string>


DCollisionData::DCollisionData(Shape sha, float den, float r)
    : shape(sha), density(den), restitution(r) {

    hMutex = CreateMutex(NULL, false, NULL);

    UpdateAABB();

    mass = CalculateMass();

    DPhysicsManager::AddObject(this);
}

DCollisionData::DCollisionData(DVector2i defaultLocation, DVector2i defaultScale, float defaultAngle, Shape sha, float den, float r)
    : DObject(defaultLocation, defaultScale, defaultAngle), shape(sha), density(den), restitution(r)
{
    hMutex = CreateMutex(NULL, false, NULL);
    UpdateAABB();

    mass = CalculateMass();

    DPhysicsManager::AddObject(this);
}


void DCollisionData::UpdateAABB() {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    aabb.min = GetLocation() - (GetScale() * 0.5f);
    aabb.max = GetLocation() + (GetScale() * 0.5f);
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}

float DCollisionData::CalculateMass()
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
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
    ReleaseMutex(hMutex);  // 뮤텍스 해제
    return 0.0f; // 다른 형태
    
}

void DCollisionData::UpdatePosition(float deltaTime) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    if (freezeX)
        velocity.x = 0;
    if (freezeY)
        velocity.y = 0;

    SetLocation(GetLocation() + velocity * deltaTime);

    UpdateAABB();

    UpdateChildren();
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}


void DCollisionData::AddChild(DCollisionData* child)
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    if (child)
    {
        children.AddNext(child);
        child->SetLocation(GetLocation()); // 부모의 위치로 동기화
    }
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}

void DCollisionData::RemoveChild(DCollisionData* child)
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
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
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}


void DCollisionData::UpdateChildren()
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
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
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}

void DCollisionData::SetRestitution(float restitutionValue)
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    restitution = restitutionValue;
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}

void DCollisionData::OnCollision(DCollisionData* other)
{

}


