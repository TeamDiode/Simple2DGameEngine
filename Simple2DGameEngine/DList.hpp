#pragma once

template<typename MemberType>
struct DIterator
{
public:
	DIterator();
	DIterator(MemberType value, DIterator<MemberType>* previousIterator, DIterator<MemberType>* nextIterator);
	~DIterator();

	MemberType currentValue;
	DIterator<MemberType>* previous;
	DIterator<MemberType>* next;
};

template<typename MemberType>
DIterator<MemberType>::DIterator()
{
	currentValue = MemberType();
	previous = this;
	next = this;
}

template<typename MemberType>
DIterator<MemberType>::DIterator(MemberType value, DIterator<MemberType>* previousIterator, DIterator<MemberType>* nextIterator)
{
	currentValue = value;
	previous = previousIterator;
	next = nextIterator;
}

template<typename MemberType>
DIterator<MemberType>::~DIterator()
{
	if (previous != this) previous->next = next;
	if (next != this) next->previous = previous;
}

template<typename MemberType>
struct DList
{
public:
	DList();
	DList(MemberType value, int size = 1);

private:
	DIterator<MemberType>* currentIterator;
	int size;

public:
	int GetSize();
	bool Move(bool isNext = true);
	MemberType GetValue();
	DIterator<MemberType>* AddNext(MemberType value);
	bool RemoveHere();

};

template<typename MemberType>
DList<MemberType>::DList()
{
	currentIterator = new DIterator<MemberType>();
	size = 1;
}

template<typename MemberType>
DList<MemberType>::DList(MemberType value, int size) : DList()
{
	currentIterator->currentValue = value;

	for (int i = 1; i < size; i++)
	{
		AddNext(value);
		Move();
	}
}

template<typename MemberType>
int DList<MemberType>::GetSize()
{
	return size;
}

template<typename MemberType>
bool DList<MemberType>::Move(bool isNext)
{
	bool isSuccess = true;
	DIterator<MemberType>* iterator;

	if (isNext)
	{
		iterator = currentIterator->next;
	}
	else
	{
		iterator = currentIterator->previous;
	}
	isSuccess = iterator != nullptr;

	if (isSuccess) currentIterator = iterator;

	return isSuccess;
}

template<typename MemberType>
MemberType DList<MemberType>::GetValue()
{
	return currentIterator->currentValue;
}

template<typename MemberType>
DIterator<MemberType>* DList<MemberType>::AddNext(MemberType value)
{
	DIterator<MemberType>* newIterator = new DIterator<MemberType>(value, currentIterator, currentIterator->next);
	currentIterator->next->previous = newIterator;
	currentIterator->next = newIterator;
	size++;

	return currentIterator;
}

template<typename MemberType>
bool DList<MemberType>::RemoveHere()
{
	bool isSuccess = Move() && (currentIterator != currentIterator->previous);

	if (isSuccess)
	{
		delete currentIterator->previous;
		size--;
	}

	return isSuccess;
}
