#pragma once

#include "EDkeyCodeEnum.h"
#define LEN 10

class DInputManager {
private:
	static bool isLockDownBuffer;
	static bool isLockUpBuffer;

	static EDkeyCode keyDownBuffer[LEN];
	static EDkeyCode keyUpBuffer[LEN];
	static EDkeyCode keyAnyBuffer[LEN];

	static void BufferAddAny(EDkeyCode k);
public:
	static void BufferAddUp(EDkeyCode k); // 
	static void BufferAddDown(EDkeyCode k);

	const static bool GetKeyDown(EDkeyCode k); 
	const static bool GetKey(EDkeyCode k); 
	const static bool GetKeyUp(EDkeyCode k); 

	static void Init();
	static void Start();
};