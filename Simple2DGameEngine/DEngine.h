#pragma once



class DEngine
{
public:
	DEngine();
	~DEngine();

	
private:
	// ������Ʈ ������
	// ���� ó��
	// ���� �ý���
	// ������

public:
	// ƽ���� ó���ϴ� ���� ���μ���
	void ProcessTick();

	// ������Ʈ ó��
	void ProcessObject();
	// ���� ó��
	void ProcessPhysics();
	// ���� ���� ó��
	void ProcessGameLogic();
	// ��� ó��
	void ProcessDisplay();

};

