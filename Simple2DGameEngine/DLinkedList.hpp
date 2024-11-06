#pragma once

#include "IDIterator.hpp"

template<typename MemberType>
class LinkedList : public IDIterator<MemberType>
{
public:
	LinkedList();
	LinkedList(MemberType newValue);
	LinkedList(MemberType newValue, LinkedList* nextNode);
	~LinkedList();

private:
	MemberType value;
	LinkedList* next;

public:
	virtual void MoveNext() override;
	virtual MemberType GetValue() override;

};

template<typename MemberType>
inline LinkedList<MemberType>::LinkedList()
{
	value = MemberType();
}

template<typename MemberType>
inline LinkedList<MemberType>::LinkedList(MemberType newValue)
{
	value = newValue;
}

template<typename MemberType>
inline LinkedList<MemberType>::LinkedList(MemberType newValue, LinkedList* nextNode)
{
}

template<typename MemberType>
inline LinkedList<MemberType>::~LinkedList()
{
}

template<typename MemberType>
inline void LinkedList<MemberType>::MoveNext()
{
}

template<typename MemberType>
inline MemberType LinkedList<MemberType>::GetValue()
{
	return value;
}
