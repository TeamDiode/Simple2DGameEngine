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
	if (next != this && previous != this)
	{
		previous->next = next;
		next->previous = previous;
	}
}

template<typename MemberType>
struct DList
{
public:
	DList();
	DList(MemberType value, int size = 1);
	DList(const DList<MemberType>& copy);
	~DList();

private:
	DIterator<MemberType>* currentIterator;
	int size;

public:
	int GetSize();
	bool Move(bool isNext = true);
	MemberType GetValue();
	DIterator<MemberType>* AddNext(MemberType value);
	bool RemoveHere();

	void operator=(const DList<MemberType>& copy);
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
DList<MemberType>::DList(const DList<MemberType>& copy) : DList()
{
	DIterator<MemberType>* copyIterator = copy.currentIterator;
	this->currentIterator->currentValue = copyIterator->currentValue;
	for (int i = 1; i < copy.size; i++)
	{
		copyIterator = copyIterator->next;
		this->AddNext(copyIterator->currentValue);
		Move();
	}
}

template<typename MemberType>
DList<MemberType>::~DList()
{
	while (RemoveHere());

	delete currentIterator;
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
	currentIterator->next = new DIterator<MemberType>(value, currentIterator, currentIterator->next);
	currentIterator->next->next->previous = currentIterator->next;
	size++;

	return currentIterator;
}

template<typename MemberType>
bool DList<MemberType>::RemoveHere()
{
	if (Move() && currentIterator != currentIterator->previous)
	{
		delete currentIterator->previous;
		size--;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename MemberType>
void DList<MemberType>::operator=(const DList<MemberType>& copy)
{
	while (RemoveHere());

	DIterator<MemberType>* copyIterator = copy.currentIterator;
	this->currentIterator->currentValue = copyIterator->currentValue;
	for (int i = 1; i < copy.size; i++)
	{
		copyIterator = copyIterator->next;
		this->AddNext(copyIterator->currentValue);
		Move();
	}
}