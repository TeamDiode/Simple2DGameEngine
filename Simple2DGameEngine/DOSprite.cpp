#include "DOSprite.h"
#include "DRenderer.h"
#include "DObject.h"
#include "DMathTypes.h"
#include <Windows.h>

#define LEFT GetLocation().x - GetScale().x / 2
#define RIGHT GetLocation().x + GetScale().x / 2
#define TOP GetLocation().y - GetScale().y / 2
#define BOTTOM GetLocation().y + GetScale().y / 2

DOSprite::DOSprite()
{
	type = 1;
}

DOSprite::DOSprite(int newType)
{
	type = newType;
	DRenderer::RegisterSprite(this);
}

DVector2i DOSprite::GetLeftTopPosition()
{
	//left
	position.x = LEFT * cos(GetAngle()) - TOP * sin(GetAngle());
	//top
	position.y = LEFT * sin(GetAngle()) + TOP * cos(GetAngle());

	return position;
}

DVector2i DOSprite::GetLeftBottomPosition()
{
	//left
	position.x = LEFT * cos(GetAngle()) - BOTTOM * sin(GetAngle());
	//bottom
	position.y = LEFT * sin(GetAngle()) + BOTTOM * cos(GetAngle());

	return position;
}

DVector2i DOSprite::GetRightTopPosition()
{
	//right
	position.x = RIGHT * cos(GetAngle()) - TOP * sin(GetAngle());
	//top
	position.y = RIGHT * sin(GetAngle()) + TOP * cos(GetAngle());

	return position;
}

DVector2i DOSprite::GetRightBottomPosiiton()
{
	//right
	position.x = RIGHT * cos(GetAngle()) - BOTTOM * sin(GetAngle());
	//bottom
	position.y = RIGHT * sin(GetAngle()) + BOTTOM * cos(GetAngle());

	return position;
}

int DOSprite::GetType()
{
	return type;
}