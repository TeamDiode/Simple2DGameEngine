#pragma once



class DEngine
{
public:
	DEngine();
	~DEngine();

	
private:
	// 오브젝트 관리자
	// 물리 처리
	// 서브 시스템
	// 랜더러

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

