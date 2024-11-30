#include "DCollision.h"
#include "DCollisionData.h"

#include "DMathTypes.h"

DCollisionDetector::DCollisionDetector(DCollisionData* objectA, DCollisionData* objectB)
    : a(objectA), b(objectB), normal(0, 0), penetration(0) {}


//�浹 ����
bool DCollisionDetector::DetectCollision()
{
    // AABB-AABB
    if (a->shape == Shape::Rectangle && b->shape == Shape::Rectangle)
    {
        return DetectAABBCollision();
    }

    // circle-circle
    else if (a->shape == Shape::Circle && b->shape == Shape::Circle)
    {
        return DetectCircleCollision();
    }

    // AABB-circle
    else if ((a->shape == Shape::Rectangle && b->shape == Shape::Circle) ||
        (a->shape == Shape::Circle && b->shape == Shape::Rectangle))
    {
        return DetectCircleAABBCollision();
    }

    return false;
}

// AABB-AABB �浹 ����
bool DCollisionDetector::DetectAABBCollision()
{
    DVector2i n = b->localPosition - a->localPosition;

    float aExtentX = (a->aabb.max.x - a->aabb.min.x) / 2;
    float bExtentX = (b->aabb.max.x - b->aabb.min.x) / 2;
    float xOverlap = aExtentX + bExtentX - ((n.x < 0) ? -n.x : n.x);

    if (xOverlap > 0) {
        float aExtentY = (a->aabb.max.y - a->aabb.min.y) / 2;
        float bExtentY = (b->aabb.max.y - b->aabb.min.y) / 2;
        float yOverlap = aExtentY + bExtentY - ((n.y < 0) ? -n.y : n.y);

        if (yOverlap > 0) {
            if (xOverlap > yOverlap) {
                normal = (n.x < 0) ? DVector2i(-1, 0) : DVector2i(1, 0);
                penetration = xOverlap;
            }
            else {
                normal = (n.y < 0) ? DVector2i(0, -1) : DVector2i(0, 1);
                penetration = yOverlap;
            }
            return true;
        }
    }
    return false;
}

// circle-circle
bool DCollisionDetector::DetectCircleCollision()
{
    DVector2i n = b->GetLocation() - a->GetLocation();
    float radiusA = a->size.x / 2.0f;
    float radiusB = b->size.x / 2.0f;
    float radiusSum = radiusA + radiusB;

    float distanceSquared = n.x * n.x + n.y * n.y; // �Ÿ� ���� ���
    if (distanceSquared < radiusSum * radiusSum) // �� �浹 Ȯ��
    {
        penetration = radiusSum * radiusSum - distanceSquared;

        normal = n;

        return true;
    }

    return false;
}

// AABB-circle
bool DCollisionDetector::DetectCircleAABBCollision() 
{

    DCollisionData* circle = (a->shape == Shape::Circle) ? a : b; // �� üũ
    DCollisionData* rect = (circle == a) ? b : a; // �簢�� üũ

    DVector2i circleCenter = circle->GetLocation(); // ���� �߽�
    float radius = circle->size.x / 2.0f; // ������ ���

    // ���簢���� ���� ����� �� ���
    float closestX = rect->aabb.min.x > circleCenter.x ? rect->aabb.min.x : (rect->aabb.max.x < circleCenter.x ? rect->aabb.max.x : circleCenter.x);
    float closestY = rect->aabb.min.y > circleCenter.y ? rect->aabb.min.y : (rect->aabb.max.y < circleCenter.y ? rect->aabb.max.y : circleCenter.y);

    // ��/���簢���� ���� ����� �� ������ �Ÿ� ����
    DVector2i difference = circleCenter - DVector2i(closestX, closestY);
    float distanceSquared = difference.x * difference.x + difference.y * difference.y;

    // �浹 ����
    if (distanceSquared < radius * radius) {
        penetration = radius * radius - distanceSquared;
        normal = difference;

        return true;
    }

    return false;
}


//�浹 �ذ�
void DCollisionDetector::ResolveCollision(DCollisionData a, DCollisionData b)
{
    DVector2i rv = b.velocity - a.velocity;
    float velAlongNormal = rv.x * normal.x + rv.y * normal.y; //���� ���
    if (velAlongNormal > 0)
        return;

    float e = a.restitution < b.restitution ? a.restitution : b.restitution;

    if (e == 0) {
        if (normal.y > 0) {
            a.velocity.y = 0;  
            b.velocity.y = 0;  

            DVector2i overlap = normal * penetration;
            a.SetLocation(a.GetLocation() - overlap);
            b.SetLocation(b.GetLocation() + overlap);
        }
        return;
    }

    float j = -(1 + e) * velAlongNormal; // ��ݷ�
    j /= 1 / a.mass + 1 / b.mass; // ��� �� �ӵ���ȭ�� ����� ��ݷ�
    DVector2i impulse = DVector2i(normal.x * j, normal.y * j);

    // ���� �浹
    if (normal.y == 0) {
        a.velocity.x -= (1 / a.mass) * impulse.x;
        a.velocity.y -= (1 / a.mass) * impulse.y;
        b.velocity.x += (1 / b.mass) * impulse.x;
        b.velocity.y += (1 / b.mass) * impulse.y;
    }
    // ���� �浹
    else if (normal.y > 0) {
        float rebound = (e > 1.0f) ? e : 1.0f; 
        a.velocity.x -= (1 / a.mass) * impulse.x;
        b.velocity.x += (1 / b.mass) * impulse.x;

        // y�� �ӵ��� ��ݷ��� ����Ͽ� ƨ�ܳ���
        a.velocity.y = -rebound * a.velocity.y;
        b.velocity.y = -rebound * b.velocity.y;

        // ��ġ ������Ʈ
        DVector2i overlap = normal * penetration;
        a.SetLocation(a.GetLocation() - overlap);
        b.SetLocation(b.GetLocation() + overlap);
    }
}