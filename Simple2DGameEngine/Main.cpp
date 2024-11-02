/*
* ===[���� ����]=========================================
* ���� ������ : 2024/11/02
*
*/


// ���
#include <windows.h>

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

	ShowWindow(windowHandle, commandShowAmount);
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

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

	case WM_KEYDOWN: // Ű �Է�

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
	

}