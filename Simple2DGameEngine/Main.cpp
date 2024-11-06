/*
* ===[���� ����]=========================================
* ���� ������ : 2024/11/02
*
*/


// ���
#include <windows.h>
#include "DEngine.h"
#include "EDkeyCodeEnum.h"
#include "DInput.h"

// â ���� ũ��
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DefaultFrameLate 60

LRESULT CALLBACK OnWindowProcedure(HWND, UINT, WPARAM, LPARAM);
void CALLBACK OnTimerTickProcedure(HWND, UINT, UINT_PTR, DWORD);
HINSTANCE g_hInst;
LPCTSTR windowShowName = TEXT("Engine");


// ����
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
	DEngine engine(GetDC(windowHandle), displayRectangle);

	ShowWindow(windowHandle, commandShowAmount);
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	DInputManager::Start(); // InputManager ���� �ʱ�ȭ  HAUN
	return (int)message.wParam;
}


// �⺻ ������ ���ν��� �ݹ� �Լ�
LRESULT CALLBACK OnWindowProcedure(HWND windowHandle, UINT messageFlag, WPARAM wordParameter,
	LPARAM pointerParameter)
{

	switch (messageFlag)
	{
	case WM_CREATE: // ���� ����
		SetTimer(windowHandle, 1, 1000 / DefaultFrameLate, OnTimerTickProcedure);
		
		break;

	case WM_TIMER: // ������ Ÿ�̸� ƽ

		break;

	case WM_KEYDOWN: // Key Down  HAUN
		if (EDkeyCode::A <= wordParameter && wordParameter <= EDkeyCode::Z || EDkeyCode::a <= wordParameter && wordParameter <= EDkeyCode::z) {
			DInputManager::BufferAddDown((EDkeyCode)wordParameter);
		}
		break;

	case WM_KEYUP: // Key Up  HAUN
		if(EDkeyCode::A <= wordParameter && wordParameter <= EDkeyCode::Z || EDkeyCode::a <= wordParameter && wordParameter <= EDkeyCode::z){
			DInputManager::BufferAddUp((EDkeyCode)wordParameter);
		}
		break;

	case WM_PAINT: // �׸���

		break;

	case WM_DESTROY: // ����
		PostQuitMessage(0);
		KillTimer(windowHandle, 1);

		break;
	}

	return (DefWindowProc(windowHandle, messageFlag, wordParameter, pointerParameter));
}


void CALLBACK OnTimerTickProcedure(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	DEngine::GetInstance()->ProcessTick();

	DInputManager::Init(); // InputManager Init (CALLBACK Last Func) HAUN
}