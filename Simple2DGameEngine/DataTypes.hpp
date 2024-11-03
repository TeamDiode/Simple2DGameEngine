#pragma once


template <typename MemberType>
struct DArray
{
public:
	DArray();
	DArray(int capacity);
	~DArray();

protected:
	MemberType* members;
	int capacity;

public:
	MemberType& operator [](int value);
	int GetCapacity();

};

template<typename MemberType>
DArray<MemberType>::DArray()
{
	members = new MemberType[0];
}

template<typename MemberType>
DArray<MemberType>::DArray(int capacity)
{
	members = new MemberType[capacity];
}

template<typename MemberType>
DArray<MemberType>::~DArray()
{
	delete[] members;
}

template<typename MemberType>
MemberType& DArray<MemberType>::operator[](int value)
{
	return members[value];
}

template<typename MemberType>
int DArray<MemberType>::GetCapacity()
{
	return capacity;
}
