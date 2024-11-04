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
	// 물리 처리
	// 서브 시스템
	DRenderer renderer;

public:
	// 틱마다 처리하는 엔진 프로세스
	void ProcessTick();

	// 오브젝트 처리
	void ProcessObject();
	// 물리 처리
	void ProcessPhysics();
	// 게임 로직 처리
	void ProcessGameLogic();
	// 출력 처리
	void ProcessDisplay();

};

