#pragma once

#define PI		3.1415926535897932384
#define Rad2Deg 0.01745329251
#define Deg2Rad 57.2957795131

class DMathHelper
{
public:
	/// <summary>
	/// 파라미터 값 중 작은 값을 반환합니다.
	/// </summary>
	static float Min(float a, float b);
	/// <summary>
	/// 파라미터 값 중 더 큰 값을 반환합니다.
	/// </summary>
	static float Max(float a, float b);
	/// <summary>
	/// 파라미터 a가 max보다 크다면 max 값을, min보다 작다면 min 값을, 사이값이라면 a 값을 반환합니다.
	/// </summary>
	static float Clamp(float a, float min, float max);
	
	/// <summary>
	/// 삼각함수 Sin
	/// </summary>
	/// <param name="val">라디안 값을 사용합니다.</param>
	static float Sin(float val);
	/// <summary>
	/// 삼각함수 Cos
	/// </summary>
	/// <param name="val">라디안 값을 사용합니다.</param>
	static float Cos(float val);
	/// <summary>
	/// 삼각함수 Tan
	/// </summary>
	/// <param name="val">라디안 값을 사용합니다.</param>
	static float Tan(float val);

	/// <summary>
	/// 역삼각함수 Asin
	/// </summary>
	/// <param name="val">라디안 값을 사용합니다.</param>
	static float Asin(float val);
	/// <summary>
	/// 역삼각함수 Acos
	/// </summary>
	/// <param name="val">라디안 값을 사용합니다.</param>
	static float Acos(float val);
	/// <summary>
	/// 역삼각함수 Atan
	/// </summary>
	/// <param name="val">라디안 값을 사용합니다.</param>
	static float Atan(float val);


};

