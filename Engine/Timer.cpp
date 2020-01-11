#include "Timer.h"

Timer::Timer()
{
	last = std::chrono::steady_clock::now();
}

void Timer::SetPoint()
{
	last = std::chrono::steady_clock::now();
}

float Timer::GetDeltaTime()
{
	std::chrono::steady_clock::time_point actualTime = std::chrono::steady_clock::now();
	std::chrono::duration<float> passed = actualTime - last;
	last = actualTime;

	return passed.count();
}
