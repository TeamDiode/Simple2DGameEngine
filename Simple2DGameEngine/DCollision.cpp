#include "DCollision.h"
#include "DCollisionData.h"
#include "DEngine.h"
#include "DMathTypes.h"
#include <string>

DCollisionDetector::DCollisionDetector(DCollisionData* objectA, DCollisionData* objectB)
    : a(objectA), b(objectB), normal(0, 0), penetration(0) {}


//충돌 감지
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

// AABB-AABB 충돌 감지
bool DCollisionDetector::DetectAABBCollision()
{

    DVector2i n = b->GetLocation() - a->GetLocation();

    //float num = b->GetLocation().x;
    //std::string commend = std::to_string(num);
    //DEngine::LogMessageBox(commend.c_str());

    //float num2 = a->GetLocation().x;
    //std::string commend2 = std::to_string(num2);
    //DEngine::LogMessageBox(commend2.c_str());


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
    float radiusA = a->GetScale().x / 2.0f;
    float radiusB = b->GetScale().x / 2.0f;
    float radiusSum = radiusA + radiusB;

    float distanceSquared = n.x * n.x + n.y * n.y; // 거리 제곱 계산
    if (distanceSquared < radiusSum * radiusSum) // 원 충돌 확인
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

    DCollisionData* circle = (a->shape == Shape::Circle) ? a : b; // 원 체크
    DCollisionData* rect = (circle == a) ? b : a; // 사각형 체크

    DVector2i circleCenter = circle->GetLocation(); // 원의 중심
    float radius = circle->GetScale().x / 2.0f; // 반지름 계산

    // 직사각형의 가장 가까운 점 계산
    float closestX = rect->aabb.min.x > circleCenter.x ? rect->aabb.min.x : (rect->aabb.max.x < circleCenter.x ? rect->aabb.max.x : circleCenter.x);
    float closestY = rect->aabb.min.y > circleCenter.y ? rect->aabb.min.y : (rect->aabb.max.y < circleCenter.y ? rect->aabb.max.y : circleCenter.y);

    // 원/직사각형의 가장 가까운 점 사이의 거리 제곱
    DVector2i difference = circleCenter - DVector2i(closestX, closestY);
    float distanceSquared = difference.x * difference.x + difference.y * difference.y;

    // 충돌 여부
    if (distanceSquared < radius * radius) {
        penetration = radius * radius - distanceSquared;
        normal = difference;

        return true;
    }

    return false;
}


