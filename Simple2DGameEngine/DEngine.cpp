#include "DEngine.h"


HWND DEngine::currentWindowHandle = NULL;


DEngine::DEngine(HWND windowHandle)
{
	// 현재 위도우 핸들 할당
	currentWindowHandle = windowHandle;
	// 매니저 초기화
	CreateSubSystemThread<DObjectManager>(new DObjectManager(), THREAD_PRIORITY_LOWEST);
	CreateSubSystemThread<DPhysicsManager>(new DPhysicsManager(), THREAD_PRIORITY_NORMAL);
	CreateSubSystemThread<DRenderer>(new DRenderer(GetDC(windowHandle), windowHandle), THREAD_PRIORITY_LOWEST);
	// 시작 세계 불러오기
	startWorld.Load();
}

DEngine::~DEngine()
{
	// 매니저 종료 코드
}

void DEngine::LogMessageBox(LPCSTR log)
{
	if(currentWindowHandle) MessageBoxA(currentWindowHandle, log, NULL, MB_OK);
}
