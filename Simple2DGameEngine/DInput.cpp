#pragma warning(disable : 26812)

#include "DInput.h"
#include "EDkeyCodeEnum.h"

void DInputManager::BufferAddAny(EDkeyCode k)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == 0) {
			keyAnyBuffer[i] = k;
			return;
		}
	}
}

void DInputManager::BufferAddUp(EDkeyCode k)
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

void DInputManager::BufferAddDown(EDkeyCode k)
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
		if(keyDownBuffer[i] != EDkeyCode::null) BufferAddAny(keyDownBuffer[i]);
		keyDownBuffer[i] = EDkeyCode::null;
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
	}
}
