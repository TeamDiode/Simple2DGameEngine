#pragma once
#include <iostream>
#include <time.h>

class DTime {
	double nowTime, lastTime;

	clock_t start, finish;
	double deltaTime; //필요한가?
public:
	void Update(); //nowTime,lastTime 리셋
	double GetDeltaTime(); 

	//Scale... 어떻게???
	void SetTimeScale(double t);

	

};