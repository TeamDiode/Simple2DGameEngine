#pragma

template<typename ClassName>
class Singleton
{
public:
	Singleton();
	~Singleton();

private:
	static ClassName* instance;

public:
	static ClassName* GetInstance();
};

template<typename ClassName>
Singleton<ClassName>::Singleton()
{
	instance = this;
}

template<typename ClassName>
Singleton<ClassName>::~Singleton()
{
}

template<typename ClassName>
ClassName* Singleton<ClassName>::GetInstance()
{
	// ��ü�� �� �������� ����
	return instance;
}
