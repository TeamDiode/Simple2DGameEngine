#pragma once

template<typename MemberType>
struct DAutoPointer
{
public:
	DAutoPointer();
	DAutoPointer(MemberType value);
	DAutoPointer(MemberType* value);
	~DAutoPointer();

private:
	MemberType* data;
public:
	MemberType* GetValue();

	void operator=(const MemberType copy);
	void operator=(const MemberType* copy);
	void operator=(const DAutoPointer<MemberType> copy);
};

template<typename MemberType>
inline DAutoPointer<MemberType>::DAutoPointer()
{
	data = nullptr;
}

template<typename MemberType>
inline DAutoPointer<MemberType>::DAutoPointer(MemberType value)
{
	data = new MemberType(value);
}

template<typename MemberType>
inline DAutoPointer<MemberType>::DAutoPointer(MemberType* value)
{
	data = value;
}

template<typename MemberType>
inline DAutoPointer<MemberType>::~DAutoPointer()
{
	if (data)
		delete data;
}

template<typename MemberType>
inline MemberType* DAutoPointer<MemberType>::GetValue()
{
	return data;
}

template<typename MemberType>
inline void DAutoPointer<MemberType>::operator=(const MemberType copy)
{
	data = new MemberType(copy);
}

template<typename MemberType>
inline void DAutoPointer<MemberType>::operator=(const MemberType* copy)
{
	data = copy;
}

template<typename MemberType>
inline void DAutoPointer<MemberType>::operator=(const DAutoPointer<MemberType> copy)
{
	data = new MemberType(copy.data);
}

