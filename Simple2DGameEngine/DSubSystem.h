#pragma once


class DSubSystem
{
public:
	DSubSystem();
	~DSubSystem();

public:
	virtual void Tick(double deltaTime);
};