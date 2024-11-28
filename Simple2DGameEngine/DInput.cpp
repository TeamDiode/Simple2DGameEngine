#pragma warning(disable : 26812)

#include "DInput.h"
#include "EDkeyCodeEnum.h"
#include "DMathTypes.h"

bool DInputManager::isLockDownBuffer = false;
bool DInputManager::isLockUpBuffer = false;
DVector2i DInputManager::mousePostion(0, 0);

EDkeyCode DInputManager::keyDownBuffer[LEN] = { EDkeyCode::null };
EDkeyCode DInputManager::keyUpBuffer[LEN] = { EDkeyCode::null };
EDkeyCode DInputManager::keyAnyBuffer[LEN] = { EDkeyCode::null };
bool DInputManager::mouseUpBuffer[MOUSE_INPUT_TYPE] = { false, };
bool DInputManager::mouseDownBuffer[MOUSE_INPUT_TYPE] = { false, };
bool DInputManager::mouseAnyBuffer[MOUSE_INPUT_TYPE] = { false, };

const EDkeyCode DInputManager::TrueValueReturn(EDkeyCode k)
{
	switch (e) {
	case EDkeyCode::back:
	case EDkeyCode::tab:
	case EDkeyCode::enter:
	case EDkeyCode::shift:
	case EDkeyCode::ctr:
	case EDkeyCode::esc:
	case EDkeyCode::space:
	case EDkeyCode::left:
	case EDkeyCode::up:
	case EDkeyCode::right:
	case EDkeyCode::down:
		return k;
	}
	if (EDkeyCode::A <= e && e <= EDkeyCode::Z) return k;
	if (EDkeyCode::a <= e && e <= EDkeyCode::z) return k;
	if (EDkeyCode::int_0 <= e && e <= EDkeyCode::int_9) return k;

	return EDkeyCode::null;
}

void DInputManager::BufferAddKeyAny(EDkeyCode k)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == 0) {
			keyAnyBuffer[i] = k;
			return;
		}
	}
}

void DInputManager::BufferAddKeyUp(EDkeyCode k)
{
	if (isLockUpBuffer) return; // 동기화를 위해 Lock적용
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == k) {
			keyAnyBuffer[i] = EDkeyCode::null;
			break;
		}
	}
	for (int i = 0; i < LEN; i++)
	{
		if (keyUpBuffer[i] == 0) {
			keyUpBuffer[i] = k;
			return;
		}
	}
}

void DInputManager::BufferAddKeyDown(EDkeyCode e)
{
	if (isLockDownBuffer) return; // 동기화를 위해 Lock적용
	for (int i = 0; i < LEN; i++)
	{
		if (keyDownBuffer[i] == 0) {
			keyDownBuffer[i] = k;
			return;
		}
	}
}

void DInputManager::BufferAddMouseUP(int i){
	if(MOUSE_INPUT_TYPE <= i || i < 0) return; //indet errer check
	mouseUpBuffer[i] = true;
	mouseAnyBuffer[i] = false;
	}

void DInputManager::BufferAddMouseDown(int i){
	if(MOUSE_INPUT_TYPE <= i || i < 0) return; //indet errer check
	mouseDownBuffer[i] = true;
}

const bool DInputManager::GetKeyDown(EDkeyCode k)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyDownBuffer[i] == k) return true;
		if (keyDownBuffer[i] == EDkeyCode::null) return false;
	}
	return false;
}

const bool DInputManager::GetKey(EDkeyCode k)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == k) return true;
	}
	return false;
}

const bool DInputManager::GetKeyUp(EDkeyCode k)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyUpBuffer[i] == k) return true;
		if (keyUpBuffer[i] == EDkeyCode::null) return false;
	}
	return false;
}


void DInputManager::Init()
{
	isLockDownBuffer = true;
	isLockUpBuffer = true;
	for (int i = 0; i < LEN; i++)
	{
		keyUpBuffer[i] = EDkeyCode::null;
		if(keyDownBuffer[i] != EDkeyCode::null) BufferAddKeyAny(keyDownBuffer[i]);
		keyDownBuffer[i] = EDkeyCode::null;
	}
	for (int i = 0; i < MOUSE_INPUT_TYPE; i++)
	{
		if(mouseDownBuffer[i]) mouseAnyBuffer[i] = true;
		mouseUpBuffer[i] = false;
		mouseDownBuffer[i] = false;
	}
	isLockDownBuffer = false;
	isLockUpBuffer = false;;
}

void DInputManager::Start()
{
	isLockDownBuffer = false;
	isLockUpBuffer = false;
	for (int i = 0; i < LEN; i++)
	{
		keyUpBuffer[i] = EDkeyCode::null;
		keyDownBuffer[i] = EDkeyCode::null;
		keyAnyBuffer[i] = EDkeyCode::null;
	}
	for (int i = 0; i < MOUSE_INPUT_TYPE; i++)
	{
		mouseUpBuffer[i] = false;
		mouseDownBuffer[i] = false;
		mouseAnyBuffer[i] = false;
	}
	
}

void DInputManager::Tick(double deltaTime) {
	Init();
}