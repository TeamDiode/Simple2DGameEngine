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
	//anyBuffer�� �߰� 
	static void BufferAddKeyAny(EDkeyCode keyValue);
public:
	//keyDownBuffer�� �߰�
	static void BufferAddKeyUp(EDkeyCode keyValue); // 
	//keyDownBuffer�� �߰�
	static void BufferAddKeyDown(EDkeyCode keyValue);
	//mouseUpBuffer�� �߰�
	static void BufferAddMouseUP(int i);
	//mouseDownBuffer�� �߰�
	static void BufferAddMouseDown(int i);

	/// <summary>
	/// Ű�� ���� ���ȴ��� üũ �Լ� 
	/// </summary>
	/// <returns>���� �����ӿ� Ű�� ���ȴٸ� true ��ȯ</returns>
	const static bool GetKeyDown(EDkeyCode keyValue);

	/// <summary>
	/// Ű�� ��� �������� üũ �Լ� 
	/// </summary>
	/// <returns>Ű�� ������ �ִٸ� true ��ȯ</returns>
	const static bool GetKey(EDkeyCode keyValue);

	/// <summary>
	/// Ű�� ��������� üũ �Լ� 
	/// </summary>
	/// <returns>Ű�� �������ٸ� true ��ȯ</returns>
	const static bool GetKeyUp(EDkeyCode keyValue);


	/// <summary>
	/// ���콺�� ���ȴ��� üũ �Լ�
	/// </summary>
	/// <returns>���콺�� ���ȴٸ� true ��ȯ</returns>
	const static bool GetMouseButtonDown(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseDownBuffer[0][i] : false; }

	/// <summary>
	/// ���콺�� ��������� üũ �Լ�
	/// </summary>
	/// <returns>���콺�� �������ٸ� true ��ȯ</returns>
	const static bool GetMouseButtonUp(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseUpBuffer[0][i] : false; }

	/// <summary>
	/// ���콺�� ��� ������ �ִ��� üũ �Լ�
	/// </summary>
	/// <returns>���콺�� ��� ������ �ִٸ� true ��ȯ</returns>
	const static bool GetMouseButton(int i) { return (MOUSE_INPUT_TYPE > i && i >= 0) ? mouseAnyBuffer[i] : false; }

	/// <summary>
	/// ������ â�� ���콺 ��ġ ��ȯ�Լ�
	/// </summary>
	/// <returns>��ȯ ���� DVector2i </returns>
	const static DVector2i GetMousePostion() { return mousePostion; }

	//���콺 ��ġ ���� �Լ�
	static void SetMousePostion(DVector2i moveVector2) { mousePostion = moveVector2; }
	

	static void Init();
};