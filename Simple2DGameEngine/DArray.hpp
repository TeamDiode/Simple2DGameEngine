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
	int size;
	int capacity;

public:
	int GetSize();
	int GetCapacity();
	void Add(MemberType newValue);
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
int DArray<MemberType>::GetSize()
{
	return size;
}

template<typename MemberType>
int DArray<MemberType>::GetCapacity()
{
	return capacity;
}

template<typename MemberType>
void DArray<MemberType>::Add(MemberType newValue)
{
	this[size++] = newValue;
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
