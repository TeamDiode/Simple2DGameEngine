#pragma once

#define ADDITIONAL_EXPAND_SIZE 5

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
	int GetCapacity();
	void ReSize(int newCapacity);
	MemberType& operator [](int value);

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
int DArray<MemberType>::GetCapacity()
{
	return capacity;
}

template<typename MemberType>
void DArray<MemberType>::ReSize(int newCapacity)
{
	newCapacity += ADDITIONAL_EXPAND_SIZE;
	MemberType* tempMembers = new MemberType[newCapacity];

	for (int i = 0; i < (capacity < newCapacity ? capacity : newCapacity); i++)
	{
		tempMembers[i] = members[i];
	}
	delete[] members;
	members = tempMembers;
	capacity = newCapacity;
}

template<typename MemberType>
MemberType& DArray<MemberType>::operator[](int value)
{
	if (value > capacity) ReSize(value);
	return members[value];
}
