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
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    aabb.min = GetLocation() - (GetScale() * 0.5f);
    aabb.max = GetLocation() + (GetScale() * 0.5f);
    ReleaseMutex(hMutex);  // ���ؽ� ����
}

float DCollisionData::CalculateMass()
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    if (shape == Shape::Rectangle)
    {
        float area = GetScale().x * GetScale().y;
        return density * area;
    }
    else if (shape == Shape::Circle)
    {
        float radius = GetScale().x / 2.0f; // ������
        float area = 3.141592f * radius * radius * GetScale().y;
        return density * area;
    }
    ReleaseMutex(hMutex);  // ���ؽ� ����
    return 0.0f; // �ٸ� ����
    
}

void DCollisionData::UpdatePosition(float deltaTime) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    if (freezeX)
        velocity.x = 0;
    if (freezeY)
        velocity.y = 0;

    SetLocation(GetLocation() + velocity * deltaTime);

    UpdateAABB();

    UpdateChildren();
    ReleaseMutex(hMutex);  // ���ؽ� ����
}


void DCollisionData::AddChild(DCollisionData* child)
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    if (child)
    {
        children.AddNext(child);
        child->SetLocation(GetLocation()); // �θ��� ��ġ�� ����ȭ
    }
    ReleaseMutex(hMutex);  // ���ؽ� ����
}

void DCollisionData::RemoveChild(DCollisionData* child)
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
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
    ReleaseMutex(hMutex);  // ���ؽ� ����
}


void DCollisionData::UpdateChildren()
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
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
    ReleaseMutex(hMutex);  // ���ؽ� ����
}

void DCollisionData::SetRestitution(float restitutionValue)
{
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    restitution = restitutionValue;
    ReleaseMutex(hMutex);  // ���ؽ� ����
}

void DCollisionData::OnCollision(DCollisionData* other)
{

}


