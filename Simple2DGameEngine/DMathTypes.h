#pragma once
#include <iostream>
#include <cmath>

struct DVector2i
{
public:
	DVector2i();
	DVector2i(int x, int y);

public:
	// x ¿ø¼Ò
	int x;
	// y ¿ø¼Ò
	int y;

public:
	// º¤ÅÍ µ¡¼À
	DVector2i operator +(DVector2i value);
	// º¤ÅÍ »¬¼À
	DVector2i operator -(DVector2i value);
	// ½ºÄ®¶ó °ö
	DVector2i operator *(int value);
	/// <summary>
	/// µÎ º¤ÅÍ°£ °Å¸®¸¦ ±¸ÇÕ´Ï´Ù.
	/// </summary>
	static float Distance(DVector2i value1, DVector2i value2);
	
};
