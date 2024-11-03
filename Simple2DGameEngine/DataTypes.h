#pragma once


template <class MemberType>
struct DArray
{
public:
	DArray();
	DArray(int capacity);
	~DArray();

private:
	MemberType* members;
	int capacity;

public:
	MemberType operator [](int value);
	int GetCapacity();

};

