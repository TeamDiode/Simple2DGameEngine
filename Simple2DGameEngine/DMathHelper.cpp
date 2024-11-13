#include "DMathHelper.h"
#include <cmath>


float DMathHelper::Min(float a, float b)
{
    return a < b ? a : b;
}

float DMathHelper::Max(float a, float b)
{
    return a > b ? a : b;
}

float DMathHelper::Clamp(float a, float min, float max)
{
    if (a > max) return max;
    else if (a < min) return min;
    else return a;
}

float DMathHelper::Sin(float val)
{
    return sin(val);
}

float DMathHelper::Cos(float val)
{
    return cos(val);
}

float DMathHelper::Tan(float val)
{
    return tan(val);
}

float DMathHelper::Asin(float val)
{
    return asin(val);
}

float DMathHelper::Acos(float val)
{
    return acos(val);
}

float DMathHelper::Atan(float val)
{
    return atan(val);
}
