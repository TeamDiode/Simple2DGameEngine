#pragma once

template<typename ClassName>
class DSingleton
{
public:
	DSingleton();
	~DSingleton();

public:
	static ClassName& GetInstance();
};


template<typename ClassName>
DSingleton<ClassName>::DSingleton()
{
	
}

template<typename ClassName>
DSingleton<ClassName>::~DSingleton()
{
}

template<typename ClassName>
ClassName& DSingleton<ClassName>::GetInstance()
{
	static DSingleton<ClassName> instance;
	return instance;
}
