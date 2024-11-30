#pragma once

#include <Windows.h>
#include <ctime>
#include "DObjectManager.h"
#include "DRenderer.h"
#include "DSingleton.hpp"
#include "DInput.h"
#include "DWorld.h"
#include "DPhysicsManager.h"
#include "DSubSystem.h"
#include "DAutoPointer.hpp"

class DEngine
{
public:
	DEngine(HWND windowHandle);
	~DEngine();

	
private:
	// 현재 엔진이 구동되는 윈도우 핸들
	static HWND currentWindowHandle;
	// 시작 세계
	DWorld startWorld;

public:
	// 윈도우 메세지 박스 형태의 로그 출력
	static void LogMessageBox(LPCSTR log);

private:
	// 매니저 로직을 동작시키는 스레드의 시작 루틴 함수
	template<class SubSystemClass>
	static DWORD WINAPI ProcessSubSystemThread(LPVOID subSystemClass)
	{
		// 현재 시간을 나타내는 클락. 단위는 ms
		clock_t currentTime = clock();
		// 이전 틱의 수행시간. 단위는 s
		double daltaTime = 0;
		// 매개변수로 받은 서브시스템 캐스트
		IDSubSystem* subSystemInstance = dynamic_cast<IDSubSystem*>((SubSystemClass*)subSystemClass);

		// 매개변수 관련 에러처리
		if (subSystemClass == nullptr)
		{
			DEngine::LogMessageBox("스레드 생성 실패");

			return 0;
		}

		// 서브시스템 틱
		while (true)
		{
			// 이전 틱의 수행시간 계산
			daltaTime = (clock() - currentTime) / (double)CLOCKS_PER_SEC;
			// 현재 시간 갱신
			currentTime = clock();
			// 서브시스템의 틱 호출
			subSystemInstance->Tick(daltatime);
		}

		return 0;
	}

	// 매니저 클래스와 우선순위를 받아 매니저 스레드를 생성 및 시작
	template<class SubSystemClass>
	void CreateSubSystemThread(IDSubSystem* subSystemClass, int threadPriority)
	{
		DWORD newThreadID;
		// 스래드 생성
		HANDLE newThreadHandle = CreateThread(NULL, 0, ProcessSubSystemThread<SubSystemClass>, subSystemClass, 0, &newThreadID);
		// 우선순위 조정
		if (newThreadHandle != NULL) SetThreadPriority(newThreadHandle, threadPriority);
	}
};
