#include "DOSprite.h"
#include "DRenderer.h"
#include "DObject.h"
#include "DMathTypes.h"
#include <Windows.h>

DOSprite::DOSprite(int newType)
{
	type = newType;
	DRenderer::GetInstance()->RegisterSprite(this);
}

DOSprite::~DOSprite()
{
}

int DOSprite::GetLeft()
{
	return GetLocation().x - GetScale().x / 2;
}

int DOSprite::GetRight()
{
	return GetLocation().x + GetScale().x / 2;
}

int DOSprite::GetTop()
{
	return GetLocation().y - GetScale().y / 2;
}

int DOSprite::GetBottom()
{
	return GetLocation().y + GetScale().y / 2;
}

int DOSprite::GetType()
{
	return type;
}