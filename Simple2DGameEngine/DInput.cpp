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
	//AnyBuffer 빈 위치에 값 추가
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
	//버퍼에 값이 추가될때 Lock을 걸어서 데이터 동기화
	isLockUpBuffer = true;
	//AnyBuffer에 들어있는 keyValue값 제거
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == keyValue) {
			keyAnyBuffer[i] = EDkeyCode::null;
			break;
		}
	}
	//UpBuffer 빈 위치에 값 추가
	for (int i = 0; i < LEN; i++)
	{
		if (keyUpBuffer[1][i] == 0) {
			keyUpBuffer[1][i] = keyValue;
			isLockUpBuffer = false;
			//리턴 전 동기화 해제
			return;
		}
	}
	//동기화 해제
	isLockUpBuffer = false;
}

void DInputManager::BufferAddKeyDown(EDkeyCode keyValue)
{
	//버퍼에 값이 추가될때 Lock을 걸어서 데이터 동기화
	isLockDownBuffer = true;
	//DownBuffer 빈 위치에 값 추가
	for (int i = 0; i < LEN; i++)
	{
		//만약 keyValue가 눌리고 있다면 리턴
		if (keyAnyBuffer[i] == keyValue) {
			//리턴 전 동기화 해제
			isLockDownBuffer = false;
			return;
		}
	}
	for (int i = 0; i < LEN; i++)
	{
		if (keyDownBuffer[1][i] == 0) {

			keyDownBuffer[1][i] = keyValue;
			//리턴 전 동기화 해제
			isLockDownBuffer = false;
			return;
		}
	}
	//동기화 해제
	isLockDownBuffer = false;
}
void DInputManager::BufferAddMouseUP(int i){
	//입력된 범위가 유효한지 체크
	if(MOUSE_INPUT_TYPE <= i && i < 0) return; //index errer check
	//mouseUp 버퍼에 값 추가, AnyBuffer에는 해제
	mouseUpBuffer[1][i] = true;
	mouseAnyBuffer[i] = false;
	}
void DInputManager::BufferAddMouseDown(int i){
	//입력된 범위가 유효한지 체크
	if(MOUSE_INPUT_TYPE <= i && i < 0) return; //index errer check
	//MouseDownBuffer 값 할당
	mouseDownBuffer[1][i] = true;
}
const bool DInputManager::GetKeyDown(EDkeyCode keyValue)
{
	//입력받은 키가 downBuffer에 있는가? 반환
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
	//입력받은 키가 anyBuffer에 있는가? 반환
	for (int i = 0; i < LEN; i++)
	{
		if (keyAnyBuffer[i] == keyValue) return true;
	}
	return false;
}
const bool DInputManager::GetKeyUp(EDkeyCode keyValue)
{
	//입력받은 키가 UpBuffer에 있는가? 반환
	for (int i = 0; i < LEN; i++)
	{
		if (keyUpBuffer[0][i] == keyValue) return true;
		if (keyUpBuffer[0][i] == EDkeyCode::null) return false;
	}
	return false;
}
void DInputManager::Init()
{
	//모든 오브젝트의 Update()가 끝나면 DInput의 down,Up값들 리셋
	for (int i = 0; i < LEN; i++)
	{
		//Lock이 걸려있지 않다면, 정상적으로 값 초기화
		if (!isLockUpBuffer) {
			keyUpBuffer[0][i] = keyUpBuffer[1][i];
			keyUpBuffer[1][i] = EDkeyCode::null;
		}
		//Lock이 걸려있지 않다면, 정상적으로 UpBuffer에 값 추가
		if (!isLockDownBuffer) {
			BufferAddKeyAny(keyDownBuffer[0][i]);
			keyDownBuffer[0][i] = keyDownBuffer[1][i];
			keyDownBuffer[1][i] = EDkeyCode::null;
		}
	}
	//마우스 Buffer 초기화 함수
	for (int i = 0; i < MOUSE_INPUT_TYPE; i++)
	{
		if(mouseDownBuffer[0][i]) mouseAnyBuffer[i] = true;

		mouseUpBuffer[0][i] = mouseUpBuffer[1][i];
		mouseDownBuffer[0][i] = mouseDownBuffer[1][i];

		mouseUpBuffer[1][i] = false;
		mouseDownBuffer[1][i] = false;
	}
}
