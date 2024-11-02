/*
* ===[수정 정보]=========================================
* 최종 수정일 : 2024/11/02
*
*/


// 헤더
#include <windows.h>

// 창 시작 크기
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DefaultFrameLate 60

LRESULT CALLBACK OnWindowProcedure(HWND, UINT, WPARAM, LPARAM);
void CALLBACK OnTimerTickProcedure(HWND, UINT, UINT_PTR, DWORD);
HINSTANCE g_hInst;
LPCTSTR windowShowName = TEXT("Engine");


// 메인
int APIENTRY WinMain(HINSTANCE instanceHandle, HINSTANCE prevInstanceHandle, LPSTR
	commandParameter, int commandShowAmount)
{
	HWND windowHandle;
	MSG message;
	WNDCLASS windowClass;
	g_hInst = instanceHandle;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hInstance = instanceHandle;
	windowClass.lpfnWndProc = OnWindowProcedure;
	windowClass.lpszClassName = windowShowName;
	windowClass.lpszMenuName = NULL;
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&windowClass);
	windowHandle = CreateWindow(windowShowName, windowShowName, WS_OVERLAPPEDWINDOW, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, (HMENU)NULL, instanceHandle, NULL);

	ShowWindow(windowHandle, commandShowAmount);
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (int)message.wParam;
}


// 기본 윈도우 프로시저 콜백 함수
LRESULT CALLBACK OnWindowProcedure(HWND windowHandle, UINT messageFlag, WPARAM wordParameter,
	LPARAM pointerParameter)
{

	switch (messageFlag)
	{
	case WM_CREATE: // 최초 생성
		SetTimer(windowHandle, 1, 1000 / DefaultFrameLate, OnTimerTickProcedure);

		break;

	case WM_TIMER: // 윈도우 타이머 틱

		break;

	case WM_KEYDOWN: // 키 입력

		break;

	case WM_PAINT: // 그리기

		break;

	case WM_DESTROY: // 종료
		PostQuitMessage(0);
		KillTimer(windowHandle, 1);

		break;
	}

	return (DefWindowProc(windowHandle, messageFlag, wordParameter, pointerParameter));
}


void CALLBACK OnTimerTickProcedure(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	

}