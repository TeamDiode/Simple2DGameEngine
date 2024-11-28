#pragma once
#include "DMathTypes.h"
#include "EDkeyCodeEnum.h"
#include "DSubSystem.h"
#define LEN 10
#define MOUSE_INPUT_TYPE 2 // 0 = L  1 = R   Temp=2

class DInputManager : public DSubSystem {
private:
	static bool isLockDownBuffer;
	static bool isLockUpBuffer;

	static DVector2i mousePostion;

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

	const static DVector2i GetMousePostion() { return mousePostion; }
	static void MouseMove(DVector2i v) { mousePostion = v; }

	static void Init();
	static void Start();
	virtual void Tick(double deltaTime);
};