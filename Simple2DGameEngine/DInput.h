#pragma once
#include "DMathTypes.h"
#include "EDkeyCodeEnum.h"

#define LEN 7
#define MOUSE_INPUT_TYPE 2 // 0 = L  1 = R   Temp=2

class DInputManager {
private:
	static bool isLockDownBuffer;
	static bool isLockUpBuffer;

	static DVector2i mousePostion;

	static bool mouseUpBuffer[2][MOUSE_INPUT_TYPE];
	static bool mouseDownBuffer[2][MOUSE_INPUT_TYPE];
	static bool mouseAnyBuffer[MOUSE_INPUT_TYPE];

	static EDkeyCode keyDownBuffer[2][LEN];
	static EDkeyCode keyUpBuffer[2][LEN];
	static EDkeyCode keyAnyBuffer[LEN];

	static void BufferAddKeyAny(EDkeyCode keyValue);
public:
	static void BufferAddKeyUp(EDkeyCode keyValue); // 
	static void BufferAddKeyDown(EDkeyCode keyValue);

	static void BufferAddMouseUP(int i);
	static void BufferAddMouseDown(int i);

	const static bool GetKeyDown(EDkeyCode keyValue);
	const static bool GetKey(EDkeyCode keyValue);
	const static bool GetKeyUp(EDkeyCode keyValue);

	const static bool GetMouseButtonDown(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseDownBuffer[0][i] : false; }
	const static bool GetMouseButtonUp(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseUpBuffer[0][i] : false; }
	const static bool GetMouseButton(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseAnyBuffer[i] : false; }

	const static DVector2i GetMousePostion() { return mousePostion; }
	static void SetMousePostion(DVector2i moveVector2) { mousePostion = moveVector2; }
	

	static void Init();
};