#pragma once

#include <stdio.h>
#include <sys\timeb.h> 

class Timer
{
public:
	Timer();
	~Timer();
	static void Inital();
	int GetCurrent();
	void Reset();
	static Timer* Instance();
	static Timer* instance;
private:
	struct timeb start, end;
};

Timer* Timer::instance = nullptr;

Timer::Timer()
{
	ftime(&start);
}
Timer::~Timer()
{
}
void Timer::Inital() {
	if (instance == nullptr)
		instance = new Timer();
}
Timer* Timer::Instance() {
	if (instance == nullptr)
		instance = new Timer();
	return instance;
}
int Timer::GetCurrent() {
	ftime(&end);
	return (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
}
void Timer::Reset() {
	ftime(&start);
}