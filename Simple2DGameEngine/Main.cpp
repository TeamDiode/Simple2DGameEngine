
// 헤더
#include <windows.h>
#include "DEngine.h"
#include "EDkeyCodeEnum.h"
#include "DInput.h"
#include "DMathTypes.h"

// 설정
#define WINDOW_NAME "Engine"
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DefaultFrameLate 60

// 윈도우 프로시저
LRESULT CALLBACK OnWindowProcedure(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR windowShowName = TEXT(WINDOW_NAME);


// 메인, 주 스레드
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

	RECT displayRectangle;
	GetClientRect(windowHandle, &displayRectangle);
	// 엔진 객체 생성
	DEngine engine(windowHandle);

	ShowWindow(windowHandle, commandShowAmount);
	// 윈도우 메세지 처리
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return (int)message.wParam;
}


LRESULT CALLBACK OnWindowProcedure(HWND windowHandle, UINT messageFlag, WPARAM wordParameter,
	LPARAM pointerParameter)
{
	DVector2i mousePostionVector2;
	switch (messageFlag)
	{
	case WM_CREATE: // 윈도우 생성
		mousePostionVector2 = DVector2i(LOWORD(wordParameter), HIWORD(wordParameter));
		DInputManager::SetMousePostion(mousePostionVector2);

		break;

	case WM_KEYDOWN: // Key Down
		DInputManager::BufferAddKeyDown((EDkeyCode)wordParameter);

		break;

	case WM_KEYUP: // Key Up
		DInputManager::BufferAddKeyUp((EDkeyCode)wordParameter);
		
		break;

	case WM_LBUTTONDOWN:
		DInputManager::BufferAddMouseDown(0);

		break;

	case WM_LBUTTONUP:
		DInputManager::BufferAddMouseUP(0);

		break;

	case WM_RBUTTONDOWN:
		DInputManager::BufferAddMouseDown(1);

		break;

	case WM_RBUTTONUP:
		DInputManager::BufferAddMouseUP(1);

		break;

	case WM_MOUSEMOVE:
		mousePostionVector2 = DVector2i((float)LOWORD(pointerParameter), (float)HIWORD(pointerParameter));
		DInputManager::SetMousePostion(mousePostionVector2);

		break;

	case WM_DESTROY: // 윈도우 소멸
		PostQuitMessage(0);

		break;
	}

	return (DefWindowProc(windowHandle, messageFlag, wordParameter, pointerParameter));
}
