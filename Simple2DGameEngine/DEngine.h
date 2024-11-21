#pragma once

#include <Windows.h>
#include "DObjectManager.h"
#include "DRenderer.h"
#include "DSingleton.hpp"
#include "DInput.h"
#include "DWorld.h"
#include "DPhysicsManager.h"

class DEngine
{
public:
	DEngine();
	DEngine(HDC deviceContextHandle);
	~DEngine();

	
private:
	static DEngine* engineInstance;

	DObjectManager objectManager;
	DPhysicsManager physicsManager;
	// 서브 시스템
	DRenderer renderer;

	DWorld startWorld;

public:
	static DEngine* GetInstance();

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
