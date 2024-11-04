#pragma once

#include "DObjectManager.h"
#include "DRenderer.h"
#include "DSingleton.hpp"

class DEngine : public DSingleton<DEngine>
{
public:
	DEngine();
	~DEngine();

	
private:
	DObjectManager objectManager;
	// ���� ó��
	// ���� �ý���
	DRenderer renderer;

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

