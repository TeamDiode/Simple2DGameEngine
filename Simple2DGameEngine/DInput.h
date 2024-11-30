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
	//anyBuffer에 추가 
	static void BufferAddKeyAny(EDkeyCode keyValue);
public:
	//keyDownBuffer에 추가
	static void BufferAddKeyUp(EDkeyCode keyValue); // 
	//keyDownBuffer에 추가
	static void BufferAddKeyDown(EDkeyCode keyValue);
	//mouseUpBuffer에 추가
	static void BufferAddMouseUP(int i);
	//mouseDownBuffer에 추가
	static void BufferAddMouseDown(int i);

	/// <summary>
	/// 키가 지금 눌렸는지 체크 함수 
	/// </summary>
	/// <returns>현재 프레임에 키가 눌렸다면 true 반환</returns>
	const static bool GetKeyDown(EDkeyCode keyValue);

	/// <summary>
	/// 키가 계속 눌리는지 체크 함수 
	/// </summary>
	/// <returns>키가 눌리고 있다면 true 반환</returns>
	const static bool GetKey(EDkeyCode keyValue);

	/// <summary>
	/// 키가 띄어졌는지 체크 함수 
	/// </summary>
	/// <returns>키가 때어졌다면 true 반환</returns>
	const static bool GetKeyUp(EDkeyCode keyValue);


	/// <summary>
	/// 마우스가 눌렸는지 체크 함수
	/// </summary>
	/// <returns>마우스가 눌렸다면 true 반환</returns>
	const static bool GetMouseButtonDown(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseDownBuffer[0][i] : false; }

	/// <summary>
	/// 마우스가 띄어졌는지 체크 함수
	/// </summary>
	/// <returns>마우스가 때어졌다면 true 반환</returns>
	const static bool GetMouseButtonUp(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseUpBuffer[0][i] : false; }

	/// <summary>
	/// 마우스가 계속 눌리고 있는지 체크 함수
	/// </summary>
	/// <returns>마우스가 계속 눌리고 있다면 true 반환</returns>
	const static bool GetMouseButton(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseAnyBuffer[i] : false; }

	/// <summary>
	/// 윈도우 창의 마우스 위치 반환함수
	/// </summary>
	/// <returns>반환 형식 DVector2i </returns>
	const static DVector2i GetMousePostion() { return mousePostion; }

	//마우스 위치 세팅 함수
	static void SetMousePostion(DVector2i moveVector2) { mousePostion = moveVector2; }
	

	static void Init();
};