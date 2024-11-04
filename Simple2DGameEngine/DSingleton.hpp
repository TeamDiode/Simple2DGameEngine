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
	// 객체가 비어도 생성하지 않음
	return instance;
}
