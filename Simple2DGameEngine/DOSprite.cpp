#include "DOSprite.h"
#include "DRenderer.h"
#include "DObject.h"
#include "DMathTypes.h"
#include <Windows.h>

#define PI 3.14

#define LEFT (GetLocation().x - GetScale().x / 2)
#define RIGHT (GetLocation().x + GetScale().x / 2)
#define TOP (GetLocation().y - GetScale().y / 2)
#define BOTTOM (GetLocation().y + GetScale().y / 2)

DOSprite::DOSprite()
{
    type = 1;
    angleInRadian = GetAngle() * (PI / 180.0f);
    DRenderer::RegisterSprite(this);
}

DOSprite::DOSprite(int newType)
{
    type = newType;
    angleInRadian = GetAngle() * (PI / 180.0f);
    DRenderer::RegisterSprite(this);
}

DVector2i DOSprite::GetRotatedPosition(float x, float y)
{
    DVector2i center = GetLocation();

    //변경된 x
    int rotatedX = center.x + ((x - center.x) * cos(angleInRadian) - (y - center.y) * sin(angleInRadian));
    //변경된 y
    int rotatedY = center.y + ((x - center.x) * sin(angleInRadian) + (y - center.y) * cos(angleInRadian));
    
    return DVector2i(rotatedX, rotatedY);
}

DVector2i DOSprite::GetLeftTopPosition()
{
    return GetRotatedPosition(LEFT, TOP);
}

DVector2i DOSprite::GetLeftBottomPosition()
{
    return GetRotatedPosition(LEFT, BOTTOM);
}

DVector2i DOSprite::GetRightTopPosition()
{
    return GetRotatedPosition(RIGHT, TOP);
}

DVector2i DOSprite::GetRightBottomPosiiton()
{
    return GetRotatedPosition(RIGHT, BOTTOM);
}

int DOSprite::GetType()
{
    return type;
}
