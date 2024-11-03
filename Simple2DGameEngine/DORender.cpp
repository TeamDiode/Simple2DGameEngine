#include "DORender.h"
#include "DObject.h"
#include "DMathTypes.h"
#include <Windows.h>

DORender::DORender(int newType)
{
	type = newType;
}

DORender::~DORender()
{
}

int DORender::GetObjectType()
{
	return type;
}

int DORender::GetLeft()
{
	return GetLocation().x - GetScale().x / 2;
}

int DORender::GetRight()
{
	return GetLocation().x + GetScale().x / 2;
}

int DORender::GetTop()
{
	return GetLocation().y - GetScale().y / 2;
}

int DORender::GetBottom()
{
	return GetLocation().y + GetScale().y / 2;
}