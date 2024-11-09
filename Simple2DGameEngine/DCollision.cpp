#include "DCollision.h"
#include "DCollisionData.h"

#include "DMathTypes.h"

DCollisionDetector::DCollisionDetector(DCollisionData* a, DCollisionData* b)
    : A(a), B(b), normal(0, 0), penetration(0) {}


//충돌 감지
bool DCollisionDetector::detectCollision()
{
    DVector2i n = B->pos - A->pos;

    float aExtentX = (A->aabb.max.x - A->aabb.min.x) / 2;
    float bExtentX = (B->aabb.max.x - B->aabb.min.x) / 2;
    float xOverlap = aExtentX + bExtentX - ((n.x < 0) ? -n.x : n.x);

    if (xOverlap > 0) {
        float aExtentY = (A->aabb.max.y - A->aabb.min.y) / 2;
        float bExtentY = (B->aabb.max.y - B->aabb.min.y) / 2;
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

//충돌 해결
void DCollisionDetector::ResolveCollision(DCollisionData a, DCollisionData b)
{
    DVector2i rv = b.velocity - a.velocity;
    float velAlongNormal = rv.x * normal.x + rv.y * normal.y; //내적 계산
    if (velAlongNormal > 0)
        return;
    float e = a.restitution < b.restitution ? a.restitution : b.restitution;
    float j = -(1 + e) * velAlongNormal;
    j /= 1 / a.mass + 1 / b.mass; // 충격 후 속도변화에 적용될 충격량
    DVector2i impulse = DVector2i(normal.x * j, normal.y * j);
    a.velocity.x -= (1 / a.mass) * impulse.x;
    a.velocity.y -= (1 / a.mass) * impulse.y;
    b.velocity.x += (1 / b.mass) * impulse.x;
    b.velocity.y += (1 / b.mass) * impulse.y;
}