#pragma


template<typename MemberType>
struct DIterator
{
public:
	DIterator();
	DIterator(MemberType value, MemberType* previousIterator, MemberType* nextIterator);
	~DIterator();

	MemberType currentValue;
	DIterator<MemberType>* previous;
	DIterator<MemberType>* next;
};

template<typename MemberType>
DIterator<MemberType>::DIterator()
{
	currentValue = MemberType();
}

template<typename MemberType>
DIterator<MemberType>::DIterator(MemberType value, MemberType* previousIterator, MemberType* nextIterator)
{
	currentValue = value;
	previous = previousIterator;
	next = nextIterator;
}

template<typename MemberType>
DIterator<MemberType>::~DIterator()
{
	previous->next = next;
	next->previous = previous;
}

template<typename MemberType>
struct DList
{
public:
	DList();
	DList(MemberType value, int size = 1);
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

};

template<typename MemberType>
DList<MemberType>::DList()
{
	currentIterator = new DIterator<MemberType>(MemberType(), nullptr, nullptr);
	currentIterator->next = currentIterator;
	currentIterator->previous = currentIterator;
	size = 1;
}

template<typename MemberType>
DList<MemberType>::DList(MemberType value, int size) : DList()
{
	currentIterator->currentValue = value;

	for (int i = 1; i < value; i++)
	{
		AddNext();
		Move();
	}
}

template<typename MemberType>
DList<MemberType>::~DList()
{
	while (Move())
	{
		delete currentIterator->previous;
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
	currentIterator->next = new DIterator<MemberType>(value, currentIterator, currentIterator->next);
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
	}
}
