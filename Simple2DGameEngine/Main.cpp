/*
* ===[¼öÁ¤ Á¤º¸]=========================================
* ÃÖÁ¾ ¼öÁ¤ÀÏ : 2024/11/02
*
*/


// Çì´õ
#include <windows.h>

// Ã¢ ½ÃÀÛ Å©±â
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DefaultFrameLate 60

LRESULT CALLBACK OnWindowProcedure(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR windowShowName = TEXT("Engine");


// ¸ÞÀÎ
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


// ±âº» À©µµ¿ì ÇÁ·Î¼¼½º ÄÝ¹é ÇÔ¼ö
LRESULT CALLBACK OnWindowProcessed(HWND windowHandle, UINT messageFlag, WPARAM wordParameter,
// ï¿½âº» ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Î½ï¿½ï¿½ï¿½ ï¿½Ý¹ï¿½ ï¿½Ô¼ï¿½
LRESULT CALLBACK OnWindowProcedure(HWND windowHandle, UINT messageFlag, WPARAM wordParameter,
	LPARAM pointerParameter)
{

	switch (messageFlag)
	{
	case WM_CREATE: // ÃÖÃÊ »ý¼º
		SetTimer(windowHandle, 1, 1000 / DefaultFrameLate, NULL);

		break;

	case WM_TIMER: // À©µµ¿ì Å¸ÀÌ¸Ó Æ½

		break;

	case WM_KEYDOWN: // Å° ÀÔ·Â

		break;

	case WM_PAINT: // ±×¸®±â

		break;

	case WM_DESTROY: // Á¾·á
		PostQuitMessage(0);
		KillTimer(windowHandle, 1);

		break;
	}

	return (DefWindowProc(windowHandle, messageFlag, wordParameter, pointerParameter));
}