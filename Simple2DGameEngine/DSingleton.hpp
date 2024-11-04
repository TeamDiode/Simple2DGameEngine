#pragma

template<typename ClassName>
class DSingleton
{
public:
	DSingleton();
	~DSingleton();

private:
	static ClassName* instance;

public:
	static ClassName* GetInstance();
};

template<typename ClassName>
DSingleton<ClassName>::DSingleton()
{
	if (instance == nullptr)
	{
		instance = this;
	}
}

template<typename ClassName>
DSingleton<ClassName>::~DSingleton()
{
}

template<typename ClassName>
ClassName* DSingleton<ClassName>::GetInstance()
{
	// ��ü�� �� �������� ����
	return instance;
}
