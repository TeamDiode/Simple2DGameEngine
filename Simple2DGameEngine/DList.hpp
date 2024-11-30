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
	bool IsEmpty();

	void operator=(const DList<MemberType>& copy);
};
/// <summary>
/// List를 생성합니다.
/// </summary>
template<typename MemberType>
DList<MemberType>::DList()
{
	currentIterator = nullptr;
	size = 0;
}
/// <summary>
/// List를 생성하고 매개변수 value를 size만큼 삽입합니다.
/// </summary>
template<typename MemberType>
DList<MemberType>::DList(MemberType value, int size) : DList()
{
	for (int i = 0; i < size; i++)
	{
		AddNext(value);
		Move();
	}
}

template<typename MemberType>
DList<MemberType>::DList(const DList<MemberType>& copy) : DList()
{
	DIterator<MemberType>* copyIterator = copy.currentIterator;
	for (int i = 0; i < copy.size; i++)
	{
		this->AddNext(copyIterator->currentValue);
		copyIterator = copyIterator->next;
		Move();
	}
}

template<typename MemberType>
DList<MemberType>::~DList()
{
	while (RemoveHere());
}
/// <summary>
/// 리스트의 크기를 반환합니다.
/// </summary>
template<typename MemberType>
int DList<MemberType>::GetSize()
{
	return size;
}
/// <summary>
/// 매개변수 isNext 값이 true일 경우 뒤로 false의 경우 뒤로 이동합니다.
/// </summary>
template<typename MemberType>
bool DList<MemberType>::Move(bool isNext)
{
	if (IsEmpty()) return false;

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
/// <summary>
/// 현재 방문하고 있는 위치의 값을 반환합니다.
/// </summary>
template<typename MemberType>
MemberType DList<MemberType>::GetValue()
{
return currentIterator->currentValue;
}
/// <summary>
/// 현재 방분하고 있는 위치의 뒤에 value을 삽입합니다.
/// </summary>
/// <returns>현재 위치의 주소를 반환합니다.</returns>
template<typename MemberType>
DIterator<MemberType>* DList<MemberType>::AddNext(MemberType value)
{
	if (IsEmpty())
	{
		currentIterator = new DIterator<MemberType>(value, nullptr, nullptr);
		currentIterator->next = currentIterator;
		currentIterator->previous = currentIterator;
	}
	else
	{
		currentIterator->next = new DIterator<MemberType>(value, currentIterator, currentIterator->next);
		currentIterator->next->next->previous = currentIterator->next;
	}
	
	size++;

	return currentIterator;
}
/// <summary>
/// 현재 방문하고 있는 위치의 데이터를 삭제하고 다음으로 이동합니다.
/// 삭제 불가능할 시 false값을 반환합니다.
/// </summary>
/// <returns>삭제 성공 여부</returns>
template<typename MemberType>
bool DList<MemberType>::RemoveHere()
{
	if (IsEmpty()) return false;

	Move();

	if(currentIterator != currentIterator->previous)
		delete currentIterator->previous;
	else
		delete currentIterator;

	size--;
	return true;
}
/// <summary>
/// 리스트가 비어있는지 확인합니다.
/// </summary>
template<typename MemberType>
inline bool DList<MemberType>::IsEmpty()
{
	return size == 0;
}

template<typename MemberType>
void DList<MemberType>::operator=(const DList<MemberType>& copy)
{
	while (RemoveHere());

	DIterator<MemberType>* copyIterator = copy.currentIterator;
	for (int i = 1; i < copy.size; i++)
	{
		this->AddNext(copyIterator->currentValue);
		copyIterator = copyIterator->next;
		Move();
	}
}