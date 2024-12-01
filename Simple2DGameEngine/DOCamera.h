#pragma once
#include "DObject.h"
#include <Windows.h>

class DOCamera : public DObject
{
public:
	//ī�޶� �ʱ�ȭ
	void InitializeCamera(HWND newhWnd, HDC newHdc, RECT cameraRect);

	//ī�޶� ������ �ùķ��̼� ���� ������
	void Rendering();

	//�ùķ��̼� ī�޶� ��ġ �ʱ�ȭ 
	void SetSimulationLocation(DVector2i newLocation);
	//�ùķ��̼� ī�޶� ��ġ ��ȯ
	DVector2i GetSimulationLocation();

	//�ùķ��̼� ī�޶� ��ġ �̵�
	void Move(DVector2i position);

private:
	//ī�޶� â�� ���� �ڵ� ����
	HWND hWnd;
	//ī�޶� â�� ���� DC������ ������ ����
	HDC hdc;
	//���� ������ �� ����
	RECT renderingRect;
	//�ùķ��̼ǿ����� ī�޶� ����
	DVector2i simulationLocation;

	//������ ���� �׸���
	void DrawScreen();
};