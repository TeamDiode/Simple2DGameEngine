#pragma warning(disable : 26812)

#include "DInput.h"
#include "EDkeyCodeEnum.h"
#include "DMathTypes.h"

#include "DEngine.h"


bool DInputManager::isLockDownBuffer = false;
bool DInputManager::isLockUpBuffer = false;
DVector2i DInputManager::mousePostion(100, 100);

EDkeyCode DInputManager::keyDownBuffer[2][LEN] = { {EDkeyCode::null},{EDkeyCode::null} };
EDkeyCode DInputManager::keyUpBuffer[2][LEN] = { {EDkeyCode::null},{EDkeyCode::null} };
EDkeyCode DInputManager::keyAnyBuffer[LEN] = { EDkeyCode::null, };
bool DInputManager::mouseUpBuffer[2][MOUSE_INPUT_TYPE] = { {false,},{false,} };
bool DInputManager::mouseDownBuffer[2][MOUSE_INPUT_TYPE] = { {false,},{false,} };
bool DInputManager::mouseAnyBuffer[MOUSE_INPUT_TYPE] = { false, };

void DInputManager::BufferAddKeyAny(EDkeyCode keyValue)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == 0) {
			keyAnyBuffer[i] = keyValue;
			return;
		}
	}
}

void DInputManager::BufferAddKeyUp(EDkeyCode keyValue)
{
	isLockUpBuffer = true;
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == keyValue) {
			keyAnyBuffer[i] = EDkeyCode::null;
			break;
		}
	}
	for (int i = 0; i < LEN; i++)
	{
		if (keyUpBuffer[1][i] == 0) {
			keyUpBuffer[1][i] = keyValue;
			isLockUpBuffer = false;
			return;
		}
	}
	isLockUpBuffer = false;
}

void DInputManager::BufferAddKeyDown(EDkeyCode keyValue)
{
	isLockDownBuffer = true;
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == keyValue) {
			isLockDownBuffer = false;
			return;
		}
	}
	for (int i = 0; i < LEN; i++)
	{
		if (keyDownBuffer[1][i] == 0) {

			keyDownBuffer[1][i] = keyValue;
			isLockDownBuffer = false;
			return;
		}
	}
	isLockDownBuffer = false;
}
void DInputManager::BufferAddMouseUP(int i){
	if(MOUSE_INPUT_TYPE <= i && i < 0) return; //index errer check
	mouseUpBuffer[1][i] = true;
	mouseAnyBuffer[i] = false;
	}
void DInputManager::BufferAddMouseDown(int i){
	if(MOUSE_INPUT_TYPE <= i && i < 0) return; //index errer check
	mouseDownBuffer[1][i] = true;
}
const bool DInputManager::GetKeyDown(EDkeyCode keyValue)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyDownBuffer[0][i] == keyValue) {
			return true;
		}
		if (keyDownBuffer[0][i] == EDkeyCode::null) {
			return false;
		}
	}
	return false;
}
const bool DInputManager::GetKey(EDkeyCode keyValue)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == keyValue) return true;
	}
	return false;
}
const bool DInputManager::GetKeyUp(EDkeyCode keyValue)
{
	for (int i = 0; i < LEN; i++)
	{
		if (keyUpBuffer[0][i] == keyValue) return true;
		if (keyUpBuffer[0][i] == EDkeyCode::null) return false;
	}
	return false;
}
void DInputManager::Init()
{
	for (int i = 0; i < LEN; i++)
	{
		if (!isLockUpBuffer) {
			keyUpBuffer[0][i] = keyUpBuffer[1][i];
			keyUpBuffer[1][i] = EDkeyCode::null;
		}
		if (!isLockDownBuffer) {
			BufferAddKeyAny(keyDownBuffer[0][i]);
			keyDownBuffer[0][i] = keyDownBuffer[1][i];
			keyDownBuffer[1][i] = EDkeyCode::null;
		}
	}
	for (int i = 0; i < MOUSE_INPUT_TYPE; i++)
	{
		if(mouseDownBuffer[0][i]) mouseAnyBuffer[i] = true;

		mouseUpBuffer[0][i] = mouseUpBuffer[1][i];
		mouseDownBuffer[0][i] = mouseDownBuffer[1][i];

		mouseUpBuffer[1][i] = false;
		mouseDownBuffer[1][i] = false;
	}
}
