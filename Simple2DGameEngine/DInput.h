#pragma once
#include "DMathTypes.h"
#include "EDkeyCodeEnum.h"
#include "DSubSystem.h"

//#include "DEngine.h"

#define LEN 10
#define MOUSE_INPUT_TYPE 2 // 0 = L  1 = R   Temp=2

class DInputManager : public IDSubSystem {
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

	static void BufferAddKeyAny(EDkeyCode keyValue);
public:
	static void BufferAddKeyUp(EDkeyCode keyValue); // 
	static void BufferAddKeyDown(EDkeyCode keyValue);

	static void BufferAddMouseUP(int i);
	static void BufferAddMouseDown(int i);

	const static bool GetKeyDown(EDkeyCode keyValue);
	const static bool GetKey(EDkeyCode keyValue);
	const static bool GetKeyUp(EDkeyCode keyValue);

	const static bool GetMouseButtonDown(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseDownBuffer[i] : false; }
	const static bool GetMouseButtonUp(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseUpBuffer[i] : false; }
	const static bool GetMouseButton(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseAnyBuffer[i] : false; }

	const static DVector2i GetMousePostion() { return mousePostion; }
	static void SetMousePostion(DVector2i moveVector2) { mousePostion = moveVector2; }
	

	static void Init();
	static void Start();
	virtual void Tick(double deltaTime) override;
};