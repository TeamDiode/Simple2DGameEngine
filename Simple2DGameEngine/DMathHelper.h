#pragma once

#define PI		3.1415926535897932384
#define Rad2Deg 0.01745329251
#define Deg2Rad 57.2957795131

class DMathHelper
{
public:
	/// <summary>
	/// �Ķ���� �� �� ���� ���� ��ȯ�մϴ�.
	/// </summary>
	static float Min(float a, float b);
	/// <summary>
	/// �Ķ���� �� �� �� ū ���� ��ȯ�մϴ�.
	/// </summary>
	static float Max(float a, float b);
	/// <summary>
	/// �Ķ���� a�� max���� ũ�ٸ� max ����, min���� �۴ٸ� min ����, ���̰��̶�� a ���� ��ȯ�մϴ�.
	/// </summary>
	static float Clamp(float a, float min, float max);
	
	/// <summary>
	/// �ﰢ�Լ� Sin
	/// </summary>
	/// <param name="val">���� ���� ����մϴ�.</param>
	static float Sin(float val);
	/// <summary>
	/// �ﰢ�Լ� Cos
	/// </summary>
	/// <param name="val">���� ���� ����մϴ�.</param>
	static float Cos(float val);
	/// <summary>
	/// �ﰢ�Լ� Tan
	/// </summary>
	/// <param name="val">���� ���� ����մϴ�.</param>
	static float Tan(float val);

	/// <summary>
	/// ���ﰢ�Լ� Asin
	/// </summary>
	/// <param name="val">���� ���� ����մϴ�.</param>
	static float Asin(float val);
	/// <summary>
	/// ���ﰢ�Լ� Acos
	/// </summary>
	/// <param name="val">���� ���� ����մϴ�.</param>
	static float Acos(float val);
	/// <summary>
	/// ���ﰢ�Լ� Atan
	/// </summary>
	/// <param name="val">���� ���� ����մϴ�.</param>
	static float Atan(float val);


};

