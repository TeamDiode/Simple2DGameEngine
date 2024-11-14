#pragma once

// TODO : 내적과 외적연산 추가

struct DVector2i
{
public:
	DVector2i();
	DVector2i(float x, float y);

public:
	// x 원소
	float x;
	// y 원소
	float y;

public:
	// 벡터 덧셈
	DVector2i operator +(DVector2i value);
	// 벡터 뺄셈
	DVector2i operator -(DVector2i value);
	// 스칼라 곱
	DVector2i operator *(float value);
	
	// 벡터 정규화
	void Normalize();

	// 백터 내적
	float Dot(DVector2i value);
	// 백터 외적
	float Cross(DVector2i value);
};