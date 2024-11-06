#pragma once


template<typename MemberType>
class IDIterator
{
public:
	virtual void MoveNext() = 0;
	virtual MemberType GetValue() = 0;
};
