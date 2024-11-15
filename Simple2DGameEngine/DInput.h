#pragma once

#include "EDkeyCodeEnum.h"
#define LEN 10
#define MOUSE_INPUT_TYPE 2 // 0 = L  1 = R   Temp=2

class DInputManager {
private:
	static bool isLockDownBuffer;
	static bool isLockUpBuffer;

	static bool mouseUpBuffer[MOUSE_INPUT_TYPE];
	static bool mouseDownBuffer[MOUSE_INPUT_TYPE];
	static bool mouseAnyBuffer[MOUSE_INPUT_TYPE];

	static EDkeyCode keyDownBuffer[LEN];
	static EDkeyCode keyUpBuffer[LEN];
	static EDkeyCode keyAnyBuffer[LEN];

	static const EDkeyCode TrueValueReturn(EDkeyCode e);

	static void BufferAddKeyAny(EDkeyCode k);
	static void BufferAddMouseAny(int i);
public:
	static void BufferAddKeyUp(EDkeyCode k); // 
	static void BufferAddKeyDown(EDkeyCode k);

	static void BufferAddMouseUP(int i);
	static void BufferAddMouseDown(int i);


	const static bool GetKeyDown(EDkeyCode k); 
	const static bool GetKey(EDkeyCode k); 
	const static bool GetKeyUp(EDkeyCode k); 

	const static bool GetMouseButtonDown(int i) { return (MOUSE_INPUT_TYPE > i && i > 0) ? mouseDownBuffer[i] : false; }
	const static bool GetMouseButtonUp(int i) { return (MOUSE_INPUT_TYPE > i && i > 0) ? mouseUpBuffer[i] : false; }
	const static bool GetMouseButton(int i) { return (MOUSE_INPUT_TYPE > i && i > 0) ? mouseAnyBuffer[i] : false; }

	static void Init();
	static void Start();
};