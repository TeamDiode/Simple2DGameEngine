#include "DataTypes.h"


template<class MemberType>
DArray<MemberType>::DArray()
{
	members = new MemberType[0];
}

template<class MemberType>
DArray<MemberType>::DArray(int capacity)
{
	members = new MemberType[capacity];
}

template<class MemberType>
DArray<MemberType>::~DArray()
{
	delete[] members;
}

template<class MemberType>
MemberType DArray<MemberType>::operator[](int value)
{
	return members[value];
}

template<class MemberType>
int DArray<MemberType>::GetCapacity()
{
	return capacity;
}
