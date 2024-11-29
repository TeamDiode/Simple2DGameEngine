#pragma once


class IDSubSystem
{
public:
	virtual void Tick(double deltaTime) = 0;
};