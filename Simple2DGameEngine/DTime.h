#pragma once
#include <iostream>
#include <time.h>

class DTime {
	double nowTime, lastTime;

	clock_t start, finish;
	double deltaTime; //�ʿ��Ѱ�?
public:
	void Update(); //nowTime,lastTime ����
	double GetDeltaTime(); 

	//Scale... ���???
	void SetTimeScale(double t);

	

};